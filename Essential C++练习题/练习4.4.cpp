#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<iomanip>
using namespace std;

class UserProfile
{
public:

	static vector<string> log;
	static void get_log()
	{
		if (!log.empty())
		{
			for (string temp : log)
			{
				cout << temp << endl;
			}
			cout << "总共:" << log.size() << "条记录。" << endl;
		}
	}
	UserProfile() :name("guest"), rank(0),percent(0.0),sign_in_times(0), right_times(0), wrong_times(0) { sign_in(); }
	void get_information()const
	{

		cout << "登陆次数(" << sign_in_times << ")、猜对次数:(" << right_times << ")、猜错次数:(" << wrong_times << ")" << endl;
	}
	void log_sign_in()
	{

		log.push_back(name + "玩过!");
	}
	inline void sign_in()
	{
		sign_in_times++;
	}
	void set_name(string _name)
	{
		name = _name;
		log_sign_in();
	}
	void set_wrong_times(int _wrong_times)
	{
		wrong_times = _wrong_times;
	}
	void set_right_times(int _right_times)
	{
		right_times = _right_times;
	}
	void update_rank()
	{
		//算术规则

	}
	void update_percent()
	{
		percent = ((float)right_times) / ((float)(right_times + wrong_times));
	}
	bool operator ==(UserProfile &tem)const;
	bool operator !=(UserProfile &tem)const;
	friend ostream & operator << (ostream &os, UserProfile &tem);
	friend istream & operator >> (istream &is, UserProfile &tem);
	//void operator ()()
	//{
	//	sign_in_times = 0;
	//	right_times = 0;
	//	wrong_times = 0;
	//	sign_in();
	//}
private:
	string name;
	int sign_in_times;
	int right_times;
	int wrong_times;
	int rank;//0\1\2\3\初级\中级\高级\专家
	float percent;
};
inline bool UserProfile::operator ==(UserProfile &tem)const
{
	if (this->name == tem.name&&this->rank == tem.rank&&this->percent == tem.percent&&this->right_times == tem.right_times&&this->wrong_times == tem.wrong_times&&this->sign_in_times == tem.sign_in_times)
		return true;
	return false;
}

inline bool UserProfile::operator !=(UserProfile &tem)const
{
	if (this->name == tem.name&&this->rank == tem.rank&&this->percent == tem.percent&&this->right_times == tem.right_times&&this->wrong_times == tem.wrong_times&&this->sign_in_times == tem.sign_in_times)
		return false;
	return true;
}

inline ostream & operator << (ostream &os, UserProfile &tem)
{
	os << "用户(" << tem.name << ")登陆次数(" << tem.sign_in_times << ")等级(" << tem.rank << ")答对百分比("<< setiosflags(ios::fixed) << setprecision(2) <<(tem.percent)*100 << "%)答错(" << tem.right_times << ")答对(" << tem.wrong_times << ")" << endl;
	return os;
}
inline istream & operator >> (istream &is, UserProfile &tem)
{

	for (int i = 0; i < 6; ++i)
	{
		switch (i)
		{
		case 0:cout << "用户名:"; is >> tem.name; break;
		case 1:cout << "登陆次数:"; is >> tem.sign_in_times; break;
		case 2:cout << "等级:"; is >> tem.rank; break;
		case 3:cout << "答对百分比:"; is >> tem.percent; break;
		case 4:cout << "答对:"; is >> tem.right_times; break;
		case 5:cout << "答错:"; is >> tem.wrong_times; break;
		}
	}
	return is;
}
vector<string>UserProfile::log = {};//在类中定义static 变量后要初始化，不然会出错。


int main(int argc, char**argv)
{
	//string user_name;
	//map<string, UserProfile> user_all;
	//cout << "请输入用户名:";
	//while (cin >> user_name && user_name != "")
	//{
	//	if (user_name == "log")
	//	{
	//		UserProfile::get_log();
	//		continue;
	//	}

	//	if (!user_all.count(user_name))
	//	{
	//		cout << "欢迎来到我的小程序,亲爱的新手用户！" << endl;
	//		cout << "历史记录:";
	//		user_all[user_name].set_name(user_name);
	//		user_all[user_name].get_information();
	//		continue;
	//	}
	//	cout << "欢迎用户回归！" << endl;
	//	user_all[user_name].sign_in();
	//	user_all[user_name].get_information();
	//}

	UserProfile Test;
	cout << Test;

	
	system("pause");
	return 0;
}