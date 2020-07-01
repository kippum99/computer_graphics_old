###############################################################################
# CS/CNS 171 Fall 2015
#
# This is a template Makefile for the assignment. Edit it however you find
# convenient.
###############################################################################
# The following line is a relative directory reference that assumes the Eigen
# folder--which your program will depend on--is located one directory above the
# directory that contains this Makefile.
INCLUDE = -I../
CXXFLAGS = -Wall -Werror -Wpedantic -Werror=sign-compare -std=c++14
SOURCES = *.cpp

EXENAME = transformation_parser

all: $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(EXENAME) $(INCLUDE) $(SOURCES)

clean:
	rm -f *.o $(EXENAME)

.PHONY: all clean
