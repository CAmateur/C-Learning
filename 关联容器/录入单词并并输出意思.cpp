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
	 
	//输入要保存的单词!
	while ([&]()->bool {return cin >> word && (word != "endend"); }())
	{
		
		words_indx.insert(word);
		if (cin >> mean)
		{
			words[word] = mean;
			
		}
		else
		{
			cout << "单词意思录入错误！" << endl;
		}
	}


	for (auto w : words_indx)
		cout << "录入的单词有:"<<w <<"意思:"<<words[w]<< endl;


	system("pause");
	return 0;
}