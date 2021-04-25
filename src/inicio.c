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
// Tiempo que durara el copilador parado.
const short time = 2;

int votar_options()
{
    int decission = 0;

    fflush(stdout);
    system("cls||clear");

    printf("Empezando sistema de carga...\n");
    system_loading(time);
    /**+-+-+-+-+-+-Empieza votar+-+-+-+-+-+- */

    printf("\n\t\tSitema de votacion RD 2021\n"
           "\n\tBienvenido!"
           "\n\n\t\tAqui puede ejercer su derecho al voto =)"
           "\n\n Desea confirmar su colegio Electoral antes? 1/0: \n");
    while ((decission = getchar()) != '\n' || (decission = getchar()) != '\r')
        if (decission == '1')
            return /*colegios_electorales*/;
        else
            /*registrar_su_voto*/;
}

int print_start_menu()
{
    unsigned options = 0;

    fflush(stdout);
    system("cls||clear");

    // Para que no se sienta la espera.
    printf("Empezando sistema de carga...\n");
    system_loading(time);

    /**+-+-+-+-+-+-Empieza el menu+-+-+-+-+-+- */

    for (size_t i = 3; i > 0 || options > 6; --i)
    {
        system("cls||clear");

        if ((options <= 0 && i != 3) || options > 6)
            printf("Heyyy, debes eligir una opcion correcta!!!\n"
                   "Porque, pues te quedan %zu intentos.\n",
                   i);

        printf("\n\tBienvenido al Sistema de Votacion RD  \n"
               "\n\t\t Que deseas hacer?\n"
               "\n\t1- Votar\n"
               "\t2- Ver si puedo votar   \n"
               "\t3- Candidato con mas votos     \n"
               "\t4- Candidato con menos votos\n"
               "\t5- Ver mi colegio electoral\n"
               "\t6- Salir del sistema \n"); // El usuario saldra cuando presione 6.
        scanf("%d", &options);
        getchar();

        if (options >= VOTE && options <= EXIT)
            break;
    }

    switch (options)
    {
    case VOTE:
        return votar_options();
    case ELEGIBLE_TO_VOTE:
        return 
    case CANDIDATE_WITH_MOST_VOTES:
        return; 

    case CANDIDATE_WITH_LESS_VOTES:
        return; 

    case CONFIRM_COLEGIO_ELECTORAL:
        return colegios_disponibles();

    case EXIT:
        fflush(stdout);
        system("cls||clear");
        printf("Gracias por ingresar a este programa!\n");
        exit(0);
    default:
        fprintf(stderr, "Verifica que hayas ingresadouna opcion correcta o "
                        "envia un issue detallando el posible bug.\n");
        break;
    }
    putchar('\n');
    return 0;
}

void system_loading(int time)
{
#ifdef __WIN32
    time += time * 1000;
#endif //__WIN32

    for (size_t i = 0; i <= 100; i++)
    {
        if (i % 25 == 0)
        {
            fflush(stdout);
            printf("Su proceso esta %zu%% completado.\r", i);
        }
        else
            continue;

        if (i == 100)
        {
            fflush(stdout);
            system("cls||clear");
        };
#ifdef __WIN32
        Sleep(time);
#else
        sleep(time);
#endif //__WIN32
    }
}

void clear_screen()
{
    fflush(stdout);
    system("cls||clear");
}