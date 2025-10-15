#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

extern int ft_strlen(char *str);
extern int ft_write(int fd, char *ptr, int size);
extern int ft_read(int fd, char *buffer, int size);
extern char* ft_strcpy(char *dest, char *src);
extern int ft_strcmp(char *dest, char *src);
extern char* ft_strdup(const char *s);

int main(int argc, char **argv)
{
	char buff[100];
	char *test = "testereaaaaa\n";
	char *test2 = "atestereAaaaa\n";
	char *test3 = "testereaaaaa\n";
	char *test4 = ft_strdup(test2);
	char *test5 = strdup(test2);
	printf("strdup:%s%s\n", test4, test5);
	printf("compare: %s%d %s%d\n", test, ft_strcmp(test, test2), test2, strcmp(test, test2));
	printf("compare: %d, %d\n", ft_strcmp(test, test3),strcmp(test, test3));
	char *ptr = ft_strcpy(buff, test);
	printf("%p\n", ptr);
	printf("my length : %d %d\n", ft_strlen(buff), ft_strlen(buff));
	ft_write(1, buff, ft_strlen(buff));
	free(test4);
	free(test5);
	return (0);
}
