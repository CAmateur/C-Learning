#include<iostream>
#include<thread>

class A
{
public:
	int num;
	A()
	{
		num = 0;
		std::cout << num<<"���캯��ִ��" << std::endl;
	}
	A(int n):num(n)
	{
		std::cout << num << "���캯��ִ��" << std::endl;
	}

	
	A(const A &a):num(a.num)
	{
		std::cout << num << "�������캯��ִ��" << std::endl;
	}
	A(const A &&a):num(a.num)
	{

		std::cout << num << "�ƶ����캯��ִ��" << std::endl;
	}
	A& operator= (const A &a)
	{
		this->num = a.num;
		std::cout << num << "������ֵ���캯��ִ��" << std::endl;
		return *this;
	}
	~A()
	{

	}
};

A func(int a)
{
	A ee(a);
	
	return ee;
}



int main(int argc, char **argv)
{
A c=func(1);
A d = (func(1));
A e = std::move(func(1));
A f;
f = func(1);
	system("pause");
	return 0;
}