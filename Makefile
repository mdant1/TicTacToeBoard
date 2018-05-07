# Building GoogleTest and running exercise-gtest unit tests against
# all code in SOURCECODE subdirectory. This Makefile is based on the
# sample Makefile provided in the official GoogleTest GitHub Repo v1.7

# Flags passed to the preprocessor and compiler
CXXFLAGS += -g -Wall -Wextra -pthread

# All tests produced by this Makefile.
TESTS = TicTacToeBoard

all : $(TESTS)

clean :
	rm -f $(TESTS) *.o

$(TESTS): TicTacToeBoard.h 
	$(CXX) $(CXXFLAGS) -c TicTacToeBoard.cpp
