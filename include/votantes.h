#ifndef VOTANTES_H
#define VOTANTES_H

/**
 * @brief Estructura llenar los datos del votante 
 */
 struct Votantes[50]
{
   char name[50];
   char lastname[50];
   unsigned age;
   unsigned ID[11];
   int colegio_electoral;

};

/**
 * @brief Esto va a llenar los datos del votante 
 * 
 */
void votante_register();

/**
 * @brief Esto va a confirmare si con la edad ingresada se puede votar 
 * 
 * @return true 
 * @return false 
 */
bool validate_age();

#endif//VOTANTES_H