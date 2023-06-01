#pragma once
#include <iostream>

#ifndef DIGITALCOUNTER_H
#define DIGITALCOUNTER_H

using namespace std;

class DigitalCounter {
protected:
    int minValue;
    int maxValue;
    int value;

public:
    DigitalCounter();
    DigitalCounter(int minVal, int maxVal);
    ~DigitalCounter();

    // Методи встановлення значень полів даних
    void setMinValue(int minVal);
    void setMaxValue(int maxVal);
    void setValue(int val);

    // Методи отримання значень полів даних
    int getMinValue() const;
    int getMaxValue() const;
    int getValue() const;

    // Перевантаження 
    void operator() (int val);
    void operator++ ();
    void operator-- ();
    void operator+= (int IncValue);
    void operator-= (int DecValue);
    void operator= (const DigitalCounter& counter);
    friend std::istream& operator>> (std::istream& input, DigitalCounter& counter);
    friend std::ostream& operator<< (std::ostream& output, const DigitalCounter& counter);

    virtual void display() const;
    virtual void increment(int IncValue = 1);
    virtual void decrement(int DecValue = 1);
};

#endif 
