# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 13:06:49 by tberthie          #+#    #+#              #
#    Updated: 2017/07/11 15:35:55 by tberthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(addsuffix .o, $(addprefix objs/, main parse render))

NAME = mod1

all: objs $(NAME)

$(NAME): $(OBJS)
	g++ -o $(NAME) $(OBJS) SDL/SDL_lib SDL/SDL_libttf

objs:
	mkdir objs

objs/%.o: srcs/%.cpp
	g++ -c $< -o $@ -I includes -I SDL -Wall -Wextra

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: fclean all
