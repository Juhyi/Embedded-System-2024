#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BOOKINFO{
	char title[100];
	char writer[100];
	int year;
	struct BOOKINFO* next;
}book;

//void showMenu();
book* bookRegister(book*);
void showBooks(book*);
void deleteBooks(book*);
void searchBooks(book*);
void main()
{
	book* head = 	NULL;
	int choice;
  do {
      printf("\n도서 등록 및 조회 프로그램\n");
      printf("1. 도서 구입 + 등록\n");
      printf("2. 도서 검색\n");
      printf("3. 도서 삭제\n");
      printf("4. 도서 출력\n");
      printf("0. 프로그램 종료\n");
      printf("선택> ");
      scanf("%d", &choice);

      switch (choice) {
        case 1:
              head = bookRegister(head);
              break;
          case 2:
              searchBooks(head);
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

book* bookRegister(book* head)
{
	char title[100];
	char writer[100];
	int year;

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
			book *current = head;
 			while (current->next != NULL) {
      	current = current->next;
    }
  current->next = newbook;
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
		printf("***%s 도서 삭제 완료***\n",curr->title);

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
		printf("***검색한 도서의 정보\n");
		printf("제목: %s, 저자: %s, 출판년도: %d\n", curr->title, curr->writer,curr->year); 
	  curr = head;
	  prev = curr->next;
	}

}
void showBooks(book* head) {
    if (head == NULL) {
        printf("Booklist is Empty.\n");
        return;
    }

    printf("도서 목록:\n");
    int count = 1;
    book *curr = head;
    while (curr != NULL) {
        printf("[%d] 제목: %s, 저자: %s, 출판년도: %d\n", count, curr->title, curr->writer, curr->year);
        curr = curr->next;
        count++;
      }
}









