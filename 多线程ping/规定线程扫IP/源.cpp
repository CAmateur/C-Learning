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
int h = 0; int l = 0;
atomic<int> Times = 0;
#define MAX_PING_TIMES 255
int THREAD_NUMBERS=0; //550
#define VECTOR_SIZE 10

vector<string> vec1;
string filename1("E:\\hh1.txt");
ofstream file1;
mutex m;
condition_variable cond;
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
void func1()
{
	double E = MAX_PING_TIMES;
	CPing objPing1;
	string addr1;
	PingReply reply1;
	while (TRUE)
	{
		{
			unique_lock<mutex> lz(m);
			addr1 = "10.31." + to_string(h) + "." + to_string(l);

			++l;
			if (l > MAX_PING_TIMES)
			{
				l = 0;
				++h;
			}
			if (h > MAX_PING_TIMES)
			{
				return;
			}
		}

		//chrono::microseconds mysleep(200);
		//this_thread::sleep_for(mysleep);
		char *addrc1 = new char[addr1.length() + 1]{ '\0' };
		memcpy(addrc1, addr1.c_str(), addr1.length());
		char *szDestIP1 = addrc1;
		if (objPing1.Ping(szDestIP1, &reply1))
		{
			Times++;
			printf("Pinging %s with %d bytes of data:\n", szDestIP1, DEF_PACKET_SIZE);
			printf("Reply from %s: bytes=%d time=%ldms TTL=%ld\n", szDestIP1, reply1.m_dwBytes, reply1.m_dwRoundTripTime, reply1.m_dwTTL);
			{
				std::unique_lock<std::mutex> mylock(m);
				vec1.push_back(addr1);
				if (vec1.size() > VECTOR_SIZE)
				{
					file1.open(filename1, ofstream::app);
					for (vector< string>::iterator it = vec1.begin(); it != vec1.end(); ++it)
					{
						file1 << *it << endl;
					}
					vec1.clear();
					file1.close();
				}
			}
		}
		delete[]addrc1;
	}
}

int main(int argc, char**argv)
{
	ULONG OLD = GetTickCountCalibrate();
	ULONG NEW;
	cout << "请输入要开启的线程数:";
	cin >> THREAD_NUMBERS;
	std::vector<std::thread> vecThread;
	for (int i = 0; i < THREAD_NUMBERS; i++)
	{
		vecThread.push_back(std::thread(func1));
	}
	for (std::vector<std::thread>::iterator it = vecThread.begin(); it != vecThread.end(); ++it)
	{
		it->join();
	}


	if (vec1.size() > 0)
	{
		file1.open(filename1, ofstream::app);
		for (vector< string>::iterator it = vec1.begin(); it != vec1.end(); ++it)
		{
			file1 << *it << endl;
		}

		vec1.clear();
		file1.close();
	}

	NEW = GetTickCountCalibrate();
	cout << "此时共" << Times << "台电脑在线并没有开启防火墙" << endl;
	cout << "消耗时间:" << (NEW - OLD) << endl;
	system("pause");
	return 0;
}