#include <stdio.h>

void main()
{
	int arr[2];
	printf("배열의 요소 첫번째 값을 입력하세요> ");
	scanf("%d", &arr[0]);
	printf("배열의 요소 두번째 값을 입력하세요> ");
	scanf("%d", &arr[1]);
	printf("입력된 배열: ");
	for(int i = 0; i <2; i ++){
	printf("%d ", arr[i]);
	}
	printf("\n");
	int temp;
	temp = arr[0];
	if(temp < arr[1])
	{
		temp =arr[0];
	}
	else
	{
		arr[0] = arr[1];
		arr[1] = temp;
	}
	printf("정렬된 배열 : ");
	for(int i = 0; i < 2 ; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
