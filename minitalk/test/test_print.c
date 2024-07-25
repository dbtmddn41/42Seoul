#include <unistd.h>
#include <stdio.h>
void	proc(char *buf, int index);
int main()
{
	char buf[2];
	int i, j;
	i = '0';
	while (1)
	{	
		j = 0;
		while (j < 2)
		{
			proc(buf, j);
			write(1, &i, 1);
			write(1, "\n", 1);
			i++;
			if (i >= '8')
			{
				if (buf[j] == '\0')
					break ;
				j++;
				i = '0';
			}
		}
		write(1, buf, j);
		if (buf[j] == '\0' && j != 2)
			break ;
	}
	write(1, "\n", 1);
}

void	proc(char *buf, int index)
{
	int sig;

	scanf("%d", &sig);

	buf[index] <<= 1;
	if (sig == 0)
		buf[index] &= 0xfe;
	else if (sig == 1)
		buf[index] |= 0x1;
}