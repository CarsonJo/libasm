#include <unistd.h>
#include <stdio.h>
extern int my_strlen(char *str);

int main()
{
	char *test = "testere\n";

	printf("result : %d\n", my_strlen(test));

	return (0);
}
