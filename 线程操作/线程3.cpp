#include<iostream>
#include<thread>
#include<string>
#include<memory>
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
};

//void func(const int i, const std::string &str)
//{
//	std::cout << i << " " << str.c_str() << std::endl;
//}
//
//void func(const int i,  const A &a)
//{
//	std::cout << i << " " << a.num << std::endl;
//}
void func(std::unique_ptr<int> a)
{
	std::cout << *a << std::endl;
}

int main(int argc, char **argv)
{
	//int i = 1;
	//char chr[] = { "hello world!" };
	//std::thread t1(func,i,std::string(chr));//��յ�����!
	//t1.detach();


	//��Ա�����̵߳ĵ��÷�������std::move()�����ݴ����߳����ʱ����join��������detach()����ȫ
	//ֻҪ�ƶ����캯�����ƹ��캯���������߳��е�����Ͱ�ȫ��
	/*int i = 1;
	A a(12);
	std::thread t1(&A::printNum,std::move(a));*/

	//������ƶ����캯�����ȵ����ƶ����캯����������ø��ƹ��캯��,���������ʱ����д���󣬵����ƶ����캯��������ת�Ƶ��߳�����Ķ������Ǳط����ġ�
	//�����������ʱ����д���Ļ��Ͳ���ȷ��������Ķ���ʲôʱ��ת�Ƶ����ݣ����������߳̽�����ûת�ƣ���ô�������߳����������߳��ͷŵ���Դ���ͻ����
	std::unique_ptr<int >a(new int(1));
	//std::thread t1(func, a);����
	std::thread t1(func, std::move(a));//��ȷ
	//std::thread t1(func, std::unique_ptr<int >(new int(1)););//��ȷ
	t1.join();//����ָ��ֻ����join����
	
	system("pause");
	return 0;
}