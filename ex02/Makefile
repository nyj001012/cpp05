NAME = bureaucrat
SRCS = main.cpp \
	   Bureaucrat.cpp \
	   AForm.cpp \
	   ShrubberyCreationForm.cpp \
	   RobotomyRequestForm.cpp
OBJS = ${SRCS:.cpp=.o}

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM = rm -f

all:	${NAME}

${NAME}:	${OBJS}
		@${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}
		@echo "\033[40;35mExecutable ${NAME} created"

%.o: %.cpp
		@${CXX} ${CXXFLAGS} -I . -c $< -o ${<:.cpp=.o}

clean:
		${RM} ${OBJS} *_shrubbery

fclean:	clean
		${RM} ${NAME}

re:		fclean all
