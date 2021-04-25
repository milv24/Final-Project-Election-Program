#ifndef VOTANTES_H
#define VOTANTES_H

//Librerias a usar:
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/**
 * @brief Estructura llenar los datos del votante 
 */
 typedef struct Registro_datos
{
   char name[50];
   char lastname[50];
   unsigned age;
   unsigned ID[11];
   bool colegio_electoral;


}votantes;

/**
 * @brief Esto va a llenar los datos del votante 
 * 
 */
void votante_register();

/**
 * @brief Esto va a confirmare si con la edad ingresada se puede votar 
 * 
 * @return true 
 * @return false 
 */
bool validate_age();

#endif//VOTANTES_H