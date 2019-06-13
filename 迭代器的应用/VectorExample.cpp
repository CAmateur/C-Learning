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
	for (auto &strcontsub : strcont) //遍历strcont容器中的每个单词！通过引用修改
	{
		for (auto &strcontsubed : strcontsub) //遍历strcontsub中的每个字母！通过引用修改
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