/**
* @file Persona.h
* @date 01/01/2019
* @title clase Persona
* @brief clase Persona, Esta es una clase base con las que otras clases heradaran de este para poder manejar estos datos
* @code
* class Persona {
*  private :
*    string Nombre ;
*  public :
*      void setNombre() ;
*
*	void Persona::setNombre(string Nombre) {
*		this->Nombre = Nombre
*
*  
* @endcode
*/



#ifndef PERSONA_H_
#define PERSONA_H_
#include <iostream>
#include <string>
#include "common.h" 
#include <limits>

using namespace std ;

class Persona {
	protected :
		string Nombre ; /** @brief Variable que almacenara el Nombre de un objeto Persona */
		string Apellido ; /** @brief Variable que almacenara el Apellido de un objeto Persona */
		string Email ; /** @brief Variable que almacenara el Email de un objeto Persona */
		int Edad ; /** @brief Variable que almacenara la Edad de un objeto Persona */
		long Cedula ; /** @brief Variable que almacenara la Cedula de un objeto Persona */
		unsigned long Telefono ; /** @brief Variable que almacenara el el Telefono de un objeto Persona */
		
	
	public :
		/** 
		*@brief Constructor de Persona sin parametros y sin dato de retorno
		*/
		Persona () ;

		/**
		*@brief Constructor de Persona  con parametros y datos necesarios de un objeto Persona sin dato de retorno
		*/
		Persona (string Nombre, string Apellido, string Email, int Edad, int Cedula, long Telefono) ;

		/**
		*@brief Asigna un Nombre a un objeto Persona (agrega un Nombre)
		*/
		void setNombre (string Nombre) ;

		/**
		*@brief Asigna un Apellido a un objeto Persona  (agrega un Apellido)
		*/
		void setApellido (string Apellido) ;

		/**
		*@brief Asigna un Email a un objeto Persona  (agrega un Email)
		*/
		void setEmail (string Email) ;
	
		/**
		*@brief Asigna una Edad a un objeto Persona  (agrega una Edad)
		*/
		void setEdad (int Edad) ;
	
		/**
		*@brief Asigna un numero de Cedula a un objeto Persona  (agrega una Cedula)
		*/
		void setCedula (long Cedula) ; 

		/**
		*@brief Asigna un numero de Telefono a un objeto Persona  (agrega un Telefono)
		*/
		void setTelefono (unsigned long Telefono) ; 

		/**
		*@brief Lee el Nombre asignado de un objeto Persona ( getNombre)
		*/
		string getNombre () ;

		/**
		*@brief Lee el Apellido asignado de un objeto Persona ( getApellido)
		*/
		string getApellido () ;

		/**
		*@brief Lee el Email asignado de un objeto Persona ( getEmail)
		*/
		string getEmail () ;

		/**
		*@brief Lee la Edad asignada de un objeto Persona ( getEdad)
		*/
		int getEdad () ;

		/**
		*@brief Lee la Cedula asignada de un objeto Persona ( getCedula)
		*/
		long getCedula () ;

		/**
		*@brief Lee el Telefono asignado de un objeto Persona ( getTlefono)
		*/
		unsigned long getTelefono () ;

		/**
		*@brief Destructor de un objeto Persona sin dato de retorno
		*/
		~Persona () ;
};
#endif
