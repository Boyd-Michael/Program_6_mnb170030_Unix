#
# Filename:  	Makefile
# Date:		4/28/2020
# Author:	Michael Boyd
# Email: 	mnb170030@utdallas.edu
# Version:	1.2
# Copyright:	2020, All Rights Reserved
#

CXX = g++
CXXFLAGS = program6.h
CPPFLAGS = -Wall -g -I/scratch/perkins/include
LDFLAGS = -L/scratch/perkins/lib
LDLIBS = -lcdk -lcurses

# Executable Name
EXECFILE = prog6

# Auto include all .cc files
SOURCES := matrixCreation.cc program6.cc recHold.cc
# $(wildcard *.cc)
OBJS = $(SOURCES:.cc=.o)

# Rely on implicit rules for compilation

all: $(EXECFILE)

clean:
	rm -f $(OBJS) $(EXECFILE) *~ \#* program6.h.gch BinaryFileTesting.bin


$(EXECFILE): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)

$(OBJS):
	$(CXX) -c $(SOURCES) $(CXXFLAGS) $(CPPFLAGS)
