#include<iostream>
#include<ostream>
#include<istream>
#include<vector>
#include<new>
std::vector<int> *application()
{
	return (new std::vector<int>);
}
std::vector<int> *writecontent(std::istream &in, std::vector<int> * ptr)
{
	int *number=new int(0);
	while (in >> *number)
	{
		ptr->push_back(*number);
	}
	delete number;
	return ptr;
}
void readcontent(std::ostream &out, std::vector<int> *ptr)
{
	
	for (std::vector<int>::iterator bg = ptr->begin(); bg != ptr->end(); bg++)
		out << *bg;
	delete ptr;
}
int main(int argc, char**argv)
{
	readcontent(std::cout, writecontent(std::cin, application()));

	system("pause");
	return 0;
}