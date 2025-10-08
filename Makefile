NAME = libft.a
SRC = ft_itoa.c \
	ft_split.c \
	ft_strnstr.c \
	ft_memchr.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_atoi.c \
	ft_memcmp.c \
	ft_strdup.c \
	ft_strtrim.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_striteri.c \
	ft_substr.c \
	ft_calloc.c \
	ft_memmove.c \
	ft_strjoin.c \
	ft_tolower.c \
	ft_isalnum.c \
	ft_memset.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_isalpha.c \
	ft_putchar_fd.c \
	ft_strlcpy.c \
	ft_isascii.c \
	ft_putendl_fd.c \
	ft_strlen.c \
	ft_isdigit.c \
	ft_putnbr_fd.c \
	ft_strmapi.c \
	ft_isprint.c \
	ft_putstr_fd.c \
	ft_strncmp.c

BONUS_SRC =	ft_lstadd_back_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstmap_bonus.c \
	ft_lstnew_bonus.c \
	ft_lstsize_bonus.c

OBJC = $(SRC:.c=.o)
BONUS_OBJC = $(BONUS_SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc

all : $(NAME)

$(NAME) : $(OBJC)
	ar rcs $@ $^
	
%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(BONUS_OBJC)
	ar rcs $(NAME) $(BONUS_OBJC)

clean:
	rm -f $(OBJC) $(BONUS_OBJC)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean