#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
int main(int argc, char**argv)
{
	map<string, vector<string>> family;
	string family_li[3] = { "李康","李周","李岩" };
	string family_zhao[3] = { "赵康","赵周","赵岩" };
	string family_song[3] = { "宋康","宋周","宋岩" };
	string family_zuo[3] = { "左康","左周","左岩" };
	string family_dou[3] = { "豆康","豆周","豆岩" };
	string family_zhang[3] = { "张康","张周","张岩" };
	for (int i = 0; i < 3;++i)
	{
		family["李"].push_back(family_li[i]);
		family["赵"].push_back(family_zhao[i]);
		family["宋"].push_back(family_song[i]);
		family["左"].push_back(family_zuo[i]);
		family["豆"].push_back(family_dou[i]);
		family["张"].push_back(family_zhang[i]);
	}
	for (auto temp : family)
	{
		cout << "姓氏:" << temp.first<<"  家庭成员:";
		for (auto _temp : temp.second)
		{
			cout << _temp << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}