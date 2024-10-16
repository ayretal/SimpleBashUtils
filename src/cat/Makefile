all : s21_cat

s21_cat : s21_cat.o
	gcc s21_cat.o -o s21_cat
	rm -rf *.o

s21_cat.o: s21_cat.c s21_cat.h
	gcc -std=c11 -c -Wall -Werror -Wextra  s21_cat.c -c 

clean:
	rm -rf *.0 s21_cat

rebuild: make clean
	make all