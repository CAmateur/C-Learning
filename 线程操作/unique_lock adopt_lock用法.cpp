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
		std::cout << "num:" << num << "this:" << this << "Ĭ�Ϲ��캯��ִ�� �̵߳�ַ��" << std::this_thread::get_id() << std::endl;
	}
	A(int n) :num(n)
	{
		std::cout << "num:" << num << "this:" << this << "���캯��ִ�� �̵߳�ַ��" << std::this_thread::get_id() << std::endl;
	}
	A(const A &a) :num(a.num)
	{
		std::cout << "num:" << num << "this:" << this << "�������캯��ִ�� �̵߳�ַ��" << std::this_thread::get_id() << std::endl;
	}
	A(const A &&a) :num(a.num)
	{

		std::cout << "num:" << num << "this:" << this << "�ƶ����캯��ִ�� �̵߳�ַ��" << std::this_thread::get_id() << std::endl;
	}
	A& operator= (const A &a)
	{
		this->num = a.num;
		std::cout << "num:" << num << "this:" << this << "������ֵ���캯��ִ�� �̵߳�ַ��" << std::this_thread::get_id() << std::endl;
		return *this;
	}
	~A()
	{
		std::cout << "num:" << num << "this:" << this << "��������ִ�� �̵߳�ַ��" << std::this_thread::get_id() << std::endl;
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
			std::cout << "����һ��Ԫ��" << i << std::endl;
			{
				mylock.lock();
				std::unique_lock<std::mutex> c(mylock, std::adopt_lock);
				vec.push_back(i);
			}
			
		}
	}
	/*std::unique_lock<std::mutex> c(mylock,std::adopt_lock);�ڴ˾�֮ǰ����������
	�ͷ�������������������*/
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
				std::cout << "ɾ��һ��Ԫ�أ�" <<command<< std::endl;
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


	std::cout << "�̵߳�ַ: " << std::this_thread::get_id() << "num:" << a.num << std::endl;

}


//void func(std::unique_ptr<int> a)
//{
//	std::cout << *a << std::endl;
//}

int main(int argc, char **argv)
{
	//int i = 1;
	//char chr[] = { "hello world!" };
	//std::thread t1(func,i,std::string(chr));//��յ�����!
	//t1.detach();
	//��Ա�����̵߳ĵ��÷�������std::move()�����ݴ����߳����ʱ����join��������detach()����ȫ
	//ֻҪ�ƶ����캯�����ƹ��캯���������߳��е�����Ͱ�ȫ��

	//A a(12);
	//std::thread t1(func,std::ref(a));
	////std::cout << a.num << std::endl;
	////std::cout << std::this_thread::get_id() << std::endl;
	//t1.join();
	//������ƶ����캯�����ȵ����ƶ����캯����������ø��ƹ��캯��,���������ʱ����д���󣬵����ƶ����캯��������ת�Ƶ��߳�����Ķ������Ǳط����ġ�
	//�����������ʱ����д���Ļ��Ͳ���ȷ��������Ķ���ʲôʱ��ת�Ƶ����ݣ����������߳̽�����ûת�ƣ���ô�������߳����������߳��ͷŵ���Դ���ͻ����
//	std::unique_ptr<int >a(new int(1));
	//std::thread t1(func, a);����
//	std::thread t1(func, std::move(a));//��ȷ
	//std::thread t1(func, std::unique_ptr<int >(new int(1)););//��ȷ
	//t1.join();//����ָ��ֻ����join����
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