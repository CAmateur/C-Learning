#include "MyHttpException.h"

MyHttpBaseException::MyHttpBaseException(const std::string Msg):msg(Msg)
{
}

const char * MyHttpBaseException::what() const
{
	return msg.c_str();
}

