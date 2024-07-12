#include <stdio.h>

int sumf();
int maf();

void main()
{
	int num1, num2;
	sumf(10, 20);
	maf(20, 10);
	printf("더한 값은 %d이고 뺀값은 %d입니다.", sumf(), maf());
}

int sumf(int a, int b)
{
	return a+b;
}

int maf(int a, int b)
{
	return  a -b;

}
