// queue 개념

#include <stdio.h>

void main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int queue[20];
	int rear =0, front =0; // rear로 삽입, front로 삭제
	int size =sizeof(arr)/sizeof(arr[1]);

	for(int i=0; i < size;i++)
	{
		queue[rear++] =arr[i];	//arr의 첫번쩨 요소부터 마지막 요소까지순차저긍로queue 배열에 저장
	}

	for(int i=0; i<size; i++)
	{
		printf("%d\n", queue[front++]); // 후위 증가. 첫번째 요소부터 마지막 요소까지 차례대로 프린트
	}


}

// FIFO을 보여줌 
