#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

//vector<int> filter(vector<int>& vec, int than_val, bool(*pred) (int, int))
//{
//	vector<int> vecTemp;
//
//	for (int x = 0; x < vec.size(); ++x)
//	{
//		if (pred(vec[x], than_val))
//			vecTemp.push_back(vec[x]);
//	}
//	return vecTemp;
//}
bool less_than(int v1, int v2)
{
	return v1 < v2 ? true : false;
}
bool greater_than(int v1, int v2)
{
	return v1 > v2 ? true : false;
}


void display(vector<int> vec)
{
	for (auto temp : vec)
	{
		cout << temp << endl;
	}
}
vector<int> filter(vector<int>& vec, int than_val,less<int> &lt)
{
	vector<int> vecTemp;
	vector<int>::const_iterator iter = vec.begin();
	while ((iter = find_if(iter, vec.end(), bind2nd(lt, than_val))) != vec.end())
	{
		vecTemp.push_back(*iter);
		iter++;
	}
	return vecTemp;
}
int main(int argc, char**argv)
{
	int num[7] = { 10,2,30,4,55,6,74 };
	vector<int> vec_a(num, num + 7);
	//sort(vec_a.begin(), vec_a.end(), greater<int>());
	//if (binary_search(vec_a.begin(), vec_a.end(), 30, greater<int>()))
	//{
	//	display(vec_a);
	//}//要配合着使用

	
	display(filter(vec_a, 10, less<int> &l));
	system("pause");
	return 0;
}