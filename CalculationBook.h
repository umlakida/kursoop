#pragma once
#include "ElectroCounter.h"
#include <vector>
#include <string>
class CalculationBook : public ElectroCounter
{
protected:
	vector<ElectroCounter> elCounters;
	double costPerKwH;
	string date;

public:
	CalculationBook();
	CalculationBook(double cost, string& dateB);
	~CalculationBook();

	void setCostKwH(double cost);
	void setDate(const string& dateB);

	double getCostKwH() const;
	string getDate() const;

	void addCheck(const ElectroCounter& elcounter);
	double getTotalConsumption()const;
	double getTotalCost()const;

	virtual void display() const;
};

