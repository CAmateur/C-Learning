#include<string>
#include<iostream>
#include<forward_list>
using namespace std;
void insert_string(forward_list<string> &list_str, string str_reserch, string str_insert)
{
	forward_list<string>::iterator curr = list_str.begin();
	forward_list<string>::iterator prev;
	bool str_ReserchAndInsert = false;
	
	while (curr != list_str.end())
	{
		if (*curr == str_reserch)
		{
			curr = list_str.insert_after(curr, str_insert);
			str_ReserchAndInsert = true;

		}
		else
			prev = curr;
			++curr;
	}
	if (str_ReserchAndInsert == false)
	{
		
		list_str.insert_after(prev, str_insert);
	}
}


int main(int argc, char**argv)
{
	forward_list<string> list_str{ "111","222","333","444" };

	insert_string(list_str, "111", "555");
	for (string content : list_str)
		cout << content << endl;

	system("pause");
	return 0;
}