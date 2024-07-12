#include <stdio.h>
//day01
void main()
{
	const int i = 10;
	printf("i: %d\n", i);
/*	
	i = 20;				// 상수선언으로 읽기만 가능, erorr
  printf("i: %d\n", i);		
*/
//  int*  pi = &i;
//  printf("*pi: %d\n",*pi);

	const int* pi2 = &i;
	printf("*pi2: %d\n", *pi2);

//	*pi2 = 20; // error
}
