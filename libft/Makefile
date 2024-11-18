SOURCE = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strip.c
BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
SRC_OBJECT = $(SOURCE:.c=.o)
BNS_OBJECT = $(BONUS:.c=.o)
NAME = libft.a

$(NAME) : all

all : LAST_ALL
bonus: LAST_BONUS

%.o : %.c
	cc -c $< -o $@ -Wall -Werror -Wextra

LAST_ALL : $(SRC_OBJECT)
	rm -rf LAST_BONUS
	ar -cr $(NAME) $^
	touch $@

LAST_BONUS : $(BNS_OBJECT)
	rm -rf LAST_ALL
	ar -cr $(NAME) $^
	touch $@

clean :
	rm -rf $(BNS_OBJECT) $(SRC_OBJECT)
	rm -rf LAST_ALL LAST_BONUS

fclean : clean
	rm -rf $(NAME) 

re : fclean all