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
	//不可直接用_1需要添加using namespace std::placeholders;
	//print有三个参数_1对应a、_2对应b、3对应c
	auto world = bind(print, _1, _2, 3);
	//world函数第一个参数对应a，第二个参数对应b
	world(2, 1);
	//print有三个参数_2对应a、_1对应b、3对应c
	auto world1 = bind(print, _2, _1, 3);
	//world函数第一个参数对应b，第二个参数对应a
	world1(2, 1);
	//print有三个参数_3对应a、_1对应b、3对应c
	auto world2 = bind(print, _3,_1,3);
	//world 由bind后没有第二个参数故出错
	world2(2, 1);

	system("pause");
	return 0;
}