  CC		=	g++
  BIN		=	`pwd | rev | cut -d "/" -f1 | rev`
  FLAG		=	-W -Wall -g

  INCLUDE	=	-I./include/
  SRC		=	$(wildcard src/*.cpp)
  OBJ		=	$(SRC:.cpp=.o)
  LIB		=	-lsfml-graphics -lsfml-window -lsfml-system

#################################################################################
## Building details                                                            ##
#################################################################################

  RM		=	rm -f
  ECHO		=	/bin/echo -e
  DEFAULT	=	"\033[00m"
  GREEN		=	"\033[1;32m"
  TEAL		=	"\033[1;36m"
  RED		=	"\033[1;31m"
  BLACK		=	"\033[1;30m"
  YELLOW	=	"\033[1;33m"
  BLUE		=	"\033[1;34m"
  PURPLE	=	"\033[1;35m"
  WHITE		=	"\033[1;37m"

#################################################################################
## Rules                                                                       ##
#################################################################################

  all:		bin
  bin:		$(OBJ)
			@$(CC) $(OBJ) -o $(BIN) $(LIB) && \
			 $(ECHO) $(TEAL) "[OUT]" $(GREEN) $(BIN) $(DEFAULT)

  .cpp.o:
			@$(CC) $(INCLUDE) $(FLAG) -c $< -o $@ && \
			 $(ECHO) $(YELLOW) "[OK] " $(PURPLE) $< $(DEFAULT) || \
			 $(ECHO) $(RED) "[KO]  " $< $(DEFAULT)
  clean:
			@$(RM) $(OBJ) &&                                        \
			 $(ECHO) $(BLUE) "Object file deleted" $(DEFAULT) ||    \
			 $(ECHO) $(RED) "Error in clean rule!" $(DEFAULT)
  fclean:			clean
			@$(RM) $(BIN) &&                                        \
			 $(ECHO) $(BLUE) "Program deleted!" $(DEFAULT) ||       \
			 $(ECHO) $(RED) "Error in fclean rule!" $(DEFAULT)
  re:		fclean all

  .PHONY: all clean fclean re

  .SUFFIXES: .cpp .o