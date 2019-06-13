#include<iostream>
#include<thread>
#include<mutex>
std::mutex ml;
std::once_flag myFlag;
class A
{
private:

	A() {};
	static A* instance;//静态成员变量
public:
	static void CreatInstance()
	{
		instance = new A();
		static shifang cl;
	}
	static A* GetInstance()
	{
		std::call_once(myFlag, CreatInstance);//保证只调用一次
		return instance;
	}
	class shifang
	{
	public:
		shifang() = default;
		~shifang()
		{
			if (A::instance != NULL)
			{
				std::unique_lock<std::mutex> mylock(ml);
				if (A::instance != NULL)
				{
					delete A::instance;
					A::instance = NULL;
				}
			}
		}
	};

	void func()
	{
		std::cout << "测试" << std::endl;
	}

};
A *A::instance = NULL;

void func1()
{
	A *ptr = A::GetInstance();
	ptr->func();
}

int main(int argc, char**argv)
{

	std::thread t1(func1);
	std::thread t2(func1);

	t1.join();
	t2.join();


	system("pause");
	return 0;
}