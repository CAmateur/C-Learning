#include<iostream>
#include<vector>
#include<utility>	
#include<string>
using namespace std;
int main(int argc, char**argv)
{
	vector<pair<string,int>> vec;
	string content;
	int number;

	//第一种方法
	while (cin >> content && (content != "end"))
	{
		if (cin >> number && (number != 0))
		{
			//第一种方法初始化pair
			pair<string, int> par(content, number);
			vec.push_back(par);
		}
		else
			break;

	}
	//第二种方法
	while (cin >> content && (content != "end"))
	{
		if (cin >> number && (number != 0))
		{
			//第二种方法初始化pair
			pair<string, int> par = { content, number };
			vec.push_back(par);
		}
		else
			break;

	}

	//第三种方法
	while (cin >> content && (content != "end"))
	{
		if (cin >> number && (number != 0))
		{
			//第三种方法初始化pair
			auto par = make_pair(content, number);
			vec.push_back(par);
			//vec.push_back(make_pair(content,number));意思同上两句一样
		}
		else
			break;

	}

	system("pause");
	return 0;
}