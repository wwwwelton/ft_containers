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
						rb_tree.hpp \
						rb_tree.tpp \
						rb_tree_private.tpp \
						rb_tree_node.hpp \
						rb_tree_iterator.hpp \
						rb_tree_iterator_reverse.hpp \
						map.hpp \
						map.tpp \

VECTOR_TEST_1		=	test/vector/vector_test_1.cpp
VECTOR_TEST_2		=	test/vector/vector_test_2.cpp

STACK_TEST_1		=	test/stack/stack_test_1.cpp
STACK_TEST_2		=	test/stack/stack_test_2.cpp

PAIR_TEST_1			=	test/pair/pair_test_1.cpp
PAIR_TEST_2			=	test/pair/pair_test_2.cpp

MAP_TEST_1			=	test/map/map_test_1.cpp
MAP_TEST_2			=	test/map/map_test_2.cpp

SET_TEST_1			=	test/set/set_test_1.cpp
SET_TEST_2			=	test/set/set_test_2.cpp

RB_TREE_TEST		=	test/rb_tree/rb_tree_main.cpp

CC					=	clang++
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

map1:				$(HEADERS)
					$(CC) $(CFLAGS) $(MAP_TEST_1) -o map_test_1
					./map_test_1

map2:				$(HEADERS)
					$(CC) $(CFLAGS) -DSTD=1 $(MAP_TEST_2) -o map_test_STD_2
					$(CC) $(CFLAGS) -DSTD=0 $(MAP_TEST_2) -o map_test_FT_2
					./map_test_FT_2 > map_test_FT_2_out
					./map_test_STD_2 > map_test_STD_2_out
					diff -y map_test_FT_2_out map_test_STD_2_out
					diff map_test_FT_2_out  map_test_STD_2_out

set1:				$(HEADERS)
					$(CC) $(CFLAGS) $(SET_TEST_1) -o set_test_1
					./set_test_1

set2:				$(HEADERS)
					$(CC) $(CFLAGS) -DSTD=1 $(SET_TEST_2) -o set_test_STD_2
					$(CC) $(CFLAGS) -DSTD=0 $(SET_TEST_2) -o set_test_FT_2
					./set_test_FT_2 > set_test_FT_2_out
					./set_test_STD_2 > set_test_STD_2_out
					diff -y set_test_FT_2_out set_test_STD_2_out
					diff set_test_FT_2_out  set_test_STD_2_out

rbtree:
					clear && $(CC) $(CFLAGS) $(RB_TREE_TEST) -o btree.out \
					&& ./btree.out

rbtreev:
					clear && $(CC) $(CFLAGS) $(RB_TREE_TEST) -o btree.out \
					&& valgrind ./btree.out


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

					$(RM) map_test_1
					$(RM) map_test_STD_2 map_test_STD_2_out
					$(RM) map_test_FT_2 map_test_FT_2_out

					$(RM) set_test_1
					$(RM) set_test_STD_2 set_test_STD_2_out
					$(RM) set_test_FT_2 set_test_FT_2_out

					$(RM) btree.out

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
