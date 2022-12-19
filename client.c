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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_chain;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	new_chain = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_chain)
		return (NULL);
	new_chain[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	while (j < ft_strlen(s2) || (s2[0] == '\0' && j <= ft_strlen(s2)))
	{
		while (i < ft_strlen(s1))
		{
			new_chain[i] = s1[i];
			i++;
		}
		new_chain[i] = s2[j];
		i++;
		j++;
	}
	return (new_chain);
}


void send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if(str[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
	}
}

char	*stob(int c)
{
	int i;
	char *bin;
	int	n;

	i = 7;
	bin = malloc(8 + 1);
	bin[8] = '\0';
	while(i >= 0)
	{
		bin[i] = (c % 2) + 48;
		c /= 2;
		i--;
	}
	return bin;
}

char	*conv_bin(char *str)
{
	int i;
	char *bits_translate;

	i = 0;
	bits_translate = NULL;
	while (str[i])
	{
		bits_translate = ft_strjoin(bits_translate, stob(str[i]));
		i++;
	}
	bits_translate = ft_strjoin(bits_translate, "00000000");
	return bits_translate;
}

int main(int argc, char **argv)
{
	char *message;

	message = conv_bin(argv[2]);
	send_message(argv[1], message);
	free(message);
	return (0);
}
