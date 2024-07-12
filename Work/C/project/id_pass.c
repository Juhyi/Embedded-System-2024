/* project1.
 아이디와 비밀번호를 입력하여 일치하면 본인의 정보가 저장된 파일을 open*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE_ID  100
#define SIZE_PASS 100
#define SIZE_INFO 1024
/*
typedef struct{
	char id[SIZE_ID];
	char pass[SIZE_PASS];
	char info[SIZE_INFO];
}userinfo;
*/
int compare(char [], char []);
void  main()
{
	char input_id[SIZE_ID];
	char input_pass[SIZE_PASS];
	char id[]= "juhyi12";
	char pass[] = "abc";
	char info[] = "이름: 이주희 생년월일: 991217 전화번호: 01042352449";
	printf("ID  입력> ");
	scanf("%s", input_id);
	printf("PASSWORD 입력> ");
	scanf("%s", input_pass);

	printf("\n**Login 정보 확인**\n");

  FILE *fp;
  fp = fopen("my_info.txt", "w");
  if(fp == NULL)
 	 {
 		 fprintf(stderr, "ERROR");
 	 	 exit(1);
	 }
  fprintf(fp,"*Login impormation\nID:%s\tPASSWORD:%s",input_id, input_pass);
  fprintf(fp,"\n\n*Human impormtion\n%s",info);
  fclose(fp);

  int login = 0;
  int a = compare(id, input_id);
  int b = compare(pass, input_pass);
  if (a == 1 && b == 1)
 	{
    login = 1;
 	 }

  if(login){

   	fp = fopen("my_info.txt", "r");
   	if( fp == NULL)
    {
       fprintf(stderr, "ERROR");
       exit(1);
     }
   	  printf("\nSuccess Login -> File Open\n");
   	  printf("\n***Login impormation***\nID:%s\tPASSWORD:%s",input_id, input_pass);
			printf("\n\n***Human impormtion***\n%s\n",info);
   	  fclose(fp);
   }
  	else
  	{
    	printf("Login Fail\n");
    	printf("Login Again\n");
   	}

}


int compare(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}
