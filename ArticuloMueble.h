/**
* @file ArticuloMueble.h
* @date 01/01/2019
* @title clase ArticuloMueble 
* @brief clase ArticuloMueble para definir articulos que tenga una herencia de este tipo
* @code
* class ArticuloMueble {
*  protected :
*      string Material;
*  public :
*      void setCantidad;
*      string getCantidad;
*
*  void ArticuloMueble::setCantidad(int Cantidad) {
*	this->CantidadTipoDeArticulo = Cantidad ;
* @endcode
*/


#ifndef ARTICULOMUEBLE_H_
#define ARTICULOMUEBLE_H_
#include "Articulo.h"
#include "Profesor.h"

using namespace std ;

class ArticuloMueble : public Articulo {
	private :
		string Material ; /** @brief en este campo Material toma el valor string */
		int CantidadMueble ; /** @brief en este campo CantidadMueble toma el valor int */
		float ValorDespreciacionAnual ; /** @brief en este campo ValorDespreciacionAnual toma el valor float */
		
		Profesor* ProfesorAsignado ; /** @brief Apunta a la direccion de un objeto de tipo Profesor que indica el Profesor asignado al articulo */
						
	public :
		/** 
		*@brief constructor de ArticuloMueble sin parametros y sin dato de retorno
		*/
		ArticuloMueble () ;

		/**
		*@brief Asigna el tipo de material a un objeto ArticuloMueble  (setMaterial)
		*/
		void setMaterial (string Material) ;

		/** 
		*@brief Asigna el valor de depreciacion a un Articulomueble (setDespreciacion)
		*/
		void setDespreciacion (float Despreciacion) ;

		/** 
		*@brief Asigna la cantidad que va a estar disponible de un Articulomueble (setCantidad)
		*/
		void setCantidad (int Cantidad) ;

		/** 
		*@brief Asigna la direccion que apunta a un objeto de tipo Profesor para indicar el Profesor a cargo de un objeto Articulomueble (AsignarAlArticulo)
		*/
		void AsignarAlArticulo (Profesor* Profesor) ;  

		/**
		*@brief Lee el tipo de material de un objeto ArticuloMueble (getMaterial)
		*/
		string getMaterial () ;

		/**
		*@brief Lee el valor de depreciacion de un objeto ArticuloMueble( getDespreciacion)
		*/
		float getDespreciacion() ;

		/** 
		*@brief Lee la cantidad disponible de un objeto ArticuloMueble (getCantidad)
		*/
		int getCantidad () ; 

		/** 
		*@brief Lee la direccion que apunta a un objeto de tipo Profesor que indica el Profesor asignado a un objeto ArticuloMueble (getProfesorAsignado)
		*/
		Profesor* getProfesorAsignado () ;

		/** 
		*@brief Aplicacion de Polimorfismo para calcular la depreciacion a un objeto ArticuloMueble (Despreciacion) 
		*/
		bool Despreciacion (Fecha* Actual, Fecha* FechaArticulo)  ; // Polimorfismo

		/** 
		*@brief Crea a un objeto ArticuloMueble (CrearMueble)
		*/
		void CrearMueble (ArticuloMueble* ArticuloACrear) ; 

		/** 
		*@brief Destructor de un objeto ArticuloMueble y sin dato de retorno (CrearMueble)
		*/
		~ArticuloMueble () ;
};
#endif 
