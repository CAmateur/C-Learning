#include<iostream>
#include<string>
#include<map>
#include<utility>
#include<vector>
#include<ostream>
#include<iterator>
#include<algorithm>
using namespace std;
int main(int argc, char**argv)
{
	string name("hello");
	int x=1;
	map<string, vector<int>> mapp;
	vector<int> vec = {1,2,3,4,5};
	ostream_iterator<int> cc(cout, " ");
	mapp.insert(pair<string,vector<int>>(name,vec));
	map<string, vector<int>>::iterator it = mapp.find(name);

	//��һ�ֳ�ʼ�������ķ���


	//�����ĳ�ʼ����
	vector<int> vec2(it->second.begin(),it->second.end());
	

	//�ڶ��ֳ�ʼ�������ķ���

	//������ù涨������С��Ϊ�õ���push_back
	vector<int> vec4;
	for (int a : it->second)
	{
		vec4.push_back(a);
	}
	//�����ֳ�ʼ�������ķ���
	copy(vec2.begin(), vec2.end(), cc);
	//�涨�����ĳ�ʼ��С��Ȼ�������С����ͽ���copy��������ͬ
	vector<int> vec3(5);
	copy(it->second.begin(), it->second.end(), vec3.begin());
	
	system("pause");
	return 0;
}