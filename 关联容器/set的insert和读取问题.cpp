#include<iostream>
#include<map>
#include<set>
using namespace std;
int main(int argc, char**argv)
{
	//֤��set��insert����Ԫ�غ����ģ�
	set<int> number;
	number.insert(1);
	number.insert(2);
	number.insert(3);
	//set��Ԫ��ֻ����iterator����������ȡ!
	set<int>::iterator it = number.begin();
	cout << *it << endl;

	system("pause");
	return 0;
}