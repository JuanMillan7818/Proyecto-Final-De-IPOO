/**
* @file Profesor.h
* @date 01/01/2019
* @title clase Profesor 
* @brief clase Profesor, clase esencial para el Laboratorio que permitira el buen funcionamiento del Laboratorio
* @code
* class Profesor : Persona {
*  private :
*    int Codigo ;
*  public :
*      void setCodigo() ;
*
*	void Profesor::setCodigo(int Codigo) {
*		this->Codigo = Codigo
*
*  
* @endcode
*/


#ifndef PROFESOR_H_
#define PROFESOR_H_
#include <iostream>
#include "Persona.h"

using namespace std ;

class Profesor : public Persona {
	private :
		int Codigo ; /** @brief Variable que almacenara la el Codigo único de un objeto Profesor */
		string TituloProfesional ; /** @brief Variable que almacenara la el Titulo Profesional de un objeto Profesor */
		
	public :
		/** 
		*@brief Constructor de Profesor sin parametros y sin dato de retorno
		*/
		Profesor () ;

		/** 
		*@brief Constructor de Profesor con parametros y con los datos necesarios para un Profesor
		*/
		Profesor (string Nombre, string Apellido, string Email, int Edad,
				  long Cedula, int Telefono, int Codigo, string TituloProfesional) ;

		/**
		*@brief Asigna un numero de Codigo a un objeto Profesor  (agrega un Codigo)
		*/
		void setCodigo (int Codigo) ;

		/**
		*@brief Asigna el Titulo Profesional a un objeto Profesor  (agrega un TituloProfesional)
		*/
		void setTituloProfesional (string TituloProfesional) ;

		/**
		*@brief Lee el numero de Codigo de un objeto Profesor (getCodigo)
		*/
		int getCodigo () ;

		/**
		*@brief Lee el Titulo Profesional de un objeto Profesor (getTituloProfesional)
		*/
		string getTituloProfesional () ;

		/**
		*@brief Metodo para crear objetos de tipo Profesor
		*/
		void CrearDatosDeProfesor (Profesor* Profesor) ;	

		/**
		*@brief Destructor de un objeto de tipo Profesor
		*/
		~Profesor () ;
};
#endif 
