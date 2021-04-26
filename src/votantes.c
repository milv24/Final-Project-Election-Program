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
#define CANDIDATE5 "Carmen De Leon"
#define CANDIDATE6 "Manolo Baez"
#define CANDIDATE0 "Voto en blanco"
#define MAX_VOTANTES 100

//Estructura que almacena los datos de los votantes
votantes Votantes[MAX_VOTANTES];

//Variables a utilizar en el que estaran los datos pedidos
char nombre[50], apellido[50];
unsigned id, edad, colegio;



votantes Votantes[MAX_VOTANTES];
//Variables para contar, guardar e ir aumentando los votos de cada candidato
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

/**
 * @brief Esta funcion va a recoger los datos del votante y guardarla en la estructura de datos
 * 
 */
void votante_register()
{
    FILE *v;//Nombre del fichero
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
            /**
             * @brief Aqui se va a imprimir los datos que se necesitan 
             * para llenar las estructuras y luego pasarlas al fichero
             * "votantes.txt"
             */
            printf("\n\t\t\tIntroduzca sus datos para registrar su voto exitosamente"
                   "\nNombre(primer):");
            fgets(nombre, sizeof(nombre), stdin); //leera el nombre y lo guardara en la variable
            nombre[strlen(nombre) - 1] = '\0';
            strcpy(Votantes[i].name, nombre); //copiara la variable antes pedida y la guardara en la estructura

            printf("\nApellido(primer):");
            fgets(apellido, sizeof(apellido), stdin);
            apellido[strlen(apellido) - 1] = '\0';
            strcpy(Votantes[i].lastname, apellido);

            printf("\nNumero de Identificacion(11digitos):)");
            scanf("%u", &id);
            getchar();
            validate_id();
            Votantes[i].ID = id;

            printf("\nEdad(+18):");
            scanf("%u", &edad);
            getchar();
            Votantes[i].age = edad;
            /**
             * @brief Si es menor de 18 no lo dejara votar
             * 
             */
            if (edad < 18)
            {
                printf("Usted no esta apto para votar aun =(");
                system("pause");
                exit(0);
            }
            Votantes[i].age = edad;
            printf("\nColegio Electoral");
            scanf("%d", &colegio);
            getchar();
            Votantes[i].colegio_electoral = colegio;
            if (colegio >= 6)
            {
                //Como solo hay 5 colegios, si presiona 6 lo saca del sistema
                printf("\nUps no existe este colegio!\n");
            }
        }
        //datos que se van a pasar al fichero
        fprintf(v, "%s|\t%s|\t%u|\t%u|\t%d|\n", nombre, apellido, id, edad, colegio);
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
 * 
 */
void validate_id()
{
    for (size_t i = 0; i < MAX_VOTANTES; i++)
    {
        if (id == Votantes[i].ID)
        {
            printf("Usted ya ha ejercido su derecho al voto!"
                   "Presione cualquier tecla para salir");
            getch();
        }
    }
}
//PUDIERA SOLO IMPRIMIR LOS COLEGIOS YA QUE SIEMPRE SERAN LOS MISMOS?
/**
 * @brief Esta funcion lo que hara es mostrar los colegios que existen
 * solo para que las personas confirmen a que colegio pertenecen
 * 
 */
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