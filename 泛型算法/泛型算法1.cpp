#include<numeric>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(int argc, char**argv)
{
	vector<int> vec1{ 1,2,3,4,5,6,7,8,9,10 };
	cout << "��������Ԫ��Ϊ��(";
	for (int elem : vec1)
		 cout<< elem << " ";
	cout << ")" << endl;
	int numberall;
	numberall=accumulate(vec1.begin(),vec1.end(),2,multiplies<int>());//��������2
	cout << "��������Ļ�Ϊ��" << numberall << endl;

	vector<string> vec2{ "hello ","world","I","am","a","teacher","!" };
	cout << "���ַ���Ϊ����";

	for (string elem : vec2)
		cout << elem << " ";
	cout << ")" << endl;
	string stringall;
	stringall = accumulate(vec2.begin(), vec2.end(),string(" "));//�ԡ� ����ͷ�Ѻ�����ַ���ȫ����������!
	cout << "����accumulate��" << stringall << endl;
	system("pause");
	return 0;
}