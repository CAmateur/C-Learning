#include<iostream>
#include<Windows.h>



//x32��ֻ�ܻ��x32�ľ��
BOOL MyCreatRemoteThread(DWORD dwProcessId, DWORD dwProcAddr)
{
	//1.��ȡ���̾��
	HANDLE hThreadId;
	HANDLE hProcess;
	HANDLE hThread;
	hProcess = 0;
	hThreadId = 0;
	hThread = 0;
	//ͨ������ID��ȡ���̾��
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);
	

	if (hProcess == NULL)
	{
		OutputDebugString("OpenProcess Error\n");
		return FALSE;
	}
	std::cout << hProcess << std::endl;
	//	CreateRemoteThread
	hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)dwProcAddr, NULL, 0, (LPDWORD)&hThreadId);
	if (hThread == NULL)
	{
		OutputDebugString("CreateRemoteThread Error\n");
		CloseHandle(hProcess);
		return FALSE;
	}
	std::cout << hThreadId << std::endl;
	std::cout << hThread << std::endl;
	CloseHandle(hProcess);
	CloseHandle(hThread);
	
	return TRUE;
}


int main(int aggc, char**aggv)
{
	MyCreatRemoteThread(4508, 0x452113);


	system("pause");
	return 0;
}