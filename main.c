#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd[3];
	int s;

	fd[1] = open("./gnlTester/files/nl", O_RDONLY);
	fd[2] = open("text.txt", O_RDONLY);
	fd[0] = 0;
	while (1)
	{
		scanf("%d", &s);
		rewind(stdin);
		if (s <= 3)
			printf("%s\n", get_next_line(fd[s]));
	}
}