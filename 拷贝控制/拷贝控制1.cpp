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



int main(int argc, char **argv)
{
	A aa;
	A bb(1);
	aa = bb;
	A cc = std::move(bb);
	A dd = bb;
	system("pause");
	return 0;
}