
#include "textquery.h"



int main(int argc, char *argv[])

{
	std::string FileName("E:\\hh.txt");

	
	std::ifstream is(FileName);

	TextQuery t1(is);

	std::string word;

	Query q = Query("fiery") & Query("bird") | Query("wind");
	std::cout << q << std::endl;

	std::cout << q.eval(t1) << std::endl;



	system("pause");
	return 0;

}
