#include<stdio.h>
#include<Windows.h>
#include<string>


char* HexToStr(DWORD adress)
{
	static char bufferStr[17];
	memset(bufferStr, 0x00, 17);
	char AdressChr[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	char high, low;
	
	
	const char* pointer = (const char*)&adress;

	for (int i = 3, n = 0; i >= 0; i--, n += 2)
	{
		high = ((pointer[i]) & 0xf0) >> 4;
		low = (pointer[i] & 0x0f);


		bufferStr[n] = AdressChr[high];
		bufferStr[n + 1] = AdressChr[low];
	}
	return bufferStr;


}



int main()
{

	char bufferStr[17];
	DWORD adress = 0x22a3A23E;
	MessageBoxA(0, (LPCSTR)HexToStr(adress), "ÕÒµ½»ùÖ·", 0);

	getchar();

	return 0;
}







