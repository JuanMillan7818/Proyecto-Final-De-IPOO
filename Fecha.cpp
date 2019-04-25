#include "Fecha.h"

// CONSTRUCTORES
Fecha::Fecha() {

}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

Fecha::Fecha(int Dia, int Mes, int Anio) {
	this->Dia = Dia ;
	this->Mes = Mes ;
	this->Anio = Anio ;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

// SETTERS
void Fecha::setDia(int Dia) {
	this->Dia = Dia ;
}

void Fecha::setMes(int Mes) {
	this->Mes = Mes ;
}

void Fecha::setAnio(int Anio) {
	this->Anio = Anio ;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

// GETTERS
int Fecha::getDia() {
	return this->Dia ;
}

int Fecha::getMes() {
	return this->Mes ;
}

int Fecha::getAnio() {
	return this->Anio ;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

//Otros metodos
bool Fecha::ValidarFormatoDeFecha(Fecha* FechaAValidar, Fecha* Actual) {
	if (FechaAValidar->getAnio() < Actual->getAnio()) {
		cout << "\n\tERROR EN LA FECHA, ¡ VERIFIQUE D/M/A !  \n" ;
		cout << "Nota : EL ANIO DEBE SER MAYOR AL ANIO DE CREACION DEL LABORATORIO \n\n" ;
		system("pause") ; 
		return false ;
	} else if (FechaAValidar->getMes() > 12) {
		cout << "\n\tERROR EN LA FECHA, ¡ VERIFIQUE D/M/A !  \n" ;
		cout << "EL RANGO DEL MES DEBE SER DE 0 - 12 \n\n" ;
		system("pause") ; 
		return  false ;
	} else if (FechaAValidar->getMes() == 2) {
		if (FechaAValidar->getDia() > 28) {
			cout << "\n\tERROR EN LA FECHA, ¡ VERIFIQUE D/M/A !  \n" ;
			cout << "EL RANGO DE DIA DEBE SER DE 0 - 28 \n\n" ;
			system("pause") ; 
			return false ;
		}
	} else if (FechaAValidar->getDia() > 31) {
		cout << "\n\tERROR EN LA FECHA, ¡ VERIFIQUE D/M/A !  \n" ;
		cout << "EL RANGO DE DIA DEBE SER DE 0 - 31 \n\n" ;
		system("pause") ; 
		return false ;
	}

	return true ;
	system("pause") ;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

// DESTRUCTOR
Fecha::~Fecha() {
}
