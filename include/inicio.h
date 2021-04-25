/**
 * @file inicio.h
 * @author your name (victoriomilvia@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef INICIO_H
#define INICIO_H
#include <stdio.h>
#include <string.h>
//TODO: Inicio lo que hara es imprimir el inicio menu y luego tambien enviar a cada uno a su opcion deseada

enum menu_option
{
    VOTE = 1,
    ELEGIBLE_TO_VOTE,
    CANDIDATE_WITH_MOST_VOTES,
    CANDIDATE_WITH_LESS_VOTES,
    CONFIRM_COLEGIO_ELECTORAL,
    EXIT
};

/**
 * @brief Esta funcion lo que hace es imprimir la cara de la opcion VOTE
 * para que el usuario elija si quiere ver su colegio electoral  antes
 * de proceder a la votacion. 
 * @return int 
 */
int votar_options();

/**
 * @brief Esta funcion va a imprimir el menu de entrada para el sistema de votacion 
 * y llevara al usuario a la opcion que desea.
 * Esto es lo que aparecera inmediatamente se ejecute el programa .
 */
int print_start_menu();

/**
 * @brief Mostrara que el sistema esta trabajando 
 * 
 */
void system_loading(void);

/**
 * @brief Limpiara la pantalla
 * 
 */
void clear_screen();



#endif //INICIO_H
