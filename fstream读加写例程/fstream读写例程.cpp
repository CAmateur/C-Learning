#include<fstream>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string FileLocotion("E:\\hhh.txt");
	string Contents;
	fstream trem;//先给读权限
	trem.open(FileLocotion, fstream::in);
	while (trem >> Contents)
		cout << Contents << endl;
	trem.close();
	trem.open("FileLocotion", fstream::out | fstream::app);//给写权限且不能截断文件截断文件要用（trunc）
	while (cin >> Contents)
	{
		if (Contents == "q")
			break;

		trem << Contents << endl;
	}

	trem.close();
	return 0;
}