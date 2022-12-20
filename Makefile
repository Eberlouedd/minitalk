# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 14:16:04 by kyacini           #+#    #+#              #
#    Updated: 2022/12/20 14:41:02 by kyacini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all : client server

server :	server.o
	gcc -o server server.o libft.a

client :	client.o
	gcc -o client client.o libft.a

client.o : client.c
	gcc -o client.o -c client.c

server.o : server.c
	gcc -o server.o -c server.c

clean	:
	rm -rf *.o

fclean	:	clean
	rm -rf ${NAME}
	
re:	fclean all