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
struct Votantes votantes[MAX_VOTANTES];

void votante_register()
{
    //Variables a utilizar en el que estaran los datos pedidos
    char nombre[50], apellido[50];
    unsigned id, edad, colegio;
    FILE *v;
    //Abriremos nuestro fichero
    v = fopen("votantes.txt", "a");
    if (v == NULL)
    {
        printf("No se pudo abrir el archivo.\n");//Imprimira si no se pudo abrir el archivo
        exit(1);
    }
    else
    
        for (size_t i = 0; i < MAX_VOTANTES; i++)
        {
            /**
             * @brief Aqui se va a imprimir los datos que se necesitan 
             * para llenar las estructuras y luego pasarlas al fichero
             * "votantes.txt"
             */
            printf("\n\t\t\tIntroduzca sus datos para registrar su voto exitosamente"
                   "\nNombre(primer):");
            scanf("%s", &nombre);//leera el nombre y lo guardara en la variable
            getchar();
            strcpy(votantes[i].name,nombre)//copiara la variable antes pedida y la guardara en la estructura
                printf("\nApellido(primer):");
            scanf("%s", , &apellido);
            getchar();
            strcpy(votantes[i].lastname,apellido)
            printf("\nNumero de Identificacion(11digitos):)");
            scanf("%u", &id);
            getchar();
            strcpy(votantes[i].ID,id)
            printf("\nEdad(+18):");
            scanf("%u", &edad);
            getchar();
            strcpy(votantes[i].age,edad)
            printf("\nColegio Electoral");
            scanf("%d", &colegio);
            getchar();
            strcpy(votantes[i].colegio_electoral,colegio)
        }

    
}