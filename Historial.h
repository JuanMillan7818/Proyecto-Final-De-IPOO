#ifndef HISTORIAL_H_
#define HISTORIAL_H_
#include "Estudiante.h"

using namespace std ;

class Historial {
	private :
		int HistorialPorArticulo ;
		int HistorialPorEstudiante ;
		
		//Vectores
		vector <Articulo>* ArticuloHistorial ;
		vector <Estudiante>* EstudianteHistorial ;
		
				
	public :
		//Constructores
		Historial () ;
		Historial (int HistorialPorArticulo, int HistorialPorEstudiante) ;
		
		//Otros metodos
		void AgregarDatosAlArticuloHistorial (Articulo &ArticuloTemporal) ;
		void AgregarDatosAlEstudianteHistorial (Estudiante &EstudianteTemporal) ;
		void ConsultarHistorialPorArticulo () ;
		void ConsultarHistorialPorEstudiante () ;
		
		//Destructor
		~Historial () ; 
};
#endif 
