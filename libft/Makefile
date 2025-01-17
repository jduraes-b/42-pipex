# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 17:31:07 by jduraes-          #+#    #+#              #
#    Updated: 2023/06/29 20:04:56 by jduraes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
PART1 =	ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c ft_strlen.c ft_tolower.c ft_toupper.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_atoi.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_strnstr.c ft_strrchr.c
PART2 =	ft_itoa.c ft_split.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUSFUNCTIONS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
EXTRA = ft_printf.c ft_isu.c printfaux1.c printfaux2.c printfaux3.c get_next_line_utils.c ft_strstr.c get_next_line.c doublefree.c
SRC =	${PART1} ${PART2} $(EXTRA)
OBJS =	${SRC:.c=.o}
BONUSOBJS =	${BONUSFUNCTIONS:.c=.o}
HEADER =	libft.h
INCLUDE =	-I .
CC =	cc -g
RM =	rm -f
CFLAGS =	-Wall -Wextra -Werror
.o:.c
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS}
bonus:	$(BONUSOBJS) $(OBJS)
	ar rcs ${NAME} ${BONUSOBJS} ${OBJS}
all:	${NAME}
clean:
	${RM} ${OBJS} ${BONUSOBJS}
fclean:	clean
	${RM} ${NAME}
re:	fclean all
