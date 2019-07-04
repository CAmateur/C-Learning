#include<iostream>
#include<fstream>
#include<Windows.h>
#include<bitset>
#include<memory>
#include<iomanip>
#include<set>
using namespace std;
#define BUFFER_SIZE 512
int main(int argc, char**argv)
{


	try
	{
		fstream file("E:/hh.txt", ios::in | ios::binary);//给予以二进制读入权限
		//file.seekg(0, ios::end);
		//fstream::pos_type ps = file.tellg();
		//int size_buff = (int)ps;
		//file.seekg(0, ios::beg);

		//编译器自动加\0代表着结束，而sizeof(except_for_char)的结果是加上\0的也就是比自己添加的多1
		char except_for_char[] = " qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM!@#$%^&*()_+1234567890-=[]\\{}|;':\",./<>?";
		set<char> except_for(except_for_char, except_for_char + sizeof(except_for_char) - 1);
		
		unique_ptr<byte[]>buffer(new byte[BUFFER_SIZE]); //销毁时自动使用delete[]
		//shared_ptr<byte[]>buffer(new byte[BUFFER_SIZE]);销毁时不能自动使用delete[]需要指定删除器


		file.read((char*)buffer.get(), BUFFER_SIZE);

		for (int i = 0; i < BUFFER_SIZE; i += 4)
		{
			cout << (bitset<8>) buffer[i] << " ";//二进制8位1个字节输出
			cout << (bitset<8>) buffer[i + 1] << " ";
			cout << (bitset<8>) buffer[i + 2] << " ";
			cout << (bitset<8>) buffer[i + 3] << "   ";
			cout << setiosflags(ios::right);//右对齐
			cout << setfill('0') << setw(2) << setbase(16) << (int)buffer[i] << " ";//不够2宽度用字符0填充且以16进制输出
			cout << setfill('0') << setw(2) << setbase(16) << (int)buffer[i + 1] << " ";
			cout << setfill('0') << setw(2) << setbase(16) << (int)buffer[i + 2] << " ";
			cout << setfill('0') << setw(2) << setbase(16) << (int)buffer[i + 3] << "   ";

			if (except_for.count(buffer[i]))
				cout << buffer[i];
			if (except_for.count(buffer[i + 1]))
				cout << buffer[i + 1];
			if (except_for.count(buffer[i + 2]))
				cout << buffer[i + 2];
			if (except_for.count(buffer[i + 3]))
				cout << buffer[i + 3];
			cout << endl;
		}


		file.close();
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}


	system("pause");
	return 0;
}