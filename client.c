/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:43:09 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/19 20:23:41 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

void send_message(int pid, char *str)
{
	int	i;

	i = 0;
	printf("%s\n", str);
	while(str[i])
	{
		if(str[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(150);
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
	send_message(ft_atoi(argv[1]), message);
	free(message);
	return (0);
}
