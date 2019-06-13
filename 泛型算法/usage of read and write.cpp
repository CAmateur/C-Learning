#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
#include<iterator>
#include<fstream>
using namespace std;
int main(int argc, char**argv)
{
	vector<int> Vec1;
	vector<int>	Vec2;
	int Temp=0;
	string NameInFile("E:\\ReadFileContent.txt");
	string NameOutFile1("E:\\WriteFileContent1.txt");
	string NameOutFile2("E:\\WriteFileContent2.txt");
	ifstream InFile(NameInFile);
	ofstream OutFile1(NameOutFile1, ofstream::app);
	ofstream OutFile2(NameOutFile2, ofstream::app);
	
	while (InFile >> Temp)
	{
		if(Temp%2==0)
		Vec1.push_back(Temp);
		if (Temp % 2 != 0)
		Vec2.push_back(Temp);
	}
	for (int Elem : Vec1)
		OutFile1 << Elem<<"\n";
	for (int Elem1 : Vec2)
		OutFile2 << Elem1<<"\n";
	system("pause");
	return 0;
}
