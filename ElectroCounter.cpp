#include "ElectroCounter.h"
#include "ExceptionMsg.h"

using namespace std;

ElectroCounter::ElectroCounter() : DigitalCounter() {
    consumption = 0;
    precision = 0;
}

ElectroCounter::ElectroCounter(int minVal, int maxVal, int consumption, int prec): DigitalCounter(minVal, maxVal) {
    this->consumption = consumption;
    this->precision = prec;
}

ElectroCounter::~ElectroCounter() {}

void ElectroCounter::setConsumption(int consumption) {
    consumption = consumption;
}

int ElectroCounter::getConsumption() const{
    return consumption;
}

void ElectroCounter::setPrec(int prec) {
    precision = prec;
}

int ElectroCounter::getPrec()const{
    return precision;
}


void ElectroCounter::operator++ (){
    if (value < maxValue) {
        increment();
    }
    else {
        throw ExceptionMsg("\n\tMaxValue is reached");
    }
}
void ElectroCounter::operator-- (){
    if (value > minValue) {
        decrement();
    }
    else {
        throw ExceptionMsg("\n\tMinValue is reached");
    }
}
void ElectroCounter::operator+= (int IncValue){}
void ElectroCounter::operator-= (int DecValue){}
//методи встановлення та визначення поточного значення лічильника
ElectroCounter& ElectroCounter::operator= (const ElectroCounter& other) {
    if (this == &other) {
        return *this;
    }

    DigitalCounter::operator=(other);

    consumption = other.consumption;
    precision = other.precision;

    return *this;
}
ostream& operator<< (ostream& out, const ElectroCounter& elcounter) {
    out << "Value = " << elcounter.getValue() << endl;
    out << "Min Value = " << elcounter.getMinValue() << endl;
    out << "Max Value = " << elcounter.getMaxValue() << endl;
    out << "Consumption = " << elcounter.getConsumption() << endl;
    out << "Precision = " << elcounter.getPrec() << endl;
    return out;
}

istream& operator>> (istream& in, ElectroCounter& elcounter) {
    cout << "Enter minValue: ";
    in >> elcounter.minValue;

    cout << "Enter maxValue: ";
    in >> elcounter.maxValue;

    cout << "Enter consumption: ";
    in >> elcounter.consumption;

    cout << "Enter precision: ";
    in >> elcounter.precision;

    return in;
}

void ElectroCounter::display() const {
    cout << "Current value of electricity counter: " << getValue() << endl;
}

void ElectroCounter::increment(int IncValue){
    value += IncValue;
    if (value < maxValue) {
        value = minValue;
    }
}

void ElectroCounter::decrement(int DecValue){
    value -= DecValue;
    if (value < minValue) {
        value = maxValue;
    }
}
