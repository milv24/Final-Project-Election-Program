/**
 * @file votantes.h
 * @author your name (victoriomilvia@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

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
   unsigned ID;
   bool colegio_electoral;


}votantes;


/**
 * @brief 
 * 
 */
void validate_id();

/**
 * @brief Esto va a llenar los datos del votante 
 * 
 */
void votante_register();

/**
 * @brief Esto va a confirmare si con la edad ingresada se puede votar 
 * 
 */
void validate_age();

#endif//VOTANTES_H