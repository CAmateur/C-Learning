#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<WinSock2.h>
#include<vector>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include"MyHttpException.h"

#pragma comment(lib,"libeay32.lib")
#pragma comment(lib,"ssleay32.lib")
#pragma comment(lib,"ws2_32.lib")


class MyHttpBase
{
public:
	MyHttpBase(const std::string Adder, const int Port);
	virtual ~MyHttpBase();
	virtual void Close() = 0;
	virtual std::string PageAccess(const std::string PageAddr, const std::string AccessMethod, const std::string Data = "") = 0;
	virtual std::string GetHtml() = 0;
	std::string GetCookie(const std::string &str, const std::string TailSign);//将从网页截取Cookie
	std::string UtfToGbk(const char* utf8);
	std::string SetDatePacked(const std::string pageAddr,const std::string accessMethodm, const std::string data);
	bool Init();
	void SetWaitTime(const int waittime);
	void SetAccept(const std::string accept);//可接受的响应内容类型
	void SetAccept_Charset(const std::string accept_Charset);//可接受的字符集 
	void SetAccept_Encoding(const std::string accept_Encoding);//可接受的响应内容的编码方式
	void SetAccept_Language(const std::string accept_Language);//可接受的响应内容语言列表
	void SetAccept_Datetime(const std::string accept_Datetime);//可接受的按照时间来表示的响应内容版本 
	void SetAuthorization(const std::string authorization);//用于表示HTTP协议中需要认证资源的认证信息 
	void SetCache_Control(const std::string cache_Control);//用来指定当前的请求/回复中的，是否使用缓存机制。
	void SetConnection(const std::string connection);//客户端（浏览器）想要优先使用的连接类型 
	void SetCookie(const std::string cookie);
	void SetContent_MD5(const std::string content_MD5);//请求体的内容的二进制 MD5 散列值（数字签名），以 Base64 编码的结果 
	void SetContent_Type(const std::string content_Type);//请求体的MIME类型 （用于POST和PUT请求中）
	void SetDate(const std::string date);//发送该消息的日期和时间（以RFC 7231中定义的"HTTP日期"格式来发送） 
	void SetExpect(const std::string expect);//表示客户端要求服务器做出特定的行为 
	void SetFrom(const std::string from);//发起此请求的用户的邮件地址 
	void SetHost(const std::string host);//表示服务器的域名以及服务器所监听的端口号。如果所请求的端口是对应的服务的标准端口（80），则端口号可以省略。 
	void SetIf_Match(const std::string if_Match);//仅当客户端提供的实体与服务器上对应的实体相匹配时，才进行对应的操作。主要用于像 PUT 这样的方法中，仅当从用户上次更新某个资源后，该资源未被修改的情况下，才更新该资源。
	void SetIf_Modified_Since(const std::string if_Modified_Since);//允许在对应的资源未被修改的情况下返回304未修改 
	void SetIf_None_Match(const std::string if_None_Match);//允许在对应的内容未被修改的情况下返回304未修改（ 304 Not Modified ），参考 超文本传输协议 的实体标记 
	void SetIf_Range(const std::string if_Range);//如果该实体未被修改过，则向返回所缺少的那一个或多个部分。否则，返回整个新的实体
	void SetIf_Unmodified_Since(const std::string if_Unmodified_Since);//仅当该实体自某个特定时间以来未被修改的情况下，才发送回应。
	void SetMax_Forwards(const std::string max_Forwards);//限制该消息可被代理及网关转发的次数。
	void SetOrigin(const std::string origin);//发起一个针对跨域资源共享的请求
	void SetPragma(const std::string pragma);//与具体的实现相关，这些字段可能在请求/回应链中的任何时候产生
	void SetProxy_Authorization(const std::string proxy_Authorization);//用于向代理进行认证的认证信息
	void SetRange(const std::string range);//表示请求某个实体的一部分，字节偏移以0开始
	void SetReferer(const std::string referer);//表示浏览器所访问的前一个页面，可以认为是之前访问页面的链接将浏览器带到了当前页面。Referer其实是Referrer这个单词，但RFC制作标准时给拼错了，后来也就将错就错使用Referer了
	void SetTE(const std::string tE);//浏览器预期接受的传输时的编码方式：可使用回应协议头Transfer-Encoding中的值（还可以使用"trailers"表示数据传输时的分块方式）用来表示浏览器希望在最后一个大小为0的块之后还接收到一些额外的字段
	void SetUser_Agent(const std::string user_Agent);//浏览器的身份标识字符串 
	void SetUpgrade(const std::string upgrade);//要求服务器升级到一个高版本协议
	void SetVia(const std::string via);//告诉服务器，这个请求是由哪些代理发出的
	void SetWarning(const std::string warning);//一个一般性的警告，表示在实体内容体中可能存在错误
	void SetServerAddr(const std::string serverAddr);

protected:
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
	std::string html;
	std::string DataContent;
	char buf[1024];
	int ServerPort;//服务器端口
	int WaitTime;
	int ret;
	int begin;
	SOCKET Socket;//自己创建的套接字可以理解为自己的端口
};


class Http : public MyHttpBase
{
public:
	Http(const std::string Adder, const int AdderPort = 80);
	virtual ~Http();
	virtual void Close() override;
	virtual std::string PageAccess(const std::string PageAddr, const std::string AccessMethod, const std::string Data = "")override;
	virtual std::string GetHtml()override;
};


class Https : public MyHttpBase
{
public:
	Https(const std::string Adder, const int AdderPort = 443);
	virtual ~Https();
	virtual void Close() override;
	virtual std::string PageAccess(const std::string PageAddr, const std::string AccessMethod, const std::string Data = "")override;
	virtual std::string GetHtml()override;
protected:
	const SSL_METHOD *meth;
	SSL_CTX* ctx;
	SSL*ssl;
};