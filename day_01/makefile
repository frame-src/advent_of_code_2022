NAME := advent_of_code

ODIR = obj
SDIR = src

SRCS :=	./src/solution.c\
		./src/utils/gnl/get_next_line.c\
		./src/utils/gnl/get_next_line_utils.c\
 
OBJS := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))

CC = cc
CFLAG = -Wall -Wextra -Werror -llibft.a

all: $(NAME)

$(NAME) : $(ODIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAG) -c $^ -o $@

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(ODIR):
	mkdir -p $(ODIR)

.PHONY: all clean fclean re