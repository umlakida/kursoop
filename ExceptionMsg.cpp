#include "ExceptionMsg.h"

ExceptionMsg::ExceptionMsg(const string& msg) : ex(msg){}
ExceptionMsg::~ExceptionMsg(){}
string ExceptionMsg::getMsg() const {
	return (ex);
}