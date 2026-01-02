#include <iostream>
#include <vector>
using namespace std;

/*
=====================================================
PART 1: BASIC STRATEGY PATTERN (YOUR ORIGINAL IDEA)
=====================================================

Purpose:
- Understand polymorphism
- Understand runtime behavior change
- Simple version without passing real data
*/

/*
Strategy Interface
------------------
- Declares common behavior
*/
class BasicSortStrategy {
public:
    virtual void sort() = 0;
    virtual ~BasicSortStrategy() {}
};

/*
Concrete Strategies
------------------
*/
class QuickSortBasic : public BasicSortStrategy {
public:
    void sort() override {
        cout << "Quick Sort It Is !!!!" << endl;
    }
};

class BubbleSortBasic : public BasicSortStrategy {
public:
    void sort() override {
        cout << "Bubble Sort It Is !!!!" << endl;
    }
};

/*
Context Class
-------------
- Holds a reference to strategy
- Executes chosen algorithm
*/
class BasicSortContext {
private:
    BasicSortStrategy* strategy;

public:
    void setStrategy(BasicSortStrategy* strategy) {
        this->strategy = strategy;
    }

    void execute() {
        strategy->sort();
    }
};

/*
=====================================================
PART 2: FINAL STRATEGY PATTERN (REALISTIC VERSION)
=====================================================

Purpose:
- Production-ready Strategy Pattern
- Each class = one algorithm
- No flags, no if-else
*/

/*
Strategy Interface
------------------
*/
class SortStrategy {
public:
    virtual void sort(vector<int>& arr) = 0;
    virtual ~SortStrategy() {}
};

/*
-----------------------------------------------------
CONCRETE STRATEGIES
-----------------------------------------------------
*/

// Quick Sort (Normal)
class NormalQuickSort : public SortStrategy {
public:
    void sort(vector<int>& arr) override {
        cout << "This is Normal Quick Sort" << endl;
    }
};

// Quick Sort (Advanced)
class AdvancedQuickSort : public SortStrategy {
public:
    void sort(vector<int>& arr) override {
        cout << "This is Advanced Quick Sort" << endl;
    }
};

// Bubble Sort (Normal)
class NormalBubbleSort : public SortStrategy {
public:
    void sort(vector<int>& arr) override {
        cout << "This is Normal Bubble Sort" << endl;
    }
};

// Bubble Sort (Advanced)
class AdvancedBubbleSort : public SortStrategy {
public:
    void sort(vector<int>& arr) override {
        cout << "This is Advanced Bubble Sort" << endl;
    }
};

// Insertion Sort (Normal)
class NormalInsertionSort : public SortStrategy {
public:
    void sort(vector<int>& arr) override {
        cout << "This is Normal Insertion Sort" << endl;
    }
};

// Insertion Sort (Advanced)
class AdvancedInsertionSort : public SortStrategy {
public:
    void sort(vector<int>& arr) override {
        cout << "This is Advanced Insertion Sort" << endl;
    }
};

/*
Context Class
-------------
- Single context
- Runtime swapping of strategies
*/
class SortContext {
private:
    SortStrategy* strategy;

public:
    SortContext(SortStrategy* strategy) {
        this->strategy = strategy;
    }

    void setStrategy(SortStrategy* strategy) {
        this->strategy = strategy;
    }

    void execute(vector<int>& arr) {
        strategy->sort(arr);
    }
};

/*
=====================================================
MAIN FUNCTION
=====================================================
*/
int main() {

    /*
    -------- BASIC STRATEGY DEMO --------
    */
    BasicSortContext basicSorter;

    basicSorter.setStrategy(new QuickSortBasic());
    basicSorter.execute();

    basicSorter.setStrategy(new BubbleSortBasic());
    basicSorter.execute();

    cout << "-------------------" << endl;

    /*
    -------- FINAL STRATEGY DEMO --------
    */
    vector<int> arr = {5, 4, 2, 3};

    SortContext sorter(new NormalQuickSort());
    sorter.execute(arr);

    sorter.setStrategy(new AdvancedQuickSort());
    sorter.execute(arr);

    sorter.setStrategy(new NormalBubbleSort());
    sorter.execute(arr);

    sorter.setStrategy(new AdvancedInsertionSort());
    sorter.execute(arr);

    return 0;
}