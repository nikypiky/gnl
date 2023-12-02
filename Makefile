Library		= get_next_line

files 	   = get_next_line \
			get_next_line_utils\
			alt_get_next_line\

Compiler	= cc

CmpFlags	= -Wall -Wextra -Werror

NAME	= $(Library).a

CFILES	= $(files:%=%.c)

OFILES	= $(files:%=%.o)

BUFFER	= BUFFER_SIZE=200000

all: $(NAME) run

$(NAME):
	@$(Compiler) $(CmpFlags) -c $(CFILES) -I./ -g3 -D $(BUFFER) -g
	@ar -rc $(NAME) $(OFILES)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

run:
	@cc $(CmpFlags) -c main.c -o main.o -g3 -D $(BUFFER) -g
	@cc $(CmpFlags) -o main main.o -L.  -g3 $(NAME) -g
	@./main
	@echo

.PHONY: all, clean, fclean, re, run
