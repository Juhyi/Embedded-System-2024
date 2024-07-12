#include <stdio.h>

extern char* input();
extern void showf(char*);

void main()
{
	char* str = input();
	showf(str);
	showf("\n");
}
