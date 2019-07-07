#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//void exemple(bool(*temp)(int x, int y))
//{
//	int a = 12, b = 13;
//	if (temp(a, b))
//	{
//		cout << a << endl;
//	}
//}

int main(int argc, char**argv)
{
	fstream file("E:/little story.txt", ios::in);
	string word;
	vector<string> vec_str;
	while (file >> word)
	{
		vec_str.push_back(word);
	}

	sort(vec_str.begin(), vec_str.end(), [](string a, string b) ->bool {if (a.size() < b.size())return true; return false; });

	for (string temp : vec_str)
	{
		cout << temp << " ";
	}

	system("pause");
	return 0;
}