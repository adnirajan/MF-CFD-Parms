# Makefile for Writing Make Files
# Nirajan Adhikari (04-24-2020)
# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

MF_PARMS: main.o Elements.o Species.o Reaction.o
	$(CXX) $(CXXFLAGS) -o MF_PARMS main.o Elements.o Species.o Reaction.o 

# The main.o target can be written more simply

main.o: main.cpp Elements.h Species.h Reaction.h 
	$(CXX) $(CXXFLAGS) -c main.cpp

Elements.o: Elements.h

Species.o: Species.h Elements.h

Reaction.o: Reaction.h Species.h

clean:
	rm *.o MF_PARMS
