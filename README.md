# C_IJC_2.projekt
2. projekt do předmětu IJC


# TAIL
Tiskne posledních 10 řádků nebo -n řádků ze **souboru** nebo ze **stdin**. 
- při spuštění tail s -n +N -> tiskne od řádku N do konce
- při spuštění tail s -n N -> tiskne posledních N řádků
- při spuštění tail bez -n N -> vypíše posledních 10 řádků
- při spuštění tail bez SOUBOR -> čte ze stdin 
- [x] tail.c

# WORDCOUNT
Počítá počet výskytů slov s pomocí hashovací tabulky **HTAB**.
- [x] wordcount.c
- [x] io.h 
- [ ] io.c
# HTAB / LIB
- [x] htab.h
- [x] htab_bucket_count.c
- [ ] htab_clear.c
- [ ] htab_erase.c
- [x] htab_find.c
- [ ] htab_for_each.c
- [x] htab_free.c
- [ ] htab_hash_function.c
- [x] htab_init.c
- [ ] htab_lookup_add.c
- [ ] htab_move.c
- [x] htab_size.c
- [x] htab_struct.h

# MAKEFILE
- [ ] makefile