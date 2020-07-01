###############################################################################
# CS/CNS 171 Fall 2015
#
# This is a template Makefile for the assignment. Edit it however you find
# convenient.
###############################################################################
# CC = g++
# FLAGS = -g
CXXFLAGS = -Wall -Werror -Wpedantic -Werror=sign-compare -std=c++14
SOURCES = *.cpp

EXENAME = obj_parser

all: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(FLAGS) -o $(EXENAME) $(SOURCES)

clean:
	rm -f *.o $(EXENAME)

.PHONY: all clean
