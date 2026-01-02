#include <iostream>
using namespace std;

/*
===========================================================
                SIMPLE FACTORY DESIGN PATTERN
===========================================================
- One factory class
- Decides which concrete object to create
- Client does NOT know the exact class
*/

// Abstract Product
class Burger {
public:
    virtual void prepare() = 0;   // Common interface
    virtual ~Burger() {}          // Virtual destructor
};

// Concrete Products
class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << "This is simple burger" << endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare() override {
        cout << "This is standard burger" << endl;
    }
};

class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout << "This is premium burger" << endl;
    }
};

// Simple Factory
class BurgerFactory {
public:
    // Creates burger object based on type
    virtual Burger* burgerFactory(string &type) {
        if (type == "Basic")    return new BasicBurger();
        if (type == "Standard") return new StandardBurger();
        if (type == "Premium")  return new PremiumBurger();

        cout << "Invalid Burger Type" << endl;
        return nullptr;
    }
};

/*
===========================================================
                FACTORY METHOD DESIGN PATTERN
===========================================================
- Factory is abstracted using inheritance
- Subclasses decide which product to create
*/

// Wheat burger variants
class BasicWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "This is simple wheat burger" << endl;
    }
};

class StandardWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "This is standard wheat burger" << endl;
    }
};

class PremiumWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "This is premium wheat burger" << endl;
    }
};

// Concrete Factory 1
class SinghBurgerFactory : public BurgerFactory {
public:
    Burger* burgerFactory(string &type) override {
        if (type == "Basic")    return new BasicBurger();
        if (type == "Standard") return new StandardBurger();
        if (type == "Premium")  return new PremiumBurger();

        cout << "Invalid Burger Type" << endl;
        return nullptr;
    }
};

// Concrete Factory 2
class KingBurgerFactory : public BurgerFactory {
public:
    Burger* burgerFactory(string &type) override {
        if (type == "Basic")    return new BasicWheatBurger();
        if (type == "Standard") return new StandardWheatBurger();
        if (type == "Premium")  return new PremiumWheatBurger();

        cout << "Invalid Burger Type" << endl;
        return nullptr;
    }
};

/*
===========================================================
            ABSTRACT FACTORY DESIGN PATTERN
===========================================================
- Factory of factories
- Creates families of related objects
- Ensures compatibility between products
*/

// Abstract Product 2
class GarlicBread {
public:
    virtual void prepare() = 0;
    virtual ~GarlicBread() {}
};

// Garlic bread variants
class BasicGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "This is basic garlic-bread" << endl;
    }
};

class CheeseGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "This is cheese garlic-bread" << endl;
    }
};

class StuffedCheeseGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "This is stuffed cheese garlic-bread" << endl;
    }
};

// Wheat garlic bread variants
class BasicWheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "This is basic wheat garlic-bread" << endl;
    }
};

class CheeseWheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "This is cheese wheat garlic-bread" << endl;
    }
};

class StuffedCheeseWheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "This is stuffed cheese wheat garlic-bread" << endl;
    }
};

// Abstract Factory
class MealFactory {
public:
    virtual Burger* burgerFactory(string &type) = 0;
    virtual GarlicBread* garlicBreadFactory(string &type) = 0;
};

// Concrete Abstract Factory 1
class SinghMealFactory : public MealFactory {
public:
    Burger* burgerFactory(string &type) override {
        if (type == "Basic")    return new BasicBurger();
        if (type == "Standard") return new StandardBurger();
        if (type == "Premium")  return new PremiumBurger();

        cout << "Invalid Burger Type" << endl;
        return nullptr;
    }

    GarlicBread* garlicBreadFactory(string &type) override {
        if (type == "Basic")    return new BasicGarlicBread();
        if (type == "Standard") return new CheeseGarlicBread();
        if (type == "Premium")  return new StuffedCheeseGarlicBread();

        cout << "Invalid Garlic-Bread Type" << endl;
        return nullptr;
    }
};

// Concrete Abstract Factory 2
class KingMealFactory : public MealFactory {
public:
    Burger* burgerFactory(string &type) override {
        if (type == "Basic")    return new BasicWheatBurger();
        if (type == "Standard") return new StandardWheatBurger();
        if (type == "Premium")  return new PremiumWheatBurger();

        cout << "Invalid Burger Type" << endl;
        return nullptr;
    }

    GarlicBread* garlicBreadFactory(string &type) override {
        if (type == "Basic")    return new BasicWheatGarlicBread();
        if (type == "Standard") return new CheeseWheatGarlicBread();
        if (type == "Premium")  return new StuffedCheeseWheatGarlicBread();

        cout << "Invalid Garlic-Bread Type" << endl;
        return nullptr;
    }
};

int main() {
    string type = "Standard";

    // SIMPLE FACTORY
    cout << "CREATING SIMPLE FACTORY DESIGN PATTERN:\n";
    BurgerFactory* factory = new BurgerFactory();
    Burger* burger = factory->burgerFactory(type);
    burger->prepare();
    cout << endl;

    // FACTORY METHOD
    cout << "CREATING FACTORY DESIGN PATTERN:\n";
    cout<<"Singh Burger Factory-->"<<endl;
    BurgerFactory* singhBurgerFactory = new SinghBurgerFactory();
    Burger* singhBurger = singhBurgerFactory->burgerFactory(type);
    singhBurger->prepare();
    cout << endl;

    cout<<"King Burger Factory-->"<<endl;
    BurgerFactory* kingBurgerFactory = new KingBurgerFactory();
    Burger* kingBurger = kingBurgerFactory->burgerFactory(type);
    kingBurger->prepare();
    cout << endl;

    // ABSTRACT FACTORY
    cout << "CREATING ABSTRACT FACTORY DESIGN PATTERN:\n";
    cout<<"Singh Meal Factory-->"<<endl;
    MealFactory* singhMealFactory = new SinghMealFactory();
    Burger* singhMealBurger = singhMealFactory->burgerFactory(type);
    GarlicBread* singhGarlicBread = singhMealFactory->garlicBreadFactory(type);
    singhMealBurger->prepare();
    singhGarlicBread->prepare();
    cout << endl;

    cout<<"King Meal Factory-->"<<endl;
    MealFactory* kingMealFactory = new KingMealFactory();
    Burger* kingMealBurger = kingMealFactory->burgerFactory(type);
    GarlicBread* kingGarlicBread = kingMealFactory->garlicBreadFactory(type);
    kingMealBurger->prepare();
    kingGarlicBread->prepare();
}