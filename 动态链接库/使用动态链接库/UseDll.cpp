#include<iostream>
#include<Windows.h>
using namespace std;
//定义函数指针
typedef int(_stdcall *UseDllFunc)();
//声明函数指针变量
UseDllFunc UseTest=NULL;

int main(int argc, char**argv)
{
	//加载dll到内存获取基地址hMoulde
	HINSTANCE hMoudle = LoadLibrary("Test.dll");
	//两种方法获取函数地址
	//第一种:符号必须完整
	UseTest = GetProcAddress(hMoudle, "_test@0");
	//第二种:0xD为导出函数的序号
	//UseTest = GetProcAddress(hMoudle, (char*)0x1);
	if (hMoudle == NULL)
	{
		cout << "加载dll失败!" << endl;
		return 0;
	}
	if (UseTest == NULL)
	{
		cout << "导出函数未找到!" << endl;
		return 0;
	}


	cout << "dll基址:"<<hMoudle << endl << "获取的函数地址:"<<UseTest << endl << "运行函数返回的结果:"<<UseTest() << endl;
	//卸载dll
	FreeLibrary(hMoudle);
	system("pause");

	return 0;
 }