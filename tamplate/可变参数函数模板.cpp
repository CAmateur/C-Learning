#include <iostream>
#include <sstream>
using namespace std;
template <typename T> std::string debug_rep(const T& t)
{
	std::ostringstream ret;
	ret << t;
	return ret.str();
}
template<typename T>
std::ostream &print(std::ostream &os, const T &t)
{
	//std::cout << "This is nonvariadic function! ";
	return os << t;
}
template <typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args&... rest)
{
	os << t << ", ";
	return print(os, rest...);
}
template <typename... Args>
std::ostream &errorMsg(std::ostream &os, const Args&... rest)
{
	return print(os, debug_rep(rest)...); //使用模板的包扩展
}
int main()
{
	int i(10); std::string s("girls");
	//print(std::cout, i, s, 42);
	errorMsg(std::cout, i, s, 10, "ladies");
	system("pause");
	return 0;

}
