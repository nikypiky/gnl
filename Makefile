Library		= gnl

files 	   = get_next_line \
			get_next_line_utils
Compiler	= cc

CmpFlags	= -Wall -Wextra -Werror

OUTN	= $(Library).a

CFILES	= $(files:%=%.c)

OFILES	= $(files:%=%.o)

NAME	= $(OUTN)

all: $(NAME) run

$(NAME):
	@$(Compiler) $(CmpFlags) -c $(CFILES) -I./ -g 
	@ar -rc $(OUTN) $(OFILES)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

run:
	@cc $(CmpFlags) -c main.c -o main.o -g
	@cc $(CmpFlags) -o main main.o -L.  -g $(NAME) 
	@./main
	@echo

.PHONY: all, clean, fclean, re, run
