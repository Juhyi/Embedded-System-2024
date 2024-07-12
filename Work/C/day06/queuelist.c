/* 연결리스트를 이용한 큐*/
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{		// 노드 구조체
	int data;             // 큐의 각 요소. link는 다음 노드를 가리키는 포인터.
	struct NODE* link;
}node;  // 새로운 요소가 큐에 추가될때마다 새로운 node 구조체가 생성됨.
				// 이전 노드의 link가 새로운 노드를 가리키게 됨.

typedef struct {			// 큐 구조체, 뒤와 앞을 가리키는 포인터를 가짐.
	node* rear;
	node* front;
}linkQ;

linkQ* createLinkQ();
void enQueue(linkQ*, int);
int  deQueue(linkQ*);
void printQ(linkQ*);
void main()
{
	linkQ* newLink;
	newLink=createLinkQ();
	enQueue(newLink, 10);
//	enQueue(newLink, 20);
	printQ(newLink);
  deQueue(newLink);
	enQueue(newLink,30);
	printQ(newLink);
  deQueue(newLink);
  printQ(newLink);
	deQueue(newLink);
}

linkQ* createLinkQ()
{
	linkQ* linkedQ= (linkQ*)malloc(sizeof(linkQ)); // 큐 생성 
	linkedQ-> rear = NULL;
	linkedQ-> front = NULL;
	printf("linkQ* 타입의 노드생성\n");
	return linkedQ ;     // 큐의 포인터 반환
}

void enQueue(linkQ* lq, int data)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->link = NULL;

	if(lq->rear == NULL){
  	lq->front = newnode;	// 큐가 비어있는 경우 새로운 노드를 큐의 첫번째 요소로 설정
  	lq->rear = newnode;   // rear를 새로운 노드로 업데이트. 맨 뒤를 newnode로설정
  }
  else{			// 큐가 비어있지 않을 경우
   	lq->rear->link = newnode;		// rear의 다음노드로 새로운 노드 추가
		// lq->rear->link : rear가 가리키는 노드의 link 포인터로 큐의 마지막 요소 다음을 가리킴.
   	lq->rear = newnode;		// rear를 새로운 노드로 업데이트
	  }
    printf("ENQUEUE %d 삽입\n", newnode->data);

}
int deQueue(linkQ* lq)  // 큐에서 요소제거 함수
{/*
	node* temp = lq->front;	// 임시노드 temp 생성, 첫번째 요소를 가리킴
	int data = temp->data;	// 데이터 추출
	lq->front = temp->link;	// front 업데이트 : 현재 front가 가리키는 노드를 큐에서 제거=> 첫번째 요소 제거
  free(temp);
	printf("DEQUEUE %d 추출 \n", data);
	return data;*/
	
			if(lq->front == NULL){
				printf("Queue is Empty, Dequeue Fail\n");
			}
			else{
				node* temp = lq->front;
				int data = temp->data;
				
				lq->front = temp ->link;
				printf("Dequeue %d 추출\n", data);
				free(temp);
				return data;
			}
}

void printQ(linkQ* lq)
{
	if(lq->front ==  NULL)
	{
		printf("QUEUE is Empty!\n");
	}
	else{		                 	// 큐가 비어있지 않은 경우-> front가 가리키는 첫번째 노드 존재 O
    printf("QUEUE : ");
    node* temp = lq->front; //임시노드 생성 후 첫번째 노드를 가리키게 함
	while(temp != NULL)	      // temp가 NULL이 될때가지 순회
	{
		printf("%d ", temp->data); 
		temp = temp->link;		// 다음노드를 가리키도록 temp 업데이트.
	}
	printf("\n");
 }
}




