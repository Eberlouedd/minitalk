/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:43:20 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/20 17:21:29 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minitalk.h"

int power2(int n)
{
	if (n == 0)
		return (1);
	return (2*power2(n-1));
}

char	*ft_strjoin2(char *s1, char *s2)
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

int	btoi(char *str)
{
	int	i;
	int	result;
	int	n;

	n = 7;
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
	decripted = malloc(2);
	decripted[1] = '\0';
	decripted[0] = (char)btoi(str);
	return (decripted);
}

void receive_message(int signal)
{
	static char *message = NULL;
	static int count = 0;
	static char *final = NULL;

	if (signal == SIGUSR1)
	{
		message = ft_strjoin2(message, "1");
		count++;
	}
	else if (signal == SIGUSR2)
	{
		message = ft_strjoin2(message, "0");
		count++;
	}
	if(count == 8)
	{
		final = ft_strjoin(final, btoc(message));
		if(ft_strcmp(message, "00000000") == 0)
		{
			ft_putstr_fd(final, 1);
			write(1, "\n", 1);
			free(final);
			final = NULL;	
		}
		free(message);
		message = NULL;
		count = 0;
	}
}
int main()
{
	write(1, "PID : ", 6);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, receive_message);
		signal(SIGUSR2, receive_message);
		pause();
	}
}


