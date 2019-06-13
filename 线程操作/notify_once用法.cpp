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
			std::cout << "����һ��Ԫ��" << i << std::endl;
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
				std::cout << "ɾ��һ��Ԫ�أ�" <<command<< std::endl;
			}
			else
			{

			}
		}*/
		//���lambda���ص�ʱfalse������Ϊ�գ�wait������������
		//�����������У�����ֱ������notify_one()Ϊֹ
		//�������Ϊtrue��������Ϊ��
		//wait��ֱ�ӷ���
		//waitû�еڶ���������lambda����false��Ч��һ��
		//�������̵߳���notify_once()����wait����ԭ����˯��/������״̬���Ѻ�
		//wait�Ϳ�ʼ�������»�ȡ����������Ҳ��������,�����ȡ�������̾Ϳ����⣬���Ż�ȡ
		//wait��ȡ������������ͼ���ִ��
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

			std::cout << "ɾ��һ��Ԫ�أ�" << command << std::endl;
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