#include <stdio.h>

void main()
{
	for(int i =0; i< 5; i ++) {
		for(int j =0 ; j <4; j ++) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n");

	for(int i=0; i <5; i++){
		for(int j =0; j <=i; j++){
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	int n;
	printf("별을 찍을 단 수를 입력하시오 > ");
	scanf("%d",&n);
	printf("%d단의 삼각형 출력\n",n);
	for(int i =0 ;i<n; i++){
		for(int j =2 ; j <=n-i+1; j++){
			printf(" ");
			}
		for (int j =0; j <= 2*i; j++){
		printf("*");
		}
		printf("\n");
	}
//	printf("\n");



}
