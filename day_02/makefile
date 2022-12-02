NAME := aoc_d2
NAME_B := aoc_d2_b

ODIR = obj
SDIR = src

SRCS :=	./src/solution.c\
		./src/utils/gnl/get_next_line.c\
		./src/utils/gnl/get_next_line_utils.c\

B_SRCS :=	./src/solution_bonus.c\
			./src/utils/gnl/get_next_line.c\
			./src/utils/gnl/get_next_line_utils.c\

OBJS := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))
B_OBJS := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(B_SRCS))

CC = cc
CFLAG = -Wall -Wextra -Werror -llibft.a

all: $(NAME)


$(NAME) : $(ODIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_B) : $(ODIR) $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(NAME_B)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAG) -c $^ -o $@

bonus: $(NAME_B)

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all

bonus: $(NAME_B)

$(ODIR):
	mkdir -p $(ODIR)

.PHONY: all clean fclean re