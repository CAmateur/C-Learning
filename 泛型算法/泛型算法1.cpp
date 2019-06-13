#include<numeric>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(int argc, char**argv)
{
	vector<int> vec1{ 1,2,3,4,5,6,7,8,9,10 };
	cout << "此容器的元素为：(";
	for (int elem : vec1)
		 cout<< elem << " ";
	cout << ")" << endl;
	int numberall;
	numberall=accumulate(vec1.begin(),vec1.end(),2,multiplies<int>());//连乘最后乘2
	cout << "计算出来的积为：" << numberall << endl;

	vector<string> vec2{ "hello ","world","I","am","a","teacher","!" };
	cout << "此字符串为：（";

	for (string elem : vec2)
		cout << elem << " ";
	cout << ")" << endl;
	string stringall;
	stringall = accumulate(vec2.begin(), vec2.end(),string(" "));//以“ ”开头把后面的字符串全部整理起来!
	cout << "用了accumulate后：" << stringall << endl;
	system("pause");
	return 0;
}