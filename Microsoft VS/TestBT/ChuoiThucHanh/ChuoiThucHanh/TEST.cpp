#include <iostream>
using namespace std;
char * createStr(char *s);

int main1()
{
	char *s = "a";
	cout << createStr(s);

	system("pause");
	return 0;
}

char * createStr(char *s) {

char char1 = *s;
char char2 = 'y';

static char str[3];  


str[0] = char1;
str[1] = char2;
str[2] = '\0';

return str;
}