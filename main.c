#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>

extern size_t	ft_strlen(char *str);
extern ssize_t	ft_write(int fd, char *ptr, int size);
extern ssize_t	ft_read(int fd, char *buffer, int size);
extern char*	ft_strcpy(char *dest, char *src);
extern int		ft_strcmp(char *dest, char *src);
extern char*	ft_strdup(const char *s);

int main()
{

	//////////////////////////////////////////////////strlen
	printf("//////////////////STRLEN///////////////////////\n");
	char	*empty = "";
	char	*test = "test";
	char	*one = "1";

	printf("ft_strlen(empty): %lu\nstrlen(empty): %lu\n", ft_strlen(empty), strlen(empty));
	printf("ft_strlen(one): %lu\nstrlen(one): %lu\n", ft_strlen(one), strlen(one));
	printf("ft_strlen(test): %lu\nstrlen(test): %lu\n", ft_strlen(test), strlen(test));


	//////////////////////////////////////////////strcpy
	printf("//////////////////STRCPY///////////////////////\n");
	char empty_cpy[0];
	char test_cpy[4];
	char one_cpy[1];

	char empty_cpy2[0];
	char test_cpy2[4];
	char one_cpy2[1];

	printf("ft_strcpy(empty): %p %p %s\nstrcpy(empty): %p %p %s\n", ft_strcpy(empty_cpy, empty),empty_cpy, empty_cpy, strcpy(empty_cpy2, empty),empty_cpy2, empty_cpy2);
	printf("ft_strcpy(one): %p %p %s\nstrcpy(one): %p %p %s\n", ft_strcpy(one_cpy, one), one_cpy, one_cpy, strcpy(one_cpy2, one),one_cpy2, one_cpy2 );
	printf("ft_strcpy(test): %p %p %s\nstrcpy(test): %p %p %s\n", ft_strcpy(test_cpy, test),test_cpy , test_cpy , strcpy(test_cpy2, test),test_cpy2 , test_cpy2);


	//////////////////////////////////////////////strcmp
	printf("//////////////////STRCMP///////////////////////\n");
	char *test2 ="test2";
	printf("ft_strcmp(empty): %d\nstrcmp(empty): %d\n", ft_strcmp(empty, one), strcmp(empty, one));
	printf("ft_strcmp(one): %d\nstrcmp(one): %d\n", ft_strcmp(one, one), strcmp(one, one));
	printf("ft_strcmp(test): %d\nstrcmp(test): %d\n", ft_strcmp(test2, test), strcmp(test2, test));


	//////////////////////////////////////////////write
	printf("//////////////////WRITE///////////////////////\n");
	int fd;

	printf("ft_write(fd 1): %zd\n",ft_write(1,"test\n", 5));
	perror("ft_write_error");
	errno = 0;
	printf("ft_write(fd 1): %zd\n",write(1,"test\n", 5));
	perror("write_error");
	errno = 0;

	fd = open("./test.txt", O_CREAT | O_RDONLY, S_IRWXU);
	printf("ft_write(O_RDONLY): %zd\n",ft_write(fd,"test\n", 5));
	perror("ft_write_error");
	errno = 0;
	printf("ft_write(O_RDONLY): %zd\n",write(fd,"test\n", 5));
	perror("write_error");
	errno = 0;
	close(fd);

	printf("ft_write(address): %zd\n",ft_write(1, (void *)0xfffffffffffffff, 5));
	perror("ft_write_error");
	errno = 0;
	printf("ft_write(address): %zd\n",write(1, (void *)0xfffffffffffffff, 5));
	perror("write_error");
	errno = 0;

	fd = open("./test2.txt", O_CREAT | O_RDWR, S_IRWXU);
	printf("ft_write(RDWR): %zd\n",ft_write(fd,"test\n", 5));
	perror("ft_write_error");
	errno = 0;
	printf("ft_write(RDWR): %zd\n",write(fd,"test\n", 5));
	perror("write_error");
	errno = 0;
	close(fd);

	////////////////////////////////////////////read
	printf("//////////////////READ///////////////////////\n");
	char buffer[6] = {0};

	printf("ft_read(fd 0): %zd %s",ft_read(0,buffer, 5), buffer);
	perror("ft_read_error");
	errno = 0;
	memset(buffer, 0, 6);
	printf("read(fd 0): %zd %s",read(0,buffer, 5), buffer);
	perror("read_error");
	errno = 0;
	memset(buffer, 0, 6);

	printf("ft_read(fd -1): %zd %s\n",ft_read(-1, buffer, 5), buffer);
	perror("ft_read_error");
	errno = 0;
	memset(buffer, 0, 6);
	printf("read(fd -1): %zd %s\n",read(-1, buffer, 5), buffer);
	perror("read_error");
	errno = 0;
	memset(buffer, 0, 6);

	fd = open("./test2.txt", O_CREAT | O_RDWR, S_IRWXU);
	printf("ft_read(test2.txt): %zd %s",ft_read(fd, buffer, 5), buffer);
	perror("ft_read_error");
	errno = 0;
	memset(buffer, 0, 6);
	printf("read(test2.txt): %zd %s",read(fd, buffer, 5), buffer);
	perror("read_error");
	errno = 0;
	close(fd);
	///////////////////////////////////////////strdup
	printf("//////////////////STRDUP///////////////////////\n");
	char *ret;

	ret = ft_strdup(test);
	printf("ft_strdup(test): %s\n", ret);
	free(ret);
	ret = strdup(test);
	printf("strdup(test): %s\n", ret);
	free(ret);

	ret = ft_strdup(empty);
	printf("ft_strdup(empty): %s\n", ret);
	free(ret);
	ret = strdup(empty);
	printf("strdup(empty): %s\n", ret);
	free(ret);

	ret = ft_strdup(one);
	printf("ft_strdup(one): %s\n", ret);
	free(ret);
	ret = strdup(one);
	printf("strdup(one): %s\n", ret);
	free(ret);
	return (0);
}
