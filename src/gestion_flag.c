/*
** EPITECH PROJECT, 2022
** DEV_ANALYTICS
** File description: LOUIS LEJAILLE
** gestion_flag
*/

#include "../use/my.h"

void usage_flag_view_list(index_t *index)
{
    system("clear");
    open_tab(index);
    if (index->tab_article[0] == '\0') {
        if (index->language == 1) {
            printf("la liste est vide\n");
            exit(0);
        }
        if (index->language == 2) {
            printf("list is empty\n");
            exit(0);
        }
    }
    if (index->language == 1) {
        printf("Vue de la liste d'article:\n\n");
    }
    if (index->language == 2) {
        printf("View of list article:\n\n");
    }
    printf("%s\n", index->tab_article);
    exit(0);
}

void usage_flag_clear(index_t *index)
{
    char *filepath = "use/tab_vente.txt";
    FILE* output_file = fopen(filepath, "w+");
    if (!output_file) {
        perror("fopen");
        exit(84);
    }
    fwrite("\0", 1, 1, output_file);
    if (index->language == 1) {
        printf("la liste est vide !\n");
    }
    if (index->language == 2) {
        printf("List is empty !\n");
    }
    exit(0);
}

void usage_flag_language_fr(index_t *index)
{
    char *filepath = "use/language.txt";
    FILE* output_file = fopen(filepath, "w+");
    if (!output_file) {
        perror("fopen");
        exit(84);
    }
    fwrite("1", 1, 1, output_file);
}

void usage_flag_language_an(index_t *index)
{
    char *filepath = "use/language.txt";
    FILE* output_file = fopen(filepath, "w+");
    if (!output_file) {
        perror("fopen");
        exit(84);
    }
    fwrite("2", 1, 1, output_file);
}