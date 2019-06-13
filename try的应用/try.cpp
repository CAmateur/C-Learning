#include<iostream>
#include<stdexcept>
using namespace std;
int main()
{



			int One = 0, Tow = 0;
			
			while (cin >> One >> Tow) {
				try {

					if (Tow == 0)
						throw runtime_error("Dn't put in 0 at tow site");

					cout << One / Tow << endl;
				}

				catch (runtime_error err) {
					cout << err.what() << endl;
					cout << "\nTry Again? Enter y or n" << endl;
					char c;
					cin >> c;
					if (c == 'n')
						break;
					else if (c == 'y')
						continue;
				}
			}
	system("pause");

	return 0;
}