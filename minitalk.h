/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:05:44 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/20 17:23:48 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
#include "libft.h"
#include <sys/types.h>
#include <signal.h>

int 	power2(int n);
int		btoi(char *str);
char	*btoc(char *str);
void 	receive_message(int signal);
void 	send_message(int pid, char *str);
char	*stob(int c);
char	*conv_bin(char *str);
char	*ft_strjoin2(char *s1, char *s2);

#endif