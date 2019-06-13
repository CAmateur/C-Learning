#include<iostream>
#include<vector>

bool defun(std::vector<int>::iterator a,std::vector<int>::iterator b, int c)
{
	 
	do {
		if (a == b)
			return false;
		if (*a == c)
			return true;
		else
			++a;
		
	} while (a != b);

}
int main()
{
	std::vector<int> a1{1,2,3,4,5,6,7,8,9};
	if (defun(a1.begin(), a1.end(), 0))
		std::cout << "сп" << std::endl;
	else
		std::cout << "ц╩сп" << std::endl;
	system("pause");
	return 0;
}