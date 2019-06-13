#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	vector<string> str(10, "hi" );
	
	for (vector<string>::iterator it1=str.begin(); it1 !=str.end(); ++it1)
		cout << *it1 << endl;
	system("pause");
	return 0;
}