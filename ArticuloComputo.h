/**
* @file ArticuloComputo.h
* @date 01/01/2019
* @title clase ArticuloComputo
* @brief clase ArticuloComputo para definir articulos que tenga una herencia de este tipo
* @code
* class ArticuloComputo {
*  protected :
*      string IDMarca;
*  public :
*      void setCantidad;
*      string getCantidad;
*
*  void ArticuloMueble::setCantidad(int Cantidad) {
*	this->CantidadMueble = Cantidad ;
* @endcode
*/

#ifndef ARTICULOCOMPUTO_H_
#define ARTICULOCOMPUTO_H_
#include "Articulo.h"
#include "Profesor.h" 

using namespace std ;

class ArticuloComputo : public Articulo {
	private :
		string IDMarca ; /** @brief en este campo IDMarca toma el valor string */
		int CantidadDisponibles ; /** @brief en este campo CantidadDisponibles toma el valor int */
		float ValorDespreciacionAnual ; /** @brief en este campo ValorDespreciacionAnual toma el valor float */
		
		Profesor* ProfesorAsignado ; /** @brief Indica el profesor asignado al articulo */	

	public :
		/** 
		*@brief constructor de ArticuloComputo sin parametros y sin dato de retorno
		*/
		ArticuloComputo () ;
		
		/** 
		*@brief Lee el objeto Profesor asignado a al articulo
		*/
		Profesor* getProfesor () ;

		/** 
		*@brief asignarle la direccion de un objeto de tipo Profesor a un artico
		*/
		void AsignarAlArticulo (Profesor* Profesor) ;

		/** 
		*@brief asignar una marca a un ArticuloComputo (setIDMarca)
		*/
		void setIDMarca (string IDMarca) ;

		/** 
		*@brief asignar un valor de depreciacion a un ArticuloComputo (setDespreciacion)
		*/
		void setDespreciacion (float Despreciacion) ;

		/** 
		*brief asignar una cantidad a un ArticuloComputo (setCantidad )
		*/
		void setCantidad (int Cantidad) ;

		/**
		*@brief lee la marca de un objeto ArticuloComputo (getIDMarca)
		*/
		string getIDMarca () ;

		/**
		*@brief lee el valor de depreciacion de un objeto ArticuloComputo (getDespreciacion)
		*/
		float getDespreciacion() ;

		/**
		*@brief lee la cantidad disponible de un objeto ArticuloComputo (getCantidad)
		*/
		int getCantidad () ; 

		/**
		*@brief Aplicacion de polomorfismo para calcular la depreciacion de un objeto ArticuloComputo (Despreciacion)
		*/
		bool Despreciacion (Fecha* Actual, Fecha* FechaArticulo)  ; // Polimorfismo 

		/**
		*@brief Crear articulos de tipo ArticuloComputo (Despreciacion)
		*/
		void CrearComputo (ArticuloComputo* ComputoACrear) ; 

		/**
		*@brief Destructor de objetos ArticuloComputo (Despreciacion)
		*/
		~ArticuloComputo () ;
};
#endif
