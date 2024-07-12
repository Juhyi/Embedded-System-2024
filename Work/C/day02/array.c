#include <stdio.h>
#define MAX 20

void  main()
{
  int arr[MAX];
  int num;

  printf("Input Data(<= 20):  ");
  scanf("%d", &num);
	
	//출력
	for(int i = 0; i < num; i++){
	  printf("배열%d번째를 입력하세요>");
		scanf("%d", &arr[i]);
 }
 printf("입력된 배열 : ");
 for (int i = 0; i < num; i++){
 		printf("%d ", arr[i]);
 		}
 		printf("\n");
	//역순
	   printf("입력된 배열의역순출력 :  " );
   for (int i = num-1; i >= 0 ; i --)
   {
    printf("%d ", arr[i]);
    }
   printf("\n");

}
