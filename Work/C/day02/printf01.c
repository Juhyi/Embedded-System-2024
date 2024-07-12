#include <stdio.h>

#define BUFSIZE 14
void main()
{
  char str[BUFSIZE] ="RaspberryPI!!";
  printf("%s\n", str);

  for(int i =0; i< BUFSIZE; i++){
		printf("%c", str[i]);
  }
  printf("\n");

}
