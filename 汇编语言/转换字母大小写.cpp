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
		mov ecx, 4h		//����ѭ������
		mov ebx, p		//������ָ�봫��ebx
		mov eax, [ebx]	//��ebx�����ݴ���eax
		s:
		or al, 00100000b	//�������Ƶĵ�6λ���1
		mov [ebx],al		//��al��ֵ����ebxָ��ĵ�ַ
		add ebx,1h			//��ַ+1
		shr eax,8			//��eax��Ķ���������8λ
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