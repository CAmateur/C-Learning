#include"text.h"
int main()
{
	std::string cc = "hello world";
	text b;
	b.a(cc, std::cout) <<std::endl;
	 const text g;
	 g.a(cc, std::cout)<<std::endl;
	system("pause");
	return 0;
}