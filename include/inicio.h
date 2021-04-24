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
 * @brief Esta funcion va a imprimir el menu de entrada para el sistema de votacion 
 * y llevara al usuario a la opcion que desea
 * Esto es lo que aparecera inmediatamente se ejecute el programa 
 */
int print_start_menu();

/**
 * @brief Mostrara que el sistema esta trabajando 
 * 
 * @param time tiempo que durara el compilador parado
 */
void system_loading(int time);

/**
 * @brief Limpiara la pantalla
 * 
 */
void clear_screen()



#endif //INICIO_H
