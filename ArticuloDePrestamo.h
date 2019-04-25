/**
* @file ArticuloDePrestamo.h
* @date 01/01/2019
* @title clase ArticuloDePrestamo 
* @brief clase ArticuloDePrestamo para definir articulos que tenga una herencia de este tipo
* @code
* class ArticuloDePrestamo {
*  protected :
*      string IDMarca;
*  public :
*      void setCantidad;
*      string getCantidad;
*
*  void ArticuloDePrestamo ::setCantidad(int Cantidad) {
*	this->CantidadTipoDeArticulo = Cantidad ;
* @endcode
*/


#ifndef ARTICULODEPRESTAMO_H_
#define ARTICULODEPRESTAMO_H_
#include "Articulo.h"
#include "Profesor.h"
#include "Fecha.h"
#include <vector>

class ArticuloDePrestamo : public Articulo { 
	private :
		string IDMarca ; /** @brief en este campo IDMarca toma el valor string */
		int CantidadDeTipoDeArticulo ; /** @brief en este campo CantidadDeTipoDeArticulo toma el valor int */
		float ValorDespreciacionAnual ; /** @brief en este campo ValorDespreciacionAnual toma el valor float  */

		
		Profesor* ProfesorAsignado ; /** @brief Apunta a un objeto de tipo Profesor asignado a un articulo  */
		Fecha* FechaLimite ; /** @brief Apunta a un objeto de tipo Fecha que indica la fecha limite de prestamo */
		
	public :
		/** 
		*@brief constructor de ArticuloDePrestamo sin parametros y sin dato de retorno
		*/
		ArticuloDePrestamo () ;

		/**
		*@brief Asigna la marca a un objeto ArticuloDePrestamo  (agrega un IDMarca)
		*/
		void setIDMarca (string IDMarca) ;

		/**
		*@brief Asigna cantidad que va a estar disponible sobre un objeto ArticuloDePrestamo  (agrega una CantidadDeArticulos)
		*/
		void setCantidadDeTipoDeArticulo (int CantidadDeArticulos) ;

		/**
		*@brief Asina el valor de depreciacion de un objeto ArticuloDePrestamo (setDespreciacion)
		*/
		void setDespreciacion (float Despreciacion) ;

		/**
		*@brief Lee marca de un objeto ArticuloDePrestamo  (getIDMarca)
		*/
		string getIDMarca () ;

		/**
		*@brief Lee la cantidad actual que tiene un objeto ArticuloDePretamo (getIDCantidadDeTipoDeArticulo)
		*/
		int getCantidadDeTipoDeArticulo () ;

		/**
		*@brief Lee el valor de depreciacion de un objeto ArticuloDePrestamo (getDespreciacion)
		*/
		float getDespreciacion() ;

		/**
		*@brief Lee todos los valores que apuntan a un objeto de tipo Profesor que es el asignado a un objeto ArticuloDePrestamo (getProfesor) 
		*/
		Profesor* getProfesor () ;

		/**
		*@brief Asigna a una direccion que apunta a un objeto de tipo Profesor que es el asignado a un objeto ArticuloDePrestamo (AsignarAProfesor)
		*/	
		void AsignarAProfesor (Profesor* Profesor) ;

		/**
		*@brief Crear un objeto ArticuloDePrestamo (AsignarAProfesor)
		*/
		void CrearArticuloParaPrestamo (ArticuloDePrestamo* ArticuloParaCrear) ; 

		/**
		*@brief Aplicacion de Polimorfismo para calcular la depreciacion de un objeto ArticuloDePrestamo (Despreciacion)
		*/
		bool Despreciacion (Fecha* Actual, Fecha* FechaArticulo)  ;  // Polimorfismo

		/**
		*@brief Asigna la direccion que apunta a un objeto de tipo Fecha que indica la Fecha de plazo de entrega para un ArticuloDePrestamo (AgregarFechaLim)
		*/
		void AgregarFechaLim (Fecha* FechaLim) ; 

		/**
		*@brief Lee la direccion que apunta a un objeto de tipo Fecha que indica la Fecha de plazo de entrega de un objeto ArticuloDePrestamo (MostrarFecha)
		*/
		Fecha* MostrarFecha () ; 

		/**
		*@brief Destructor de un objeto de tipo ArticuloDePrestamo sin dato de retorno
		*/
		~ArticuloDePrestamo () ;
};
#endif 
