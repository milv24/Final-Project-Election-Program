#ifndef COLEGIOS_H
#define COLEGIOS_H
//Librerias a usar:
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/**


typedef struct colegio
{
    char colegio_name[100];
    int street_num;
    int register_num_colegio;

}
colegio_N,colegio_S,colegio_E,colegio_D,colegio_SDQ;


/**
 * @brief Esta funcion solo va a imprimir los colegios que el sistema tenga registrados
 */
void colegios_disponibles();

#endif//COLEGIOS_H