#include<sstream>
#include<iostream>
using namespace std;
int main()
{
	char tolk;

	ostringstream disword;
	string sentences;

	while (1)
	{
		cin >> tolk;
		if (tolk == 'q')
			break;
		disword.put(tolk);
	}
	sentences = disword.str();
	cout << sentences << endl;

	system("pause");
	return 0;
}