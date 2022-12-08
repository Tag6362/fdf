# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 17:41:24 by tgernez           #+#    #+#              #
#    Updated: 2022/12/08 14:52:03 by tgernez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf
FTSRCS			= .c
DIRSRCS 		= srcs/
SRCS 			=	$(addsuffix ${FTSRCS},	\
					$(addprefix ${DIRSRCS},	\
					main \
					centring \
					parsing_1 \
					parsing_2 \
					plotting_1 \
					plotting_2 \
					clear_image \
					ft_atou_hexa \
					events_window \
					mouse_functions \
					memory_cleaning \
					memory_allocation \
					))
INCLUDES		= -Iincludes
LIBFTDIR		= libft
LIBFTLIB		= -lft
MLXDIR			= minilibx
MLXLIB			= -lmlx
XLIBS			= -lX11 -lXext 
CC				= clang
FLAGS			= -Wall -Wextra
#------------------------------ADD -WERROR
OBJS			= ${SRCS:.c=.o}
RM				= rm -rf
RED				= \033[1;31m
NC				= \033[0m
LGREEN			= \033[1;32m
CYAN			= \033[1;36m

%.o: %.c
	@echo "\033[1A                                                          "
	@echo -n "\033[1A"
	@echo "${CYAN}Compiling $< ${NC}"
	@${CC} ${FLAGS} -o $@ -c $^ ${INCLUDES}

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

${NAME}: ${OBJS} ${LIBFTDIR}/libft.a ${MLXDIR}/libmlx.a
	@${CC} ${OBJS} ${INCLUDES} ${XLIBS} -L${MLXDIR} ${MLXLIB} -L${LIBFTDIR} ${LIBFTLIB} -lm -o $@ -g3

sanitize: ${OBJS} ${LIBFTDIR}/libft.a ${MLXDIR}/libmlx.a
	@${CC} ${OBJS} ${INCLUDES} ${XLIBS} -L${MLXDIR} ${MLXLIB} -L${LIBFTDIR} ${LIBFTLIB} -lm -o fdf -g3 -fsanitize=address 

re_san: fclean sanitize

${LIBFTDIR}/libft.a:
	@make -C ${LIBFTDIR}

${MLXDIR}/libmlx.a:
	@make -C ${MLXDIR}

#----------------------------FDF

clean:
	@echo "${CYAN}Cleaned FdF${NC}"
	@${RM} ${OBJS}

fclean:		clean
	@echo "${CYAN}FCleaned FdF${NC}"
	@${RM} ${NAME}

re: fclean all

#----------------------------LIBFT

libft_all:
	@make -C ${LIBFTDIR} all

libft_clean:
	@make -C ${LIBFTDIR} clean

libft_fclean:
	@make -C ${LIBFTDIR} fclean

libft_re:
	@make -C ${LIBFTDIR} re

#----------------------------MLX

mlx_re:
	@make -C ${LIBFTDIR} re

mlx_clean:
	@make -C ${LIBFTDIR} clean

mlx_all:
	@make -C ${LIBFTDIR} all

#----------------------------ALL

all_clean: clean libft_clean mlx_clean

all_fclean: fclean libft_fclean mlx_clean

all_re: mlx_re libft_re fclean all
	@echo "${CYAN}Re-ed FdF${NC}"

.PHONY: all clean fclean re libft_re libft_all libft_fclean libft_clean libft_re all_re all_fclean all_clean mlx_all mlx_clean mlx_re 
