# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 17:41:24 by tgernez           #+#    #+#              #
#    Updated: 2022/11/21 16:08:46 by tgernez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf
FTSRCS			= .c
DIRSRCS 		= srcs/
SRCS 			=	$(addsuffix ${FTSRCS},	\
					$(addprefix ${DIRSRCS},	\
					main \
					))
INCLUDES		= -Iincludes
LIBFTDIR		= libft
LIBFTLIB		= -lft
MLXDIR			= minilibx
MLXLIB			= -lmlx
XLIBS			= -lX11 -lXext 
CC				= clang
FLAGS			= -Wall -Wextra -Werror
# OBJS			= ${SRCS:.c=.o}
RM				= rm -rf
RED				= \033[0;31m
NC				= \033[0m
LGREEN			= \033[1;32m
CYAN			= \033[0;36m

# .%.o: %.c
# 	@echo "${CYAN}Compiling $<${NC}"
# 	@${CC} ${FLAGS} -o $@ -c $^ -L${LIBDIR} -l${LIBNAME} ${INCLUDES}

all: ${NAME}
	@echo '_______________________________________________________          '
	@echo ' __/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\_____/\\\\\\\\\\\\\\\_    	    '
	@echo '  _\/\\\///////////__\/\\\////////\\\__\/\\\///////////__        '
	@echo '   _\/\\\_____________\/\\\______\//\\\_\/\\\_____________       '	
	@echo '    _\/\\\\\\\\\\\_____\/\\\_______\/\\\_\/\\\\\\\\\\\_____      '
	@echo '     _\/\\\///////______\/\\\_______\/\\\_\/\\\///////______     '
	@echo '      _\/\\\_____________\/\\\_______\/\\\_\/\\\_____________    '
	@echo '       _\/\\\_____________\/\\\_______/\\\__\/\\\_____________   '
	@echo '        _\/\\\_____________\/\\\\\\\\\\\\/___\/\\\_____________  '
	@echo '         _\///______________\////////////_____\///______________ '
	@echo '          _______________________________________________________'
	@echo '                                                  By tgernez	    '
	@echo "${LGREEN}Successfully created${NC}${CYAN} ${NAME}${NC}${LGREEN}!${NC}"

${NAME}: ${LIBFTDIR}/libft.a ${MLXDIR}/libmlx.a
	${CC} ${SRCS} ${INCLUDES} ${XLIBS} -L${MLXDIR} ${MLXLIB} -L${LIBFTDIR} ${LIBFTLIB} -o $@ 

${LIBFTDIR}/libft.a:
	@make -C ${LIBFTDIR}

${MLXDIR}/libmlx.a:
	@make -C ${MLXDIR}

clean:
	@echo "${CYAN}Cleaned FdF${NC}"
	@${RM} ${OBJS}

fclean:		clean
	@echo "${CYAN}FCleaned FdF${NC}"
	@${RM} ${NAME}

libft_re:
	@make -C ${LIBFTDIR} re

libft_clean:
	@make -C ${LIBFTDIR} clean

libft_fclean:
	@make -C ${LIBFTDIR} fclean

libft_all:
	@make -C ${LIBFTDIR} all

all_clean: clean libft_clean

all_fclean: fclean libft_fclean

mlx_re:
	@make -C ${LIBFTDIR} re

mlx_clean:
	@make -C ${LIBFTDIR} clean

mlx_all:
	@make -C ${LIBFTDIR} all

all_clean: clean libft_clean mlx_clean

all_fclean: fclean libft_fclean mlx_clean

all_re: mlx_re libft_re fclean all
	@echo "${CYAN}Re-ed FdF${NC}"

re: fclean all

.PHONY: all clean fclean re libft_re libft_all libft_fclean libft_clean libft_re 