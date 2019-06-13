#include<iostream>
#include<string>
#include<vector>
#include<algorithm>//泛型算法头文件
using namespace std;

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());//按字典序排序words，以便找查重复单词，使相同的word紧挨排列
	auto end_unique = unique(words.begin(), words.end());//让不重复的word排在前面，重复的排在后面反回第一个开始重复的迭代器
	words.erase(end_unique, words.end());//删除重复的word

}
void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	//<即由小到大排序，相同大小按原来顺序 >则由大到小排序
	stable_sort(words.begin(), words.end(), [](string &a, string &b) {return a.size() < b.size(); });
	//反回第一个大于sz的word的迭代器
	auto wc = find_if(words.begin(), words.end(), [sz](string &a) {return a.size() >= sz; });
	//经过find_if后wc到words.end（）全都是大于sz的elem，下面即是计算大于sz的数量
	auto count = words.end() - wc;
	//经过for_each输出所有大于sz的elem
	for_each(wc, words.end(), [](const string &s) {cout << s <<" "; });
	cout << endl;
}


int main(int argc, char**argv)
{



	return 0;
}