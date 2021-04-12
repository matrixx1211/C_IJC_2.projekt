#############################
#		Marek Bitomský		#
#		2. projekt IJC		#
#		 20. 04. 2021		#
#############################

COMPILER = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -g

CPPCOMPILER = g++
CPPFLAGS = -std=c++17 -pedantic -Wall

TAIL = tail
WORDCOUNT = wordcount

#############################



#############################

all: tail wordcount_cpp

tail: $(TAIL).c
	$(COMPILER) $(CFLAGS) $(TAIL).c -o $(TAIL)

wordcount_cpp: $(WORDCOUNT).cpp
	$(CPPCOMPILER) $(CPPFLAGS) $(WORDCOUNT).cpp -o $(WORDCOUNT)_cpp

#############################

clear: 
	rm *.o tail wordcount wordcount-dynamic wordcount_cpp
# libhtab.a - libhtab.so