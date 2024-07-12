#include <stdio.h>

void main()
{
  char ch;
  char ch2;
  int n; 
//  printf("문자: ");
//  scanf("%c", &ch);
  printf("학번 : ");
  scanf("%d", &n);

//  printf("입력한 문자 : %c, 입력한 숫자: %d", ch, n);
 // getchar(); 사용 or 들여쓰기 하기 enter때문
  printf("이름  : ");
  scanf(" %c", &ch2);
  printf(" %d, %c\n", n ,ch2);

}
/*
int add(int a,int b)
{
 return a+b;
}

int minus(int a, int b)
{
 return a-b;
}

int multi(int a, intb)
{
return a *b;

void main()
{
	int a, b;
	char op;
	printf("첫번째 정수를 입력하세요 > " );
  scanf("%d", &a);
  printf("두번째 정수를 입력하세요 > ");
  scanf("%d", &b);

  printf("연산 기호를 입력하세요 ( +, - , * , /) > " );
  scanf("%c", &op);

  if (op  =='+')
  {
		printf("덧셈 결과 : %d\n" ,add(a,b));
  }
  else if (op == '-')
  {
   printf("뺄셈 결과 : %d\n", minus(a,b));
  }
  else if (op == '*')
  {
 	 printf("곱셈 결과 : %d\n", multi(a,b));
  }
  else if (op == '.')
  {printf("나눗셈 결과 : %d\n", divid(a,b));

 }

		


}

*/




