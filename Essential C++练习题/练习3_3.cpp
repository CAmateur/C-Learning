#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
int main(int argc, char**argv)
{
	map<string, vector<string>> family;
	string family_li[3] = { "�","����","����" };
	string family_zhao[3] = { "�Կ�","����","����" };
	string family_song[3] = { "�ο�","����","����" };
	string family_zuo[3] = { "��","����","����" };
	string family_dou[3] = { "����","����","����" };
	string family_zhang[3] = { "�ſ�","����","����" };
	for (int i = 0; i < 3;++i)
	{
		family["��"].push_back(family_li[i]);
		family["��"].push_back(family_zhao[i]);
		family["��"].push_back(family_song[i]);
		family["��"].push_back(family_zuo[i]);
		family["��"].push_back(family_dou[i]);
		family["��"].push_back(family_zhang[i]);
	}
	for (auto temp : family)
	{
		cout << "����:" << temp.first<<"  ��ͥ��Ա:";
		for (auto _temp : temp.second)
		{
			cout << _temp << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}