/*
FILE: linkedList

Created: 24-03-27
Author: 이주희
*/

#include "book_ver2_head.h"

void main()
{
	book* head = 	NULL;
	int choice;
  do {
      printf("\n도서 등록 및 조회 프로그램\n");
      printf("1. 도서 구입 + 등록\n");
      printf("2. 도서 검색- 대여여부\n");
      printf("3. 도서 삭제\n");
      printf("4. 도서 출력- 대여여부\n");
      printf("0. 프로그램 종료\n");
      printf("선택> ");
      scanf("%d", &choice);

      switch (choice) {
          case 1:
              head = bookRegister(head);
              break;
          case 2:
          		printf(" 1. 도서검색 \n");
          		printf(" 2. 도서대여 \n");
          		printf(" 3. 도서반납 \n");
          		printf("선택 > ");
   					  int choice1;
  					  scanf("%d", &choice1);
  					  switch(choice1){
  					  	case 1:
 									searchBooks(head);
 									break;
 								case 2:
 									rentBooks(head);
 									break;
 								case 3:
 									returnBooks(head);
 									break;
       					default:
        				 printf("잘못된 입력입니다.\n");
        				 break;
        				 }
  				   break;
          case 3:
          		deleteBooks(head);
          		if (head != NULL) {
           			 head = head->next;
							}
          		break;
          case 4:
          		showBooks(head);
          		break;
          case 0:
              printf("도서 프로그램을 종료.\n");
              break;
          default:
             printf("잘못된 선택입니다. 다시 시도하세요.\n");
             break;
      }
  } while (choice != 0);

 		book *curr = head;
    while (curr != NULL) {
        book *temp = curr;
        curr = curr->next;
        free(temp);
    }
}

