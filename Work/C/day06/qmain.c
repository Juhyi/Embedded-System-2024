]/* 연결리스트를 이용한 큐*/
//#include <stdio.h>
#include "qlist.h"

void main()
{
	linkQ* newLink;
	newLink=createLinkQ();
	enQueue(newLink, 10);
	enQueue(newLink, 20);
	printQ(newLink);
  deQueue(newLink);
	enQueue(newLink,30);
	printQ(newLink);
  deQueue(newLink);
  printQ(newLink);
//	deQueue(newLink);
}




