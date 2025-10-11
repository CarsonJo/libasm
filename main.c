#include <unistd.h>
#include <stdio.h>
#include <errno.h>
extern int my_strlen(char *str);
extern int my_write(int fd, char *ptr, int size);
extern int my_read(int fd, char *buffer, int size);
int main(int argc, char **argv)
{
	char *test = "testere\n";
	char buffer[100];
	int ret = my_write(257, test, 8);
	perror("my_error");
	int retr = my_read(256, buffer, 100);
	perror("my_error");
	printf("nukmber: %d, %d\n", ret, retr);
	// printf("", my_write(1, test, 8));
	return (0);
}
