#include<iostream>
#include<thread>
#include<string>
class A
{
public:
	int num;
	A()
	{
		num = 0;
		std::cout << "num:" << num << "this:" << this << "默认构造函数执行 线程地址："<<std::this_thread::get_id() << std::endl;
	}
	A(int n) :num(n)
	{
		std::cout << "num:" << num << "this:" << this << "构造函数执行 线程地址："<<std::this_thread::get_id()<< std::endl;
	}
	A(const A &a) :num(a.num)
	{
		std::cout << "num:" << num << "this:" << this << "拷贝构造函数执行 线程地址：" << std::this_thread::get_id() << std::endl;
	}
	A(const A &&a) :num(a.num)
	{

		std::cout << "num:" << num << "this:" << this << "移动构造函数执行 线程地址："<<std::this_thread::get_id()<< std::endl;
	}
	A& operator= (const A &a)
	{
		this->num = a.num;
		std::cout << "num:" << num << "this:" << this << "拷贝赋值构造函数执行 线程地址：" << std::this_thread::get_id() << std::endl;
		return *this;
	}
	~A()
	{
		std::cout <<"num:"<< num <<"this:"<<this<< "析构函数执行 线程地址：" << std::this_thread::get_id() << std::endl;
	}
	void printNum()
	{
		std::cout <<num << std::endl;
	}
};

//void func(const int i, const std::string &str)
//{
//	std::cout << i << " " << str.c_str() << std::endl;
//}

void func(const int i,  const A &a)
{
	std::cout << i << " " << a.num << std::endl;
}

int main(int argc,  char **argv)
{
	//int i = 1;
	//char chr[] = { "hello world!" };
	//std::thread t1(func,i,std::string(chr));//最保险的做法!
	//t1.detach();
	int i = 1; 
	int t = 12;
	std::thread t1(func, i, A(t));
	//如果有移动构造函数了先调用移动构造函数，否则调用复制构造函数,如果采用临时变量写法后，调用移动构造函数将数据转移到线程里面的对象，这是必发生的。
	//但是如果不临时变量写法的话就不能确定数据里的对象什么时候转移的数据，可能在主线程结束后还没转移，那么创建的线程在利用主线程释放的资源，就会出错
	t1.detach();
	system("pause");
	return 0;
}