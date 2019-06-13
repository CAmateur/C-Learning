#pragma once
#include<string>
#include<algorithm>
#include<memory>

class String
{
public:
	String();
	String(const char *s)//���ǿ��ܵ�����һ����������const�ĺ�����������Ҫ����ȥ��ʵ�ʲ���ȷʵconst�ģ�
		//��������֪����������ǲ���Բ������޸ĵġ��������Ǿ���Ҫʹ��const_castȥ��const�޶����Ա㺯���ܹ��������ʵ�ʲ����� 
		//Ӧ�����������ԭ��ʹ��const_castȥ��const�޶���Ŀ�ľ��Բ���Ϊ���޸��������ݣ�ֻ�ǳ������Ρ�
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
		//copy �����ε������ص������=,
			//uninitialized_copy�����ε��ÿ������캯��
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
