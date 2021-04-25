/**
 * @file candidatos.h
 * @author your name (victoriomilvia@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CANDIDATOS
#define CANDIDATOS
#include <stdio.h>
#include <string.h>
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
};

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
#endif //CANDIDATOS