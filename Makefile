NAME		=	bomberman

DIR		=	src/

SRC		=	$(DIR)main.cpp\
			$(DIR)MyGame.cpp\
			$(DIR)Camera.cpp\
			$(DIR)Primitive.cpp\
			$(DIR)Bomberman.cpp\
			$(DIR)Bomb.cpp\
			$(DIR)Object.cpp

OBJ		=	$(SRC:.cpp=.o)

RM		=	rm -f

CC		=	g++

INCLUDE		+=	-I./include/ -I./lib/include

CXXFLAGS	+=	

LDFLAGS		=	-L./lib -Wl,--rpath=./lib -lgdl_gl -lGL -lGLU



$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)
		$(RM) src/*~
		$(RM) src/*#
		$(RM) include/*~
		$(RM) include/*#

fclean	:	clean
		$(RM) $(NAME)

re	: 	fclean all

.cpp.o	:
		$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@