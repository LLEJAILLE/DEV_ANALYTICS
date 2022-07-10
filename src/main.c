/*
** EPITECH PROJECT, 2022
** DEV_ANALYTICS
** File description: LOUIS LEJAILLE
** main
*/

#include "../use/my.h"

int main(int argc, char **argv)
{
    index_t *index = malloc(sizeof(index_t));
    open_language(index);
    if (argc == 1) {
        usage_flag_view_list(index);
    }

    if (!strcmp(argv[1], "-h")) {
        open_help(index);
        printf("%s\n", index->file);
    }

    if (!strcmp(argv[1], "-clear")) {
        usage_flag_clear(index);
    }

    if (!strcmp(argv[1], "-language") && argv[2] != NULL) {
        if (argv[2][0] == 'f') {
            usage_flag_language_fr(index);
            printf("Vous avez changé la langue en Français !\n");
        }
        if (argv[2][0] == 'a') {
            usage_flag_language_an(index);
            printf("you've been changed the language in English !\n");
        }
        exit (0);
    }

    if (!strcmp(argv[1], "-add") && argc >= 4) {
        system("clear");
        initialize(index);
        float price = atof(argv[3]);
        float total = 0.0;
        int i = 0;
        int tmp = 0;

        for (int i = 0; argv[i] != NULL; i++) {
            if (!strcmp(argv[i], "-t")) {
                if (argv[i + 1] == NULL) {
                    if (index->language == 1) {
                        printf("erreur d'arguments!!\n");
                    }
                    if (index->language == 2) {
                        printf("Error arguments!!\n");
                    }
                } else
                    index->taux = atof(argv[i + 1]);
            }
        }

        if (index->tab_article != NULL) {
            i = 1;
            strcat(index->final, index->tab_article);
        } else {
            open_tab(index);
            strcat(index->final, index->tab_article);
        }

        index->strtmp = malloc(sizeof(char) * 100);

        strcat(index->strtmp, argv[2]);

        tmp = strlen(index->strtmp);

        if (tmp > 20) {
            if (index->language == 1) {
                printf("Le nom du produit est trop long...\n");
                return (0);
            }
            if (index->language == 2) {
                printf("The product name is too long...\n");
                return (0);
            }
        }


        if (tmp <= 20) {
            for (tmp; tmp <= 20; tmp++) {
                strcat(index->strtmp, " ");
            }
        }

        gcvt(price, 4, index->floatmp);

        strcat(index->strtmp, "    ");
        strcat(index->strtmp, index->floatmp);
        strcat(index->strtmp, "$");


        
        total = (price / 100) * index->taux;

        price = price + total;

        gcvt(price, 4, index->pricestr);

        strcat(index->strtmp, "     ");
        strcat(index->strtmp, index->pricestr);
        strcat(index->strtmp, "$");


        if (i != 1)
            strcat(index->final, "\n");
        strcat(index->final, index->strtmp);

        strcat(index->final, "     ");

        sprintf(index->strtaux, "%d", index->taux);
        strcat(index->final, index->strtaux);
        char pourcent = '%';
        strncat(index->final, &pourcent, 1);

        char *filepath = "use/tab_vente.txt";
        FILE* output_file = fopen(filepath, "w+");
        if (!output_file) {
            perror("fopen");
            exit(84);
        }

        fwrite(index->final, 1, strlen(index->final), output_file);

        if (index->language == 1) {
            printf("Le produit à été ajouté !!\n");
            printf("Vue de la liste :\n\n");
            printf("[nom]                   [achat]   [vente]   [taux]\n");
            printf("%s\n\n", index->final);
        }
        if (index->language == 2) {
            printf("Article has been added!!\n");
            printf("View of the list :\n\n");
            printf("[name]                 [purchase]   [sale]   [rate]\n");
            printf("%s\n\n", index->final);
        }

    }
    return (0);
}
