all : s21_grep

s21_grep : 	s21_grep.o
	gcc s21_grep.o -o s21_grep
	rm -rf *.o

s21_grep.o: s21_grep.c s21_grep.h
	gcc -std=c11 -c -Wall -Werror -Wextra  s21_grep.c -c 

clean:
	rm -rf *.0 s21_grep

rebuild: make clean
	make all
