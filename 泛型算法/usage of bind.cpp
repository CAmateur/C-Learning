#include<iostream>
#include<vector>
#include<functional>
using namespace std;
using namespace std::placeholders;
void print(int a, int b,int c)
{
	
	cout << "a=" << a << " b=" << b << " c=" << c << endl;
	
}


int main(int argc, char**argv)
{
	//����ֱ����_1��Ҫ���using namespace std::placeholders;
	//print����������_1��Ӧa��_2��Ӧb��3��Ӧc
	auto world = bind(print, _1, _2, 3);
	//world������һ��������Ӧa���ڶ���������Ӧb
	world(2, 1);
	//print����������_2��Ӧa��_1��Ӧb��3��Ӧc
	auto world1 = bind(print, _2, _1, 3);
	//world������һ��������Ӧb���ڶ���������Ӧa
	world1(2, 1);
	//print����������_3��Ӧa��_1��Ӧb��3��Ӧc
	auto world2 = bind(print, _3,_1,3);
	//world ��bind��û�еڶ��������ʳ���
	world2(2, 1);

	system("pause");
	return 0;
}