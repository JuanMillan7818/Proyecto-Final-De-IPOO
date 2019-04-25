
#include "ManejoDeArchivo.h" 

// CONSTRUCTOR
ManejoDeArchivo::ManejoDeArchivo() {
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Funcion para crear el archivo .csv de informacion del laboratorio
void ManejoDeArchivo::CrearArchivoInformacionCSV(vector <Informacion> Informaciones) {
	ifstream Archivo ("Informacion-Laboratorio.csv") ;

	if (!Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Informacion-Laboratorio.csv", ios::app) ;

		for (int i=0 ; i<Informaciones.size() ; i++) {
			Archivo << Informaciones[i].getNombreDeInfo() << ';' << Informaciones[i].getContenidoDeInfo() << '\n' ;
		}
		Archivo.close() ;
	} else if (!Informaciones.empty()) {
		ofstream Archivo ;
		Archivo.open("Informacion-Laboratorio.csv", ios::out) ;

		for (int i=0 ; i<Informaciones.size() ; i++) {
			Archivo << Informaciones[i].getNombreDeInfo() << ';' << Informaciones[i].getContenidoDeInfo() << '\n' ; 
		}
	}
	Archivo.close() ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::CargarArchivoInformacionCSV(vector <Informacion>* Informaciones) {
	Informaciones->clear() ;

	ifstream Archivo ("Informacion-Laboratorio.csv") ;
	Informacion* InformacionAuxiliar = new Informacion ;
	string Nombre, Contenido ;

	if (Archivo.is_open()) {
		if (!Archivo.fail()) {
			while (!Archivo.eof()) {
				// Copiar todo a variables temporales
				getline(Archivo, Nombre, ';') ;
				getline(Archivo, Contenido, '\n') ;
	
				// Guardar lo que hay en las variables en vectores
				InformacionAuxiliar->setNombreDeInfo(Nombre) ;
				InformacionAuxiliar->setContenidoDeInfo(Contenido) ;
	
				// Agregar  al vector
				Informaciones->push_back(*InformacionAuxiliar) ;
			}
			// Eliminar un ultimo elemento que me crea
			Informaciones->pop_back() ;
		}else {
			system("cls") ;
			cout << "\nExiste un fallo en los archivos de informacion, REVISALAS !! \n\n" ;
			system("pause") ;
			CrearArchivoInformacionCSV(*Informaciones) ;
		}		
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Funcion para crear Archivo .csv  de informacion de estudiantes
void ManejoDeArchivo::CrearArchivoEstudianteCSV(vector <Estudiante> Estudiantes) {
	ifstream Archivo ("Estudiantes-Laboratorio.csv") ;

	if (!Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Estudiantes-Laboratorio.csv" , ios::app) ;

		for (int i=0 ; i<Estudiantes.size() ; i++) {
			Archivo << "Nombre" << ';' << "Apellido" << ';' << "Email" << ';'  ;
			Archivo << "Carrera" << ';' << "Edad" << ';' << "Cedula" << ';'   ;
			Archivo << "Telefono" << ';'<< "Codigo" << ';' << "Semestre" << ';' ;
			Archivo << "Valor de multa Acomulada" << ';' << "Estado de multa" << ';' << "Estado del estudiante" << '\n' ;
			Archivo << Estudiantes[i].getNombre() << ';' << Estudiantes[i].getApellido() << ';'  ;
			Archivo << Estudiantes[i].getEmail() << ';' << Estudiantes[i].getCarrera() << ';'       ;
			Archivo << Estudiantes[i].getEdad() << ';' << Estudiantes[i].getCedula() << ';'  ;
			Archivo << Estudiantes[i].getTelefono() << ';' << Estudiantes[i].getCodigo() << ';'   ;
			Archivo << Estudiantes[i].getSemestre() << ';' << Estudiantes[i].getValorMultaAcomulada() << ';'      ;
			Archivo << Estudiantes[i].getEstadoDeMulta() << ';' << Estudiantes[i].getEstadoDeEstudiante() << '\n'  ;
		}
		Archivo.close() ;
	}else { // Agregar otro registro de persona
		ActualizarArchivoEstudianteCSV(Estudiantes) ;
	}
	Archivo.close() ;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Actualizar Archivo de Estudiantes
void ManejoDeArchivo::ActualizarArchivoEstudianteCSV(vector <Estudiante> Estudiantes) {
	ofstream Archivo ("Estudiantes-Laboratorio.csv", ios::out) ;
	// Cabezeras
	Archivo << "Nombre" << ';' << "Apellido" << ';' << "Email" << ';'  ;
	Archivo << "Carrera" << ';' << "Edad" << ';' << "Cedula" << ';'   ;
	Archivo << "Telefono" << ';'<< "Codigo" << ';' << "Semestre" << ';' ;
	Archivo << "Valor de multa Acomulada" << ';' << "Estado de multa" << ';' << "Estado del estudiante" << '\n' ;

	for (int i=0 ; i<Estudiantes.size() ; i++) {
		Archivo << Estudiantes[i].getNombre() << ';' << Estudiantes[i].getApellido() << ';'  ;
		Archivo << Estudiantes[i].getEmail() << ';' << Estudiantes[i].getCarrera() << ';'       ;
		Archivo << Estudiantes[i].getEdad() << ';' << Estudiantes[i].getCedula() << ';'  ;
		Archivo << Estudiantes[i].getTelefono() << ';' << Estudiantes[i].getCodigo() << ';'   ;
		Archivo << Estudiantes[i].getSemestre() << ';' << Estudiantes[i].getValorMultaAcomulada() << ';'      ;
		Archivo << Estudiantes[i].getEstadoDeMulta() << ';' << Estudiantes[i].getEstadoDeEstudiante() << '\n'  ;
	}
	Archivo.close() ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void ManejoDeArchivo::CargarArchivoEstudianteCSV(vector <Estudiante>& Estudiantes) {
	Estudiantes.clear() ; // Eliminar por si existe algo ya en el vector

	ifstream Archivo ("Estudiantes-Laboratorio.csv") ;
	Estudiante* EstudianteAuxiliar = new Estudiante ;
	string Nombre, Apellido, Email, Carrera, Edad, Cedula, Telefono, Codigo ;
	string Semestre, ValorMultaAcomulada, EstadoDeMulta, EstadoDeEstudiante ;


	if (Archivo.is_open()) {
		if (!Archivo.fail()) {
			char texto[512]  ;
			Archivo.getline(texto,512, '\n') ; // Cabeceras
			while (!Archivo.eof()) {
				// Copiar todo a variables temporales
				getline(Archivo, Nombre, ';') ;
				getline(Archivo, Apellido, ';') ;
				getline(Archivo, Email, ';') ;
				getline(Archivo, Carrera, ';') ;
				getline(Archivo, Edad, ';') ;
				getline(Archivo, Cedula, ';') ;
				getline(Archivo, Telefono, ';') ;
				getline(Archivo, Codigo, ';') ;
				getline(Archivo, Semestre, ';') ;
				getline(Archivo, ValorMultaAcomulada, ';') ;
				getline(Archivo, EstadoDeMulta, ';') ;
				getline(Archivo, EstadoDeEstudiante, '\n') ;
	
				// Guardar lo que hay en las variables en vectores
				EstudianteAuxiliar->setNombre (Nombre) ;
				EstudianteAuxiliar->setApellido(Apellido) ;
				EstudianteAuxiliar->setEmail(Email) ;
				EstudianteAuxiliar->setCarrera(Carrera) ;
				// Variable con paso de strin a entero
				EstudianteAuxiliar->setEdad(CambioStringALong (Edad)) ;
				EstudianteAuxiliar->setCedula(CambioStringALong (Cedula)) ;
				EstudianteAuxiliar->setTelefono(CambioStringALong (Telefono)) ;
				EstudianteAuxiliar->setCodigo(CambioStringALong (Codigo)) ;
				EstudianteAuxiliar->setSemestre(CambioStringALong (Semestre)) ;
				EstudianteAuxiliar->CorrerValorMulta(CambioStringALong (ValorMultaAcomulada)) ;
				EstudianteAuxiliar->setEstadoDeMulta(CambioStringALong (EstadoDeMulta)) ;
				EstudianteAuxiliar->setEstadoDeEstudiante(CambioStringALong (EstadoDeEstudiante)) ;
	
				// Agregar  al vector
				Estudiantes.push_back(*EstudianteAuxiliar) ;
			}
			// Eliminar un ultimo elemento que me crea
			Estudiantes.pop_back() ;
			
		}else {
			system("cls") ;
			cout << "\nExiste un fallo en los archivos de Estudiantes, REVISALAS !! \n\n" ;
			system("pause") ;
			ActualizarArchivoEstudianteCSV(Estudiantes) ;
		}		
	}

	delete EstudianteAuxiliar ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void ManejoDeArchivo::CrearArchivoPrestados(vector <Estudiante> Prestamos) {
	
	ifstream Archivo ("Articulos-De-Estudiantes.csv") ;
	
	if(!Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Articulos-De-Estudiantes.csv", ios::app) ;
		
		Archivo << "Codigo del Estudiante" << ';' << "Codigo del articulo Prestado" << '\n' ; 
	
		for (int i=0 ; i<Prestamos.size() ; i++) {
			for (int j=0 ; j<Prestamos[i].MisArticulos().size() ; j++) {
				Archivo << Prestamos[i].getCodigo() << ';' <<  Prestamos[i].MisArticulos()[j]->getCodigoArticulo() << '\n' ; 
			}
		}
	}else {
		ActualizarPrestados(Prestamos) ;
	}
	Archivo.close() ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::ActualizarPrestados(vector <Estudiante> Prestamos) {
	ofstream Archivo ;
	Archivo.open("Articulos-De-Estudiantes.csv", ios::out) ;
		
	Archivo << "Codigo del Estudiante" << ';' << "Codigo del articulo Prestado" << '\n' ; 
		
	for (int i=0 ; i<Prestamos.size() ; i++) {
		for (int j=0 ; j<Prestamos[i].MisArticulos().size() ; j++) {
			Archivo << Prestamos[i].getCodigo() << ';' <<  Prestamos[i].MisArticulos()[j]->getCodigoArticulo() << '\n' ; 
		}
	}
	Archivo.close() ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::CargarPrestados(vector <Estudiante*> Prestamos, vector <ArticuloDePrestamo*> Articulos) {
	
	ifstream Archivo ("Articulos-De-Estudiantes.csv") ;

	string CodigoEstudiante, CodigoArticulo ;
	int CodigoEstAux, CodigoArtAux ;

	if (Archivo.is_open()) {
		if(!Archivo.fail()) {
			char texto[512]  ;
			// Copiar todo a variables temporales
			Archivo.getline(texto,512, '\n') ; // Cabeceras
			while (!Archivo.eof()) {
				
				for (int i=0 ; i<Prestamos.size() ; i++) {
					getline(Archivo, CodigoEstudiante, ';') ;
					CodigoEstAux = CambioStringALong (CodigoEstudiante) ;
					
					getline(Archivo, CodigoArticulo, '\n') ;
					CodigoArtAux = CambioStringALong (CodigoArticulo) ;
					
					if (CodigoEstAux == Prestamos[i]->getCodigo()) {
						for (int j=0 ; j<Articulos.size() ; j++) {
							if (CodigoArtAux == Articulos[j]->getCodigoArticulo()) {							
								Prestamos[i]->ArticuloParaPrestar(Articulos[j]) ; 
							}
						} 
	 				}
				}
			}
		}else {
			system("cls") ;
			cout << "\nExiste un fallo en los archivos de Estudiantes, REVISALAS !! \n\n" ;
			system("pause") ;
		}		
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Funcion para crear Archivo .csv de informacion de profesores
void ManejoDeArchivo::CrearArchivoProfesorCSV(vector <Profesor> Profesores) {
	ifstream Archivo ("Profesores-Laboratorio.csv") ;
	
	if (!Archivo.is_open()) {
		ofstream Archivo ;
		
		Archivo.open("Profesores-Laboratorio.csv", ios::app) ;
	
		Archivo << "Nombre" << ';' << "Apellido" << ';' << "Email" << ';'  ;
		Archivo << "Edad" << ';' << "Cedula" << ';' << "Telefono" << ';'   ;
		Archivo << "Codigo" << ';' << "Titulo Prfesional" << '\n' ;
		
		for (int i=0 ; i<Profesores.size() ; i++) {
			Archivo << Profesores[i].getNombre() << ';' << Profesores[i].getApellido() << ';'  ;
			Archivo << Profesores[i].getEmail() << ';' << Profesores[i].getEdad() << ';'       ;
			Archivo << Profesores[i].getCedula() << ';' << Profesores[i].getTelefono() << ';'  ;
			Archivo << Profesores[i].getCodigo() << ';' << Profesores[i].getTituloProfesional() << '\n'   ;
			
		}
	}else {
		ActualizarArchivoProfesorCSV(Profesores) ;
	}
	
	Archivo.close() ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void ManejoDeArchivo::ActualizarArchivoProfesorCSV(vector <Profesor> Profesores) {
	ofstream Archivo ;
	Archivo.open("Profesores-Laboratorio.csv", ios::out) ;

	Archivo << "Nombre" << ';' << "Apellido" << ';' << "Email" << ';'  ;
	Archivo << "Edad" << ';' << "Cedula" << ';' << "Telefono" << ';'   ;
	Archivo << "Codigo" << ';' << "Titulo Prfesional" << '\n' ;
	
	for (int i=0 ; i<Profesores.size() ; i++) {
		Archivo << Profesores[i].getNombre() << ';' << Profesores[i].getApellido() << ';'  ;
		Archivo << Profesores[i].getEmail() << ';' << Profesores[i].getEdad() << ';'       ;
		Archivo << Profesores[i].getCedula() << ';' << Profesores[i].getTelefono() << ';'  ;
		Archivo << Profesores[i].getCodigo() << ';' << Profesores[i].getTituloProfesional() << '\n' ;
	}
	Archivo.close() ;
}
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::CargarArchivoProfesorCSV(vector <Profesor>* Profesores) {
	Profesores->clear() ; // Eliminar por si existe algo ya en el vector

	ifstream Archivo ("Profesores-Laboratorio.csv") ;
	Profesor* ProfesoreAuxiliar = new Profesor ;
	string Nombre, Apellido, Email, Carrera, Edad, Cedula, Telefono, Codigo, TituloProfesional ;

	if (Archivo.is_open()) {
		if(!Archivo.fail()) {
			char texto[512]  ;
			// Copiar todo a variables temporales
			Archivo.getline(texto,512, '\n') ; // Cabeceras
			while (!Archivo.eof()) {
				getline(Archivo, Nombre, ';') ;
				getline(Archivo, Apellido, ';') ;
				getline(Archivo, Email, ';') ;
				getline(Archivo, Edad, ';') ;
				getline(Archivo, Cedula, ';') ;
				getline(Archivo, Telefono, ';') ;
				getline(Archivo, Codigo, ';') ;
				getline(Archivo, TituloProfesional, '\n') ;
	
				// Guardar lo que hay en las variables en vectores
				ProfesoreAuxiliar->setNombre (Nombre) ;
				ProfesoreAuxiliar->setApellido(Apellido) ;
				ProfesoreAuxiliar->setEmail(Email) ;
				ProfesoreAuxiliar->setTituloProfesional(TituloProfesional) ;
	
				// Variable con paso de strin a entero
				ProfesoreAuxiliar->setEdad(CambioStringALong (Edad)) ;
				ProfesoreAuxiliar->setCedula(CambioStringALong (Cedula)) ;
				ProfesoreAuxiliar->setTelefono(CambioStringALong (Telefono)) ;
				ProfesoreAuxiliar->setCodigo(CambioStringALong (Codigo)) ;
	
				// Agregar  al vector
				Profesores->push_back(*ProfesoreAuxiliar) ;
			}
			// Eliminar un ultimo elemento que me crea
			Profesores->pop_back() ;
		}else {
			system("cls") ;
			cout << "\nExiste un fallo en los archivos de Profesores, REVISALAS !! \n\n" ;
			system("pause") ;
			ActualizarArchivoProfesorCSV(*Profesores) ;
		}		
	}

	delete ProfesoreAuxiliar ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void ManejoDeArchivo::CrearArchivoAdminisCSV(vector <PersonalAdmi> PersonalAdm) {
	ifstream Archivo ("PersonalAdmi-Laboratorio.csv") ;
	
	if(!Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("PersonalAdmi-Laboratorio.csv", ios::app) ;
	
		Archivo << "Nombre" << ';' << "Apellido" << ';' << "Email" << ';'  ;
		Archivo << "Edad" << ';' << "Cedula" << ';' << "Telefono" << '\n'   ;
		
		for (int i=0 ; i<PersonalAdm.size() ; i++) {
			Archivo << PersonalAdm[i].getNombre() << ';' << PersonalAdm[i].getApellido() << ';'  ;
			Archivo << PersonalAdm[i].getEmail() << ';' << PersonalAdm[i].getEdad() << ';'       ;
			Archivo << PersonalAdm[i].getCedula() << ';' << PersonalAdm[i].getTelefono() << '\n'  ;
		}
	}else {
		ActualizarAdimisCSV(PersonalAdm) ; 
	}
	
	Archivo.close() ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::ActualizarAdimisCSV(vector <PersonalAdmi> PersonalAdm) {
	ofstream Archivo ;
	Archivo.open("PersonalAdmi-Laboratorio.csv", ios::out) ;
	
	Archivo << "Nombre" << ';' << "Apellido" << ';' << "Email" << ';'  ;
	Archivo << "Edad" << ';' << "Cedula" << ';' << "Telefono" << '\n'   ;
		
	for (int i=0 ; i<PersonalAdm.size() ; i++) {
		Archivo << PersonalAdm[i].getNombre() << ';' << PersonalAdm[i].getApellido() << ';'  ;
		Archivo << PersonalAdm[i].getEmail() << ';' << PersonalAdm[i].getEdad() << ';'       ;
		Archivo << PersonalAdm[i].getCedula() << ';' << PersonalAdm[i].getTelefono() << '\n'  ;
	}
	
	Archivo.close() ; 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::CargarArchivoAdminisCSV(vector <PersonalAdmi>* PersonalAdm) {
	PersonalAdm->clear() ; // Eliminar por si existe algo ya en el vector

	ifstream Archivo ("PersonalAdmi-Laboratorio.csv") ;
	PersonalAdmi* PersonalAuxiliar = new PersonalAdmi ;
	string Nombre, Apellido, Email, Carrera, Edad, Cedula, Telefono ;

	if (Archivo.is_open()) {
		if(!Archivo.fail()) {
			char texto[512]  ;
			// Copiar todo a variables temporales
			Archivo.getline(texto,512, '\n') ; // Cabeceras
			while (!Archivo.eof()) {
				getline(Archivo, Nombre, ';') ;
				getline(Archivo, Apellido, ';') ;
				getline(Archivo, Email, ';') ;
				getline(Archivo, Edad, ';') ;
				getline(Archivo, Cedula, ';') ;
				getline(Archivo, Telefono, '\n') ;
	
				// Guardar lo que hay en las variables en vectores
				PersonalAuxiliar->setNombre (Nombre) ;
				PersonalAuxiliar->setApellido(Apellido) ;
				PersonalAuxiliar->setEmail(Email) ;
	
				// Variable con paso de strin a entero
				PersonalAuxiliar->setEdad(CambioStringALong (Edad)) ;
				PersonalAuxiliar->setCedula(CambioStringALong (Cedula)) ;
				PersonalAuxiliar->setTelefono(CambioStringALong (Telefono)) ;
	
				// Agregar  al vector
				PersonalAdm->push_back(*PersonalAuxiliar) ;
			}
			// Eliminar un ultimo elemento que me crea
			PersonalAdm->pop_back() ;
		}else {
			system("cls") ;
			cout << "\nExiste un fallo en los archivos de Personales de Administrativas, REVISALAS !! \n\n" ;
			system("pause") ;
			ActualizarAdimisCSV(*PersonalAdm) ;
		}		
	}

	delete PersonalAuxiliar ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void ManejoDeArchivo::CrearArchivoArticuloComputoCSV(vector <ArticuloComputo> ArticulosComputo) {
	ifstream Archivo ("Articulo-De-Computo-Laboratorio.csv") ;
	
	if (!Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Articulo-De-Computo-Laboratorio.csv", ios::app) ;
		Archivo << "Nombre" << ';' << "Marca" << ';' << "Cantidad De Articulos" << ';' << "Codigo" << ';' ;
		Archivo << "Valor De Articulo" << ';' << "Valor Actual Del Articulo" << ';' << "Estado Del Articulo" << ';' << "Estado De Disponibilidad" << ';' ;
		Archivo << "Estado De Asignacion a Profesor" << ';' << "Valor De Despreciacion" << ';' <<  "Asignado a" << ';' ;
		Archivo << "Anio" << ';' << "Mes" << ';' << "Dia" << '\n' ; 
			
		for (int i=0 ; i<ArticulosComputo.size() ; i++) {
			Archivo << ArticulosComputo[i].getIDNombre() << ';' << ArticulosComputo[i].getIDMarca() << ';' ;
			Archivo << ArticulosComputo[i].getCantidad() << ';' << ArticulosComputo[i].getCodigoArticulo() << ';' ;
			Archivo << ArticulosComputo[i].getValorArticuloInicial() << ';' << ArticulosComputo[i].getValorActualArticulo() << ';' << ArticulosComputo[i].getEstadoArticuloDeActivo() << ';' ;
			Archivo << ArticulosComputo[i].getEstadoDeLimiteDeArticulos() << ';' << ArticulosComputo[i].getEstadoDeAsignadoAProfesor() << ';' ; 
			Archivo << ArticulosComputo[i].getDespreciacion() << ';' << ArticulosComputo[i].getProfesor()->getCodigo() << ';' ;
			Archivo << ArticulosComputo[i].getFecha()->getAnio() << ';' << ArticulosComputo[i].getFecha()->getMes() << ';' << ArticulosComputo[i].getFecha()->getDia() << '\n' ;
		}
		Archivo.close() ;
	}else {
		ActualizarComputoCSV (ArticulosComputo) ; 
	}
	Archivo.close() ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::ActualizarComputoCSV(vector <ArticuloComputo> ArticulosComputo) {
	ofstream Archivo ;
	Archivo.open("Articulo-De-Computo-Laboratorio.csv", ios::out) ;
	
	Archivo << "Nombre" << ';' << "Marca" << ';' << "Cantidad De Articulos" << ';' << "Codigo" << ';' ;
	Archivo << "Valor De Articulo" << ';' << "Valor Actual Del Articulo" << ';' << "Estado Del Articulo" << ';' << "Estado De Disponibilidad" << ';' ;
	Archivo << "Estado De Asignacion a Profesor" << ';' << "Valor De Despreciacion" << ';' <<  "Asignado a" << ';' ;
	Archivo << "Anio" << ';' << "Mes" << ';' << "Dia" << '\n' ; 
	
	for (int i=0 ; i<ArticulosComputo.size() ; i++) {
		Archivo << ArticulosComputo[i].getIDNombre() << ';' << ArticulosComputo[i].getIDMarca() << ';' ;
		Archivo << ArticulosComputo[i].getCantidad() << ';' << ArticulosComputo[i].getCodigoArticulo() << ';' ;
		Archivo << ArticulosComputo[i].getValorArticuloInicial() << ';' << ArticulosComputo[i].getValorActualArticulo() << ';' << ArticulosComputo[i].getEstadoArticuloDeActivo() << ';' ;
		Archivo << ArticulosComputo[i].getEstadoDeLimiteDeArticulos() << ';' << ArticulosComputo[i].getEstadoDeAsignadoAProfesor() << ';' ; 
		Archivo << ArticulosComputo[i].getDespreciacion() << ';' << ArticulosComputo[i].getProfesor()->getCodigo() << ';' ;
		Archivo << ArticulosComputo[i].getFecha()->getAnio() << ';' << ArticulosComputo[i].getFecha()->getMes() << ';' << ArticulosComputo[i].getFecha()->getDia() << '\n' ;
	} 
	Archivo.close() ;
}


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

vector <int> ManejoDeArchivo::CargarArchivoArticuloComputoCSV(vector <ArticuloComputo>* ArticulosComputo) {
	ArticuloComputo* ArticuloAux = new ArticuloComputo ;
	
	ArticulosComputo->clear() ; 
	
	vector <int> Codigos ; 
		
	ifstream Archivo ("Articulo-De-Computo-Laboratorio.csv") ;
	
	string Datos, CodigoProfe, Codigo ;
	 
	if (Archivo.is_open()) {
		if (!Archivo.fail()) {
			char Cabezeras[512] ; // Esto es Para cabezeras
			Archivo.getline(Cabezeras,512, '\n') ; // Para copiar cabezeras y desacerlas
			while(!Archivo.eof()) {
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setIDNombre(Datos) ;
	
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setIDMarca(Datos) ;
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setCantidad (CambioStringALong (Datos)) ;
				
				getline(Archivo, Codigo, ';') ;
				ArticuloAux->setCodigoArticulo (CambioStringALong (Codigo)) ;
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setValorArticuloInicial (CambioStringALong (Datos)) ; 
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setValorActualArticulo (CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setEstadoArticuloDeActivo (CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setEstadoDeLimiteDeArticulos (CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setEstadoDeAsignadoAProfesor (CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setDespreciacion (CambioStringALong (Datos)) ; 
				
				getline(Archivo, CodigoProfe, ';') ;
	
				getline(Archivo, Datos, ';') ; 			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, '\n') ;
				
				
				Codigos.push_back(CambioStringALong (CodigoProfe)) ; 
				Codigos.push_back(CambioStringALong (Codigo)) ;
				
				ArticulosComputo->push_back(*ArticuloAux) ;   			 
			}  
			ArticulosComputo->pop_back() ; 
			Codigos.pop_back() ;
			Codigos.pop_back() ;
		}else {
			system("cls") ;
			cout << "\nExiste un fallo en los archivos de Articulos de Computo, REVISALAS !! \n\n" ;
			system("pause") ;
			ActualizarComputoCSV(*ArticulosComputo) ; 
		}
	}
	delete ArticuloAux ;
	return Codigos ;
}



///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::CargarArticuloComputoCSV(vector <Fecha>* FechasRegistradas) {
	FechasRegistradas->clear() ;
	
	Fecha* Fechas = new Fecha ;
	
	ifstream Archivo ("Articulo-De-Computo-Laboratorio.csv") ;
	
	string Datos ;
	 
	if (Archivo.is_open()) {
		if(!Archivo.fail()) {
			char Cabezeras[512] ; // Esto es Para cabezeras
			Archivo.getline(Cabezeras,512, '\n') ; // Para copiar cabezeras y desacerlas
			while(!Archivo.eof()) {
				getline(Archivo, Datos, ';') ;
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;
				getline(Archivo, Datos, ';') ;
				
				getline(Archivo, Datos, ';') ;
				Fechas->setAnio(CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, ';') ;
				Fechas->setMes(CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, '\n') ;
				Fechas->setDia(CambioStringALong (Datos)) ;
				
				FechasRegistradas->push_back(*Fechas) ;
			} 		
			FechasRegistradas->pop_back() ; 
		}else {
			system("cls") ;
			cout << "\nExiste un fallo en los archivos de Articulos de Computo, REVISALAS !! \n\n" ;
			system("pause") ;
		}		
	}
	
	delete Fechas ; 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Crear Archivo para articulos de prestamos
void ManejoDeArchivo::CrearArchivoArticuloDePrestamoCSV(vector <ArticuloDePrestamo> ArticulosParaPrestar) {
	ifstream Archivo ("Articulo-De-Prestamo-Laboratorio.csv") ;

	if (!Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Articulo-De-Prestamo-Laboratorio.csv", ios::app) ;
		Archivo << "Nombre" << ';' << "Marca" << ';' << "Cantidad De Articulos" << ';' << "Codigo" << ';' ;
		Archivo << "Valor De Articulo" << ';' << "Valor Actual Del Articulo" << ';' << "Estado Del Articulo" << ';' << "Estado De Disponibilidad" << ';' ;
		Archivo << "Estado De Asignacion a Profesor" << ';' << "Valor De Despreciacion" << ';' <<  "Asignado a" << ';' ;
		Archivo << "Anio" << ';' << "Mes" << ';' << "Dia" << '\n' ; 
		
		for (int i=0 ; i<ArticulosParaPrestar.size() ; i++) {
			Archivo << ArticulosParaPrestar[i].getIDNombre() << ';' << ArticulosParaPrestar[i].getIDMarca() << ';' ;
			Archivo << ArticulosParaPrestar[i].getCantidadDeTipoDeArticulo() << ';' << ArticulosParaPrestar[i].getCodigoArticulo() << ';' ;
			Archivo << ArticulosParaPrestar[i].getValorArticuloInicial() << ';' << ArticulosParaPrestar[i].getValorActualArticulo() << ';' << ArticulosParaPrestar[i].getEstadoArticuloDeActivo() << ';' ;
			Archivo << ArticulosParaPrestar[i].getEstadoDeLimiteDeArticulos() << ';' << ArticulosParaPrestar[i].getEstadoDeAsignadoAProfesor() << ';' ; 
			Archivo << ArticulosParaPrestar[i].getDespreciacion() << ';' << ArticulosParaPrestar[i].getProfesor()->getCodigo() << ';' ;
			Archivo << ArticulosParaPrestar[i].getFecha()->getAnio() << ';' << ArticulosParaPrestar[i].getFecha()->getMes() << ';' << ArticulosParaPrestar[i].getFecha()->getDia() << '\n' ;
		}
		Archivo.close() ;
	}else {
		ActualizarArchivoArticuloDePrestamoCSV(ArticulosParaPrestar) ;
	}
	
	Archivo.close() ;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::ActualizarArchivoArticuloDePrestamoCSV(vector <ArticuloDePrestamo> ArticulosParaPrestar) {
	
	ofstream Archivo ;
	
	Archivo.open("Articulo-De-Prestamo-Laboratorio.csv", ios::out) ;
	
	Archivo << "Nombre" << ';' << "Marca" << ';' << "Cantidad De Articulos" << ';' << "Codigo" << ';' ;
	Archivo << "Valor De Articulo" << ';' << "Valor Actual Del Articulo" << ';' << "Estado Del Articulo" << ';' << "Estado De Disponibilidad" << ';' ;
	Archivo << "Estado De Asignacion a Profesor" << ';' << "Valor De Despreciacion" << ';' <<  "Asignado a" << ';' ;
	Archivo << "Anio" << ';' << "Mes" << ';' << "Dia" << '\n' ; 
	
	for (int i=0 ; i<ArticulosParaPrestar.size() ; i++) {
		Archivo << ArticulosParaPrestar[i].getIDNombre() << ';' << ArticulosParaPrestar[i].getIDMarca() << ';' ;
		Archivo << ArticulosParaPrestar[i].getCantidadDeTipoDeArticulo() << ';' << ArticulosParaPrestar[i].getCodigoArticulo() << ';' ;
		Archivo << ArticulosParaPrestar[i].getValorArticuloInicial() << ';' << ArticulosParaPrestar[i].getValorActualArticulo() << ';' << ArticulosParaPrestar[i].getEstadoArticuloDeActivo() << ';' ;
		Archivo << ArticulosParaPrestar[i].getEstadoDeLimiteDeArticulos() << ';' << ArticulosParaPrestar[i].getEstadoDeAsignadoAProfesor() << ';' ; 
		Archivo << ArticulosParaPrestar[i].getDespreciacion() << ';' << ArticulosParaPrestar[i].getProfesor()->getCodigo() << ';' ;
		Archivo << ArticulosParaPrestar[i].getFecha()->getAnio() << ';' << ArticulosParaPrestar[i].getFecha()->getMes() << ';' << ArticulosParaPrestar[i].getFecha()->getDia() << '\n' ;
	}
	Archivo.close() ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector <int> ManejoDeArchivo::CargarArchivoArticuloDePrestamoCSV(vector <ArticuloDePrestamo>* ArticulosParaPrestar) {
	ArticuloDePrestamo* ArticuloAux = new ArticuloDePrestamo ; 
	vector <int> Codigos ; 
	
	ArticulosParaPrestar->clear() ;

	ifstream Archivo ("Articulo-De-Prestamo-Laboratorio.csv") ;

	string Datos, CodigoProfe, Codigo ;
	 
	if (Archivo.is_open()) {
		if(!Archivo.fail()) {
			char Cabezeras[512] ; // Esto es Para cabezeras
			Archivo.getline(Cabezeras,512, '\n') ; // Para copiar cabezeras y desacerlas
			while(!Archivo.eof()) {
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setIDNombre(Datos) ;
	
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setIDMarca(Datos) ;
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setCantidadDeTipoDeArticulo (CambioStringALong (Datos)) ;
				
				getline(Archivo, Codigo, ';') ;
				ArticuloAux->setCodigoArticulo (CambioStringALong (Codigo)) ;
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setValorArticuloInicial (CambioStringALong (Datos)) ; 
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setValorActualArticulo (CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setEstadoArticuloDeActivo (CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setEstadoDeLimiteDeArticulos (CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setEstadoDeAsignadoAProfesor (CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setDespreciacion (CambioStringALong (Datos)) ; 
				
				getline(Archivo, CodigoProfe, ';') ;
				
				getline(Archivo, Datos, ';') ; 			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, '\n') ;
				
				
				Codigos.push_back(CambioStringALong (CodigoProfe)) ;
				Codigos.push_back(CambioStringALong (Codigo)) ;
				
				// Agregat al Vector
				ArticulosParaPrestar->push_back(*ArticuloAux) ;   			
			}
			ArticulosParaPrestar->pop_back() ;  
			Codigos.pop_back() ;
			Codigos.pop_back() ;
		}else {
			system("cls") ;
			cout << "\nExiste un fallo en los archivos de Articulos de Prestamos, REVISALAS !! \n\n" ;
			system("pause") ;
			ActualizarArchivoArticuloDePrestamoCSV(*ArticulosParaPrestar) ; 
		}		
	}
	delete ArticuloAux ;
	return Codigos ;	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::CargarArticuloDePrestamoCSV(vector <Fecha>* FechasRegistradas) {
	FechasRegistradas->clear() ;
	
	Fecha* Fechas = new Fecha ;
	
	ifstream Archivo ("Articulo-De-Prestamo-Laboratorio.csv") ;
	
	string Datos ;
	 
	if (Archivo.is_open()) {
		if(!Archivo.fail()) {
			char Cabezeras[512] ; // Esto es Para cabezeras
			Archivo.getline(Cabezeras,512, '\n') ; // Para copiar cabezeras y desacerlas
			while(!Archivo.eof()) {
				getline(Archivo, Datos, ';') ;
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;
				getline(Archivo, Datos, ';') ;
				
				getline(Archivo, Datos, ';') ;
				Fechas->setAnio(CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, ';') ;
				Fechas->setMes(CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, '\n') ;
				Fechas->setDia(CambioStringALong (Datos)) ;
				
				FechasRegistradas->push_back(*Fechas) ;
			} 		
			FechasRegistradas->pop_back() ; 
		}else {
			system("cls") ;
			cout << "\nExiste un fallo en los archivos de Articulos de Prestamos, REVISALAS !! \n\n" ;
			system("pause") ;
		}		
	}
	delete Fechas ; 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::CrearArchivoArticuloMuebleCSV(vector <ArticuloMueble> ArticulosParaMueble) {
	ifstream Archivo ("Articulo-De-Mueble-Laboratorio.csv") ;
	
	if (!Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Articulo-De-Mueble-Laboratorio.csv", ios::app) ;
		Archivo << "Nombre" << ';' << "Material" << ';' << "Cantidad De Articulos" << ';' << "Codigo" << ';' ;
		Archivo << "Valor De Articulo" << ';' << "Valor Actual Del Articulo" << ';' << "Estado Del Articulo" << ';' << "Estado De Disponibilidad" << ';' ;
		Archivo << "Estado De Asignacion a Profesor" << ';' << "Valor De Despreciacion" << ';' <<  "Asignado a" << ';' ;
		Archivo << "Anio" << ';' << "Mes" << ';' << "Dia" << '\n' ; 
	
		for (int i=0 ; i<ArticulosParaMueble.size() ; i++) {
			Archivo << ArticulosParaMueble[i].getIDNombre() << ';' << ArticulosParaMueble[i].getMaterial() << ';' ;
			Archivo << ArticulosParaMueble[i].getCantidad() << ';' << ArticulosParaMueble[i].getCodigoArticulo() << ';' ;
			Archivo << ArticulosParaMueble[i].getValorArticuloInicial() << ';' << ArticulosParaMueble[i].getValorActualArticulo() << ';' << ArticulosParaMueble[i].getEstadoArticuloDeActivo() << ';' ;
			Archivo << ArticulosParaMueble[i].getEstadoDeLimiteDeArticulos() << ';' << ArticulosParaMueble[i].getEstadoDeAsignadoAProfesor() << ';' ; 
			Archivo << ArticulosParaMueble[i].getDespreciacion() << ';' << ArticulosParaMueble[i].getProfesorAsignado()->getCodigo() << ';' ;
			Archivo << ArticulosParaMueble[i].getFecha()->getAnio() << ';' << ArticulosParaMueble[i].getFecha()->getMes() << ';' << ArticulosParaMueble[i].getFecha()->getDia() << '\n' ;
		}
		Archivo.close() ;
	}else {
		ActualizarMuebleCSV(ArticulosParaMueble) ;
	}
	Archivo.close() ;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void ManejoDeArchivo::ActualizarMuebleCSV(vector <ArticuloMueble> ArticulosParaMueble) {
	ofstream Archivo ;
	Archivo.open("Articulo-De-Mueble-Laboratorio.csv", ios::out) ;
	Archivo << "Nombre" << ';' << "Material" << ';' << "Cantidad De Articulos" << ';' << "Codigo" << ';' ;
	Archivo << "Valor De Articulo" << ';' << "Valor Actual Del Articulo" << ';' << "Estado Del Articulo" << ';' << "Estado De Disponibilidad" << ';' ;
	Archivo << "Estado De Asignacion a Profesor" << ';' << "Valor De Despreciacion" << ';' <<  "Asignado a" << ';' ;
	Archivo << "Anio" << ';' << "Mes" << ';' << "Dia" << '\n' ;
	
	for (int i=0 ; i<ArticulosParaMueble.size() ; i++) {
		Archivo << ArticulosParaMueble[i].getIDNombre() << ';' << ArticulosParaMueble[i].getMaterial() << ';' ;
		Archivo << ArticulosParaMueble[i].getCantidad() << ';' << ArticulosParaMueble[i].getCodigoArticulo() << ';' ;
		Archivo << ArticulosParaMueble[i].getValorArticuloInicial() << ';' << ArticulosParaMueble[i].getValorActualArticulo() << ';' << ArticulosParaMueble[i].getEstadoArticuloDeActivo() << ';' ;
		Archivo << ArticulosParaMueble[i].getEstadoDeLimiteDeArticulos() << ';' << ArticulosParaMueble[i].getEstadoDeAsignadoAProfesor() << ';' ; 
		Archivo << ArticulosParaMueble[i].getDespreciacion() << ';' << ArticulosParaMueble[i].getProfesorAsignado()->getCodigo() << ';' ;
		Archivo << ArticulosParaMueble[i].getFecha()->getAnio() << ';' << ArticulosParaMueble[i].getFecha()->getMes() << ';' << ArticulosParaMueble[i].getFecha()->getDia() << '\n' ;
	}
	Archivo.close() ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector <int> ManejoDeArchivo::CargarArchivoArticuloMuebleCSV(vector <ArticuloMueble>* ArticulosParaMueble) {
	ArticuloMueble* ArticuloAux = new ArticuloMueble ;
	vector <int> Codigos ; 
	
	ArticulosParaMueble->clear() ;

	ifstream Archivo ("Articulo-De-Mueble-Laboratorio.csv") ;

	string Datos, CodigoProfe, Codigo ;
	 
	if (Archivo.is_open()) {
		if(!Archivo.fail()) {
			char Cabezeras[512] ; // Esto es Para cabezeras
			Archivo.getline(Cabezeras,512, '\n') ; // Para copiar cabezeras y desacerlas
			while(!Archivo.eof()) {
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setIDNombre(Datos) ;
	
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setMaterial(Datos) ;
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setCantidad (CambioStringALong (Datos)) ;
				
				getline(Archivo, Codigo, ';') ;
				ArticuloAux->setCodigoArticulo (CambioStringALong (Codigo)) ;
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setValorArticuloInicial (CambioStringALong (Datos)) ; 
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setValorActualArticulo (CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setEstadoArticuloDeActivo (CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setEstadoDeLimiteDeArticulos (CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setEstadoDeAsignadoAProfesor (CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, ';') ;
				ArticuloAux->setDespreciacion (CambioStringALong (Datos)) ; 
				
				getline(Archivo, CodigoProfe, ';') ;
				
				getline(Archivo, Datos, ';') ; 			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, '\n') ;
				
				Codigos.push_back(CambioStringALong (CodigoProfe)) ;
				Codigos.push_back(CambioStringALong (Codigo)) ;
				
				// Agregat al Vector
				ArticulosParaMueble->push_back(*ArticuloAux) ;   			
			}		
			ArticulosParaMueble->pop_back() ;  
			Codigos.pop_back() ;
			Codigos.pop_back() ;
		}else {
			system("cls") ;
			cout << "\nExiste un fallo en los archivos de Articulos de Muebles, REVISALAS !! \n\n" ;
			system("pause") ;
			ActualizarMuebleCSV(*ArticulosParaMueble) ;
		}		
	}
	delete ArticuloAux ;
	return Codigos ;
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::CargarArticuloMuebleCSV(vector <Fecha>* FechasRegistradas) {
	FechasRegistradas->clear() ;
	
	Fecha* Fechas = new Fecha ;
	
	ifstream Archivo ("Articulo-De-Mueble-Laboratorio.csv") ;
	
	string Datos ;
	 
	if (Archivo.is_open()) {
		if(!Archivo.fail()) {
			char Cabezeras[512] ; // Esto es Para cabezeras
			Archivo.getline(Cabezeras,512, '\n') ; // Para copiar cabezeras y desacerlas
			while(!Archivo.eof()) {
				getline(Archivo, Datos, ';') ;
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;
				getline(Archivo, Datos, ';') ;
				
				getline(Archivo, Datos, ';') ;
				Fechas->setAnio(CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, ';') ;
				Fechas->setMes(CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, '\n') ;
				Fechas->setDia(CambioStringALong (Datos)) ;
				
				FechasRegistradas->push_back(*Fechas) ;
			} 		
			FechasRegistradas->pop_back() ; 
		}else {
			system("cls") ;
			cout << "\nExiste un fallo en los archivos de Articulos de Muebles, REVISALAS !! \n\n" ;
			system("pause") ;
		}		
	}
	delete Fechas ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::HistorialPrestamoCSV(vector <Estudiante> EstudiantePrestamo) {
	
	ifstream Archivo ("Historial-Articulos-Prestados.csv") ;
	
	if (!Archivo.is_open()) {
		ofstream Archivo ;
	
		Archivo.open("Historial-Articulos-Prestados.csv", ios::out)	 ;
		
		Archivo << "Codigo del Estudiante" << ';' << "Nombre del estudiante" << ';' << "Nombre del Articulo" << ';' ;
		Archivo << "Codigo del Articulo" << ';' << "Anio" << ';' << "Mes" << ';' << "Dia" << '\n' ; 
		
		for (int i=0 ; i<EstudiantePrestamo.size() ; i++) {
			for (int j=0 ; j<EstudiantePrestamo[i].MisArticulos().size() ; j++) {
				Archivo << EstudiantePrestamo[i].getCodigo() << ';' << EstudiantePrestamo[i].getNombre() << ';' ;
				Archivo << EstudiantePrestamo[i].MisArticulos()[j]->getIDNombre() << ';' << EstudiantePrestamo[i].MisArticulos()[j]->getCodigoArticulo() << ';' ;
				Archivo << EstudiantePrestamo[i].MisArticulos()[j]->getFecha()->getAnio() << ';' << EstudiantePrestamo[i].MisArticulos()[j]->getFecha()->getMes() << ';' ;
				Archivo << EstudiantePrestamo[i].MisArticulos()[j]->getFecha()->getDia() << '\n' ;  
			} 	
		}
	}else {
		ActualizarHistorial(EstudiantePrestamo) ; 
	}
	Archivo.close() ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void ManejoDeArchivo::ActualizarHistorial(vector <Estudiante> EstudiantePrestamo) {
	ofstream Archivo ;
	
	Archivo.open("Historial-Articulos-Prestados.csv", ios::out)	 ;
		
	Archivo << "Codigo del Estudiante" << ';' << "Nombre del estudiante" << ';' << "Nombre del Articulo" << ';' ;
	Archivo << "Codigo del Articulo" << ';' << "Anio" << ';' << "Mes" << ';' << "Dia" << '\n' ; 
	
	for (int i=0 ; i<EstudiantePrestamo.size() ; i++) {
		for (int j=0 ; j<EstudiantePrestamo[i].MisArticulos().size() ; j++) {
			Archivo << EstudiantePrestamo[i].getCodigo() << ';' << EstudiantePrestamo[i].getNombre() << ';' ;
			Archivo << EstudiantePrestamo[i].MisArticulos()[j]->getIDNombre() << ';' << EstudiantePrestamo[i].MisArticulos()[j]->getCodigoArticulo() << ';' ;
			Archivo << EstudiantePrestamo[i].MisArticulos()[j]->getFecha()->getAnio() << ';' << EstudiantePrestamo[i].MisArticulos()[j]->getFecha()->getMes() << ';' ;
			Archivo << EstudiantePrestamo[i].MisArticulos()[j]->getFecha()->getDia() << '\n' ;  
		} 	
	}
	Archivo.close() ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void ManejoDeArchivo::CargarHistorialPrestamo(vector <Estudiante>* Estudiantes) {

	string NroCodigos, IDNombres, DatosFecha ;
	Fecha* FechaGuardar = new Fecha ;
	vector <Fecha> FechaAux ;
	Estudiante* Auxiliar = new Estudiante ; 
	vector <Estudiante> EstuAuxiliar ;
	ArticuloDePrestamo* Prestamos = new ArticuloDePrestamo ;
	vector <ArticuloDePrestamo> PrestaAux ;
	
	ifstream Archivo("Historial-Articulos-Prestados.csv") ;
	
	if (Archivo.is_open()) {
		if(!Archivo.fail()) {
			char Cabezeras[512] ; // Esto es Para cabezeras
			Archivo.getline(Cabezeras,512, '\n') ; // Para copiar cabezeras y desacerlas
			while(!Archivo.eof()) {
				getline(Archivo, NroCodigos, ';') ;
				Auxiliar->setCodigo(CambioStringALong (NroCodigos)) ;
				
				getline(Archivo, IDNombres, ';') ;
				Auxiliar->setNombre(IDNombres) ;
				
				getline(Archivo, IDNombres, ';') ; 						
				getline(Archivo, NroCodigos, ';') ;
				getline(Archivo, DatosFecha, ';') ;
				getline(Archivo, DatosFecha, ';') ;
				getline(Archivo, DatosFecha, '\n') ;
			
				Estudiantes->push_back(*Auxiliar) ; 
			}	
			Estudiantes->pop_back() ;
		}else {
			system("cls") ;
			cout << "\nExiste un fallo en los archivos de Historiales, REVISALAS !! \n\n" ;
			system("pause") ;
			ActualizarHistorial(*Estudiantes) ;
		}		
	}
	Archivo.close() ; 
	
	delete Auxiliar ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::CargarHistorialPrestamo(vector <ArticuloDePrestamo>* Prestamos) {
	
	Prestamos->clear() ;
	ArticuloDePrestamo* Auxiliar = new ArticuloDePrestamo ; 
	
	ifstream Archivo ("Historial-Articulos-Prestados.csv") ;
	
	string Datos ;
	 
	if (Archivo.is_open()) {
		if(!Archivo.fail()) {
			char Cabezeras[512] ; // Esto es Para cabezeras
			Archivo.getline(Cabezeras,512, '\n') ; // Para copiar cabezeras y desacerlas
			while(!Archivo.eof()) {
				getline(Archivo, Datos, ';') ;
				getline(Archivo, Datos, ';') ;
							
				getline(Archivo, Datos, ';') ;			
				Auxiliar->setIDNombre(Datos) ;
				
				getline(Archivo, Datos, ';') ;
				Auxiliar->setCodigoArticulo(CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, ';') ;	
				getline(Archivo, Datos, ';') ;					
				getline(Archivo, Datos, '\n') ;
				
				Prestamos->push_back(*Auxiliar) ;
			} 		
			Prestamos->pop_back() ; 
		}else {
			system("cls") ;
			cout << "\nExiste un fallo en los archivos de Historiales, REVISALAS !! \n\n" ;
			system("pause") ;
		}		
	}
	delete Auxiliar ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::CargarHistorialPrestamo(vector <Fecha>* FechaHistorial) {
	
	FechaHistorial->clear() ;
	
	Fecha* Fechas = new Fecha ;
	
	ifstream Archivo ("Historial-Articulos-Prestados.csv") ;
	
	string Datos ;
	 
	if (Archivo.is_open()) {
		if(!Archivo.fail()) {
			char Cabezeras[512] ; // Esto es Para cabezeras
			Archivo.getline(Cabezeras,512, '\n') ; // Para copiar cabezeras y desacerlas
			while(!Archivo.eof()) {
				getline(Archivo, Datos, ';') ;
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;			
				getline(Archivo, Datos, ';') ;
				
				getline(Archivo, Datos, ';') ;
				Fechas->setAnio(CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, ';') ;
				Fechas->setMes(CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, '\n') ;
				Fechas->setDia(CambioStringALong (Datos)) ;
				
				FechaHistorial->push_back(*Fechas) ;
			} 		
			FechaHistorial->pop_back() ; 
		}else {
			system("cls") ;
			cout << "\nExiste un fallo en los archivos de Historiales, REVISALAS !! \n\n" ;
			system("pause") ;
		}		
	}
	delete Fechas ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::CrearPlazoEntrega(vector <Estudiante> EstudiantePlazo) {
	ifstream Archivo("Plazo-De-Prestamos.csv") ;
	
	if (!Archivo.is_open()) {
		ofstream Archivo ;
		
		Archivo.open("Plazo-De-Prestamos.csv", ios::app) ;
		
		Archivo << "Codigo Estudiante" << ';' << "Codigo del Articulo" << ';' << "Año" << ';' << "Mes" << ';' << "Dia" << '\n' ;
		
		for (int i=0 ; i<EstudiantePlazo.size() ; i++) {
			for (int j=0 ; j<EstudiantePlazo[i].MisArticulos().size() ; j++) {
				Archivo << EstudiantePlazo[i].getCodigo() << ';' <<  EstudiantePlazo[i].MisArticulos()[j]->getCodigoArticulo() <<  ';' ;
				Archivo << EstudiantePlazo[i].MisArticulos()[j]->MostrarFecha()->getAnio() << ';' << EstudiantePlazo[i].MisArticulos()[j]->MostrarFecha()->getMes() << ';' << EstudiantePlazo[i].MisArticulos()[j]->MostrarFecha()->getDia() << '\n' ; 
			}
		}
	}else {
		ActualizarPlazos(EstudiantePlazo) ;
	}
	Archivo.close() ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void ManejoDeArchivo::ActualizarPlazos(vector <Estudiante> EstudiantePlazo) {
	ofstream Archivo ;
		
	Archivo.open("Plazo-De-Prestamos.csv", ios::out) ;
		
	Archivo << "Codigo Estudiante" << ';' << "Codigo del Articulo" << ';' << "Año" << ';' << "Mes" << ';' << "Dia" << '\n' ;
		
	for (int i=0 ; i<EstudiantePlazo.size() ; i++) {
			for (int j=0 ; j<EstudiantePlazo[i].MisArticulos().size() ; j++) {
				Archivo << EstudiantePlazo[i].getCodigo() << ';' <<  EstudiantePlazo[i].MisArticulos()[j]->getCodigoArticulo() <<  ';' ;
					Archivo << EstudiantePlazo[i].MisArticulos()[j]->MostrarFecha()->getAnio() << ';' << EstudiantePlazo[i].MisArticulos()[j]->MostrarFecha()->getMes() << ';' << EstudiantePlazo[i].MisArticulos()[j]->MostrarFecha()->getDia() << '\n' ; 
			}
		}
	Archivo.close() ; 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::CargarPlazos(vector <Estudiante>* EstudianteAux) {
	
	EstudianteAux->clear() ;
	
	string NroCodigos, IDNombres, DatosFecha ;
	Estudiante* Auxiliar = new Estudiante ; 
	

	ifstream Archivo ("Plazo-De-Prestamos.csv") ; 
	
	if (Archivo.is_open()) {
		if(!Archivo.fail()) {
			char Cabezeras[512] ; // Esto es Para cabezeras
			Archivo.getline(Cabezeras,512, '\n') ; // Para copiar cabezeras y desacerlas
			while(!Archivo.eof()) {
				getline(Archivo, NroCodigos, ';') ;
				Auxiliar->setCodigo(CambioStringALong (NroCodigos)) ;
			
				getline(Archivo, NroCodigos, ';') ;
				getline(Archivo, DatosFecha, ';') ;
				getline(Archivo, DatosFecha, ';') ;				
				getline(Archivo, DatosFecha, '\n') ;
				
				EstudianteAux->push_back(*Auxiliar) ; ;
			}
			EstudianteAux->pop_back() ;
		}else {
			system("cls") ;
			cout << "\nExiste un fallo en los archivos de Plazo de Articulos, REVISALAS !! \n\n" ;
			system("pause") ;
			ActualizarPlazos(*EstudianteAux) ;
		}		
	}
	
	delete Auxiliar ; 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::CargarPlazos(vector <ArticuloDePrestamo>* PrestamosAux) {
	
	PrestamosAux->clear() ;
	
	string NroCodigos, IDNombres, DatosFecha ;
	ArticuloDePrestamo* Prestamos = new ArticuloDePrestamo ;
	

	ifstream Archivo ("Plazo-De-Prestamos.csv") ; 
	
	if (Archivo.is_open()) {
		if(!Archivo.fail()) {
			char Cabezeras[512] ; // Esto es Para cabezeras
			Archivo.getline(Cabezeras,512, '\n') ; // Para copiar cabezeras y desacerlas
			while(!Archivo.eof()) {
				getline(Archivo, NroCodigos, ';') ;
				getline(Archivo, NroCodigos, ';') ;
				Prestamos->setCodigoArticulo(CambioStringALong (NroCodigos)) ;
				
				getline(Archivo, DatosFecha, ';') ;
				getline(Archivo, DatosFecha, ';') ;				
				getline(Archivo, DatosFecha, '\n') ;
				
				PrestamosAux->push_back(*Prestamos) ; 
			}
			PrestamosAux->pop_back() ;	
		}else {
			system("cls") ;
			cout << "\nExiste un fallo en los archivos de Plazo de Articulos, REVISALAS !! \n\n" ;
			system("pause") ;
		}		
	}
	
	delete Prestamos ; 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::CargarPlazos(vector <Fecha>* FechasRegistradas) {
	FechasRegistradas->clear() ;
	
	Fecha* Fechas = new Fecha ;
	
	ifstream Archivo ("Plazo-De-Prestamos.csv") ;
	
	string Datos ;
	 
	if (Archivo.is_open()) {
		if(!Archivo.fail()) {
			char Cabezeras[512] ; // Esto es Para cabezeras
			Archivo.getline(Cabezeras,512, '\n') ; // Para copiar cabezeras y desacerlas
			while(!Archivo.eof()) {
				getline(Archivo, Datos, ';') ;
				getline(Archivo, Datos, ';') ;			
			
				getline(Archivo, Datos, ';') ;
				Fechas->setAnio(CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, ';') ;
				Fechas->setMes(CambioStringALong (Datos)) ;
				
				getline(Archivo, Datos, '\n') ;
				Fechas->setDia(CambioStringALong (Datos)) ;
				
				FechasRegistradas->push_back(*Fechas) ;
			} 		
			FechasRegistradas->pop_back() ; 
		}else {
			system("cls") ;
			cout << "\nExiste un fallo en los archivos de Plazo de Articulos, REVISALAS !! \n\n" ;
			system("pause") ;
		}		
	}
	delete Fechas ;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Funcion para Cambiar el dato de string -> long
float ManejoDeArchivo::CambioStringALong(string Temporal) {

	stringstream geek(Temporal);
	float CambioDeDato ;
	geek >> CambioDeDato ;

	return CambioDeDato ;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////// ////////////////////////////////////////////////////////////////////////////

// DESTRUCTOR
ManejoDeArchivo::~ManejoDeArchivo() {
}
