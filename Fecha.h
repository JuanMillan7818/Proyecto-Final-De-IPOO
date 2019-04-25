/**
* @file Fecha.h
* @date 4/13/2019
* @title clase fecha
* @brief clase fecha para definir articulos que tenga una herencia de este tipo
* @code
* class Fecha {
*  private :
*    int Dia ;
*  public :
*      void setDia (int Dia) ;
*      int getDia() ;
*
*  
* @endcode
*/


#ifndef FECHA_H_
#define FECHA_H_
#include <iostream>
#include <stdlib.h>

using namespace std ;

class Fecha {
	private :
		int Dia ; /** @brief en este campo Dia toma el valor int */
		int Mes ; /** @brief en este campo mes toma el valor int */
		int Anio ; /** @brief en este campo Anio toma el valor int */
	
	public :
		/** 
		*@brief Constructor de Fecha sin parametros y sin dato de retorno
		*/
		Fecha () ;

		/**
		*@brief Constructor de Fecha con parametros y todos los datos posibles para crear un objeto Fecha
		*/
		Fecha (int Dia, int Mes, int Anio) ;

		/**
		*@brief Asigna el dia a un objeto Fecha  (agrega un Dia)
		*/
		void setDia (int Dia) ;

		/**
		*@brief Asigna el mes a un objeto Fecha  (agrega un Mes)
		*/
		void setMes (int Mes) ;

		/**
		*@brief Asigna el Anño a un objeto Fecha  (agrega un Anio)
		*/
		void setAnio (int Anio) ;

		/**
		*@brief Lee el dia de un objeto Fecha (getDia)
		*/
		int getDia () ;

		/**
		*@brief Lee el mes de un objeto Fecha (getMes)
		*/
		int getMes () ;

		/**
		*@brief Lee el año de un objeto Fecha (getAnio)
		*/
		int getAnio () ;

		/**
		*@brief Valida si una fecha tiene los datos validos de un objeto Fecha (ValidarFormatoDeFecha)
		*/
		bool ValidarFormatoDeFecha (Fecha* FechaAValidar, Fecha* Actual) ;

		/**
		*@brief Destructor de un objeto Fecha sin dato de retorno
		*/
		~Fecha () ;
};
#endif
