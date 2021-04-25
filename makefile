#############################
#		Marek Bitomský		#
#		2. projekt IJC		#
#		 20. 04. 2021		#
#############################

COMPILER = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra # -g # bcs of VALGRIND and DBG 

CPPCOMPILER = g++
CPPFLAGS = -std=c++17 -pedantic -Wall

HTAB_FILES = htab_bucket_count.c htab_clear.c htab_erase.c htab_find.c htab_for_each.c htab_free.c  htab_hash_function.c htab_init.c htab_lookup_add.c htab_move.c htab_size.c

HTAB_OFILES = htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_for_each.o htab_free.o  htab_hash_function.o htab_init.o htab_lookup_add.o htab_move.o htab_size.o

ZIPNAME = xbitom00

.PHONY: all clear


#############################
all: tail libhtab.a libhtab.so wordcount wordcount-dynamic

everything: all wordcount- movetest movetest-dynamic hashtest hashtest-dynamic pack
#############################


#############################
# TAIL
#############################
tail: tail.c tail.h
	$(COMPILER) $(CFLAGS) $@.c -o $@


#############################
# WORDCOUNT - CPP
#############################
wordcount-: wordcount-.cc
	$(CPPCOMPILER) $(CPPFLAGS) $@.cc -o $@


#############################
# WORDCOUNT
#############################
wordcount: io.o libhtab.a wordcount.c
	$(COMPILER) $(CFLAGS) io.o $@.c -o $@ libhtab.a


#############################
# WORDCOUNT-dynamic
#############################
wordcount-dynamic: io.o libhtab.so wordcount.c
	$(COMPILER) $(CFLAGS) -Wl,-rpath . io.o wordcount.c -o $@ libhtab.so


#############################
# IO
#############################
io.o: io.c io.h
	$(COMPILER) $(CFLAGS) -c io.c


#############################
# LIBHTAB - static
#############################
libhtab.a: $(HTAB_FILES) htab.h htab_struct.h
	$(COMPILER) $(CFLAGS) -c $(HTAB_FILES)
	ar -cr $@ $(HTAB_OFILES)
	ranlib $@


#############################
# LIBHTAB - dynamic
#############################
libhtab.so: $(HTAB_FILES) htab.h htab_struct.h
	$(COMPILER) $(CFLAGS) -c -fPIC $(HTAB_FILES)
	$(COMPILER) $(CFLAGS) -shared -fPIC $(HTAB_OFILES) -o $@


#############################
# TESTING - MOVE
#############################
movetest: io.o libhtab.a wordcount.c
	$(COMPILER) $(CFLAGS) -D MOVETEST io.o wordcount.c -o $@ libhtab.a

movetest-dynamic: io.o libhtab.so wordcount.c
	$(COMPILER) $(CFLAGS) -D MOVETEST -Wl,-rpath . io.o wordcount.c -o $@ libhtab.so


#############################
# TESTING - HASH
#############################
hashtest: io.o libhtab-hashtest.a wordcount.c
	$(COMPILER) $(CFLAGS) io.o wordcount.c -o $@ libhtab-hashtest.a

hashtest-dynamic: io.o libhtab-hashtest.so wordcount.c
	$(COMPILER) $(CFLAGS) -Wl,-rpath . io.o wordcount.c -o $@ libhtab-hashtest.so

libhtab-hashtest.a: $(HTAB_FILES) htab.h htab_struct.h
	$(COMPILER) $(CFLAGS) -D HASHTEST -c $(HTAB_FILES)
	ar -cr $@ $(HTAB_OFILES)
	ranlib $@

libhtab-hashtest.so: $(HTAB_FILES) htab.h htab_struct.h
	$(COMPILER) $(CFLAGS) -D HASHTEST -c -fPIC $(HTAB_FILES)
	$(COMPILER) $(CFLAGS) -D HASHTEST -shared -fPIC $(HTAB_OFILES) -o $@


#############################
# ETC - clear, zip
#############################
pack: *.c *.h Makefile
	zip $(ZIPNAME).zip $^

clear: clear-created

clear-all: clear-created clear-pack

clear-created: 
	rm -f *.o tail wordcount wordcount-dynamic wordcount- libhtab.a libhtab.so movetest movetest-dynamic hashtest hashtest-dynamic libhtab-hashtest.a libhtab-hashtest.so

clear-pack:
	rm -f $(ZIPNAME).zip



