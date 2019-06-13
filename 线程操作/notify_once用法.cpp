#include<iostream>
#include<thread>
#include<string>
#include<memory>
#include<list>
#include<mutex>

class A
{
private:
	int num;
	std::list<int> vec;
	std::mutex mylock;
	std::condition_variable mycond;
public:


	A()
	{
		num = 0;
		std::cout << "num:" << num << "this:" << this << "默认构造函数执行 线程地址：" << std::this_thread::get_id() << std::endl;
	}
	A(int n) :num(n)
	{
		std::cout << "num:" << num << "this:" << this << "构造函数执行 线程地址：" << std::this_thread::get_id() << std::endl;
	}
	A(const A &a) :num(a.num)
	{
		std::cout << "num:" << num << "this:" << this << "拷贝构造函数执行 线程地址：" << std::this_thread::get_id() << std::endl;
	}
	A(const A &&a) :num(a.num)
	{

		std::cout << "num:" << num << "this:" << this << "移动构造函数执行 线程地址：" << std::this_thread::get_id() << std::endl;
	}
	A& operator= (const A &a)
	{
		this->num = a.num;
		std::cout << "num:" << num << "this:" << this << "拷贝赋值构造函数执行 线程地址：" << std::this_thread::get_id() << std::endl;
		return *this;
	}
	~A()
	{
		std::cout << "num:" << num << "this:" << this << "析构函数执行 线程地址：" << std::this_thread::get_id() << std::endl;
	}
	void printNum()
	{

		std::cout << num << std::endl;
	}


	void functionsend()
	{
		for (int i = 0; i < 100000; ++i)
		{
			
			if (vec.size() == 20)
			{
				std::chrono::milliseconds mysleep(50);
				std::this_thread::sleep_for(mysleep);
			}

			std::unique_lock<std::mutex> c(mylock);
			std::cout << "插入一个元素" << i << std::endl;
			vec.push_back(i);
			

			mycond.notify_one();


		}


	}

	bool ddd(int &command)
	{
		std::unique_lock<std::mutex> c(mylock);
		if (!vec.empty())
		{
			command = vec.front();
			vec.pop_front();

			return true;
		}

		return false;
	}
	void functionrecv()
	{
		/*int command = 0;*/
		/*for (int i = 0; i < 100000; ++i)
		{
			bool result = ddd(command);
			if (result==true)
			{
				std::cout << "删除一个元素：" <<command<< std::endl;
			}
			else
			{

			}
		}*/
		//如果lambda返回的时false则容器为空，wait将解锁互斥量
		//并阻塞到本行，堵塞直到调用notify_one()为止
		//如果反回为true则容器不为空
		//wait就直接反回
		//wait没有第二个参数和lambda反回false的效果一样
		//当其他线程调用notify_once()将本wait（）原来是睡着/阻塞的状态唤醒后
		//wait就开始尝试重新获取互斥量锁，也就是上锁,如果获取不到流程就卡在这，等着获取
		//wait获取到互斥量锁后就继续执行
		while (true)
		{
			std::unique_lock<std::mutex> c(mylock);
			mycond.wait(c, [this] {
				if (!vec.empty())
					return true;
				return false;
			});
			int command = vec.front();

			vec.pop_front();

			std::cout << "删除一个元素：" << command << std::endl;
		}
	}
};




int main(int argc, char **argv)
{
	A a(12);
	std::thread t1(&A::functionsend, &a);
	std::thread t2(&A::functionrecv, &a);
	t1.join();
	t2.join();




	system("pause");
	return 0;
}