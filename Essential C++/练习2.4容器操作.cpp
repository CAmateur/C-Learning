#include<iostream>
#include<string>
#include<vector>
using namespace std;

//inline bool Is_Ok(int Size)
//{
//	if (Size <= 0 || Size >= 100)
//	{
//		cerr << "Ҫ���ɵ���̫��" << endl;
//		return false;
//	}
//	return true;
//}
//
//inline int Calc(int num)
//{
//	return (num*(3 * num - 1)) / 2;
//}
//
//bool setVec(vector<int> &vecTemp, int Size)
//{
//	
//	if(Is_Ok(Size))
//	for (int i = 1; i <= Size; ++i)
//	{
//		vecTemp.push_back(Calc(i));
//	}
//	return true;
//
//}

inline int Calc(int num)
{
	return (num*(3 * num - 1)) / 2;
}
inline bool Is_Ok(int Size)
{
	if (Size <= 0 || Size >= 100)
	{
		cerr << "Ҫ���ɵ���̫��" << endl;
		return false;
	}
	return true;
}
vector<int>* setVec(int Size)
{
	static vector<int> vec;
	if (vec.empty())
	{
		for (int i = 1; i <= Size; ++i)
			vec.push_back(Calc(i));
	}
	if (Is_Ok(Size))
	{
		for (int i = vec.size(); i <= Size; ++i)
			vec.push_back(Calc(i));
		cout << "������С��"<<vec.size() << endl;
	}

	return &vec;
}


bool showVec(vector<int> *vecTemp, string typeStr)
{
	if ((*vecTemp).empty())
	{
		cerr << "��δ�����������ֵ!" << endl;
		return false;
	}
	for (vector<int>::iterator it = (*vecTemp).begin(); it != (*vecTemp).end(); ++it)
	{
		cout << *it << endl;
	}
	return true;

}




int main(int atgc, char**argv) {
	int pos;
	vector<int> *Pvec;
	while (true)
	{

		cout << "��������Ҫ���Ԫ�ص�λ��:";
		cin >> pos;
		Pvec = setVec(pos);
		cout << (*Pvec)[pos];
	}
	system("pause");
	return 0;
}