
#include "common.h"

int common::ValidarEntero(string Mensaje) { // Esta funcion solicta un enetro por consola y valida que sea correcto
	float* Validar = new float ;
	
	cout << Mensaje ;
	cin >> *Validar ;

	while(true) {
		if(cin.fail()) {
			cin.clear() ; 
			cin.ignore(numeric_limits<streamsize>::max(), '\n') ;
			cout << "Has ingresado un valor no valido \n" ;
			cout << "Intenta de nuevo \n" ;
			system("pause") ;
			cout << "\n" ;
			cout << Mensaje ;
			cin >> *Validar ;
		}
		if(!cin.fail())
			break;
	}
	
	return *Validar;	
	delete Validar ;
}

unsigned long common::Validarlong(string Mensaje) { // Esta funcion solicta un enetro por consola y valida que sea correcto
	unsigned long* Validar = new unsigned long ;
	
	cout << Mensaje ;
	cin >> *Validar ;

	while(true) {
		if(cin.fail()) {
			cin.clear() ; 
			cin.ignore(numeric_limits<streamsize>::max(), '\n') ;
			cout << "Has ingresado un valor no valido \n" ;
			cout << "Intenta de nuevo \n" ;
			system("pause") ;
			cout << "\n" ;
			cout << Mensaje ;
			cin >> *Validar ;
		}
		if(!cin.fail())
			break;
	}
	
	delete Validar ;
	return *Validar;	
	
}
