#include<iostream>
#include<map>
#include<set>
#include<string>
#include<vector>

using namespace std;
int main(int argc, char**argv)
{
	map<string, string> words;
	string word, mean;
	set<string> words_indx;
	 
	//����Ҫ����ĵ���!
	while ([&]()->bool {return cin >> word && (word != "endend"); }())
	{
		
		words_indx.insert(word);
		if (cin >> mean)
		{
			words[word] = mean;
			
		}
		else
		{
			cout << "������˼¼�����" << endl;
		}
	}


	for (auto w : words_indx)
		cout << "¼��ĵ�����:"<<w <<"��˼:"<<words[w]<< endl;


	system("pause");
	return 0;
}