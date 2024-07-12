#include<stdio.h>

void main()
{
  char name[10];
  int age;
  printf("이름을 입력하세요 > ");
  scanf("%s",name)  // 매열은 주소 &필요X

	printf("나이를 입력하세요 > " );
	scanf("%d",&age);
	
	printff("이름 : %s, 나이: %d", name, age);



}
