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

    //clear the window

        system("clear");

    //call the initialize function

        initialize(index);

    //initialize values outside the structure

        float price = atof(argv[3]);
        float total = 0.0;
        int i = 0;
        int tmp = 0;

    //put the rate with a flag -t (20% default)

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

    //concat the file in a new str (index->final)

        if (index->tab_article != NULL) {
            i = 1;
            strcat(index->final, index->tab_article);
        } else {
            open_tab(index);
            strcat(index->final, index->tab_article);
        }
        for (int i = 0; index->tab_article[i] != '\0'; i++) {
            if (index->tab_article[i] == '$' && index->language == 1) {
                printf("Utilisez [-clear], vous tentez d'ajouter un élément en euro dans une liste comprenant des artcile en dollards!\n");
                exit(84);
            }
            if (index->tab_article[i] == 'E' && index->tab_article[i + 1] == 'u' && index->tab_article[i + 2] == 'r'&&
            index->tab_article[i + 3] == 'o' &&  index->tab_article[i + 4] == 's' && index->language == 2) {
                printf("Use [-clear], You try to add an element in dollard but you've got purchase in euro in you're list!\n");
                exit(84);
            }
        }

    //concat the name of article in a new str (index->strcmp)

        strcat(index->strtmp, argv[2]);

    //create the good space bitween elements and check number of characters in name

        tmp = strlen(index->strtmp);
        if (tmp > 20) {
            if (index->language == 1) {
                printf("Le nom du produit est trop long...(pas plus de 20 lettres)\n");
                return (0);
            }
            if (index->language == 2) {
                printf("The product name is too long...(no more 20 characters)\n");
                return (0);
            }
        }
        if (tmp <= 20) {
            for (tmp; tmp <= 20; tmp++) {
                strcat(index->strtmp, " ");
            }
        }

    //gcvt transform a float in a str

        gcvt(price, 4, index->floatmp);

    //concat for the esthetic aspect (add space and $)

        strcat(index->strtmp, "    ");
        strcat(index->strtmp, index->floatmp);
        if (index->language == 1) {
            strcat(index->strtmp, "Euros");
        }
        if (index->language == 2) {
            strcat(index->strtmp, "$");
        }

        //calcule of the rate 

        total = (price / 100) * index->taux;

        price = price + total;

        gcvt(price, 4, index->pricestr);

        //concat for the esthetic aspect

        strcat(index->strtmp, "     ");
        strcat(index->strtmp, index->pricestr);
        if (index->language == 1) {
            strcat(index->strtmp, "Euros");
        }
        if (index->language == 2) {
            strcat(index->strtmp, "$");
        }


        if (i != 1)
            strcat(index->final, "\n");
        strcat(index->final, index->strtmp);

        strcat(index->final, "     ");

        sprintf(index->strtaux, "%d", index->taux);
        strcat(index->final, index->strtaux);
        char pourcent = '%';
        strncat(index->final, &pourcent, 1);

        //write in the file "tab_vente.txt"

        char *filepath = "use/tab_vente.txt";
        FILE* output_file = fopen(filepath, "w+");
        if (!output_file) {
            perror("fopen");
            exit(84);
        }

        fwrite(index->final, 1, strlen(index->final), output_file);

        //print list

        if (index->language == 1) {
            printf("Le produit à été ajouté !!\n");
            printf("Vue de la liste :\n\n");
            printf("[nom]                     [achat]        [vente]     [taux]\n");
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
