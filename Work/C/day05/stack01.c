/* 배열로 구현 _ stack  LIFO*/
#include <stdio.h>

#define STACK_SZ 10
#define TRUE 1
#define FALSE 0
int stack[STACK_SZ];
int top = -1;
void push(); // 함수선언
int pop();

void main()
{
	push(3);   // xx = puch(3); 형태면 출력이 존재하여 받는 행위가 존재
	push(5);   // 함수 호출
	push(10);

	printf("%d\n", pop());
	printf("%d\n", pop());
}
int  isFull(void){
	if (top == STACK_SZ -1)
	 return TRUE;
	else {
	 return FALSE;
	 }
}
// isFull() if(isFull) {  }
void  push(int data) // 함수 정의
{
  if(isFull()) {
		printf("stack overflow!!!\n");
		return;
  }
	stack[++top] = data;  // 오버플로때문에 ++전위로 사용.
	//return 0 ;  // 0이 가지는 의미는 있음 => 정상적으로 실행되었다
}
int isEmpty(void){
	if (top <= -1) // 사용환경에서 일시적 오류가 발생할 수 있으므로 == 말고 <= 사용.
	{
	  return TRUE;
   }
  else {
  	return FALSE;
  }
}
int  pop()
{
	//if(top == -1){
	if(isEmpty()){
		printf("stack underflow\n");
		return -1;
  }
	return stack[top--];
  //top--;
}
