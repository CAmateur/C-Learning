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

	//��һ�ַ���
	while (cin >> content && (content != "end"))
	{
		if (cin >> number && (number != 0))
		{
			//��һ�ַ�����ʼ��pair
			pair<string, int> par(content, number);
			vec.push_back(par);
		}
		else
			break;

	}
	//�ڶ��ַ���
	while (cin >> content && (content != "end"))
	{
		if (cin >> number && (number != 0))
		{
			//�ڶ��ַ�����ʼ��pair
			pair<string, int> par = { content, number };
			vec.push_back(par);
		}
		else
			break;

	}

	//�����ַ���
	while (cin >> content && (content != "end"))
	{
		if (cin >> number && (number != 0))
		{
			//�����ַ�����ʼ��pair
			auto par = make_pair(content, number);
			vec.push_back(par);
			//vec.push_back(make_pair(content,number));��˼ͬ������һ��
		}
		else
			break;

	}

	system("pause");
	return 0;
}