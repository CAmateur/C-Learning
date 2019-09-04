#include<iostream>
using namespace std;




int main(int argc, char**argv)
{
	char chr[] = { 0x41,0x42,0x43,0x44};//A,B,C,D
	
	char *p = chr;
	_asm
	{
		push eax
		push ebx
		push ecx
		mov ecx, 4h		//设置循环次数
		mov ebx, p		//将数组指针传给ebx
		mov eax, [ebx]	//将ebx的内容传给eax
		s:
		or al, 00100000b	//将二进制的第6位或成1
		mov [ebx],al		//将al的值传入ebx指向的地址
		add ebx,1h			//地址+1
		shr eax,8			//将eax里的二进制右移8位
		loop s
		pop ecx
		pop ebx
		pop eax
	}
	
	for (char elem : chr)
		cout << elem << endl;

	system("pause");
	return 0;
}