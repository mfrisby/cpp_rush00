NAME = 		ft_retro 	

SRCS =		srcs/ABigShip.cpp \
			srcs/AEntity.cpp \
			srcs/ASimpleShip.cpp \
			srcs/Player.cpp \
			srcs/Weapon.cpp \
			srcs/Game.cpp\
			srcs/Rocket.cpp\
			srcs/main_test.cpp\

OBJS =      $(patsubst srcs/%.cpp, objs/%.o, $(SRCS))

INC =		-I ./includes

FLAGS =		 -Wall -Wextra -Werror

CC =		clang++

all:		$(NAME)

$(NAME):	objs $(OBJS)
			@$(CC) $(FLAGS) -o $(NAME) $(OBJS) -lncurses
			@echo "Clang++..."

objs/%.o:	srcs/%.cpp
			@$(CC) $(FLAGS) $(INC) -o $@ -c $<

objs:
			@mkdir -p objs

clean:
			@rm -rf objs
			@echo "Cleaning..."

fclean:		clean
			@rm -f $(NAME)
			@echo "FClean..."

re:			fclean all

.PHONY =	all clean fclean re