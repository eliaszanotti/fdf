# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 17:58:08 by ezanotti          #+#    #+#              #
#    Updated: 2022/11/24 17:22:41 by ezanotti         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_strlen.c ft_bzero.c ft_strchr.c ft_atoi.c ft_calloc.c \
		  ft_strdup.c ft_substr.c ft_strjoin.c ft_split.c ft_itoa.c \
		  get_next_line.c get_next_line_utils.c ft_isnl.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a
HEADER	= includes
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
AR		= ar rcs

all :		${NAME}

%.o: %.c	${HEADER}/libft.h ${HEADER}/get_next_line.h Makefile
			${CC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} 
			${AR} ${NAME} ${OBJS} 

clean :
			${RM} ${OBJS} 

fclean :	clean
			${RM} ${NAME} 

re :		fclean all

.PHONY : all re clean fclean
