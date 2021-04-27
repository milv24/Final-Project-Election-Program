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

//Variables a utilizar en el que estaran los datos pedidos
char nombre[50], apellido[50];
unsigned edad;
unsigned colegio;
int id[11];

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

    if (votesCount1 < votesCount2 && votesCount1 < votesCount3 && votesCount1 < votesCount4 && votesCount1 < emptytvotes)
    {
        printf("\n\t%s", CANDIDATE1);
        printf("\n\t%d personas votaron por este candidato!", votesCount1);
        printf("\t\tPor lo que va perdiendo =(\n");
    }
    else if (votesCount2 < votesCount3 && votesCount2 < votesCount4 && votesCount2 < votesCount1 && votesCount2 < emptytvotes)
    {
        printf("\n\t%s", CANDIDATE2);
        printf("\n\t%d personas votaron por este candidato!", votesCount2);
        printf("\t\tPor lo que va perdiendo =(\n");
    }
    else if (votesCount3 < votesCount4 && votesCount3 < votesCount2 && votesCount3 < votesCount1 && votesCount3 < emptytvotes)
    {
        printf("\n\t%s", CANDIDATE3);
        printf("\n\t%d personas votaron por este candidato!", votesCount3);
        printf("\t\tPor lo que va perdiendo =(\n");
    }
    else if (votesCount4 < votesCount1 && votesCount4 < votesCount2 && votesCount4 < votesCount3 && votesCount4 < emptytvotes)
    {
        printf("\n\t%s", CANDIDATE4);
        printf("\n\t%d personas votaron por este candidato!", votesCount4);
        printf("\t\tPor lo que va perdiendo =(\n");
    }
    else if (emptytvotes < votesCount1 && emptytvotes < votesCount2 && emptytvotes < votesCount3 && emptytvotes < votesCount4)
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

    FILE *v; //Nombre del fichero
    //Abriremos nuestro fichero
    v = fopen("votantes.txt", "a");
    if (v == NULL)
    {
        printf("No se pudo abrir el archivo.\n"); //Imprimira si no se pudo abrir el archivo
        exit(1);
    }
    else
    {
        for (size_t i = 0; i < MAX_VOTANTES; i++)
        {
            char line[sizeof(int)];
                       Votantes[i].has_votado = true; //se va a llenar el voto y no se va a poder repetir la cedula
                                           /**
             * @brief Aqui se va a imprimir los datos que se necesitan 
             * para llenar las estructuras y luego pasarlas al fichero
             * "votantes.txt"
             */
            printf("\n\t\t\tIntroduzca sus datos para registrar su voto exitosamente");

            printf("\nNombre(primer):");
            fgets(nombre, sizeof(nombre), stdin); //leera el nombre y lo guardara en la variable
            nombre[strlen(nombre) - 1] = '\0';
            strcpy(Votantes[i].name, nombre); //copiara la variable antes pedida y la guardara en la estructura

            printf("\nApellido(primer):");
            fgets(apellido, sizeof(apellido), stdin);
            apellido[strlen(apellido) - 1] = '\0';
            strcpy(Votantes[i].lastname, apellido);

            printf("\nNumero de Identificacion( 11 digitos):");
            fgets(line, sizeof(line), stdin);
            sscanf(line, "%d", &id);
            Votantes[i].ID = id;

            printf("\nEdad(+18):");
            fgets(line, sizeof(line), stdin);
            sscanf(line, "%u", &edad);

            //Si es menor de 18 no lo dejara votar
            if (edad < 18)
            {
                printf("Usted no esta apto para votar aun =(");
                system("pause");
                exit(0);
            }
            Votantes[i].age = edad;

            printf("\nColegio Electoral:");
            fgets(line, sizeof(line), stdin);
            sscanf(line, "%u", &colegio);
            if (colegio >= 6)

                //Como solo hay 5 colegios, si presiona 6 lo saca del sistema
                printf("\nUps no existe este colegio!\n");

            Votantes[i].colegio_electoral = colegio;

            //datos que se van a pasar al fichero
            fprintf(v, "%s|\t%s|\t%u|\t%u|\t%u|\n", nombre, apellido, id, edad, colegio);

            fclose(v);
            select_your_candidate(); //Lo va a llevar al lugar de votacion
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

    printf("Para saber si puedesvotar solo tienes que ingresar tu edad para verificarla!"
           "Ingresa tu edad:");
    scanf("%u", &edad);
    getchar();
    if (edad < 18)
    {
        printf("Usted no es apto para votar, lo sentimos =(");
        system("pause");
        Sleep(200);
        system("cls||clear");
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

void validate_id()
{
    for (size_t i = 0; i < MAX_VOTANTES; i++)
    {
        if (!Votantes[i].has_votado)

            if (Votantes[i].ID = id)
            {
                printf("\nUsted ya ha votado, no puede volver a votar!!\n");
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

            votante_register();

        else

            print_start_menu();
    }
}