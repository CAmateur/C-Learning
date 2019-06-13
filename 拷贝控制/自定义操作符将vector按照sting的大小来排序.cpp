#include<iostream>
#include<string>
#include<vector>	
#include<algorithm>
class Hasptr
{
public:
	friend void swap(Hasptr &, Hasptr&);
	friend bool operator<(const Hasptr& s1, const Hasptr&s2);
	friend void show(std::vector<Hasptr> &vec);
	Hasptr();//构造函数
	//重载构造函数
	Hasptr(const std::string &s = std::string()) :ps(new std::string(s)), i(0), use(new size_t(1)) {}
	//拷贝构造函数
	Hasptr(const Hasptr &p) :ps(p.ps), i(p.i), use(p.use) { ++*use; }
	
	//拷贝赋值运算符
	Hasptr & operator=(const Hasptr &d)
	{
		++*d.use;
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
		ps = d.ps;
		use = d.use;
		i = d.i;
		return *this;
	}
	~Hasptr() 
	{ 
		if (*use == 0)
		{
			delete ps;
			delete use;
		}
	}
private:
	std::string *ps;
	size_t *use;
	int i;

};
inline void swap(Hasptr &a, Hasptr &b)
{
	using std::swap;
	swap(a.ps, b.ps);
	std::swap(a.i, b.i);
}

bool operator<(const Hasptr &s1, const Hasptr &s2)
{
	//这里按照的是std::string里的<进行比对的
	return *s1.ps < *s2.ps;
}
void show(std::vector<Hasptr>& vec)
{
	std::vector<Hasptr>::iterator it1 = vec.begin();
	for (it1; it1 != vec.end(); ++it1)
	{
		std::cout << *(it1->ps) << std::endl;
	}
}

int main(int argc, char**argv)
{
	std::vector<Hasptr>vec;
	Hasptr a("l"), b("llll"), c("lll");
	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);
	std::vector<Hasptr>::iterator it1 = vec.begin();
	sort(vec.begin(), vec.end());
	show(vec);
	system("pause");
	return 0;
}