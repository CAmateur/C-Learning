#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(int argc, char**argv)
{
	map<string, string> words = { {"hello","ÄãºÃ£¡"},
									{"you","Äã" }};
	words["hello"] = "ÄúºÃ";


	for (auto &w : words)
		cout << w.first << " " << w.second << " " << endl;
	system("pause");
	return 0;
}