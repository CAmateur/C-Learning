#pragma once
#include<exception>
#include<string>
class MyHttpBaseException :public std::exception
{
public:
	MyHttpBaseException(const std::string Msg);
	~MyHttpBaseException() = default;
	virtual const char* what()const override;
private:
	std::string msg;
};
