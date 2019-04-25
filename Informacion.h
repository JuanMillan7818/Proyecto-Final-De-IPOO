/**
* @file Informacion.h
* @date 4/13/2019
* @title clase Informacion
* @brief clase Informacion para definir articulos que tenga una herencia de este tipo
* @code
* class Informacion {
*  private :
*      string NombreDeInfo;
*  public :
*      void setNombreDeInfo;
*      string getNombreDeInfo;
*
* @endcode
*/


#ifndef INFORMACION_H_
#define INFORMACION_H_
#include <iostream>
#include <string> 


using namespace std ;

class Informacion {
	private :
		string NombreDeInfo ; /** @brief en este campo NombreDeInfo toma el valor string */
		string ContenidoDeInfo ; /** @brief en este campo ContenidoDeInfo toma el valor string */
		
	public :	
		/** 
		*@brief Constructor de Inforamcion sin parametros y sin dato de retorno
		*/
		Informacion () ;

		/**
		*@brief Constructor de Informacion  con parametros y todos los datos posible de un objeto Informacion
		*/
		
		Informacion (string NombreDeInfo, string ContenidoDeInfo) ;
		/**
		*@brief Asigna el nombre o campo a un objeto Informacion ( Agrega un setNombreDeInfo)
		*/
		void setNombreDeInfo (string NombreDeInfo) ;

		/**
		*@brief Asigna el contenido del campo de un objeto Informacion ( Agrega un setContenidoDeInfo)
		*/
		void setContenidoDeInfo (string ContenidoDeInfo) ;

		/**
		*@brief Lee el nombre o campo de un objeto Informacion (getNombreDeInfo)
		*/
		string getNombreDeInfo () ;

		/**
		*@brief Lee el contenido de un campo de un objeto Informacion (getContenidoDeInfo)
		*/
		string getContenidoDeInfo () ;

		/**
		*@brief Crea datos iniciales o fijos del Laboratorio (DatosIniciales)
		*/
		void DatosIniciales (Informacion* InfoInicial, int NroAuxiliar) ;

		/**
		*@brief Crea datos de un objeto Informacion (CrearInformacionLabotatorio)
		*/
		void CrearInformacionLabotatorio (Informacion* InformacionParaCrear) ;

		/**
		*@brief Destructor de un objeto Informacion sin dato de retorno
		*/				
		~Informacion () ;
};
#endif
