#include<iostream>
#include<algorithm>
#include<istream>
#include<ostream>
#include<iterator>
#include<vector>
using namespace std;
int main(int argc, char **argv)
{
	istream_iterator<int> int_number(cin);
	istream_iterator<int> int_end;
	vector<int> vec ,vec1;
	ostream_iterator<int> out_number(cout, " ");
	while (int_number != int_end)
	{
		vec.push_back(*int_number);
		int_number++;
	}
	sort(vec.begin(), vec.end());

	unique_copy(vec.begin(), vec.end(),back_inserter(vec1));
	stable_sort(vec1.begin(), vec1.end(), [](int a, int b) {return a < b; });
	copy(vec1.begin(), vec1.end(), out_number);
	system("pause");
	return 0;
}