#include <stdio.h>

void sortfunc(int *, int );
void print(int *, int );
void main()
{
	int arr[]={9, 4, 8, 15, 3, 7, 2, 1};
  static	int size = sizeof(arr)/sizeof(arr[0]);  //(8*4)/(1*4) = 8
	printf("배열: ");
	print(arr, size);

	sortfunc(arr, size);

	printf("정렬된 배열: ");
	print(arr, size);
}

void print(int *arr, int n)
{
	for(int i =0 ; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void sortfunc(int *arr, int n)
{
	for(int i =0; i < n-1; i++)
	{
		for(int j =0; j < n-1-i; j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				}
			}
		}
}
