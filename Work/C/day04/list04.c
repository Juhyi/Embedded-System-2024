#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
	int data;
	struct NODE* next;
}node;

typedef struct{
	struct node* next;
}headNode;

headNode* createHeadNode(void)
{
	headNode* head = (headNode*)malloc(sizeof(headNode));
	head->next =NULL;
	return head;
}
void preaddNode(node* pnode, int data)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = pnode->next;
	pnode->next = newnode;
}

void rear_addNode(node* pnode, int _data)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = _data;
	newnode->next = NULL;

	while(pnode->next != NULL)
	{
		pnode = pnode->next;
	}

	pnode->next = newnode;
}

void showNode(node* pnode)
{
	node* curr = pnode ->next;
	while(curr != NULL)
	{
	 	printf("%d\n", curr->data);
	 	curr=curr->next;
	}
}

void allFreeNode(node *pnode)
{
  node* curr = pnode->next;
  while(curr !=	NULL)
  {
  	printf("%d 노드 삭제\n",curr->data);
	  node* temp = curr;
	  curr = curr -> next;
	  free(temp);
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
	headNode* head = createHeadNode();
	preaddNode(head,10);
	preaddNode(head,20);
	preaddNode(head,30);
	preaddNode(head,40);
	preaddNode(head,50);
	rear_addNode(head,11);
	rear_addNode(head,12);
	rear_addNode(head,13);
	showNode(head);
	printf("\n");
	allFreeNode(headNode*);
}
