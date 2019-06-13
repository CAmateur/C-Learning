#include<iostream>
#include<ostream>
#include<istream>
#include<vector>
#include<memory>
std::shared_ptr<std::vector<int>> application()
{
	return (std::make_shared<std::vector<int>>());
}
std::shared_ptr<std::vector<int>> writecontent(std::istream &in, std::shared_ptr<std::vector<int>> ptr)
{
	std::shared_ptr<int> number = std::make_shared<int>(0);
	while (in >> *number)
	{
		ptr->push_back(*number);
	}
	return ptr;
}
void readcontent(std::ostream &out, std::shared_ptr<std::vector<int>> ptr)
{
	
	for (std::vector<int>::iterator bg = ptr->begin(); bg != ptr->end(); bg++)
		out << *bg;
	
}
int main(int argc, char**argv)
{
	readcontent(std::cout, writecontent(std::cin, application()));

	system("pause");
	return 0;
}