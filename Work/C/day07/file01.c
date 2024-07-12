#include <stdio.h>
#include <stdlib.h>
void main()
{
	char msg[20] = "File Test!!";

	FILE* fp;			// 파일 포인터
	fp = fopen("test.txt","w"); // 파일 오픈
	if(fp  ==  NULL){
		fprintf(stderr, "Error"); // 파일에서 printf : fprintf 함수 사용
		exit(1);
	}
	fprintf(fp, "%s", msg);  // 파일로 출력
	printf("%s", msg);
	printf("file descriptor: %d\n", fp);
	fclose(fp);

	char name[20] = "juhyi";
	char name2[] = "jaegyeong";
	char number[] = "01042342449";
	char number2[] = "01023803750";
	FILE* afp;
	afp = fopen("import.txt","w");
	if(fp == NULL){
		fprintf(stderr, "Error");
		exit(1);
	}
	fprintf(afp, "NAME: %s\n", name);
	fprintf(afp, "PHONE NUMBER: %s\n", number);
	fprintf(afp, "NAME: %s\n", name2);
	fprintf(afp, "PHONE NUMBER: %s\n", number2);
	printf("%s", name);

	fclose(afp);
}
