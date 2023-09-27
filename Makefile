Library		= gnl

files 	   = get_next_line \
			get_next_line_utils
Compiler	= cc

CmpFlags	= -Wall -Wextra -Werror

OUTN	= $(Library).a

CFILES	= $(files:%=%.c)

OFILES	= $(files:%=%.o)

NAME	= $(OUTN)

BUFFER	= BUFFER_SIZE=3000

all: $(NAME) run

$(NAME):
	@$(Compiler) $(CmpFlags) -c $(CFILES) -I./ -g3 -D $(BUFFER)
	@ar -rc $(OUTN) $(OFILES)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

run:
	@cc $(CmpFlags) -c main.c -o main.o -g3 -D $(BUFFER)
	@cc $(CmpFlags) -o main main.o -L.  -g3 $(NAME)
	@./main
	@echo

.PHONY: all, clean, fclean, re, run
