#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main(int argc, char**argv)
{
	list<int> list1(7, 8);
	vector<int> vec2(5, 2);

	vector<double> vec1(list1.begin(), list1.end());
	vector<double>vec3(vec2.begin(), vec2.end());

	vector<double>::iterator it1 = vec1.begin();
	vector<double>::iterator it2 = vec3.begin();
	for (it1; it1 != vec1.end(); it1++)
		cout << *it1 << endl;
	for (it2; it2 != vec3.end(); it2++)
		cout << *it2 << endl;
	system("pause");
	return 0;
}