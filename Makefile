NAME = push_swap
CC = cc
CFLAGS = 
RM = rm -f

SRCS = main.c \
	linked_list/ft_lstadd_back.c linked_list/ft_lstadd_front.c linked_list/ft_lstlast.c linked_list/ft_lstnew.c linked_list/ft_lstsize.c \
	operations/push.c operations/reverse_rotate.c operations/rotate.c operations/swap.c \
	parsing/parsing_mode.c parsing/validate_input.c \
	sort/simple_sort.c sort/medium_sort.c sort/complex_sort.c sort/medium_utils.c\
	strategy/adaptive.c strategy/execute_strategy.c \
	utils/disorder.c utils/free.c utils/ft_split.c utils/index.c utils/is_sorted.c utils/safe_atoi.c utils/stack_init.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
