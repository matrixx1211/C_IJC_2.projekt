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
WORDCOUNT = wordcount-

#############################



#############################

all: tail wordcount_cpp

tail: $(TAIL).c
	$(COMPILER) $(CFLAGS) $(TAIL).c -o $(TAIL)

wordcount_cpp: $(WORDCOUNT).cc
	$(CPPCOMPILER) $(CPPFLAGS) $(WORDCOUNT).cc -o $(WORDCOUNT)

#htab_bucket_count.c
#htab_clear.c
#htab_erase.c
#htab_find.c
#htab_for_each.c
#htab_free.c
#htab_hash_function.c
#htab_init.c
#htab_lookup_add.c
#htab_move.c
#htab_size.c
#htab_struct.h


#############################

clear: 
	rm *.o tail wordcount wordcount-dynamic wordcount-
# libhtab.a - libhtab.so