#include <stdio.h>
#include <stdlib.h>

void main()
{
	char msg[20];
	FILE* fp;
	if((fp = fopen("test.txt","r"))== NULL){
		fprintf(stderr," ERROR");		// 모니터와 연결되어있음.
		exit(1);
	}
	fscanf(fp, "%s", msg); // fp 파일의 문자열을 msg에 저장.
	printf("%s\n", msg);

	fclose(fp);
}
