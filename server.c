/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:43:20 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/19 21:00:43 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>


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
	while(str[i])
	{
		decripted[n] = btoi(str, i);
		i += 8;
		n++;
	}
	return (decripted);
}

void receive_message(int signal)
{
	static char *message = NULL;
	static int count = 0;
	static char *final = NULL;

	if (signal == SIGUSR1)
	{
		message = ft_strjoin(message, "1");
		count++;
	}
	else if (signal == SIGUSR2)
	{
		message = ft_strjoin(message, "0");
		count++;
	}
	if(count == 8)
	{
		final = ft_strjoin(final, btoc(message));
		if(ft_strcmp(message, "00000000") == 0)
		{
			dprintf(2, "%s", final);
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
	printf("PID : %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, receive_message);
		signal(SIGUSR2, receive_message);
		pause();
	}
}


