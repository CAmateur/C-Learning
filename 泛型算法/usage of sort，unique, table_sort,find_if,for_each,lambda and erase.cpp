#include<iostream>
#include<string>
#include<vector>
#include<algorithm>//�����㷨ͷ�ļ�
using namespace std;

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());//���ֵ�������words���Ա��Ҳ��ظ����ʣ�ʹ��ͬ��word��������
	auto end_unique = unique(words.begin(), words.end());//�ò��ظ���word����ǰ�棬�ظ������ں��淴�ص�һ����ʼ�ظ��ĵ�����
	words.erase(end_unique, words.end());//ɾ���ظ���word

}
void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	//<����С����������ͬ��С��ԭ��˳�� >���ɴ�С����
	stable_sort(words.begin(), words.end(), [](string &a, string &b) {return a.size() < b.size(); });
	//���ص�һ������sz��word�ĵ�����
	auto wc = find_if(words.begin(), words.end(), [sz](string &a) {return a.size() >= sz; });
	//����find_if��wc��words.end����ȫ���Ǵ���sz��elem�����漴�Ǽ������sz������
	auto count = words.end() - wc;
	//����for_each������д���sz��elem
	for_each(wc, words.end(), [](const string &s) {cout << s <<" "; });
	cout << endl;
}


int main(int argc, char**argv)
{



	return 0;
}