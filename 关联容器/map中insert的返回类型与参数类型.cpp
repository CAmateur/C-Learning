#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<utility>
using namespace std;
int main(int argc, char**argv)
{
	map<string, vector<int>> mapp;
	vector<int> vec;
	pair<map<string, vector<int>>::iterator, bool> ref = 
		mapp.insert(make_pair("hello", vec));


	pair<map<string, vector<int>>::iterator, bool> ref = 
		mapp.insert(pair<string, vector<int>>("hello", vec));


	pair<map<string, vector<int>>::iterator, bool> ref = 
		mapp.insert(map<string,vector<int>>::value_type("hello",vec));
	//value_type在ma中指向的是pair
	system("pause");
	return 0;
}