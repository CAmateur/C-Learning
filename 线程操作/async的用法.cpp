#include<iostream>
#include<thread>
#include<future>

int mythread()
{
	std::cout << "my thread()开始运行啦！" << std::endl;
	std::chrono::milliseconds mysleep(5000);
	std::this_thread::sleep_for(mysleep);
	std::cout << "my thread()结束运行啦！" << std::endl;
	return 5;
}

int main(int argc, char**argv)
{
	std::future<int> result = std::async(mythread);
	std::cout << "my main thread:" << std::this_thread::get_id() << std::endl;
	std::cout << "mythread()return result: " << result.get() << std::endl;
	system("pause");
	return 0;

	//result.get()卡在这里等待mythread（）执行完毕，拿到结果
	//result.wait（）等待线程反回，本身并不返回结果，像join（）//感觉不太安全尽量用get（）
}