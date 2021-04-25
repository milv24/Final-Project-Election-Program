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
// Tiempo que durara el copilador parado.
#define time 2

//TODO quiero hacer que imprima cuantas personas votaron por este candidato
//TODO como puedo guardar los votos 
/**
 * @brief Con esta funcion se elegiran los candidatos
 * Se ira sumando un contador para cada candidato por cada voto por ellos
 * @return int 
 */
int select_your_candidate()
{

}
/**
 * @brief Aqui se va amostrar el candidato con menos votos por el momento
 * y va a imprimir la cantidad de votos que obtuvo
 */
void candidate_looser()
{
    printf("\n \t\t%s es el candidato con menos votos hasta el momento\n"
    "\t\tPor lo que va perdiendo =(\n"
    "\n\t\t\t\t\t\t %d personas votaron por este candidato!");
}
/**
 * @brief Aqui se va a imprimir quien es el candidato con mas votos
 * y cuantos votos obtuvo
 */
void candidate_winner()
{
     printf("\n \t\t%s es el candidato con mas votos hasta el momento\n"
    "\t\tPor lo que va ganando =) !!!!!\n"
    "\n\t\t\t\t\t\t %d personas votaron por este candidato!");
}