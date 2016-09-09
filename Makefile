# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbateau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 14:55:10 by jbateau           #+#    #+#              #
#    Updated: 2016/06/10 11:31:36 by jbateau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = flem-in

OBJ_PATH = flem-in

NAME = lem-in

CC = clang

CFLAGS = -Wall -Wextra -Werror

SRC_NAME = main.c \
		  ft_putendl.c \
		  ft_strlen.c \
		  ft_putstr.c \
		  ft_strcmp.c \
		  ft_putnbrl.c \
		  ft_putnbr.c \
		  ft_strlen.c \
		  ft_strdup.c \
		  ft_strndup.c \
		  ft_strdel.c \
		  get_next_line.c \
		  ft_strnew.c \
		  ft_strjoin.c \
		  ft_strjoindel.c \
		  ft_strchr_cnt.c \
		  ft_strcpy.c \
		  ft_bzero.c \
		  ft_putchar.c \
		  ft_strtrimall.c \
		  ft_isdigit.c \
		  ft_infoinit.c \
		  ft_pipeinit.c \
		  ft_roominit.c \
		  ft_exit.c \
		  ft_checknbant.c \
		  ft_addroom.c \
		  ft_isroom.c \
		  ft_isinfo.c \
		  ft_isignore.c \
		  ft_savepipe.c \
		  ft_ispipe.c \
		  ft_lenpipe.c \
		  ft_from.c \
		  ft_to.c \
		  ft_fword.c \
		  ft_checkdup.c \
		  ft_infodup.c \
		  ft_checkinfo.c \
		  ft_whichpipe.c \
		  ft_creategraph.c \
		  ft_lastcheck.c \
		  ft_nbroom.c \
		  ft_rnum.c \
		  ft_roomptr.c \
		  ft_trimname.c \
		  ft_printmove.c \
		  ft_printmap.c \
		  ft_savemap.c \
		  ft_ant.c \
		  ft_startinit.c \
		  ft_addfile.c \
		  ft_delfile.c \
		  ft_inum.c \
		  ft_addweight.c \
		  ft_resolve.c \
		  ft_playturn.c \
		  ft_antptr.c \
		  ft_nextroom.c \
		  ft_itoa.c \
		  ft_normstr.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
