NAME = ft_printf
CC = gcc 
CC_LIB = -L libft/ -lft
CFLAGS = -Wall -Wextra -Werror  
INCL = -I libft/includes
SRCS = main.c ft_printf1.c ft_parse0.c ft_parse1.c ft_parse2.c ft_check.c
OBJS = $(SRCS:.c=.o)
ARAJOUTERDSNAME1 = make -C libft/ fclean && make -C libft/

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(INCL) $(CC_LIB)

bug: $(OBJS) 
	$(CC) -o bug $(CFLAGS) -fsanitize=address $(OBJS) $(INCL) $(CC_LIB)

debug: $(OBJS) 
	$(CC) -o debug $(CFLAGS) -g $(OBJS) $(INCL) $(CC_LIB)

%.o: %.c
	$(CC) $(CFLAGS) $(INCL) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

test : all
	@./ft_printf 
