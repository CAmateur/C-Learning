#pragma once
#include<iostream>
#include<string>
class text
{
public:
	text();
	~text();

	std::ostream  &a(std::string &contents,std::ostream &os)const
	{
		os << contents<<"this is const";
		return os;
	}
	std::ostream &a(std::string &contents, std::ostream &os)
	{
		os << contents << "this is not const ";
		return os;
	}
};

