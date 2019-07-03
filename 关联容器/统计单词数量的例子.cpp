#include<iostream>
#include<string>
#include<map>
#include<set>
#include<fstream>
#include<Windows.h>

using namespace std;
int main(int argc, char**argv)
{
	string file_name = "E:\\hh.txt";
	string temp_str;

	/*byte temp[2048];*/
	//fstream file("E:\\hh.txt", ios::in | ios::binary);

	//file.read((char*)temp, sizeof(byte) * 2048);
	///*while (file >> str)
	//{
	//	cout << str << endl;
	//}*/
	//for (int i=0;i<2048;i++	)
	//{
	//	cout << temp[i];	
	//}

	map<string, int> voca_number;
	set<string> except_for = { "a","an","The" };
	
	fstream file;
	file.open(file_name, ios::in);
	if (file.bad())
	{
		cout << "文件读入失败" << endl;
	}

	while (file >> temp_str)
	{
		if(!except_for.count(temp_str))
		voca_number[temp_str]++;
	}
	cout << voca_number.size() << endl;
	map<string, int>::iterator it = voca_number.begin();
	for (; it != voca_number.end(); ++it)
	{
		cout << "单词：" << it->first;
		cout << "出现的次数"<<it->second << endl;
	}
	system("pause");
	return 0;
}