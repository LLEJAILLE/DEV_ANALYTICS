/*
** EPITECH PROJECT, 2022
** DEV_ANALYTICS
** File description:
** initiation_values
*/

#include "../use/my.h"

void initialize(index_t *index)
{
    index->final = malloc(sizeof(char) * 100000);
    index->floatmp = malloc(sizeof(char) * 100);
    index->strtaux = malloc(sizeof(char) * 100);
    index->pricestr = malloc(sizeof(char) * 100);
    index->strtmp = malloc(sizeof(char) * 100);
    index->taux = 20;
}