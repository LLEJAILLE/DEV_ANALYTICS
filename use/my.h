/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include "stdarg.h"
    #include <unistd.h>
    #include <time.h>
    #include <stddef.h>
    #include <string.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/mman.h>

typedef struct index {

char *tab_article;
char *file;
char *newstr;
int size_line;
int size_col;
char **array;
int j_len;
int tmp_len;
int taux;
char *final;
char *strtmp;
char *floatmp;
char *pricestr;
char *strtaux;
int language;
char *langue;
//1 = fra, 2 = ang

}index_t;

void my_printf(char *s, ...);
void my_putchar(char c);
int my_putstr(char *str);
int my_strlen(char const *str);
char *my_revstr(char *str);
int count_line(char *str);
int my_strlenne(index_t *fasta, char const *str);
void usage_flag_view_list(index_t *index);
void usage_flag_clear(index_t *index);
void initialize(index_t *index);
void open_tab(index_t *index);
void open_help(index_t *index);
void open_language(index_t *index);
void usage_flag_language_an(index_t *index);
void usage_flag_language_fr(index_t *index);

#endif /* MY_H_ */
