#include<iostream>
#include<thread>

class A
{
public:
	int num;
	A()
	{
		num = 0;
		std::cout << num << "���캯��ִ��" << std::endl;
	}
	A(int n) :num(n)
	{
		std::cout << num << "���캯��ִ��" << std::endl;
	}


	A(const A &a) :num(a.num)
	{
		std::cout << num << "�������캯��ִ��" << std::endl;
	}
	A(const A &&a) :num(a.num)
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
	int num = 520;
	auto func=[num]()mutable->double {/*mutable�ǿ����޸ĸ���num ->numΪlambada�ķ�������*/
		while (1)
		{
			if (num == 0)
			{
				std::cout << "0" << std::endl;
				break;
			}
			--num;
			
		}
		return 0;
	};
	auto func1 = [&num] {/*�����޸ĵĲ��Ǹ�����num*/
		while (1)
		{
			if (num == 0)
			{
				std::cout << "0" << std::endl;
				break;
			}
			--num;

		}
	
	};

	func();
	std::cout << num << std::endl;
	func1();
	std::cout << num << std::endl;
	system("pause");
	return 0;

}