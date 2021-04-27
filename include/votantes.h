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
   bool has_votado;  //para validar el id


}votantes;


/**
 * @brief Esto va a validar que la cedula no se haya repetido
 * 
 */
void validate_id();

/**
 * @brief Esta va a inicializar el voto
 * 
 */
void iniciar_vote();

/**
 * @brief Esto va a llenar los datos del votante 
 * 
 */
void votante_register();

/**
 * @brief Esto va a confirmar si con la edad ingresada se puede votar 
 * 
 */
void validate_age();

/**
 * @brief Esta funcion solo va a imprimir los colegios que el sistema tenga registrados
 */
int colegios_disponibles();

//TODO: Candidatos lo que hara es alamacenara los votos que se le hayan hecho a cada uno
//TODO: Ver si tengo que poner un contador para cada candidato


/**
 * @brief En esta funcion se eligiran los votos y se iran sumando 
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