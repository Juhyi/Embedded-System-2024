#include <stdio.h>

char* input()
{
	static char str[10];   //static을 붙이지 않으면 에러뜸
	static char *pstr = str;

	printf("입력 > ");
	scanf("%s",str);

	return pstr;
}
