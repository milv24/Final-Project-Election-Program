/**
 * @file candidatos.c
 * @author your name (victoriomilvia@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __WIN32
#include <windows.h> /* Windows dectetado. */
#include <conio.h>
#elif __linux__ /* Linux detectado. */
#include "../include/getch.h"
#include <unistd.h>
#endif //__WIN32
#include "../include/candidatos.h"
#include "../include/inicio.h"
#include "../include/votantes.h"
// Tiempo que durara el copilador parado.
#define time 2
#define CANDIDATE1 "Daniela Alvarez"
#define CANDIDATE2 "Aylin Merejo"
#define CANDIDATE3 "Brandy Perez"
#define CANDIDATE4 "Karla Siri"
#define CANDIDATE5 "Carmen De Leon"
#define CANDIDATE6 "Manolo Baez"
#define CANDIDATE0 "Voto en blanco"
#define MAX_VOTANTES 100

votantes Votantes[MAX_VOTANTES];

int votesCount1 = 0, votesCount2 = 0, votesCount3 = 0,
    votesCount4 = 0, votesCount5 = 0, votesCount6 = 0, emptytvotes = 0;
//TODO quiero hacer que imprima cuantas personas votaron por este candidato
//TODO como puedo guardar los votos
/**
 * @brief Con esta funcion se elegiran los candidatos
 * Se ira sumando un contador para cada candidato por cada voto por ellos
 */
void select_your_candidate()
{
    int eleccion;
    int decission;
    clear_screen();

    printf("\n\t\tEleccion de su candidato\n"
           "\n 1. %s \n2. %s \n3. %s \n4. %s \n5. %s \n6. %s \n0. %s",
           CANDIDATE1, CANDIDATE2, CANDIDATE3, CANDIDATE4, CANDIDATE5, CANDIDATE6, CANDIDATE0);
    printf("Solo tiene una oportunidad de votar"
           "Luego de ingresar su voto no se podra eliminar"
           "Elija al candidato de su preferencia de acuerdo a su numero:");
    scanf("%d", &eleccion);
    getchar();

    //Quitar break, hacerla unsigned
    switch (eleccion)//Hacer enum
    {
    case 1:
        votesCount1++;
        break;
    case 2:
        votesCount2++;
        break;
    case 3:
        votesCount3++;
        break;
    case 4:
        votesCount4++;
        break;
    case 5:
        votesCount5++;
        break;
    case 6:
        votesCount6++;
        break;
    case 0:
        emptytvotes++;
        break;
    default:
        printf("\n Error: Escoja una opcion valida!!!!");
        getchar();
        break;
    }
    for (size_t i = 0; i < MAX_VOTANTES; i++)
    {
        printf("Su voto ha sido registrado con exito!"
               "Gracias %s por ejercer su derecho!"
               "Presione 's' para ir al menu principal",
               Votantes[i].name);
        scanf("%d", &decission);
        while ((decission = getchar()) != '\n' || (decission = getchar()) != '\r')
        {
            if (decission == 's')
            {
                print_start_menu();
            }
            else
            {
                exit(0);
            }
        }
    }
}
/**
 * @brief Aqui se va amostrar el candidato con menos votos por el momento
 * y va a imprimir la cantidad de votos que obtuvo
 */
void candidate_looser()
{
    printf("\n \t\t es el candidato con menos votos hasta el momento\n"
           "\t\tPor lo que va perdiendo =(\n"
           "\n\t\t\t\t\t\t personas votaron por este candidato!");
}
/**
 * @brief Aqui se va a imprimir quien es el candidato con mas votos
 * y cuantos votos obtuvo
 */
void candidate_winner()
{
    printf("\n \t\t es el candidato con mas votos hasta el momento\n"
           "\t\tPor lo que va ganando =) !!!!!\n"
           "\n\t\t\t\t\t\t  personas votaron por este candidato!");
}