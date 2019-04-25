/**
* @file Laboratorio.h
* @date 01/01/2019
* @title clase Laboratorio
* @brief clase Laboratorio, clase principal para tener funcionamiento el Laboratorio
* @code
* class Laboratorio {
*  private :
*      vector <Informacion> Informaciones
*  public :
*      void AgregarAlVectorInformaciones (int Cantidad) ;
*
* @endcode
*/


#ifndef LABORATORIO_H_
#define LABORATORIO_H_
#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#include "Profesor.h"
#include "Estudiante.h"
#include "Informacion.h"
#include "PersonalAdmi.h"
#include "ManejoDeArchivo.h"
#include "ArticuloDePrestamo.h"
#include "ArticuloComputo.h"
#include "ArticuloMueble.h"


using namespace std ;

class Laboratorio {
	private :
		Fecha* FechaInicio = new Fecha () ; /** @brief en este campo se estrablece la Fecha de creacion del Laboratorio del tipo objeto Fecha. */
		vector <Profesor> Profesores ; 	/** @brief en este campo se establece un vector donde almacena los Profesores del Laboratorio.  */
		vector <Estudiante> Estudiantes ; /** @brief en este campo se estrablece un vector donde almacena los Estudiantes del Laboratorio. */	
		vector <Informacion> Informaciones ; /** @brief en este campo se estrablece un vector donde almacena la Informaciomn disponible del Labboratorio. */
		vector <PersonalAdmi> PersonalAdmin ; /** @brief en este campo se estrablece un vector donde almacena el Personal Administrativo del Laboratorio. */
		vector <ArticuloDePrestamo> ArticulosDisponibles ; /** @brief en este campo se estrablece un vector donde alamcena los Articulos de Prestamo del Laboratorio. */
		vector <ArticuloComputo> ArticulosComp ; /** @brief en este campo se estrablece un vector donde almacena los Articulos de Computo del Laboratorio. */
		vector <ArticuloMueble> ArticulosMuebles ; /** @brief en este campo se estrablece un vector donde almacena los Articulos de Mueble del Laboratorio. */
		vector <int*> CodigosDeEstudiantes ; /** @brief en este campo se estrablece un vector donde almacena los codigos de los estudiantes */ // Verificar //
		vector <Fecha> FechasAuxiliarComp ; /** @brief en este campo se estrablece un vector auxiliares donde almacena las Fecha de Articulos de Computo */
		vector <Fecha> FechasAuxiliarMueb ; /** @brief en este campo se estrablece un vector auxiliares donde almacena las Fecha de Articulos de Mueble */
		vector <Fecha> FechasAuxiliarPrest ; /** @brief en este campo se estrablece un vector auxiliares donde almacena las Fecha de Articulos de Prestamos */

	public :
		/**
		*@brief Constructor de un objeto Laboratorio sin dato de retorno
		*/
		Laboratorio () ;
		
		// Mostrar todo lo que tiene cada vector
		/**
		*@brief Lee todos los objeto de tipo Profesor asignados al Laboratorio (getProfesores)
		*/
		void getProfesores () ; 

		/**
		*@brief Lee todos los objetos de tipo Estudiant asigandos al Laboratorio (getEstudiantes)
		*/
		void getEstudiantes () ;

		/**
		*@brief Lee todos los objeto de tipo Estudiantes con Asignaciones de prestamos que estan registrados en el Laboratorio (getEstudianteYPrestados)
		*/
		void getEstudianteYPrestados () ;

		/**
		*@brief Lee todos los objeto de tipo Personal Administrativo asignados al Laboratorio (getPersonalAdmin)
		*/
		void getPersonalAdmin () ;

		/**
		*@brief Lee todos los objeto de tipo Informacion asignados al Laboratorio (getProfesores)
		*/	
		void getInformaciones () ;

		/**
		*@brief Lee todos los objeto de tipo Articulos de Computo asignados al Laboratorio (getProfesores)
		*/
		void getComputo () ;

		/**
		*@brief Lee todos los objeto de tipo Articulos de Mueble asignados al Laboratorio (getProfesores)
		*/
		void getMuebles () ;

		/**
		*@brief Lee todos los objeto de tipo Articulos de Prestamo asignados al Laboratorio (getProfesores)
		*/
		void getPrestamos () ;

		/**
		*@brief Lee todos los objeto de tipo Fecha asignados al Laboratorio (getProfesores)
		*/
		void getFechaLaboratorio () ; 



		// Reglas
		/**
		*@brief Indica las reglas especificadas por el programador (Reglas)
		*/
		void Reglas () ;

		/**
		*@brief Para dar Limite de Fecha para los estudiantes que indicaron el servicion de prestamos (LimitePrestamos)
		*/
		void LimitePrestamos (int Articulo, Estudiante* EstudiantePrest, Fecha* FechaRegistro) ;  

		/**
		*@brief Asociar las fechas de plazo asignadas a los estudiantes (AsociarLimite)
		*/
		void AsociarLimite () ;

		/**
		*@brief Leer la fehca de plazo que tiene un estudiante en especifico (MostrarFechasLimites)
		*/
		void MostrarFechasLimites (int Posicion) ;
		
		
		// Cargar todos los archivos 
		/**
		*@brief Cargar todos los archivos con asignaciones desde los Archivos CSV a los vectores (CargarTodoslosArchivos)
		*/
		void CargarTodoslosArchivos () ;

		// Mandar tamaño del vector y posicion del ultimo dato
		// Cargar todos los archivos 
		/**
		*@brief Funcion Auxiliar que sirve para tener el tamaño total de todos los vectores mediante las funciones de map (MandarPosicionActual)
		*/	
		int MandarPosicionActual (int ClaseVector) ;
		
		//  Diligenciar Prestamo a estudiantes
		/**
		*@brief Diligenciar un prestamo solicitado por un estudiante asignado todo lo necesario para este (ServicioPrestamo)
		*/
		void ServicioPrestamo(int PosiEstudiante, int PosiArticulo) ;
		
		/**
		*@brief Lee todos los articulos prestados por un estudiante (VerMisPrestados) 
		*/
		void VerMisPrestados (int Posicion) ; 
		
		// Diligenciar devolucion de prestamos 
		/**
		*@brief Diligenciar el servicio de devolucion disponible para los estudiantes (ServicioDevolucion)
		*/
		bool ServicioDevolucion (int PosiEstudiante) ; 
		
		// Diligenciar pago de multa 
		/**
		*@brief Diligenciar el servicio disponible para los estudiantes de cancelar una deuda (RealizarPagoMulta)
		*/
		void RealizarPagoMulta(int Posicion) ;

		/**
		*@brief Procesar multa por demora de entraga de un articulo de prestamo solicitado por un estudiante (Multa)
		*/
		void Multa() ; 
		
		// Pedir datos y agregarlos al vector correspondiente

		bool AgregarAlVectorProfesores (int Cantidad) ; /**  @brief Pedir datos y agregarlos al vector correspondiente */

		bool AgregarAlVectorEstudiantes (int Cantidad) ; /**  @brief Pedir datos y agregarlos al vector correspondiente */

		void AgregarAlVectorInformaciones (int Cantidad) ; /**  @brief Pedir datos y agregarlos al vector correspondiente */

		bool AgregarAlVectorPersonalAdmin (int Cantidad) ; /**  @brief Pedir datos y agregarlos al vector correspondiente */

		bool AgregarAlVectorComputo (int Cantidad) ; /**  @brief Pedir datos y agregarlos al vector correspondiente */

		bool AgregarAlVectorMueble (int Cantidad) ; /**  @brief Pedir datos y agregarlos al vector correspondiente */

		bool AgregarAlVectorPrestamo(int Cantidad ); /**  @brief Pedir datos y agregarlos al vector correspondiente */

		// Acceder a alguna posicion
		// Para acceder mediante el codigo y agregarlo al articulo
		void AccederProfesor (int Codigo, int CodigoArticulo) ; /** @brief Para acceder mediante el codigo y agregarlo al articulo */

		void AccederProfesorPosicion (int Posicion) ; /** @brief Acceder a alguna posicion */

		void AccederArticulosProfe(int Posicion) ; /** @brief Acceder a alguna posicion */

		void AccederAUnEstudiante (int Posicion) ; /** @brief Acceder a alguna posicion */

		void AccederPersonalAdmi(int Posicion) ; /** @brief Acceder a alguna posicion */

		Informacion* AccederAUnaInformacion (int Posicion) ; /** @ brief Acceder a alguna posicion con puntero */

		void AccederAComputo (int Posicion) ; /**  brief Acceder a alguna posicion */

		void AccederAMueble (int Posicion) ; /** @brief Acceder a alguna posicion */

		void AccederProfesorMueb (int Codigo , int CodigoArticulo) ; /** @ brief Acceder a alguna posicion */

		void AccederArticulosPrestamo(int Posicion) ; /** @ brief Acceder a alguna posicion */

		void AccederProfesorArtPrestamo (int Codigo , int CodigoArticulo) ; /** @ brief Acceder a alguna posicion */

		void AccederEstadoMultaEstudiante(int Posicion); /** @ brief Acceder a alguna posicion y mostrar los estados */


		// Modificar datos de los vectores
		void ModificarDatosDelVectorInformaciones() ; /** @brief Modificar datos de los vector correspondiente */

		void ModificarDatosBasicosProfe(int Posicion) ; /** @brief Modificar datos de los vector correspondiente */

		void ModificarDatosProfe(int Posicion) ; /** @brief Modificar datos de los vector correspondiente */

		void ModificarDatosEstudiante(int Posicion) ; /** @brief Modificar datos de los vector correspondiente */

		void ModificarDatosDelVectorComputo() ; /** @brief Modificar datos de los vector correspondiente */

		void ModificarDatosMueble(int Posicion) ; /** @brief Modificar datos de los vector correspondiente */

		void ModificarDatosArticulosPrestamos(int Posicion) ; /** @brief Modificar datos de los vector correspondiente */


		// Eliminar datos de los vectores
		void EliminarDatosDelVectorInformaciones() ; /** @brief Eliminar datos de los vector correspondiente  */

		void EliminarDatosDelVectorComputo() ; /** @brief Eliminar datos de los vector correspondiente  */

		void EliminarDatosDelVectorProfesor() ; /** @brief Eliminar datos de los vector correspondiente  */

		void EliminarDatosDelVectorEstudiante(int Opcion) ; /** @brief Eliminar datos de los vector correspondiente  */

		void EliminarDatosDelVectorMueble() ; /** @brief Eliminar datos de los vector correspondiente  */

		void EliminarDatosDelVectorArticuloPrestamos() ; /** @brief Eliminar datos de los vector correspondiente  */

		void EliminarDatosDelVectorAdmi() ;  /** @brief Eliminar datos de los vector correspondiente  */

		void EliminarHistorial() ;  /** @brief Eliminar historial  */
		
		void EliminarAsignado (int Posicion) ; /** @brief Eliminar asignacion del articulo cuando se elimina un profesor  */

		// Asignar Profesor a Articulo
		void AsignarCodigosEstudiantes () ; /** @brief Asignar Codigos al estudiantes  */

		void AsignarProfesorComputo (int Posicion) ; /** @brief Asignar Profesor a Articulo Computo*/

		void AsignarProfeMueble (int Posicion) ; /** @brief Asignar Profesor a Articulo Mueble*/

		void AsignarProfePrestamo (int Posicion) ; /** @brief Asignar Profesor a Articulo Prestamo */


		// Asignar Fechas 
		void AsignarFechaComputo (int Posicion) ; /** @brief Asignar Fecha a Articulo Computo*/

		void AsignarFechaMueble (int Posicion) ; /** @brief Asignar Profesor a Articulo Mueble */

		void AsignarFechaPrestamo (int Posicion) ; /** @brief Asignar Fecha a Articulo Prestamo */

	
		// Consultas 
		void ConsultaProfeArticulos() ; /** @brief Consultar articulos asignados a un profesor*/

		void ConsultaAsignacionArt() ; /** @brief Consulta el profesor asignado a un articulo */

		void ConsultaMultaYEstado() ; /** @brief Consultar estado y multa de un Estudiante */

		void ConsultaVDEArticulo() ;  /** @brief Consultar Valor, Depreciacion y Estado de un articulo */

		void ConsultaActiInac() ; /** @brief Consultar Estado activo y inactivos  */

		
		// Funciones para los historiales

		void MostrarHistorialArticulo() ; /** @brief Mostrar Historial de prestamo de un articulo  */

		void MostrarHistorialEstudiante() ;  /** @brief Mostrar el Historial de prestamo de un Estudiante */

		void MostrarHistorialConFechas() ;  /** @brief Mostrar Historial en un rango dwe fechas indicadas*/

		
		// Indicar fecha actual 
		bool IndicarFecha() ; /** @brief Indicar la fecha actual */

		void Depreciar() ; /** @brief Procesar depreciacion a todos los articulos registrados en el Laboratorio */
		 
		// Para verificar si el vector esta vacio o no

		bool VerificarVectorProfesores () ; /** @brief Para verificar si el vector de Profesor esta vacio o no */

		bool VerificarVectorAdmin () ; /** @brief Para verificar si el vector de Personal Administrativo esta vacio o no */

		bool VerificarVectorEstudiantes () ; /** @brief Para verificar si el vector de Estudiantes esta vacio o no */

		bool VerificarVectorInformaciones () ; /** @brief Para verificar si el vector de Informacion del Laboratorio esta vacio o no */

		bool VerificarArticulosCompu () ; /** @brief Para verificar si el vector de Articulos de Computo esta vacio o no */

		bool VerificarArticulosMueble() ; /** @brief Para verificar si el vector de Articulos de Mueble esta vacio o no */

		bool VerificarArticulosPrestamo() ; /** @brief Para verificar si el vector de Articulos de Prestamo esta vacio o no */


		/**
		*@brief Destructor de un objeto de tipo Laboratorio, Funcion sin dato de retorno 
		*/
		~Laboratorio () ;
};
#endif
