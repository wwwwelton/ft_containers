NAME				=	container

OBJ_DIR				=	objects

SRC_DIR				=	./

HEADERS				=	vector.hpp vector.tpp vector_operators.tpp

SRC_FILES			=	main2.cpp

SRCS				=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJS				=	$(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CC					=	c++
CFLAGS				=	-Wall -Wextra -Werror -Wshadow -Wconversion
CFLAGS				+=	-std=c++98 -pedantic-errors -g

RM					=	rm -rf

$(OBJ_DIR)/%.o:		$(SRCS) $(HEADERS)
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJ_DIR) $(OBJS) $(HEADERS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re