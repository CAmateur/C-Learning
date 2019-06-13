#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;
int main(int argc, char**argv)
{
	list<int> lis = { 1,2,3,4,5,6,7,3,0,1 };
	 
	 
	cout <<  *find(lis.cbegin(), lis.cend(), 0) << endl;
	system("pause");
	return 0;
}