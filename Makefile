# Makefile
# Makefile for CSC300 Data Structures PA1 Paint Program

# Author:
# Class: CSC300 Data Structures
# Date: Fall 2015

# Usage: make target1 target2 ...

#------------------------------------------------------------------------------

# GNU C/C++ compiler and linker:
LINK = g++

# Preprocessor and compiler flags (turn on warning, optimization, and debugging):
# CPPFLAGS = <preprocessor flags go here>

#CFLAGS = -Wall -O -g -std=c++0x
CFLAGS = -Wall -O -g
CXXFLAGS = $(CFLAGS)

#------------------------------------------------------------------------------
# Targets

all: cs-twilightinmass

#------------------------------------------------------------------------------

cs-twilightinmass: globals.o game.o main.o person.o place.o persons.o plot.o places.o
	$(LINK) -o $@ $^

#-----------------------------------------------------------------------------

clean:
	rm -f *.o *~ core cs-midinmass

