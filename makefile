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

#############################



#############################

runtail: tail
#clear
	##################################################
	./tail -n 3 readme.md
	##################################################
	./tail -n 2 <readme.md
	##################################################
	./tail -n +1 <readme.md
	##################################################
	./tail -n 0 <readme.md
	##################################################

tail: $(TAIL).c
	gcc $(TAIL).c -o $(TAIL)

#############################

clear: 
	rm *.o tail wordcount wordcount-dynamic 
# libhtab.a - libhtab.so