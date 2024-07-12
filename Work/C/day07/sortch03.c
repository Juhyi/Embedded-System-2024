/*이진 탐색- 함수로 구현*/ 
#include <stdio.h>

int binarySearch(int * , int, int, int); 
void main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int size = sizeof(arr)/sizeof(arr[1]);
	int first = 0;
	int last = size;
	int middle =0;
	int value = 3;
	int index = binarySearch(arr, first, last, value);
	 if (index != -1)
        printf("%d는 배열의 %d번째 위치에 있습니다.\n", value, index);
   else
        printf("%d는 배열에 존재하지 않습니다.\n", value);
}

int binarySearch(int *arr, int first, int last, int value)
{
	while(first <= last){
		int middle =( first + last ) /2;
		if (arr[middle] == value){
		 return middle;
		 }
		else{
			if(arr[middle] < value){
			 first = middle+1;
			 }
			else{
			 last = middle -1;
			 }
			}
 		}
	return -1;
}
