/*순차 자료구조를 이용한 큐 자료구조*/
#include <stdio.h>
#include <stdlib.h>
#define QSIZE 10

typedef struct  {
	int front;
	int rear;
	char queue[QSIZE];
}queue;

queue*  create();
void enqueue(queue*, char);
char dequeue(queue*);
void printQueue(queue*);
void main()
{
	queue* qa = create();
	enqueue(qa, 'A');
	enqueue(qa, 'B');

	printQueue(qa);	
	dequeue(qa);
	dequeue(qa);

	printQueue(qa);
}

queue* create()
{
	//동적할당
	queue* q = malloc(sizeof(queue));
	if(q == NULL) exit(1);
	q->front = -1;
	q->rear = -1;
	return q;
}
void enqueue(queue* qNew, char a)
{
	if(qNew->rear >= QSIZE -1){
		printf(" QUEUE Overflow!\n ");
		return;
	}
	//qNew->rear++;
	qNew->queue[++(qNew->rear)] = a;
  printf("ENQUEUE: %c\n",qNew->queue[qNew->rear]);
}
char dequeue(queue* q)
{
	if(q->front == q->rear)
	{
		printf("QUEUE Underflow!");
		return -1;
	}
//	else{
	//q->front++;
  char dequeueQ = q->queue[++(q->front)];
  printf("DEQUEUE: %c\n", dequeueQ);
  return dequeueQ;
//  }
}
void printQueue(queue* pq)
{
	if(pq->front == pq->rear)
	{
	 	printf("QUEUE is Empty!\n");
	}
	else{
	printf("QUEUE: "	);
	int i = pq ->front;
//	for(int i= pq->front + 1;i <=  pq->rear; i ++)
	while( i <=pq -> rear)
	{
    //i++;
		printf("%c ",pq->queue[++i]);
	}
	printf("\n");
	}
}



