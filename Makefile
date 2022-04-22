NAME				=	container

OBJ_DIR				=	objects

SRC_DIR				=	./

HEADERS				=	algorithm.hpp \
						iterator_funcs.hpp \
						iterator_random.hpp \
						iterator_reverse.hpp \
						iterator_traits.hpp \
						type_traits.hpp \
						vector.hpp \
						vector.tpp \
						stack.hpp \
						stack.tpp \
						utility.hpp \
						allocator.hpp \

VECTOR_TEST_1		=	test/vector/vector_test_1.cpp
VECTOR_TEST_2		=	test/vector/vector_test_2.cpp

STACK_TEST_1		=	test/stack/stack_test_1.cpp
STACK_TEST_2		=	test/stack/stack_test_2.cpp

PAIR_TEST_1			=	test/pair/pair_test_1.cpp
PAIR_TEST_2			=	test/pair/pair_test_2.cpp

CC					=	c++
CFLAGS				=	-Wall -Wextra -Werror -Wno-long-long
CFLAGS				+=	-std=c++98 -pedantic-errors -g

RM					=	rm -rf

all:				$(NAME)

$(NAME):			$(OBJ_DIR) $(OBJS) $(HEADERS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

vector1:			$(HEADERS)
					$(CC) $(CFLAGS) $(VECTOR_TEST_1) -o vector_test_1
					./vector_test_1

vector2:			$(HEADERS)
					$(CC) $(CFLAGS) -DSTD=1 $(VECTOR_TEST_2) -o vector_test_STD_2
					$(CC) $(CFLAGS) -DSTD=0 $(VECTOR_TEST_2) -o vector_test_FT_2
					./vector_test_FT_2 > vector_test_FT_2_out
					./vector_test_STD_2 > vector_test_STD_2_out
					diff -y vector_test_FT_2_out vector_test_STD_2_out
					diff vector_test_FT_2_out vector_test_STD_2_out

stack1:				$(HEADERS)
					$(CC) $(CFLAGS) $(STACK_TEST_1) -o stack_test_1
					./stack_test_1

stack2:				$(HEADERS)
					$(CC) $(CFLAGS) -DSTD=1 $(STACK_TEST_2) -o stack_test_STD_2
					$(CC) $(CFLAGS) -DSTD=0 $(STACK_TEST_2) -o stack_test_FT_2
					./stack_test_FT_2 > stack_test_FT_2_out
					./stack_test_STD_2 > stack_test_STD_2_out
					diff -y stack_test_FT_2_out stack_test_STD_2_out
					diff stack_test_FT_2_out stack_test_STD_2_out

pair1:				$(HEADERS)
					$(CC) $(CFLAGS) $(PAIR_TEST_1) -o pair_test_1
					./pair_test_1

pair2:				$(HEADERS)
					$(CC) $(CFLAGS) -DSTD=1 $(PAIR_TEST_2) -o pair_test_STD_2
					$(CC) $(CFLAGS) -DSTD=0 $(PAIR_TEST_2) -o pair_test_FT_2
					./pair_test_FT_2 > pair_test_FT_2_out
					./pair_test_STD_2 > pair_test_STD_2_out
					diff -y pair_test_FT_2_out pair_test_STD_2_out
					diff pair_test_FT_2_out pair_test_STD_2_out


clean:
					$(RM) $(OBJ_DIR)

					$(RM) vector_test_1
					$(RM) vector_test_STD_2 vector_test_STD_2_out
					$(RM) vector_test_FT_2 vector_test_FT_2_out

					$(RM) stack_test_1
					$(RM) stack_test_STD_2 stack_test_STD_2_out
					$(RM) stack_test_FT_2 stack_test_FT_2_out

					$(RM) pair_test_1
					$(RM) pair_test_STD_2 pair_test_STD_2_out
					$(RM) pair_test_FT_2 pair_test_FT_2_out

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
