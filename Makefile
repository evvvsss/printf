NAME		= 	libftprintf.a

SRCS		=  	ft_atoi.c 		\
				ft_itoa_16.c	\
				ft_itoa.c		\
				ft_itoa_uint.c	\
				ft_printf.c		\
				add_func.c 		\
				output.c		\
				output_types.c	\
				display_d.c 	\
				display_csp.c	\
				check.c 		\

INCLUDES	=	libftprintf.h

OBJS		= 	${SRCS:.c=.o}

CC			= 	gcc
RM			= 	rm -f

CFLAGS		= 	-Wall -Werror -Wextra 

.c.o:
				${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS}
				ar rcs ${NAME} ${OBJS}
				ranlib $(NAME)

all:			${NAME}

clean:			
				${RM} ${OBJS} 

fclean:			clean 
				rm -rf ${NAME}

re:				fclean all

.PHONY:			all clean fclean 