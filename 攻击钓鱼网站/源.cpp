#include<iostream>
#include<string>
#include<sstream>
#include"MyHttp.h"
#include<fstream>
#include<regex>
#include<vector>
#include<atomic>
#include<thread>
#include<random>
#include<mutex>
#include<list>
using namespace std;
mutex mylock;
atomic<int> times = 0;
list<string> vecstr;
bool ddd(string &command)
{
	if (!vecstr.empty())
	{
		std::unique_lock<std::mutex> c(mylock);
		if (!vecstr.empty())
		{
			command = vecstr.front() + vecstr.front();
			vecstr.pop_front();
			return true;
		}
		return false;
	}
	return false;
}
void func()
{

	string str_find = "\\u63d2\\u5165\\u6210\\u529f2";
	string random_str_user;
	string str;
	MyHttp http("124.156.182.177", 80);
	while (true)
	{

		if (ddd(random_str_user))
		{
			//{
			//	un
			//uique_lock<mutex> my(mylock);
			//	cout << random_str_user << endl;
			//}




			//cout << random_str_pass << " " << random_str_user << endl;

			http.SetHost("myloy.cn");
			http.SetUser_Agent("Mozilla/5.0 (Windows NT 10.0; WOW64; rv:67.0) Gecko/20100101 Firefox/67.0");
			http.SetAccept("*/*");
			http.SetAccept_Language("zh-CN");
			http.SetConnection("keep-alive");
			http.SetContent_Type("application/x-www-form-urlencoded; charset=UTF-8");
			http.SetCookie("login_count=1");
			http.SetOrigin("http://myloy.cn");
			http.SetReferer("http://myloy.cn/Ru_op/");




			str = http.PageAccess("http://myloy.cn/plus/diy.php", "POST", "user=" + random_str_user + "&pass=" + random_str_user + "sb&action=post&do=4&diyid=4");
			if (str.find(str_find) == 265)
			{
				times++;
				mylock.lock();
				cout << "账号:" << random_str_user << "密码:" << random_str_user << "sb发送假数据成功!size:" << vecstr.size() << endl;
				mylock.unlock();
				system("cls");
			}
			else
			{
				//mylock.lock();
				//cout << "账号:" << random_str_user << "密码:" << random_str_user << "sb发送假数据失败!size:" << vecstr.size() << endl;
				//mylock.unlock();
			}
			//dddddddddddd:4294967295

			//random_str_user
		//	cout << str << endl;
			//目标网站
			//http://h.b2233.xyz/?m=vod-type-8-0.html
			//http.Close();
		}
		else
		{
			break;
		}
	}
}

void funcrand()
{
	srand((int)time(NULL));
	while (true)
	{
		{
			unique_lock<mutex> my(mylock);
			vecstr.push_back(to_string(rand()));
		}
		if (vecstr.size() > 10000)
		{
			cout << "结束" << endl;
			break;

		}
	}
}


int main(int argc, char**argv)
{


	//vector<thread> vecThread;
	//
	////uniform_int_distribution< int> u(0, 9);
	//
	//
	//
	//for (int i = 0; i < 1; i++)
	//{
	//	vecThread.push_back(thread(func));
	//}
	//
	//for (std::vector<std::thread>::iterator it = vecThread.begin(); it != vecThread.end(); ++it)
	//{
	//	it->join();
	//}
	cout << "共发送假数据:" << times << endl;



	///*
	//string filename("C:\\Users\\guibinw\\Desktop\\webstr.txt");
	//ofstream file(filename,ios::binary);
	//file.write(webstr.c_str(), webstr.size());
	//file.close();
	//*/

	//string filesuffix;
	//string filepath;
	//string host;
	//int t = 0;
	//for (string webstr : vec)
	//{
	//	//匹配host
	//	for (string::iterator it1 = webstr.begin() + 7; it1 != webstr.begin() + 22; ++it1)
	//	{
	//		host += *it1;
	//	}
	//	//匹配文件后缀名
	//	for (string::iterator it = webstr.end() - 4; it != webstr.end(); ++it)
	//	{
	//		filesuffix += *it;
	//	}
	//	//合成文件名字通过变量t是文件名称不同
	//	filepath = "C:\\Users\\guibinw\\Desktop\\hhh\\" + to_string(t) + filesuffix;
	//	cout << filepath << endl;
	//	MyHttp http(host, 80);

	//	http.SetHost(host);
	//	host.clear();
	//	filesuffix.clear();
	//	string htmlstr;
	//	htmlstr = http.PageAccess(webstr, "GET");
	//	if (htmlstr != "")
	//	{
	//		cout << "DownImage Succeed" << endl;
	//		regex k("Content-Length: [\\d]+");
	//		string tempsize;
	//		string temstr;
	//		int tsize = 0;
	//		for (sregex_iterator it2(htmlstr.begin(), htmlstr.end(), k), it2_end; it2 != it2_end; ++it2)
	//		{
	//			temstr = it2->str();
	//			for (string::iterator it3 = temstr.begin() + 16; it3 != temstr.end(); ++it3)
	//			{
	//				tempsize += *it3;
	//			}
	//		}
	//		tsize = atoi(tempsize.c_str());
	//		ofstream file(filepath, ios::binary);
	//		for (string::iterator it4 = htmlstr.end() - tsize; it4 != htmlstr.end(); ++it4)
	//		{
	//			file.write(&(*it4), sizeof(char));
	//		}
	//		file.close();

	//		cout << tsize << endl;
	//		++t;
	//	}
	//	else
	//	{
	//		cout << "DownImage error" << endl;
	//	}
	//	http.Close();
	//	filepath.clear();

	//}

	system("pause");
	return 0;
}


