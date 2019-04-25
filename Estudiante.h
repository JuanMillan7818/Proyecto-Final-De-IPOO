/**
* @file Estudiante.h
* @date 01/01/2019
* @title clase Estudiante 
* @brief clase Estudiante para definir Estudiane con datos propios de este y lo que tenga herencia de Persona
* @code
* class Estudiante {
*  protected :
*   	string Carrera ;  
*  public :
*	void setCarrera (string Carrera) ;
*	void setCodigo (int Codigo) ;
*
*  void Estudiante::setCarrera(string Carrera) {
*	this->Carrera = Carrera ;
* @endcode
*/


#ifndef ESTUDIANTE_H_
#define ESTUDIANTE_H_
#include <iostream>
#include <vector>
#include "Persona.h"
#include "ArticuloDePrestamo.h"


class Estudiante : public Persona {
	private :
		string Carrera ; /** @brief en este campo Carrera toma el valor string */
		int Codigo ; /** @brief en este campo Codigo toma el valor int */
 		int Semestre ; /** @brief en este campo Semestre toma el valor int */
		int ValorMultaAcomulada ; /** @brief en este campo ValorMultaAcomulada toma el valor int */
		bool EstadoDeMulta ; /** @brief en este campo EstadoDeMulta toma el valor bool */
		bool EstadoDeEstudiante ; /** @brief en este campo EstadoDeMultaEstudiante toma el valor boll */
		
		// Articulos prestamos Por estudiante
		vector <ArticuloDePrestamo*> ArticulosPrestados ; /** @brief vector que almacena los articulos prestados por el estudiante */	 

	public :
		/** 
		*@brief constructor de Estudiante sin parametros y sin dato de retorno
		*/
		Estudiante () ;

		/** 
		*@brief Constructor de Estudiante con parametros y todos lo datos posibles de un estudiante
		*/
		Estudiante (string Nombre, string Apellido, string Email, int Edad, long Cedula, int Telefono,		
				string Carrera, int Codigo, int Semestre, int ValorMultaAcomulada, bool EstadoDeMulta, bool EstadoDeEstudiante) ;					

		/**
		*@brief Asigna la carrera a un objeto Estudiante (setCarrera)
		*/
		void setCarrera (string Carrera) ;

		/**
		*@brief Asigna el codigo único a un objeto Estudiante  (setCodigo)
		*/
		void setCodigo (int Codigo) ;

		/**
		*@brief Asigna el semestre a un objeto Estudiante  (setSemestre)
		*/
		void setSemestre (int Semestre) ;

		/**
		*@brief Asigna en valor de multa por demora de entrega de un articulo prestado de un objeto Estudiante (CorrerValorMulta)
		*/
		void CorrerValorMulta (int ValorMultaAcomulada) ;

		/**
		*@brief Asigna un estado de multa por si tiene o no multa un objeto Estudiante (setEstadoDeMulta)
		*/
		void setEstadoDeMulta (bool EstadoDeMulta) ;

		/**
		*@brief Asigna un estado de si el Estudiante esta habilitadoa prestar un objeto de prestamo  (setEstadoDeEstudiante)
		*/
		void setEstadoDeEstudiante (bool EstadoDeEstudiante) ;

		/**
		*@brief Asigan una direccion que apunta a un objeto de tipo ArticuloDePrestamo para almacenarlos en el vector de prestmaos de un objeto Estudiante (ArticuloParaPrestar)
		*/
		void ArticuloParaPrestar (ArticuloDePrestamo* Articulo) ;

		/**
		*@brief Lee la carrera de un objeto Estudiante (getCarrera)
		*/
		string getCarrera () ;

		/**
		*@brief Lee el codigo de un objeto Estudiante (getCodigo)
		*/
		int getCodigo () ;

		/**
		*@brief Lee el semestre de un objeto Estudiante (getSemestre)
		*/
		int getSemestre ()  ;

		/**
		*@brief Lee el valor de multa de un objeto Estudiante (getValorMultaAcomulada)
		*/
		int getValorMultaAcomulada () ;

		/**
		*@brief Lee estado de multa de un objeto Estudiante (getEstadoDeMulta)
		*/
		bool getEstadoDeMulta () ;

		/**
		*@brief Lee el estado de habilitado de un objeto Estudiante (getEstadoDeEstudiante)
		*/
		bool getEstadoDeEstudiante () ;

		/**
		*@brief Lee la direcciones que apuntan a objetos de tipo ArticuloDePrestam para ve todos los prestados de un objeto Estudiante (MisArticulos MisArticulos)
		*/
		vector <ArticuloDePrestamo*> MisArticulos () ;

		/**
		*@brief Muestra todos los articulos prestados por un objeto Estudiante (MostrarTodosLosArticulos)
		*/		
		void MostrarTodosLosArticulos () ;

		/**
		*@brief Crea un objeto Estudiante (CrearDatosDeObjetoEstudiante)
		*/
		void CrearDatosDeObjetoEstudiante (Estudiante* EstudianteParaCrear) ;

		/**
		*@brief Generar devolucion de un articulo prestado por un objeto Estudiante (Devolucion)
		*/
		void Devolucion (int Posicion) ;

		/**
		*@brief Destructor de un objeto Estudiante sin dato de retorno
		*/
		~Estudiante () ;
};
#endif
