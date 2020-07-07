###############################################################################
# CS/CNS 171 Fall 2015
#
# This is a template Makefile for the assignment. Edit it however you find
# convenient.
###############################################################################
# The following line is a relative directory reference that assumes the Eigen
# folder--which your program will depend on--is located one directory above the
# directory that contains this Makefile.
# INCLUDE = -I../
# INCLUDE = -I /usr/local/include/eigen-3.3.7
CXXFLAGS = -std=c++17
SOURCES = object.o transformation.o data_loader.o

EXENAME = data_loader

all: $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(EXENAME) $(INCLUDE) $^

clean:
	rm -f *.o $(EXENAME)

.PHONY: all clean
