#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
int main(int argc, char**argv)
{
	map<string, vector<string>> family;
	string surname;
	string name;
	//输入数据功能
	while (cin >> surname && (surname != "end"))
	{	
		cout << "请输入家庭姓氏:";
		while (cin >> name&&(name != "end"))
		{
			cout << "请输入家庭成员的名字:";
			family[surname].push_back(name);
		}
		cout << endl;
	}

	//输入数据功能同上
	//两种写法意思一样，下方更为高逼格，且更简洁；lambda[&]根据函数体中的语句自动隐式捕获，下面lambda捕获的
	//是cin

	while ([&]()->bool {cout << "请输入家庭姓氏:" ; return cin >> surname&&(surname != "end"); }())
	{
		while ([&]()->bool {cout << "请输入家庭成员的名字:"; return cin >> name&&(name != "end"); }())
		{
			family[surname].push_back(name);
		}
	}
	//输出语句

	 
	for (map<string, vector<string>>::iterator it = family.begin(); it != family.end(); it++)
	{
		cout << "家庭:" << it->first << "成员:";
		for (vector<string>::iterator it1 = it->second.begin(); it1 != it->second.end(); it1++)
			cout << *it1 << " ";
		cout << endl;
	}


	system("pause");
	return 0;
}