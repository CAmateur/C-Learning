#include<fstream>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string FileLocotion("E:\\hhh.txt");
	string Contents;
	fstream trem;//�ȸ���Ȩ��
	trem.open(FileLocotion, fstream::in);
	while (trem >> Contents)
		cout << Contents << endl;
	trem.close();
	trem.open("FileLocotion", fstream::out | fstream::app);//��дȨ���Ҳ��ܽض��ļ��ض��ļ�Ҫ�ã�trunc��
	while (cin >> Contents)
	{
		if (Contents == "q")
			break;

		trem << Contents << endl;
	}

	trem.close();
	return 0;
}