#include<iostream>
#include<vector>
#include<numeric>
#include<string>
#include<algorithm>
using namespace std;
void elimDups(vector<string> &words)
{
	cout << "����֮ǰ��(";
	for (string word : words)
		cout << word << " ";
	cout << ")" << endl;

	sort(words.begin(), words.end());
	cout << "����֮��(";
	for (string word : words)
		cout << word << " ";
	cout << ")" << endl;
	
	vector<string>::iterator it1=unique(words.begin(), words.end());
	cout << "unique��(";
	for (string word : words)
		cout << word << " ";
	cout << ")" << endl;

	words.erase(it1, words.end());
	cout << "rease��(";
	for (string word : words)
		cout << word << " ";
	cout << ")" << endl;
	
}


int main(int argc, char**argv)
{
	vector<string> vec;
	string str;//i am a teacher . what are you  ?  are you a teacher  ?  oh ! i am a teacher too . what a coincidence !
	while (cin >> str)
	{
		if (str == "qqq")
			break;
		vec.emplace_back(str);
	}

	elimDups(vec);

	system("pause");

	return 0;
}