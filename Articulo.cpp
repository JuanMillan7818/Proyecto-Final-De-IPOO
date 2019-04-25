#include "Articulo.h"

// CONSTRUCTORES
Articulo::Articulo(){
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// CONSTRUCTOR

Articulo::Articulo(string IDNombre, int CodigoArticulo, int ValorArticuloInicial, int ValorActualArticulo, 
				  bool EstadoArticulo, bool EstadoDeLimiteDeArticulos, bool EstadoDeAsignadoAProfesor) {
				  	
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// SETTERS
void Articulo::setIDNombre(string IDNombre) {
	this->IDNombre = IDNombre ;
}


void Articulo::setCodigoArticulo(int CodigoArticulo) {
	this->CodigoArticulo = CodigoArticulo ;
}

void Articulo::setValorArticuloInicial(float ValorArticuloInicial) {
	this->ValorArticulo = ValorArticuloInicial ;
}

void Articulo::setValorActualArticulo(float ValorActualArticulo) {
	this->ValorActualArticulo = ValorActualArticulo ;
}

void Articulo::setEstadoArticuloDeActivo(bool EstadoArticulo) {
	this->EstadoArticuloDeActivo = EstadoArticulo ;
}

void Articulo::setEstadoDeLimiteDeArticulos(bool EstadoDeLimiteDeArticulos) {
	this->EstadoDeLimiteDeArticulos = EstadoDeLimiteDeArticulos ;
}

void Articulo::setEstadoDeAsignadoAProfesor(bool EstadoAsignadoAProfesor) {
	this->EstadoDeAsignadoAProfesor = EstadoAsignadoAProfesor ;
}


//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// GETTERS
string Articulo::getIDNombre() {
	return this->IDNombre ;
}

int Articulo::getCodigoArticulo() {
	return this->CodigoArticulo ;
}

float Articulo::getValorArticuloInicial() {
	return this->ValorArticulo ;
}

float  Articulo::getValorActualArticulo() {
	return this->ValorActualArticulo ;
}


bool Articulo::getEstadoArticuloDeActivo() {
	return this->EstadoArticuloDeActivo ;
}

bool Articulo::getEstadoDeLimiteDeArticulos() {
	return this->EstadoDeLimiteDeArticulos ;
}

bool Articulo::getEstadoDeAsignadoAProfesor() {
	return this->EstadoDeAsignadoAProfesor ;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

Fecha* Articulo::getFecha() {
	return this->FechaDeRegistro ; 
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void Articulo::AsignarFecha(Fecha* FechaRegistro) {
	this->FechaDeRegistro = FechaRegistro ; 
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// DESTRUCTOR
Articulo::~Articulo() {
}
