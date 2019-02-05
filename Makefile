# Builds and tests tictactoe game program.
#
# Author (starting point): Russ Tuck
# Authors (everything else):

# Tictactoe uses C++ 2011.  Compile for debugging (-g) with warnings.
# Google Test needs -pthread.
CXXFLAGS=-std=c++11 -g -Wall -Wextra -pthread

# Instructor's note: First target is the default; use it to build everything.
all:		Game-of-Life \


# Main program for users to use.
Game-of-Life :		Game-of-Life.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $^

# Program to run tests and report results.
#tictactoe_test:		tictactoe_test.o tictactoe.o
#	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $^

# Instructor's note: For now, we'll write and run tests with simple C++ code.
# Later, we'll learn to use a unit test framework.  It will ease writing
# tests and improve their output.
