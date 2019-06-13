#include<iostream>
#include<list>
#include<vector>
#include<numeric>
#include<algorithm>
#include<iterator>
using namespace std;
int main(int argc, char**argv)
{
	vector<int> vec{ 1,2,3,4,5,6,7,8,9};
	list<int> lis;
	copy(vec.begin(), vec.end(),front_inserter(lis));
	for (auto elem : lis)
		cout << elem << " ";
	cout << endl;
	lis.clear();
	copy(vec.begin(), vec.end(), back_inserter(lis));
	for (auto elem : lis)
		cout << elem << " ";
	cout << endl;
	lis.clear();
	copy(vec.begin(), vec.end(), inserter(lis,lis.begin()));
	for (auto elem : lis)
		cout << elem << " ";
	cout << endl;
	lis.clear();
	
	system("pause");
	return 0;
}