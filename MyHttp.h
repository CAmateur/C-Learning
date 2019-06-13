#pragma once
#pragma comment(lib,"ws2_32.lib")
#include<iostream>
#include<string>
#include<sstream>
#include<WinSock2.h>

class MyHttp
{
public:
	MyHttp(std::string serverAdder, int port);
	~MyHttp();
	//<param name = "adder">这里是参数 b 的说明< / param>
	std::string PageAccess(std::string accessMethod,std::string pageAddr,std::string data );
	std::string GetCookie(std::string str);//将从网页截取Cookie
	void Init();
	void Close();
	std::string UtfToGbk(const char* utf8);
	void SetWaitTime(int waittime);
	void SetAccept(std::string accept = "");//可接受的响应内容类型
	void SetAccept_Charset(std::string accept_Charset);//可接受的字符集 
	void SetAccept_Encoding(std::string accept_Encoding);//可接受的响应内容的编码方式
	void SetAccept_Language(std::string accept_Language);//可接受的响应内容语言列表
	void SetAccept_Datetime(std::string accept_Datetime);//可接受的按照时间来表示的响应内容版本 
	void SetAuthorization(std::string authorization);//用于表示HTTP协议中需要认证资源的认证信息 
	void SetCache_Control(std::string cache_Control);//用来指定当前的请求/回复中的，是否使用缓存机制。
	void SetConnection(std::string connection);//客户端（浏览器）想要优先使用的连接类型 
	void SetCookie(std::string cookie);
	void SetContent_MD5(std::string content_MD5);//请求体的内容的二进制 MD5 散列值（数字签名），以 Base64 编码的结果 
	void SetContent_Type(std::string content_Type);//请求体的MIME类型 （用于POST和PUT请求中）
	void SetDate(std::string date);//发送该消息的日期和时间（以RFC 7231中定义的"HTTP日期"格式来发送） 
	void SetExpect(std::string expect);//表示客户端要求服务器做出特定的行为 
	void SetFrom(std::string from);//发起此请求的用户的邮件地址 
	void SetHost(std::string host);//表示服务器的域名以及服务器所监听的端口号。如果所请求的端口是对应的服务的标准端口（80），则端口号可以省略。 
	void SetIf_Match(std::string if_Match);//仅当客户端提供的实体与服务器上对应的实体相匹配时，才进行对应的操作。主要用于像 PUT 这样的方法中，仅当从用户上次更新某个资源后，该资源未被修改的情况下，才更新该资源。
	void SetIf_Modified_Since(std::string if_Modified_Since);//允许在对应的资源未被修改的情况下返回304未修改 
	void SetIf_None_Match(std::string if_None_Match);//允许在对应的内容未被修改的情况下返回304未修改（ 304 Not Modified ），参考 超文本传输协议 的实体标记 
	void SetIf_Range(std::string if_Range);//如果该实体未被修改过，则向返回所缺少的那一个或多个部分。否则，返回整个新的实体
	void SetIf_Unmodified_Since(std::string if_Unmodified_Since);//仅当该实体自某个特定时间以来未被修改的情况下，才发送回应。
	void SetMax_Forwards(std::string max_Forwards);//限制该消息可被代理及网关转发的次数。
	void SetOrigin(std::string origin);//发起一个针对跨域资源共享的请求
	void SetPragma(std::string pragma);//与具体的实现相关，这些字段可能在请求/回应链中的任何时候产生
	void SetProxy_Authorization(std::string proxy_Authorization);//用于向代理进行认证的认证信息
	void SetRange(std::string range);//表示请求某个实体的一部分，字节偏移以0开始
	void SetReferer(std::string referer);//表示浏览器所访问的前一个页面，可以认为是之前访问页面的链接将浏览器带到了当前页面。Referer其实是Referrer这个单词，但RFC制作标准时给拼错了，后来也就将错就错使用Referer了
	void SetTE(std::string tE);//浏览器预期接受的传输时的编码方式：可使用回应协议头Transfer-Encoding中的值（还可以使用"trailers"表示数据传输时的分块方式）用来表示浏览器希望在最后一个大小为0的块之后还接收到一些额外的字段
	void SetUser_Agent(std::string user_Agent);//浏览器的身份标识字符串 
	void SetUpgrade(std::string upgrade);//要求服务器升级到一个高版本协议
	void SetVia(std::string via);//告诉服务器，这个请求是由哪些代理发出的
	void SetWarning(std::string warning);//一个一般性的警告，表示在实体内容体中可能存在错误
	void SetServerAddr(std::string serverAddr);



private:
	std::string Accept;//可接受的响应内容类型
	std::string Accept_Charset;//可接受的字符集 
	std::string Accept_Encoding;//可接受的响应内容的编码方式
	std::string Accept_Language;//可接受的响应内容语言列表
	std::string Accept_Datetime;//可接受的按照时间来表示的响应内容版本 
	std::string Authorization;//用于表示HTTP协议中需要认证资源的认证信息 
	std::string Cache_Control;//用来指定当前的请求/回复中的，是否使用缓存机制。
	std::string Connection;//客户端（浏览器）想要优先使用的连接类型 
	std::string Cookie;//
	std::string Content_MD5;//请求体的内容的二进制 MD5 散列值（数字签名），以 Base64 编码的结果 
	std::string Content_Type;//请求体的MIME类型 （用于POST和PUT请求中）
	std::string Date;//发送该消息的日期和时间（以RFC 7231中定义的"HTTP日期"格式来发送） 
	std::string Expect;//表示客户端要求服务器做出特定的行为 
	std::string From;//发起此请求的用户的邮件地址 
	std::string Host;//表示服务器的域名以及服务器所监听的端口号。如果所请求的端口是对应的服务的标准端口（80），则端口号可以省略。 
	std::string If_Match;//仅当客户端提供的实体与服务器上对应的实体相匹配时，才进行对应的操作。主要用于像 PUT 这样的方法中，仅当从用户上次更新某个资源后，该资源未被修改的情况下，才更新该资源。
	std::string If_Modified_Since;//允许在对应的资源未被修改的情况下返回304未修改 
	std::string If_None_Match;//允许在对应的内容未被修改的情况下返回304未修改（ 304 Not Modified ），参考 超文本传输协议 的实体标记 
	std::string If_Range;//如果该实体未被修改过，则向返回所缺少的那一个或多个部分。否则，返回整个新的实体
	std::string If_Unmodified_Since;//仅当该实体自某个特定时间以来未被修改的情况下，才发送回应。
	std::string Max_Forwards;//限制该消息可被代理及网关转发的次数。
	std::string Origin;//发起一个针对跨域资源共享的请求
	std::string Pragma;//与具体的实现相关，这些字段可能在请求/回应链中的任何时候产生
	std::string Proxy_Authorization;//用于向代理进行认证的认证信息
	std::string Range;//表示请求某个实体的一部分，字节偏移以0开始
	std::string Referer;//表示浏览器所访问的前一个页面，可以认为是之前访问页面的链接将浏览器带到了当前页面。Referer其实是Referrer这个单词，但RFC制作标准时给拼错了，后来也就将错就错使用Referer了
	std::string TE;//浏览器预期接受的传输时的编码方式：可使用回应协议头Transfer-Encoding中的值（还可以使用"trailers"表示数据传输时的分块方式）用来表示浏览器希望在最后一个大小为0的块之后还接收到一些额外的字段
	std::string User_Agent;//浏览器的身份标识字符串 
	std::string Upgrade;//要求服务器升级到一个高版本协议
	std::string Via;//告诉服务器，这个请求是由哪些代理发出的
	std::string Warning;//一个一般性的警告，表示在实体内容体中可能存在错误
	std::string ServerAddr;//服务器地址
	int ServerPort;//服务器端口
	int WaitTime;
	SOCKET Socket;//自己创建的套接字可以理解为自己的端口
	std::string GetHtml();
};

std::string MyHttp::PageAccess(std::string accessMethod, std::string pageAddr,  std::string data = "")
{
	if (accessMethod =="POST")
	{
		std::stringstream request;
		request << "POST " << pageAddr << " HTTP/1.1\r\n";
		if (this->Accept != "")
			request << "Accept:" << this->Accept << "\r\n";
		if (this->Accept_Charset != "")
			request << "Accept-Charset:" << this->Accept_Charset << "\r\n";
		if (this->Accept_Encoding != "")
			request << "Accept-Encoding:" << this->Accept_Encoding << "\r\n";
		if (this->Accept_Language != "")
			request << "Accept-Language:" << this->Accept_Language << "\r\n";
		if (this->Accept_Datetime != "")
			request << "Accept-Datetime:" << this->Accept_Datetime << "\r\n";
		if (this->Authorization != "")
			request << "Authorization:" << this->Authorization << "\r\n";
		if (this->Cache_Control != "")
			request << "Cache-Control:" << this->Cache_Control << "\r\n";
		if (this->Connection != "")
			request << "Connection:" << this->Connection << "\r\n";
		if (this->Cookie != "")
			request <<"Cookie:"<< this->Cookie <<"\r\n";
		request << "Content-Length:" << data.length() << "\r\n";
		if (this->Content_MD5 != "")
			request << "Content-MD5:" << this->Content_MD5 << "\r\n";
		if (this->Content_Type != "")
			request << "Content-Type:"<<this->Content_Type<<"\r\n";
		if (this->Date != "")
			request << "Date:" << this->Date << "\r\n";
		if (this->Expect != "")
			request << "Expect:" << this->Expect << "\r\n";
		if (this->From != "")
			request << "From:" << this->From << "\r\n";
		if (this->Host != "")
			request << "Host:" << this->Host << "\r\n";
		if (this->If_Match != "")
			request << "If-Match:" << this->If_Match << "\r\n";
		if (this->If_Modified_Since != "")
			request << "If-Modified-Since :" << this->If_Modified_Since << "\r\n";
		if (this->If_None_Match != "")
			request << "If-None-Match:" << this->If_None_Match << "\r\n";
		if (this->If_Range != "")
			request << "If-Range :" << this->If_Range << "\r\n";
		if (this->If_Unmodified_Since != "")
			request << "If-Unmodified-Since:" << this->If_Unmodified_Since << "\r\n";
		if (this->Max_Forwards != "")
			request << "Max-Forwards:" << this->Max_Forwards << "\r\n";
		if (this->Origin != "")
			request << "Origin:" << this->Origin << "\r\n";
		if (this->Pragma != "")
			request << "Pragma:" << this->Pragma << "\r\n";
		if (this->Proxy_Authorization != "")
			request << "Proxy-Authorization:" << this->Proxy_Authorization << "\r\n";
		if (this->Range != "")
			request << "Range:" << this->Range << "\r\n";
		if (this->Referer != "")
			request << "Referer:" << this->Referer << "\r\n";
		if (this->TE != "")
			request << "TE:" << this->TE << "\r\n";
		if (this->User_Agent != "")
			request << "User-Agent:" << this->User_Agent << "\r\n";
		if (this->Upgrade != "")
			request << "Upgrade:" << this->Upgrade << "\r\n";
		if (this->Via != "")
			request << "Via:" << this->Via << "\r\n";
		if (this->Warning != "")
			request << "Warning:" << this->Warning << "\r\n";
		request << "\r\n";
		request << data;
		std::string Post = request.str();
		std::cout << Post << std::endl;
		if (send(this->Socket, Post.c_str(), Post.size(), 0)>0)
		{
			std::cout << "Post Succeed" << std::endl;
		}
		else
		{
			std::cout << "Post error" << std::endl;

		}
		std::string str = this->GetHtml();
		
		return str;
	}
	else if (accessMethod == "GET")
	{
		std::stringstream request;
		request<<"GET " + pageAddr + " HTTP/1.1\r\n";
		if (this->Accept != "")
			request << "Accept:" << this->Accept << "\r\n";
		if (this->Accept_Charset != "")
			request << "Accept-Charset:" << this->Accept_Charset << "\r\n";
		if (this->Accept_Encoding != "")
			request << "Accept-Encoding:" << this->Accept_Encoding << "\r\n";
		if (this->Accept_Language != "")
			request << "Accept-Language:" << this->Accept_Language << "\r\n";
		if (this->Accept_Datetime != "")
			request << "Accept-Datetime:" << this->Accept_Datetime << "\r\n";
		if (this->Authorization != "")
			request << "Authorization:" << this->Authorization << "\r\n";
		if (this->Cache_Control != "")
			request << "Cache-Control:" << this->Cache_Control << "\r\n";
		if (this->Connection != "")
			request << "Connection:" << this->Connection << "\r\n";
		else if (this->Cookie != "")
			request << "Cookie:" << this->Cookie<<"\r\n";
		if (this->Content_MD5 != "")
			request << "Content-MD5:" << this->Content_MD5 << "\r\n";
		if (this->Content_Type != "")
			request << "Content-Type:"<<this->Content_Type<<"\r\n";
		if (this->Date != "")
			request << "Date:" << this->Date << "\r\n";
		if (this->Expect != "")
			request << "Expect:" << this->Expect << "\r\n";
		if (this->From != "")
			request << "From:" << this->From << "\r\n";
		if (this->Host != "")
			request << "Host:" << this->Host << "\r\n";
		if (this->If_Match != "")
			request << "If-Match:" << this->If_Match << "\r\n";
		if (this->If_Modified_Since != "")
			request << "If-Modified-Since :" << this->If_Modified_Since << "\r\n";
		if (this->If_None_Match != "")
			request << "If-None-Match:" << this->If_None_Match << "\r\n";
		if (this->If_Range != "")
			request << "If-Range :" << this->If_Range << "\r\n";
		if (this->If_Unmodified_Since != "")
			request << "If-Unmodified-Since:" << this->If_Unmodified_Since << "\r\n";
		if (this->Max_Forwards != "")
			request << "Max-Forwards:" << this->Max_Forwards << "\r\n";
		if (this->Origin != "")
			request << "Origin:" << this->Origin << "\r\n";
		if (this->Pragma != "")
			request << "Pragma:" << this->Pragma << "\r\n";
		if (this->Proxy_Authorization != "")
			request << "Proxy-Authorization:" << this->Proxy_Authorization << "\r\n";
		if (this->Range != "")
			request << "Range:" << this->Range << "\r\n";
		if (this->Referer != "")
			request << "Referer:" << this->Referer << "\r\n";
		if (this->TE != "")
			request << "TE:" << this->TE << "\r\n";
		if (this->User_Agent != "")
			request << "User-Agent:" << this->User_Agent << "\r\n";
		if (this->Upgrade != "")
			request << "Upgrade:" << this->Upgrade << "\r\n";
		if (this->Via != "")
			request << "Via:" << this->Via << "\r\n";
		if (this->Warning != "")
			request << "Warning:" << this->Warning << "\r\n";
		request << "\r\n";
		std::string Get = request.str();
		std::cout << Get << std::endl;
		if (send(this->Socket, Get.c_str(), Get.size(), 0)>0)
		{
			std::cout << "Get Succeed!" << std::endl;
		}
		else
		{
			std::cout << "Get Error!" << std::endl;

		}
		std::string str = this->GetHtml();
		return str;

	}

}
void MyHttp::SetWaitTime(int waittime) { this->WaitTime = waittime; }
void MyHttp::SetAccept(std::string accept) { this->Accept = accept; }
void MyHttp::SetAccept_Charset(std::string accept_Charset) { this->Accept_Charset = accept_Charset; }//可接受的字符集 
void MyHttp::SetAccept_Encoding(std::string accept_Encoding) { this->Accept_Encoding = accept_Encoding; }//可接受的响应内容的编码方式
void MyHttp::SetAccept_Language(std::string accept_Language) { this->Accept_Language = accept_Language; }//可接受的响应内容语言列表
void MyHttp::SetAccept_Datetime(std::string accept_Datetime) { this->Accept_Datetime = accept_Datetime; }//可接受的按照时间来表示的响应内容版本 
void MyHttp::SetAuthorization(std::string authorization) { this->Authorization = authorization; }//用于表示HTTP协议中需要认证资源的认证信息 
void MyHttp::SetCache_Control(std::string cache_Control) { this->Cache_Control = cache_Control; }//用来指定当前的请求/回复中的，是否使用缓存机制。
void MyHttp::SetConnection(std::string connection) { this->Connection = connection; }//客户端（浏览器）想要优先使用的连接类型 
void MyHttp::SetCookie(std::string cookie) { this->Cookie = cookie; }//
void MyHttp::SetContent_MD5(std::string content_MD5) { this->Content_MD5 = content_MD5; }//请求体的内容的二进制 MD5 散列值（数字签名），以 Base64 编码的结果 
void MyHttp::SetContent_Type(std::string content_Type) { this->Content_Type = content_Type; }//请求体的MIME类型 （用于POST和PUT请求中）
void MyHttp::SetDate(std::string date) { this->Date = date; }//发送该消息的日期和时间（以RFC 7231中定义的"HTTP日期"格式来发送） 
void MyHttp::SetExpect(std::string expect) { this->Expect = expect; }//表示客户端要求服务器做出特定的行为 
void MyHttp::SetFrom(std::string from) { this->From = from; }//发起此请求的用户的邮件地址 
void MyHttp::SetHost(std::string host) { this->Host = host; }//表示服务器的域名以及服务器所监听的端口号。如果所请求的端口是对应的服务的标准端口（80），则端口号可以省略。 
void MyHttp::SetIf_Match(std::string if_Match) { this->If_Match = if_Match; }//仅当客户端提供的实体与服务器上对应的实体相匹配时，才进行对应的操作。主要用于像 PUT 这样的方法中，仅当从用户上次更新某个资源后，该资源未被修改的情况下，才更新该资源。
void MyHttp::SetIf_Modified_Since(std::string if_Modified_Since) {this->If_Modified_Since = if_Modified_Since;}//允许在对应的资源未被修改的情况下返回304未修改 
void MyHttp::SetIf_None_Match(std::string if_None_Match) { this->If_None_Match = if_None_Match; }//允许在对应的内容未被修改的情况下返回304未修改（ 304 Not Modified ），参考 超文本传输协议 的实体标记 
void MyHttp::SetIf_Range(std::string if_Range) { this->If_Range = if_Range; }//如果该实体未被修改过，则向返回所缺少的那一个或多个部分。否则，返回整个新的实体
void MyHttp::SetIf_Unmodified_Since(std::string if_Unmodified_Since) { this->If_Unmodified_Since = if_Unmodified_Since; }//仅当该实体自某个特定时间以来未被修改的情况下，才发送回应。
void MyHttp::SetMax_Forwards(std::string max_Forwards) { this->Max_Forwards = max_Forwards; }//限制该消息可被代理及网关转发的次数。
void MyHttp::SetOrigin(std::string origin) { this->Origin = origin; }//发起一个针对跨域资源共享的请求
void MyHttp::SetPragma(std::string pragma) { this->Pragma = pragma; }//与具体的实现相关，这些字段可能在请求/回应链中的任何时候产生
void MyHttp::SetProxy_Authorization(std::string proxy_Authorization) { this->Proxy_Authorization = proxy_Authorization; }//用于向代理进行认证的认证信息
void MyHttp::SetRange(std::string range) { this->Range = range; }//表示请求某个实体的一部分，字节偏移以0开始
void MyHttp::SetReferer(std::string referer) { this->Referer = referer; }//表示浏览器所访问的前一个页面，可以认为是之前访问页面的链接将浏览器带到了当前页面。Referer其实是Referrer这个单词，但RFC制作标准时给拼错了，后来也就将错就错使用Referer了
void MyHttp::SetTE(std::string tE) { this->TE = tE; }//浏览器预期接受的传输时的编码方式：可使用回应协议头Transfer-Encoding中的值（还可以使用"trailers"表示数据传输时的分块方式）用来表示浏览器希望在最后一个大小为0的块之后还接收到一些额外的字段
void MyHttp::SetUser_Agent(std::string user_Agent) { this->User_Agent = user_Agent; }//浏览器的身份标识字符串 
void MyHttp::SetUpgrade(std::string upgrade) { this->Upgrade = upgrade; }//要求服务器升级到一个高版本协议
void MyHttp::SetVia(std::string via) { this->Via = via; }//告诉服务器，这个请求是由哪些代理发出的
void MyHttp::SetWarning(std::string warning) { this->Warning = warning; }//一个一般性的警告，表示在实体内容体中可能存在错误
void MyHttp::SetServerAddr(std::string serverAddr) { this->ServerAddr = serverAddr; }
MyHttp::~MyHttp()
{
	this->Close();
}
MyHttp::MyHttp(std::string serverAdder, int port):ServerAddr(serverAdder),ServerPort(port)
{
	this->WaitTime = 3000;
	this->Accept = "";//可接受的响应内容类型
	this->Accept_Charset = "";//可接受的字符集 
	this->Accept_Encoding = "";//可接受的响应内容的编码方式
	this->Accept_Language = "";//可接受的响应内容语言列表
	this->Accept_Datetime = "";//可接受的按照时间来表示的响应内容版本 
	this->Authorization = "";//用于表示HTTP协议中需要认证资源的认证信息 
	this->Cache_Control = "";//用来指定当前的请求/回复中的，是否使用缓存机制。
	this->Connection = "";//客户端（浏览器）想要优先使用的连接类型 
	this->Cookie = "";//
	this->Content_MD5 = "";//请求体的内容的二进制 MD5 散列值（数字签名），以 Base64 编码的结果 
	this->Content_Type = "";//请求体的MIME类型 （用于POST和PUT请求中）
	this->Date = "";//发送该消息的日期和时间（以RFC 7231中定义的"HTTP日期"格式来发送） 
	this->Expect = "";//表示客户端要求服务器做出特定的行为 
	this->From = "";//发起此请求的用户的邮件地址 
	this->Host = "";//表示服务器的域名以及服务器所监听的端口号。如果所请求的端口是对应的服务的标准端口（80），则端口号可以省略。 
	this->If_Match = "";//仅当客户端提供的实体与服务器上对应的实体相匹配时，才进行对应的操作。主要用于像 PUT 这样的方法中，仅当从用户上次更新某个资源后，该资源未被修改的情况下，才更新该资源。
	this->If_Modified_Since = "";//允许在对应的资源未被修改的情况下返回304未修改 
	this->If_None_Match = "";//允许在对应的内容未被修改的情况下返回304未修改（ 304 Not Modified ），参考 超文本传输协议 的实体标记 
	this->If_Range = "";//如果该实体未被修改过，则向返回所缺少的那一个或多个部分。否则，返回整个新的实体
	this->If_Unmodified_Since = "";//仅当该实体自某个特定时间以来未被修改的情况下，才发送回应。
	this->Max_Forwards = "";//限制该消息可被代理及网关转发的次数。
	this->Origin = "";//发起一个针对跨域资源共享的请求
	this->Pragma = "";//与具体的实现相关，这些字段可能在请求/回应链中的任何时候产生
	this->Proxy_Authorization = "";//用于向代理进行认证的认证信息
	this->Range = "";//表示请求某个实体的一部分，字节偏移以0开始
	this->Referer = "";//表示浏览器所访问的前一个页面，可以认为是之前访问页面的链接将浏览器带到了当前页面。Referer其实是Referrer这个单词，但RFC制作标准时给拼错了，后来也就将错就错使用Referer了
	this->TE = "";//浏览器预期接受的传输时的编码方式：可使用回应协议头Transfer-Encoding中的值（还可以使用"trailers"表示数据传输时的分块方式）用来表示浏览器希望在最后一个大小为0的块之后还接收到一些额外的字段
	this->User_Agent = "";//浏览器的身份标识字符串 
	this->Upgrade = "";//要求服务器升级到一个高版本协议
	this->Via = "";//告诉服务器，这个请求是由哪些代理发出的
	this->Warning = "";//一个一般性的警告，表示在实体内容体中可能存在错误
	this->Init();
}
void MyHttp::Init()
{
	WSADATA WSAData;
	WSAStartup(0x202, &WSAData);
	this->Socket = socket(AF_INET, SOCK_STREAM, 0);
	hostent *host = gethostbyname(this->ServerAddr.c_str());
	sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(this->ServerPort);
	std::memcpy(&saddr.sin_addr, host->h_addr, 4);
	if (connect(this->Socket, (sockaddr *)&saddr, sizeof(saddr)) == -1)
	{
		std::cout << "connect error" << std::endl;
	}
	else
	{
		std::cout << "connect succeed" << std::endl;
	}
	int timeout = this->WaitTime;                                               //设置发送数据和接收数据的最大延迟时间
	setsockopt(this->Socket, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
	setsockopt(this->Socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
}
void MyHttp::Close()
{
	closesocket(this->Socket);
	WSACleanup();
}

std::string MyHttp::GetHtml()
{
	std::string html;
	char buf[1024];
	memset(&buf, 0, sizeof(buf));
	int n=0;
	int sum = 0;
	std::cout << "正在获取Html" << std::endl;
	while ((n = recv(this->Socket, buf, sizeof(buf) - sizeof(char), 0)) > 0)
	{
		std::cout << n << "字节" << std::endl;
		
		for (int i = 0; i<n; i++)
		{

			html += buf[i];
		}
	}
	int begin;
	if ((begin = html.find("utf-8")) != -1)
		html = UtfToGbk(html.c_str());
	return html;
}
std::string MyHttp::UtfToGbk(const char* utf8)   //由于windowscmd窗口支持的编码格式为gbk而网站默认的编码格式为utf8 所以要转换编码
{
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}
std::string MyHttp::GetCookie(std::string str)
{
	int begin=0;
	if ((begin = str.find("Cookie:")) != -1)
	{
		int end = str.find("path", begin);
		int len = end - begin;
		std::string cookie = str.substr(begin, len);
		return cookie;
	}
	else
		return "";
	
		
}