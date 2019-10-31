# CMake is higly recommended for your projects

# ---------------------------------------- #
#               Variables				   #
# ---------------------------------------- #

NAME			=	/*#!ProgramName*/

CXX				=	g++

CXXFLAGS		=	-Wall -Wextra

SRC				=	/*#!SrcMakefile*/

CPPFLAGS	    =	-I inc

LD_DIRS			=	-I

LDFLAGS	        =

SRCOBJ	        =	$(SRC:.cpp=.o)

# ---------------------------------------- #
#                 RULES					   #
# ---------------------------------------- #

all: $(NAME)

$(NAME): $(SRCOBJ)
	$(CXX) -o $(NAME) $(SRCOBJ) $(CPPFLAGS) $(LDFLAGS)

debug: CFLAGS += -g3
debug: fclean $(NAME)

clean:
	$(RM) $(SRCOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
