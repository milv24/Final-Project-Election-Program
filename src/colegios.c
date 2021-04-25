/**
 * @file colegios.c
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
#if defined(__WIN32) //Windows detectado
#include <windows.h>
#include <conio.h>
#elif defined(__linux__) //Linux detectado
#include <unistd.h>
#include "../include/getch.h"
#endif
#include "../include/colegios.h"
#include "../include/inicio.h"
//struct colegios_disponibles;
#define time 2
//PUDIERA SOLO IMPRIMIR LOS COLEGIOS YA QUE SIEMPRE SERAN LOS MISMOS?
void colegios_disponibles()
{
    char decission;
    char temp[100];

    clear_screen();

    printf("Empezando sistema de carga...\n");
    system_loading();

    /******************Se imprimen los colegios que se han registrado en el fichero************/
    FILE *c; //c= variable de fichero de colegios
    //Abrimos el fichero
    c = fopen("votantes.txt", "r");
    if (c == NULL)
    {
        printf("No se pudo abrir el archivo. Chequealo\n");
        exit(1);
    }
    while (!feof(c))
    {
        fgets(temp, 100, c); //fgets para leer strings
        printf("%s", temp);
    }
    printf("\n");
    fclose(c);

    while ((decission = getchar()) != '\n' || (decission = getchar()) != '\r')
    {
        if (decission == 'l' || 'L')
        {
            print_start_menu();
        }
        else
        {
            exit(0);
        }
    }
}