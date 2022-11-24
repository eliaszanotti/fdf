# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 17:58:08 by ezanotti          #+#    #+#              #
#    Updated: 2022/11/24 17:29:21 by ezanotti         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	= ${DIR}ft_strlen.c ${DIR}ft_bzero.c ${DIR}ft_strchr.c \
		  ${DIR}ft_atoi.c ${DIR}ft_calloc.c ${DIR}ft_strdup.c \
		  ${DIR}ft_substr.c ${DIR}ft_strjoin.c ${DIR}ft_split.c\
		  ${DIR}ft_itoa.c ${DIR}get_next_line.c \
		  ${DIR}get_next_line_utils.c ${DIR}ft_isnl.c

OBJS	= ${SRCS:.c=.o}

DIR		= srcs/
NAME	= libft.a
HEADER	= includes/
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
AR		= ar rcs

all :		${NAME}

%.o: %.c	${HEADER}libft.h ${HEADER}get_next_line.h Makefile
			${CC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} 
			${AR} ${NAME} ${OBJS} 

clean :
			${RM} ${OBJS} 

fclean :	clean
			${RM} ${NAME} 

re :		fclean all

.PHONY : all re clean fclean
