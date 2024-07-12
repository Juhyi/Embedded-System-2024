#include <stdio.h>
#include <stdlib.h>

void main()
{
	char data[30] = "ju-hyi,42352449...";
	char jdata[30] = "jea-gyeong,23803750";
	char copydata[100];


	FILE* fp;
	fp = fopen("juhyi.txt","w");
	if(fp == NULL){
		fprintf(stderr, "ERROR");
		exit(1);
	}
	fprintf(fp, "%s", data);
	fprintf(fp,"%s",jdata);
	printf("%s", data);
	fclose(fp);

	fp = fopen("juhyi.txt","r");
	if(fp == NULL){
		fprintf(stderr, "ERROR");
		exit(1);
	}
	fscanf(fp, "%s",copydata);
	fclose(fp);

	FILE* cpfp;
  cpfp = fopen("juhyi_copy.txt", "w");
  if(cpfp == NULL){
     fprintf(stderr, "ERROR");
     exit(1);
   }
	 fprintf(cpfp, "%s", copydata);
   fclose(cpfp);

}
