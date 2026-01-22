

/*
===========================================================
 PARKING LOT SYSTEM – LOW LEVEL DESIGN
===========================================================

OVERVIEW:
This design models a multi-floor parking lot system
capable of handling different types of vehicles.

The system focuses on:
- Parking space management
- Vehicle entry and exit flow
- Fee calculation
- Clean responsibility separation

-----------------------------------------------------------
CORE FUNCTIONALITIES:
The parking lot supports:
- Vehicle entry
- Spot allocation based on vehicle type
- Multi-floor parking management
- Parking fee calculation
- Payment processing
- Vehicle exit and spot release

-----------------------------------------------------------
USER FLOW (HIGH LEVEL):
1. Vehicle enters parking lot
2. System finds a suitable free spot
3. Vehicle is parked
4. Vehicle stays for a duration
5. Fee is calculated
6. Payment is processed
7. Vehicle exits
8. Spot becomes available again

-----------------------------------------------------------
KEY DESIGN IDEAS:
- Parking spots do NOT know vehicle details
- Vehicle is treated as an independent entity
- Parking lot coordinates floors and spots
- Fee and payment logic are kept separate
- The system should handle parking failures gracefully

-----------------------------------------------------------
FAILURE SCENARIOS HANDLED:
- Parking lot is full
- No suitable spot for vehicle type
- Payment failure
- Invalid exit request
- Unsupported vehicle types

-----------------------------------------------------------
DESIGN GOAL:
Build a modular and extensible parking system that:
- Models real-world parking behavior
- Avoids tight coupling between components
- Allows easy extension for new vehicle types
- Supports different pricing and payment strategies

===========================================================
*/



#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
--------------------------------------------------
ENUMS
--------------------------------------------------
*/

enum VehicleType {
    BIKE,
    CAR,
    TRUCK,
    OTHERS
};

enum DurationType {
    HOUR,
    DAY
};

/*
--------------------------------------------------
VEHICLE
--------------------------------------------------
Simple data holder.
*/

class Vehicle {
private:
    VehicleType type;
    string vehicleNumber;

public:
    Vehicle(VehicleType type, string vehicleNumber)
        : type(type), vehicleNumber(vehicleNumber) {}

    VehicleType getType() const {
        return type;
    }

    string getVehicleNumber() const {
        return vehicleNumber;
    }
};

/*
--------------------------------------------------
PARKING SPOT
--------------------------------------------------
Represents a physical parking space.
*/

class ParkingSpot {
protected:
    int spotId;
    bool isEmpty;
    VehicleType spotType;

public:
    ParkingSpot(int id, VehicleType type)
        : spotId(id), isEmpty(true), spotType(type) {}

    virtual bool canPark(VehicleType vehicleType) = 0;

    bool park() {
        if (isEmpty) {
            isEmpty = false;
            return true;
        }
        return false;
    }

    void unpark() {
        isEmpty = true;
    }

    bool isAvailable() const {
        return isEmpty;
    }

    int getSpotId() const {
        return spotId;
    }

    virtual ~ParkingSpot() {}
};

/*
--------------------------------------------------
DIFFERENT TYPES OF PARKING SPOTS
--------------------------------------------------
*/

class BikeParkingSpot : public ParkingSpot {
public:
    BikeParkingSpot(int id) : ParkingSpot(id, BIKE) {}

    bool canPark(VehicleType vehicleType) override {
        return vehicleType == BIKE;
    }
};

class CarParkingSpot : public ParkingSpot {
public:
    CarParkingSpot(int id) : ParkingSpot(id, CAR) {}

    bool canPark(VehicleType vehicleType) override {
        return vehicleType == CAR;
    }
};

class TruckParkingSpot : public ParkingSpot {
public:
    TruckParkingSpot(int id) : ParkingSpot(id, TRUCK) {}

    bool canPark(VehicleType vehicleType) override {
        return vehicleType == TRUCK;
    }
};

/*
--------------------------------------------------
PARKING FLOOR
--------------------------------------------------
A floor contains multiple parking spots.
*/

class ParkingFloor {
private:
    int floorNumber;
    vector<ParkingSpot*> spots;

public:
    ParkingFloor(int floorNumber) : floorNumber(floorNumber) {}

    void addSpot(ParkingSpot* spot) {
        spots.push_back(spot);
    }

    ParkingSpot* getAvailableSpot(VehicleType vehicleType) {
        for (auto spot : spots) {
            if (spot->isAvailable() && spot->canPark(vehicleType)) {
                return spot;
            }
        }
        return nullptr;
    }
};

/*
--------------------------------------------------
PARKING LOT (SINGLETON)
--------------------------------------------------
Manages all floors.
*/

class ParkingLot {
private:
    vector<ParkingFloor*> floors;

    ParkingLot() {}

public:
    static ParkingLot& getInstance() {
        static ParkingLot instance;
        return instance;
    }

    void addFloor(ParkingFloor* floor) {
        floors.push_back(floor);
    }

    ParkingSpot* parkVehicle(const Vehicle& vehicle) {
        for (auto floor : floors) {
            ParkingSpot* spot = floor->getAvailableSpot(vehicle.getType());
            if (spot && spot->park()) {
                cout << "Vehicle parked at spot: "
                     << spot->getSpotId() << endl;
                return spot;
            }
        }
        cout << "No available spot!" << endl;
        return nullptr;
    }
};

/*
--------------------------------------------------
PARKING FEE STRATEGY
--------------------------------------------------
*/

class ParkingFeeStrategy {
public:
    virtual int calculateFee(int duration,
                             DurationType durationType,
                             VehicleType vehicleType) = 0;
    virtual ~ParkingFeeStrategy() {}
};

class BasicFeeStrategy : public ParkingFeeStrategy {
public:
    int calculateFee(int duration,
                     DurationType durationType,
                     VehicleType vehicleType) override {

        int rate;

        if (vehicleType == BIKE) rate = 10;
        else if (vehicleType == CAR) rate = 15;
        else if (vehicleType == TRUCK) rate = 20;
        else rate = 18;

        if (durationType == DAY)
            return rate * duration * 24;

        return rate * duration;
    }
};

/*
--------------------------------------------------
PAYMENT STRATEGY
--------------------------------------------------
*/

class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() {}
};

class CardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid Rs " << amount << " using Card" << endl;
    }
};

class UpiPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid Rs " << amount << " using UPI" << endl;
    }
};

/*
--------------------------------------------------
MAIN FUNCTION
--------------------------------------------------
Flow:
1. Create parking lot
2. Park vehicle
3. Calculate fee
4. Pay
5. Unpark
*/

int main() {
    ParkingLot& parkingLot = ParkingLot::getInstance();

    cout << "\n================ PARKING LOT SYSTEM ================\n";

    /* -------------------------------
       Create Floors & Parking Spots
    -------------------------------- */
    cout << "\n[SETUP] Creating parking floors and spots\n";

    ParkingFloor* floor1 = new ParkingFloor(1);
    floor1->addSpot(new CarParkingSpot(103));
    floor1->addSpot(new TruckParkingSpot(104));

    ParkingFloor* floor2 = new ParkingFloor(2);
    floor2->addSpot(new CarParkingSpot(201));
    floor2->addSpot(new CarParkingSpot(202));
    floor2->addSpot(new TruckParkingSpot(203));

    parkingLot.addFloor(floor1);
    parkingLot.addFloor(floor2);

    cout << "[SETUP COMPLETE] Parking lot is ready\n";

    /* -------------------------------
       Create Vehicles
    -------------------------------- */
    cout << "\n[SETUP] Creating vehicles\n";

    Vehicle bike(BIKE, "PB10BK1111");
    Vehicle car(CAR, "PB10CR2222");
    Vehicle truck(TRUCK, "PB10TR3333");
    Vehicle other(OTHERS, "PB10OT4444");

    /* -------------------------------
       Park Vehicles
    -------------------------------- */
    cout << "\n[ACTION] Bike entering parking lot\n";
    ParkingSpot* bikeSpot = parkingLot.parkVehicle(bike);
    if (!bikeSpot)
        cout << "[FAILED] No suitable spot for BIKE\n";

    cout << "\n[ACTION] Car entering parking lot\n";
    ParkingSpot* carSpot = parkingLot.parkVehicle(car);
    if (!carSpot)
        cout << "[FAILED] No suitable spot for CAR\n";

    cout << "\n[ACTION] Truck entering parking lot\n";
    ParkingSpot* truckSpot = parkingLot.parkVehicle(truck);
    if (!truckSpot)
        cout << "[FAILED] No suitable spot for TRUCK\n";

    cout << "\n[ACTION] OTHER vehicle entering parking lot\n";
    ParkingSpot* otherSpot = parkingLot.parkVehicle(other);
    if (!otherSpot)
        cout << "[FAILED] No suitable spot for OTHER vehicle type\n";

    /* -------------------------------
       Fee & Payment Strategy
    -------------------------------- */
    ParkingFeeStrategy* feeStrategy = new BasicFeeStrategy();
    PaymentStrategy* upiPayment  = new UpiPayment();
    PaymentStrategy* cardPayment = new CardPayment();

    /* -------------------------------
       Exit Vehicles
    -------------------------------- */
    cout << "\n================ VEHICLE EXIT FLOW ================\n";

    if (bikeSpot) {
        cout << "\n[EXIT] Bike exiting after 1 hour\n";
        int fee = feeStrategy->calculateFee(1, HOUR, bike.getType());
        cout << "[FEE] Calculated parking fee: Rs " << fee << endl;
        upiPayment->pay(fee);
        bikeSpot->unpark();
        cout << "[SUCCESS] Bike exited, spot released\n";
    }

    if (carSpot) {
        cout << "\n[EXIT] Car exiting after 3 hours\n";
        int fee = feeStrategy->calculateFee(3, HOUR, car.getType());
        cout << "[FEE] Calculated parking fee: Rs " << fee << endl;
        cardPayment->pay(fee);
        carSpot->unpark();
        cout << "[SUCCESS] Car exited, spot released\n";
    }

    if (truckSpot) {
        cout << "\n[EXIT] Truck exiting after 1 day\n";
        int fee = feeStrategy->calculateFee(1, DAY, truck.getType());
        cout << "[FEE] Calculated parking fee: Rs " << fee << endl;
        upiPayment->pay(fee);
        truckSpot->unpark();
        cout << "[SUCCESS] Truck exited, spot released\n";
    }

    cout << "\n================ SYSTEM FLOW COMPLETE ================\n";

    return 0;
}