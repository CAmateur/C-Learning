#include <winsock2.h>
#include <stdio.h>
#include "ping.h"
#include<string>
#include<iostream>
#include<fstream>
#include<mutex>
#include<thread>
#include<atomic>
using namespace std;
atomic<int> Times = 0;
#define THREAD_NUMBERS 6 //550
mutex m;
ULONG GetTickCountCalibrate()
{
	static ULONG s_ulFirstCallTick = 0;
	static LONGLONG s_ullFirstCallTickMS = 0;
	SYSTEMTIME systemtime;
	FILETIME filetime;
	GetLocalTime(&systemtime);
	SystemTimeToFileTime(&systemtime, &filetime);
	LARGE_INTEGER liCurrentTime;
	liCurrentTime.HighPart = filetime.dwHighDateTime;
	liCurrentTime.LowPart = filetime.dwLowDateTime;
	LONGLONG llCurrentTimeMS = liCurrentTime.QuadPart / 10000;

	if (s_ulFirstCallTick == 0)
	{
		s_ulFirstCallTick = GetTickCount();
	}
	if (s_ullFirstCallTickMS == 0)
	{
		s_ullFirstCallTickMS = llCurrentTimeMS;
	}

	return s_ulFirstCallTick + (ULONG)(llCurrentTimeMS - s_ullFirstCallTickMS);
}
atomic<int> run = 1;
void func1(char *szDestIP1)
{
	CPing objPing;
	PingReply reply;
	while (TRUE)
	{
		if (run == 0)
		{
			return;
		}
		//chrono::microseconds mysleep(200);
		//this_thread::sleep_for(mysleep);
		if (objPing.Ping(szDestIP1, &reply))
		{
			Times++;
			//printf("Pinging %s with %d bytes of data:\n", szDestIP1, DEF_PACKET_SIZE);
			//printf("Reply from %s: bytes=%d time=%ldms TTL=%ld\n", szDestIP1, reply1.m_dwBytes, reply1.m_dwRoundTripTime, reply1.m_dwTTL);
		}

	}
}
void func2()
{
	string flag;
	while (true)
	{
		cout << "输入 q 退出!" << endl;
		cin >> flag;
		if (flag == "q")
		{
			run = 0;
			return;
		}
		else
		{
			flag.clear();
		}
	}

}

int main(int argc, char**argv)
{
	ULONG OLD = GetTickCountCalibrate();
	ULONG NEW;
	char *addrc;
	char *szDestIP;
	string addrs;
	std::vector<std::thread> vecThread;
	cout << "请输入要怼的IP地址:";
	cin >> addrs;
	cout << "正在怼" << endl;
	addrc = new char[addrs.length() + 1]{ '\0' };
	memcpy(addrc, addrs.c_str(), addrs.length());
	szDestIP = addrc;
	for (int i = 0; i < THREAD_NUMBERS; i++)
	{
		vecThread.push_back(std::thread(func1, szDestIP));
	}
	thread t1(func2);
	t1.join();
	for (std::vector<std::thread>::iterator it = vecThread.begin(); it != vecThread.end(); ++it)
	{
		it->join();
	}

	NEW = GetTickCountCalibrate();
	cout << "共怼:" << Times << "次" << endl;
	cout << "消耗时间:" << (NEW - OLD) << endl;
	system("pause");
	return 0;
}