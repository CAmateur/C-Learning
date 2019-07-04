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
		fstream file("E:/hh.txt", ios::in | ios::binary);//�����Զ����ƶ���Ȩ��
		//file.seekg(0, ios::end);
		//fstream::pos_type ps = file.tellg();
		//int size_buff = (int)ps;
		//file.seekg(0, ios::beg);

		//�������Զ���\0�����Ž�������sizeof(except_for_char)�Ľ���Ǽ���\0��Ҳ���Ǳ��Լ���ӵĶ�1
		char except_for_char[] = " qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM!@#$%^&*()_+1234567890-=[]\\{}|;':\",./<>?";
		set<char> except_for(except_for_char, except_for_char + sizeof(except_for_char) - 1);
		
		unique_ptr<byte[]>buffer(new byte[BUFFER_SIZE]); //����ʱ�Զ�ʹ��delete[]
		//shared_ptr<byte[]>buffer(new byte[BUFFER_SIZE]);����ʱ�����Զ�ʹ��delete[]��Ҫָ��ɾ����


		file.read((char*)buffer.get(), BUFFER_SIZE);

		for (int i = 0; i < BUFFER_SIZE; i += 4)
		{
			cout << (bitset<8>) buffer[i] << " ";//������8λ1���ֽ����
			cout << (bitset<8>) buffer[i + 1] << " ";
			cout << (bitset<8>) buffer[i + 2] << " ";
			cout << (bitset<8>) buffer[i + 3] << "   ";
			cout << setiosflags(ios::right);//�Ҷ���
			cout << setfill('0') << setw(2) << setbase(16) << (int)buffer[i] << " ";//����2������ַ�0�������16�������
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