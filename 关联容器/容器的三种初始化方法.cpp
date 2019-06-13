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

	//第一种初始化容器的方法


	//容器的初始化！
	vector<int> vec2(it->second.begin(),it->second.end());
	

	//第二种初始化容器的方法

	//这个不用规定容器大小因为用的是push_back
	vector<int> vec4;
	for (int a : it->second)
	{
		vec4.push_back(a);
	}
	//第三种初始化容器的方法
	copy(vec2.begin(), vec2.end(), cc);
	//规定容器的初始大小不然会出错！大小必须和进行copy的容器相同
	vector<int> vec3(5);
	copy(it->second.begin(), it->second.end(), vec3.begin());
	
	system("pause");
	return 0;
}