#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd[3];
	char* s;

	fd[1] = open("./gnlTester/files/41_with_nl", O_RDWR);
	fd[2] = open("text.txt", O_RDONLY);
	fd[0] = 0;
/*	while (1)
	{
		scanf("%d", &s);
		rewind(stdin);
		if (s <= 3)
			printf("%s", get_next_line(fd[s]));
	}*/

	while (s=get_next_line(fd[1]))
	{
		printf("%s", s);
		free(s);
	}
	printf("%s", get_next_line(fd[1]));
}