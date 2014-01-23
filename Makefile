# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/04 16:27:25 by wbeets            #+#    #+#              #
#    Updated: 2014/01/23 14:32:54 by wbeets           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= filler
FILES	= main.c\
		  strstart.c\
		  analyse.c\
		  save_map.c\
		  free.c
SRC		= $(addprefix src/, $(FILES))
OBJ		= $(SRC:src/%.c=.obj/%.o)
FLAGS	= -Wall -Werror -Wextra
DFLAGS	= -Wall -Werror -Wextra -g3 -pedantic
LIBCOM	= -L libft -lft
NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m
ERROR_COLOR=\x1b[31;01m
WARN_COLOR=\x1b[33;01m
INCLUDE	= -I includes -I libft/includes
DEB		= .deb/test

all: $(NAME)

$(NAME): disp lib disp2 $(OBJ)
	@echo "$(OK_COLOR)\t---OBJECTS CREATED---$(NO_COLOR)"
	@echo  "\t---COMPILING---EXECUTABLE---"
	@gcc $(OBJ) $(INCLUDE) $(FLAGS) $(LIBCOM) -o $@
	@echo  "$(OK_COLOR)\t---SUCCES---"
	@echo  "---COMPILATION COMPLETE---$(NO_COLOR)"

disp:
	@echo  "$(WARN_COLOR)---PLEASE-HOLD---COMPILING--- $(NO_COLOR)"

disp2:
	@echo  "\t---COMPILING---OBJECTS---"

.obj/%.o: src/%.c
	@mkdir -p .obj/
	@echo ".\c"
	@gcc $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf .obj/
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(DEB)
	@make fclean -C libft/

re: fclean all

gdb:
	@mkdir -p .deb/
	@cc -o $(DEB) $(INCLUDE) $(DFLAGS) $(LIBCOM) $(SRC)
	gdb $(DEB)

exec:
	~/p1/algo/fillergit/ruby-2.1.0/bin/./ruby \
	~/p1/algo/fillergit/vm_beta.rb -f map -p1 ~/p1/algo/fillergit/filler \
	-p2 ~/p1/algo/fillergit/a.out > toto

lib:
	@echo "\t---CHECKING LIBRARY---"
	@make -C libft
	@echo "$(OK_COLOR)\t---LIBRARY UP TO DATE---$(NO_COLOR)"

relib:
	@echo "\t---CHECKING LIBRARY---"
	@make re -C libft
	@echo "$(OK_COLOR)\t---LIBRARY UP TO DATE---$(NO_COLOR)"
