# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 17:58:08 by ezanotti          #+#    #+#              #
#    Updated: 2022/11/26 10:51:24 by ezanotti         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# SOURCES
S_LIB	= ${DIR}ft_isalpha.c ${DIR}ft_isdigit.c ${DIR}ft_isalnum.c \
		${DIR}ft_isascii.c ${DIR}ft_isprint.c ${DIR}ft_strlen.c \
		${DIR}ft_memset.c ${DIR}ft_bzero.c ${DIR}ft_memcpy.c \
		${DIR}ft_memmove.c ${DIR}ft_strlcpy.c ${DIR}ft_strlcat.c \
		${DIR}ft_toupper.c ${DIR}ft_tolower.c ${DIR}ft_strchr.c \
		${DIR}ft_strrchr.c ${DIR}ft_strncmp.c ${DIR}ft_memchr.c \
		${DIR}ft_memcmp.c ${DIR}ft_strnstr.c ${DIR}ft_atoi.c \
		${DIR}ft_calloc.c ${DIR}ft_strdup.c ${DIR}ft_substr.c \
		${DIR}ft_strjoin.c ${DIR}ft_strtrim.c ${DIR}ft_split.c \
		${DIR}ft_itoa.c ${DIR}ft_strmapi.c ${DIR}ft_striteri.c \
		${DIR}ft_putchar_fd.c ${DIR}ft_putstr_fd.c ${DIR}ft_putendl_fd.c \
		${DIR}ft_putnbr_fd.c ${DIR}ft_lstnew.c ${DIR}ft_lstadd_front.c \
		${DIR}ft_lstsize.c ${DIR}ft_lstlast.c ${DIR}ft_lstadd_back.c \
		${DIR}ft_lstdelone.c ${DIR}ft_lstclear.c ${DIR}ft_lstiter.c \
		${DIR}ft_lstmap.c

S_GNL	= ${DIR}get_next_line.c ${DIR}get_next_line_utils.c ${DIR}ft_isnl.c

S_FDF	= main.c ft_parsing.c

O_LIB	= ${S_LIB:.c=.o}
O_GNL	= ${S_GNL:.c=.o}
O_FDF	= ${S_FDF:.c=.o}

OBJS	= ${O_LIB} ${O_GNL} ${O_FDF}

# VARIABLES
NAME	= fdf
DIR		= srcs/
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

# MLX
MLX		= -framework OpenGL -framework AppKit

# COMPILATION
all :		${NAME}

%.o: %.c	libft.h Makefile
			${CC} ${CFLAGS} -I . -I ./mlx -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS}
			${CC} -L./srcs ${OBJS} -o ${NAME} ${MLX}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME} 

re :		fclean all

.PHONY : all re clean fclean
