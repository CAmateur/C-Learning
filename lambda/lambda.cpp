#include<iostream>
#include<thread>

class A
{
public:
	int num;
	A()
	{
		num = 0;
		std::cout << num << "构造函数执行" << std::endl;
	}
	A(int n) :num(n)
	{
		std::cout << num << "构造函数执行" << std::endl;
	}


	A(const A &a) :num(a.num)
	{
		std::cout << num << "拷贝构造函数执行" << std::endl;
	}
	A(const A &&a) :num(a.num)
	{

		std::cout << num << "移动构造函数执行" << std::endl;
	}
	A& operator= (const A &a)
	{
		this->num = a.num;
		std::cout << num << "拷贝赋值构造函数执行" << std::endl;
		return *this;
	}
	~A()
	{

	}
};



int main(int argc, char **argv)
{
	int num = 520;
	auto func=[num]()mutable->double {/*mutable是可以修改副本num ->num为lambada的反回类型*/
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
	auto func1 = [&num] {/*这是修改的不是副本的num*/
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