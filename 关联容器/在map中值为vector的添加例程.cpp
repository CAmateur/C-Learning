#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
int main(int argc, char**argv)
{
	map<string, vector<string>> family;
	string surname;
	string name;
	//�������ݹ���
	while (cin >> surname && (surname != "end"))
	{	
		cout << "�������ͥ����:";
		while (cin >> name&&(name != "end"))
		{
			cout << "�������ͥ��Ա������:";
			family[surname].push_back(name);
		}
		cout << endl;
	}

	//�������ݹ���ͬ��
	//����д����˼һ�����·���Ϊ�߱Ƹ��Ҹ���ࣻlambda[&]���ݺ������е�����Զ���ʽ��������lambda�����
	//��cin

	while ([&]()->bool {cout << "�������ͥ����:" ; return cin >> surname&&(surname != "end"); }())
	{
		while ([&]()->bool {cout << "�������ͥ��Ա������:"; return cin >> name&&(name != "end"); }())
		{
			family[surname].push_back(name);
		}
	}
	//������

	 
	for (map<string, vector<string>>::iterator it = family.begin(); it != family.end(); it++)
	{
		cout << "��ͥ:" << it->first << "��Ա:";
		for (vector<string>::iterator it1 = it->second.begin(); it1 != it->second.end(); it1++)
			cout << *it1 << " ";
		cout << endl;
	}


	system("pause");
	return 0;
}