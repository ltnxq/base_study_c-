
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/uio.h>

/*
 struct iovec{
   ptr_t iov_base;//starting address
   size_t iov_len;// length in bytes
 }

 readv ºÍ writev
 ssize_t readv(int fd,const struct iovec* iov,int iovcnt);
 ssize_t writev(int fd,const struct iovec* iov,int iovcnt);

*/

#define BUF_SIZE 100

static void testReadv()
{
	char buf1[BUFSIZ] = { 0 };
	char buf2[BUFSIZ] = { 0 };
	char buf3[BUFSIZ] = { 0 };
	struct iovec iov[3];
	ssize_t nread;

	iov[0].iov_base = buf1;
	iov[0].iov_len = 5;

	iov[1].iov_base = buf2;
	iov[1].iov_len = 8;

	iov[2].iov_base = buf3;
	iov[2].iov_len = BUF_SIZE;

	nread = readv(STDIN_FILENO,iov,3);
    
	printf("%ld bytes read.\n", nread);
	printf("buf1: %s\n", buf1);
	printf("buf2: %s\n", buf2);
	printf("buf3: %s", buf3);

	printf("over");

}

static void testWritev()
{
	struct iovec iov[3];
	char* p1 = "I";
	char* p2 = " am";
	char* p3 = " happy.\n";

	iov[0].iov_base = p1;
	iov[0].iov_len = strlen(p1);

	iov[1].iov_base = p2;
	iov[1].iov_len = strlen(p2);

	iov[2].iov_base = p3;
	iov[2].iov_len = strlen(p3);

	ssize_t ret = writev(STDOUT_FILENO, iov, 3);
	if (ret < 0)
		printf("writev error:\n");

}