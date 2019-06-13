#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
int main()
{
	string FileLocotion = "E:\\hhh.txt";
	string Content;
	vector<string> Contents;
	fstream fstrm(FileLocotion);
	while (fstrm >> Content)
	{
		Contents.push_back(Content);
	}
	fstrm.close();
	for (string Elem : Contents)
		cout << Elem << endl;
	system("pause");
	return 0;
}