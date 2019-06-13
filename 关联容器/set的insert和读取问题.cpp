#include<iostream>
#include<map>
#include<set>
using namespace std;
int main(int argc, char**argv)
{
	//证明set的insert是在元素后插入的！
	set<int> number;
	number.insert(1);
	number.insert(2);
	number.insert(3);
	//set的元素只能用iterator迭代器来读取!
	set<int>::iterator it = number.begin();
	cout << *it << endl;

	system("pause");
	return 0;
}