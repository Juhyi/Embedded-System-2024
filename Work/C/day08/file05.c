#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
void main()
{
	char data[] = "RINUX...juhyi,42352449";
	char copydata[1024];
	int fd;
	int rd;

	fd = open("juhyi1.txt", O_CREAT|O_RDWR|O_TRUNC,0600);
	if(fd < 0) printf("Open Error");
	if(write(fd, data, strlen(data)) < 0) printf("Write Error");
	close(fd);

	fd = open("juhyi1.txt",O_RDONLY);
	if(read(fd, copydata, 1024) < 0) printf("Read Error");

	printf("%s\n", copydata);

	rd= open("juhyi1_copy.txt", O_RDWR| O_CREAT| O_TRUNC, 0600);
	if(rd < 0) printf("Open Error");
	if(write(rd, copydata, strlen(copydata)) < 0) printf("Write Error");
	close(fd);


}
