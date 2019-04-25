
#include "Estudiante.h"

// CONSTRUCTOR
Estudiante::Estudiante(){
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// SETTERS
void Estudiante::setCarrera(string Carrera) {
	this->Carrera = Carrera ;
}

void Estudiante::setCodigo(int Codigo) {
	this->Codigo = Codigo ;
}

void Estudiante::setSemestre(int Semestre) {
	this->Semestre = Semestre ;
}

void Estudiante::CorrerValorMulta(int ValorMultaAcomulada) {
	this->ValorMultaAcomulada = ValorMultaAcomulada ;
}

void Estudiante::setEstadoDeMulta(bool EstadoDeMulta) {
	this->EstadoDeMulta = EstadoDeMulta ;
}

void Estudiante::setEstadoDeEstudiante(bool EstadoDeEstudiante) {
	this->EstadoDeEstudiante = EstadoDeEstudiante ;
}

void Estudiante::ArticuloParaPrestar(ArticuloDePrestamo* Articulo) {
	this->ArticulosPrestados.push_back(Articulo) ;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// GETTERS
string Estudiante::getCarrera() {
	return this->Carrera ; 
}

int Estudiante::getCodigo() {
	return this->Codigo ;
}

int Estudiante::getSemestre() {
	return this->Semestre ;
}

int Estudiante::getValorMultaAcomulada() {
	return this->ValorMultaAcomulada ;
}

bool Estudiante::getEstadoDeMulta() {
	return this->EstadoDeMulta ;
}

bool Estudiante::getEstadoDeEstudiante() {
	return this->EstadoDeEstudiante ;
}

vector <ArticuloDePrestamo*> Estudiante::MisArticulos() {
	return this->ArticulosPrestados ;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// Mostrar
void Estudiante::MostrarTodosLosArticulos() {
	cout << "\n\tMis Articulos Prestados \n\n" ;
	for (int i=0 ; i<this->ArticulosPrestados.size() ; i++) {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
		cout << "\n\t Articulo #" << i+1 << "\n\n" ;
		cout << "1. NOMBRE:					" << this->ArticulosPrestados[i]->getIDNombre() << "\n" ;
	 	cout << "2. CODIGO:					" << this->ArticulosPrestados[i]->getCodigoArticulo() << "\n" ;
	 	cout << "3. MARCA:					"  << this->ArticulosPrestados[i]->getIDMarca() << "\n" ;
	 	cout << "4. CANTIDAD:				" << this->ArticulosPrestados[i]->getCantidadDeTipoDeArticulo() << "\n" ;
	 	cout << "5. VALOR ARTICULO:			" << this->ArticulosPrestados[i]->getValorArticuloInicial() << "\n" ;
	 	cout << "6. VALOR ACTUAL:			" << this->ArticulosPrestados[i]->getValorActualArticulo() << "\n" ;
	 	cout << "7. ESTADO: 				" << this->ArticulosPrestados[i]->getEstadoArticuloDeActivo() << "\n" ;
	 	cout << "8. ESTADO LIMITE: 			" << this->ArticulosPrestados[i]->getEstadoDeLimiteDeArticulos() << "\n" ;
	 	cout << "9. PROFESOR RESPONSABLE: 	" << this->ArticulosPrestados[i]->getEstadoDeAsignadoAProfesor() << "\n" ;
	 	cout << "10.VALOR DESPRECIACION: " << this->ArticulosPrestados[i]->getDespreciacion() << "\n" ;
	 	cout << "11. ASIGNADO AL PROEFSOR:	" << this->ArticulosPrestados[i]->getProfesor()->getNombre() << "\n" ;  
		cout << "    COSIGO DEL PROFESOR:	" << this->ArticulosPrestados[i]->getProfesor()->getCodigo() << "\n" ;  
		cout << "12. ANIO:					" << this->ArticulosPrestados[i]->getFecha()->getAnio() << "\n" ;
		cout << "13. MES:					" << this->ArticulosPrestados[i]->getFecha()->getMes() << "\n" ;
 		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
	}
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// OTROS METODOS 
void Estudiante::CrearDatosDeObjetoEstudiante(Estudiante* EstudianteParaCrear) {
	system("cls") ;
	string Nombre, Apellido, Email, Carrera ; 
	int Edad, Codigo, Semestre, ValorMultaAcomulada = 0 ;
	long Cedula ;
	unsigned long Telefono ;
	bool EstadoDeMulta = false ;
	bool EstadoDeEstudiante = false ;

	cout << "\n\tCOMPLETE EL SIGUIENTE FORMULARIO \n\n" ;
	cout << "-NOMBRE:		" ;
	fflush(stdin) ;
	cin  >> Nombre ;
	EstudianteParaCrear->setNombre(Nombre) ;
			
	cout << "-APELLIDO:		" ;
	fflush(stdin) ;
	cin  >> Apellido ;
	EstudianteParaCrear->setApellido(Apellido) ;
			
	cout << "-EMAIL:			" ;
	fflush(stdin) ; 
	cin  >> Email ;
	EstudianteParaCrear->setEmail(Email) ;
			
	cout << "-CARRERA:		" ;
	fflush(stdin) ;
	cin  >> Carrera ;
	EstudianteParaCrear->setCarrera(Carrera) ;
			
	fflush(stdin) ;
	Edad = common::ValidarEntero("-EDAD:			") ;
	EstudianteParaCrear->setEdad(Edad) ;
			
	Cedula = common::Validarlong("-# DOC. IDENTIDAD:	") ;
	EstudianteParaCrear->setCedula(Cedula) ;
	
	
	Telefono = common::Validarlong("-# TELEFONICO:		") ;
	EstudianteParaCrear->setTelefono(Telefono) ;
			
	Codigo = common::ValidarEntero("-CODIGO:		") ;
	EstudianteParaCrear->setCodigo(Codigo) ;
			
	Semestre = common::ValidarEntero("-SEMESTRE QUE CURSA:	") ;
	EstudianteParaCrear->setSemestre(Semestre) ;
			
	EstudianteParaCrear->setEstadoDeMulta(EstadoDeMulta) ;
	EstudianteParaCrear->setEstadoDeEstudiante(EstadoDeEstudiante) ;
	EstudianteParaCrear->CorrerValorMulta(ValorMultaAcomulada) ;
	cout << "\nUn momento por favor... \n" ;
	cout <<  "EL SISTEMA REVISARA SI LOS DATOS INGRESADOS SON CORRECTOS \n\n" ;
	system("pause") ; 
}


////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////


void Estudiante::Devolucion(int Posicion) {
	
	vector <ArticuloDePrestamo> Paso ; 
	for (int i=0 ; i<this->ArticulosPrestados.size() ; i++) {
		Paso.push_back(*this->ArticulosPrestados[i]) ; 
	}
	
	Paso.erase(Paso.begin()+Posicion, Paso.begin()+(Posicion+1)) ; 
	
	///////////////////////////////////////////////////////////////////////
	
	vector <ArticuloDePrestamo> PasoAOriginal ; 
	this->ArticulosPrestados.clear() ;
	for (int i=0 ; i<Paso.size() ; i++) {
		this->ArticulosPrestados.push_back(&Paso[i]) ; 
	}
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
// DESTRUCTOR
Estudiante::~Estudiante() {
}
