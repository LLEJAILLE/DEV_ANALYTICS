/*
** EPITECH PROJECT, 2022
** DEV_ANALYTICS
** File description: LOUIS LEJAILLE
** open_file
*/

#include "../use/my.h"

void open_language(index_t *index)
{
    index->langue = NULL;
    int fd = open("use/language.txt", O_RDONLY);
    struct stat sb;
    fstat(fd, &sb);
    index->langue = malloc(sizeof(char) * sb.st_size + 1);
    read(fd, index->langue, sb.st_size);
    index->langue[sb.st_size] = '\0';
    close(fd);
    index->language = atoi(index->langue);
}

void open_tab(index_t *index)
{
    index->tab_article = NULL;
    int fd = open("use/tab_vente.txt", O_RDONLY);
    struct stat sb;
    fstat(fd, &sb);
    index->tab_article = malloc(sizeof(char) * sb.st_size + 1);
    read(fd, index->tab_article, sb.st_size);
    index->tab_article[sb.st_size] = '\0';
    close(fd);
}

void open_help(index_t *index)
{
    index->file = NULL;
    int fd = open("use/help_option.txt", O_RDONLY);
    struct stat sb;
    fstat(fd, &sb);
    if (sb.st_size == 0) {
        exit(84);
    }
    index->file = malloc(sizeof(char) * sb.st_size + 1);
    if (fd == -1) {
        exit(84);
    }
    read(fd, index->file, sb.st_size);
    index->file[sb.st_size] = '\0';
    close(fd);
}
