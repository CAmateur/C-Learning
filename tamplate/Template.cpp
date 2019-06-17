#include<iostream>
#include<vector>
#include<list>
using namespace std;
//template<typename T>
//int compare(const t &v1, const t &v2)
//{
//	if (v1 < v2) return 1;
//	if (v2 < v1) return -1;
//
//}
//template<unsigned n, unsigned m>
//int compare(const char(&p1)[n], const char(&p2)[m])
//{
//	return strcmp(p1, p2);
//}

//class Test
//{
//public:
//	int i;
//	Test() = default;
//	~Test() = default;
//};

//template<typename U, typename T> bool find_my__(const U& it1, const U&it2, const T&val)
//{
//	auto it3 = it1;
//	for (it3; it3 != it2; ++it3)
//	{
//		if (*it3 == val)
//		{
//			return true;
//		}
//	}
//	return false;
//}

//template<typename T, unsigned N> void print_my(const T (&v1) [N] )
//{
//	for (auto elem : v1)
//	{
//		cout << elem << endl;
//	}
//	cout << N << endl;
//	return;
//}

//template<typename T, unsigned N> T*begin_my(const T(&v1)[N])
//{
//	auto v2 = const_cast<T*>(v1);
//	return v2;
//}
//template<typename T, unsigned N> T* end_my(const T(&v1)[N])
//{
//	auto v2 = const_cast<T*>(v1);//const_cast<里面只能是指针或着引用>
//	return v2 + N - 1;
//}

//template<typename T> class MyClass
//{
//public:
//	typedef typename std::vector<T>::size_type size_type;
//	MyClass();
//	MyClass(initializer_list<t> il);
//	size_type size() const { return data->size(); }
//	bool empty()const { return data->empty(); }
//	void push_back(const T &t) { data->push_back(t); }
//	void push_back(T &&t) { data->push_back(std::move(t)); }
//	void pop_back();
//	T& back();
//	T& operator[](size_type i);
//private:
//	shared_ptr<vector<T>> data;
//	void check(size_type i, const string &msg)const;
//
//
//};

int main(int argc, char**argv)
{
	//vector<int> vec1{1,2,3};
	//vector<int> vec2{4,5,6};
	//cout << compare(1.1, 2.1) << endl;
	//Test t1;
	//Test t2;
	//compare(t1, t2);

	//vector<int> vec = { 1,2,3,4,5,6,7 };
	//if (find_my__(vec.begin(),vec.end(),8))
	//	cout << "ture" << endl;

	//int a[3] = { 1,2,3 };
	//print_my(a);

	//int number[3] = { 1,2,3 };
	//
	//cout << *(begin_my(number)) << endl;
	//cout << *(end_my(number)) << endl;



	system("pause");
	return 0;
}

