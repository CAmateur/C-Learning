#include<iostream>
#include<map>
#include<utility>	
#include<string>
#include<vector>
using namespace std;
int main(int argc, char**argv)
{
	map<string, vector<string>> family;
	string surname;
	string name;

	while (cin >> surname && (surname != "end"))
		if (cin >> name && (name != "end"))
		pair<map<string,vector<string>>::iterator,bool> a=	
			family.insert(make_pair(surname,vector<string>(name)));
	system("pause");
	return 0;
}