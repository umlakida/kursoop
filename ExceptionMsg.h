#pragma once
#include <iostream>
#include <string>

using namespace std;

class ExceptionMsg : public std :: exception
{
private:
	string ex;
public:
	ExceptionMsg(const string& msg);
	~ExceptionMsg();
	string getMsg() const;
};

