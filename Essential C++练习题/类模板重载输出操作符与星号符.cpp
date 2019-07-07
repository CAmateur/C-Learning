#include<iostream>
using namespace std;





template<typename T>
class general
{
public:
	//第一种方法输入流符号同样的方法
	friend ostream & operator <<(ostream &os, general<T> &tem)
	{
		os << tem.content;
		return os;
	}
	friend T & operator *(general<T> &tem)
	{
		return tem.content;
	}
	
	//第二种方法输入流符号同样的方法
	//template<typename U>
	//friend ostream & operator <<(ostream &os, general<U> &tem);


	//template<typename U>
	//friend U& operator *(general<U> &tem);


	general() = default;
	general(T tn) :content(tn) {}

	
	
	
private:
	T content;
};
//第二种方法输入流符号同样的方法
//template<typename U>
//ostream & operator <<(ostream &os, general<U> &tem)
//{
//	
//		os << tem.content;
//		return os;
//}


//template<typename U>
//U& operator *(general<U> &tem)
//{
//	return tem.content;
//}



int main(int argc, char**argv)
{
	general<int> hh(1);
	cout << *hh;

	system("pause");
	return 0;
}