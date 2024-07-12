/* main에서 오름차순 정렬*/
#include <stdio.h>

void main()
{
	int arr[] = {9, 4, 8, 15, 3, 7, 2, 1};
	//오름차순으로 정리

	printf("배열: \n");
  for (int i = 0; i < 8; i++)
    printf("%d ", arr[i]);
  printf("\n");


	for(int i = 0 ; i < 8; i++)
	{
	 for(int j =0; j < 7 - i ; j++)
	 {
			if(arr[j] > arr[j+1])
			{
			int temp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = temp;
			}
		}
	}
	printf("정렬된 배열: ");
  for (int i = 0; i < 8; i++)
  {
   		printf("%d ", arr[i]);
   }
   printf("\n");



}
