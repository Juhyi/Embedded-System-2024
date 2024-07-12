#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
	int data;           // 정수형 데이터
	struct NODE* next;  // 다음 노드를 가리키는 포인터next
}node;

typedef struct{ // headNode 구초제 정의
	node *head;   // 연결리스트의 헤드 노드를 가리키는포인터
	              // head를 포함
}headNode;


headNode* createHeadNode(void)
{
	headNode *newhead = (headNode*)malloc(sizeof(headNode));
	//newhead->data = 0;
	//newhead->next = NULL;
 	return newhead;
}
// newhead: headNode의 구조체 포인터,
//  => 이 구조체는 'node'의 구조체 포인터인 head를 멤버로 가짐.
// newhead-> head가 node를 가리키는 포인터
// 즉, newhead->head->data는 node 구조체의 data 멤버에 접근
void preaddNode(headNode* pnode, int data) //전위 삽입
{
	node* newnode = (node*)malloc(sizeof(node)); // newnode 동적할당
	newnode->data = data;
	newnode->next = pnode->head; // newnode의next포인터
	                             // => 기존의 헤드노드를 가리키도록 설정
	pnode->head = newnode;	     // 헤드포인터인 pnode->head를 새로운 노드로업데이트.
	                             // => 새로운 노드가 연결리스트의 새로운 헤드      
}

void rear_addNode(headNode* pnode, int _data)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = _data;
	newnode->next = NULL;        // newnode의 next를 NULL로 설정
	                             // => 새로운 노드가 연결리스트의 마지막 노드
	node * curr = pnode -> head; // 임시변수 curr, curr이 헤드노드를 가리키게 초기화
// pnode는 headNode 구조체를 가리키는 포인터
// headNode 구조체는 연결리스트의 시작을 가리키는 head를 가짐.
// => pnode->head는 pnode가 가리키는 headNode 구조체의 head 멤버를 가리킴.
// => 즉, pnode->head는 연결리스트의 시작을 가리키는 포인터이고 이것을 curr에 할당

	while(curr->next != NULL)    // 연결리스트의 끝까지 이동
	{
		curr= curr->next;
	}
	curr->next = newnode;        // 연결리스트의 끝에 도달 후 
}                              // newnode를 마지막노드의 next로 연결 

void showNode(headNode* pnode)
{
	node* curr = pnode ->head;
	while(curr != NULL)
	{
	 	printf("%d\n", curr->data);
	 	curr=curr->next;
	}
}

void allFreeNode(headNode *pnode)
{
  node* curr = pnode->head; // 연결리스트의 첫번째 노드를 가리키는 포인터 curr선언및 초기화
  while(curr !=	NULL)
  {
  	printf("%d 노드 삭제\n",curr->data);
	  node* temp = curr;  // 현재 노드를 가리키는 포인터 curr을 임시변수에 저장
	  curr = curr -> next; // 다음 노드를 가리키게함/
	  free(temp);  // temp에 저장한 현재 노드 해제
	   //pnode ->next =  curr->next;
	   //free(curr);
	   //curr = pnode->next;
  }
  printf("헤드 삭제\n");
  free(pnode); 
}

void main()
{
//	node *head = (node*)malloc(sizeof(node));
//	head->next = NULL;
	headNode* newhead =createHeadNode();
/*
	preaddNode(newhead,10);
	preaddNode(newhead,20);
	preaddNode(newhead,30);
	preaddNode(newhead,40);
	preaddNode(newhead,50);
	*/
	rear_addNode(newhead,11);
	rear_addNode(newhead,12);
	rear_addNode(newhead,13);
	showNode(newhead);
	printf("\n");
	allFreeNode(newhead);
}
