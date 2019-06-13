#pragma once
#include<iostream>
#include<string>
class Sales_data
{
	friend std::istream& read(std::istream&, Sales_data&);

	friend std::ostream& print(std::ostream &, const Sales_data &);
public:

	Sales_data()=default;
	~Sales_data();
	Sales_data(const std::string &);
	Sales_data(const std::string &, unsigned, double);
	Sales_data(std::iostream &);


	std::string isbn()const;
	Sales_data& combine(const Sales_data &);
	Sales_data add(Sales_data &, Sales_data &);

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double avg_price()const;

};
std::istream& read(std::istream&, Sales_data&);

std::ostream& print(std::ostream &, const Sales_data &);
