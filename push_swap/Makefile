NAME1 = push_swap
NAME2 = checker
MAIN1 = push_swap.c
MAIN2 = checker.c
SRC = libft.c \
		algorithms.c \
		string.c \
		parsing.c \
		printf.c \
		operations.c \
		sol.c \
		oper_ck.c
CC = gcc
FLAGS = -Wall -Wextra -Werror

.PHONY: all re clean fclean

all: $(NAME1) $(NAME2)

$(NAME2): $(SRC:.c=.o) $(MAIN2:.c=.o)
	@echo ">\033[32mCompiling Checker program\033[0m"
	@ $(CC) -o $(NAME2) $(SRC:.c=.o) $(MAIN2:.c=.o) $(FLAGS) -g
	@echo ">\033[32mCompiling of Checker finished successfuly!\033[0m\n"

$(NAME1): $(SRC:.c=.o) $(MAIN1:.c=.o)
	@echo ">\033[32mCompiling executable file\033[0m"
	@ $(CC) -o $(NAME1) $(SRC:.c=.o) $(MAIN1:.c=.o) $(FLAGS) -g
	@echo ">\033[32mCompiling finished successfuly!\033[0m\n"

$(MAIN1:.c=.o): $(MAIN1)
	@ $(CC) -o $@ -c $< $(FLAGS)

$(MAIN2:.c=.o): $(MAIN2)
	@ $(CC) -o $@ -c $< $(FLAGS)

%.o: %.c
	@ $(CC) -o $@ -c $< $(FLAGS)

clean:
	@rm -f $(SRC:.c=.o) $(MAIN1:.c=.o) $(MAIN2:.c=.o)

fclean: clean
	@rm -f $(NAME1) $(NAME2)
	@echo ">\033[32mCleaning successfull!\033[0m\n"

re: fclean all
