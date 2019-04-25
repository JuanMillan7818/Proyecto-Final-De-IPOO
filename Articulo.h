/**
* @file Articulo.h
* @date 01/01/2019
* @title clase articulo
* @brief clase articulo para definir articulos que tenga una herencia de este tipo
* @code
* class Articulo {
*  protected :
*      string IDnombre;
*  public :
*      void setIDnombre;
*      string getIDnombre;
*
*  string Articulo::getIDNombre() {
*  return this->IDNombre ;
* @endcode
*/

#ifndef ARTICULO_H_
#define ARTICULO_H_
#include <iostream>
#include <string>
#include "common.h"
#include "Fecha.h"

using namespace std ; 

class Articulo  {
	protected :
		string IDNombre ; /** @brief en este campo IDNombre toma el valor string */
		int CodigoArticulo ; /** @brief en este campo CodigoArticulo toma el valor int */
		float ValorArticulo ; /** @brief en este campo ValorArticulo toma el valor float  */
		float ValorActualArticulo ; /** @brief en este campo ValorActualArticulo toma el valor float  */ 
		bool EstadoArticuloDeActivo ; /** @brief en en este campo EstadoArticuloDeActivo toma el valor bool  */
		bool EstadoDeLimiteDeArticulos ; /** @brief en esta campo EstadoDeLimiteDeArticulos toma el valor bool  */
		bool EstadoDeAsignadoAProfesor ; /** @biref en este campo EstadoDeAsignadoProfesor */
		
		// Fecha De Registro
		Fecha* FechaDeRegistro ; /** @brief  Objeto de tipo Fecha que permite determinar en que fecha se crea un articulo */
		
	public :
		/** 
		*@brief constructor de articulo sin parametros y sin dato de retorno
		*/
		Articulo () ;

		/**
		*@brief constructor de articulo  con parametros y dato de retorno
		*/
		Articulo (string IDNombre, int CodigoArticulo, int ValorArticuloInicial, int ValorActualArticulo, 
				  bool EstadoArticulo, bool EstadoDeLimiteDeArticulos, bool EstadoDeAsignadoAProfesor) ;
		
		/**
		*@brief asignar valores a un objeto articulo  (agrega un IDnombre)
		*/
		void setIDNombre (string IDNombre) ;
		
		/**
		*@brief asignar Codigo único a un objeto articulo ( Agrega un CodigoArticulo)
		*/
		void setCodigoArticulo (int CodigoArticulo) ;
		
		/**
		*@brief asignar valor de precio a un objeto articulo ( Agrega un ValorArticuloInicial)
		*/
		void setValorArticuloInicial (float ValorArticuloInicial) ;
		
		/**
		*@brief asignar valor actual a un objeto articulo ( Agrega un VAlorActualArticulo)
		*/
		void setValorActualArticulo (float ValorActualArticulo) ;
		
		/**
		*@brief asignar estado de actividad a un objeto articulo ( Agrega un EstadoArticulo)
		*/
		void setEstadoArticuloDeActivo (bool EstadoArticulo) ;
		
		/**
		*@brief asignar estado de cantidad excedida a un objeto articulo ( Agrega un EstadoDeLimiteDeArticulos)
		*/
		void setEstadoDeLimiteDeArticulos (bool EstadoDeLimiteDeArticulos) ;
		
		/**
		*@brief asignar estado de asignacion por parte de un profesor a un objeto articulo ( Agrega un EstadoDeAsignadoAProfesor)
		*/
		void setEstadoDeAsignadoAProfesor (bool EstadoDeAsignadoAProfesor) ;
		
		/**
		*@brief lee el nombre de un objeto articulo (getIDNombre)
		*/
		string getIDNombre () ;
		
		/**
		*@brief lee el codigo único de un objeto articulo ( getCodigoArticulo)
		*/
		int getCodigoArticulo () ;
		
		/**
		*@brief lee valor incial de un objeto articulo ( getArticuloInicial)
		*/
		float getValorArticuloInicial () ;
		
		/**
		*@brief lee el valor actual de un objeto articulo ( getValorActualArticulo)
		*/
		float getValorActualArticulo () ;
		
		/**
		*@brief lee el estado actual de un objeto articulo ( getEstadoArticuloDeActivo)
		*/
		bool getEstadoArticuloDeActivo () ;
		
		/**
		*@brief lee el estado actual de cantidad disponible de un objeto articulo ( getEstadoDeLimiteDeArticulos)
		*/
		bool getEstadoDeLimiteDeArticulos () ;
		
		/**
		*@brief lee el estado de asignacion a un profesor de un objeto articulo ( getEstadoDeAsigandoAProfesor )
		*/
		bool getEstadoDeAsignadoAProfesor () ;
		
		/**
		* @brief lee una direccion que tiene un objeto de tipo Fecha para indicar la Fecha de registro de un objeto articulo (getFecha)
		*/
		Fecha* getFecha () ; 
		
		/**
		* @brief Asigna el valor de un objeto de tipo Fecha a la Fecha registrada del un objeto articulo (AsignarFecha)
		*/
		void AsignarFecha (Fecha* FechaArticulo) ;
		
		/**
       		* @brief Una funcion virutal pura que obliga a sus hijos a implementarla, porque cuando la hereda y no la implementa tambien esta se convierte en una clase pura y dicha clase no permite crear objetos de ese tipo 
       		* @see Despreciacion
       		* @param Cuenta con dos parametros de entrada; Uno que hace referencia a la Fecha actual del programa y la otra a la Feca en que se registro el articulo
       		*/
		virtual bool Despreciacion (Fecha* Actual, Fecha* FechaArticulo) = 0 ;
		
		/** 
		*@brief destructor de articulo sin parametros y sin datos de retorno
		*/
		~Articulo () ; 
};
#endif
