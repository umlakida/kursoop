#include "CalculationBook.h"
#include <vector>
#include <string>
using namespace std;

CalculationBook::CalculationBook() {
	costPerKwH = 0.0;
	date = "01/01/2023";
}
CalculationBook::CalculationBook(double cost, string& dateB){
	this->costPerKwH = cost;
	this->date = dateB;
}
CalculationBook::~CalculationBook(){}

void CalculationBook::setCostKwH(double cost){
	costPerKwH = cost;
}
void CalculationBook::setDate(const string& dateB){
	date = dateB;
}
double CalculationBook::getCostKwH() const{
	return costPerKwH;
}
string CalculationBook::getDate() const{
	return date;
}

void CalculationBook::addCheck(const ElectroCounter& elcounter){
	elCounters.push_back(elcounter);
}
double CalculationBook::getTotalConsumption() const{
	double totalConsumption = 0.0;
	for (const auto& elcounter : elCounters) {
		totalConsumption += elcounter.getValue();
	}
	return totalConsumption;
}
double CalculationBook::getTotalCost() const{
	double totalCost = getTotalConsumption() * costPerKwH;
	return totalCost;
}

void CalculationBook::display() const{
    cout << "\n\t<<Calculation Book Information>>" << endl;
    cout << "Date: " << date << endl;
    cout << "Cost per kWh: " << costPerKwH << endl;

    cout << "Electricity counters:" << endl;
	for (const auto& elcounter : elCounters) {
        cout << "ElCounter Value: " << elcounter.getValue() << endl;
        cout << "Consumption: " << elcounter.getConsumption() << endl;
        cout << "Precision: " << elcounter.getPrec() << endl;
        cout << endl;
    }
    cout << "Total Consumption: " << getTotalConsumption() << endl;
    cout << "Total Cost: " << getTotalCost() << endl;
}

