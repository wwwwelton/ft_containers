NAME				=	container

OBJ_DIR				=	objects

SRC_DIR				=	./

VECTOR_HEADERS		=	algorithm.hpp \
						iterator_funcs.hpp \
						iterator_random.hpp \
						iterator_reverse.hpp \
						iterator_traits.hpp \
						type_traits.hpp \
						vector.hpp \
						vector.tpp \

VECTOR_TEST_1		=	test/vector/vector_test_1.cpp
VECTOR_TEST_2		=	test/vector/vector_test_2.cpp

CC					=	c++
CFLAGS				=	-Wall -Wextra -Werror -Wno-long-long
CFLAGS				+=	-std=c++98 -pedantic-errors -g

RM					=	rm -rf

all:				$(NAME)

$(NAME):			$(OBJ_DIR) $(OBJS) $(HEADERS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

vector1:			$(VECTOR_HEADERS)
					$(CC) $(CFLAGS) $(VECTOR_TEST_1) -o vector_test_1
					./vector_test_1

vector2:			$(VECTOR_HEADERS)
					$(CC) $(CFLAGS) -DSTD=1 $(VECTOR_TEST_2) -o vector_test_STD_2
					$(CC) $(CFLAGS) -DSTD=0 $(VECTOR_TEST_2) -o vector_test_FT_2
					./vector_test_FT_2 > vector_test_FT_2_out
					./vector_test_STD_2 > vector_test_STD_2_out
					diff -y vector_test_FT_2_out vector_test_STD_2_out
					diff vector_test_FT_2_out vector_test_STD_2_out


clean:
					$(RM) $(OBJ_DIR)
					$(RM) vector_test_1
					$(RM) vector_test_STD_2 vector_test_STD_2_out
					$(RM) vector_test_FT_2 vector_test_FT_2_out

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
