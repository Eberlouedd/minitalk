#include <stdlib.h>
#include <stdio.h>

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

char	*ft_realloc(char *str, char c)
{
	char	*new;
	int	i;

	result = ft_calloc((ft_strlen(str) + 2), 1);
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = c;
	free(str);
	return (result);
}

char *receive_message(int signal)
{
	char *message;
	static int count = 0;

	if (!message)
		message = ft_calloc(1, 1);
	if (signal == SIGUSR1)
	{
		ft_realloc(message, '1');
		count = 0;
	}
	else
	{
		ft_realloc(message, '0');
		count++;
	}
	if(count == 8)
	{
		printf("%s\n", message);
	}
	free(message);
}

int power2(int n)
{
	if (n == 0)
		return (1);
	return (2*power2(n-1));
}

int	btoi(char *str, int n)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while(i < 8)
	{
		if(str[n] == '1')
			result += power2(i);
		n--; 
		i++;
	}
	return (result);
}

char	*btoc(char *str)
{
	char	*decripted;
	int i;
	int	n;

	i = 7;
	n = 0;
	decripted = malloc(ft_strlen(str) / 8 + 1);
	decripted[ft_strlen(str) / 8] = '\0';
	while(str[i])
	{
		decripted[n] = btoi(str, i);
		i += 8;
		n++;
	}
	return (decripted);
}

int main()
{
	ft_printf("PID : %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, receive_message);
		signal(SIGUSR2, receive_message);
		pause();
	}
}
