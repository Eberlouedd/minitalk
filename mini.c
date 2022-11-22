#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*stob(int c)
{
	int i;
	char *bin;
	int	n;

	n = c;
	i = 0;
	while (n != 0)
	{
		n /= 2;
		i++;
	}
	bin = malloc(i + 1);
	bin[i] = '\0';
	i--;
	while(i >= 0)
	{
		bin[i] = (c % 2) + 48;
		c /= 2;
		i--;
	}
	return bin;
}

char	**conv_bin(char *str)
{
	int i;
	char **bits_translate;

	i = 0;
	bits_translate = malloc(ft_strlen(str) + 1);
	while (str[i])
	{
		bits_translate[i] = stob(str[i]);
		i++;
	}
	return bits_translate;
}

int main(int argc, char **argv)
{
	// char **message;

	// message = conv_bin(argv[1]);
	// while(message[i])
	// {
	// 	send_lettre(message[i]);
	// 	i++;
	// }
	printf("oui");
	return (0);
}