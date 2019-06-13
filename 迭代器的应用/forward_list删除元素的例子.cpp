#include<iostream>
#include<list>
#include<forward_list>
using namespace std;
int main(int argc, char**argv)
{
	forward_list<int> lis1{ 1,2,3,4,5,6,7,8,9 };
	forward_list<int>::iterator prev = lis1.before_begin();
	forward_list<int>::iterator curr=lis1.begin();
	while (curr != lis1.end())
	{
		if (*curr % 2 != 0)
			curr = lis1.erase_after(prev);
		else
		{
			prev = curr;
			++curr;
		}
	}
	for (auto a : lis1)
		cout << a << endl;
	system("pause");
	return 0;
}