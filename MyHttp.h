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
	//<param name = "adder">�����ǲ��� b ��˵��< / param>
	std::string PageAccess(std::string accessMethod,std::string pageAddr,std::string data );
	std::string GetCookie(std::string str);//������ҳ��ȡCookie
	void Init();
	void Close();
	std::string UtfToGbk(const char* utf8);
	void SetWaitTime(int waittime);
	void SetAccept(std::string accept = "");//�ɽ��ܵ���Ӧ��������
	void SetAccept_Charset(std::string accept_Charset);//�ɽ��ܵ��ַ��� 
	void SetAccept_Encoding(std::string accept_Encoding);//�ɽ��ܵ���Ӧ���ݵı��뷽ʽ
	void SetAccept_Language(std::string accept_Language);//�ɽ��ܵ���Ӧ���������б�
	void SetAccept_Datetime(std::string accept_Datetime);//�ɽ��ܵİ���ʱ������ʾ����Ӧ���ݰ汾 
	void SetAuthorization(std::string authorization);//���ڱ�ʾHTTPЭ������Ҫ��֤��Դ����֤��Ϣ 
	void SetCache_Control(std::string cache_Control);//����ָ����ǰ������/�ظ��еģ��Ƿ�ʹ�û�����ơ�
	void SetConnection(std::string connection);//�ͻ��ˣ����������Ҫ����ʹ�õ��������� 
	void SetCookie(std::string cookie);
	void SetContent_MD5(std::string content_MD5);//����������ݵĶ����� MD5 ɢ��ֵ������ǩ�������� Base64 ����Ľ�� 
	void SetContent_Type(std::string content_Type);//�������MIME���� ������POST��PUT�����У�
	void SetDate(std::string date);//���͸���Ϣ�����ں�ʱ�䣨��RFC 7231�ж����"HTTP����"��ʽ�����ͣ� 
	void SetExpect(std::string expect);//��ʾ�ͻ���Ҫ������������ض�����Ϊ 
	void SetFrom(std::string from);//�����������û����ʼ���ַ 
	void SetHost(std::string host);//��ʾ�������������Լ��������������Ķ˿ںš����������Ķ˿��Ƕ�Ӧ�ķ���ı�׼�˿ڣ�80������˿ںſ���ʡ�ԡ� 
	void SetIf_Match(std::string if_Match);//�����ͻ����ṩ��ʵ����������϶�Ӧ��ʵ����ƥ��ʱ���Ž��ж�Ӧ�Ĳ�������Ҫ������ PUT �����ķ����У��������û��ϴθ���ĳ����Դ�󣬸���Դδ���޸ĵ�����£��Ÿ��¸���Դ��
	void SetIf_Modified_Since(std::string if_Modified_Since);//�����ڶ�Ӧ����Դδ���޸ĵ�����·���304δ�޸� 
	void SetIf_None_Match(std::string if_None_Match);//�����ڶ�Ӧ������δ���޸ĵ�����·���304δ�޸ģ� 304 Not Modified �����ο� ���ı�����Э�� ��ʵ���� 
	void SetIf_Range(std::string if_Range);//�����ʵ��δ���޸Ĺ������򷵻���ȱ�ٵ���һ���������֡����򣬷��������µ�ʵ��
	void SetIf_Unmodified_Since(std::string if_Unmodified_Since);//������ʵ����ĳ���ض�ʱ������δ���޸ĵ�����£��ŷ��ͻ�Ӧ��
	void SetMax_Forwards(std::string max_Forwards);//���Ƹ���Ϣ�ɱ���������ת���Ĵ�����
	void SetOrigin(std::string origin);//����һ����Կ�����Դ���������
	void SetPragma(std::string pragma);//������ʵ����أ���Щ�ֶο���������/��Ӧ���е��κ�ʱ�����
	void SetProxy_Authorization(std::string proxy_Authorization);//��������������֤����֤��Ϣ
	void SetRange(std::string range);//��ʾ����ĳ��ʵ���һ���֣��ֽ�ƫ����0��ʼ
	void SetReferer(std::string referer);//��ʾ����������ʵ�ǰһ��ҳ�棬������Ϊ��֮ǰ����ҳ������ӽ�����������˵�ǰҳ�档Referer��ʵ��Referrer������ʣ���RFC������׼ʱ��ƴ���ˣ�����Ҳ�ͽ���ʹ�ʹ��Referer��
	void SetTE(std::string tE);//�����Ԥ�ڽ��ܵĴ���ʱ�ı��뷽ʽ����ʹ�û�ӦЭ��ͷTransfer-Encoding�е�ֵ��������ʹ��"trailers"��ʾ���ݴ���ʱ�ķֿ鷽ʽ��������ʾ�����ϣ�������һ����СΪ0�Ŀ�֮�󻹽��յ�һЩ������ֶ�
	void SetUser_Agent(std::string user_Agent);//���������ݱ�ʶ�ַ��� 
	void SetUpgrade(std::string upgrade);//Ҫ�������������һ���߰汾Э��
	void SetVia(std::string via);//���߷��������������������Щ��������
	void SetWarning(std::string warning);//һ��һ���Եľ��棬��ʾ��ʵ���������п��ܴ��ڴ���
	void SetServerAddr(std::string serverAddr);



private:
	std::string Accept;//�ɽ��ܵ���Ӧ��������
	std::string Accept_Charset;//�ɽ��ܵ��ַ��� 
	std::string Accept_Encoding;//�ɽ��ܵ���Ӧ���ݵı��뷽ʽ
	std::string Accept_Language;//�ɽ��ܵ���Ӧ���������б�
	std::string Accept_Datetime;//�ɽ��ܵİ���ʱ������ʾ����Ӧ���ݰ汾 
	std::string Authorization;//���ڱ�ʾHTTPЭ������Ҫ��֤��Դ����֤��Ϣ 
	std::string Cache_Control;//����ָ����ǰ������/�ظ��еģ��Ƿ�ʹ�û�����ơ�
	std::string Connection;//�ͻ��ˣ����������Ҫ����ʹ�õ��������� 
	std::string Cookie;//
	std::string Content_MD5;//����������ݵĶ����� MD5 ɢ��ֵ������ǩ�������� Base64 ����Ľ�� 
	std::string Content_Type;//�������MIME���� ������POST��PUT�����У�
	std::string Date;//���͸���Ϣ�����ں�ʱ�䣨��RFC 7231�ж����"HTTP����"��ʽ�����ͣ� 
	std::string Expect;//��ʾ�ͻ���Ҫ������������ض�����Ϊ 
	std::string From;//�����������û����ʼ���ַ 
	std::string Host;//��ʾ�������������Լ��������������Ķ˿ںš����������Ķ˿��Ƕ�Ӧ�ķ���ı�׼�˿ڣ�80������˿ںſ���ʡ�ԡ� 
	std::string If_Match;//�����ͻ����ṩ��ʵ����������϶�Ӧ��ʵ����ƥ��ʱ���Ž��ж�Ӧ�Ĳ�������Ҫ������ PUT �����ķ����У��������û��ϴθ���ĳ����Դ�󣬸���Դδ���޸ĵ�����£��Ÿ��¸���Դ��
	std::string If_Modified_Since;//�����ڶ�Ӧ����Դδ���޸ĵ�����·���304δ�޸� 
	std::string If_None_Match;//�����ڶ�Ӧ������δ���޸ĵ�����·���304δ�޸ģ� 304 Not Modified �����ο� ���ı�����Э�� ��ʵ���� 
	std::string If_Range;//�����ʵ��δ���޸Ĺ������򷵻���ȱ�ٵ���һ���������֡����򣬷��������µ�ʵ��
	std::string If_Unmodified_Since;//������ʵ����ĳ���ض�ʱ������δ���޸ĵ�����£��ŷ��ͻ�Ӧ��
	std::string Max_Forwards;//���Ƹ���Ϣ�ɱ���������ת���Ĵ�����
	std::string Origin;//����һ����Կ�����Դ���������
	std::string Pragma;//������ʵ����أ���Щ�ֶο���������/��Ӧ���е��κ�ʱ�����
	std::string Proxy_Authorization;//��������������֤����֤��Ϣ
	std::string Range;//��ʾ����ĳ��ʵ���һ���֣��ֽ�ƫ����0��ʼ
	std::string Referer;//��ʾ����������ʵ�ǰһ��ҳ�棬������Ϊ��֮ǰ����ҳ������ӽ�����������˵�ǰҳ�档Referer��ʵ��Referrer������ʣ���RFC������׼ʱ��ƴ���ˣ�����Ҳ�ͽ���ʹ�ʹ��Referer��
	std::string TE;//�����Ԥ�ڽ��ܵĴ���ʱ�ı��뷽ʽ����ʹ�û�ӦЭ��ͷTransfer-Encoding�е�ֵ��������ʹ��"trailers"��ʾ���ݴ���ʱ�ķֿ鷽ʽ��������ʾ�����ϣ�������һ����СΪ0�Ŀ�֮�󻹽��յ�һЩ������ֶ�
	std::string User_Agent;//���������ݱ�ʶ�ַ��� 
	std::string Upgrade;//Ҫ�������������һ���߰汾Э��
	std::string Via;//���߷��������������������Щ��������
	std::string Warning;//һ��һ���Եľ��棬��ʾ��ʵ���������п��ܴ��ڴ���
	std::string ServerAddr;//��������ַ
	int ServerPort;//�������˿�
	int WaitTime;
	SOCKET Socket;//�Լ��������׽��ֿ������Ϊ�Լ��Ķ˿�
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
void MyHttp::SetAccept_Charset(std::string accept_Charset) { this->Accept_Charset = accept_Charset; }//�ɽ��ܵ��ַ��� 
void MyHttp::SetAccept_Encoding(std::string accept_Encoding) { this->Accept_Encoding = accept_Encoding; }//�ɽ��ܵ���Ӧ���ݵı��뷽ʽ
void MyHttp::SetAccept_Language(std::string accept_Language) { this->Accept_Language = accept_Language; }//�ɽ��ܵ���Ӧ���������б�
void MyHttp::SetAccept_Datetime(std::string accept_Datetime) { this->Accept_Datetime = accept_Datetime; }//�ɽ��ܵİ���ʱ������ʾ����Ӧ���ݰ汾 
void MyHttp::SetAuthorization(std::string authorization) { this->Authorization = authorization; }//���ڱ�ʾHTTPЭ������Ҫ��֤��Դ����֤��Ϣ 
void MyHttp::SetCache_Control(std::string cache_Control) { this->Cache_Control = cache_Control; }//����ָ����ǰ������/�ظ��еģ��Ƿ�ʹ�û�����ơ�
void MyHttp::SetConnection(std::string connection) { this->Connection = connection; }//�ͻ��ˣ����������Ҫ����ʹ�õ��������� 
void MyHttp::SetCookie(std::string cookie) { this->Cookie = cookie; }//
void MyHttp::SetContent_MD5(std::string content_MD5) { this->Content_MD5 = content_MD5; }//����������ݵĶ����� MD5 ɢ��ֵ������ǩ�������� Base64 ����Ľ�� 
void MyHttp::SetContent_Type(std::string content_Type) { this->Content_Type = content_Type; }//�������MIME���� ������POST��PUT�����У�
void MyHttp::SetDate(std::string date) { this->Date = date; }//���͸���Ϣ�����ں�ʱ�䣨��RFC 7231�ж����"HTTP����"��ʽ�����ͣ� 
void MyHttp::SetExpect(std::string expect) { this->Expect = expect; }//��ʾ�ͻ���Ҫ������������ض�����Ϊ 
void MyHttp::SetFrom(std::string from) { this->From = from; }//�����������û����ʼ���ַ 
void MyHttp::SetHost(std::string host) { this->Host = host; }//��ʾ�������������Լ��������������Ķ˿ںš����������Ķ˿��Ƕ�Ӧ�ķ���ı�׼�˿ڣ�80������˿ںſ���ʡ�ԡ� 
void MyHttp::SetIf_Match(std::string if_Match) { this->If_Match = if_Match; }//�����ͻ����ṩ��ʵ����������϶�Ӧ��ʵ����ƥ��ʱ���Ž��ж�Ӧ�Ĳ�������Ҫ������ PUT �����ķ����У��������û��ϴθ���ĳ����Դ�󣬸���Դδ���޸ĵ�����£��Ÿ��¸���Դ��
void MyHttp::SetIf_Modified_Since(std::string if_Modified_Since) {this->If_Modified_Since = if_Modified_Since;}//�����ڶ�Ӧ����Դδ���޸ĵ�����·���304δ�޸� 
void MyHttp::SetIf_None_Match(std::string if_None_Match) { this->If_None_Match = if_None_Match; }//�����ڶ�Ӧ������δ���޸ĵ�����·���304δ�޸ģ� 304 Not Modified �����ο� ���ı�����Э�� ��ʵ���� 
void MyHttp::SetIf_Range(std::string if_Range) { this->If_Range = if_Range; }//�����ʵ��δ���޸Ĺ������򷵻���ȱ�ٵ���һ���������֡����򣬷��������µ�ʵ��
void MyHttp::SetIf_Unmodified_Since(std::string if_Unmodified_Since) { this->If_Unmodified_Since = if_Unmodified_Since; }//������ʵ����ĳ���ض�ʱ������δ���޸ĵ�����£��ŷ��ͻ�Ӧ��
void MyHttp::SetMax_Forwards(std::string max_Forwards) { this->Max_Forwards = max_Forwards; }//���Ƹ���Ϣ�ɱ���������ת���Ĵ�����
void MyHttp::SetOrigin(std::string origin) { this->Origin = origin; }//����һ����Կ�����Դ���������
void MyHttp::SetPragma(std::string pragma) { this->Pragma = pragma; }//������ʵ����أ���Щ�ֶο���������/��Ӧ���е��κ�ʱ�����
void MyHttp::SetProxy_Authorization(std::string proxy_Authorization) { this->Proxy_Authorization = proxy_Authorization; }//��������������֤����֤��Ϣ
void MyHttp::SetRange(std::string range) { this->Range = range; }//��ʾ����ĳ��ʵ���һ���֣��ֽ�ƫ����0��ʼ
void MyHttp::SetReferer(std::string referer) { this->Referer = referer; }//��ʾ����������ʵ�ǰһ��ҳ�棬������Ϊ��֮ǰ����ҳ������ӽ�����������˵�ǰҳ�档Referer��ʵ��Referrer������ʣ���RFC������׼ʱ��ƴ���ˣ�����Ҳ�ͽ���ʹ�ʹ��Referer��
void MyHttp::SetTE(std::string tE) { this->TE = tE; }//�����Ԥ�ڽ��ܵĴ���ʱ�ı��뷽ʽ����ʹ�û�ӦЭ��ͷTransfer-Encoding�е�ֵ��������ʹ��"trailers"��ʾ���ݴ���ʱ�ķֿ鷽ʽ��������ʾ�����ϣ�������һ����СΪ0�Ŀ�֮�󻹽��յ�һЩ������ֶ�
void MyHttp::SetUser_Agent(std::string user_Agent) { this->User_Agent = user_Agent; }//���������ݱ�ʶ�ַ��� 
void MyHttp::SetUpgrade(std::string upgrade) { this->Upgrade = upgrade; }//Ҫ�������������һ���߰汾Э��
void MyHttp::SetVia(std::string via) { this->Via = via; }//���߷��������������������Щ��������
void MyHttp::SetWarning(std::string warning) { this->Warning = warning; }//һ��һ���Եľ��棬��ʾ��ʵ���������п��ܴ��ڴ���
void MyHttp::SetServerAddr(std::string serverAddr) { this->ServerAddr = serverAddr; }
MyHttp::~MyHttp()
{
	this->Close();
}
MyHttp::MyHttp(std::string serverAdder, int port):ServerAddr(serverAdder),ServerPort(port)
{
	this->WaitTime = 3000;
	this->Accept = "";//�ɽ��ܵ���Ӧ��������
	this->Accept_Charset = "";//�ɽ��ܵ��ַ��� 
	this->Accept_Encoding = "";//�ɽ��ܵ���Ӧ���ݵı��뷽ʽ
	this->Accept_Language = "";//�ɽ��ܵ���Ӧ���������б�
	this->Accept_Datetime = "";//�ɽ��ܵİ���ʱ������ʾ����Ӧ���ݰ汾 
	this->Authorization = "";//���ڱ�ʾHTTPЭ������Ҫ��֤��Դ����֤��Ϣ 
	this->Cache_Control = "";//����ָ����ǰ������/�ظ��еģ��Ƿ�ʹ�û�����ơ�
	this->Connection = "";//�ͻ��ˣ����������Ҫ����ʹ�õ��������� 
	this->Cookie = "";//
	this->Content_MD5 = "";//����������ݵĶ����� MD5 ɢ��ֵ������ǩ�������� Base64 ����Ľ�� 
	this->Content_Type = "";//�������MIME���� ������POST��PUT�����У�
	this->Date = "";//���͸���Ϣ�����ں�ʱ�䣨��RFC 7231�ж����"HTTP����"��ʽ�����ͣ� 
	this->Expect = "";//��ʾ�ͻ���Ҫ������������ض�����Ϊ 
	this->From = "";//�����������û����ʼ���ַ 
	this->Host = "";//��ʾ�������������Լ��������������Ķ˿ںš����������Ķ˿��Ƕ�Ӧ�ķ���ı�׼�˿ڣ�80������˿ںſ���ʡ�ԡ� 
	this->If_Match = "";//�����ͻ����ṩ��ʵ����������϶�Ӧ��ʵ����ƥ��ʱ���Ž��ж�Ӧ�Ĳ�������Ҫ������ PUT �����ķ����У��������û��ϴθ���ĳ����Դ�󣬸���Դδ���޸ĵ�����£��Ÿ��¸���Դ��
	this->If_Modified_Since = "";//�����ڶ�Ӧ����Դδ���޸ĵ�����·���304δ�޸� 
	this->If_None_Match = "";//�����ڶ�Ӧ������δ���޸ĵ�����·���304δ�޸ģ� 304 Not Modified �����ο� ���ı�����Э�� ��ʵ���� 
	this->If_Range = "";//�����ʵ��δ���޸Ĺ������򷵻���ȱ�ٵ���һ���������֡����򣬷��������µ�ʵ��
	this->If_Unmodified_Since = "";//������ʵ����ĳ���ض�ʱ������δ���޸ĵ�����£��ŷ��ͻ�Ӧ��
	this->Max_Forwards = "";//���Ƹ���Ϣ�ɱ���������ת���Ĵ�����
	this->Origin = "";//����һ����Կ�����Դ���������
	this->Pragma = "";//������ʵ����أ���Щ�ֶο���������/��Ӧ���е��κ�ʱ�����
	this->Proxy_Authorization = "";//��������������֤����֤��Ϣ
	this->Range = "";//��ʾ����ĳ��ʵ���һ���֣��ֽ�ƫ����0��ʼ
	this->Referer = "";//��ʾ����������ʵ�ǰһ��ҳ�棬������Ϊ��֮ǰ����ҳ������ӽ�����������˵�ǰҳ�档Referer��ʵ��Referrer������ʣ���RFC������׼ʱ��ƴ���ˣ�����Ҳ�ͽ���ʹ�ʹ��Referer��
	this->TE = "";//�����Ԥ�ڽ��ܵĴ���ʱ�ı��뷽ʽ����ʹ�û�ӦЭ��ͷTransfer-Encoding�е�ֵ��������ʹ��"trailers"��ʾ���ݴ���ʱ�ķֿ鷽ʽ��������ʾ�����ϣ�������һ����СΪ0�Ŀ�֮�󻹽��յ�һЩ������ֶ�
	this->User_Agent = "";//���������ݱ�ʶ�ַ��� 
	this->Upgrade = "";//Ҫ�������������һ���߰汾Э��
	this->Via = "";//���߷��������������������Щ��������
	this->Warning = "";//һ��һ���Եľ��棬��ʾ��ʵ���������п��ܴ��ڴ���
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
	int timeout = this->WaitTime;                                               //���÷������ݺͽ������ݵ�����ӳ�ʱ��
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
	std::cout << "���ڻ�ȡHtml" << std::endl;
	while ((n = recv(this->Socket, buf, sizeof(buf) - sizeof(char), 0)) > 0)
	{
		std::cout << n << "�ֽ�" << std::endl;
		
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
std::string MyHttp::UtfToGbk(const char* utf8)   //����windowscmd����֧�ֵı����ʽΪgbk����վĬ�ϵı����ʽΪutf8 ����Ҫת������
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