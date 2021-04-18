# C_IJC_2.projekt
2. projekt do předmětu IJC
## 1. úkol - TAIL
Tiskne posledních 10 řádků nebo -n řádků ze **souboru** nebo ze **stdin**. 
- při spuštění tail s -n +N -> tiskne od řádku N do konce
- při spuštění tail s -n N -> tiskne posledních N řádků
- při spuštění tail bez -n N -> vypíše posledních 10 řádků
- při spuštění tail bez SOUBOR -> čte ze stdin 
- [x] tail.c

## 2. úkol
### WORDCOUNT
Počítá počet výskytů slov s pomocí hashovací tabulky **HTAB**.
- [x] wordcount.c
- [x] io.h 
- [x] io.c
- [ ] htab
### HTAB / LIB
Knihovna, která obsahuje všechny funkce pro práci s hashovací tabulkou.
- [x] htab.h
- [x] htab_bucket_count.c
- [x] htab_clear.c
- [ ] htab_erase.c
- [x] htab_find.c
- [x] htab_for_each.c
- [x] htab_free.c       **tipoval bych, že tady jsem to rozbil**
- [x] htab_hash_function.c
- [x] htab_init.c
- [x] htab_lookup_add.c
- [ ] htab_move.c
- [x] htab_size.c
- [x] htab_struct.h

### MAKEFILE
- [x] makefile pro tail
- [x] makefile pro wordcount
- [x] makefile pro htab
- [x] makefile pro io