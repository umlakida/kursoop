#pragma once
#include "DigitalCounter.h"

using namespace std;
class ElectroCounter : public DigitalCounter
{
private:
	int consumption;
	int precision;

public:
	ElectroCounter();
	ElectroCounter(int minVal, int maxVal, int consumption, int prec);
	~ElectroCounter();

	void setConsumption(int consumption);
	int getConsumption() const;

	void setPrec(int prec);
	int getPrec() const;

    void operator++ ();
	void operator-- ();
	void operator+= (int IncValue);
	void operator-= (int DecValue);
	//методи встановлення та визначення поточного значення лічильника
	ElectroCounter& operator= (const ElectroCounter& other);
	friend ostream& operator<< (ostream& out, const ElectroCounter& elcounter);
	friend istream& operator>> (istream& in, ElectroCounter& elcounter);

	virtual void display() const override;
	virtual void increment(int IncValue = 1) ;
	virtual void decrement(int DecValue = 1);
};

