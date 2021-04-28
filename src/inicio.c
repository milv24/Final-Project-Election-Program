/**
 * @file inicio.c
 * @author your name (victoriomilvia@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-25
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
#include "../include/inicio.h"

#include "../include/votantes.h"

// Tiempo que durara el copilador parado.
#define time 2


/**
 * @brief Esta funcion va a permitir elegir las opciones 
 * que el usuario quiera realizar 
 * 
 */
void votar_options()
{
    int decission;

    fflush(stdout);
    system("cls||clear");

    printf("Empezando sistema de carga...\n");
    system_loading();
    /**+-+-+-+-+-+-Empieza votar+-+-+-+-+-+- */

    printf("\n\t\tSitema de votacion RD 2021\n"
           "\n\tBienvenido!"
           "\n\n\t\tAqui puede ejercer su derecho al voto =)"
           "\n\n Si desea confirmar su colegio Electoral antes presione 1 \n"
           "\nSi quiere ir a la votacion presione 0 o cualquier otra tecla\n");
    scanf("%d", &decission);
    getchar();

    switch (decission)
    {
    case 1:
        colegios_disponibles();
        break;

    default:
        votante_register();
        break;
    }
}
/**
 * @brief Aqui se imprime el menu de inicio para la ejecucion del programa
 * 
 * @return int 
 */
int print_start_menu()
{
    unsigned options = 0;//variable para opciones a escoger// input

    /**+-+-+-+-+-+-Empieza el menu+-+-+-+-+-+- */

    for (unsigned i = 1; i > 0 || options > 6; --i)
    {
        system("cls||clear");

        printf("\n\tBienvenido al Sistema de Votacion RD  \n"
               "\n\t\t Que deseas hacer?\n"
               "\n\t1- Votar\n"
               "\t2- Ver si puedo votar   \n"
               "\t3- Candidato con mas votos     \n"
               "\t4- Candidato con menos votos\n"
               "\t5- Ver mi colegio electoral\n"
               "\t6- Salir del sistema \n"); // El usuario saldra cuando presione 6.
        scanf("%u", &options);
        getchar();
        if ((options <= 0 && i != 1) || options > 6)
        {
            printf("Heyyy, debes eligir una opcion correcta!!!\n"
                   "Porque, pues te quedan %u intentos.\n",
                   i);
        }
    }

    if (options >= VOTE && options <= EXIT)
    {

        switch (options)
        {
        case VOTE:
            votar_options();
            break;
        case ELEGIBLE_TO_VOTE:
            validate_age();
            break;
        case CANDIDATE_WITH_MOST_VOTES:
            candidate_winner();
            break;

        case CANDIDATE_WITH_LESS_VOTES:
            candidate_looser();
            break;

        case CONFIRM_COLEGIO_ELECTORAL:
            colegios_disponibles();
            break;
        case EXIT:
            fflush(stdout);
            system("cls||clear");
            printf("\n\n\n\n\t\t\tGracias por ingresar a este programa!\n");
            exit(0);
        default:
            fprintf(stderr, "Verifica que hayas ingresado una opcion correcta o "
                            "envia un issue detallando el posible bug.\n");
            break;
        }
    }
    putchar('\n');
    return 0;
}
/**
 * @brief Para que no se sienta el tiempo de ejecucion
 * se emplea esta funcion como metodo de carga
 * 
 */
void system_loading(void)
{
    unsigned temp = 0;
#ifdef __WIN32
    temp = time * 100;
#endif //__WIN32

    for (unsigned i = 0; i <= 100; i++)
    {
        if (i % 25 == 0)
        {
            fflush(stdout);
            printf("Su proceso esta %u%% completado.\r", i);
        }
        else
            continue;

        if (i == 100)
        {
            fflush(stdout);
            system("cls||clear");
        }
#ifdef __WIN32
        Sleep(temp);
#else
        sleep(time);
#endif //__WIN32
    }
}
/**
 * Limpuador de pantalla 
 */
void clear_screen()
{
    fflush(stdout);
    system("cls||clear");
}