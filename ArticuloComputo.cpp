#include "ArticuloComputo.h"

// CONSTRUCTOR
ArticuloComputo::ArticuloComputo() {
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// SETTERS
void ArticuloComputo::setIDMarca(string IDMarca) {
	this->IDMarca = IDMarca ;
}

void ArticuloComputo::setDespreciacion(float Despreciacion) {
	this->ValorDespreciacionAnual = Despreciacion ;
}

void ArticuloComputo::AsignarAlArticulo(Profesor* Profesor) {
	this->ProfesorAsignado = Profesor ;
}

void ArticuloComputo::setCantidad(int Cantidad) {
	this->CantidadDisponibles = Cantidad ;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// GETTERS
string ArticuloComputo::getIDMarca() {
	return this->IDMarca ;
}

Profesor* ArticuloComputo::getProfesor() {
	return this->ProfesorAsignado ;
}

int ArticuloComputo::getCantidad() {
	return this->CantidadDisponibles ;
}

float ArticuloComputo::getDespreciacion() {
	return this->ValorDespreciacionAnual ; 
}


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

bool ArticuloComputo::Despreciacion (Fecha* Actual, Fecha* FechaArticulo) {
	int DiferenciAnios ; 
	DiferenciAnios = Actual->getAnio() - FechaArticulo->getAnio() ;
	
	if (DiferenciAnios >= 10) {
		this->ValorActualArticulo = 0 ;
		return true ; 				
	}else  {
		switch (DiferenciAnios) {
			case 0 : { // 0 Años
				this->ValorActualArticulo = this->ValorActualArticulo ;  				
				return false ;
				break;
			}
			
			case 1 : { // Un año 
				this->ValorActualArticulo -= this->ValorDespreciacionAnual ;  								
				return false ;
				break;
			}
			
			case 2 : { // Dos años
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 2) ;				
				return false ;
				break;
			}
			
			case 3 : { // Tres años
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 3) ;
				return false ;
				break;
			}
			
			case 4 : { // Cuatro años
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 4) ;
				return false ;
				break;
			}
			
			case 5 : { // Cinco años
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 5) ;
				return false ;
				break;
			}
			
			case 6 : { // Seis años
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 6) ;
				return false ;
				break;
			}
			
			case 7 : { // Siete años
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 7) ;
				return false ;
				break;
			}
			
			case 8 : { // Ocho años
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 8) ;
				return false ;
				break;
			}
			
			case 9 : { // Nueve años
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 9) ;
				return false ;
				break;
			}
			
			default : { // Datos incorrecto
				cout << "\nDato Incorrecto \n\n" ;
				system("pause") ; 
				return false ;
				break;
			}
		}
	}
	
	if (this->ValorActualArticulo == 0) {
		this->EstadoArticuloDeActivo == false ; 
	}
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////


void ArticuloComputo::CrearComputo(ArticuloComputo* ComputoACrear) {
	
	string Nombre, Marca ;
	int Codigo, Cantidad, DatosFecha ;
	float ValorArticulo ; 

	system("cls") ;

	cout << "\n\tA Continuacion digite la informacion correspondiente \n\n" ;

	cout << "\nIngrese el nombre del articulo: \n" ;
	fflush(stdin) ;
	cin  >> Nombre ;
	
	cout << "\nIngrese la Marca del articulo: \n" ;
	fflush(stdin) ;
	cin  >> Marca ;
	
	Codigo = common::ValidarEntero("\nIngrese el codigo del articulo \n") ;

	ValorArticulo = common::ValidarEntero("\nIngrese el valor del articulo \n") ;
	
	Cantidad = common::ValidarEntero("\nIngrese la cantidad del articulo que van a estar disponibles \n") ;
		
	ComputoACrear->setIDNombre(Nombre) ;
	ComputoACrear->setIDMarca(Marca) ; 
	ComputoACrear->setCodigoArticulo(Codigo) ;
	ComputoACrear->setCantidad(Cantidad) ; 
	ComputoACrear->setValorArticuloInicial(ValorArticulo) ;
	ComputoACrear->setValorActualArticulo(ValorArticulo) ;
	ComputoACrear->setDespreciacion(this->ValorArticulo/10) ; 
	ComputoACrear->setEstadoArticuloDeActivo(1) ;
	ComputoACrear->setEstadoDeLimiteDeArticulos(1) ;
	ComputoACrear->setEstadoDeAsignadoAProfesor(1) ;
}


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// DESTRUCTOR
ArticuloComputo::~ArticuloComputo() {
}
