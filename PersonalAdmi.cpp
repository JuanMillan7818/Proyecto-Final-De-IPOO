
#include "PersonalAdmi.h"

// Constructor
PersonalAdmi::PersonalAdmi() {
}

PersonalAdmi::PersonalAdmi(string Nombre, string Apellido, string Email, int Edad, int Cedula, long Telefono) : Persona (Nombre,Apellido,Email,Edad,Cedula,Telefono) {
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void PersonalAdmi::CrearPersonal(PersonalAdmi* Personal) {
	system("cls") ;
	string Nombre, Apellido, Email ;
	int Edad ;
	long Cedula, Telefono ;

	cout << "\nIngresa los datos correspondiente de Personal administrativo \n" ;
	cout << "Ingrese su nombre: \n" ;
	fflush(stdin) ;
	cin  >> Nombre ;
	Personal->setNombre(Nombre) ;

	cout << "Ingrese su apellido: \n" ;
	fflush(stdin) ;
	cin  >> Apellido ;
	Personal->setApellido(Apellido) ;

	cout << "Ingrese su email: \n" ;
	fflush(stdin) ; 
	cin  >> Email ;
	Personal->setEmail(Email) ;

	Edad = common::ValidarEntero("Ingrese su edad: \n") ;
	Personal->setEdad(Edad) ;


	Cedula = common::ValidarEntero("Ingrese su numero de cedula: \n" ) ;
	Personal->setCedula(Cedula) ;

	Telefono = common::ValidarEntero("Ingrese su numero de telefono: \n") ;
	Personal->setTelefono(Telefono) ;

	cout << "\nPor favor espere ! \n" ;
	cout <<  "Estamos Revisando si los datos ingresados estan correctamente \n\n" ;
	system("pause") ;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

// Destructor
PersonalAdmi::~PersonalAdmi() {
}
