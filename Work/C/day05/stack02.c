/* 연결리스트로 구현*/
#include <stdio.h>
#include <stdlib.h>
#define STACK_SZ 10

typedef struct STACK{
		int buf[STACK_SZ];
		int top;
}stack;

void push(stack*, int);
int pop(stack*);

void main()
{
	stack newSt;
	newSt.top = -1;
	push(&newSt,1);
	push(&newSt,2);
	push(&newSt,3);
	printf("%d\n", pop(&newSt));
	printf("%d\n", pop(&newSt));
	printf("%d\n", pop(&newSt));

}

void push(stack* st, int value)
{
	if(st->top == STACK_SZ -1){
		printf("stack overflow\n");
		return;
	}
 	++	st->top;
	st->buf[st->top] = value;
//	st->buf[++(st->top)] = value;
	printf("%d\n",value);
}

int pop(stack* st)
{
	if(st->top == -1){
		printf("stack underflow\n");
		return 0;
	}
	int delete;
	delete = st->buf[st->top];
	st->top--;
	return delete;
 //	return st->buf[(st->top)--];	//반환되는 값이 buf 배열안의 top번 인덱스 값
}

