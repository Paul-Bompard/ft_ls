SRC = binary_flag.c \
	add_all_data.c \
	flag_extract.c \
	ft_error.c \
	ft_init.c \
	ft_ls.c \
	ft_sort.c \
	ft_rev_sort.c \
	ft_date_sort.c \
	ft_rev_date_sort.c \
	clear_list.c \
	create_all_elem.c \
	create_elem.c \
	add_end.c \
	otoi.c \
	sort_path.c \
	ft_stats.c \
	ft_init_size.c \
	ft_indent.c \
	ft_stat_lstat.c \
	recursive.c \
	main.c \
	# option_1.c \
	# option_R.c \
	# option_a.c \
	# option_l.c \
	# option_r.c \

OBJ = $(SRC:.c=.o)

LIB = libft/

NAME = ft_ls

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C $(LIB)
	gcc -c $(SRC) $(FLAGS)
	gcc -o $(NAME) $(OBJ) $(LIB)libft.a

clean:
	make -C $(LIB) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C $(LIB) fclean

re: fclean all