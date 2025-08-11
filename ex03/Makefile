# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 11:45:58 by fmaurer           #+#    #+#              #
#    Updated: 2025/08/11 11:27:05 by fmaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Simple skeleton Makefile

NAME 		= abstract

VPATH 	= .

SRC			= main.cpp utils.cpp AMateria.cpp Cure.cpp Ice.cpp IMateriaSource.cpp MateriaSource.cpp Character.cpp ICharacter.cpp Tests.cpp
HDR			= utils.hpp AMateria.hpp Cure.hpp Ice.hpp ICharacter.hpp Character.hpp IMateriaSource.hpp MateriaSource.hpp Tests.hpp
OBJDIR	= obj
OBJS		= $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC))
CFLAGS	= -Wall -Werror -Wextra -Wshadow -std=c++98
CPP			= c++

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

# will never try to compile HDR or any other prequesite specified after `%.c`.
# this is because the `%.o` and matched against all .c-files in the current dir.
$(OBJDIR)/%.o: %.cpp $(HDR) | $(OBJDIR)
	$(CPP) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(OBJDIR)

nodebug: CFLAGS += -DDEBUG=0
nodebug:
	$(CPP) $(CFLAGS) -o $(NAME) $(SRC)

debug:
	$(CPP) -g $(CFLAGS) -o $(NAME) $(SRC)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re nodebug debug
