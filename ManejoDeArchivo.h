/**
* @file ManejoDeArchivo.h
* @date 01/01/2019
* @title clase ManejoDeArchivo
* @brief clase ManejoDeArchivo, clase con el control total del Manejo de archivos de todo el Laboratorio
* @code
* class ManejoDeArchivo {
*  private :
*      int PosicionDelVector ;
*  public :
*      void CrearArchivoInformacionCSV (vector <Informacion> Informaciones) ;
*
* @endcode
*/


#ifndef MANEJODEARCHIVO_H_
#define MANEJODEARCHIVO_H_
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include "Laboratorio.h"
#include "ArticuloComputo.h"
#include "ArticuloMueble.h"


using namespace std ;

class ManejoDeArchivo {
	private :
		int PosicionDelVector ;  

	public :
		/**
		*@brief Constructor de un objeto ManejoDeArchivo, Funcion sin dato de retorno
		*/
		ManejoDeArchivo () ;
		
		// Manejo de Archivos Para Informacion del laboratorio
		void CrearArchivoInformacionCSV (vector <Informacion> Informaciones) ; /** @brief Manejo de Archivos para crear CSV Para Informacion del laboratorio */
		void CargarArchivoInformacionCSV (vector <Informacion>* Informaciones) ; /** @brief Manejo de Archivos para cargar CSV de Informacion del laboratorio y almacencarlas en el vector correspondiente */

		// Manejo de Archivos Para Estudiante del laboratorio
		void CrearArchivoEstudianteCSV (vector <Estudiante> Estudiantes) ; /** @brief Manejo de Archivos para crear CSV Para Estudiantes del laboratorio */
		void ActualizarArchivoEstudianteCSV (vector <Estudiante> Estudiantes) ; /** @brief Manejo de Archivos para actualizar CSV de Estudiantes del laboratorio */
		void CargarArchivoEstudianteCSV (vector <Estudiante>& Estudiantes) ; /** @brief Manejo de Archivos para cargar CSV de Estudiantes del laboratorio y almacencarlas en el vector correspondiente */
		
		// Manejo De Archivos Para Los Articulos Prestados Por Un Estudiante
		void CrearArchivoPrestados (vector <Estudiante> Prestamos) ; /** @brief Manejo de Archivos para crear CSV Para los Archivos prestados del laboratorio */
		void ActualizarPrestados (vector <Estudiante> Prestamos) ; /** @brief Manejo de Archivos para actualizar CSV de los Archivos prestados del laboratorio */
		void CargarPrestados (vector <Estudiante*> Prestamos, vector <ArticuloDePrestamo*> Articulos) ; /** @brief Manejo de Archivos para cargar CSV de Articulos Prestados del laboratorio y almacencarlas en el vector correspondiente */

		// Manejo de Archivos Para Profesor del laboratorio
		void CrearArchivoProfesorCSV (vector <Profesor> Profesores) ; /** @brief Manejo de Archivos para crear CSV para los Profesores del laboratorio */
		void ActualizarArchivoProfesorCSV (vector <Profesor> Profesores) ; /** @brief Manejo de Archivos para actualizar CSV de Profesores del laboratorio */
		void CargarArchivoProfesorCSV (vector <Profesor>* Profesores) ; /** @brief Manejo de Archivos para cargar CSV de Profesores del laboratorio y almacencarlas en el vector correspondiente */
		
		// Manejo de Archivos Para Articulo de Personal Administrativo del laboratorio
		void CrearArchivoAdminisCSV (vector <PersonalAdmi> PersonalAdm) ; /** @brief Manejo de Archivos para crear CSV para el Personal Administrativo del laboratorio */
		void ActualizarAdimisCSV (vector <PersonalAdmi> PersonalAdm) ;  /** @brief Manejo de Archivos para actualizar CSV de Personal Administrativo del laboratorio */
		void CargarArchivoAdminisCSV (vector <PersonalAdmi>* PersonalAdm) ; /** @brief Manejo de Archivos para cargar CSV de Personal Administrativo del laboratorio y almacencarlas en el vector correspondiente */
		
		
		// Manejo de Archivos para Articulos de Computo del Laboratorio 
		void CrearArchivoArticuloComputoCSV (vector <ArticuloComputo> ArticulosParaComputo) ; /** @brief Manejo de Archivos para crear CSV para los Articulos de Computo del laboratorio */
		void ActualizarComputoCSV (vector <ArticuloComputo> ArticulosParaComputo) ; /** @brief Manejo de Archivos para actualizar CSV de Articulos de Computo del laboratorio */
		vector <int> CargarArchivoArticuloComputoCSV (vector <ArticuloComputo>* ArticulosParaComputo) ; /** @brief Manejo de Archivos para cargar CSV de Articulos de Computo del laboratorio y almacencarlas en el vector correspondiente */
		void CargarArticuloComputoCSV (vector <Fecha>* FechasRegistradas) ; /** @brief Manejo de Archivos para cargar las Fechas del CSV de Articulos de Computo del laboratorio y almacencarlas en el vector correspondiente */
		
		
		// Manejo de Archivos Para Articulo de prestamo del laboratorio
		void CrearArchivoArticuloDePrestamoCSV (vector <ArticuloDePrestamo> ArticulosParaPrestar) ; /** @brief Manejo de Archivos para crear CSV para los Articulos de Prestamo del laboratorio */
		void ActualizarArchivoArticuloDePrestamoCSV (vector <ArticuloDePrestamo> ArticulosParaPrestar) ; /** @brief Manejo de Archivos para actualizar CSV de Articulos de Prestamo del laboratorio */
		vector <int> CargarArchivoArticuloDePrestamoCSV (vector <ArticuloDePrestamo>* ArticulosParaPrestar) ; /** @brief Manejo de Archivos para cargar CSV de Articulos de Prestamo del laboratorio y almacencarlas en el vector correspondiente */
		void CargarArticuloDePrestamoCSV (vector <Fecha>* FechasRegistradas) ; /** @brief Manejo de Archivos para cargar las Fechas del CSV de Articulos de Prestamo del laboratorio y almacencarlas en el vector correspondiente */

		// Manejo de Archivos para Articulos de Mueble del Laboratorio
		void CrearArchivoArticuloMuebleCSV (vector <ArticuloMueble> ArticulosParaMueble) ; /** @brief Manejo de Archivos para crear CSV para los Articulos de Mueble del laboratorio */
		void ActualizarMuebleCSV (vector <ArticuloMueble> ArticulosParaMueble) ; /** @brief Manejo de Archivos para actualizar CSV de Articulos de Mueble del laboratorio */
		vector <int> CargarArchivoArticuloMuebleCSV (vector <ArticuloMueble>* ArticulosParaMueble) ; /** @brief Manejo de Archivos para cargar CSV de Articulos de Mueble del laboratorio y almacencarlas en el vector correspondiente */
		void CargarArticuloMuebleCSV (vector <Fecha>* FechasRegistradas) ; /** @brief Manejo de Archivos para cargar las Fechas del CSV de Articulos de Mueble del laboratorio y almacencarlas en el vector correspondiente */
	
		// Crear historiales
		void HistorialPrestamoCSV (vector <Estudiante> EstudiantePrestamo) ; /** @brief Manejo de Archivos para crear CSV para el Historial del laboratorio */
		void ActualizarHistorial (vector <Estudiante> EstudiantePrestamo) ; /** @brief Manejo de Archivos para actualizar CSV de Historial del laboratorio */
		void CargarHistorialPrestamo (vector <Estudiante>* Estudiantes) ; /** @brief Manejo de Archivos para cargar los Estudiantes que han generado Historial en el CSV de Historial del laboratorio y almacencarlas en el vector correspondiente */
		void CargarHistorialPrestamo (vector <ArticuloDePrestamo>* Prestamos) ; /** @brief Manejo de Archivos para cargar los Articulos de Prestamo que estan en el CSV de Historial del laboratorio y almacencarlas en el vector correspondiente */
		void CargarHistorialPrestamo (vector <Fecha>* FechaHistorial) ; /** @brief Manejo de Archivos para cargar las Fechas del CSV de Historial del laboratorio y almacencarlas en el vector correspondiente */
				
		// Crear Plazo de entrega
		void CrearPlazoEntrega (vector <Estudiante> EstudiantePlazo) ; /** @brief Manejo de Archivos para crear CSV para las Fechas limites de Articulos de Prestamos del laboratorio */
		void ActualizarPlazos (vector <Estudiante> EstudiantePlazo) ; /** @brief Manejo de Archivos para actualizar CSV de las Fechas limites de Articulos de Prestamos del laboratorio */
		void CargarPlazos (vector <Estudiante>* EstudianteAux) ; /** @brief Manejo de Archivos para cargar los Estudiantes del CSV de las Fechas limites de Articulos de Prestamos del laboratorio y almacencarlas en el vector correspondiente */
		void CargarPlazos (vector <Fecha>* FechasRegistradas) ; /** @brief Manejo de Archivos para cargar las Fechas del CSV de las Fechas limites de Articulos de Prestamos del laboratorio y almacencarlas en el vector correspondiente */
		void CargarPlazos (vector <ArticuloDePrestamo>* PrestamosAux) ; /** @brief Manejo de Archivos para cargar los Articulos de prestamos del CSV con las Fechas limites de Articulos de Prestamos del laboratorio y almacencarlas en el vector correspondiente */
		
		// Funcion para Cambiar de string -> int
		/**
		*@brief Funcion Auxiliar para convertir los string en flotantes para su uso
		*/
		float CambioStringALong (string Temporal) ;

		/**
		*@brief Destructor de un objeto ManejoDeArchivo, Funcion sin dato de retorno
		*/		
		~ManejoDeArchivo () ;
};
#endif
