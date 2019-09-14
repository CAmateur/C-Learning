#include"MyHttp.h"
#include "MyHttpException.h"

void MyHttpBase::SetWaitTime(const int waittime) { this->WaitTime = waittime; }
void MyHttpBase::SetAccept(const std::string accept) { this->Accept = accept; }
void MyHttpBase::SetAccept_Charset(const std::string accept_Charset) { this->Accept_Charset = accept_Charset; }//可接受的字符集 
void MyHttpBase::SetAccept_Encoding(const std::string accept_Encoding) { this->Accept_Encoding = accept_Encoding; }//可接受的响应内容的编码方式
void MyHttpBase::SetAccept_Language(const std::string accept_Language) { this->Accept_Language = accept_Language; }//可接受的响应内容语言列表
void MyHttpBase::SetAccept_Datetime(const std::string accept_Datetime) { this->Accept_Datetime = accept_Datetime; }//可接受的按照时间来表示的响应内容版本 
void MyHttpBase::SetAuthorization(const std::string authorization) { this->Authorization = authorization; }//用于表示HTTP协议中需要认证资源的认证信息 
void MyHttpBase::SetCache_Control(const std::string cache_Control) { this->Cache_Control = cache_Control; }//用来指定当前的请求/回复中的，是否使用缓存机制。
void MyHttpBase::SetConnection(const std::string connection) { this->Connection = connection; }//客户端（浏览器）想要优先使用的连接类型 
void MyHttpBase::SetCookie(const std::string cookie) { this->Cookie = cookie; }//
void MyHttpBase::SetContent_MD5(const std::string content_MD5) { this->Content_MD5 = content_MD5; }//请求体的内容的二进制 MD5 散列值（数字签名），以 Base64 编码的结果 
void MyHttpBase::SetContent_Type(const std::string content_Type) { this->Content_Type = content_Type; }//请求体的MIME类型 （用于POST和PUT请求中）
void MyHttpBase::SetDate(const std::string date) { this->Date = date; }//发送该消息的日期和时间（以RFC 7231中定义的"HTTP日期"格式来发送） 
void MyHttpBase::SetExpect(const std::string expect) { this->Expect = expect; }//表示客户端要求服务器做出特定的行为 
void MyHttpBase::SetFrom(const std::string from) { this->From = from; }//发起此请求的用户的邮件地址 
void MyHttpBase::SetHost(const std::string host) { this->Host = host; }//表示服务器的域名以及服务器所监听的端口号。如果所请求的端口是对应的服务的标准端口（80），则端口号可以省略。 
void MyHttpBase::SetIf_Match(const std::string if_Match) { this->If_Match = if_Match; }//仅当客户端提供的实体与服务器上对应的实体相匹配时，才进行对应的操作。主要用于像 PUT 这样的方法中，仅当从用户上次更新某个资源后，该资源未被修改的情况下，才更新该资源。
void MyHttpBase::SetIf_Modified_Since(const std::string if_Modified_Since) { this->If_Modified_Since = if_Modified_Since; }//允许在对应的资源未被修改的情况下返回304未修改 
void MyHttpBase::SetIf_None_Match(const std::string if_None_Match) { this->If_None_Match = if_None_Match; }//允许在对应的内容未被修改的情况下返回304未修改（ 304 Not Modified ），参考 超文本传输协议 的实体标记 
void MyHttpBase::SetIf_Range(const std::string if_Range) { this->If_Range = if_Range; }//如果该实体未被修改过，则向返回所缺少的那一个或多个部分。否则，返回整个新的实体
void MyHttpBase::SetIf_Unmodified_Since(const std::string if_Unmodified_Since) { this->If_Unmodified_Since = if_Unmodified_Since; }//仅当该实体自某个特定时间以来未被修改的情况下，才发送回应。
void MyHttpBase::SetMax_Forwards(const std::string max_Forwards) { this->Max_Forwards = max_Forwards; }//限制该消息可被代理及网关转发的次数。
void MyHttpBase::SetOrigin(const std::string origin) { this->Origin = origin; }//发起一个针对跨域资源共享的请求
void MyHttpBase::SetPragma(const std::string pragma) { this->Pragma = pragma; }//与具体的实现相关，这些字段可能在请求/回应链中的任何时候产生
void MyHttpBase::SetProxy_Authorization(const std::string proxy_Authorization) { this->Proxy_Authorization = proxy_Authorization; }//用于向代理进行认证的认证信息
void MyHttpBase::SetRange(const std::string range) { this->Range = range; }//表示请求某个实体的一部分，字节偏移以0开始
void MyHttpBase::SetReferer(const std::string referer) { this->Referer = referer; }//表示浏览器所访问的前一个页面，可以认为是之前访问页面的链接将浏览器带到了当前页面。Referer其实是Referrer这个单词，但RFC制作标准时给拼错了，后来也就将错就错使用Referer了
void MyHttpBase::SetTE(const std::string tE) { this->TE = tE; }//浏览器预期接受的传输时的编码方式：可使用回应协议头Transfer-Encoding中的值（还可以使用"trailers"表示数据传输时的分块方式）用来表示浏览器希望在最后一个大小为0的块之后还接收到一些额外的字段
void MyHttpBase::SetUser_Agent(const std::string user_Agent) { this->User_Agent = user_Agent; }//浏览器的身份标识字符串 
void MyHttpBase::SetUpgrade(const std::string upgrade) { this->Upgrade = upgrade; }//要求服务器升级到一个高版本协议
void MyHttpBase::SetVia(const std::string via) { this->Via = via; }//告诉服务器，这个请求是由哪些代理发出的
void MyHttpBase::SetWarning(const std::string warning) { this->Warning = warning; }//一个一般性的警告，表示在实体内容体中可能存在错误
void MyHttpBase::SetServerAddr(const std::string serverAddr) { this->ServerAddr = serverAddr; }
MyHttpBase::MyHttpBase(const std::string Adder, const int Port) :
	ServerAddr(Adder),
	ServerPort(Port),
	Accept(),//可接受的响应内容类型
	WaitTime(3000),//数值越小发送和接受数据更快，应适当调节
	Accept_Charset(),//可接受的字符集 
	Accept_Encoding(),//可接受的响应内容的编码方式
	Accept_Language(),//可接受的响应内容语言列表
	Accept_Datetime(),//可接受的按照时间来表示的响应内容版本 
	Authorization(),//用于表示HTTP协议中需要认证资源的认证信息 
	Cache_Control(),//用来指定当前的请求/回复中的，是否使用缓存机制。
	Connection(),//客户端（浏览器）想要优先使用的连接类型 
	Cookie(),//
	Content_MD5(),//请求体的内容的二进制 MD5 散列值（数字签名），以 Base64 编码的结果 
	Content_Type(),//请求体的MIME类型 （用于POST和PUT请求中）
	Date(),//发送该消息的日期和时间（以RFC 7231中定义的"HTTP日期"格式来发送） 
	Expect(),//表示客户端要求服务器做出特定的行为 
	From(),//发起此请求的用户的邮件地址 
	Host(),//表示服务器的域名以及服务器所监听的端口号。如果所请求的端口是对应的服务的标准端口（80），则端口号可以省略。 
	If_Match(),//仅当客户端提供的实体与服务器上对应的实体相匹配时，才进行对应的操作。主要用于像 PUT 这样的方法中，仅当从用户上次更新某个资源后，该资源未被修改的情况下，才更新该资源。
	If_Modified_Since(),//允许在对应的资源未被修改的情况下返回304未修改 
	If_None_Match(),//允许在对应的内容未被修改的情况下返回304未修改（ 304 Not Modified ），参考 超文本传输协议 的实体标记 
	If_Range(),//如果该实体未被修改过，则向返回所缺少的那一个或多个部分。否则，返回整个新的实体
	If_Unmodified_Since(),//仅当该实体自某个特定时间以来未被修改的情况下，才发送回应。
	Max_Forwards(),//限制该消息可被代理及网关转发的次数。
	Origin(),//发起一个针对跨域资源共享的请求
	Pragma(),//与具体的实现相关，这些字段可能在请求/回应链中的任何时候产生
	Proxy_Authorization(),//用于向代理进行认证的认证信息
	Range(),//表示请求某个实体的一部分，字节偏移以0开始
	Referer(),//表示浏览器所访问的前一个页面，可以认为是之前访问页面的链接将浏览器带到了当前页面。Referer其实是Referrer这个单词，但RFC制作标准时给拼错了，后来也就将错就错使用Referer了
	TE(),//浏览器预期接受的传输时的编码方式：可使用回应协议头Transfer-Encoding中的值（还可以使用"trailers"表示数据传输时的分块方式）用来表示浏览器希望在最后一个大小为0的块之后还接收到一些额外的字段
	User_Agent(),//浏览器的身份标识字符串 
	Upgrade(),//要求服务器升级到一个高版本协议
	Via(),//告诉服务器，这个请求是由哪些代理发出的
	Warning(),//一个一般性的警告，表示在实体内容体中可能存在错误
	html(),
	ret(),
	begin()
{
	this->Init();
}
MyHttpBase::~MyHttpBase()
{

}
bool MyHttpBase::Init()
{


	WSADATA WSAData;
	WSAStartup(0x202, &WSAData);
	this->Socket = socket(AF_INET, SOCK_STREAM, 0);//参数protocol用来指定socket所使用的传输协议编号。这一参数通常不具体设置，一般设置为0即可。
	hostent *host = gethostbyname(this->ServerAddr.c_str());
	if (host == nullptr)
	{
		throw MyHttpBaseException("host填写错误!");
	}
	sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(this->ServerPort);
	std::memcpy(&saddr.sin_addr, host->h_addr, 4);


	if (connect(this->Socket, (sockaddr *)&saddr, sizeof(saddr)) == -1)
	{
		throw MyHttpBaseException("连接失败!");//抛出异常
		return false;


	}
	else
	{
		//设置发送数据和接收数据的最大延迟时间
		setsockopt(this->Socket, SOL_SOCKET, SO_SNDTIMEO, (char *)&this->WaitTime, sizeof(this->WaitTime));
		setsockopt(this->Socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&this->WaitTime, sizeof(this->WaitTime));
		return true;
	}


}

std::string MyHttpBase::UtfToGbk(const char* utf8)   //由于windowscmd窗口支持的编码格式为gbk而网站默认的编码格式为utf8 所以要转换编码
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
std::string MyHttpBase::SetDatePacked(const std::string pageAddr, const std::string accessMethod, const std::string data)
{
	std::stringstream request;
	if (accessMethod == "POST")
	{

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
			request << "Cookie:" << this->Cookie << "\r\n";
		request << "Content-Length:" << data.length() << "\r\n";
		if (this->Content_MD5 != "")
			request << "Content-MD5:" << this->Content_MD5 << "\r\n";
		if (this->Content_Type != "")
			request << "Content-Type:" << this->Content_Type << "\r\n";
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
	}
	else if (accessMethod == "GET")
	{

		request << "GET " + pageAddr + " HTTP/1.1\r\n";
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
			request << "Cookie:" << this->Cookie << "\r\n";
		if (this->Content_MD5 != "")
			request << "Content-MD5:" << this->Content_MD5 << "\r\n";
		if (this->Content_Type != "")
			request << "Content-Type:" << this->Content_Type << "\r\n";
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

	}
	else throw MyHttpBaseException("没有此访问方法!");//抛出异常

	return request.str();
}
std::string MyHttpBase::GetCookie(const std::string &str, const std::string TailSign)
{

	if ((begin = str.find("Cookie:")) != -1)
	{
		int end = str.find(TailSign, begin);
		int len = end - begin;
		std::string cookie = str.substr(begin, len);
		return cookie;
	}
	else
		return "";


}


std::string Http::GetHtml()
{

	html.clear();


	//int sum = 0;
	while ((ret = recv(this->Socket, buf, sizeof(buf) - sizeof(char), 0)) > 0)
	{
		//sum += ret;
		for (int i = 0; i < ret; ++i)
		{
			html += buf[i];
		}
	}
	//std::cout << sum << "字节" << std::endl;

	if ((begin = html.find("utf-8")) != -1)
		return UtfToGbk(html.c_str());
	return html;
}
Http::Http(const std::string Adder, const int AdderPort) :MyHttpBase(Adder, AdderPort)
{

}
Http::~Http()
{
	this->Close();
}

void Http::Close()
{
	closesocket(this->Socket);
	WSACleanup();
}
std::string Http::PageAccess(const std::string PageAddr, const std::string AccessMethod, const std::string Data)
{
	DataContent.clear();
	DataContent = SetDatePacked(PageAddr, AccessMethod, Data);
	if (send(this->Socket, DataContent.c_str(), DataContent.size(), 0) > 0)
	{
		//std::cout << "发送 成功！" << std::endl;
		return this->GetHtml();
	}
	else
	{
		throw MyHttpBaseException("Http发送失败!");//抛出异常
		return "";
	}

}



Https::Https(const std::string Adder, const int AdderPort) : MyHttpBase(Adder, AdderPort)
{
	//加载SSL错误信息 
	SSL_load_error_strings();
	//添加SSL的加密/HASH算法 
	SSLeay_add_ssl_algorithms();
	//客户端，服务端选择SSLv23_server_method() 
	meth = SSLv23_client_method();
	//建立新的SSL上下文 
	ctx = SSL_CTX_new(meth);
	ssl = SSL_new(ctx);
	if (ssl == NULL)
	{
		throw MyHttpBaseException("SLL NEW ERROR!");//抛出异常
	}
	//将SSL与TCP SOCKET 连接 
	SSL_set_fd(ssl, this->Socket);
	//SSL连接 
	ret = SSL_connect(ssl);
	if (ret == -1)
	{
		throw MyHttpBaseException("SSL ACCEPT ERROR!");//抛出异常
	}
}
Https::~Https()
{
	this->Close();
}
void Https::Close()
{

	//关闭SSL套接字 
	SSL_shutdown(ssl);
	//释放SSL套接字 
	SSL_free(ssl);
	//释放SSL会话环境 
	SSL_CTX_free(ctx);

	closesocket(this->Socket);
	WSACleanup();
}
std::string Https::PageAccess(const std::string PageAddr, const std::string AccessMethod, const std::string Data)
{
	DataContent.clear();
	DataContent = SetDatePacked(PageAddr, AccessMethod, Data);
	ret = SSL_write(ssl, DataContent.c_str(), strlen(DataContent.c_str()));//发送数据
	if (ret == -1)
	{
		//std::cout << "发送 失败！" << std::endl;
		throw MyHttpBaseException("Https发送失败!");//抛出异常
		return "";
	}
	else
	{
		//std::cout << "发送 成功！" << std::endl;
		return this->GetHtml();
	}

}
std::string Https::GetHtml()
{
	html.clear();
	while ((ret = SSL_read(ssl, buf, sizeof(buf) - sizeof(char))) > 0)
	{
		for (int i = 0; i < ret; ++i)
		{
			html += buf[i];
		}
	}

	if ((begin = html.find("utf-8")) != -1)
		return UtfToGbk(html.c_str());
	return html;
}