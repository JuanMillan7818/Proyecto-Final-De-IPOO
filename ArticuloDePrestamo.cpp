#include "ArticuloDePrestamo.h"

// CONSTRUCTOR
ArticuloDePrestamo::ArticuloDePrestamo() {
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// SETTERS 
void ArticuloDePrestamo::setIDMarca(string IDMarca) {
	this->IDMarca = IDMarca ;
}

void ArticuloDePrestamo::AsignarAProfesor(Profesor* Profesor) {
	this->ProfesorAsignado = Profesor ; 
}

void ArticuloDePrestamo::setDespreciacion(float Despreciacion){
	this->ValorDespreciacionAnual = Despreciacion ;
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

//Asignar un profesor responsable a un articulo
void ArticuloDePrestamo::setCantidadDeTipoDeArticulo(int CantidadDeArticulos)  {
	this->CantidadDeTipoDeArticulo = CantidadDeArticulos ;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// GETTERS
string ArticuloDePrestamo::getIDMarca() {
	return this->IDMarca ; 
}


int ArticuloDePrestamo::getCantidadDeTipoDeArticulo() {
	return this->CantidadDeTipoDeArticulo ;
}

Profesor* ArticuloDePrestamo::getProfesor() {
	return this->ProfesorAsignado ; 
}

float ArticuloDePrestamo::getDespreciacion(){
	return this->ValorDespreciacionAnual ;
} 

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

//Otros metodos
bool ArticuloDePrestamo::Despreciacion(Fecha* Actual, Fecha* FechaArticulo) { 
	int DiferenciAnios, DiferenciaMes, DiferenciaAlAnio ; 
	int TotalMeses, TotalActualMes ;
	
	DiferenciAnios = Actual->getAnio() - FechaArticulo->getAnio() ;
	DiferenciaMes = Actual->getMes() - FechaArticulo->getMes() ;
	
	if (DiferenciAnios >= 2) {
		this->ValorActualArticulo = 0 ;
		return true ; 				
	}else if (DiferenciAnios == 1) {
		if (Actual->getMes() >= FechaArticulo->getMes()){
			TotalActualMes = 12  + (Actual->getMes() - FechaArticulo->getMes()) ;
			
			switch (TotalActualMes) {
				case 12 : { // Doce meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 12) ;			
					return false ;
					break;
				}
				
				case 13 : { // Trece meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 13) ;
					return false ;
					break;
				}
				
				case 14 : { // Cartorce meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 14) ;
					return false ;
					break;
				}
				
				case 15 : { // Quince meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 15) ;
					return false ;
					break;
				}
				
				case 16 : { // Diez y seis meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 16) ;
					return false ;
					break;
				}
				
				case 17 : { // Diez y siete meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 17) ;
					return false ;
					break;
				}
				
				case 18 : { // Diez y ocho meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 18) ;
					return false ;
					break;
				}
			}
		}else {
			TotalActualMes = 12 - (FechaArticulo->getMes() - Actual->getMes()) ;
			
			switch (TotalActualMes) {
				case 1 : { // Un mes
					this->ValorActualArticulo -= this->ValorDespreciacionAnual ;  				
					return false ;
					break;
				}
				
				case 2 : { // Dos meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 2) ;
					return false ;
					break;
				}
				
				case 3 : { // Tres meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 3) ;
					return false ;
					break;
				}
				
				case 4 : { // Cuatro meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 4) ;
					return false ;
					break;
				}
				
				case 5 : { // Cinco meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 5) ;
					return false ;
					break;
				}
				
				case 6 : { // Seis meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 6) ;
					return false ;
					break;
				}
				
				case 7 : { // Siete meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 7) ;
					return false ;
					break;
				}
				
				case 8 : { // Ocho meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 8) ;
					return false ;
					break;
				}
				
				case 9 : { // Nueve meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 9) ;
					return false ;
					break;
				}
				
				case 10 : { // Dies meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 10) ;
					return false ;
					break;
				}
				
				
				case 11 : { // Once meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 11) ;
					return false ;
					break;
				}
			}
		}
	}else if (DiferenciAnios == 0) {
		if (Actual->getMes() >= FechaArticulo->getMes()) {
			switch (DiferenciaMes) {
				case 1 : { // Un mes
					this->ValorActualArticulo -= this->ValorDespreciacionAnual ;  				
					return false ;
					break;
				}
				
				case 2 : { // Dos meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 2) ;
					return false ;
					break;
				}
				
				case 3 : { // Tres meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 3) ;
					return false ;
					break;
				}
				
				case 4 : { // Cuatro meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 4) ;
					return false ;
					break;
				}
				
				case 5 : { // Cinco meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 5) ;
					return false ;
					break;
				}
				
				case 6 : { // Seis meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 6) ;
					return false ;
					break;
				}
				
				case 7 : { // Siete meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 7) ;
					return false ;
					break;
				}
				
				case 8 : { // Ocho meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 8) ;
					return false ;
					break;
				}
				
				case 9 : { // Nueve meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 9) ;
					return false ;
					break;
				}
				
				case 10 : { // Dies meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 10) ;
					return false ;
					break;
				}
				
				
				case 11 : { // Once meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 11) ;
					return false ;
					break;
				}
				
				case 12 : { // Doce meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 12) ;
					return false ;
					break;
				}
			}
		}
		
	}
	
	if (this->ValorActualArticulo == 0) {
		this->EstadoArticuloDeActivo == false ; 
	}
}


//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void ArticuloDePrestamo::CrearArticuloParaPrestamo(ArticuloDePrestamo* ArticuloParaCrear) {
	system("cls") ;
	string Nombre, Marca ;
	int Codigo, NroDeArticulos ; 
	float Valor ;
	bool EstadoArticulo = true, EstadoDeLimiteCantidad = true, Asignacion = true ;
	
	cout << "\n\tINGRESE LOS SIGUIENTES DATOS PARA CREAR ARTICULOS DE PRESTAMO \n\n" ;
	
	cout << "-INGRESE NOMBRE DEL ARTICULO:		" ;
	fflush(stdin) ;
	cin  >> Nombre ;
	
	cout << "-INGRESE LA MARCA DEL ARTICULO:		"  ;
	fflush(stdin) ;
	cin  >> Marca ;
	
	Codigo = common::ValidarEntero("-INGRESE EL CODIGO DEL ARTICULO:	" ) ;
	
	NroDeArticulos = common::ValidarEntero("-INGRESE UNA CANTIDAD DE DISPONIBLES:	" ) ;
		
	Valor = common::ValidarEntero("-INGRESE UN VALOR AL ARTICULO:		" ) ;
		
	ArticuloParaCrear->setIDNombre(Nombre) ;
	ArticuloParaCrear->setIDMarca(Marca) ;
	ArticuloParaCrear->setCodigoArticulo(Codigo) ;
	ArticuloParaCrear->setCantidadDeTipoDeArticulo(NroDeArticulos) ;
	ArticuloParaCrear->setValorArticuloInicial(Valor) ;
	ArticuloParaCrear->setValorActualArticulo(Valor) ;
	ArticuloParaCrear->setDespreciacion(Valor/18) ;
	ArticuloParaCrear->setEstadoArticuloDeActivo(EstadoArticulo) ;
	ArticuloParaCrear->setEstadoDeLimiteDeArticulos(EstadoDeLimiteCantidad) ;
	ArticuloParaCrear->setEstadoDeAsignadoAProfesor(Asignacion) ;

}


/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

void ArticuloDePrestamo::AgregarFechaLim(Fecha* FechaLim) {
	this->FechaLimite = FechaLim ;	
}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

Fecha* ArticuloDePrestamo::MostrarFecha() {
	return this->FechaLimite ; 
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// DESTRUCTOR
ArticuloDePrestamo::~ArticuloDePrestamo() {
}
