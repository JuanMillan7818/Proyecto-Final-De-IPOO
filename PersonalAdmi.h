/**
* @file PersonalAdmi.h
* @date 01/01/2019
* @title clase PersonalAdmi
* @brief clase PersonalAdmi, clase que emplea un rol en el manejo de Archivo y en el Laboratorio
* @code
* class PersonalAdmi : Persona {
*  private :
*    string Nombre ;
*  public :
*      void setNombre() ;
*
*	void PersonalAdmi::setNombre(string Nombre) {
*		this->Nombre = Nombre
*
*  
* @endcode
*/



#ifndef PERSONALADMI_H_
#define PERSONALADMI_H_

#include "Persona.h"

using namespace std ;

class PersonalAdmi : public Persona {
	public :
		/** 
		*@brief Constructor de PersonalAdmi sin parametros y sin dato de retorno
		*/
		PersonalAdmi () ;

		/** 
		*@brief Constructor de PersonalAdmi con parametros y con los datos necesarios para un objeto Administrativo
		*/		
		PersonalAdmi (string Nombre, string Apellido, string Email, int Edad, int Cedula, long Telefono) ; 
		
		/** 
		*@brief Metodo que permite crear un objeto de Personal Administrativo
		*/
		void CrearPersonal (PersonalAdmi* Personal) ;
		
		/** 
		*@brief Destructor de un objeto de Personal Administrativo
		*/
		~PersonalAdmi () ;
};
#endif
