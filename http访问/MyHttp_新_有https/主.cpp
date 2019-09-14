#include<iostream>
#include<string>
#include<sstream>
#include"MyHttp.h"

using namespace std;
int main(int argc, char**argv)
{
	try {
		Https https("www.baiducom");
		https.SetAccept("*text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8*");
		https.SetAccept_Language("zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2	");
		https.SetCache_Control("max-age=0");
		https.SetConnection("Keep-Alive");
		https.SetHost("ss1.bdstatic.com");
		https.SetCookie("BAIDUID=AAF4EBD54D9C2014857D65D8F02ADAFD:FG=1; BIDUPSID=C0A2DB06AACBE7BF6EB98B5C59518790; PSTM=1560333658; BD_UPN=13314752; sug=3; sugstore=1; ORIGIN=0; bdime=0; BDORZ=B490B5EBF6F3CD402E515D22BCDA1598; H_PS_PSSID=1455_21078_29523_29518_29099_29568_28831_29221_29460_29589; delPer=0; BD_CK_SAM=1; PSINO=1; session_id=1565612459423; session_name=www.baidu.com; ___wk_scode_token=nk6H6LaaLs9QNkfb2E0lR6jZgDuvbABiQJvZvmfWUGU%3D; BD_HOME=0; H_PS_645EC=3486KsJziUnwM5otQunxHu%2FEJIq%2FUICsrangrgOchUOvYfRaVasRdjCJguw; COOKIE_SESSION=12891_0_8_4_18_25_0_3_4_5_300_2_0_0_1_0_1565603727_0_1565616617%7C9%232656009_8_1563845702%7C4; pgv_pvi=7879172096; pgv_si=s8241840128");
		https.SetReferer("https://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&tn=monline_7_dg&wd=VS%E6%80%8E%E4%B9%88%E7%94%A8openssl&oq=%2526lt%253B%252B%252B%25E5%25AE%259E%25E7%258E%25B0https%25E8%25AE%25BF%25E9%2597%25AE&rsv_pq=b782f37a000059e4&rsv_t=d7a1OfJyJ%2F3dVYzyRj5nAbJ%2Fkm4Kkv8SEu%2B9RXP%2FC7q7Rhlczfv%2BtHx8lDjS0juMCV10&rqlang=cn&rsv_enter=1&rsv_dl=tb&inputT=7527&rsv_sug3=68&rsv_sug1=27&rsv_sug7=100&rsv_sug2=0&rsv_sug4=9544");
		https.SetUser_Agent("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/64.0.3282.140 Safari/537.36 Edge/17.17134");
		string html = https.PageAccess("https://ss1.bdstatic.com/5eN1bjq8AAUYm2zgoY3K/r/www/cache/static/protocol/https/home/img/qrcode/zbios_09b6296.png", "GET");
		cout << html << endl;
	}
	catch (exception &e)
	{
		std::cerr<<e.what();
	}

	
	system("pause");
	return 0;
}


