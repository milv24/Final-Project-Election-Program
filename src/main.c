/************************************************************/
/*           Programacion para mecatronicos                 */
/*  Nombre: Milvia Linette Victorio De la Cruz              */
/*  Matricula: 2020-9598                                    */
/*  Seccion: Miercoles                                      */
/*  Practica: Trabajo Final  "Election System"              */
/*  Fecha: 28/4/2021                                        */
/************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/votantes.h"
#include "../include/inicio.h"

/*La funcion de este programa es registrar a los votantes, con sus datos y guardarlos en un archivo
Sii el votante es menor de edad no le permitira ejercer el voto.
Este programa los datos del usuario en el fichero adjuntado como "votantes.txt"
Los demas datos solo se guardaran en memoria
por lo que no se debe salir sin ver los votos, porque se borraran inmediatamente.
*/


/**
 * @brief Esta es la funcion principal para la ejecucion del programa
 * Te lleva al menu de inicio y de ahi va a llamar a cada funcion de acuerdo a la eleccion
 * 
 * @return int 
 */
int main()
{
	system("color B0"); //cambia el color, el numero cambia el fondo
                        // y la letra cambia el color de letra
                        //Para mas info de estos colores
                        // https://www.geeksforgeeks.org/how-to-print-colored-text-in-c/

	system("cls||clear");

	print_start_menu();

	return 0;
}