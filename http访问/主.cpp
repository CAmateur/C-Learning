#include<iostream>
#include<string>
#include<sstream>
#include"MyHttp.h"

using namespace std;
int main(int argc, char**argv)
{
	MyHttp http("sp0.baidu.com", 80);
	http.SetAccept("*/*");
	http.SetAccept_Language("zh-CN");
	http.SetCache_Control("max-age=0");
	http.SetConnection("Keep-Alive");
	http.SetHost("sp0.baidu.com");
	http.SetReferer("https://www.csdn.net/");
	http.SetUser_Agent("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/64.0.3282.140 Safari/537.36 Edge/17.17134");
	string html=http.PageAccess("GET", "https://sp0.baidu.com/5a1Fazu8AA54nxGko9WTAnF6hhy/su?wd=hhhhhhhh&p=3&cb=BaiduSuggestion.callbacks.give1555938158140&t=1555938188770");
	cout << html << endl;
	system("pause");
	return 0;
}


