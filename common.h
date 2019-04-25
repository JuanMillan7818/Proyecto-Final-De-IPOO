/**
* @file common.h
* @date 01/01/2019
* @title clase common 
* @brief clase common (Para validar los datos ingresados por consola)
* @code ;
* namespace common {
*	
* int ValidarEntero(string Mensaje) ;
* }
* @endcode
*/

#include <iostream>
#include <limits>
#include <string>

using namespace std;

namespace common {
	
	/**
	*@brief Permite Pedir un dato como entrada y validar si existe un fallo para volver a pedir el dato hasta
	*@brief sea valido
	*/
	int ValidarEntero(string Mensaje) ;
	unsigned long Validarlong(string Mensaje) ;
}
