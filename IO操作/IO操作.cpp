#include<iostream>
using namespace std;
istream& nubiliti(istream& is)
{
	char word;
	while (is >> word)
	{
		cout << word;
	}
	return is;
}
int main()
{
	nubiliti(cin).clear();
	system("pause");

	return 0;
}