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
			cout << "�ܹ�:" << log.size() << "����¼��" << endl;
		}
	}
	UserProfile() :name("guest"), rank(0),percent(0.0),sign_in_times(0), right_times(0), wrong_times(0) { sign_in(); }
	void get_information()const
	{

		cout << "��½����(" << sign_in_times << ")���¶Դ���:(" << right_times << ")���´����:(" << wrong_times << ")" << endl;
	}
	void log_sign_in()
	{

		log.push_back(name + "���!");
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
		//��������

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
	int rank;//0\1\2\3\����\�м�\�߼�\ר��
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
	os << "�û�(" << tem.name << ")��½����(" << tem.sign_in_times << ")�ȼ�(" << tem.rank << ")��԰ٷֱ�("<< setiosflags(ios::fixed) << setprecision(2) <<(tem.percent)*100 << "%)���(" << tem.right_times << ")���(" << tem.wrong_times << ")" << endl;
	return os;
}
inline istream & operator >> (istream &is, UserProfile &tem)
{

	for (int i = 0; i < 6; ++i)
	{
		switch (i)
		{
		case 0:cout << "�û���:"; is >> tem.name; break;
		case 1:cout << "��½����:"; is >> tem.sign_in_times; break;
		case 2:cout << "�ȼ�:"; is >> tem.rank; break;
		case 3:cout << "��԰ٷֱ�:"; is >> tem.percent; break;
		case 4:cout << "���:"; is >> tem.right_times; break;
		case 5:cout << "���:"; is >> tem.wrong_times; break;
		}
	}
	return is;
}
vector<string>UserProfile::log = {};//�����ж���static ������Ҫ��ʼ������Ȼ�����


int main(int argc, char**argv)
{
	//string user_name;
	//map<string, UserProfile> user_all;
	//cout << "�������û���:";
	//while (cin >> user_name && user_name != "")
	//{
	//	if (user_name == "log")
	//	{
	//		UserProfile::get_log();
	//		continue;
	//	}

	//	if (!user_all.count(user_name))
	//	{
	//		cout << "��ӭ�����ҵ�С����,�װ��������û���" << endl;
	//		cout << "��ʷ��¼:";
	//		user_all[user_name].set_name(user_name);
	//		user_all[user_name].get_information();
	//		continue;
	//	}
	//	cout << "��ӭ�û��ع飡" << endl;
	//	user_all[user_name].sign_in();
	//	user_all[user_name].get_information();
	//}

	UserProfile Test;
	cout << Test;

	
	system("pause");
	return 0;
}