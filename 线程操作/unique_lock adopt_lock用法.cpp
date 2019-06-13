#include<iostream>
#include<thread>
#include<string>
#include<memory>
#include<list>
#include<mutex>

class A
{
public:

	int num;
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
	std::list<int> vec;
	std::mutex mylock;

	void functionsend()
	{
		for (int i = 0; i < 10000; ++i)
		{
			std::cout << "插入一个元素" << i << std::endl;
			{
				mylock.lock();
				std::unique_lock<std::mutex> c(mylock, std::adopt_lock);
				vec.push_back(i);
			}
			
		}
	}
	/*std::unique_lock<std::mutex> c(mylock,std::adopt_lock);在此句之前必须先上锁
	释放锁则在析构函数里面*/
	bool ddd(int &command)
	{
		mylock.lock();
		std::unique_lock<std::mutex> c(mylock,std::adopt_lock);
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
		int command = 0;
		for (int i = 0; i < 100000; ++i)
		{
			bool result = ddd(command);
			if (result==true)
			{
				std::cout << "删除一个元素：" <<command<< std::endl;
			}
			else 
			{
				
			}
		}
	}
};

//void func(const int i, const std::string &str)
//{
//	std::cout << i << " " << str.c_str() << std::endl;
//}
//
void func(A &a)
{


	std::cout << "线程地址: " << std::this_thread::get_id() << "num:" << a.num << std::endl;

}


//void func(std::unique_ptr<int> a)
//{
//	std::cout << *a << std::endl;
//}

int main(int argc, char **argv)
{
	//int i = 1;
	//char chr[] = { "hello world!" };
	//std::thread t1(func,i,std::string(chr));//最保险的做法!
	//t1.detach();
	//成员函数线程的调用方法加了std::move()后将数据传到线程里，此时无论join（）还是detach()都安全
	//只要移动构造函数或复制构造函数都在主线程中调用则就安全！

	//A a(12);
	//std::thread t1(func,std::ref(a));
	////std::cout << a.num << std::endl;
	////std::cout << std::this_thread::get_id() << std::endl;
	//t1.join();
	//如果有移动构造函数了先调用移动构造函数，否则调用复制构造函数,如果采用临时变量写法后，调用移动构造函数将数据转移到线程里面的对象，这是必发生的。
	//但是如果不临时变量写法的话就不能确定数据里的对象什么时候转移的数据，可能在主线程结束后还没转移，那么创建的线程在利用主线程释放的资源，就会出错
//	std::unique_ptr<int >a(new int(1));
	//std::thread t1(func, a);出错
//	std::thread t1(func, std::move(a));//正确
	//std::thread t1(func, std::unique_ptr<int >(new int(1)););//正确
	//t1.join();//智能指针只能用join（）
	//std::vector<std::thread> vec;
	//
	//for (int i = 0; i < 10; ++i)
	//{
	//	vec.push_back(std::thread(func, A(i)));
	//}
	//for (std::vector<std::thread>::iterator it=vec.begin();it!=vec.end();++it)
	//{
	//	it->detach();
	//}
	/*A a(12);
	std::thread t1(&A::printNum, &a);
	std::cout << std::this_thread::get_id() << std::endl;
	t1.join();*/
	std::cout << std::this_thread::get_id() << std::endl;
	A a(12);

	std::thread t1(&A::functionsend, &a);
	std::thread t2(&A::functionrecv, &a);
	t1.join();
	t2.join();




	system("pause");
	return 0;
}