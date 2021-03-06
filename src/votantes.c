/**
 * @file votantes.c
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
#include "../include/inicio.h"
#include "../include/votantes.h"
// Tiempo que durara el copilador parado.
const short time = 2;
#define CANDIDATE1 "Daniela Alvarez"
#define CANDIDATE2 "Aylin Merejo"
#define CANDIDATE3 "Brandy Perez"
#define CANDIDATE4 "Karla Siri"
#define CANDIDATE0 "Voto en blanco"
#define MAX_VOTANTES 100

/**
 * @brief Su voto solo se guardara cuando este dentro del programa, 
 * luego que salga, este voto sera eliminado.
*/

//Estructura que almacena los datos de los votantes
votantes Votantes[MAX_VOTANTES];

//Variables para contar, guardar e ir aumentando los votos de cada candidato
int votesCount1 = 0, votesCount2 = 0, votesCount3 = 0,
    votesCount4 = 0, emptytvotes = 0;

/**
 * @brief Con esta funcion se elegiran los candidatos
 * Se ira sumando un contador para cada candidato por cada voto por ellos
 */
void select_your_candidate()
{
    unsigned eleccion;
    char decission;
    clear_screen();
    printf("Empezando sistema de carga...\n");
    system_loading();

    printf("\n\t\tEleccion de su candidato\n"
           "\n 1. %s \n2. %s \n3. %s \n4. %s  \n0. %s",
           CANDIDATE1, CANDIDATE2, CANDIDATE3, CANDIDATE4, CANDIDATE0);
    printf("\n\t\t\tSolo tiene una oportunidad de votar\n"
           "\nLuego de ingresar su voto no se podra eliminar\n"
           "\nElija al candidato de su preferencia de acuerdo a su numero: \n");
    scanf("%u", &eleccion);
    getchar();

    //Quitar break, hacerla unsigned
    switch (eleccion) //Hacer enum
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
               "Gracias  por ejercer su derecho!"
               "Presione 's' para ir al menu principal  ");
        scanf("%s", &decission);
        getchar();
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
/**
 * @brief Aqui se va amostrar el candidato con menos votos por el momento
 * y va a imprimir la cantidad de votos que obtuvo
 */
void candidate_looser()
{
    clear_screen();
    printf("Empezando sistema de carga...\n");
    system_loading();

    printf("\n \t\t El candidato con menos votos hasta el momento es:\n\n");

    if (votesCount1 < votesCount2 && votesCount1 < votesCount3 &&
        votesCount1 < votesCount4 && votesCount1 < emptytvotes)
    {
        printf("\n\t%s", CANDIDATE1);
        printf("\n\t%d personas votaron por este candidato!", votesCount1);
        printf("\t\tPor lo que va perdiendo =(\n");
    }
    else if (votesCount2 < votesCount3 && votesCount2 < votesCount4 &&
             votesCount2 < votesCount1 && votesCount2 < emptytvotes)
    {
        printf("\n\t%s", CANDIDATE2);
        printf("\n\t%d personas votaron por este candidato!", votesCount2);
        printf("\t\tPor lo que va perdiendo =(\n");
    }
    else if (votesCount3 < votesCount4 && votesCount3 < votesCount2 &&
             votesCount3 < votesCount1 && votesCount3 < emptytvotes)
    {
        printf("\n\t%s", CANDIDATE3);
        printf("\n\t%d personas votaron por este candidato!", votesCount3);
        printf("\t\tPor lo que va perdiendo =(\n");
    }
    else if (votesCount4 < votesCount1 && votesCount4 < votesCount2 &&
             votesCount4 < votesCount3 && votesCount4 < emptytvotes)
    {
        printf("\n\t%s", CANDIDATE4);
        printf("\n\t%d personas votaron por este candidato!", votesCount4);
        printf("\t\tPor lo que va perdiendo =(\n");
    }
    else if (emptytvotes < votesCount1 && emptytvotes < votesCount2 &&
             emptytvotes < votesCount3 && emptytvotes < votesCount4)
    {
        printf("\n\t%s", CANDIDATE0);
        printf("\n\t%d personas votaron por este candidato!", emptytvotes);
        printf("\t\tPor lo que va perdiendo =(\n");
    }
    else
    {
        printf("\n\t\t----- Aun no se ha elegido ningun candidato como perdedor---");
    }
}
/**
 * @brief Aqui se va a imprimir quien es el candidato con mas votos
 * y cuantos votos obtuvo
 */
void candidate_winner()
{
    clear_screen();

    printf("Empezando sistema de carga...\n");
    system_loading();

    printf("\n \t\t El candidato con mas votos hasta el momento es:\n");
    if (votesCount1 > votesCount2 && votesCount1 > votesCount3 && votesCount1 > votesCount4 && votesCount1 > emptytvotes)
    {
        printf("\n\t%s", CANDIDATE1);
        printf("\n\t%d personas votaron por este candidato!", votesCount1);
        printf("\t\tPor lo que va ganando =) !!!!!\n");
    }
    else if (votesCount2 > votesCount3 && votesCount2 > votesCount4 && votesCount2 > votesCount1 && votesCount2 > emptytvotes)
    {
        printf("\n\t%s", CANDIDATE2);
        printf("\n\t%d personas votaron por este candidato!", votesCount2);
        printf("\t\tPor lo que va ganando =) !!!!!\n");
    }
    else if (votesCount3 > votesCount4 && votesCount3 > votesCount2 && votesCount3 > votesCount1 && votesCount3 > emptytvotes)
    {
        printf("\n\t%s", CANDIDATE3);
        printf("\n\t%d personas votaron por este candidato!", votesCount3);
        printf("\t\tPor lo que va ganando =) !!!!!\n");
    }
    else if (votesCount4 > votesCount1 && votesCount4 > votesCount2 && votesCount4 > votesCount3 && votesCount4 > emptytvotes)
    {
        printf("\n\t%s", CANDIDATE4);
        printf("\n\t%d personas votaron por este candidato!", votesCount4);
        printf("\t\tPor lo que va ganando =) !!!!!\n");
    }
    else if (emptytvotes > votesCount1 && emptytvotes > votesCount2 && emptytvotes > votesCount3 && emptytvotes > votesCount4)
    {
        printf("\n\t%s", CANDIDATE0);
        printf("\n\t%d personas votaron por este candidato!", emptytvotes);
        printf("\t\tPor lo que va ganando =) !!!!!\n");
    }
    else
    {
        printf("\n\t\t\t----- Aun no se ha elegido ningun candidato como perdedor---"
               "\n\t\t\tO quizas hay un empate, espere a que voten mas personas por favor");
    }
}

/**
 * @brief Esta funcion va a recoger los datos del votante y guardarla en la estructura de datos
 * Luego la pasara a un fichero
 * 
 */
void votante_register()
{
    clear_screen();
    printf("Empezando sistema de carga...\n");
    system_loading();

    FILE *v;                // Nombre del fichero
    char line[sizeof(int)]; // Donde se guardara a el input recibido con fgets.
    bool llenado = true;    // Para salir del loop luego de haber llenado una
                            // estructura.
                            //Abriremos nuestro fichero

    for (size_t i = 0; i < MAX_VOTANTES && llenado; i++)
    {
        /**
             * @brief Aqui se va a imprimir los datos que se necesitan 
             * para llenar las estructuras y luego pasarlas al fichero
             * "votantes.txt"
             */
        printf("\n\t\t\tIntroduzca sus datos para registrar su voto exitosamente");

        printf("\nNombre(primer): ");
        fgets(Votantes[i].name, sizeof(Votantes[i].name), stdin); //leera el nombre y lo guardara en la variable
        Votantes[i].name[strlen(Votantes[i].name) - 1] = '\0';
        //copiara la variable antes pedida y la guardara en la estructura

        printf("\nApellido(primer): ");
        fgets(Votantes[i].lastname, sizeof(Votantes[i].lastname), stdin);
        Votantes[i].lastname[strlen(Votantes[i].lastname) - 1] = '\0';

        printf("\nNumero de Identificacion( 11 digitos): ");
        scanf("%s", Votantes[i].ID);
        getchar();
       
        printf("\nEdad(+18): ");
        fgets(line, sizeof(line) * 2, stdin);
        sscanf(line, "%u", &Votantes[i].age);

        Votantes[i].has_votado = true; //se va a llenar el voto y no se va a poder repetir la cedula

        //Si es menor de 18 no lo dejara votar
        if (Votantes[i].age >= 18)
        {
            printf("\nColegio Electoral:");
            fgets(line, sizeof(line), stdin);
            sscanf(line, "%hu", &Votantes[i].colegio_electoral);

            if (Votantes[i].colegio_electoral <= 0 || Votantes[i].colegio_electoral > 5)
            { //Como solo hay 5 colegios, si presiona 6 lo saca del sistema
                printf("\nUps no existe este colegio!\n");
                Sleep(200);
                colegios_disponibles();
            }
            v = fopen("votantes.txt", "a");
            if (v == NULL)
            {
                printf("No se pudo abrir el archivo.\n"); //Imprimira si no se pudo abrir el archivo
                exit(1);
            }
            //datos que se van a pasar al fichero
            fprintf(v, "%s|\t%s|\t%s|\t%u|\t%hu|\n", Votantes[i].name,
                    Votantes[i].lastname, Votantes[i].ID, Votantes[i].age,
                    Votantes[i].colegio_electoral);

            fclose(v);
            select_your_candidate(); //Lo va a llevar al lugar de votacion
            llenado = false;
        }
        else
        {
            printf("Usted no esta apto para votar aun =(");
            system("pause");
            exit(0);
        }
    }
}

/**
 * @brief Esta funcion lo que hara sera validar la edad
 * si es mayor de 18 puede votar
 * sino le dara un mensaje y lo sacara del sistema
 * 
 */
void validate_age()
{
    clear_screen();
    for (size_t i = 0; i < MAX_VOTANTES; i++)
    {
        printf("\n\n\t\tPara saber si puedes votar solo tienes que ingresar tu edad para verificarla!"
               "\n\t\tIngresa tu edad:\n");
        scanf("%u", &Votantes[i].age);
        getchar();
        if (Votantes[i].age < 18)
        {
            printf("Usted no es apto para votar, lo sentimos =(");
            system("pause");
            Sleep(200);
            system("cls||clear");
            exit(0);
        }
        else
        {
            printf("Usted esta apto para votar, continue el proceso =)");
            system("pause");
            Sleep(200);
            system("cls||clear");

            print_start_menu();
        }
    }
}
/**
 * @brief Esta funcion lo que hace es que verifica la cedula/id 
 * y revisa si ya esta registrado en la estructura.
 * Si esta registrado, este le dara un mensaje y lo sacara del sistema
 * Debe dejar el programa abierto para que le valide la cedula
 */
void iniciar_vote()
{
    for (size_t i = 0; i < MAX_VOTANTES; i++)
    {
        Votantes[i].has_votado = false;
    }
}

void validate_id(unsigned id)
{
    for (size_t i = 0; i < MAX_VOTANTES; i++)
    {
        if (Votantes[i].has_votado)
        {
            if (Votantes[i].ID)
            {
                printf("\nUsted ya ha votado, no puede volver a votar!!\n");
            }
        }
    }
}

/**
 * @brief Esta funcion lo que hara es mostrar los colegios que existen
 * solo para que las personas confirmen a que colegio pertenecen
 * 
 */
int colegios_disponibles()
{
    char decission;
    char temp[100];

    clear_screen();

    printf("Empezando sistema de carga...\n");
    system_loading();

    /******************Se imprimen los colegios que se han registrado en el fichero************/
    FILE *c; //c= variable de fichero de colegios
    //Abrimos el fichero
    c = fopen("colegios electorales.txt", "r");
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
            getchar();
            votante_register();//Te lleva a registrarte
        }

        else

            print_start_menu();//sino imprime el menu de inicio
    }
}