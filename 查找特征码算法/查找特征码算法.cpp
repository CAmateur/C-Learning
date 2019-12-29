#include<stdio.h>
#include<Windows.h>


int main()
{
	char buffer[13] = { 0x77,0x22,0x22,0x22,0x33,0x33,0x22 ,0x55,0x66,0x77,0x88,0x99,0x00 };
	char bufferdest[4] = { 0x22,0x22,0x33,0x33 };
	bool successFlag = false;
	char * destAdress = 0;
	printf("%d\n", sizeof(buffer));

	for (int i = 0; i < sizeof(buffer); i++) {

		if (buffer[i] == bufferdest[0]) {

			for (int n = 1; n < sizeof(bufferdest); n++) {

				if (buffer[n + i] == bufferdest[n]) {

					if (n == (sizeof(bufferdest) - 1)) {

						destAdress = &buffer[i];
						successFlag = true;
						break;
					}
					else {
						continue;
					}

				}
				else {
					break;
				}
			}
		}
		else {
			continue;
		}

		if (successFlag == true) {
			break;
		}
	}



	getchar();

	return 0;
}