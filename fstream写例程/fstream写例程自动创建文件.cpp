#include<fstream>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string FileLocotion("E:\\hhh.txt");
	string Contents;
	fstream trem(FileLocotion,fstream::out);
	while (cin >> Contents)
	{
		if (Contents == "q")
			break;

		trem << Contents << endl;
	}

	trem.close();
	return 0;
}