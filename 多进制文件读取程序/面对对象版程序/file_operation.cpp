#include "file_operation.h"





file_operation::file_operation(string &file_name, int x, int y, int show_x) : axis_horizontal(x), axis_vertical(y), buffer_size(axis_horizontal*axis_vertical), show_horizontal(show_x), name(file_name)
{
	char_show_x = show_x;
	char_show_y = 0;
	hex_show_x = 0;
	hex_show_y = 0;
	char except_for_char[] = " qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM!@#$%^&*()_+1234567890-=[]\\{}|;':\",./<>?";
	except_for.insert(except_for_char, except_for_char + sizeof(except_for_char) - 1);
	buffer.reset(new byte[buffer_size], [](byte *p) {delete[]p; });//一会要做个实验看能不能正确释放掉.
	file.open(name, ios::in | ios::binary);
	file.seekg(0, ios::end);
	file_size = (int)file.tellg();
	file.seekg(0, ios::beg);
}

file_operation::~file_operation() { file.close(); }

bool file_operation::read_down()
{
	read_surplus_size = file_size - file.tellg();
	if (read_surplus_size >= buffer_size)
	{
		file.read((char*)buffer.get(), buffer_size);
		puts_hex();
		puts_chars();
	}
	else
	{
		buffer_size = read_surplus_size;
		buffer.reset(new byte[read_surplus_size], [](byte *p) {delete[]p; });
		file.read((char*)buffer.get(), read_surplus_size);
		puts_hex();
		puts_chars();
		buffer_size = axis_horizontal * axis_vertical;
	}
	cout << endl;
	return true;

}
void file_operation::puts_hex()
{
	int tem_x = hex_show_x, tem_y = hex_show_y;//读取上次输出的位置
	set_cursor(tem_x, ++tem_y);
	for (int i = 0; i < buffer_size; ++i)
	{
		cout << setfill('0') << setw(2) << hex << (int)buffer.get()[i] << " ";
		if ((i + 1) % axis_horizontal == 0)
		{
			set_cursor(tem_x, ++tem_y);
		}
	}
	get_cursor(hex_show_x, hex_show_y);//记录输出完后的位置
	hex_show_x = 0;
	hex_show_y += 1;
}
void file_operation::puts_chars()
{
	int tem_x = char_show_x, tem_y = char_show_y;//读取上次输出的位置
	set_cursor(tem_x, ++tem_y);
	for (int i = 0; i < buffer_size; ++i)
	{
		

		if (except_for.count(buffer.get()[i]))
			cout << buffer.get()[i];
		else
			cout<<" ";

		if ((i + 1) % axis_horizontal == 0)
			set_cursor(tem_x, ++tem_y);
	}
	get_cursor(char_show_x, char_show_y);//记录输出完后的位置
	char_show_x = show_horizontal;
	char_show_y += 1;
}
void file_operation::get_cursor(int & x, int & y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOut, &bInfo);
	x = bInfo.dwCursorPosition.X;
	y = bInfo.dwCursorPosition.Y;
}
void file_operation::set_cursor(int x, int y)
{
	HANDLE hout;
	COORD coord;
	coord.X = x;
	coord.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
}
bool file_operation::read_up()
{
	file.seekg((int)file.tellg()-buffer_size*2);
	if (read_surplus_size >= buffer_size)
	{
		file.read((char*)buffer.get(), buffer_size);
		puts_hex();
		puts_chars();
	}
	
	cout << endl;
	return true;
	
}

