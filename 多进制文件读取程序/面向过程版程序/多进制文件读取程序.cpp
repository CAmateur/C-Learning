#include<iostream>
#include<fstream>
#include<Windows.h>
#include<bitset>
#include<memory>
#include<iomanip>
#include<set>
using namespace std;
#define BUFFER_SIZE 128
#define y_number 8

void print_mess(set<char> & set_temp, unique_ptr<char[]> &temp_ptr)
{
	for (int i = 0; i < BUFFER_SIZE; i += y_number)
	{
		//cout << (bitset<8>) buffer[i] << " ";//二进制8位1个字节输出
		//cout << (bitset<8>) buffer[i + 1] << " ";
		//cout << (bitset<8>) buffer[i + 2] << " ";
		//cout << (bitset<8>) buffer[i + 3] << "   ";
		cout << setiosflags(ios::right);//右对齐
		for (int t = i; t < i + y_number; ++t)
		{
			cout << setfill('0') << setw(2) << setbase(16) << (int)temp_ptr[t] << " ";
		}
		cout << "  ";
		for (int t = i; t < i + y_number; ++t)
		{
			if (set_temp.count(temp_ptr[t]))
				cout << temp_ptr[t];
		}
		cout << endl;
	}
}

int main(int argc, char**argv)
{
	try
	{
		string file_path("E:/little story.txt");
		//cin >> file_path;
		char except_for_char[] = " qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM!@#$%^&*()_+1234567890-=[]\\{}|;':\",./<>?";
		set<char> except_for(except_for_char, except_for_char + sizeof(except_for_char) - 1);
		//unique_ptr<byte[]>buffer(new byte[BUFFER_SIZE]); //销毁时自动使用delete[]
		shared_ptr<byte[]>buffer(new byte[BUFFER_SIZE], []() {});//销毁时不能自动使用delete[]需要指定删除器
		//编译器自动加\0代表着结束，而sizeof(except_for_char)的结果是加上\0的也就是比自己添加的多1
		fstream file(file_path, ios::in | ios::binary);//给予以二进制读入权限
		//file.seekg(0, ios::end);
		//fstream::pos_type ps = file.tellg();
		//int size_buff = (int)ps;
		//file.seekg(0, ios::beg);
		file.read((char*)buffer.get(), BUFFER_SIZE);
		print_mess(except_for,buffer);
		file.close();
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}
	system("pause");
	return 0;
}