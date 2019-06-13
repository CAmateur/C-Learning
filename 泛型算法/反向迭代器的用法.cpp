#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char **argv)
{
	vector<int> Elem = { 1,2,3,4,5,6 };
	vector<int>::reverse_iterator Rit=Elem.rbegin();
	vector<int>::reverse_iterator RitEnd = Elem.rend();
	while (Rit != RitEnd)
		cout << *Rit++ << endl;

	system("pause");
	return 0;
}