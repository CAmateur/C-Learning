#include "Sales_data.h"



Sales_data::Sales_data(const std::string &hh,unsigned aa,double price):bookNo(hh),units_sold(aa),revenue(price)
{

}
//委托函数初始化列表只能有一个参数且为构造函数
Sales_data::Sales_data(const std::string &kk):Sales_data(kk,0,0) {

}


Sales_data::~Sales_data()
{
}

double Sales_data::avg_price()const
{
	return units_sold ? revenue / units_sold : 0;
}
std::istream& read(std::istream &is, Sales_data &ss)
{
	double price = 0;
	is >> ss.bookNo >> ss.units_sold >> price;
	ss.revenue = price*ss.units_sold;
	return is;
}
std::ostream& print(std::ostream &os, const Sales_data &ss)
{
	os << ss.bookNo << " " << ss.revenue << " " << ss.units_sold;
	return os;
}
