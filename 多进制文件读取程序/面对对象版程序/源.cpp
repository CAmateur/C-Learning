#include<iostream>
#include"file_operation.h"
using namespace std;


int main(int argc, char**argv)
{
	string file_name = "E:/Program Files (x86)/Steam/GameOverlayUI.exe";
	char tem_char;
	file_operation read_file(file_name, 16, 8);
	while (cin >> tem_char)
	{
		switch (tem_char)
		{
		case 'd':read_file.read_down(); break;
		case 'u':read_file.read_up(); break;
		default:cout << "Ã»ÓÐ´ËÃüÁî!" << endl; break;
		}
	}
	system("pause");
	return 0;
}