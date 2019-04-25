/**
* @file Menu.h
* @date 01/01/2019
* @title clase Menu
* @brief clase Menu, Permite tener la interactuacion con el usuario, y dar orden al programa
* @code
* class Menu {
*  private :
*    int Opcion ;
*  public :
*      void MenuIngreso() ;
*
*	void Menu::MenuIngreso() {
*		cout << "1.Registrarse \n" ;
*
*  
* @endcode
*/



#ifndef MENU_H_
#define MENU_H_
#include <string>
#include "Laboratorio.h"

using namespace std ;

class Menu {
	private :
		// Este Atributo es para utilizar solo en el menu
		int Opcion ; /** @brief Este Atributo es para utilizar solo en el menu 
			     * para que me vaya almacenando la opciones ingresadas
			     */
		Laboratorio* UsoDelLaboratorio = new Laboratorio () ; /** @brief Apunta a un objeto Laboratorio que permitira que se pueda adminisstrar y manejar todos los datos del Laboratorio */
		 
	public :
		/** 
		*@brief Constructor de MenuIngreso sin parametros y sin dato de retorno
		*/
		Menu () ; 

		/** 
		*@brief Menu inicial que permitira la interactuacion para ingresar centro del sistema
		*/
		void MenuIngreso () ;

		/** 
		*@brief Menu que indicara un registro de persona o ingresar con datos existentes
		*/
		void RegistroIDPersona () ;

		/** 
		*@brief Menu que indicara con que informacion ya existente podras ingresar al sistema
		*/
		void MenuDatosExistentes() ;

		/** 
		*@brief Menu de las opciones posibles	
		*/
		void MenuOpcionesPosibles () ;

		/** 
		*@brief Menu para personas que se hallan registrado como Estudiantes con las funciones posibles de un Estudiante
		*/
		void MenuParaEstudiantes(int Posicion) ;

		/** 
		*@brief Menu solo para Personal Administrativo para manejar datos exclusivos de un Estudiante
		*/
		void MenuExclusivoEstudiante();

		/** 
		*@brief Menu para las personas que se hallan registrado como Profesores con las funciones posibles de un Profesor
		*/
		void MenuParaProfesores (int Posicion) ;

		/** 
		*@brief Menu solo para PersonalAdministrativo para manejar datos exclusivos de un Profesor
		*/
		void MenuExclusivoProfe() ;
		
		/** 
		*@brief Menu para interactuar con todas los funciones disponibles de un Articulo de Prestamo
		*/
		void MenuParaArticulosDePrestamo () ;

		/** 
		*@brief Menu para interactuar con todas los funciones disponibles de un Articulo de Mueble
		*/
		void MenuParaArticulosDeMueble   () ;

		/** 
		*@brief Menu para interactuar con todas los funciones disponibles de un Articulo de Computo
		*/
		void MenuParaArticulosDeComputo  () ;

		/** 
		*@brief Menu Para las personas que se hallan registrado como Personal Administrativo con las funciones disponibles de este
		*/
		void MenuParaPersonalAdmi(int Posicion) ;
		
		/** 
		*@brief Menu para el manejo de Informacion del Laboratorio
		*/
		void MenuInformacionLaboratorio () ;
		
		/** 
		*@brief Menu Para averiguar que estados de los articulos desea ver
		*/
		void MenuParaEstadosDeArticulo () ;

		/** 
		*@brief Menu para interactuar con las funciones acerca de las consultas permitidas
		*/
		void MenuConsultas () ;

		/** 
		*@brief Destructor de un objeto Menu sin dato de retorno
		*/
		~Menu () ;
};
#endif 
