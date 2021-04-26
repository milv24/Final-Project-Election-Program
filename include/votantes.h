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

/**
 * @brief Esta funcion solo va a imprimir los colegios que el sistema tenga registrados
 */
void colegios_disponibles();

//TODO: Candidatos lo que hara es alamacenara los votos que se le hayan hecho a cada uno
//TODO: Ver si tengo que poner un contador para cada candidato

/**
 * @brief Estructura donde se guardaran los candidatos 
 * y los simbolos o numeros que hay que ejecutar para
 * poder votar por ese candidato
 */
typedef struct candidatos
{
    char nombres[50];
    int num_votacion;
}Candidatos;

/**
 * @brief 
 * 

 */
void select_your_candidate();

/**
 * @brief Esto lo que va a hacer es mostrar el nombre del candidato
 *  que tenga menos votos hasta el momento
 */
void candidate_winner();


/**
 * @brief Esta lo que hara es mostrar el nombre del candidato con menos votos
 * 
 */
void candidate_looser();

#endif//VOTANTES_H