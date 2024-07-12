#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
	int data;           // 정수형 데이터
	struct NODE* next;  // 다음 노드를 가리키는 포인터next
}node;

typedef struct{ // headNode 구초제 정의
	node *head;
}headNode;


headNode* createHeadNode(void)
{
	headNode *newhead = (headNode*)malloc(sizeof(headNode));
 	return newhead;
}

void preaddNode(headNode* pnode, int data)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = pnode->head;
	pnode->head = newnode;
}

void rear_addNode(headNode* pnode, int _data)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = _data;
	newnode->next = NULL;
//	node * curr = pnode -> head;

  while(pnode->head->next != NULL)   // Segmentation fault 발생
	{                            // => pnode->head가 NULL이 되어 그 다음 노드를 접근할때 발생할 가능성 O
	                             // list의 시작인 pnode->head를 직접 조작하여문제 발생      
		pnode->head = pnode->head->next;  // list03.c에서는 직접 접근이 아닌 참조, 접근함
	}                                   // 여기서는 직접 조작하므로오류 발생 
	pnode->head->next = newnode;
}

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
  node* curr = pnode->head;
  while(curr !=	NULL)
  {
  //	printf("%d 노드 삭제\n",curr->data);
	//  node* temp = curr;
	//  curr = curr -> next;
	//  free(temp);
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
	preaddNode(newhead,10);
  preaddNode(newhead,20);
	preaddNode(newhead,30);
	preaddNode(newhead,40);
	preaddNode(newhead,50);
	rear_addNode(newhead,11);
	rear_addNode(newhead,12);
	rear_addNode(newhead,13);

	showNode(newhead);
	printf("\n");
	allFreeNode(newhead);
}
