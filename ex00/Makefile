NAME		= BraiiiiiiinnnzzzZ
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g
RM			= rm -f

OBJ_DIR		= obj

VPATH		= src

SRCS 		=	main.cpp \
				newZombie.cpp \
				randomChump.cpp \
				Zombie.cpp
				
OBJS		= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

INCLUDES	= -Iinclude 

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "BrainZ OK\n"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean: 
	@$(RM) -r $(OBJ_DIR)
	@echo "Objects removed\n"

fclean: clean
	@$(RM) -r $(NAME)

re: fclean all

.PHONY : all clean fclean re
