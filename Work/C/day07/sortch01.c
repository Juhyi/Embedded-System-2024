#include <stdio.h>
int lSerch(int *, int, int);
void main()
{
	int arr[] = {3, 5, 2, 4, 9, 8, 1};
	int ridx;
	int size = sizeof(arr)/sizeof(arr[1]);
  rdix = lSerch(arr ,size, 9);
	if(ridx == -1) printf("찾는 원소가 없습니다.\n");
	else{
		printf(
		"찾은 인덱스: %d\n", ridx);
	}
}

int lSerch(int *arr, int n, int value)
{
	for(int i =0; i < n; i++)
	{
		if (arr[i] == value)
			return i;
	}
}
