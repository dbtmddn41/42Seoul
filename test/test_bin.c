#include <unistd.h>
#include <stdio.h>
void	proc(char *buf, int index);

int main(void)
{
	char *msg = "abc";
	int i;
	int sig;
	while (*msg != '\0')
	{
		i = 8;
		while (--i >= 0)
		{
			sig = (*msg >> i) & 1;
			printf("%d", sig);
		}
		msg++;
	}
}