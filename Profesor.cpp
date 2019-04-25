
#include "Profesor.h"

// CONSTRUCTOR
Profesor::Profesor(){
}


//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// SETTERS
void Profesor::setCodigo(int Codigo) {
	this->Codigo = Codigo ;
}

void Profesor::setTituloProfesional(string TituloProfesional) {
	this->TituloProfesional = TituloProfesional ;
}


// GETTERS
int Profesor::getCodigo() {
	return this->Codigo ;
}

string Profesor::getTituloProfesional() {
	return this->TituloProfesional ;
}


//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// OTROS METODOS
void Profesor::CrearDatosDeProfesor(Profesor* Profesor) {
	system("cls") ;
	string* Nombre = new string ;
	string* Apellido = new string ;
	string* Email = new string ;
	int* Edad = new int ;
	unsigned long* Cedula = new unsigned long ;
	unsigned long* Telefono = new unsigned long ;
	int* Codigo = new int ;
	string* TituloProfesional = new string ;

	cout << "\nIngresa los datos correspondiente de Profesor \n" ;
	cout << "Ingrese su nombre: \n" ;
	fflush(stdin) ;
	cin  >> *Nombre ;
	Profesor->setNombre(*Nombre) ;
	
	cout << "\nIngrese su apellido: \n" ;
	fflush(stdin) ;
	cin  >> *Apellido ;
	Profesor->setApellido(*Apellido) ;
	
	cout << "\nIngrese su email: \n" ;
	fflush(stdin) ;
	cin  >> *Email ;
	Profesor->setEmail(*Email) ;

	cout << "\nIngrese su Titulo de profesion: \n" ;
	fflush(stdin) ; // Liberar memoria para string
	cin  >> *TituloProfesional ;
	Profesor->setTituloProfesional(*TituloProfesional) ;
	
		
	*Edad = common::ValidarEntero("\nIngrese su edad: \n") ;
	Profesor->setEdad(*Edad) ;
	
		
	*Cedula = common::Validarlong("\nIngrese su numero de cedula: \n" ) ;
	Profesor->setCedula(*Cedula) ;
	
	*Telefono = common::Validarlong("\nIngrese su numero de telefono: \n") ;
	Profesor->setTelefono(*Telefono) ;
	
	*Codigo = common::ValidarEntero("\nIngrese su nuevo numero de codigo: \n") ;
	Profesor->setCodigo(*Codigo) ;
	
	cout << "\nPor favor espere ! \n" ;
	cout <<  "Estamos Revisando si los datos ingresados estan correctamente \n\n" ;
	system("pause") ;
	
   	delete Nombre, Apellido, Email, TituloProfesional ;
	delete Edad, Cedula, Telefono, Codigo ;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// DESTRUCTOR
Profesor::~Profesor(){
}


