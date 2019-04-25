#include "Laboratorio.h"

// CONSTRUCTOR
Laboratorio::Laboratorio() {
	
	//          Mi fecha de creacion (Fecha Base)      //
	
	this->FechaInicio->setAnio(2019) ;
	this->FechaInicio->setMes(01) ;
	this->FechaInicio->setDia(01) ; 
}

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

//                            Auxiliares para la Aplicacion                         		   //

//vector <int*> CodigosDeEstudiantes ; 					// Asignar codigo si ha ingresado datos correctos --- Detallar bien si es necesaria ----
vector <Estudiante> ParaHistoriales ; 					// Vector auxiliar de estudiantes para almacenar historiales
vector <Estudiante> ParaPlazos ;						//  Vector auxiliar para agregarle a los articulos prestados de los estudiante una fecha limite de entrega
vector <ArticuloDePrestamo> ArticuloHistorial ; 		// Vector de articulos auxiliar para cargar los historiales
vector <ArticuloDePrestamo> ArticuloParaPlazos ; 		// Vector de articulos auxiliar para cargar los plazos 
vector <Fecha> ParaFechasPlazo ; 						// Vector de Fechas para almacenar las fechas limite de entrega
vector <Fecha> FechasHistoriales ; 						// Vector de fechas para almacenar las fechas de los prestamos
Fecha* FechaActual = new Fecha ; 						// Para indicar la fecha actual 


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

// Mostrar todo el vector de profesores
void Laboratorio::getProfesores(){
	system("cls") ;
	for (int i=0 ; i<this->Profesores.size() ; i++) {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
		cout << "\n\tPROFESOR	" << i+1 << "\n\n" ;
		cout << "-NOMBRE :		" << Profesores[i].getNombre() << "\n" ;
		cout << "-APELLIDO :		" << Profesores[i].getApellido() << "\n" ;
		cout << "-EMAIL: 		" << Profesores[i].getEmail() << "\n" ;
		cout << "-EDAD: 			" << Profesores[i].getEdad() << "\n" ;
		cout << "-CEDULA: 		" << Profesores[i].getCedula() << "\n" ;
		cout << "-TELEFONO: 		" << Profesores[i].getTelefono() << "\n" ;
		cout << "-TITULO:		" << Profesores[i].getTituloProfesional() << "\n" ;
		cout << "-CODIGO:		" << Profesores[i].getCodigo() << "\n" ;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

// Mostrar todo el vector de estudiantes
void Laboratorio::getEstudiantes() {
	system("cls") ;
	for (int i=0 ; i<this->Estudiantes.size() ; i++) {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
		cout << "\n\tESTUDIANTE " << i+1 << "\n\n" ;
		cout << "-NOMBRE:			" << Estudiantes[i].getNombre() << "\n" ;
		cout << "-APELLIDO:			" << Estudiantes[i].getApellido() << "\n" ;
		cout << "-EMAIL:				" << Estudiantes[i].getEmail() << "\n" ;
		cout << "-EDAD:				" << Estudiantes[i].getEdad() << "\n" ;
		cout << "-CEDULA:			" << Estudiantes[i].getCedula() << "\n" ;
		cout << "-TELEFONO:			" << Estudiantes[i].getTelefono() << "\n" ;
		cout << "-CARRERA:			" << Estudiantes[i].getCarrera() << "\n" ;
		cout << "-CODIGO:			" << Estudiantes[i].getCodigo() << "\n" ;
		cout << "-SEMESTRE:			" << Estudiantes[i].getSemestre() << "\n" ;
		cout << "-MULTA ACUMULADA: 		" << Estudiantes[i].getValorMultaAcomulada() << "\n" ;
		cout << "-ESTADO MULTA:			" << Estudiantes[i].getEstadoDeMulta()<< "\n" ;
		cout << "-ESTADO ESTUDIANTE:		" << Estudiantes[i].getEstadoDeEstudiante() << "\n" ;
		if (this->Estudiantes[i].MisArticulos().empty()) {
			cout << "ARTICULOS PRESTADOS:" << 0 << "\n\n" ;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
		} else {
			for (int j=0 ; j<this->Estudiantes[i].MisArticulos().size() ; j++) {
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
				cout << "CODIGO DE ARTICULO PRESTADO #"<< j+1 << ":" << this->Estudiantes[i].MisArticulos()[j]->getCodigoArticulo() << "\n\n" ;
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::getEstudianteYPrestados() {
	system("cls") ;
	for (int i=0 ; i<this->Estudiantes.size() ; i++) {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
		cout << "\n\tESTUDIANTE " << i+1 << "\n\n" ;
		cout << "-NOMBRE:			" << Estudiantes[i].getNombre() << "\n" ;
		cout << "-APELLIDO:			" << Estudiantes[i].getApellido() << "\n" ;
		cout << "-EMAIL:				" << Estudiantes[i].getEmail() << "\n" ;
		cout << "-EDAD:				" << Estudiantes[i].getEdad() << "\n" ;
		cout << "-CEDULA:			" << Estudiantes[i].getCedula() << "\n" ;
		cout << "-TELEFONO:			" << Estudiantes[i].getTelefono() << "\n" ;
		cout << "-CARRERA:			" << Estudiantes[i].getCarrera() << "\n" ;
		cout << "-CODIGO:			" << Estudiantes[i].getCodigo() << "\n" ;
		cout << "-SEMESTRE:			" << Estudiantes[i].getSemestre() << "\n" ;
		cout << "-MULTA ACUMULADA: 		" << Estudiantes[i].getValorMultaAcomulada() << "\n" ;
		cout << "-ESTADO MULTA:			" << Estudiantes[i].getEstadoDeMulta()<< "\n" ;
		cout << "-ESTADO ESTUDIANTE:		" << Estudiantes[i].getEstadoDeEstudiante() << "\n" ;
		if (this->Estudiantes[i].MisArticulos().empty()) {
			cout << "ARTICULOS PRESTADOS:" << 0 << "\n\n" ;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
		} else {			
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
			this->Estudiantes[i].MostrarTodosLosArticulos() ;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

// Mostrar todo el vector de personal administrativo
void Laboratorio::getPersonalAdmin(){
	system("cls") ;
	for (int i=0 ; i<this->PersonalAdmin.size() ; i++) {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
		cout << "\n\tPERSONAL ADMINISTRATIVO  " << i+1 << "\n\n" ;
		cout << "1.NOMBRE:		" << PersonalAdmin[i].getNombre() << "\n" ;
		cout << "2.APELLIDO:		" << PersonalAdmin[i].getApellido() << "\n" ;
		cout << "3.EMAIL:		" << PersonalAdmin[i].getEmail() << "\n" ;
		cout << "4.EDAD: 		" << PersonalAdmin[i].getEdad() << "\n" ;
		cout << "5.CEDULA: 		" << PersonalAdmin[i].getCedula() << "\n" ;
		cout << "6.TELEFONO: 		" << PersonalAdmin[i].getTelefono() << "\n" ;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::getInformaciones() {
	
	system("cls") ;
	
	cout << "\n\t<INFORMACION DISPONIBLE DEL LABORATORIO> \n\n\n" ;
	for (int i=1 ; i<this->Informaciones.size() ; i++) { 
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
		cout << i << ". " << Informaciones[i].getNombreDeInfo() << ": \n" ;
		cout <<     Informaciones[i].getContenidoDeInfo() << "\n" ;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ; 
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::getComputo() {
	system("cls") ;
	cout << "\n\tARTICULOS DE COMPUTO DISPONIBLES \n\n\n" ;
	
	for (int i=0 ; i<this->ArticulosComp.size() ; i++) {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
		cout << "\t ARTICULO #" << i+1 << "\n\n" ;
		cout << "1.NOMBRE:			" << ArticulosComp[i].getIDNombre() << "\n" ;
		cout << "2.MARCA:			" << ArticulosComp[i].getIDMarca() << "\n" ;
		cout << "3.CANTIDAD:			" << ArticulosComp[i].getCantidad() << "\n" ;
		cout << "4.CODIGO:			" << ArticulosComp[i].getCodigoArticulo() << "\n" ;
		cout << "4.VALOR:			" << ArticulosComp[i].getValorArticuloInicial() << "\n" ;  // -> VALOR CON EL QUE INGRESA AL LABORATORIO...
		cout << "5.VALOR ACTUAL:			" << ArticulosComp[i].getValorActualArticulo() << "\n" ; // -> VALOR QUE VA TOMANDO DEPUES DEL TIEMPO...
		cout << "6.Estado:			" << ArticulosComp[i].getEstadoArticuloDeActivo() << "\n" ;
		cout << "7.DISPONIBILIDAD:		" << ArticulosComp[i].getEstadoDeLimiteDeArticulos() << "\n" ; // FUNCION PARA AVERIGUAR SI HAY MAS DISPONIBLES DE ESTA REFERENCIA...
		cout << "9.ESTADO DE ASIGNACION: " << ArticulosComp[i].getEstadoDeAsignadoAProfesor() << "\n" ;
		cout << "10.VALOR DE DESPRECIACION: " << ArticulosComp[i].getDespreciacion() << "\n" ;
		cout << "11.ASIGNADO AL PROFESOR: " << ArticulosComp[i].getProfesor()->getNombre() << "\n" ;
		cout << "   CODIGO DEL PROFESOR: " << ArticulosComp[i].getProfesor()->getCodigo() << "\n" ;
		cout << "12.Fecha: " << ArticulosComp[i].getFecha()->getAnio() << "/" ;
		cout << ArticulosComp[i].getFecha()->getMes() << "/" << ArticulosComp[i].getFecha()->getDia() << "\n" ;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::getMuebles() {
	system("cls") ;
	cout << "\n\tArticulos de Mueble disponibles \n\n\n" ;
	for (int i=0 ; i<this->ArticulosMuebles.size() ; i++) {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
		cout << "\t Articulo #" << i+1 << "\n\n" ;
		cout << "1.NOMBRE:			" << ArticulosMuebles[i].getIDNombre() << "\n" ;
		cout << "2.MATERIAL:			" << ArticulosMuebles[i].getMaterial() << "\n" ;
		cout << "3.CANTIDAD: 			" << ArticulosMuebles[i].getCantidad() << "\n" ;
		cout << "4.CODIGO: 			" << ArticulosMuebles[i].getCodigoArticulo() << "\n" ;
		cout << "5.VALOR: 			" << ArticulosMuebles[i].getValorArticuloInicial() << "\n" ; 
		cout << "6.VALOR ACTUAL: 		" << ArticulosMuebles[i].getValorActualArticulo() << "\n" ;
		cout << "7.ESTADO DEL ARTICULO:		" << ArticulosMuebles[i].getEstadoArticuloDeActivo() << "\n" ;
		cout << "8.DISPONIBILIDAD:		" << ArticulosMuebles[i].getEstadoDeLimiteDeArticulos() << "\n" ; // Este es para saber si aun hay articulos de este tipo
		cout << "9.ESTADO ASIGNACION:		" << ArticulosMuebles[i].getEstadoDeAsignadoAProfesor() << "\n" ;
		cout << "10.VALOR DESPRECIACION:		" << ArticulosMuebles[i].getDespreciacion() << "\n" ;
		cout << "11.ASIGNADO AL PROFESOR:	" << ArticulosMuebles[i].getProfesorAsignado()->getNombre() << "\n" ;  
		cout << "12.CODIGO DEL PROFESOR:		" << ArticulosMuebles[i].getProfesorAsignado()->getCodigo() << "\n" ;
		cout << "12.FECHA: 			" << ArticulosMuebles[i].getFecha()->getAnio() << "/" ;
		cout << ArticulosMuebles[i].getFecha()->getMes() << "/" << ArticulosMuebles[i].getFecha()->getDia() << "\n" ;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::getPrestamos() {
	system("cls") ;
	cout << ("\n\tArticulos De Prestamo \n\n\n") ;
	for (int i=0 ; i<this->ArticulosDisponibles.size() ; i++) {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
		cout << "1.ID NOMBRE:			" << ArticulosDisponibles[i].getIDNombre() << "\n" ;
		cout << "2.CODIGO:			" << ArticulosDisponibles[i].getCodigoArticulo() << "\n" ;
		cout << "3.PRECIO:			" << ArticulosDisponibles[i].getValorArticuloInicial() << "\n" ;
		cout << "4.PRECIO ACTUAL:		" << ArticulosDisponibles[i].getValorActualArticulo() << "\n" ;
		cout << "5.ESTADO:			" << ArticulosDisponibles[i].getEstadoArticuloDeActivo() << "\n" ;
		cout << "6.ESTADO DE LIMITE:		" << ArticulosDisponibles[i].getEstadoDeLimiteDeArticulos () << "\n" ;
		cout << "7.Estado DE ASIGNACION:		" << ArticulosDisponibles[i].getEstadoDeAsignadoAProfesor() << "\n" ;
		cout << "8.ID MARCA:			" << ArticulosDisponibles[i].getIDMarca() << "\n" ;
		cout << "9.CANTIDAD DEL MISMO TIPO:	" << ArticulosDisponibles[i].getCantidadDeTipoDeArticulo() << "\n" ;
		cout << "10.DEPRECIACION ANUAL:		" << ArticulosDisponibles[i].getDespreciacion () << "\n" ;
 		cout << "11.CODIGO DEL PROFESOR: " << ArticulosDisponibles[i].getProfesor()->getCodigo() << "\n" ;
		cout << "12. FECHA:			" << ArticulosDisponibles[i].getFecha()->getAnio() << "/" ;
		cout << ArticulosDisponibles[i].getFecha()->getMes() << "/" << ArticulosDisponibles[i].getFecha()->getDia() << "\n" ;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::getFechaLaboratorio() {
	cout << "FFORMATO DE FECHA:  AAAAA/MM/DD \n" ;
	cout << "\nLA FECHA DEL LABORATORIO ES: \n" ;
	cout << this->FechaInicio->getAnio() << "/" << this->FechaInicio->getMes() << "/" << this->FechaInicio->getDia() << "\n\n" ;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::Reglas() {
	system("cls") ;
	
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" ;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n" ;
	cout << "\n\t\tREGLAS BASICAS DEL LABORATORIO \n\n" ;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n" ;
	
	cout << "\n\t# REGLAS " ;
	cout << "\t\t\t DESCRIPCION DE CADA REGLA\n\n" ;
	
	cout << "\t1" << "\t\t\t NINGUN ESTUDIANTE DEBE TENER UN DEUDA DE MULTA  				\n\t\t\t\t PARA ACCEDER AL SERVIBIO DE PRESTAMOS \n\n" ;
	cout << "\t2" << "\t\t\t CADA ESTUDIANTE DEBE MANEJAR UN ESTADO DE ACTIVO				\n\t\t\t\t PARA EL SERVICIO DE PRESTAMO \n\n" ;
	cout << "\t3" << "\t\t\t CADA ARTICULO DESEADO DEBE ESTAR VIGENTE Y ACTIVO 				\n\t\t\t\t PARA EL SERVICIO DE PRESTAMO \n\n" ;
	cout << "\t4" << "\t\t\t DEBEN EXISTIR ARTICULOS DISPONIBLES			   				\n\t\t\t\t PARA EL SERVICIO DE PRESTAMO \n\n" ;
	cout << "\t5" << "\t\t\t LUEGO DE LA FECHA VENCIDA EL VALOR DE MULTA SERA $250/Dia 		\n\t\t\t\t PARA LOS ESTUDIANTES \n\n" ; 
	cout << "\t6" << "\t\t\t LUEGO DE LA FECHA VENCIDA EL VALOR DE MULTA SERA $7.500/MES    \n\t\t\t\t PARA LOS ESTUDIANTES \n\n" ;
	cout << "\t7" << "\t\t\t LUEGO DE LA FECHA VENCIDA EL VALOR DE MULTA SERA $90.000/ANIO  \n\t\t\t\t PARA LOS ESTUDIANTES \n\n" ;
	cout << "\t8" << "\t\t\t LOS ARTICULOS DE COMPUTO SE DESPRECIAN A LOS 10 ANIOS 			\n\t\t\t\t Y LLEGAN A UN VALOR 0 \n\n" ;
	cout << "\t9" << "\t\t\t LOS ARTICULOS DE COMPUTO SE DESPRECIAN A LOS 20 ANIOS 			\n\t\t\t\t Y LLEGAN A UN VALOR 0 \n\n" ;
	cout << "\t10" << "\t\t\t LOS ARTICULOS DE COMPUTO SE DESPRECIAN A LOS 18 MESES 		\n\t\t\t\t Y LLEGAN A UN VALOR 0 \n\n" ;
}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::LimitePrestamos(int Articulo, Estudiante* EstudiantePrest, Fecha* FechaRegistro) {
	ManejoDeArchivo Limite ; 
	ParaPlazos.push_back(*EstudiantePrest) ; 
	system("cls") ;

	cout << "\n\tLA FECHA DE EXPEDICION DE SU PRESTAMO ES: \n\n" ;
	cout << "FORMATO FECHA: AAAAA/MM/DD \n" ;
	cout << FechaRegistro->getAnio() << "/" << FechaRegistro->getMes() << "/" << FechaRegistro->getDia() << "\n\n" ;
	
	FechaRegistro->setMes(FechaRegistro->getMes()+1) ;
	FechaRegistro->setDia(01) ;
	
	cout << "FECHA EN QUE VENCE EL PLAZO: \n" ;
	cout << FechaRegistro->getAnio() << "/" << FechaRegistro->getMes() << "/" << FechaRegistro->getDia() << "\n\n" ;

	this->ArticulosDisponibles[Articulo-1].AgregarFechaLim(FechaRegistro) ;
	ParaFechasPlazo.push_back(*FechaRegistro) ; 
	
	Limite.CrearPlazoEntrega(ParaPlazos) ;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::AsociarLimite() {

	for (int i=0 ; i<this->Estudiantes.size() ; i++) {
		for (int j=0 ; j<ParaPlazos.size() ; j++){
			if (ParaPlazos[j].getCodigo() == this->Estudiantes[i].getCodigo()){
				for (int k=0 ; k<this->Estudiantes[i].MisArticulos().size() ; k++) {
					for (int l=0 ; l<ArticuloParaPlazos.size() ; l++) {
						if (ArticuloParaPlazos[l].getCodigoArticulo() == this->Estudiantes[i].MisArticulos()[k]->getCodigoArticulo()) {
							for (int m=0 ; m<ParaFechasPlazo.size() ; m++) {
								this->Estudiantes[i].MisArticulos()[k]->AgregarFechaLim(&ParaFechasPlazo[m]) ; 
							}							
						}
					}					
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::MostrarFechasLimites(int Posicion) {
	Posicion-- ; 
	
	for (int i=0 ; i<this->Estudiantes.size() ; i++) {
		if (Posicion == i) {
			if (!this->Estudiantes[i].MisArticulos().empty()) {
				for (int j=0 ; j<this->Estudiantes[i].MisArticulos().size() ; j++) {
					cout << "FECHA DE VENCIMIENTO DEL PLAZO A ENTREGA: \n\n" ; 
					cout << this->Estudiantes[i].MisArticulos()[j]->MostrarFecha()->getAnio() << "/" ;
					cout << this->Estudiantes[i].MisArticulos()[j]->MostrarFecha()->getMes() << "/" ;
					cout << this->Estudiantes[i].MisArticulos()[j]->MostrarFecha()->getDia() << "\n\n" ;							
				}
			}else {
				system("cls") ;
				cout << "\nEL PROCESO A EXPIRADO, SE HA PRESENTADO UNA FALLA !!!" ;
			}			
		}else {
			cout << "\nNO EXISTEN DATOS DE UN ESTUDIANTE \n\n" ; 
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

// Cargar todos los archivos
void Laboratorio::CargarTodoslosArchivos() {
	ManejoDeArchivo CargarArchivos ;
	CargarArchivos.CargarArchivoEstudianteCSV(Estudiantes) ;
	CargarArchivos.CargarArchivoInformacionCSV(&Informaciones) ;
	CargarArchivos.CargarArchivoProfesorCSV(&Profesores) ;
	CargarArchivos.CargarArchivoAdminisCSV(&PersonalAdmin) ;

	//////////////////////////////////////////////////////////////////////////////////
	//       Cargar y Asignarle los Profesores que tienen los articulos de Computo  //
	vector <int> Tamanio ;  // Traspaso de codigos
	for (int i=0 ; i<CargarArchivos.CargarArchivoArticuloComputoCSV(&ArticulosComp).size() ; i++) {
		Tamanio.push_back(CargarArchivos.CargarArchivoArticuloComputoCSV(&ArticulosComp)[i]) ;
	}

	if(!this->ArticulosComp.empty()) {
		for (int i=0 ; i<Tamanio.size() ; i+=2) {
			int a = Tamanio[i] ;
			int b = Tamanio[i+1] ;
			AccederProfesor(a, b) ;
		}
	}

	CargarArchivos.CargarArticuloComputoCSV(&this->FechasAuxiliarComp) ;
	for (int i=0 ; i<this->ArticulosComp.size() ; i++) {
		this->ArticulosComp[i].AsignarFecha(&this->FechasAuxiliarComp[i]) ;
	}

	//////////////////////////////////////////////////////////////////////////////////
	//     Cargar y Asignarle los Profesores que tienen los articulos de Mueble     //
	vector <int> TamanioMueble ;  // Traspaso de codigos
	for (int i=0 ; i<CargarArchivos.CargarArchivoArticuloMuebleCSV(&ArticulosMuebles).size() ; i++) {
		TamanioMueble.push_back(CargarArchivos.CargarArchivoArticuloMuebleCSV(&ArticulosMuebles)[i]) ;
	}

	if(!this->ArticulosMuebles.empty()) {
		for (int i=0 ; i<TamanioMueble.size() ; i+=2) {
			int a = TamanioMueble[i] ;
			int b = TamanioMueble[i+1] ;
			AccederProfesorMueb(a, b) ;
		}
	} 
	
	CargarArchivos.CargarArticuloMuebleCSV(&this->FechasAuxiliarMueb) ;
	for (int i=0 ; i<this->ArticulosMuebles.size() ; i++) {
		this->ArticulosMuebles[i].AsignarFecha(&this->FechasAuxiliarMueb[i]) ;
	}
	
	//////////////////////////////////////////////////////////////////////////////////
	//        Cargar y Asignarle los Profesores que tienen los articulos de Mueble  //
	vector <int> TamanioPrestamo ;  // Traspaso de codigos
	for (int i=0 ; i<CargarArchivos.CargarArchivoArticuloDePrestamoCSV(&this->ArticulosDisponibles).size() ; i++) {
		TamanioPrestamo.push_back(CargarArchivos.CargarArchivoArticuloDePrestamoCSV(&this->ArticulosDisponibles)[i]) ;
	}

	if(!this->ArticulosDisponibles.empty()) {
		for (int i=0 ; i<TamanioPrestamo.size() ; i+=2) {
			int a = TamanioPrestamo[i] ;
			int b = TamanioPrestamo[i+1] ;
			AccederProfesorArtPrestamo(a, b) ;
		}
	}
	
	CargarArchivos.CargarArticuloDePrestamoCSV(&this->FechasAuxiliarPrest) ;
	for (int i=0 ; i<this->ArticulosDisponibles.size() ; i++) {
		this->ArticulosDisponibles[i].AsignarFecha(&this->FechasAuxiliarPrest[i]) ;
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////
	//                        Cargar Asiganciones a estudiantes                     //
	// Traspaso a un vector de direcciones para trabajar las asignaciones correctamente
	vector <Estudiante*> TraspasoEstudiantes ;
	for (int i=0 ; i<this->Estudiantes.size() ; i++) {
		TraspasoEstudiantes.push_back(&this->Estudiantes[i]) ;
	}

	// Traspaso a un vector de direcciones para trabajar las asignaciones correctamente
	vector <ArticuloDePrestamo*> TraspasoArticulos ;
	for (int i=0 ; i<this->ArticulosDisponibles.size() ; i++) {
		TraspasoArticulos.push_back(&this->ArticulosDisponibles[i]) ;
	}
	CargarArchivos.CargarPrestados(TraspasoEstudiantes, TraspasoArticulos) ;
	
	
	//////////////////////////////////////////////////////////////////////////////////////
	//                              Cargar historiales                                  // 
	CargarArchivos.CargarHistorialPrestamo(&ParaHistoriales) ;
	CargarArchivos.CargarHistorialPrestamo(&ArticuloHistorial) ; 
	CargarArchivos.CargarHistorialPrestamo(&FechasHistoriales) ; 
	
	for (int i=0 ; i<ArticuloHistorial.size() ; i++) {
		ArticuloHistorial[i].AsignarFecha(&FechasHistoriales[i]) ; 
		ParaHistoriales[i].ArticuloParaPrestar(&ArticuloHistorial[i]) ; 
	}
	
	//////////////////////////////////////////////////////////////////////////////////////
	//                               Cargar Fechas de Limite                            //
	CargarArchivos.CargarPlazos(&ParaPlazos) ;
	CargarArchivos.CargarPlazos(&ParaFechasPlazo) ; 
	CargarArchivos.CargarPlazos(&ArticuloParaPlazos) ; 
	this->AsociarLimite() ; 
}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

int Laboratorio::MandarPosicionActual(int ClaseVector) { // ClaseVector = es el tipo de objeto que estamos trabajando
	// si es 0 = vector de estudiantes, si es 1 = vector de profesores
	// si es 2 = vector de informaciones, si es 3 = vector de administrativos
	// si es 4 = vector de computo , si es 5 = vector de muebles , si es 6 Articulos Prestamo


	// Claves para los vectores
	map< string, int > Vectores ;
	Vectores.insert(pair< string, int> ("Estudiantes", 0)) ;
	Vectores.insert(pair< string, int> ("Profesores", 1)) ;
	Vectores.insert(pair< string, int> ("Informaciones", 2)) ;
	Vectores.insert(pair< string, int> ("Personal administrativo", 3)) ;
	Vectores.insert(pair< string, int> ("Articulos de Computo", 4)) ;
	Vectores.insert(pair< string, int> ("Articulos de Mueble", 5)) ;
	Vectores.insert(pair< string, int> ("Articulos Prestamo", 6)) ;

	if (Vectores["Estudiantes"] == ClaseVector) {
		return this->Estudiantes.size() ;
	} else if (Vectores["Profesores"] == ClaseVector) {
		return this->Profesores.size() ;
	} else if (Vectores["Informaciones"] == ClaseVector) {
		return this->Informaciones.size() ;
	} else if (Vectores["Personal administrativo"] == ClaseVector) {
		return this->PersonalAdmin.size() ;
	} else if (Vectores["Articulos de Computo"] == ClaseVector) {
		return this->ArticulosComp.size() ;
	} else if (Vectores["Articulos de Mueble"] == ClaseVector) {
		return this->ArticulosMuebles.size() ;
	} else if (Vectores["Articulos Prestamo"] == ClaseVector) {
		return this->ArticulosDisponibles.size() ;
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::ServicioPrestamo(int PosiEstudiante, int PosiArticulo) {
	ManejoDeArchivo Historial ; 
	bool* Salir = new bool (false) ;
	bool* Confirmar = new bool (true) ;
	int Opcion ;
	system("cls") ;

	cout << "\n\nVerificando Autorizacion para reaiizar prestamos \n\n" ;

	if (this->ArticulosDisponibles[PosiArticulo-1].getCantidadDeTipoDeArticulo() == 0) {
		system("cls") ;
		cout << "\n\tNo hay articulos disponibles, por el momento estan todos prestados \n\n" ;
		*Confirmar = false ; 
	}
	
	if (*Confirmar == true) {
		if (PosiArticulo > this->ArticulosDisponibles.size()) {
			system("cls") ;
			cout << "\n\tNo existe ese indicador del articulo ingresado \n\n" ;
		} else if (this->Estudiantes[PosiEstudiante-1].getEstadoDeMulta() == true) {
			system("cls") ;
			cout << "\n\n\tERRO DE PRESTAMO \n" ;
			cout << "No puedes accerder al prestamo ya que cuentas con una multa por retraso de entrega de un articulo \n\n" ;
			cout << "Por favor primero cancele la totalidad de su Multa \n\n" ;
			RealizarPagoMulta(PosiEstudiante) ;
		} else if (this->ArticulosDisponibles[PosiArticulo-1].getEstadoArticuloDeActivo() == false) {
			system("cls") ;
			cout << "\n\n\tERRO DE PRESTAMO \n" ;
			cout << "No puedes accerder al prestamo ya que el articulo esta inactivo para prestamos \n\n" ;
			cout << "Por favor intenta con otro articulo \n\n" ;
		}else{
			system("pause") ;
			system("cls") ;
			cout << "\n\tEl articulo que desea prestar es el siguiemte \n\n" ;
			system("pause") ;
	
			AccederArticulosPrestamo(PosiArticulo) ;
	
			do {
				cout << "\n\tConfirmar el proceso \n\n" ;
				cout << "1. Continuar proceso \n" ;
				cout << "2. Cancelar proceso \n\n" ;
	
				Opcion = common::ValidarEntero("Elige una opcion \n") ;
	
				switch(Opcion) {
					case 1 : { // Continuar
						cout << "\nPor favor espera \n\n" ;
						system("pause") ;
						for (int i=0 ; i<this->Estudiantes[PosiEstudiante-1].MisArticulos().size() ; i++) {
							if (this->ArticulosDisponibles[PosiArticulo-1].getCodigoArticulo() == this->Estudiantes[PosiEstudiante-1].MisArticulos()[i]->getCodigoArticulo()) {
								cout << "\n\n\tERROR DE PRESTAMO !!! \n" ;
								cout << "\tYa tienes este articulo prestado \n" ;
								cout << "\tIntenta de nuevo con otro artculo \n\n" ;
								*Confirmar = false ;
							}
						}
						if (*Confirmar == true) {
							if (this->ArticulosDisponibles[PosiArticulo-1].getCantidadDeTipoDeArticulo() > 0) {
								this->Estudiantes[PosiEstudiante-1].ArticuloParaPrestar(&this->ArticulosDisponibles[PosiArticulo-1]) ;							
								int Cantidad = this->ArticulosDisponibles[PosiArticulo-1].getCantidadDeTipoDeArticulo()- 1 ; // Memar a la cantidad dispoible
								this->ArticulosDisponibles[PosiArticulo-1].setCantidadDeTipoDeArticulo(Cantidad) ; // Modificarla
								Historial.ActualizarArchivoArticuloDePrestamoCSV(this->ArticulosDisponibles) ;  // Actualizar el CSV de prestamos
								
								for (int i=0 ; i<this->Estudiantes[PosiEstudiante-1].MisArticulos().size() ; i++) {
									this->Estudiantes[PosiEstudiante-1].MisArticulos()[i]->getFecha()->setAnio(FechaActual->getAnio()) ; 
									this->Estudiantes[PosiEstudiante-1].MisArticulos()[i]->getFecha()->setMes(FechaActual->getMes()) ; 
									this->Estudiantes[PosiEstudiante-1].MisArticulos()[i]->getFecha()->setDia(FechaActual->getDia()) ; 
								}								
								
								Historial.HistorialPrestamoCSV(this->Estudiantes) ;							
								
								system("cls") ; 
								cout << "Prestamo Exitoso !!! \n\n" ;
								system("pause") ;
								LimitePrestamos(PosiArticulo, &this->Estudiantes[PosiEstudiante-1], FechaActual) ; 
								*Salir = true ;
							}else {
								system("cls") ;
								cout << "\n\nNo hay articulos de este tipo disponibles \n\n" ;								
								*Confirmar = false ; 
								*Salir = true ;
							}																				
						}else {
							*Salir = true ;
						}
						break;
					}
	
					case 2 : { // Cancelar
						system("cls") ;
						cout << "\nAcabas de cancelar el servicio de prestamo \n" ;
						cout << "Por favor espera un momento mientras te redirigimos \n\n" ;
						*Salir = true ;
						*Confirmar = false ;
						break;
					}
	
					default : { // Opcion Incorrecta
						cout << "\nHas elegido una opcion incorrecta \n" ;
						cout << "Por favor intente de nuevo \n" ;
						system("pause") ;
						system("cls") ;
						break;
					}
				}
			} while(!*Salir) ;
	
			if (*Confirmar == true) {
				ManejoDeArchivo ManejoParaPrestados ;
				ManejoParaPrestados.CrearArchivoPrestados(this->Estudiantes) ;
			}
		}
	}
	

	delete Salir, Confirmar ;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::VerMisPrestados(int Posicion) {
	if (this->Estudiantes[Posicion-1].MisArticulos().empty()) {
		cout << "\n\n\tNO TIENES ARTICULOS PRESTADOS EN EL HISTORIAL \n\n" ;
	} else {
		this->Estudiantes[Posicion-1].MostrarTodosLosArticulos() ;
		system("pause") ;
		this->MostrarFechasLimites(Posicion) ; 
		
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

bool Laboratorio::ServicioDevolucion(int PosiEstudiante) {
	bool* Salir = new bool(false) ;
	bool* Confirmar = new bool(true) ;
	int PosiArticulo ;
	int Opcion ;
	system("cls") ;

	if (this->Estudiantes[PosiEstudiante-1].MisArticulos().empty()) {
		cout << "\n\tERROR DE DEVOLUCION \n" ;
		cout << "NO HAY ARTICULOS PARA DEVOLUCION EN TU HISTORIAL DE PRESTAMO \n\n" ;
	} else {
		VerMisPrestados(PosiEstudiante) ;

		PosiArticulo = common::ValidarEntero("\n\nSELECCIONA EL ARTICULO A DEVOLVER: ") ;

		if (PosiArticulo > this->ArticulosDisponibles.size()) {
			system("cls") ;
			cout << "\n\tINDICADOR DE ARTICULO NO EXISTENTE \n\n" ;
		} else {
			system("pause") ;
			system("cls") ;
			cout << "\n\tARTICULO A DEVOLVER : \n\n" ;
			system("pause") ;

			AccederArticulosPrestamo(PosiArticulo) ;

			do {
				cout << "\n\tCONFIRMAR PROCESO \n\n" ;
				cout << "1. CONTINUAR \n" ;
				cout << "2. CANCELAR \n\n" ;

				Opcion = common::ValidarEntero("SELECCIONA UNA OPCION: ") ;

				switch(Opcion) {
					case 1 : { // Confirmar
						cout << "\nUN MOMENTO, PRESIONA UNA TECLA PARA CONTINUAR\n\n" ;
						this->Estudiantes[PosiEstudiante-1].Devolucion(PosiArticulo) ;
						int Cantidad = this->ArticulosDisponibles[PosiArticulo-1].getCantidadDeTipoDeArticulo() + 1 ;
						this->ArticulosDisponibles[PosiArticulo-1].setCantidadDeTipoDeArticulo(Cantidad) ; 
						*Salir = true ; 
						break;
					}

					case 2 : { // Cancelar
						system("cls") ;
						cout << "\nPROCESO DE DEVOLUCION CANCELADO \n" ;
						cout << "PRESIONA UNA TECLA PARA CONTINUAR \n\n" ;
						*Salir = true ;
						*Confirmar = false ;
						break;
					}

					default : { // Opcion Incorrecta
						cout << "\nOPCION INCORRECTA... \n" ;
						cout << "INTENTA DE NUEVO \n\n" ;
						system("pause") ;
						system("cls") ;
						break;
					}
				}
			} while(!*Salir) ;
		}


		if (*Confirmar == true) {
			ManejoDeArchivo ManejoParaPrestados ;
			ManejoParaPrestados.CrearArchivoPrestados(this->Estudiantes) ;
		}
	}

	delete Salir ;
	return *Confirmar ;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::RealizarPagoMulta(int Posicion) {
	bool* Salir = new bool (false) ;
	bool* Confirmar = new bool (true) ;
	int OpcionMultiple ;

	if (this->Estudiantes[Posicion-1].getValorMultaAcomulada() == 0) {
		system("cls") ;
		cout << "\n\tTU ESTADO DE MULTA ES : $0  \n\n" ;
	} else {
		do {
			system("cls") ;
			cout << "\n\nACERQUESE AL LABORATORIO Y CANCELE SU DEUDA ACTUAL EN MULTA DE PRESTAMO \n" ;
			cout << "SU SALDO ACTUAL DE MULTA ES: $" << this->Estudiantes[Posicion-1].getValorMultaAcomulada() << "\n" ;
			cout << "\n\n\tPOR FAVOR CONFIRMAR \n\n" ;
			cout << "1. CONFIRMAR \n" ;
			cout << "2. CANCELAR \n\n" ;

			OpcionMultiple = common::ValidarEntero("SELECCIONA UNA OPCION: ") ;

			switch(OpcionMultiple) {
				case 1 : { // Continuar proceso
					cout << "EL VALOR DE SU MULTA ES: $" << this->Estudiantes[Posicion-1].getValorMultaAcomulada() << "\n" ;

					OpcionMultiple = common::ValidarEntero("INGRESA LA CANTIDAD DE DINERO PARA CANCELAR SU MULTA: $ ") ;

					cout << "\nESTAMOS REALIZANDO SU PAGO \n\n" ;
					system("pause") ;

					if (OpcionMultiple < this->Estudiantes[Posicion-1].getValorMultaAcomulada()) {
						system("cls") ;
						cout << "\n\nERROR \n" ;
						cout << "SALDO INSUFICIENTE PARA REALIZAR EL PAG \n" ;
						cout << "VERIFIQUE SU PAGO DE NUEVO \n\n" ;
						system("pause") ;
						RealizarPagoMulta(Posicion) ;
					} else {
						system("cls") ;
						int Saldo = OpcionMultiple - this->Estudiantes[Posicion-1].getValorMultaAcomulada() ;
						if (Saldo == 0) {
							this->Estudiantes[Posicion-1].CorrerValorMulta(0) ;
							this->Estudiantes[Posicion-1].setEstadoDeMulta(false) ; 
							this->Estudiantes[Posicion-1].setEstadoDeEstudiante(false) ; 
						} else {
							cout << "Su cambio es: $" << Saldo ;
							this->Estudiantes[Posicion-1].CorrerValorMulta(0) ;
							this->Estudiantes[Posicion-1].setEstadoDeMulta(false) ; 
							this->Estudiantes[Posicion-1].setEstadoDeEstudiante(false) ; 
						}
						cout << "\n\nPAGO EXITOSO !!! \n\n" ;
					}
					*Salir = true ;
					break;
				}

				case 2 : { // Cancelar proceso
					system("cls") ;
					cout << "\nMULTA PAGADA, ESTADO DE MULTA EN $0 \n" ;
					cout << "PPRESIONA UNA TECLA PARA SER DIRIGIDO \n\n" ;
					*Salir = true ;
					*Confirmar = false ;
					break;
				}

				default : { // Opcion Incorrecta
					cout << "\nOPCION INCORRECTA \n" ;
					cout << "INTENTE DE NUEVO \n" ;
					system("pause") ;
					break;
				}
			}

		} while(!*Salir) ;
	}


	if (*Confirmar == true) {
		ManejoDeArchivo ActualizarPago ;
		ActualizarPago.ActualizarArchivoEstudianteCSV(this->Estudiantes) ;
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::Multa() {
	bool* Confirmar = new bool ; 
	ManejoDeArchivo ActualizarEstudiante ;
	
	for (int i=0 ; i<this->Estudiantes.size() ; i++) {
		for (int j=0 ; j<this->Estudiantes[i].MisArticulos().size() ; j++) {
			if (FechaActual->getAnio() > this->Estudiantes[i].MisArticulos()[j]->MostrarFecha()->getAnio()) {
				int Diferencia = FechaActual->getAnio() - this->Estudiantes[i].MisArticulos()[j]->MostrarFecha()->getAnio() ;
				this->Estudiantes[i].CorrerValorMulta(this->Estudiantes[i].getValorMultaAcomulada() + (90000*Diferencia)) ;
				this->Estudiantes[i].setEstadoDeMulta(true) ; 
				this->Estudiantes[i].setEstadoDeEstudiante(true) ;
				*Confirmar = true ; 
					
			}else if (FechaActual->getMes() > this->Estudiantes[i].MisArticulos()[j]->MostrarFecha()->getMes()) {
				int Diferencia = FechaActual->getMes() - this->Estudiantes[i].MisArticulos()[j]->MostrarFecha()->getMes() ;
				this->Estudiantes[i].CorrerValorMulta(this->Estudiantes[i].getValorMultaAcomulada() + (7500*Diferencia)) ;
				this->Estudiantes[i].setEstadoDeMulta(true) ; 
				this->Estudiantes[i].setEstadoDeEstudiante(true) ;
				*Confirmar = true ;
				
			}else if (FechaActual->getDia() > this->Estudiantes[i].MisArticulos()[j]->MostrarFecha()->getDia()) {
				int Diferencia = FechaActual->getDia() - this->Estudiantes[i].MisArticulos()[j]->MostrarFecha()->getDia() ;
				this->Estudiantes[i].CorrerValorMulta(this->Estudiantes[i].getValorMultaAcomulada() + (250*Diferencia)) ;
				this->Estudiantes[i].setEstadoDeMulta(true) ; 
				this->Estudiantes[i].setEstadoDeEstudiante(true) ;
				*Confirmar = true ;
				
			}else {
				this->Estudiantes[i].setEstadoDeMulta(false) ; 
				this->Estudiantes[i].setEstadoDeEstudiante(false) ;
				*Confirmar = false ; 
			}
		}		
	}
	
	if (*Confirmar == true) {
		ActualizarEstudiante.ActualizarArchivoEstudianteCSV(this->Estudiantes) ; 
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

// Crear objetos profesores y agregarlos al vector de profesores
bool Laboratorio::AgregarAlVectorProfesores(int Cantidad) {
	bool DatosCorrectos = true ;
	Profesor* ProfesoresParaCrear = new Profesor ;

	for (int i=0 ; i<Cantidad ; i++) {
		ProfesoresParaCrear->CrearDatosDeProfesor(ProfesoresParaCrear) ;

		for (int j=0 ; j<this->Profesores.size() ; j++) {
			if (this->Profesores[j].getCodigo() == ProfesoresParaCrear->getCodigo()) {
				system("cls") ;
				cout << "\nERROR, NO ES POSIBLE CREAR UN PROFESOR CON UN CODIGO EXISTENTE \n" ;
				cout << "EL REGISTRO HA FALLADO \n\n" ;
				
				
				system("pause") ;
				DatosCorrectos = false ;
			}
		}

		if (DatosCorrectos == true) {
			cout << "\nSE HA REGISTRADO CON EXITO \n\n" ;
			system("pause") ;
			this->Profesores.push_back(*ProfesoresParaCrear) ;
		}
	}

	if (DatosCorrectos == true) {
		ManejoDeArchivo ParaProfesores ;
		ParaProfesores.CrearArchivoProfesorCSV(Profesores) ;
	}

	delete ProfesoresParaCrear ;
	return DatosCorrectos ;
}

// Funcion para crear estudiantes, agregar al vector de estudiantes y crear archivo
bool Laboratorio::AgregarAlVectorEstudiantes(int Cantidad) {
	bool DatosCorrectos = true ;
	Estudiante* EstudiantesParaCrear = new Estudiante ;

	for (int i=0 ; i<Cantidad ; i++) {
		EstudiantesParaCrear->CrearDatosDeObjetoEstudiante(EstudiantesParaCrear) ;
		for (int j=0 ; j<this->Estudiantes.size() ; j++) {
			if (this->Estudiantes[j].getCodigo() == EstudiantesParaCrear->getCodigo()) {
				system("cls") ;
				cout << "\nERROR, NO ES POSIBLE CREAR UN ESTUDIANTE CON UN CODIGO EXISTENTE \n" ;
				cout << "EL REGISTRO HA FALLADO \n\n" ;
				system("pause") ;
				DatosCorrectos = false ;
			}
		}

		if (DatosCorrectos == true) {
			cout << "\nSE HA REGISTRADO CON EXITO \n\n" ;
			this->Estudiantes.push_back(*EstudiantesParaCrear) ;
			AsignarCodigosEstudiantes() ;
		}
	}
	if (DatosCorrectos == true) {
		ManejoDeArchivo ParaEstudiantes ;
		ParaEstudiantes.CrearArchivoEstudianteCSV(Estudiantes) ;
	}

	delete EstudiantesParaCrear ;
	return DatosCorrectos ;
}


// Crear objetos de informaciones y agregarlos al vector de informacion
void Laboratorio::AgregarAlVectorInformaciones(int Cantidad) {
	Informacion* InformacionParaCrear = new Informacion ;
	bool DatosCorrectos = true ;
		
	if (VerificarVectorInformaciones() == true ) {
		for (int i=0 ; i<Cantidad ; i++) {
			InformacionParaCrear->DatosIniciales(InformacionParaCrear, i) ;
			this->Informaciones.push_back(*InformacionParaCrear) ;
		}
	} else {
		for (int i=0 ; i<Cantidad ; i++) {
			InformacionParaCrear->CrearInformacionLabotatorio(InformacionParaCrear) ;
			this->Informaciones.push_back(*InformacionParaCrear) ;
			cout << "\nSE HA REGISTRADO CON EXITO \n\n" ;
			system("pause") ;
		}
	}
	
	if (DatosCorrectos == true) {
		ManejoDeArchivo ManejoDeInformacion ;
		ManejoDeInformacion.CrearArchivoInformacionCSV(Informaciones)  ;
	}
	

	delete InformacionParaCrear ;
}


// Crear objetos de personal administrativo y agregarlos al vector de personal
bool Laboratorio::AgregarAlVectorPersonalAdmin(int Cantidad) {
	PersonalAdmi* PersonalParaCrear = new PersonalAdmi ;
	bool DatosCorrectos = true ;

	for (int i=0 ; i<Cantidad ; i++) {
		PersonalParaCrear->CrearPersonal(PersonalParaCrear) ;

		for (int j=0 ; j<this->PersonalAdmin.size() ; j++) {
			if (this->PersonalAdmin[j].getCedula() == PersonalParaCrear->getCedula()) {
				system("cls") ;
				cout << "\nERROR, NO ES POSIBLE CREAR UN PERSONAL ADMINISTRATIVO CON UN NUMERO DE CEDULA EXISTENTE \n" ;
				cout << "EL REGISTRO HA FALLADO \n\n" ;
				system("pause") ;
				DatosCorrectos = false ;
			}
		}
		if (DatosCorrectos == true) {
			cout << "\nREGISTRADO CON EXITO \n\n" ;
			this->PersonalAdmin.push_back(*PersonalParaCrear) ;
		}
	}

	if (DatosCorrectos == true) {
		ManejoDeArchivo ManejoAdministra ;
		ManejoAdministra.CrearArchivoAdminisCSV(this->PersonalAdmin) ;
	}

	delete PersonalParaCrear ;
	return DatosCorrectos ;
}
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

bool Laboratorio::AgregarAlVectorComputo(int Cantidad) {
	ArticuloComputo* ComputoACrear = new ArticuloComputo ;
	bool DatosCorrectos = true ; 

	for (int i=0 ; i<Cantidad ; i++) {
		ComputoACrear->CrearComputo(ComputoACrear) ;
		for (int j=0 ; j<this->ArticulosComp.size() ; j++) {
			if (this->ArticulosComp[j].getCodigoArticulo() == ComputoACrear->getCodigoArticulo()) {
				system("cls") ;
				cout << "\nERROR, NO ES POSIBLE CREAR UN ARTICULO CON UN CODIGO EXISTENTE \n" ;
				cout << "EL REGISTRO HA FALLADO \n\n" ;
				DatosCorrectos = false ;
			}
		}
		
		if (DatosCorrectos == true) {
			this->ArticulosComp.push_back(*ComputoACrear) ;  // Agregar al vector
			AsignarProfesorComputo(MandarPosicionActual(4)) ; // Funcion de asignar profesor
			this->AsignarFechaComputo(MandarPosicionActual(4)) ; // Asignar Fecha
		}	
	}

	if (DatosCorrectos == true) {
		cout << "\nREGISTRADO CON EXITO \n\n" ;
		ManejoDeArchivo ManejoDeComputo ;
		ManejoDeComputo.CrearArchivoArticuloComputoCSV(ArticulosComp) ;
	}

	delete ComputoACrear ;
	return DatosCorrectos ;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

bool Laboratorio::AgregarAlVectorMueble(int Cantidad) {
	ArticuloMueble* MuebleCrear = new ArticuloMueble ;
	bool DatosCorrectos = true ;
	
	for (int i=0 ; i<Cantidad ; i++) {
		MuebleCrear->CrearMueble(MuebleCrear) ;
		for (int j=0 ; j<this->ArticulosMuebles.size() ; j++) {
			if (this->ArticulosMuebles[j].getCodigoArticulo() == MuebleCrear->getCodigoArticulo()) {
				system("cls") ;
				cout << "\nERROR, NO ES POSIBLE CREAR UN ARTICULO CON UN CODIGO EXISTENTE \n" ;
				cout << "EL REGISTRO HA FALLADO \n\n" ;
				DatosCorrectos = false ;
			}
		}
		
		if (DatosCorrectos == true) {
			this->ArticulosMuebles.push_back(*MuebleCrear) ;  // Agregar al vector
			AsignarProfeMueble(MandarPosicionActual(5)) ; // Funcion de asignar profesor
			this->AsignarFechaMueble(MandarPosicionActual(5)) ; 
		}
	}

	if (DatosCorrectos == true) {
		cout << "\nREGISTRADO CON EXITO \n\n" ;
		ManejoDeArchivo ManejoDeMueble ;
		ManejoDeMueble.CrearArchivoArticuloMuebleCSV(this->ArticulosMuebles) ;
	}
	
	delete MuebleCrear ;
	return DatosCorrectos ;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

bool Laboratorio::AgregarAlVectorPrestamo(int Cantidad) {
	ArticuloDePrestamo* PrestamoCrear = new ArticuloDePrestamo ;
	bool DatosCorrectos = true ;
		
	for (int i = 0; i<Cantidad ; i++) {
		PrestamoCrear->CrearArticuloParaPrestamo(PrestamoCrear);
		
		for (int j=0 ; j<this->ArticulosDisponibles.size() ; j++) {
			if (this->ArticulosDisponibles[j].getCodigoArticulo() == PrestamoCrear->getCodigoArticulo()) {
				system("cls") ;
				cout << "\nERROR, NO ES POSIBLE CREAR UN ARTICULO CON UN CODIGO EXISTENTE \n" ;
				cout << "EL REGISTRO HA FALLADO \n\n" ;
				DatosCorrectos = false ;
			}
		}
		
		if (DatosCorrectos == true) {
			this->ArticulosDisponibles.push_back(*PrestamoCrear);
			AsignarProfePrestamo(MandarPosicionActual(6)) ;
			this->AsignarFechaPrestamo(MandarPosicionActual(6)) ; 
		}
	}
	
	
	if (DatosCorrectos == true) {
		ManejoDeArchivo ManejoDePrestamo ;
		ManejoDePrestamo.CrearArchivoArticuloDePrestamoCSV(this->ArticulosDisponibles) ;
	}

	delete PrestamoCrear ;
	return DatosCorrectos ; 
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// Modificar datos de informacion del Laboratorio
void Laboratorio::ModificarDatosDelVectorInformaciones() {

	getInformaciones() ;

	bool* Salir = new bool (false) ;
	bool* SalirAux = new bool (false) ;
	int Opcion, DecisionAux ;
	string DatoAuxiliar ;

	Opcion = common::ValidarEntero("Ingrese el valor asignado a la informacion que desea modificar \n") ;

	for (int i=1 ; i<Informaciones.size() ; i++) { // Posicion 0 = Cabeceras
		do {
			if (Opcion == i) {
				system("cls") ;

				do { // Ciclo para repetir solo desde que desea cambiar por si introduce datos equivocados
					system("cls") ;
					cout << "SELECCIONE ESPECIFICAMENTE QUE INFORMACION DESEA MODIFICAR: \n" ;
					cout << "1. " << Informaciones[i].getNombreDeInfo() << "\n" ;
					cout << "2. " << Informaciones[i].getContenidoDeInfo() << "\n" ;

					Opcion = common::ValidarEntero("\nSELECCIONE UNA OPCION:	") ;

					if ((Opcion >=1) && (Opcion <=2)) { // Evaluar si esta en las opciones mostradas para evitar hacer un switch
						cout << "\nNota:  0=no ; 1=si \n" ;
						
						DecisionAux = common::ValidarEntero("¿ESTA SEGURO DE REALIZAR ESTA ACCION? \n") ;

						if (DecisionAux == 1 ) {
							switch (Opcion) {
								case 1 : { // Modificar nombre del dato correspondiente
									cout << "\nINGRESE UN NOMBRE NUEVO:		" ;
									cin  >>  DatoAuxiliar ;

									Informaciones[i].setNombreDeInfo(DatoAuxiliar) ;

									cout << "\n\tSU MODIFICACION TUVO EXITO, <NOMBRE ACTUALIZADO> \n" ;
									system("pause") ;

									*Salir = true ;
									*SalirAux = true ;
									break;
								}

								case 2 : { // Modificar Contenido del dato correspondiente
									cout << "\nINGRESE UN NUEVO CONTENIDO:		" ;
									cin  >>  DatoAuxiliar ;
									
									Informaciones[i].setContenidoDeInfo(DatoAuxiliar) ;
									
									cout << "\n\nSU MODIFICACION TUVO EXITO, <CONTENIDO ACTUALIZADO> \n\n" ;
									system("pause") ;
									
									*Salir = true ;
									*SalirAux = true ;
									break;
								}
								
								default : { 			// Opcion Incorrecta
									cout << "\nOPCION NO VALIDA... \n\n" ;
									system("pause") ;
									break;
								} 
							}
						}else if (DecisionAux == 0) { 	// Evalua si la opcion es 0 para mostrarle de nuevo las opciones permitidas
							cout << "\n\tREGRESANDO AL ANTERIOR PROCESO... PRESIONA UNA TECLA PARA CONTINUAR. \n" ;
							system("pause") ;
							*SalirAux = true ;
							*Salir = true ;
							ModificarDatosDelVectorInformaciones () ;	
						}else { 						// Opcion incorrecta de opciones 0 y 1 (es de si esta seguro o no de modificar algo)
							cout << "\nVUELVE A INTENTARLO... \n" ;
							cout << "OPCION INVALIDA... \n\n" ;
							system("pause") ;
						}
					}else { 							// Opcion invalida
						cout << "\nACCION FALLIDA, OPCION INCORRECTA. \n" ;
						system("pause") ;
						system("cls") ;
					}
				}while(!*SalirAux) ;
				
			}else { 									// No encontro nada, entonces salir del bucle
				*Salir = true ; 
			}
		}while (!*Salir) ;
	}


	// Mostrar mensaje si no encontro nada
	if (*SalirAux == false) {
		system("cls") ;
		cout << "\n<NO SE HAYO EL CONTENIDO> \n" ;
		system("pause") ;
	}

	ManejoDeArchivo ManejoDeInformacion ;
	ManejoDeInformacion.CrearArchivoInformacionCSV(Informaciones)  ;
}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////


void Laboratorio::ModificarDatosBasicosProfe(int Posicion) {
	
	int Campo ;
	char NombreCampo[512] ;
	
	
	AccederProfesorPosicion(Posicion) ;
		
	cout << "NOTA: SE MOSTRARAN DATOS PERSONALES Y REGISTRADOS EN EL SISTEMA...\n" ;
	cout << "SOLO SE ENCUENTRA AUTORIZADO POARA MODIFICAR LOS SIGUIENTES DATOS: Email, Edad, Telefono \n\n" ;
	
		
	Campo = common::ValidarEntero("CAMPO A MODIFICAR: \n") ;
		
	switch(Campo) {
		case 3 : { 			// EMail
			cout << "NUEVO E-MAIL:		" ;
			cin  >> NombreCampo ; 
			
			this->Profesores[Posicion-1].setEmail(NombreCampo) ;
			
			cout << "\nMODIFICACION EXITOSA...  \n\n" ;
			system("pause") ;
			 
			break;
		}
			
		case 4 : { 			// Edad
			cout << "NUEVA EDAD:		" ;
			cin  >> NombreCampo ;
			
			this->Profesores[Posicion-1].setEdad(atof(NombreCampo)) ;
 			
			cout << "\nMODIFICACION EXITOSA...  \n\n" ;
			system("pause") ;
			
			break;
		}
			
		case 6 :{ 			// Telefono
			cout << "NUEVO # TELEFONICO:		" ;
			cin  >> NombreCampo ;
			
			this->Profesores[Posicion-1].setTelefono(atof(NombreCampo)) ;
			
			cout << "\nMODIFICACION EXITOSA...  \n\n" ;
			system("pause") ;
			
			break;
		}
			
		case 1 : { 			// Nombre
		}
			
		case 2 : { 			// Apellido 
		}
			
		case 5 : { 			// Cedula 
		}
			
		case 7 : { 			// Codigo
		}
			
		case 8 : { 			// Titulo Profesional
			
			cout << "\n\nNO SE ENCUENTRA AUTORIZADO PARA REALIZAR ESTA ACCION \n" ;
			cout << "<EN CASO DE QUERER MODIFICAR DIRIJASE A UN PERSONAL ADMINISTRATIVO> \n\n" ;
			system("pause") ; 
				
			ModificarDatosBasicosProfe(Posicion) ;
				
			break;
		}
			
		default : { 		// Opcion Incorrecta
			cout << "\nOPCION INCORRECTA, NO VALIDA. \n\n" ;
			system("pause") ;
			
			ModificarDatosBasicosProfe(Posicion) ;
				
			break;
		}
	}
	ManejoDeArchivo ActualizarCSV ;
	ActualizarCSV.ActualizarArchivoProfesorCSV(this->Profesores) ;
	
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::ModificarDatosProfe(int Posicion){
	
	
	char NombreOpcion[512] ;
	
	
	Posicion = common::ValidarEntero("CAMPO A MODIFICAR: ") ;
		
	switch(Posicion) {
		
		case 1 : { 			// Nombre
			cout << "NUEVO NOMBRE:		" ;
			cin >> NombreOpcion ;
		
			this->Profesores[Posicion-1].setNombre(NombreOpcion) ;
		
			cout << "\nMODIFICACION EXITOSA... \n\n" ;
		
			break ;
		}
		
		case 2 : { 			// Apellido 
			cout << "NUEVO APELLIDO:		" ;
			cin >> NombreOpcion ;
		
			this->Profesores[Posicion-1].setApellido(NombreOpcion) ;
		
			cout << "\nMODIFICACION EXITOSA... \n\n" ;
		
			break ;
		}
		
		case 3 : { 			// EMail
			cout << "NUEVO E-MAIL:		" ;
			cin  >> NombreOpcion ; 
			
			this->Profesores[Posicion-1].setEmail(NombreOpcion) ;
			
			cout << "\nMODIFICACION EXITOSA... \n\n" ;
			 
			break;
		}
			
		case 4 : { 			// Edad
			cout << "NUEVA EDAD:		" ;
			cin  >> NombreOpcion ;
			
			this->Profesores[Posicion-1].setEdad(atof(NombreOpcion)) ;
 			
			cout << "\nMODIFICACION EXITOSA... \n\n" ;
			
			break;
		}
		
		case 5 : { 			// Cedula 
			cout << "NEUVO # CEDULA:	" ;
			cin >> NombreOpcion ;
		
			this->Profesores[Posicion-1].setCedula(atof(NombreOpcion)) ;
		
			cout << "\nMODIFICACION EXITOSA...\n\n" ;
 			break ;
		}
			
		case 6 :{ 			// Telefono
			cout << "NUEVO # TELEFONICO:		" ;
			cin  >> NombreOpcion ;
			
			this->Profesores[Posicion-1].setTelefono(atof(NombreOpcion)) ;
			
			cout << "\nMODIFICACION EXITOSA...\n\n" ;
			
			break;
		}
			
			
		case 7 : { 			// Codigo
			cout << "NUEVO CODIGO:		" ;
			cin >> NombreOpcion ;
		
			this->Profesores[Posicion-1].setCodigo(atof(NombreOpcion)) ;
		
			cout << "\nMODIFICACION EXITOSA...\n\n" ;
		
			break ;
		}
			
		case 8 : { 			// Titulo Profesional
			cout << "NUEVO TITULO		" ;
			cin >> NombreOpcion ;
			
			this->Profesores[Posicion-1].setTituloProfesional(NombreOpcion) ;
			
			cout << "\nMODIFICACION EXITOSA...\n\n" ;
				
			break;
		}
			
		default : { 		// Opcion Incorrecta
			cout << "\nCAMPO INCORRECTO, OPCION INCORRECTA. \n\n" ;
			system("pause") ;
			break;
		}
	}
	ManejoDeArchivo ActualizarCSV ;
	ActualizarCSV.ActualizarArchivoProfesorCSV(this->Profesores) ;
	
}


/////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::ModificarDatosEstudiante(int Posicion){
	char NombreOpcion [512] ;
	int Campo ;
	cout << "LA INFORMACION DEL ESTUDIANTE ES: \n" ;
	AccederAUnEstudiante(Posicion) ;
	
	Campo = common::ValidarEntero("CAMPO A MODIFICAR: \n") ;
	
	switch(Campo){
		case 1 : {		//Nombre
			cout << "NUEVO NOMBRE:		";
			cin>>NombreOpcion;
			this->Estudiantes[Posicion-1].setNombre(NombreOpcion);
			cout << "\nMODIFICACION EXITOSA... \n\n" ;
			break;
		}
		case 2 : {		//Apellido
			cout << "NUEVO APELLIDO:	";
			cin>>NombreOpcion;
			this->Estudiantes[Posicion-1].setApellido(NombreOpcion);
			cout << "\nMODIFICACION EXITOSA... \n\n" ;
			break;
		}
		case 3 : {		//E-mail
			cout << "NUEVO E-MAIL:		";
			cin>>NombreOpcion;
			this->Estudiantes[Posicion-1].setEmail(NombreOpcion);
			cout << "\nMODIFICACION EXITOSA... \n\n" ;
			break;
		}
		case 4 : {		//Edad
			cout << "NUEVA EDAD:		";
			cin>>NombreOpcion;
			this->Estudiantes[Posicion-1].setEdad(atof(NombreOpcion));
			cout << "\nMODIFICACION EXITOSA... \n\n" ;
			break;
		}
		case 5 : {		// Cedula
			cout << "NUEVO # DE CEDULA:		";
			cin>>NombreOpcion;
			this->Estudiantes[Posicion-1].setCedula(atof(NombreOpcion));
			cout << "\nMODIFICACION EXITOSA... \n\n" ;
			break;
		}
		case 6 : {		//Telefono
			cout << "NUEVO # TELEFONICO:		";
			cin>>NombreOpcion;
			this->Estudiantes[Posicion-1].setTelefono(atof(NombreOpcion));
			cout << "\nMODIFICACION EXITOSA...\n\n" ;
			break;
		}
		case 7 : {   	//Carrera
			cout << "NUEVA CARRERA:		";
			cin>>NombreOpcion;
			this->Estudiantes[Posicion-1].setCarrera(NombreOpcion);
			cout << "\nMODIFICACION EXITOSA... \n\n" ;
			break;
		}
		case 8 : {		//Codigo
			cout << "NUEVO CODIGO:		";
			cin>>NombreOpcion;
			this->Estudiantes[Posicion-1].setCodigo(atof(NombreOpcion));
			break;
		}
		case 9 :{		//Semestre
			cout << "NUEVO SEMESTRE:	" ;
			cin>>NombreOpcion;
			this->Estudiantes[Posicion-1].setSemestre(atof(NombreOpcion));
			cout << "\nMODIFICACION EXITOSA... \n\n" ;
			break;
		}
		case 10 : {		//Multa a verificar
			cout << "VALOR DE MULTA A VERIFICAR";
			cin>>NombreOpcion;
			this->Estudiantes[Posicion-1].CorrerValorMulta(atof(NombreOpcion));
			cout << "\nMODIFICACION EXITOSA... \n\n" ;
			break;
		}
		case 11 : {		//Estado de multa
			cout << "ESTADO DE  MULTA:		" ;
			cin>>NombreOpcion;
			this->Estudiantes[Posicion-1].setEstadoDeMulta(atof(NombreOpcion));
			cout << "\nMODIFICACION EXITOSA... \n\n" ;
			break;
		}
		case 12 : {		// Estado  	Activo/Inactivo
			cout << "NUEVO ESTADO DE ESTUDIANTE:		" ;
			cin>>NombreOpcion;
			this->Estudiantes[Posicion-1].setEstadoDeEstudiante(atof(NombreOpcion));
			cout << "\nMODIFICACION EXITOSA... \n\n" ;
			break;
		}	
		default : { // Opcion Incorrecta
			cout << "\nCAMPO INCORRECTO, OPCION INCORRECTA. \n\n" ;
			system("pause") ;
			break;
	
		}
	}
	ManejoDeArchivo ActualizarCSV ;
	ActualizarCSV.ActualizarArchivoEstudianteCSV(this->Estudiantes) ;
}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::ModificarDatosDelVectorComputo() {
	
	system("cls") ;
	int PosicionACambiar ;
	char Campo[512] ; 
	
	getComputo() ; 
		
	PosicionACambiar = common::ValidarEntero("SELECIONE UN ARTICULO A MODIFICAR:	") ;
	
	cout << PosicionACambiar << endl ;
	for(int i=0 ; i<this->ArticulosComp.size() ; i++) {
		if (PosicionACambiar == i+1) {
			cout << "\n\tDATOS VIGENTES DEL ARTICULO:\n" ;
			system("pause") ;
				
			AccederAComputo(PosicionACambiar) ;
			
			cout << "\nSELECCIONE UN CAMPO A MODIFICAR \n\n" ;
				
			PosicionACambiar = common::ValidarEntero("CAMPO A MODIFICAR:	") ;
				
			switch(PosicionACambiar) {
				case 1 : { 			// IDNombre
					cout << "\nINGRESE UN NUEVO NOMBRE:		" ;
					cin  >> Campo ;
					this->ArticulosComp[i].setIDNombre(Campo) ;
						
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;
											
					break;
				}
					
				case 2 : { 			// Marca
					cout << "\nINGRESE UNA NUEVA MARCA:		" ;
					cin  >> Campo ;
					this->ArticulosComp[i].setIDMarca(Campo) ;
						
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ; 
					break;
				}
					
				case 3 : {			// Cantidad de articulos
					cout << "\nINGRESE UNA NUEVA CANTIDAD:	" ;
					cin  >> Campo ;
					this->ArticulosComp[i].setCantidad(atof (Campo)) ;
						
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;
						
					break;
				}
					
				case 4 : { 			// Codigo
					cout << "\nINGRESE UN NUEVO CODIGO:		" ;
					cin  >> Campo ;
					this->ArticulosComp[i].setCodigoArticulo(atof (Campo)) ;
						
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;
					
					break;
				}
				
				case 5 : { 			// Valor de Inicial Articulo
					cout << "\nINGRESE UN NUEVO VALOR INICIAL:		" ;
					cin  >> Campo ;
					this->ArticulosComp[i].setValorArticuloInicial(atof(Campo)) ;
					
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;
					
					break;
				}
					
				case 6 : { 			// Valor Actual del Articulo
					cout << "\nINGRESE UN NUEVO VALOR ACTUAL:		" ;
					cin  >> Campo ;
					this->ArticulosComp[i].setValorActualArticulo(atof(Campo)) ;
					
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;
						
					break;
				}
					
				case 7 : { 			// Estado del Articulo
					cout << "\nINGRESE ESTADO DE ARTICULO:		" ;
					cin  >> Campo ;
					this->ArticulosComp[i].setEstadoArticuloDeActivo(atof(Campo)) ;
						
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;
						
					break;
				}
					
				case 8 : { 			// Estado de Disponibilidad
					cout << "\nINGRESE ESTADO DE DISPONIBILIDAD:		" ;
					cin  >> Campo ;
					this->ArticulosComp[i].setEstadoDeLimiteDeArticulos(atof(Campo)) ;
					
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;
					
					break;
				}
					
				case 9 : { 			// Estado de Asignacion
					cout << "\nINGRESE ESTADO DE ASIGNACION:		" ;
					cin  >> Campo ;
					this->ArticulosComp[i].setEstadoDeAsignadoAProfesor(atof(Campo)) ;
					
					cout << "\nSE HA ELIMINADO LA INFORMACION DE ASIGNACION \n" ; 
					cout << "POR FAVOR ASIGNAR UNO NUEVO. \n" ; 
					system("pause") ;
					
					this->AsignarProfesorComputo(i) ;
						
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;
						
					break;
				}
					
				case 10 : { 		// Valor de Despreciacion
					
					cout << "\n\n<NO PUEDES MODIFICAR ESTE CAMPO> \n" ;
					cout << "ESTA OPCION SE MANEJA A DEPENDENCIA DEL ARTICULO \n" ;
					system("pause") ; 
					
					break;
				}
						
				case 11 : { 		// Asignado
					
					cout << "\nINGRESE UN NUEVO ASIGNADO:		" ;
					cin  >> Campo ;
									
					cout << "\nSE HA ELIMINADO LA INFORMACION DE ASIGNACION \n" ; 
					cout << "POR FAVOR ASIGNAR UNO NUEVO. \n" ;  
					system("pause") ;
					
					this->AsignarProfesorComputo(i) ;
						
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;
					
					break;
				}
					
				default : { 		// Opcion Incorrecta
					cout << "\nESTA OPCION ES INCORRECTA \n\n" ;
					system("pause") ;
	
					ModificarDatosDelVectorComputo() ; 
						
					break;
				}
			}
		}else {
			cout << "\n\n\tARTICULO ELIMINADO O NO EXISTENTE, SELECCIONE UNA OPCION VALIDA \n\n" ;
			system("pause") ;
			
			ModificarDatosDelVectorComputo() ; 
		}
	}
	
	ManejoDeArchivo ActualizarComputo ;
	ActualizarComputo.ActualizarComputoCSV(ArticulosComp) ; 
}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::ModificarDatosMueble(int Posicion) {
	
	system("cls") ;
	char Campo[512] ; 
	
	
	for(int i=0 ; i<this->ArticulosMuebles.size() ; i++) {
		if (Posicion == i+1) {
			cout << "\n\tDATOS VIGENTES DEL ARTICULO:\n" ;
			system("pause") ;
				
			AccederAMueble(Posicion) ;
			
			cout << "\nSELECCIONE UN CAMPO A MODIFICAR \n\n" ;
				
			Posicion = common::ValidarEntero("CAMPO A MODIFICAR:	") ;
				
			switch(Posicion) {
				case 1 : { 		// IDNombre
					cout << "\nINGRESE UN NUEVO NOMBRE:		" ;
					cin  >> Campo ;
					this->ArticulosMuebles[i].setIDNombre(Campo) ;
						
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;
											
					break;
				}
					
				case 2 : { // Material
					cout << "\nINGRESE NUEVO NOMBRE DE MATERIAL:		" ;
					cin  >> Campo ;
					this->ArticulosMuebles[i].setMaterial(Campo) ;
						
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ; 
					break;
				}
					
				case 3 : { // Cantidad de articulos
					cout << "\nINGRESE CANTIDAD DE ARTICULOS DISPONIBLES:		" ;
					cin  >> Campo ;
					this->ArticulosMuebles[i].setCantidad(atof (Campo)) ;
						
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;
						
					break;
				}
					
				case 4 : { // Codigo
					cout << "\nINGRESE UN NUEVO CODIGO:		" ;
					cin  >> Campo ;
					this->ArticulosMuebles[i].setCodigoArticulo(atof (Campo)) ;
						
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;
					
					break;
				}
				
				case 5 : { // Valor de Inicial Articulo
					cout << "\nNUEVO VALOR INICIAL:		" ;
					cin  >> Campo ;
					this->ArticulosMuebles[i].setValorArticuloInicial(atof(Campo)) ;
					
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;
					
					break;
				}
					
				case 6 : { // Valor Actual del Articulo
					cout << "\nNUEVO VALOR ACTUAL:		" ;
					cin  >> Campo ;
					this->ArticulosMuebles[i].setValorActualArticulo(atof(Campo)) ;
					
					cout << "\n\nMODIFICACION EXITOSA...\n\n" ;
						
					break;
				}
					
				case 7 : { // Estado del Articulo
					cout << "\nNUEVO ESTADO DE ARTICULO:		" ;
					cin  >> Campo ;
					this->ArticulosMuebles[i].setEstadoArticuloDeActivo(atof(Campo)) ;
						
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;
						
					break;
				}
					
				case 8 : { // Estado de Disponibilidad
					cout << "\nESTADO DE DISPONIBILIDAD" ;
					cin  >> Campo ;
					this->ArticulosMuebles[i].setEstadoDeLimiteDeArticulos(atof(Campo)) ;
					
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;
					
					break;
				}
					
				case 9 : { // Estado de Asignacion
					cout << "\nESTADO DE ASIGNACION:		" ;
					cin  >> Campo ;
					this->ArticulosMuebles[i].setEstadoDeAsignadoAProfesor(atof(Campo)) ;
					
					cout << "\n \n" ; 
					cout << "Por favor asigne otro por favor \n" ; 
					system("pause") ;
					
					AsignarProfeMueble(i) ;
						
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;
						
					break;
				}
					
				case 10 : { // Valor de Despreciacion
					
					cout << "\n\n<NO PUEDES MODIFICAR ESTE CAMPO> \n" ;
					cout << "ESTA OPCION SE MANEJA A DEPENDENCIA DEL ARTICULO \n" ;
					system("pause") ; 
					
					break;
				}
					
				case 11 : { // Asignado
				
					cout << "\nIngrese el estado de disponibilidad articulo: \n" ;
					cin  >> Campo ;
									
					cout << "\nSE HA ELIMINADO LA INFORMACION DE ASIGNACION \n" ; 
					cout << "POR FAVOR ASIGNAR UNO NUEVO. \n" ;   
					system("pause") ;
					
					AsignarProfeMueble(i) ;
						
					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;
					
					break;
				}
					
				default : { // Opcion Incorrecta
					cout << "\nESTA OPCION ES INCORRECTA \n\n" ;
					system("pause") ;
	
					ModificarDatosMueble(Posicion) ; 
						
					break;
				}
			}
		}else {
			cout << "\n\n\tARTICULO ELIMINADO O NO EXISTENTE, SELECCIONE UNA OPCION VALIDA \n\n" ;
			system("pause") ;
			
			ModificarDatosMueble(Posicion) ; 
		}
	}
	
	ManejoDeArchivo ActualizarMueble ;
	ActualizarMueble.ActualizarMuebleCSV(this->ArticulosMuebles) ;
	
}

/////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void Laboratorio::ModificarDatosArticulosPrestamos(int Posicion) {

	system("cls") ;
	char Campo[512] ;
	bool Encontrado = false ;


	for(int i=0 ; i<this->ArticulosDisponibles.size() ; i++) {
		if (Posicion == i+1) {
			Encontrado = true ;
			cout << "\n\tLOS DATOS DEL ARTICULO VIGENTES SON : \n" ;
			system("pause") ;

			AccederArticulosPrestamo(Posicion) ;

			cout << "\nCAMPO A MODIFICAR: \n\n" ;

			Posicion = common::ValidarEntero("CAMPO DESEADO \n") ;

			switch(Posicion) {
				case 1 : { // IDNombre
					cout << "NUEVO NOMBRE:		" ;
					cin  >> Campo ;
					this->ArticulosDisponibles[i].setIDNombre(Campo) ;

					cout << "\nMODIFICACION EXITOSA... \n\n" ;

					break;
				}

				case 2 : { // Marca
					cout << "\nNUEVO NOMBRE DE MATERIAL: \n" ;
					cin  >> Campo ;
					this->ArticulosDisponibles[i].setIDMarca(Campo) ;

					cout << "\nMODIFICACION EXITOSA... \n\n" ;
					break;
				}

				case 3 : { // Cantidad de articulos
					cout << "\nINGRESE UNA NUEVA CANTIDAD:	" ;
					cin  >> Campo ;
					this->ArticulosDisponibles[i].setCantidadDeTipoDeArticulo(atof (Campo)) ;

					cout << "\nMODIFICACION EXITOSA... \n\n" ;

					break;
				}

				case 4 : { // Codigo
					cout << "\nINGRESE UN NUEVO CODIGO:		" ;
					cin  >> Campo ;
					this->ArticulosDisponibles[i].setCodigoArticulo(atof (Campo)) ;

					cout << "\nMODIFICACION EXITOSA... \n\n" ;

					break;
				}

				case 5 : { // Valor de Inicial Articulo
					cout << "\nINGRESE UN NUEVO VALOR INICIAL:		" ;
					cin  >> Campo ;
					this->ArticulosDisponibles[i].setValorArticuloInicial(atof(Campo)) ;

					cout << "\nMODIFICACION EXITOSA... \n\n" ;

					break;
				}

				case 6 : { // Valor Actual del Articulo
					cout << "\nINGRESE UN NUEVO VALOR ACTUAL:		" ;
					cin  >> Campo ;
					this->ArticulosDisponibles[i].setValorActualArticulo(atof(Campo)) ;

					cout << "\nMODIFICACION EXITOSA... \n\n" ;

					break;
				}

				case 7 : { // Estado del Articulo
					cout << "\nIngrese el estado del articulo: \n" ;
					cin  >> Campo ;
					this->ArticulosDisponibles[i].setEstadoArticuloDeActivo(atof(Campo)) ;

					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;

					break;
				}

				case 8 : { // Estado de Disponibilidad
					cout << "\nINGRESE ESTADO DE ARTICULO:		" ;
					cin  >> Campo ;
					this->ArticulosDisponibles[i].setEstadoDeLimiteDeArticulos(atof(Campo)) ;

					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;

					break;
				}

				case 9 : { // Estado de Asignacion
					cout << "\nINGRESE ESTADO DE DISPONIBILIDAD:		" ;
					cin  >> Campo ;
					this->ArticulosDisponibles[i].setEstadoDeAsignadoAProfesor(atof(Campo)) ;

					cout << "\nSE HA ELIMINADO LA INFORMACION ACTUAL \n" ;
					cout << "POR FAVOR INGRESE OTRO \n" ;
					system("pause") ;

					AsignarProfePrestamo(i) ;

					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;

					break;
				}

				case 10 : { // Valor de Despreciacion

					cout << "\n\n<NO PUEDES MODIFICAR ESTE CAMPO> \n" ;
					cout << "ESTA OPCION SE MANEJA A DEPENDENCIA DEL ARTICULO \n" ;
					system("pause") ;

					break;
				}

				case 11 : { // Asignado

					cout << "\nINGRESE UN NUEVO ASIGNADO:		" ;
					cin  >> Campo ;

					cout << "\nSE HA ELIMINADO LA INFORMACION DE ASIGNACION \n" ;
					cout << "POR FAVOR ASIGNAR UNO NUEVO. \n" ; 
					system("pause") ;

					AsignarProfePrestamo(i) ;

					cout << "\n\nMODIFICACION EXITOSA... \n\n" ;

					break;
				}

				default : { // Opcion Incorrecta
					cout << "\nESTA OPCION ES INCORRECTA \n\n" ;
					system("pause") ;

					ModificarDatosArticulosPrestamos(Posicion) ;

					break;
				}
			}
		}
	}

	if (Encontrado == false) {
		cout << "\n\n\tARTICULO ELIMINADO O NO EXISTENTE, SELECCIONE UNA OPCION VALIDA \n\n" ;
		system("pause") ;
	}

	ManejoDeArchivo ActualizarArticuloPrestamo ;
	ActualizarArticuloPrestamo.ActualizarArchivoArticuloDePrestamoCSV(this->ArticulosDisponibles) ;
}


/////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

// ELiminar datos de informacion
void Laboratorio::EliminarDatosDelVectorInformaciones() {
	int Opcion, Confirmar ;
	bool* ConfirmarAux = new bool (false) ; 
	
	system("cls") ;

	getInformaciones() ;

	cout << "\n00. Atras \n" ;
	cout << "\nQue informacion desea eliminar ? \n" ;
	cout << "Solo puedes eliminar los puntos que existan del 3 en adelante \n\n" ;

	Opcion = common::ValidarEntero("Elije una opcion \n") ;

	if (Opcion > 2) {
		system("cls") ;
		cout << "\nLa Inforacion que desea eliminar es la siguiente \n" ;
		cout << Informaciones[Opcion].getNombreDeInfo() << ":" ;
		cout << Informaciones[Opcion].getContenidoDeInfo() << "\n\n" ;

		Confirmar = common::ValidarEntero("Confirmar (0=no y 1=si)\n") ;

		if (Confirmar == 1) {
			system("cls") ;
			Informaciones.erase(Informaciones.begin()+Opcion, Informaciones.begin()+(Opcion+1)) ;
			*ConfirmarAux = true ; 
			cout << "\nInformacion Eliminada \n\n" ;
			system("pause") ;

		} else if (Confirmar == 0) {

			EliminarDatosDelVectorInformaciones() ;

		} else {
			cout << "\n\nOpcion incorrecta \n\n" ;
			system("pause") ;
		}

	} else if (Opcion == 00) {
		system("cls") ;
		cout << "Ya te estamos dirigiendo \n\n" ;
		system("pause") ;

	} else { // Opcion incorrecta
		cout << "\nRecuerda que no puedes eliminar esta informacion \n" ;
		cout << "Requiere mas autorizacion \n\n" ;
		system("pause") ;
	}
	
	
	if (*ConfirmarAux == true) {
		ManejoDeArchivo ManejoDeInformacion ;
		ManejoDeInformacion.CrearArchivoInformacionCSV(Informaciones)  ;
	}
	
	delete ConfirmarAux ; 	
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::EliminarDatosDelVectorProfesor() {

	system("cls") ;

	int Opcion, PosiProfe ;
	bool* Confirmar = new bool (false) ; 
	bool* Salir = new bool (false) ;
	
	this->getProfesores() ;
	
	PosiProfe = common::ValidarEntero("Elije el Profesor a eliminar \n") ;
	PosiProfe-- ; 
	
	cout << "\n1. Continuar Proceso \n" ;
	cout << "00. Atras \n\n" ;

	Opcion = common::ValidarEntero("Elije una opcion \n") ;


	do {
		switch(Opcion) {
			case 1 : { //Continuar Proceso..
				for(int i=0 ; i<this->Profesores.size() ; i++) {
					if(PosiProfe == i) {
						system("cls") ;
						
						this->EliminarAsignado(PosiProfe) ; 
												
						Profesores.erase(Profesores.begin()+PosiProfe , Profesores.begin()+(PosiProfe+1)) ;
											
						*Confirmar = true ; 
						cout <<"\nAccion Exitosa\n" ;
						*Salir = true ;
					}
				}
				break ;
			}

			case 00 : {//Atras
				*Salir = true ;
				break;
			}

			default : {//Opcion incorrecta
				cout << "\n\nOPCION INCORRECTA \n\n" ;
				system("pause") ;
				break;
			}
		}
	} while(!*Salir) ;

	if (*Confirmar == true) {
		ManejoDeArchivo ManejoDeProfesores ;
		ManejoDeProfesores.ActualizarArchivoProfesorCSV(this->Profesores) ;
		ManejoDeProfesores.ActualizarComputoCSV(this->ArticulosComp) ; 
		ManejoDeProfesores.ActualizarArchivoArticuloDePrestamoCSV(this->ArticulosDisponibles) ;
		ManejoDeProfesores.ActualizarMuebleCSV(this->ArticulosMuebles) ; 
	}
	
	delete Salir, Confirmar ;
}
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::EliminarDatosDelVectorEstudiante(int Opcion) {

	Opcion-- ; 
	system("cls") ;

	int Confirmacion ;
	bool* Confirmar = new bool (false) ; 
	bool* Salir = new bool (false) ;

	cout << "1. Continuar Proceso \n" ;
	cout << "00. Atras \n\n" ;

	Confirmacion = common::ValidarEntero("Elije una opcion \n") ;


	do {
		switch(Confirmacion) {
			case 1 : { //Continuar Proceso..
				for(int i=0 ; i<this->Estudiantes.size() ; i++) {
					if(Opcion == i+1) {
						system("cls") ;
						Estudiantes.erase(Estudiantes.begin()+Opcion , Estudiantes.begin()+(Opcion+1)) ;
						*Confirmar = true ; 
						cout <<"\nAccion Exitosa\n" ;
						*Salir = true ;
					}
				}
				break ;
			}

			case 00 : {//Atras
				*Salir = true ;
				break;
			}

			default : {//Opcion incorrecta
				cout << "\n\nOPCION INCORRECTA \n\n" ;
				system("pause") ;
				break;
			}
		}
	} while(!*Salir) ;

	if (*Confirmar == true) {
		ManejoDeArchivo ManejoDeEstudiantes ;
		ManejoDeEstudiantes.ActualizarArchivoEstudianteCSV(this->Estudiantes) ;
		ManejoDeEstudiantes.ActualizarPrestados(this->Estudiantes) ; 
	}
	
	delete Salir, Confirmar ; 
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::EliminarDatosDelVectorComputo() {
	int Opcion ;
	bool* Confirmar = new bool (false) ; 

	system("cls") ;

	getComputo() ;

	cout << "\n00. Atras \n" ;
	cout << "\nQue informacion desea eliminar ? \n" ;

	Opcion = common::ValidarEntero("Elije una opcion \n") ;

	for (int i=0 ; i<this->ArticulosComp.size() ; i++) {
		if (Opcion == i+1) {
			cout << "\nEl articulo que desea eliminar se le mostrara a continuacion \n\n" ;
			system("pause") ;

			AccederAComputo(Opcion) ;
			
			Opcion-- ; 

			this->ArticulosComp.erase(this->ArticulosComp.begin()+Opcion, this->ArticulosComp.begin()+(Opcion+1)) ;
			
			*Confirmar = true ; 
			cout << "\n\nEsta informacion se ha elimando correctamente \n" ;
			cout << "Proceso Exitoso !!! \n\n" ;
		}
	}

	if (Opcion == 00) {
		cout << "\nEn este momento sera transladado al menu anterior \n\n" ;
	}
	
	if (*Confirmar == true) {
		ManejoDeArchivo ActualizarComputo ;
		ActualizarComputo.ActualizarComputoCSV(this->ArticulosComp) ;
	}else {
		system("cls") ; 
		cout << "\nError el indicador no existe \n\n" ;
		cout << "Por favor intente de nuevo \n\n" ; 
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::EliminarDatosDelVectorMueble() {
	int Opcion ;
	bool* Confirmar = new bool (false) ; 

	system("cls") ;

	getMuebles() ;

	cout << "\n00. Atras \n" ;
	cout << "\nQue informacion desea eliminar ? \n" ;

	Opcion = common::ValidarEntero("Elije una opcion \n") ;

	for (int i=0 ; i<this->ArticulosMuebles.size() ; i++) {
		if (Opcion == i+1) {
			cout << "\nEl articulo que desea eliminar se le mostrara a continuacion \n\n" ;
			system("pause") ;

			AccederAMueble(Opcion) ;
			
			Opcion-- ; 
			
			this->ArticulosMuebles.erase(this->ArticulosMuebles.begin()+Opcion, this->ArticulosMuebles.begin()+(Opcion+1)) ;
			
			*Confirmar = true ; 
			cout << "\n\nEsta informacion se ha elimando correctamente \n" ;
			cout << "Proceso Exitoso !!! \n\n" ;
		}
	}

	if (Opcion == 00) {
		cout << "\nEn este momento sera transladado al menu anterior \n\n" ;
	}
	
	if (*Confirmar == true) {
		ManejoDeArchivo ActualizarMueble ;
		ActualizarMueble.ActualizarMuebleCSV(this->ArticulosMuebles) ;
	}else {
		system("cls") ; 
		cout << "\nError el indicador no existe \n\n" ;
		cout << "Por favor intente de nuevo \n\n" ; 
	}
	
	delete Confirmar ; 
}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////



void Laboratorio::EliminarDatosDelVectorArticuloPrestamos() {

	int Opcion ;
	bool* Confirmar = new bool (false) ; 

	system("cls") ;

	getPrestamos() ;

	cout << "\n00. Atras \n" ;
	cout << "\nQue informacion desea eliminar ? \n" ;

	Opcion = common::ValidarEntero("Elije una opcion \n") ;

	for (int i=0 ; i<this->ArticulosDisponibles.size() ; i++) {
		if (Opcion == i+1) {
			cout << "\nEl articulo que desea eliminar se le mostrara a continuacion \n\n" ;
			system("pause") ;

			AccederArticulosPrestamo(Opcion) ;
			
			Opcion-- ; 
			
			for (int i=0 ; i<this->Estudiantes.size() ; i++) {
				for (int j=0 ; j<this->Estudiantes[i].MisArticulos().size() ; j++) {
					if (this->Estudiantes[i].MisArticulos()[j]->getCodigoArticulo() == this->ArticulosDisponibles[Opcion].getCodigoArticulo()) {
						this->Estudiantes[i].MisArticulos().erase(this->Estudiantes[i].MisArticulos().begin()+ j, this->Estudiantes[i].MisArticulos().begin()+ (j+1)) ;
					}					
				}	
			}
			
			this->ArticulosDisponibles.erase(this->ArticulosDisponibles.begin()+Opcion, this->ArticulosDisponibles.begin()+(Opcion+1)) ;
			
			
			*Confirmar = true ; 
			cout << "\n\nEsta informacion se ha elimando correctamente \n" ;
			cout << "Proceso Exitoso !!! \n\n" ;
		}
	}

	if (Opcion == 00) {
		cout << "\nEn este momento sera transladado al menu anterior \n\n" ;
	}
	
	if (*Confirmar == true) {
		ManejoDeArchivo ActualizarArticuloPrestamo ;
		ActualizarArticuloPrestamo.ActualizarArchivoArticuloDePrestamoCSV(this->ArticulosDisponibles) ;
		ActualizarArticuloPrestamo.ActualizarPrestados(this->Estudiantes) ; 
	}else {
		system("cls") ; 
		cout << "\nError el indicador no existe \n\n" ;
		cout << "Por favor intente de nuevo \n\n" ; 
	}
	
	delete Confirmar ; 
}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::EliminarDatosDelVectorAdmi() {
	int Opcion ;
	bool* Confirmar = new bool (false) ; 

	system("cls") ;

	this->getPersonalAdmin() ; 

	cout << "\n00. Atras \n" ;
	cout << "\nQue informacion desea eliminar ? \n" ;

	Opcion = common::ValidarEntero("Elije una opcion \n") ;

	for (int i=0 ; i<this->PersonalAdmin.size() ; i++) {
		if (Opcion == i+1) {
			cout << "\nEl articulo que desea eliminar se le mostrara a continuacion \n\n" ;
			system("pause") ;

			this->AccederPersonalAdmi(Opcion) ; 
			
			Opcion-- ; 

			this->PersonalAdmin.erase(this->PersonalAdmin.begin()+Opcion, this->PersonalAdmin.begin()+(Opcion+1)) ;
			
			*Confirmar = true ;
			cout << "\n\nEsta informacion se ha elimando correctamente \n" ;
			cout << "Proceso Exitoso !!! \n\n" ;
		}
	}

	if (Opcion == 00) {
		cout << "\nEn este momento sera transladado al menu anterior \n\n" ;
	}
	
	if (*Confirmar == true) {
		ManejoDeArchivo ActualizaAdmi ;
		ActualizaAdmi.ActualizarAdimisCSV(this->PersonalAdmin) ;
	}else {
		system("cls") ; 
		cout << "\nError el indicador no existe \n\n" ;
		cout << "Por favor intente de nuevo \n\n" ; 
	}
	delete Confirmar ; 
}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::EliminarHistorial() {
	system("cls") ; 
	
	ParaHistoriales.clear() ; 
	
	ManejoDeArchivo ActualizarHistorial ; 
	ActualizarHistorial.ActualizarHistorial(ParaHistoriales) ;
	
	cout << "\n\tSE HA ELIMINADO TODO EL HISTORIAL DEL LABORATORIO \n\n" ; 
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::EliminarAsignado(int Posicion) {
	
	for (int i=0 ; i<this->ArticulosComp.size() ; i++) {
		if (this->Profesores[Posicion].getCodigo() == this->ArticulosComp[i].getProfesor()->getCodigo()) {
			system("cls") ;
			cout << "\n\tAL ELIMINAR AL PROFESOR NECESITAS ASIGNARLE UN PROFESOR AL ARTICULO QUE ESTE TENIA A CARGO \n\n" ; 
			this->AsignarProfesorComputo(i+1) ; 
		} 
	}	
	
	for (int i=0 ; i<this->ArticulosDisponibles.size() ; i++) {
		if (this->Profesores[Posicion].getCodigo() == this->ArticulosDisponibles[i].getProfesor()->getCodigo()) {
			system("cls") ;
			cout << "\n\tAL ELIMINAR AL PROFESOR NECESITAS ASIGNARLE UN PROFESOR AL ARTICULO QUE ESTE TENIA A CARGO \n\n" ; 
			this->AsignarProfePrestamo(i+1) ; 
		} 
	}
	
	for (int i=0 ; i<this->ArticulosMuebles.size() ; i++) {
		if (this->Profesores[Posicion].getCodigo() == this->ArticulosMuebles[i].getProfesorAsignado()->getCodigo()) {
			system("cls") ;
			cout << "\n\tAL ELIMINAR AL PROFESOR NECESITAS ASIGNARLE UN PROFESOR AL ARTICULO QUE ESTE TENIA A CARGO \n\n" ; 
			this->AsignarProfeMueble(i+1) ; 
		} 
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::AccederProfesorPosicion(int Posicion) {
	
	system("cls") ;
	Posicion-- ; 
	
	for (int i=0 ; i<this->Profesores.size() ; i++) {
		if (i == Posicion) {
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
			cout << "\n\tDATOS PERSONALES PROFESOR: " << "\n\n" ;
			cout << "1. NOMBRE		" << Profesores[i].getNombre() << "\n" ;
			cout << "2. APELLIDO		" << Profesores[i].getApellido() << "\n" ;
			cout << "3. E-MAIL		" << Profesores[i].getEmail() << "\n" ;
			cout << "4. EDAD:		" << Profesores[i].getEdad() << "\n" ;
			cout << "5. CEDULA:		" << Profesores[i].getCedula() << "\n" ;
			cout << "6. TELEFONO:		" << Profesores[i].getTelefono() << "\n" ;
			cout << "7. CODIGO:		" << Profesores[i].getCodigo() << "\n" ;
			cout << "8. TITULO PROFESIONAL:	" << Profesores[i].getTituloProfesional() << "\n" ;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::AccederArticulosProfe(int Posicion) {
	system("cls") ;
	Posicion-- ;
	int Itera = 1 ;
	
	cout << "\n\tLos articulos Asignados al profesor son: \n\n" ;
	
	if (this->VerificarArticulosCompu() == false) {
		for (int i=0 ; i<this->ArticulosComp.size() ; i++) {
			if (this->Profesores[Posicion].getCodigo() == this->ArticulosComp[i].getProfesor()->getCodigo()) {
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
				cout << "-Articulo #" << i+1 << "\n\n" ;
				cout << "-NOMBRE:				" << ArticulosComp[i].getIDNombre() << "\n" ;
				cout << "-MARCA:				" << ArticulosComp[i].getIDMarca() << "\n" ;
				cout << "-CANTIDAD:			" << ArticulosComp[i].getCantidad() << "\n" ;
				cout << "-CODIGO:				" << ArticulosComp[i].getCodigoArticulo() << "\n" ;
				cout << "-VALOR ARTICULO:		" << ArticulosComp[i].getValorArticuloInicial() << "\n" ; 
				cout << "-VALOR ACTUAL: 			" << ArticulosComp[i].getValorActualArticulo() << "\n" ;
				cout << "-ESTADO DEL ARTICULO:		" << ArticulosComp[i].getEstadoArticuloDeActivo() << "\n" ;
				cout << "-DISPONIBILIDAD: 		" << ArticulosComp[i].getEstadoDeLimiteDeArticulos() << "\n" ; // Este es para saber si aun hay articulos de este tipo
				cout << "-ESTADO DE ASIGNACION:		" << ArticulosComp[i].getEstadoDeAsignadoAProfesor() << "\n" ;
				cout << "-VALOR DE DESPRECIACION:		" << ArticulosComp[i].getDespreciacion() << "\n" ;
				cout << "-ASIGNADO AL PROFESOR:		" << ArticulosComp[i].getProfesor()->getNombre() << "\n" ;  
				cout << "-CODIGO DEL PROFESOR:		" << ArticulosComp[i].getProfesor()->getCodigo() << "\n" ;  
				Itera ++ ;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
			}
		}
	}
	
	if (this->VerificarArticulosMueble() == false) {
		for (int i=0 ; i<this->ArticulosMuebles.size() ; i++) {
			if (this->Profesores[Posicion].getCodigo() == this->ArticulosMuebles[i].getProfesorAsignado()->getCodigo()) {
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
				cout << "-Articulo #" << i+1 << "\n\n" ;
				cout << "-NOMBRE:				" << ArticulosComp[i].getIDNombre() << "\n" ;
				cout << "-MARCA:				" << ArticulosComp[i].getIDMarca() << "\n" ;
				cout << "-CANTIDAD:			" << ArticulosComp[i].getCantidad() << "\n" ;
				cout << "-CODIGO:				" << ArticulosComp[i].getCodigoArticulo() << "\n" ;
				cout << "-VALOR ARTICULO:		" << ArticulosComp[i].getValorArticuloInicial() << "\n" ; 
				cout << "-VALOR ACTUAL: 			" << ArticulosComp[i].getValorActualArticulo() << "\n" ;
				cout << "-ESTADO DEL ARTICULO:		" << ArticulosComp[i].getEstadoArticuloDeActivo() << "\n" ;
				cout << "-DISPONIBILIDAD: 		" << ArticulosComp[i].getEstadoDeLimiteDeArticulos() << "\n" ; // Este es para saber si aun hay articulos de este tipo
				cout << "-ESTADO DE ASIGNACION:		" << ArticulosComp[i].getEstadoDeAsignadoAProfesor() << "\n" ;
				cout << "-VALOR DE DESPRECIACION:		" << ArticulosComp[i].getDespreciacion() << "\n" ;
				cout << "-ASIGNADO AL PROFESOR:		" << ArticulosComp[i].getProfesor()->getNombre() << "\n" ;  
				cout << "-CODIGO DEL PROFESOR:		" << ArticulosComp[i].getProfesor()->getCodigo() << "\n" ;  
				Itera ++ ;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
			}
		}
	}
	
	if (this->VerificarArticulosPrestamo() == false) {
		for (int i=0 ; i<this->ArticulosDisponibles.size() ; i++) {
			if (this->Profesores[Posicion].getCodigo() == this->ArticulosDisponibles[i].getProfesor()->getCodigo()) {
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
				cout << "-Articulo #" << i+1 << "\n\n" ;
				cout << "-NOMBRE:				" << ArticulosComp[i].getIDNombre() << "\n" ;
				cout << "-MARCA:				" << ArticulosComp[i].getIDMarca() << "\n" ;
				cout << "-CANTIDAD:			" << ArticulosComp[i].getCantidad() << "\n" ;
				cout << "-CODIGO:				" << ArticulosComp[i].getCodigoArticulo() << "\n" ;
				cout << "-VALOR ARTICULO:		" << ArticulosComp[i].getValorArticuloInicial() << "\n" ; 
				cout << "-VALOR ACTUAL: 			" << ArticulosComp[i].getValorActualArticulo() << "\n" ;
				cout << "-ESTADO DEL ARTICULO:		" << ArticulosComp[i].getEstadoArticuloDeActivo() << "\n" ;
				cout << "-DISPONIBILIDAD: 		" << ArticulosComp[i].getEstadoDeLimiteDeArticulos() << "\n" ; // Este es para saber si aun hay articulos de este tipo
				cout << "-ESTADO DE ASIGNACION:		" << ArticulosComp[i].getEstadoDeAsignadoAProfesor() << "\n" ;
				cout << "-VALOR DE DESPRECIACION:		" << ArticulosComp[i].getDespreciacion() << "\n" ;
				cout << "-ASIGNADO AL PROFESOR:		" << ArticulosComp[i].getProfesor()->getNombre() << "\n" ;  
				cout << "-CODIGO DEL PROFESOR:		" << ArticulosComp[i].getProfesor()->getCodigo() << "\n" ;  
				Itera ++ ;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::AccederProfesor(int Codigo, int CodigoArticulo) {


	for (int i=0 ; i<this->Profesores.size() ; i++) {
		if (Codigo == this->Profesores[i].getCodigo()) {
			for (int j=0 ; j<this->ArticulosComp.size() ; j++) {
				if(CodigoArticulo == this->ArticulosComp[j].getCodigoArticulo()) {
					this->ArticulosComp[j].AsignarAlArticulo(&this->Profesores[i]) ;
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::AccederProfesorMueb(int Codigo, int CodigoArticulo) {

	for (int i=0 ; i<this->Profesores.size() ; i++) {
		if (Codigo == this->Profesores[i].getCodigo()) {
			for (int j=0 ; j<this->ArticulosMuebles.size() ; j++) {
				if(CodigoArticulo == this->ArticulosMuebles[j].getCodigoArticulo()) {
					this->ArticulosMuebles[j].AsignarAlArticulo(&this->Profesores[i]) ;
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::AccederProfesorArtPrestamo(int Codigo, int CodigoArticulo) {

	for (int i=0 ; i<this->Profesores.size() ; i++) {
		if (Codigo == this->Profesores[i].getCodigo()) {
			for (int j=0 ; j<this->ArticulosDisponibles.size() ; j++) {
				if(CodigoArticulo == this->ArticulosDisponibles[j].getCodigoArticulo()) {
					this->ArticulosDisponibles[j].AsignarAProfesor(&this->Profesores[i]) ;
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////


void Laboratorio::AccederAUnEstudiante(int Posicion) {
	system("cls") ;
	Posicion-- ;
	for (int i=0 ; i<this->Estudiantes.size() ; i++) {
		if (i == Posicion) {
			cout << "\n\tSus datos Actuales: " << "\n\n" ;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
			cout << "-Nombre:			" << Estudiantes[i].getNombre() << "\n" ;
			cout << "-Apellido:			" << Estudiantes[i].getApellido() << "\n" ;
			cout << "-Email:				" << Estudiantes[i].getEmail() << "\n" ;
			cout << "-Edad:				" << Estudiantes[i].getEdad() << "\n" ;
			cout << "-Cedula:			" << Estudiantes[i].getCedula() << "\n" ;
			cout << "-Telefono:			" << Estudiantes[i].getTelefono() << "\n" ;
			cout << "-Carrera:			" << Estudiantes[i].getCarrera() << "\n" ;
			cout << "-Codigo:			" << Estudiantes[i].getCodigo() << "\n" ;
			cout << "-Semestre:			" << Estudiantes[i].getSemestre() << "\n" ;
			cout << "-Valor la multa acomulada:	" << Estudiantes[i].getValorMultaAcomulada() << "\n" ;
			cout << "-Estado de multa:		" << Estudiantes[i].getEstadoDeMulta()<< "\n" ;
			cout << "-Estado de estudiante:		" << Estudiantes[i].getEstadoDeEstudiante() << "\n\n" ;
			if (this->Estudiantes[i].MisArticulos().empty()) {
				cout << "Articulos Prestados:" << 0 << "\n\n" ;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
			} else {
				//for (int j=0 ; j<this->Estudiantes[i].MisArticulos().size() ; j++) {
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
				this->Estudiantes[i].MostrarTodosLosArticulos() ;
				//}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////


void Laboratorio::AccederPersonalAdmi(int Posicion) {
	system("cls") ;
	Posicion-- ;
	for (int i=0 ; i<this->PersonalAdmin.size() ; i++) {
		if (i == Posicion) {
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
			cout << "\n\tDATOS PERSONALES PERSONAL ADMINISTRATIVO: " << "\n\n" ;
			cout << "-Nombre:		" << PersonalAdmin[i].getNombre() << "\n" ;
			cout << "-Apellido:	" << PersonalAdmin[i].getApellido() << "\n" ;
			cout << "-Email:		" << PersonalAdmin[i].getEmail() << "\n" ;
			cout << "-Edad:		" << PersonalAdmin[i].getEdad() << "\n" ;
			cout << "-Cedula:	" << PersonalAdmin[i].getCedula() << "\n" ;
			cout << "-Telefono:	" << PersonalAdmin[i].getTelefono() << "\n\n" ;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::AccederAComputo(int Posicion) {
	system("cls") ;
	Posicion-- ; 
	
	for (int i=0 ; i<this->ArticulosComp.size() ; i++) {
		if (Posicion == i) {
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
			cout << "Articulo #" << i+1 << "\n\n" ;
			cout << "-Nombre:		" << ArticulosComp[i].getIDNombre() << "\n" ;
			cout << "-Marca:	" << ArticulosComp[i].getIDMarca() << "\n" ;
			cout << "-Cantidad:		" << ArticulosComp[i].getCantidad() << "\n" ;
			cout << "-Codigo:		" << ArticulosComp[i].getCodigoArticulo() << "\n" ;
			cout << "-Valor del Articulo:	" << ArticulosComp[i].getValorArticuloInicial() << "\n" ; 
			cout << "-Valor Actual:		" << ArticulosComp[i].getValorActualArticulo() << "\n" ;
			cout << "-Estado del Articulo:		" << ArticulosComp[i].getEstadoArticuloDeActivo() << "\n" ;
			cout << "-Disponibilidad:	" << ArticulosComp[i].getEstadoDeLimiteDeArticulos() << "\n" ; // Este es para saber si aun hay articulos de este tipo
			cout << "-Estado de Asigancion:		" << ArticulosComp[i].getEstadoDeAsignadoAProfesor() << "\n" ;
			cout << "-Valor de despreciacion:	" << ArticulosComp[i].getDespreciacion() << "\n" ;
			cout << "-Asignado al Profesor:		" << ArticulosComp[i].getProfesor()->getNombre() << "\n" ;  
			cout << "-Codigo del Profesor:		" << ArticulosComp[i].getProfesor()->getCodigo() << "\n" ;  
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
		}
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::AccederAMueble(int Posicion) {
//	system("cls") ;
	Posicion-- ; 
	
	for (int i=0 ; i<this->ArticulosMuebles.size() ; i++) {
		if (Posicion == i) {
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
			cout << "Articulo #" << i+1 << "\n\n" ;
			cout << "-Nombre: " << ArticulosMuebles[i].getIDNombre() << "\n" ;
			cout << "-Material: " << ArticulosMuebles[i].getMaterial() << "\n" ;
			cout << "-Cantidad: " << ArticulosMuebles[i].getCantidad() << "\n" ;
			cout << "-Codigo: " << ArticulosMuebles[i].getCodigoArticulo() << "\n" ;
			cout << "-Valor del Articulo: " << ArticulosMuebles[i].getValorArticuloInicial() << "\n" ; 
			cout << "-Valor Actual: " << ArticulosMuebles[i].getValorActualArticulo() << "\n" ;
			cout << "-Estado del Articulo: " << ArticulosMuebles[i].getEstadoArticuloDeActivo() << "\n" ;
			cout << "-Disponibilidad: " << ArticulosMuebles[i].getEstadoDeLimiteDeArticulos() << "\n" ; // Este es para saber si aun hay articulos de este tipo
			cout << "-Estado de Asigancion: " << ArticulosMuebles[i].getEstadoDeAsignadoAProfesor() << "\n" ;
			cout << "-Valor de despreciacion: " << ArticulosMuebles[i].getDespreciacion() << "\n" ;
			cout << "-Asignado al Profesor: " << ArticulosMuebles[i].getProfesorAsignado()->getNombre() << "\n" ;  
			cout << "-Codigo del Profesor: " << ArticulosMuebles[i].getProfesorAsignado()->getCodigo() << "\n" ;  
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::AccederArticulosPrestamo(int Posicion) {
//	system("cls") ;
	Posicion-- ;
	cout << "\n\t\tLos datos existentes del articulo son los siguientes \n\n" ;
	for(int i=0 ; i<this->ArticulosDisponibles.size() ; i++) {
		if (Posicion == i) {
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
			cout << "\n\t Articulo #" << i+1 << "\n\n" ;
			cout << "1. Nombre: " << ArticulosDisponibles[i].getIDNombre() << "\n" ;
			cout << "2. Marca: "  << ArticulosDisponibles[i].getIDMarca() << "\n" ;
			cout << "3. Cantidad: " << ArticulosDisponibles[i].getCantidadDeTipoDeArticulo() << "\n" ;
			cout << "4. Codigo: " << ArticulosDisponibles[i].getCodigoArticulo() << "\n" ;
			cout << "5. Valor Articulo: " << ArticulosDisponibles[i].getValorArticuloInicial() << "\n" ;
			cout << "6. Valor Actual: " << ArticulosDisponibles[i].getValorActualArticulo() << "\n" ;
			cout << "7. Estado: " << ArticulosDisponibles[i].getEstadoArticuloDeActivo() << "\n" ;
			cout << "8. Estado Limite: " << ArticulosDisponibles[i].getEstadoDeLimiteDeArticulos() << "\n" ;
			cout << "9. Asignado al profesor: " << ArticulosDisponibles[i].getEstadoDeAsignadoAProfesor() << "\n" ;
			cout << "10.Valor de despreciacion: " << ArticulosDisponibles[i].getDespreciacion() << "\n" ;
			cout << "11. Asignado al Profesor: " << ArticulosDisponibles[i].getProfesor()->getNombre() << "\n" ;
			cout << "    Codigo del Profesor: " << ArticulosDisponibles[i].getProfesor()->getCodigo() << "\n" ;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::AccederEstadoMultaEstudiante(int Posicion) {
	system ("cls") ;

	cout << "SU ESTADO ES : " << this->Estudiantes[Posicion-1].getEstadoDeEstudiante() << "\n" ;
	cout << "SU ESTADO DE MULTA ES: " << this->Estudiantes[Posicion-1].getEstadoDeMulta() << "\n" ;
	cout << "SEL VALOR DE MULTA ACUMULADO ES:" << this->Estudiantes[Posicion-1].getValorMultaAcomulada() << "\n\n" ; 
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::AsignarCodigosEstudiantes() {
	CodigosDeEstudiantes.clear() ;

	for (int i=0 ; i<this->Estudiantes.size() ; i++) {
		int Codigo = this->Estudiantes[i].getCodigo() ; 
		int* CodigoAux = &Codigo ;
		CodigosDeEstudiantes.push_back(CodigoAux) ;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::AsignarProfesorComputo(int Posicion) {
	int Asignar ;
	bool* Confirmar = new bool (false);

	if (VerificarVectorProfesores() == false) {
		// Mostrar todos los profesores para asignar
		getProfesores() ;

		Asignar = common::ValidarEntero("\nASIGNELE UN PROFESOR RESPONSABLE \n\n") ;
		
		Asignar-- ;
		
		// Asignarle el Articulo
		for (int i=0 ; i<this->Profesores.size() ; i++) {
			if (Asignar == i) {
				this->ArticulosComp[Posicion-1].AsignarAlArticulo(&this->Profesores[i]) ;
				cout << "\nASIGNACION EXITOSA \n\n" ;
				system("pause") ;
				*Confirmar = true ;
			}
		}
	} else {
		cout << "NO HAY DATOS EXISTENTES \n\n" ;
		system("pause") ;
	}
	
	if (*Confirmar == false) {
		cout << "\nEL INDICADOR NO EXISTE \n\n" ;
		cout << "INTENTA DE NUEVO \n\n" ;
		system("pause") ;
		AsignarProfesorComputo(Posicion) ;
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
void Laboratorio::AsignarProfeMueble(int Posicion) {
	
	int Asignar ;
	bool* Confirmar = new bool (false);
	
	if (VerificarVectorProfesores() == false) {
		// Mostrar todos los profesores para asignar
		getProfesores() ;
	
		Asignar = common::ValidarEntero("\nASIGNELE UN PROFRESOR RESPONSABLE \n\n") ;
	
		Asignar-- ;
		
		// Asignarle el Articulo
		for (int i=0 ; i<this->Profesores.size() ; i++) {
			if (Asignar == i) {
				this->ArticulosMuebles[Posicion-1].AsignarAlArticulo(&this->Profesores[i]) ;
				cout << "\nASIGNACION EXITOSA \n\n" ;
				system("pause") ;
				*Confirmar = true ;
			}
		}	
	}else {
		cout << "NO EXISTEN DATOS \n\n" ;
		system("pause") ;
	}
	
	if (*Confirmar == false) {
		cout << "\nEL INDICADOR NO EXISTE \n\n" ;
		cout << "INTENTA DE NUEVOI \n\n" ;
		system("pause") ;
		AsignarProfeMueble(Posicion) ;
	}
	
}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::AsignarProfePrestamo(int Posicion) {

	int Asignar ;
	bool* Confirmar = new bool (false);
	
	if (VerificarVectorProfesores() == false) {
		
		getProfesores();
	
		Asignar = common::ValidarEntero("\nASIGNELE UN PROFRESOR RESPONSABLE \n\n") ;
		
		Asignar-- ;
	
		for(int i=0; i<this->Profesores.size(); i++) {
			if (Asignar == i) {
				this->ArticulosDisponibles[Posicion-1].AsignarAProfesor(&this->Profesores[i]) ;
	
				cout << " \nASIGNACION EXITOSA \n\n" ;
				system("pause") ;
				*Confirmar = true ;
			}
		}
	}else {
		cout << "NO EXISTEN DATOS \n\n" ;
		system("pause") ;
	}
	
	if (*Confirmar == false) {
		cout << "\nNO EXISTE EL INDICADOR  \n\n" ;
		cout << "INTENTA DE NUEVO \n\n" ;
		system("pause") ;
		AsignarProfePrestamo(Posicion) ;
	}
	
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::AsignarFechaComputo(int Posicion) {
	system("cls") ;
	int DatosFecha ;
	Fecha* FechaActual = new Fecha ;

	cout << "\nASIGNE UNA FECHA \n\n" ;
	DatosFecha = common::ValidarEntero("\nANIO DE ENTRADA:	") ;
	FechaActual->setAnio(DatosFecha) ;

	DatosFecha = common::ValidarEntero("\nMES DE ENTRADA:	") ;
	FechaActual->setMes(DatosFecha) ;

	DatosFecha = common::ValidarEntero("\nDIA DE ENTRADA:	") ;
	FechaActual->setDia(DatosFecha) ;

	bool Estado = FechaActual->ValidarFormatoDeFecha(FechaActual, this->FechaInicio) ; 
	
	if (Estado == true) {
		this->ArticulosComp[Posicion-1].AsignarFecha(FechaActual) ;
		cout << "\n\nFECHA REGISTRADA CON EXITO !!! \n\n" ;
		system("pause") ;
	}else {
		AsignarFechaComputo(Posicion) ;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::AsignarFechaMueble(int Posicion) {
	system("cls") ;
	int DatosFecha ;
	Fecha* FechaActual = new Fecha ;

	cout << "\nASIGNE UNA FECHA \n\n" ;
	DatosFecha = common::ValidarEntero("\nANIO DE ENTRADA:	") ;
	FechaActual->setAnio(DatosFecha) ;

	DatosFecha = common::ValidarEntero("\nMES DE ENTRADA:	") ;
	FechaActual->setMes(DatosFecha) ;

	DatosFecha = common::ValidarEntero("\nDIA DE ENTRADA:	") ;
	FechaActual->setDia(DatosFecha) ;
	
	bool Estado = FechaActual->ValidarFormatoDeFecha(FechaActual, this->FechaInicio) ; 
	
	if (Estado == true) {
		this->ArticulosMuebles[Posicion-1].AsignarFecha(FechaActual) ;
		cout << "\n\nFECHA REGISTRADA CON EXITO !!! \n\n" ;
		system("pause") ;
	}else {
		AsignarFechaMueble(Posicion) ;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::AsignarFechaPrestamo(int Posicion) {
	system("cls") ;
	int DatosFecha ;
	Fecha* FechaActual = new Fecha ;

	cout << "\nASIGNE UNA FECHA \n\n" ;
	DatosFecha = common::ValidarEntero("\nANIO DE ENTRADA:	") ;
	FechaActual->setAnio(DatosFecha) ;

	DatosFecha = common::ValidarEntero("\nMES DE ENTRADA:	") ;
	FechaActual->setMes(DatosFecha) ;

	DatosFecha = common::ValidarEntero("\nDIA DE ENTRADA:	") ;
	FechaActual->setDia(DatosFecha) ;

	bool Estado = FechaActual->ValidarFormatoDeFecha(FechaActual, this->FechaInicio) ; 
	
	if (Estado == true) {
		this->ArticulosDisponibles[Posicion-1].AsignarFecha(FechaActual) ;
		cout << "\n\nFECHA REGISTRADA CON EXITO !!! \n\n" ;
		system("pause") ;
	}else {
		AsignarFechaPrestamo(Posicion) ;
	}	
}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::ConsultaProfeArticulos() {
	system("cls") ;
	int Codigo ;
	bool Confirmar = false ;
	bool ConfirmarCompu = false ;
	bool ConfirmarMuebl = false ;
	bool ConfirmarPrest = false ;

	Codigo = common::ValidarEntero("\nINGRESE EL CODIGO DEL PROFESOR QUE DESEA ENCONTRAR \n\n") ;

	if (this->VerificarVectorProfesores() == false) {
		for (int i=0 ; i<this->Profesores.size() ; i++) {
			if (Codigo == Profesores[i].getCodigo()) {
				Codigo = Profesores[i].getCodigo() ;
				Confirmar = true ;
			}
		}
	} else {
		system("cls") ;
		cout << "NO EXISTEN DATOS DEL PROFESOR \n\n" ;
	}

	if (Confirmar == true) {
		for(int i=0 ; i<this->ArticulosComp.size() ; i++) {
			if(this->ArticulosComp[i].getProfesor()->getCodigo() == Codigo) {
				cout << "\tARTICULOS DE COMPUTO \n\n" ;
				AccederAComputo(i+1) ;
				cout << "\n\n" ;
			}else {
				ConfirmarCompu = true ;
			}
		}

		for(int i=0 ; i<this->ArticulosMuebles.size() ; i++) {
			if(this->ArticulosMuebles[i].getProfesorAsignado()->getCodigo() == Codigo) {
				cout << "\tARTICULOS DE MUEBLE\n\n" ;
				AccederAMueble(i+1) ;
				cout << "\n\n" ;
			}else {
				ConfirmarMuebl = true ; 
			}
		}

		for(int i=0 ; i<this->ArticulosDisponibles.size() ; i++) {
			if(this->ArticulosDisponibles[i].getProfesor()->getCodigo() == Codigo) {
				cout << "\tARTICULOS DE PRESTAMO \n\n" ;
				AccederArticulosPrestamo(i+1) ;
				cout << "\n\n" ;
			}else {
				ConfirmarPrest = true ;
			}
		}
	} else {
		system("cls") ;
		cout << "\nO SE HA ENCONTRADO RESULTADOS DE BUSQUEDA \n\n" ;
	}
	
	
	if ((ConfirmarCompu == true) && (ConfirmarMuebl == true) && (ConfirmarPrest == true)) {
		system("cls") ;
		cout << "\n\tNO TIENE ARTICULOS ASIGNADOS  \n\n" ;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////


void Laboratorio::ConsultaAsignacionArt() {
	system("cls") ; 
	
	int Codigo ;
	bool Confirmar = false ;
	bool ConfirmarCompu = false ;
	bool ConfirmarMuebl = false ;
	bool ConfirmarPrest = false ;

	Codigo = common::ValidarEntero("\nINGRESE EL CODIGO DEL PROFESOR QUE DESEA ENCONTRAR \n\n") ;

	if (this->VerificarArticulosCompu() == false) {
		for (int i=0 ; i<this->ArticulosComp.size() ; i++) {
			if (this->ArticulosComp[i].getCodigoArticulo() == Codigo) {
				cout << "\nEl ARTICULO DE COMPUTO A CARGO DE : \n\n" ;
				cout << "Nombre:	"<< this->ArticulosComp[i].getProfesor()->getNombre() << "\n" ;
				cout << "Apellido:	"<< this->ArticulosComp[i].getProfesor()->getApellido() << "\n" ;
				cout << "Codigo:	"<< this->ArticulosComp[i].getProfesor()->getCodigo() << "\n" ;
				cout << "Cedula:	"<< this->ArticulosComp[i].getProfesor()->getCedula() << "\n" ;
			}else {
				ConfirmarCompu = true ;
			}
		}
	}
	
	if (this->VerificarArticulosMueble() == false) {
		for (int i=0 ; i<this->ArticulosMuebles.size() ; i++) {
			if (this->ArticulosMuebles[i].getCodigoArticulo() == Codigo) {
				cout << "\nEl ARTICULO DE MUEBLE A CARGO DE : \n\n" ;
				cout << "Nombre:	"<< this->ArticulosMuebles[i].getProfesorAsignado()->getNombre() << "\n" ;
				cout << "Apellido:	"<< this->ArticulosMuebles[i].getProfesorAsignado()->getApellido() << "\n" ;
				cout << "Codigo:	"<< this->ArticulosMuebles[i].getProfesorAsignado()->getCodigo() << "\n" ;
				cout << "Cedula:	"<< this->ArticulosMuebles[i].getProfesorAsignado()->getCedula() << "\n" ;
			}else {
				ConfirmarMuebl = true ;
			}
		}
	}
	
	if (this->VerificarArticulosPrestamo() == false) {
		for (int i=0 ; i<this->ArticulosDisponibles.size() ; i++) {
			if (this->ArticulosDisponibles[i].getCodigoArticulo() == Codigo) {
				cout << "\nEl ARTICULO DE PRESTAMO A CARGO DE : \n\n" ;
				cout << "Nombre:	"<< this->ArticulosDisponibles[i].getProfesor()->getNombre() << "\n" ;
				cout << "Apellido:	"<< this->ArticulosDisponibles[i].getProfesor()->getApellido() << "\n" ;
				cout << "Codigo:	"<< this->ArticulosDisponibles[i].getProfesor()->getCodigo() << "\n" ;
				cout << "Cedula:	"<< this->ArticulosDisponibles[i].getProfesor()->getCedula() << "\n" ;
			}else {
				ConfirmarPrest = true ;
			}
		}
	}
	
	if ((ConfirmarCompu == true) && (ConfirmarMuebl == true) && (ConfirmarPrest == true)) {
		system("cls") ;
		cout << "\n\tNO SE HA ENCONTRADO NINGUNA ASIGNACION  \n\n" ;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::ConsultaMultaYEstado() {
	system("cls") ;
	
	int Codigo ;
	bool Confirmar = false ;

	Codigo = common::ValidarEntero("\nINGRESE EL CODIGO DEL ESTUDIANTE QUE DESEA ENCONTRAR\n\n") ;

	if (this->VerificarVectorEstudiantes() == false) {
		for (int i=0 ; i<this->Estudiantes.size() ; i++) {
			if (this->Estudiantes[i].getCodigo() == Codigo) {
				if (this->Estudiantes[i].getValorMultaAcomulada() == 0) {
					system("cls") ;
					cout << "\n\nNO HAY REGISTRO DE MULTA \n\n" ;
					
					if (this->Estudiantes[i].getEstadoDeEstudiante() == false ){
						cout << "ESTADO ACTIVO PARA PRESTAMOS \n\n" ;
					}
				}else {
					system("cls") ;
					cout << "\n\nSU MULTA ES : \n" ;
					cout << "$ " << this->Estudiantes[i].getValorMultaAcomulada() << "\n\n" ;
					cout << "ESTADO TEMPORAL DE INACTIVO PARA PRESTAMOS \n\n" ;
				}
			}else {
				Confirmar = true ;
			}                                                        				
		}                                   
	}else {
		system("cls") ;
		cout << "\n\tNO EXISTEN DATOS REGISTRADOS DEL ESTUDIANTE \n\n" ;
	}
	
	
	if (Confirmar == true) {
		system("cls") ;
		cout << "\n\tNO HAY DATOS EN EL BUSCADOR CON CODIGO \n\n" ;
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////


void Laboratorio::ConsultaVDEArticulo() {
	system("cls") ;
	
	int Itera = 1 ;
	bool* Confirmar = new bool (false) ;
	
	cout << "\n\tLOS DATOS REQUERIDOS PARA EL ARTICULO SON: \n\n" ;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
	
	if (this->VerificarArticulosCompu() == false) {
		for (int i=0 ; i<this->ArticulosComp.size() ; i++) {
			cout << "\t\nArticulo #" << Itera << "\n" ;			
			cout << "Nombre del Articulo: " << this->ArticulosComp[i].getIDNombre() << "\n" ;
			cout << "Valor del articulo: $ " << this->ArticulosComp[i].getValorArticuloInicial() << "\n" ; 
			cout << "Valor actual del articulo: $ " << this->ArticulosComp[i].getValorActualArticulo() << "\n" ;
			cout << "Valor de despreciacion anual: $ " << this->ArticulosComp[i].getDespreciacion() << "\n" ; 
			cout << "Estado del Articulo: " << this->ArticulosComp[i].getEstadoArticuloDeActivo() << "\n\n" ;
			Itera++ ; 
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
			*Confirmar = true ; 
		}
	}
	
	if (this->VerificarArticulosMueble() == false) {
		for (int i=0 ; i<this->ArticulosMuebles.size() ; i++) {
			cout << "\t\nArticulo #" << Itera << "\n" ;
			cout << "Nombre del Articulo: " << this->ArticulosMuebles[i].getIDNombre() << "\n" ;
			cout << "Valor del articulo: $ " << this->ArticulosMuebles[i].getValorArticuloInicial() << "\n" ; 
			cout << "Valor actual del articulo: $ " << this->ArticulosMuebles[i].getValorActualArticulo() << "\n" ;
			cout << "Valor de despreciacion anual: $ " << this->ArticulosMuebles[i].getDespreciacion() << "\n" ; 
			cout << "Estado del Articulo: " << this->ArticulosMuebles[i].getEstadoArticuloDeActivo() << "\n\n" ;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
			Itera++ ;
			*Confirmar = true ; 
		}
	}
	
	if (this->VerificarArticulosPrestamo() == false) {
		for (int i=0 ; i<this->ArticulosDisponibles.size() ; i++) {
			cout << "\t\nArticulo #" << Itera << "\n" ;
			cout << "Nombre del Articulo: " << this->ArticulosDisponibles[i].getIDNombre() << "\n" ;
			cout << "Valor del articulo: $ " << this->ArticulosDisponibles[i].getValorArticuloInicial() << "\n" ; 
			cout << "Valor actual del articulo: $ " << this->ArticulosDisponibles[i].getValorActualArticulo() << "\n" ;
			cout << "Valor de despreciacion anual: $ " << this->ArticulosDisponibles[i].getDespreciacion() << "\n" ; 
			cout << "Estado del Articulo: " << this->ArticulosDisponibles[i].getEstadoArticuloDeActivo() << "\n\n" ;
			Itera++ ;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
			*Confirmar = true ; 
		}
	}
	
	if (*Confirmar == false) {
		system("cls") ;
		cout << "\n\n\tNO HAY DATOS CON EL IDENTIFICADOR  \n\n" ;
	}	
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::ConsultaActiInac() {
	system("cls") ;

	bool* Confirmar = new bool (false) ;
	
	
	cout << "\n\t\tOS DATOS QUE REQUIERE EL ARTICULO SON: \n\n" ;
	cout << "Nombre del Articulo" << "\t\t\tCodigo del articulo" << "\t\t\tEstado \n\n" ;
	
	if (this->VerificarArticulosCompu() == false) {
		for (int i=0 ; i<this->ArticulosComp.size() ; i++) {
			if (this->ArticulosComp[i].getEstadoArticuloDeActivo() == 0) {
				cout << this->ArticulosComp[i].getIDNombre() << "\t\t\t\t\t" << this->ArticulosComp[i].getCodigoArticulo() << "\t\t\t\t\t   Inactivo \n" ;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
			}else {
				cout << this->ArticulosComp[i].getIDNombre() << "\t\t\t\t\t" << this->ArticulosComp[i].getCodigoArticulo() << "\t\t\t\t\t   Activo \n" ;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
			}
			*Confirmar = true ; 
		}
	}
	
	if (this->VerificarArticulosMueble() == false) {
		for (int i=0 ; i<this->ArticulosMuebles.size() ; i++) {
			if (this->ArticulosMuebles[i].getEstadoArticuloDeActivo() == 0) {
				cout << this->ArticulosMuebles[i].getIDNombre() << "\t\t\t\t\t" << this->ArticulosMuebles[i].getCodigoArticulo() << "\t\t\t\t\t   Inactivo \n" ;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
			}else {
				cout << this->ArticulosMuebles[i].getIDNombre() << "\t\t\t\t\t" << this->ArticulosMuebles[i].getCodigoArticulo() << "\t\t\t\t\t   Activo \n" ;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
			}
			*Confirmar = true ; 
		}
	}
	
	if (this->VerificarArticulosPrestamo() == false) {
		for (int i=0 ; i<this->ArticulosDisponibles.size() ; i++) {
			if (this->ArticulosDisponibles[i].getEstadoArticuloDeActivo() == 0) {
				cout << this->ArticulosDisponibles[i].getIDNombre() << "\t\t\t\t\t" << this->ArticulosDisponibles[i].getCodigoArticulo() << "\t\t\t\t   Inactivo \n" ;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
			}else {
				cout << this->ArticulosDisponibles[i].getIDNombre() << "\t\t\t\t\t" << this->ArticulosDisponibles[i].getCodigoArticulo() << "\t\t\t\t   Activo \n" ;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
			}
			*Confirmar = true ; 
		}
	}
	
	if (*Confirmar == false) {
		system("cls") ;
		cout << "\n\n\tNO HAY DATOS \n\n" ;
	}
	
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::MostrarHistorialArticulo() {
	system("cls") ; 
	int Codigo ;
	
	Codigo = common::ValidarEntero("\nINGRESE EL CODIGO DEL ARTICULO QUE DESEA BUSCAR \n\n") ;
	
	if (!ParaHistoriales.empty()) {
		for (int i=0 ; i<ParaHistoriales.size() ; i++) {
			for (int j=0 ; j<ParaHistoriales[i].MisArticulos().size() ; j++) {
				if(Codigo == ParaHistoriales[i].MisArticulos()[j]->getCodigoArticulo()) {
					cout << "\n\tSERVICIO DE PRESTAMO #" << i+1 << "\n\n" ;
					cout << "Nombre del Estudiante:		" << ParaHistoriales[i].getNombre() << "\n" ;
					cout << "Codigo del Estudiante:		" << ParaHistoriales[i].getCodigo() << "\n" ;
					cout << "Nombre del Articulo:		" << ParaHistoriales[i].MisArticulos()[j]->getIDNombre() << "\n" ;
					cout << "Codigo del Articulo:		" << ParaHistoriales[i].MisArticulos()[j]->getCodigoArticulo() << "\n" ;
					cout << "Fecha : " << ParaHistoriales[i].MisArticulos()[j]->getFecha()->getAnio() << "/" ;
					cout <<  ParaHistoriales[i].MisArticulos()[j]->getFecha()->getMes() << "/" ; 
					cout << ParaHistoriales[i].MisArticulos()[j]->getFecha()->getDia() << "\n" ;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" ;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" ;	
				}
				
			}
		}	
	}else {
		cout << "\nNO HY DATOS EN EL HISTORIAL\n\n" ;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::MostrarHistorialEstudiante() {
	system("cls") ; 
	
	int Codigo ;
	bool* Confirmar = new bool ; 
	
	Codigo = common::ValidarEntero("\nINGRESE EL CODIGO DEL ESTUDIANTE QUE DESEA BUSCAR \n\n") ;
	
	cout << "\n\nLOS ARTICULOS PRESTADOS SON: \n\n" ; 
	
	for (int i=0 ; i<ParaHistoriales.size() ; i++) {
		if (ParaHistoriales[i].getCodigo() == Codigo) {
			for (int j=0 ; j<ParaHistoriales[i].MisArticulos().size() ; j++) {				
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" ;
				cout << "\tARTICULO #" << i+1 << "\n" ; 
				cout << "Nombre:	" << ParaHistoriales[i].MisArticulos()[j]->getIDNombre() << "\n" ;
				cout << "Codigo:	" << ParaHistoriales[i].MisArticulos()[j]->getCodigoArticulo() << "\n" ;
				cout << "Fecha: 	" << ParaHistoriales[i].MisArticulos()[j]->getFecha()->getAnio() << "/" ;
				cout << ParaHistoriales[i].MisArticulos()[j]->getFecha()->getMes() << "/" ;
				cout << ParaHistoriales[i].MisArticulos()[j]->getFecha()->getDia() << "\n\n" ;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" ;
			} 
		}else {
			system("cls") ;
			cout << "\n\n\tNO HAY DATOS \n\n" ;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::MostrarHistorialConFechas() {
	system("cls") ;
	
	int Anio, Mes, Dia ;
	Fecha* FechaInicio = new Fecha ;
	Fecha* FechaFinal = new Fecha ;
	
	cout << "\tFECHA INICIO \n" ;
	Anio = common::ValidarEntero("\nIngrese el anio \n") ;
	Mes = common::ValidarEntero("\nIngrese el mes \n") ;
	Dia = common::ValidarEntero("\nIngrese el dia \n") ;
	FechaInicio->setAnio(Anio) ;
	FechaInicio->setMes(Mes) ;
	FechaInicio->setDia(Dia) ;
	
	cout << "\tFECHA DE VENCIMIENTO \n" ;
	Anio = common::ValidarEntero("\nIngrese el anio \n") ;
	Mes = common::ValidarEntero("\nIngrese el mes \n") ;
	Dia = common::ValidarEntero("\nIngrese el dia \n") ;
	FechaFinal->setAnio(Anio) ;
	FechaFinal->setMes(Mes) ;
	FechaFinal->setDia(Dia) ;
	
	bool Estado = FechaInicio->ValidarFormatoDeFecha(FechaInicio, this->FechaInicio) ; 
	bool EstadoFin = FechaFinal->ValidarFormatoDeFecha(FechaFinal, this->FechaInicio) ; 
	
	if ((Estado == true) && (EstadoFin == true))  {
		cout << "\n\tPRESTAMO EN EL RANGO DE FECHA SON \n\n " ;
	
		for (int i=0 ; i<ParaHistoriales.size() ; i++) {
			for (int j=0 ; j<ParaHistoriales[i].MisArticulos().size() ; j++) {
				int Anio = ParaHistoriales[i].MisArticulos()[j]->getFecha()->getAnio() ;
				int Mes = ParaHistoriales[i].MisArticulos()[j]->getFecha()->getMes() ;
				if ((Anio >= FechaInicio->getAnio()) && (Anio <= FechaFinal->getAnio())) {
					if (Mes >= FechaInicio->getMes()) {
						cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" ;
						cout << "\tArticulo #" << i+1 << "\n" ; 
						cout << "Nombre: " << ParaHistoriales[i].MisArticulos()[j]->getIDNombre() << "\n" ;
						cout << "Codigo: " << ParaHistoriales[i].MisArticulos()[j]->getCodigoArticulo() << "\n" ;
						cout << "Fecha:  " << ParaHistoriales[i].MisArticulos()[j]->getFecha()->getAnio() << "/" ;
						cout << ParaHistoriales[i].MisArticulos()[j]->getFecha()->getMes() << "/" ;
						cout << ParaHistoriales[i].MisArticulos()[j]->getFecha()->getDia() << "\n\n" ;
						cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" ;
					}
				}else {
					system("cls") ;
					cout << "\nNO HAY DATOS DE REGISTRO \n\n" ;
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

bool Laboratorio::IndicarFecha() {
	system("cls") ; 
	int Anio, Dia, Mes ; 
	
	cout << "\n\t\tPOR FAVOR CONFIRMAR LA FECHA ACTUAL \n\n" ; 
	cout << "\tAnio Actual:	" ; cin  >> Anio ;
	cout << "\tMes Actual:	"  ; cin  >> Mes ;
	cout << "\tDia Actual:	"  ; cin  >> Dia ;
	
	FechaActual->setAnio(Anio) ; 
	FechaActual->setMes(Mes)   ;
	FechaActual->setDia(Dia)   ;
	
	bool Estado = FechaActual->ValidarFormatoDeFecha(FechaActual, this->FechaInicio) ; 
	
	if (Estado == true) {
		cout << "\n\nFECHA ACTUAL: \n"  ;
		cout << FechaActual->getAnio() << "/" << FechaActual->getMes() << "/" << FechaActual->getDia() << "\n" ;
		system("pause")  ;
		return true ;
	}else {
		return false ; 
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void Laboratorio::Depreciar() {
	ManejoDeArchivo ManejadorDespre ; 
	if (this->VerificarArticulosCompu() == false) {
		for (int i=0 ; i<this->ArticulosComp.size() ; i++) {
			this->ArticulosComp[i].Despreciacion(FechaActual, this->ArticulosComp[i].getFecha()) ;			
		}
		ManejadorDespre.ActualizarComputoCSV(this->ArticulosComp) ;
	}
	
	if (this->VerificarArticulosPrestamo() == false) {
		for (int i=0 ; i<this->ArticulosDisponibles.size() ; i++) {
			this->ArticulosDisponibles[i].Despreciacion(FechaActual, this->ArticulosDisponibles[i].getFecha()) ;
		}
		ManejadorDespre.ActualizarArchivoArticuloDePrestamoCSV(this->ArticulosDisponibles) ;
	}
	
	if (this->VerificarArticulosMueble() == false) {
		for (int i=0 ; i<this->ArticulosMuebles.size() ; i++) {
			this->ArticulosMuebles[i].Despreciacion(FechaActual, this->ArticulosMuebles[i].getFecha()) ;
		}
		ManejadorDespre.ActualizarMuebleCSV(this->ArticulosMuebles) ;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

bool Laboratorio::VerificarVectorProfesores() {
	if (this->Profesores.empty()) {
		return true ;
	} else return false ;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

bool Laboratorio::VerificarVectorAdmin() {
	if (this->PersonalAdmin.empty()) {
		return true ;
	} else return false ;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

bool Laboratorio::VerificarVectorEstudiantes() {
	if (this->Estudiantes.empty()) {
		return true ;
	} else return false ;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////


bool Laboratorio::VerificarVectorInformaciones() {
	if (this->Informaciones.empty()) {
		return true ;
	} else return false ;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

bool Laboratorio::VerificarArticulosCompu() {
	if(this->ArticulosComp.empty()) {
		return true ;
	} else return false ;
}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

bool Laboratorio::VerificarArticulosMueble() {
	if (this->ArticulosMuebles.empty()) {
		return true ;
	} else return false ;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

bool Laboratorio::VerificarArticulosPrestamo() {
	if (this->ArticulosDisponibles.empty()) {
		return true ;
	} else return false ;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

// DESTRUCTOR
Laboratorio::~Laboratorio() {
}
