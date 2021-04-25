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
#define MAX_VOTANTES 100

//Estructura que almacena los datos de los votantes
votantes Votantes[MAX_VOTANTES];

//Variables a utilizar en el que estaran los datos pedidos
char nombre[50], apellido[50];
unsigned id, edad, colegio;

void votante_register()
{
    FILE *v;
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
            scanf("%s", &nombre); //leera el nombre y lo guardara en la variable
            getchar();
            strcpy(Votantes[i].name, nombre) //copiara la variable antes pedida y la guardara en la estructura
                printf("\nApellido(primer):");
            scanf("%s", , &apellido);
            getchar();
            strcpy(Votantes[i].lastname, apellido)
                printf("\nNumero de Identificacion(11digitos):)");
            scanf("%u", &id);
            getchar();
            validate_id();
            strcpy(Votantes[i].ID, id)
                printf("\nEdad(+18):");
            scanf("%u", &edad);
            getchar();
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
            strcpy(Votantes[i].age, edad)
                printf("\nColegio Electoral");
            scanf("%d", &colegio);
            getchar();
            strcpy(Votantes[i].colegio_electoral, colegio);
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
    return 0;
}