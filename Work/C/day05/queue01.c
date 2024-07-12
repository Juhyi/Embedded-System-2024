// 배열로 queue 구현하기 , FIFO 선입선출
#include <stdio.h>
#define Q_SIZE 10

int queue[Q_SIZE];
int rear = 0;
int front = 0;

void enqueue(int);
int dequeue();

void main()
{

//	enqueue(10);
//	enqueue(20);
//	enqueue(30);

	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
  printf("%d\n", dequeue());

}

void enqueue(int data)
{
	if(rear >= Q_SIZE -1){
		printf("queue overflow\n");
		return;
	}

	queue[rear++] = data;
	printf("%d\n", data);
}

int dequeue()
{
	if(front == rear)
	{
		printf("queue underflow\n");
		return 0;
	}

	return queue[front++];
}

