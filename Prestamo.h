#ifndef PRESTAMO_H_
#define PRESTAMO_H_
#include <iostream> 
#include <string>
#include <vector>
#include "Estudiante.h" 
//#include "ManejoDeArchivo.h" 

using namespace std ;

class Prestamo {
	private :
		//Vector
		vector <ArticuloDePrestamo*> ArticulosPrestados ;
		
		//Puntero 
		Estudiante* Auxiliar ; // Mirar a ver si este es necesario
		
	public :
		//Constructor
		Prestamo() ;
		
		//Otros metodos
		void CrearArchivoCSVHistorial () ; 
		void AgregarAlHistorial (ArticuloDePrestamo* ArticuloAPrestar) ;
		void DiligenciarPrestamo (ArticuloDePrestamo* ArticuloAPrestar, Estudiante* a ) ;
		
		//Destructor
		~Prestamo() ; 
};
#endif
