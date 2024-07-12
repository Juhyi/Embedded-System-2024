#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;  //자기자신을 가치키는 구조체 변수(자기참고구조체)
}Node;

void main()
{
	Node *node1 = malloc(sizeof(Node));
  node1->data = 10;
  node1->next = NULL;

	printf("node1-data: %d, node- next: %d",node1->data, node1->next);

	Node *node2 = malloc(sizeof(Node));
	node2->data = 11;
	node2->next = NULL;
	printf("node2-data: %d, node2-next: %d", node2->data, node2->next);

  node1->next = node2;

  printf("node2-data: %d\n", node1->data );
  free(node1);
  free(node2);
}
