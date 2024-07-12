#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
	int data;
	struct NODE* next;
}node;

typedef struct {
	node* head;
}headNode;

headNode* createHeadNode(void)
{
	headNode* newhead = (headNode*)malloc(sizeof(headNode));
	return newhead;
}

void preAddNode( headNode* pnode, int data)
{
	node* newnode = (node*)malloc(sizeof(node));
 //if(newNode == NULL) return -1;
 //if(newNode != NULL){
	newnode->data = data;
	newnode->next = NULL;
	pnode->head = newnode;
	
}

void proAddNode( headNode* pnode, int data)
{
	node* newnode = (node*)malloc(sizeof(node));
  if(newnode != NULL){
 	 newnode->data = data;
 	 newnode->next = NULL;
   if(pnode->head == NULL) pnode->head = newnode; //첫번째 노드로 삽입
   else{																					//첫번째 노드가 아니면					
			node* curr = pnode->head;										//마지막 노드를 찾는다.			
	while( curr->next !=NULL)
	{
		curr = curr->next;
	}
	curr -> next = newnode;
	}
 }
}

void showNode(headNode*pnode)
{
	node *curr = pnode->head;
	while(curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
  }
}

void AllFree(headNode*pnode)
{
	node *curr = pnode->head;
	while (curr != NULL)
	{
    printf("메모리해제");
		node* temp = curr; // 현재 노드를 가리키는 포인터curr을 
		curr = curr->next;
		free(temp);
  }
}

node* seachNode(headNode* pnode, int pdata)
{
 


}

void main()
{
	headNode* nehead = createHeadNode() ;
//	preAddNode(nehead, 10);
//	preAddNode(nehead, 20);
	proAddNode(nehead, 11);
	proAddNode(nehead, 12);
	printf("\n");
	showNode(nehead);
	AllFree(nehead);










}




