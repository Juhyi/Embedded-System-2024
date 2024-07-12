#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{  //  각 노드를정의하는 구조체 선언
	int data;
	struct NODE* next;  // 다음 노드를 가리키는 포인터 next
}node;   // typedef로 struct NODE를 간단하게 node로 선언가능

void preaddNode(node* pnode, int data)			//전위 삽입 : 맨앞에 노드에 삽입.
{
  node* newnode = (node*)malloc(sizeof(node)); // node 사이즈의 새로운 노드할당
	newnode -> data = data; // newnode 데이터에 매개변수 int 값 저장
	newnode -> next = pnode->next;//새로운 노드가 현재 노드의 다음 노드를 가리키게 함.
	pnode->next = newnode;				//node가 새로 생성될때마다 첫번째 노드로 삽입, (현재 노드가  새로운 노드를 가리키도록 함
}

void rear_addNode(node* pnode, int _data)  //후위 삽입
{
	node* newnode = (node*)malloc(sizeof(node));  // 새로운 노드추가
	newnode -> data = _data;
	newnode -> next = NULL;

	while(pnode->next != NULL) // 연결리스트의 마지막 노드의 next가 NULL이므로 끝이 될때까지 순회
	{
  	pnode  = pnode->next; // pnode가 다음 노드를 가리킴
  }												// 마지막 노드를 가리킬때 까지 반복

  pnode -> next = newnode; 	//마지막 노드 뒤에 새로만든 노드 붙임
}

void showNode(node * pnode) // 출력 함수
{
 	node*curr = pnode->next;  // curr가 현재 노드를 가리킴
 	while(curr != NULL)       // 값이 다 출력되도록 출력
 	{
 		printf("%d\n",curr->data);  // 현재 데이터 출력
 		curr = curr -> next;      // curr가 다음 노드를 가리키게 함.
 		}
}
void main()
{
  node* head = (node*)malloc(sizeof(node)); // head 노드 할당
  head->next = NULL;

	preaddNode(head,10);
	preaddNode(head,20);
  preaddNode(head,30);
  preaddNode(head,40);
  preaddNode(head,50);
  rear_addNode(head,11);
  rear_addNode(head,12);
  rear_addNode(head,13);
//  node*curr = head->next;  //연결 리스트이 첫번째 노드를 가리키는 포인터. head->next : 첫번째 노드 가리킴.
//  while(curr != NULL){
//  printf("%d",curr->data); // 출력하고
//  curr = curr->next;       // curr을 다음 노드를 가리키게 함.
//  }
   showNode(head);
	 printf("\n");
// 초기화를안하면 NODE5 삭제 후 NODE4가 가리키는게 없음.
// curr = head->next; // 첫번째 노드를 가리키는 curr을 head로 초기화, head가 현재 가리키는 것은 마지막 노드의 주소값
// while(curr !=NULL){
//  head->next = curr->next; // 메모리 반환전에 head가 가리키는 두번째 node(&n4)를 가리키게 함
//  free(curr); // 첫번째노드가 가리키는curr와 메모리 반환. 두번째 node가 첫번째가 됨.
 // curr = head->next; // curr 값이 두번째 node를 가리키게 함
  
 // while 문 밖에서 head->next = null;  
 /*
  node* temp =curr; //현재 노드를 가리키는 curr 임시포인터 temp에 저장.
  curr = curr->next; // 다음 노드로 이동.
  free(temp); // temp가 가리키는 노드 해제, 이전에 저장된 노드 삭제 후 다음 노드가리킴.
 if( curr != NULL){ 		// if 절을 사용하지 않으면 NULL일때 출력시도, 프로그램 종료됨.
  printf("%d 삭제", curr->data);
  }
  printf("%d, %d\n",head->next, curr); */
// free(head); 	// head 해제도 잊지말자,,,!!


}
