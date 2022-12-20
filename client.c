/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:43:09 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/20 17:10:39 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(400);
	}
	free(str);
}

char	*stob(int c)
{
	int i;
	char *bin;

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
	bits_translate = ft_strjoin(bits_translate, stob(0));
	return bits_translate;
}
#include <stdio.h>
int main(int argc, char **argv)
{
	char *message;

	message = conv_bin(argv[2]);
	send_message(ft_atoi(argv[1]), message);
	return (0);
}
