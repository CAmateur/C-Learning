#include "Sales_data.h"
//��������
Sales_data::Sales_data()
{
}
Sales_data::Sales_data(const std::string &s) :bookNo(s) {}
Sales_data::Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p*n) {}
Sales_data::Sales_data(std::iostream &is)
{
	read(is, *this);
}
Sales_data::~Sales_data()
{
}
std::string Sales_data::isbn()const 
{
	return this->bookNo;
}
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	this->units_sold += rhs.units_sold;
	this->revenue += rhs.revenue;
	return *this;
}
Sales_data Sales_data::add(Sales_data &lhs, Sales_data &rhs)
{
	Sales_data sum = lhs;//ϵͳ�Զ������=�Ĺ���
	sum.combine(rhs);
	return sum;
}
double Sales_data::avg_price()const
{
	return units_sold?revenue / units_sold:0;
}
std::istream& read(std::istream& is, Sales_data& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}
std::ostream & print(std::ostream &os, const Sales_data & item)
{
	os <<"ISBN:"<< item.bookNo << "������:" << item.units_sold << "����������:" << item.revenue << "���۵���:" << item.avg_price();
	return os;
}