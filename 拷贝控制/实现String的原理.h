#pragma once
#include<string>
#include<algorithm>
#include<memory>

class String
{
public:
	String();
	String(const char *s)//我们可能调用了一个参数不是const的函数，而我们要传进去的实际参数确实const的，
		//但是我们知道这个函数是不会对参数做修改的。于是我们就需要使用const_cast去除const限定，以便函数能够接受这个实际参数。 
		//应该遵从这样的原则：使用const_cast去除const限定的目的绝对不是为了修改它的内容，只是出于无奈。
	{
		auto s1 = const_cast<char*>(s);
		while (*s1)
		{
			++s1;
		}
		alloc_n_copy(s, s1);

	}
	String(const String &);
	String& operator=(const String&);
	~String()
	{
		free();
	}
	void free()
	{
		if (elements)
		{
			std::for_each(elements,
				end, [this](char &rhs) {alloc.destroy(&rhs);});
			alloc.deallocate(elements, end - elements);
		}
	}

private:
	std::allocator<char> alloc;
	char *elements;
	char *end;
	std::pair<char*, char*>alloc_n_copy(
		const char *a, const char *b
	)
	{
		auto s1 = alloc.allocate(b - a);
		//copy 是依次调用重载的运算符=,
			//uninitialized_copy是依次调用拷贝构造函数
		auto s2 = std::uninitialized_copy(a, b, s1);
		return std::make_pair(s1, s2);

	}
	void range_initializer(const char *c,
		const char *d)
	{
		auto p = alloc_n_copy(d, c);
		elements = p.first;
		end = p.second;

	}
};
