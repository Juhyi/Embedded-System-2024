/* 연결리스트를 이용한 큐*/
#ifndef QLIST_H
#define QLIST_H


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

#endif


