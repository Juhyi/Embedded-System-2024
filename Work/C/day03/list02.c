#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
	int data;
	struct NODE *next;
} node;

void main()
{
  node* head = (node*) malloc(sizeof(node));
  head->next = NULL; // head는 데이터를 가질 필요X, 첫번째 노드를 가리킴. 

	node* node1 =(node*) malloc(sizeof(node));  //첫번째 노드
	node1->data=10;
	node1->next=NULL;
	head->next = node1;
	
	node* node2 = (node*) malloc(sizeof(node)); //두번째 노드
	node2->data=20;
	node2->next=NULL;
  node1->next = node2;      // 연결리스트의 핵심: 두번째 노드를 연결한다.

  node* node3 =(node*) malloc(sizeof(node));  //세번째 노드
  node3->data = 30;
  node3->next = NULL;
  node2->next = node3;

  node* curr = head->next;		// 첫번째 노드를 가리키게 한다.
  while(curr != NULL){   // 횟수가 정해져 있지 X => while
  printf("%d\n",curr->data);  // 첫번째 노드 데이터 출력
  curr = curr->next; 					// node2(주소값이 들어감)  가리키기.
 }// curr의 next를 curr에 집어 넣으닌깐 curr이 NULL일때 마지막 노드.
	free(node1);
	free(node2);
	free(node3);
}
