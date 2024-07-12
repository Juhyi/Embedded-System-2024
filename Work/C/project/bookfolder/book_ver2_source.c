/*
FILE: linkedList

Created: 24-03-27
Author: 이주희
*/

#include "book_ver2_head.h"

book* bookRegister(book* head)
{
	char title[100];
	char writer[100];
	int year;
	int rented;

	printf("도서 제목 입력> ");
	scanf("%s", title);
	printf("\n도서 저자 입력> ");
	scanf("%s", writer);
	printf("\n도서 출판년도 입력> ");
	scanf("%d", &year);
	book *newbook =(book*)malloc(sizeof(book));
	if (newbook == NULL)
	{
		printf("메모리할당 실패\n");
  	return head;
	}

	strcpy(newbook->title, title);
	strcpy(newbook->writer, writer);
	newbook->year = year;
	newbook->next = NULL;
	if(head == NULL){
		head = newbook;
	}
	else
	{
			book *curr = head;
 			while (curr->next != NULL) {
      	curr = curr->next;
    }
  curr->next = newbook;
 }
  printf("도서 추가완료\n");
  return head;
}

void deleteBooks(book* head){
		if (head == NULL){
				printf("Booklist is Empty\n");
				printf("**Delete Error\n");
		}

		book *curr = head;
		book *prev = NULL;

		char deletetitle[100];
		printf("삭제할 도서명 입력> ");
		scanf(" %s", deletetitle);
		printf("\n** 삭제할 도서명 확인 **\n");
		while(curr != NULL && strcmp(curr->title, deletetitle) != 0)
		{
			prev = curr;
			curr = curr ->next;

		}

		if(curr == NULL)
		{
			printf("삭제할 도서가 존재하지 않음.\n");
			return;
		}

		if(prev == NULL){
				head= head->next;

		} else{
			prev->next = curr->next;
			curr->next = NULL;
	  }
		printf("***[%s] 도서 삭제 완료***\n",curr->title);

		free(curr);
}

void searchBooks(book* head)
{
	if(head == NULL)
	{
		printf("Booklist is Empty.\n");
		return;
	}
	char searchTitle[100];
	printf("찾을 도서명 입력> ");
	scanf(" %s", searchTitle);
	printf("\n**검색한  도서명 확인**\n");


  book* curr = head;
  book* prev = NULL;
	while(strcmp(curr->title, searchTitle) != 0)
	{
		prev = curr;
		curr = curr->next;
		return;
	}

 	if(curr == NULL)
 	{
 		printf("검색한 도서는 존재하지 않습니다.\n");	
 	}
	if(curr != NULL && strcmp(curr->title, searchTitle)== 0){
		printf("[검색한 도서의 정보]\n");
		printf("제목: %s\n저자: %s\n출판년도: %d\n", curr->title, curr->writer,curr->year); 
		if(curr->rented == 0){
		  printf("대여 가능\n");
    }
    else if(curr->rented == 1){
      printf("대여중\n");
    }
	  curr = head;
	  prev = curr->next;
	}

}

void rentBooks(book *head) {
    if (head == NULL) {
        printf("Booklist is Empty.\n");
        return;
    }

    char rentTitle[100];
    printf("대여할 도서명 입력> ");
    scanf(" %s", rentTitle);

    book *curr = head;
    while (curr != NULL) {
        if (strcmp(curr->title, rentTitle) == 0) {
            if (curr->rented == 0) {
                curr->rented = 1;
                printf("***[%s] 도서 대여 완료***\n", curr->title);
                return;
            } else {
                printf("***[%s] 도서는 이미 대여 중입니다.***\n", curr->title);
                return;
            }
        }
        curr = curr->next;
    }

    printf("입력한 도서를 찾을 수 없습니다.\n");
}

void returnBooks(book *head) {
    if (head == NULL) {
        printf("Booklist is Empty.\n");
        return;
    }

    char returnTitle[100];
    printf("반납할 도서명 입력> ");
    scanf(" %s", returnTitle);

    book *curr = head;
    while (curr != NULL) {
        if (strcmp(curr->title, returnTitle) == 0) {
            if (curr->rented == 1) {
                curr->rented = 0;
                printf("***[%s] 도서 반납 완료***\n", curr->title);
                return;
            } else {
                printf("***[%s] 도서는 이미 반납되었습니다.***\n", curr->title);
                return;
            }
        }
        curr = curr->next;
    }

    printf("입력한 도서를 찾을 수 없습니다.\n");
}
void showBooks(book* head) {
    if (head == NULL) {
        printf("Booklist is Empty.\n");
        return;
    }

    printf("[도서 목록]\n");
    int count = 1;
    book *curr = head;
    while (curr != NULL) {
        printf("[%d]\n제목: %s\n저자: %s\n출판년도: %d\n대여 여부:",
               count, curr->title, curr->writer, curr->year);
        if(curr->rented == 0){
        	printf("대여 가능\n");
        } else if(curr->rented == 1){
        	printf("대여중\n");
       	}

        curr = curr->next;
        count++;
        }
}








