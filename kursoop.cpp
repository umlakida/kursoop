// kursoop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DigitalCounter.h"
#include "ElectroCounter.h"
#include "CalculationBook.h"
#include "ExceptionMsg.h"

using namespace std;

int main()
{
    cout <<"+------------------------------------------+" << endl;
    cout << "|           Course work | Option#19        |" << endl;
    cout << "|               Kovtunenko L.S.            |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << endl;


    DigitalCounter d1 = DigitalCounter();
    ElectroCounter e1 = ElectroCounter();
    CalculationBook book1 = CalculationBook();

    bool act = false;
    while (act) {
        cout << "============================================" << endl;
        cout << "|              Choose action               |" << endl;
        cout << "|                       ...                |" << endl;
        cout << "============================================" << endl;

        int todo; cin >> todo;
    }

    /*DigitalCounter count_1;
    DigitalCounter count_2(1, 15);

     count_1.display();
     count_2.operator++();
     count_2.display();*/
    //Механізм пізнього зв'язування
    ElectroCounter* counter = new ElectroCounter(0, 100, 2, 3);
    DigitalCounter digitalCouter = DigitalCounter();
    counter->display();
    cout << digitalCouter;
    delete counter;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
