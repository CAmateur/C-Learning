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
	file.seekg(0,ios::end);
	file_size = (int)file.tellg();
	file.seekg(0, ios::beg);
	

}

file_operation::~file_operation() { file.close(); }

bool file_operation::read_down()
{

	read_surplus_size = file.tellg();

	file.read((char*)buffer.get(), buffer_size);
	puts_hex();
	puts_chars();
	cout << endl;
	return true;

}
void file_operation::puts_hex()
{
	int tem_x = hex_show_x, tem_y = hex_show_y;//读取上次输出的位置
	
	for (int i = 0; i < axis_vertical; ++i)
	{
		set_cursor(tem_x, tem_y+i);
		for (int t = i * axis_horizontal; t < i * axis_horizontal + axis_horizontal; ++t)
		{
			cout << setfill('0') << setw(2) << hex << (int)buffer.get()[t] << " ";
		}
		
	}
	
	get_cursor(hex_show_x, hex_show_y);//记录输出完后的位置
	hex_show_x = 0;
	hex_show_y+=2;

}
void file_operation::puts_chars()
{
	int tem_x = char_show_x, tem_y = char_show_y;//读取上次输出的位置
	
	for (int i = 0; i < axis_vertical; ++i)
	{
		set_cursor(tem_x, tem_y+i);
		for (int t = i * axis_horizontal; t < i * axis_horizontal + axis_horizontal; ++t)
		{
			if (except_for.count(buffer.get()[t]))
				cout << buffer.get()[t];
		}
		
	}
	
	get_cursor(char_show_x, char_show_y);//记录输出完后的位置
	char_show_x = show_horizontal;
	char_show_y+=2;

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
	return true;
}

