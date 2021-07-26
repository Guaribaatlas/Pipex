NAME=pipex
SRC=	src/main.c src/utils.c Get_next_line/get_next_line.c Get_next_line/get_next_line_utils.c src/ft_strdup.c \
		src/ft_strlen.c src/ft_strcpy.c src/ft_strncmp.c src/ft_split.c src/ft_strtrim.c src/ft_strjoin.c
OBJ= $(SRC:.c=.o)
CC= gcc
INC = inc
CFLAGS= -Wall -Wextra -Werror
RM= rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC) $< -c -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


clean:
	@$(RM) $(OBJ)

fclean: clean
	@echo "Removing binary file"
	@$(RM) $(NAME)

re: fclean all