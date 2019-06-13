#include<iostream>
#include<thread>
#include<future>

int mythread()
{
	std::cout << "my thread()��ʼ��������" << std::endl;
	std::chrono::milliseconds mysleep(5000);
	std::this_thread::sleep_for(mysleep);
	std::cout << "my thread()������������" << std::endl;
	return 5;
}

int main(int argc, char**argv)
{
	std::future<int> result = std::async(mythread);
	std::cout << "my main thread:" << std::this_thread::get_id() << std::endl;
	std::cout << "mythread()return result: " << result.get() << std::endl;
	system("pause");
	return 0;

	//result.get()��������ȴ�mythread����ִ����ϣ��õ����
	//result.wait�����ȴ��̷߳��أ����������ؽ������join����//�о���̫��ȫ������get����
}