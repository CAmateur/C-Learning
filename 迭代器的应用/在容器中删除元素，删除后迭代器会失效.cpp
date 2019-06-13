#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main(int argc, char** argv)
{
	int ia[] = { 0,1,2,3,4,5,6,7,8,13,21,55,89 };
	vector<int> vec1;
	list<int>lis1;
	for (int i = 0; i <12; i++)
	{
		vec1.push_back(ia[i]);
		lis1.push_back(ia[i]);
	}
	
	vector<int>::iterator it1 = vec1.begin();
	list<int>::iterator it2 = lis1.begin();
	for(;it1!= vec1.end();)
		if (*it1 % 2 != 0)//如果是奇数则删除当前迭代器，并且迭代器全部失效！
		{
			it1=vec1.erase(it1);
			
		}
		else {
			it1++;
		}
	for (; it2 != lis1.end();)
	{
		if (*it2 % 2 == 0)//如果是偶数则删除当前迭代器，并且迭代器全部失效！
		{
			it2=lis1.erase(it2);
			
		}
		else
		{
			it2++; 
		}
			
	}

	for (auto a : vec1)
		cout << a << endl;
	for (auto a : lis1)
		cout << a << endl;
	system("pause");
	return 0;
}