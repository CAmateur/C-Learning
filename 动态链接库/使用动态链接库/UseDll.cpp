#include<iostream>
#include<Windows.h>
using namespace std;
//���庯��ָ��
typedef int(_stdcall *UseDllFunc)();
//��������ָ�����
UseDllFunc UseTest=NULL;

int main(int argc, char**argv)
{
	//����dll���ڴ��ȡ����ַhMoulde
	HINSTANCE hMoudle = LoadLibrary("Test.dll");
	//���ַ�����ȡ������ַ
	//��һ��:���ű�������
	UseTest = GetProcAddress(hMoudle, "_test@0");
	//�ڶ���:0xDΪ�������������
	//UseTest = GetProcAddress(hMoudle, (char*)0x1);
	if (hMoudle == NULL)
	{
		cout << "����dllʧ��!" << endl;
		return 0;
	}
	if (UseTest == NULL)
	{
		cout << "��������δ�ҵ�!" << endl;
		return 0;
	}


	cout << "dll��ַ:"<<hMoudle << endl << "��ȡ�ĺ�����ַ:"<<UseTest << endl << "���к������صĽ��:"<<UseTest() << endl;
	//ж��dll
	FreeLibrary(hMoudle);
	system("pause");

	return 0;
 }