#include "DigitalCounter.h"
#include "ExceptionMsg.h"
#include <iostream>

using namespace std;

 DigitalCounter::DigitalCounter() {
        minValue = 0;
        maxValue = 10;
        value = 0;
    }

    DigitalCounter::DigitalCounter(int minVal, int maxVal) {
        this->minValue = minVal;
        this->maxValue = maxVal;
        this->value = minVal;
    }

    DigitalCounter::~DigitalCounter() {}

    void DigitalCounter::setMinValue(int minVal) {
        minValue = minVal;
    }
    void DigitalCounter::setMaxValue(int maxVal) {
        maxValue = maxVal;
    }
    void DigitalCounter::setValue(int val) {
        if (val >= minValue && val <= maxValue) {
            value = val;
        }
        else {
            cout << "Incorrect value" << endl;
        }
    }

    int DigitalCounter::getMinValue() const {
        return minValue;
    }
    int DigitalCounter::getMaxValue() const {
        return maxValue;
    }
    int DigitalCounter::getValue() const {
        return value;
    }


    void DigitalCounter::operator() (int val) {
        setValue(val);
    }

    void DigitalCounter::operator++ () {
        if (value < maxValue) {
            increment();
        }
        else {
            throw ExceptionMsg("\n\tMaxValue is reached");
        }
    }

    void DigitalCounter::operator-- () {
        if (value > minValue) {
            decrement();
        }
        else {
            throw ExceptionMsg("\n\tMinValue is reached");
        }
    }

    void DigitalCounter::operator+= (int IncValue) {
        int oldValue = value;
        increment(IncValue);
        if (value > maxValue) {
            value = oldValue;
            throw ExceptionMsg("\n\tMax value is reached");
        }
    }


    void DigitalCounter::operator-= (int DecValue) {
        int oldValue = value;
        decrement(DecValue);
        if (value < minValue) {
            value = oldValue;
            throw ExceptionMsg("\n\tMin value is reached");
        }
    }


    void DigitalCounter::operator= (const DigitalCounter& counter) {
        minValue = counter.minValue;
        maxValue = counter.maxValue;
        value = counter.value;
    }

    std::istream& operator>> (std::istream& input, DigitalCounter& counter) {
        cout << "Enter MinValue: ";
        input >> counter.minValue;
        cout << "Enter MaxValue: ";
        input >> counter.maxValue;
        cout << "Enter current value: ";
        input >> counter.value;

        return input;
    }

    std::ostream& operator<< (std::ostream& output, const DigitalCounter& counter) {
         output << "MinValue = " << counter.minValue << endl;
         output << "MaxValue = " << counter.maxValue << endl;
         output << "Current Value = " << counter.value << endl;
         return output;
    }

    void DigitalCounter::display()const{
        cout << "Current value: " << value << endl;
    }

    void DigitalCounter::increment(int IncValue) {
        value += IncValue;
        if (value < maxValue) {
            value = minValue;
        }
    }

    void DigitalCounter::decrement(int DecValue) {
        value -= DecValue;
        if (value < minValue) {
            value = maxValue;
        }
    }



   