#include<iostream>
#include<string>	
#include<vector>
#include<cctype>
using namespace std;
int main() 
{
	string str;
	vector<string> strcont;
	while (cin>>str)
	{
		strcont.push_back(str);
		if (strcont.size() >= 3)
			break;
	}
	for (auto &strcontsub : strcont) //����strcont�����е�ÿ�����ʣ�ͨ�������޸�
	{
		for (auto &strcontsubed : strcontsub) //����strcontsub�е�ÿ����ĸ��ͨ�������޸�
		{
			if (islower(strcontsubed))
				strcontsubed = toupper(strcontsubed);
		}
	}
	for (auto stred : strcont)
	{
		cout << stred << endl;
	}
	system("pause");
	return 0;
}