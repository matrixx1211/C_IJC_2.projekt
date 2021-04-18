#############################
#		Marek Bitomský		#
#		2. projekt IJC		#
#		 20. 04. 2021		#
#############################

COMPILER = gcc
CFLAGS = -std=c99 -g -pedantic -Wall -Wextra 

CPPCOMPILER = g++
CPPFLAGS = -std=c++17 -pedantic -Wall

TAIL = tail
WORDCOUNT = wordcount-

HTAB_FILES = htab_bucket_count.c htab_clear.c htab_erase.c htab_find.c htab_for_each.c htab_free.c  htab_hash_function.c htab_init.c htab_lookup_add.c htab_move.c htab_size.c

HTAB_OFILES = htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_for_each.o htab_free.o  htab_hash_function.o htab_init.o htab_lookup_add.o htab_move.o htab_size.o

#############################
all: tail libhtab.a libhtab.so wordcount wordcount-dynamic
#############################


#############################
# TAIL
#############################
tail: $(TAIL).c
	$(COMPILER) $(CFLAGS) $(TAIL).c -o $(TAIL)


#############################
# WORDCOUNT - CPP
#############################
wordcount_cpp: $(WORDCOUNT).cc
	$(CPPCOMPILER) $(CPPFLAGS) $(WORDCOUNT).cc -o $(WORDCOUNT)


#############################
# WORDCOUNT
#############################
wordcount: io.o libhtab.a wordcount.c
	$(COMPILER) $(CFLAGS) io.o wordcount.c -o wordcount libhtab.a


#############################
# WORDCOUNT-dynamic
#############################
wordcount-dynamic: io.o libhtab.so wordcount.c
	$(COMPILER) $(CFLAGS) io.o wordcount.c -o wordcount-dynamic libhtab.so


#############################
# IO
#############################
io.o: io.c io.h
	$(COMPILER) $(CFLAGS) -c io.c -o io.o


#############################
# LIBHTAB - static
#############################
libhtab.a: $(HTAB_FILES) htab.h htab_struct.h
	$(COMPILER) $(CFLAGS) -c $(HTAB_FILES)
	ar -cr $@ $(HTAB_OFILES)


#############################
# LIBHTAB - dynamic
#############################
libhtab.so: $(HTAB_FILES) htab.h htab_struct.h
	$(COMPILER) $(CFLAGS) -c -fPIC $(HTAB_FILES)
	$(COMPILER) $(CFLAGS) -shared -fPIC $(HTAB_OFILES) -o $@


#############################
# ETC - clear, zip
#############################
clear: 
	rm *.o tail wordcount wordcount-dynamic wordcount- libhtab.a libhtab.so
