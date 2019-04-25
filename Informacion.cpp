#include "Informacion.h"

// CONSTRUCTOR
Informacion::Informacion() {
}

Informacion::Informacion(string NombreDeInfo, string ContenidoDeInfo) {
	this->NombreDeInfo = NombreDeInfo ;
	this->ContenidoDeInfo = ContenidoDeInfo ;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

// SETTERS
void Informacion::setNombreDeInfo(string NombreDeInfo) {
	this->NombreDeInfo = NombreDeInfo ;
}

void Informacion::setContenidoDeInfo(string ContenidoDeInfo) {
	this->ContenidoDeInfo = ContenidoDeInfo ;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

// GETTERS 
string Informacion::getNombreDeInfo() {
	return this->NombreDeInfo ;
}

string Informacion::getContenidoDeInfo() {
	return this->ContenidoDeInfo ;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

// OTROS METODOS
void Informacion::DatosIniciales(Informacion* InfoInicial, int NroAuxiliar) {
	string* Nombre = new string ;
	string* Contenido = new string ;
	
	if (NroAuxiliar == 0) {
		*Nombre = "NOMBRE O TIPO DE INFORMACION" ;
		*Contenido = "CONTENIDO" ;
		InfoInicial->setNombreDeInfo(*Nombre) ;
		InfoInicial->setContenidoDeInfo(*Contenido) ;
	}else if (NroAuxiliar == 1) {
		// Hacer otro objeto de informacion
		*Nombre = "NOMBRE DEL LABORATORIO" ;
		*Contenido = "LABORATORIO CENTRAL DE TULUA" ;
		InfoInicial->setNombreDeInfo(*Nombre) ;
		InfoInicial->setContenidoDeInfo(*Contenido) ;
	}else if (NroAuxiliar == 2) {
		// Hacer otro objeto de informacion
		*Nombre = "DIRECCION" ;
		*Contenido = "Carrera 13 #21-56 B/Ruben Cruz" ;
		InfoInicial->setNombreDeInfo(*Nombre) ;
		InfoInicial->setContenidoDeInfo(*Contenido) ;
	}
	// ELiminar datos en memoria dinamica
	delete Nombre ;
	delete Contenido ;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void Informacion::CrearInformacionLabotatorio(Informacion* InformacionParaCrear) {
	
	string Nombre, Contenido ;
	
	system("cls") ;
	
	cout << "\n\tCOMPLETE LA SIGUIENTE INFORMACION \n\n" ;
	
		
	cout << "INGRESE EL TIPO O NOMBRE QUE DESEA REGISTRAR:		" ;
	cin  >> Nombre ;
		
	cout << "INGRESE EL CONTENIDO QUE DESEA REGISTRAR:		" ;
	cin  >> Contenido ;		
		
	InformacionParaCrear->setNombreDeInfo(Nombre) ;
	InformacionParaCrear->setContenidoDeInfo(Contenido) ;
	
	cout << "\n\tACCION EXITOSA... \n" ;
	system("pause") ; 
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

// DESTRUCTOR
Informacion::~Informacion() {
}

