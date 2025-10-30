NAME = cub3D

SRC =	main.c \
        parsing/tools/ft_strncmp.c \
        parsing/read_file.c \
        parsing/gnl/get_next_line.c \
        parsing/gnl/get_next_line_utils.c \

OBJ = $(SRC:%.c=%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g 

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

.PHONY : clean fclean