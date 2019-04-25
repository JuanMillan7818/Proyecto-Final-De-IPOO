#include "Menu.h"

// CONSTRUCTOR
Menu::Menu(){
	
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::MenuIngreso() {
	bool* Salir = new bool (false) ;
	
	UsoDelLaboratorio->CargarTodoslosArchivos() ; // Cargar los archivos a los vecotres
	
	bool Estado = UsoDelLaboratorio->IndicarFecha() ;  // Dar la fecha actual
	
	if (Estado == true) {
		 
		UsoDelLaboratorio->Multa() ; 
		UsoDelLaboratorio->Depreciar() ;
		
		// Crear Informacion Inicial 
		if (UsoDelLaboratorio->VerificarVectorInformaciones() == true) {
			UsoDelLaboratorio->AgregarAlVectorInformaciones(3) ;
		}
 		
		 
		do {
			system("cls") ;
			cout << "\n\tBIENVENIDO AL LABORATORIO BUDAKAI TAICHI \n\n" ;
			cout << "1. REGISTRARSE. \n" ;
			cout << "2. VER INFORMACION PRINCIPAL. \n" ;
			cout << "3. CONSULTAS. \n" ;
			cout << "4. SALIR. \n\n " ;
			
			Opcion = common::ValidarEntero("Ingresa una opcion: \n" ) ;
			
			switch (this->Opcion) {
				case 1 : { // Ingreso al sistema
					RegistroIDPersona () ;
					break;  
				}
				
				case 2 : { // Ver informacion principal
					UsoDelLaboratorio->getInformaciones() ;
					system("pause") ;
					this->MenuInformacionLaboratorio() ;  
					break;
				}
				
				case 3 : { // Consultas
					MenuConsultas() ;
					break;
				}
				
				case 4 : { // Salir 
					cout << "GRACIAS POR VISITARNOS, ESPERAMOS TU REGRESO... \n\n" ;
					*Salir = true ;
					exit(1) ; // sale del ejecutable directamente
					break;
				}
							
				default : { // Opcion Incorrecta
					cout << "\nOPCION NO VALIDA \n\n" ;
					cout << "INTENTA DE NUEVO \n" ;
					system("pause") ;
					break;
				}
			} 
		}while (!*Salir) ;
	}else {
		system("cls") ;
		cout << "\n\t\tHAS INGRESADO DATOS NO VALIDOS \n" ;
		cout << "\t\tINTENTA DE NUEVO \n\n" ;
		system("pause") ;
		MenuIngreso() ; 
	}
	
	delete Salir ;
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::RegistroIDPersona() {
	bool* Salir = new bool (false) ;
	
	do {
		system("cls") ;
		cout << "\t\nRegistro De Usuario \n" ;
		cout << "Elige la opcion correspendiente... \n\n" ;
		cout << "1. INGRESAR COMO ESTUDIANTE \n" ;
		cout << "2. INGRESAR COMO PROFESOR \n" ;
		cout << "3. INGRESAR COMO PERSONAL ADMINISTRATIVO \n" ;
		cout << "4. FUNCIONES AL MANEJO DE INFORMACION DEL LABORATORIO \n" ;
		cout << "5. INGRESAR CON DATOS EXISTENTES \n" ; 
		cout << "6. Atras \n\n" ;
		
		this->Opcion = common::ValidarEntero("Ingresa una opcion: \n" ) ;

		int Cantidad = 1 ; // Para referir que solo puede registrarse una persona a la vez
		
		switch (this->Opcion) { // Registrarse como estudiante
			case 1 : {
				bool Estado = UsoDelLaboratorio->AgregarAlVectorEstudiantes(Cantidad) ;
				
				if (Estado == true) {
					*Salir = true ;
					MenuParaEstudiantes(UsoDelLaboratorio->MandarPosicionActual(0)) ;
				}
				break;
			}
			
			case 2 : { // Registrarse como Profesor
				bool Estado = UsoDelLaboratorio->AgregarAlVectorProfesores(Cantidad) ;
				
				if (Estado == true) {
					*Salir = true ;
					MenuParaProfesores(UsoDelLaboratorio->MandarPosicionActual(1)) ;
				}
				break;
			}
			
			case 3 : { // Registrarse como Personal Administrativo
				bool Estado = UsoDelLaboratorio->AgregarAlVectorPersonalAdmin(Cantidad) ;
				
				if (Estado == true) {
					*Salir = true ;
					MenuParaPersonalAdmi(UsoDelLaboratorio->MandarPosicionActual(3)) ;
				}
				system("pause") ; 
				break;
			}
			
			case 4 : { // Manejo de informacion del Laboratorio
				MenuInformacionLaboratorio() ; 
				break;
			}
			
			case 5 : { // Ingresar con datos ya existentes
				system("cls") ;
				MenuDatosExistentes() ;
				break;
			}
			
			case 6 : { // Atras
				MenuIngreso () ;
				*Salir = true ;
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nOPCION INVALIDA \n" ;
				cout << "INTENTA DE NUEVO \n" ;
				system("pause") ;
				break;
			}
		}
	}while (!*Salir) ;
	
	delete Salir ; 
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::MenuDatosExistentes() {
	bool* Salir = new bool (false) ;
	
	do {
		system("cls") ;
		
		cout << "\n\tDATOS EXISTENTES \n\n" ;
		cout << "1. INGRESAR COMO ESTUDIANTE \n" ;
		cout << "2. INGRESAR COMO PROFESOR \n" ;
		cout << "3. INGRESAR COMO PERSONAL ADMINISTRATIVO \n" ;
		cout << "4. Atras \n" ;
		cout << "5. Salir \n\n" ;
		
		this->Opcion = common::ValidarEntero("Elija una opcion\n") ; 
		
		switch(this->Opcion) {
			case 1 : { // Ingresar con datos de estudiantes
				if(UsoDelLaboratorio->VerificarVectorEstudiantes() == false) {
					UsoDelLaboratorio->getEstudiantes() ;
				
					this->Opcion = common::ValidarEntero("\n\nElija con que informacion desea ingresar \n") ; 
				
					MenuParaEstudiantes(this->Opcion) ;	
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
					RegistroIDPersona() ; 
				}
				break;
			}
			
			case 2 : { // Ingresar con datos de profesores
				if(UsoDelLaboratorio->VerificarVectorProfesores() == false) {
					UsoDelLaboratorio->getProfesores() ;
				
					this->Opcion = common::ValidarEntero("Elija con que informacion desea ingresar \n") ; 
				
					MenuParaProfesores(this->Opcion) ;
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
					RegistroIDPersona() ; 
				}		
				break;
			}
			
			case 3 : { // Ingresar con Datos de Personal Administrativo
				if(UsoDelLaboratorio->VerificarVectorAdmin() == false) {
					UsoDelLaboratorio->getPersonalAdmin() ;
				
					this->Opcion = common::ValidarEntero("Elija con que informacion desea ingresar \n") ; 
				
					MenuParaPersonalAdmi(this->Opcion) ;	
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
					RegistroIDPersona() ; 
				}				
				break;
			}
			
			case 4 : { // Atras
				*Salir = true ;
				RegistroIDPersona() ;
				break;
			}
			
			case 5 : { // Salir
				cout << "\nESPERAMOS SU REGRESO \n\n" ;
				system("pause") ;
				exit(1) ; // Sale del ejecutable directamente
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nOPCION INCORRECTA \n" ;
				cout << "INTENTE DE NUEVO \n" ;
				system("pause") ;
				break;
			}
		}
	}while(!*Salir) ;	
}


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////



void Menu::MenuParaProfesores(int Posicion) {
	
	bool* Salir = new bool ;
	
	do {
		system("cls") ;
		
		cout << "\n\tFUNCIONES DISPONIBLES PARA PROFESORES \n\n" ;
		cout << "1. VER MI INFORMACION DISPONIBLE \n" ;
		cout << "2. VER ARTICULOS ENCARGADOS \n" ;
		cout << "3. VER PROFESORES REGISTRADOS EN EL LABORATORIO \n" ;
		cout << "4. MODIFICAR DATOS BASICOS \n" ;
		cout << "5. Atras \n" ;
		cout << "6. Salir \n\n" ; 
		
		this->Opcion = common::ValidarEntero("Elija una opcion\n") ; 
		
		switch(this->Opcion) {
			case 1 : { // Ver mi informacion disponible
				
				UsoDelLaboratorio->AccederProfesorPosicion(Posicion) ;
				system("pause") ; 
				
				break;
			}
			
			case 2 : { // Ver informacion de los articulos 
				UsoDelLaboratorio->AccederArticulosProfe(Posicion) ;
				system("pause") ;
				
				break;
			}
			
			case 3 : { // Ver todos los profesores 
				UsoDelLaboratorio->getProfesores() ;
				
				system("pause") ;
				break;
			}
			
			case 4 : { // Modificar datos basicos
				UsoDelLaboratorio->ModificarDatosBasicosProfe(Posicion) ;
								
				break;
			}
			
			case 5 : { // Atras
				RegistroIDPersona() ;
				break;
			}
			
			case 6 : { // Salir
				cout << "\nESPERAMOS SU REGRESO, ADIOS... \n\n" ;
				system("pause") ;
				exit(1) ; // Sale del ejecutable directamente
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nHOPCION INCORRECTA \n" ;
				cout << "INTENTE DE NUEVO \n" ;
				system("pause") ;
				break;
			}
		}
		
	}while(!*Salir) ;
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::MenuExclusivoProfe(){

	bool* Salir = new bool (false) ;
	
	do{
		system("cls") ;
		
		cout << "\n\tFUNCIONES DISPONIBLES PARA PROFESORES \n\n" ;	
		cout << "1. VER TODOS LOS PROFESORES EXISTENTES \n" ;
		cout << "2. VER ARTICULOS ASIGNADOS A UN PROFESOR \n" ;
		cout << "3. REGISTRAR PROFESORES \n" ;
		cout << "4. MODIFICAR INFORMACION DE UN PROFESOR \n" ;
		cout << "5. ELIMINAR UN PROFESOR DEL SISTEMA \n" ;
		cout << "6. Atras\n" ;
		cout << "7. Salir \n\n" ;
		
		this->Opcion = common::ValidarEntero("Elija una Opcion: \n") ;
		
		
		switch(this->Opcion) {
			case 1 : { // Ver todos los profesores 
				UsoDelLaboratorio->getProfesores() ;
				system("pause") ;	
				break;
			}
			
			case 2 : { //Ver articulos Asignados
				UsoDelLaboratorio->getProfesores() ;
				
				this->Opcion = common::ValidarEntero("Elija el indicador del profesor: \n") ;
				
				UsoDelLaboratorio->AccederArticulosProfe(this->Opcion) ;
				system("pause") ;
				break;
			}
			
			case 3 : { // Registrar profesores
				system("cls") ;
				
				cout << "\nCuantos profesores quiere registrar? \n\n" ;
				this->Opcion = common::ValidarEntero("Ingrese la cantidad de profesores a registrar: \n") ;
				
				UsoDelLaboratorio->AgregarAlVectorProfesores(this->Opcion) ;
				system("pause") ;
				break;
			}
			
			case 4 : { //Modifica los datos personales de un profesor
				UsoDelLaboratorio->getProfesores() ;
				
				this->Opcion = common::ValidarEntero("Elija el indicador del profesor: \n") ;
				
				UsoDelLaboratorio->ModificarDatosProfe(this->Opcion) ;
				system("pause") ;
				break;
			}
			
			case 5 : { //Eliminar un profesor
				UsoDelLaboratorio->EliminarDatosDelVectorProfesor() ;
				system("pause") ;
				break;
			}
			
			case 6 : { //Atras
				*Salir = true ; 
				break;
			}
			
			case 7 : { //Salir
				cout << "\nESPERAMOS SU REGRESO, ADIOS... \n\n" ;
				system("pause") ;
				exit(1) ;
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nOPCION INCORRECTA \n" ;
				cout << "INTENTE DE NUEVO \n" ;
				system("pause") ;
				system("cls") ;
				break;
			}
		}  
	}while(!*Salir) ;
}


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


void Menu::MenuParaArticulosDePrestamo(){
	
	bool* Salir = new bool (false) ;
		    
    do{
    	system("cls");
    	
    	cout << "\n\tFUNCIONES PERMITIDAS PARA ARTICULOS DE PRESTAMOS \n\n" ;
    	cout << "1. VER TODOS LOS ARTICULOS PRESTADOS \n" ;
    	cout << "2. VER UN ARTICULO EN ESPECIFICO \n" ;
    	cout << "3. REGISTRAR UN ARTICULO DE PRESTAMO \n" ;
    	cout << "4. MODIFICAR UN ARTICULO \n" ;
    	cout << "5. ELIMINAR UN ARTICULO \n" ;
    	cout << "6. Atras \n" ;
    	cout << "7. Salir \n\n" ;
    	
    	this->Opcion = common::ValidarEntero("Elija una Opcion: \n") ;
    	
    	switch(this->Opcion){
    		case 1 :{ // Ver todos los articulos
    			if (UsoDelLaboratorio->VerificarArticulosPrestamo() == false) {
					UsoDelLaboratorio->getPrestamos() ;
    				system("pause");
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
				}
    			
				break;
			}
			
			case 2 :{ // Ver un articulo en especifico
				if (UsoDelLaboratorio->VerificarArticulosPrestamo() == false) {
					UsoDelLaboratorio->getPrestamos() ;
					this->Opcion = common::ValidarEntero("Elija ucual desea ver especificamente? \n") ;					
					
					UsoDelLaboratorio->AccederArticulosPrestamo(Opcion);
					system("pause");
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
				}
				
				break;
			}
			
			case 3 :{ // Registrar nuevos articulos de prestamos
				
				cout << "\nPor favor ingrese la cantidad de articulos que desea registrar \n\n" ;
				
				this->Opcion = common::ValidarEntero("Ingrese la cantidad: \n") ;
				
				bool Estado = UsoDelLaboratorio->AgregarAlVectorPrestamo(this->Opcion) ; 
				system("pause") ;
				
				if (Estado == false) {
					*Salir = true ;
					MenuParaArticulosDePrestamo() ;
				}
				
				break;
			}
			
			case 4 :{  // Modificar 
				
				UsoDelLaboratorio->getPrestamos() ;
				
				this->Opcion = common::ValidarEntero("\nQue articulo desea modificar ? \n") ;
					
				UsoDelLaboratorio->ModificarDatosArticulosPrestamos(this->Opcion) ; 
					
				system("pause") ; 
				
				break;
			}
			
			case 5 :{ // Eliminar
				
				UsoDelLaboratorio->EliminarDatosDelVectorArticuloPrestamos() ;
				
				system("pause") ; 
				break;
			}
			
			case 6 :{ // Atras
				*Salir = true ; 
				break;
			}
			
			case 7 :{ // Salir
				cout << "\nESPERAMOS SU REGRESO, ADIOS... \n\n" ;
				system("pause") ;
				exit(1) ;
				break;
			}
			
			default :{ // Opcion Incorrecta
				cout << "\nOPCION INCORRECTA \n" ;
				cout << "INTENTE DE NUEVO \n" ;
				system("pause") ;
				system("cls") ;
				break;
			}
		}
	}while (!*Salir) ;
		
	
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::MenuParaEstudiantes(int Posicion) {
	bool* Salir = new bool (false) ;
	
	do {
		system("cls") ;
		
		cout << "\n\t\tMENU EXCLUSIVO PARA ESTUDIANTES \n\n" ;
		cout << "1. VER MI INFORMACION PERSONAL \n" ;
		cout << "2. VER ESTUDIANTES REGISTRADOS EN EL LABORATORIO \n" ;
		cout << "3. VER ARTICULOS DE PRESTAMO DISPONIBLES PARA PRESTAMOS \n" ;
		cout << "4. VER MIS ARTICULOS PRESTADOS \n" ; 
		cout << "5. DILIGENCIAR PRESTAMOS \n" ;
		cout << "6. DILIGENCIAR DEVOLUCION \n" ;
		cout << "7. DILIGENCIAR PAGO DE MULTA \n" ; 
		cout << "8. CONSULTAR MI ESTADO Y VALOR DE MULTA \n" ;
		cout << "9. Atras \n" ;
		cout << "10. Salir \n\n" ;
		
		this->Opcion = common::ValidarEntero("Elija una opcion\n") ;
		
		switch (this->Opcion) {
			case 1 : { // Ver mi informacion es decir el de registrado
				// Nota : 0 = Al vector de estudiantes, y lo utilizamos para sacar la ultima posicion del vector que es donde se encuentra mis datos
				UsoDelLaboratorio->AccederAUnEstudiante(Posicion) ; 
				
				system("Pause") ;
				break;
			}
			
			case 2 : { // Ver todos los estudiantes registrados en el Laboratorio
				UsoDelLaboratorio->getEstudiantes() ; 
				system("pause") ;
				break;
			}
			
			case 3 : { // Ver articulos de prestamo disponible
				UsoDelLaboratorio->getPrestamos() ;
				system("pause") ;
				break;
			}
			
			case 4 : { // Ver mis articulos prestados
				system("cls") ; 
				UsoDelLaboratorio->VerMisPrestados(Posicion) ;
				system("pause") ; 
				break;
			}
			
			case 5 : { //diligenciar prestamos
				if (UsoDelLaboratorio->VerificarArticulosPrestamo() == false) {
					UsoDelLaboratorio->getPrestamos() ;
					
					cout << "\n\tEsta Opcion esclusiva del estudiante perrmite acceder a un prestamo de un articulo \n\n" ;
					this->Opcion = common::ValidarEntero("Por favor seleccione que articulo desea prestar \n") ;
					
					UsoDelLaboratorio->ServicioPrestamo(Posicion, this->Opcion) ;	
				}else {
					system("cls") ;
					cout << "\n\tNo han registrados articulos de tipo prestamo \n\n" ;
					*Salir = true ; 
				}
				system("pause") ;
				break;
			}
			
			case 6 : { // diligenciar devolucion
				bool Estado ; 
				if (UsoDelLaboratorio->VerificarArticulosPrestamo() == false) {
					
					Estado = UsoDelLaboratorio->ServicioDevolucion(Posicion) ;
					
				}else {
					cout << "\n\tERROR !!! \n" ;
					cout << "\tNo puedes ejecutar la funcion de devolucion por razones de no haber registro de articulos de Prestamo \n\n" ;
				}				
				system("pause") ; 	
				
				if (Estado == true) {
					cout << "\n\tTe redigiriendo al menu anterios para que se conserven los cambios \n\n" ; 
					system("pause") ; 
					*Salir = true ;
					RegistroIDPersona() ; 
				}
				break;
			}
			
			case 7 : { // Diligenciar pago de multa	
				UsoDelLaboratorio->RealizarPagoMulta(Posicion) ; 
				system("pause") ;
				break;
			}
			
			case 8 : { //consultar estado y valor de multa					
				UsoDelLaboratorio->AccederEstadoMultaEstudiante(Posicion) ;
				system("pause") ;
				break;
			}
			
			case 9 : { // Atras
				*Salir = true ;
				RegistroIDPersona () ;
				
				break;
			}
			
			case 10 : { // Salir
				cout << "\nESPERAMOS SU REGRESO, ADIOS... \n\n" ;
				system("pause") ;
				exit(1) ; // sale del ejecutable directamente
				break;
			}
						
			default : { // Opcion Incorrecta
				cout << "\nOPCION INCORRECTA \n" ;
				cout << "INTENTE DE NUEVO \n" ;
				system("pause") ;
				break;
			}
		}
	}while (!*Salir) ;
	
	delete Salir ;
}


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::MenuExclusivoEstudiante(){

	bool* Salir = new bool (false) ;
	
	int Eleccion ;
	
	do {
	
		system("cls");
		
		cout << "\n\t FUNCIONES PARA ESTUDIANTES \n\n\n";
		
		cout << "1. VER TODOS LOS ESTUDIANTES. \n" ;
		cout << "2. VER UN ESTUDIANTE EN ESPECIFICO. \n";
		cout << "3. REGISTRAR UN ESTUDIANTE. \n";
		cout << "4. MODIFICAR UN ESTUDIANTE. \n";
		cout << "5. ELIMINAR UN ESTUDIANTE. \n" ;
		cout << "6. Atras. \n" ;
		cout << "7. Salir. \n";
		
		Eleccion = common::ValidarEntero("Elija una Opcion: \n") ;
		
		switch(Eleccion){
			case 1 : { // Ver todos los estudiantes
				cout << "Todos los estudiantes registrados son: ";
				UsoDelLaboratorio->getEstudiantes();
				system("pause");
				break;
			}
			
			case 2 : { // Ver un estudiante en especifico 
				UsoDelLaboratorio->getEstudiantes();
				
				this->Opcion = common::ValidarEntero("Elija una Opcion: \n") ; 
				
				cout<< "El estudiante que eligio es:";
				UsoDelLaboratorio->AccederAUnEstudiante(this->Opcion);
				system("pause");
				break;
			}
			
			case 3 : { // Registrar estudiantes
				cout << "Cuantos estudiantes quiere registrar \n";
				this->Opcion = common::ValidarEntero("Elija una Opcion: \n") ;
				
				bool Estado = UsoDelLaboratorio->AgregarAlVectorEstudiantes(this->Opcion);
				
				if (Estado == false) {
					*Salir = true ;
					MenuExclusivoEstudiante() ; 
				}
				break;
			}
			
			case 4 : { // Modificar estudiantes
				cout << "Modificacion de estudiante";
				UsoDelLaboratorio->getEstudiantes() ;
				this->Opcion = common::ValidarEntero("Elija el estudiante que desea modificar: ") ;
				UsoDelLaboratorio->ModificarDatosEstudiante(this->Opcion) ;
				system("pause");
				break;
			}
			
			case 5 : { // Eliminar algun estudiante
				
				UsoDelLaboratorio->getEstudiantes() ;
			
				this->Opcion = common::ValidarEntero("Elija el estudiante que desea eliminar: ") ;
				
				UsoDelLaboratorio->EliminarDatosDelVectorEstudiante(this->Opcion);
				system("pause");
				break;
			}
			
			case 6 : { // Atras
				*Salir = true ;
				break;
			}
			
			case 7 : { // Salir
				cout << "\nESPERAMOS SU REGRESO, ADIOS... \n\n" ;
				system("pause") ;
				exit(1) ; // sale del ejecutable directamente
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nOPCION INCORRECTA \n" ;
				cout << "INTENTE DE NUEVO \n" ;
				system("pause") ;
				break;
			}
		}
	}while(!*Salir);
	
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::MenuParaArticulosDeMueble() {
	
	bool* Salir = new bool (false) ;
	int Cantidad ;
	
	
	do {
		system("cls") ;
		
		cout << "\n\tFUNCIONES DISPONIBLES  \n\n" ;
		cout << "1. VER ARTICULOS DE MUEBLE REGISTRADOS. \n" ;
		cout << "2. VER UN ARTICULO EN ESPECIFICO. \n" ; 
		cout << "3. REGISTRAR NUEVOS ARTICULOS DE MUEBLE. \n" ;
		cout << "4. MODIFICAR ARTICULOS DE MUEBLE. \n" ;
		cout << "5. ELIMINAR ARTICULOS DE MUEBLE. \n" ;
		cout << "6. Atras \n" ;
		cout << "7. Salir \n\n" ; 
		
		this->Opcion = common::ValidarEntero("Elija una opcion \n") ;
		
		switch(this->Opcion) {
			case 1 : { // Ver articulos registrados
				system("cls") ;
				
				if (UsoDelLaboratorio->VerificarArticulosMueble() == false) {
					UsoDelLaboratorio->getMuebles() ;
	
					system("pause") ; 
					
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
					 
				}
				break;
			}
			
			case 2 : { // Ver articulo en especifico
				system("cls") ; 
				
				if (UsoDelLaboratorio->VerificarArticulosMueble() == false) {
					UsoDelLaboratorio->getMuebles() ;
					
					cout << "\nIngrese el articulo que desea ver su informacion \n\n" ;
					cin  >> this->Opcion ;
					UsoDelLaboratorio->AccederAMueble(this->Opcion) ;
					
					system("pause") ;
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
				}  
				
				break;
			}
				
			case 3 : { // Registrar Articulos
				system("cls") ;
				
				Cantidad = common::ValidarEntero("\nCuantos articulos desea requistar ? \n") ;
					
				bool Estado = UsoDelLaboratorio->AgregarAlVectorMueble(Cantidad) ;
				system("pause") ; 
				
				if (Estado == false) {
					*Salir = true ;
					MenuParaArticulosDeMueble() ;
				}

				break;
			}
				
			case 4 : { // Modificar Articulos
				system("cls") ;
				
				if (UsoDelLaboratorio->VerificarArticulosMueble() == false){
					UsoDelLaboratorio->getMuebles() ;
					
					this->Opcion = common::ValidarEntero("\nQue articulo desea modificar ? \n") ;
					
					UsoDelLaboratorio->ModificarDatosMueble(this->Opcion) ;
					 
					system("pause") ;
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
				}
				break;
			} 
				
			case 5 : { // Eliminar Articulos 
				system("cls") ;
				
				if (UsoDelLaboratorio->VerificarArticulosMueble() == false){
					UsoDelLaboratorio->EliminarDatosDelVectorMueble() ;
					system("pause") ;
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
				}
				break;
			}
			
			case 6 : { // Atras
				*Salir = true ; 
				break;
			}
				
			case 7 : { // Salir
				cout << "\nESPERAMOS SU REGRESO, ADIOS... \n\n" ;
				system("pause") ;
				exit(1) ;
				break;
			}
				
			default : { // Opcion Incorrecta
				cout << "\nOPCION INCORRECTA \n" ;
				cout << "INTENTE DE NUEVO \n" ;
				system("pause") ;
				break;
			}
		}
	}while(!*Salir) ;
	
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


void Menu::MenuParaArticulosDeComputo() {
	
	bool* Salir = new bool (false) ;
	int Cantidad ;
	
	
	do {
		system("cls") ;
		
		cout << "\n\tFUNCIONES DISPONIBLES. \n\n" ;
		cout << "1. VER ARTICULOS DE COMPUTO REGISTRADOS. \n" ;
		cout << "2. VER UN ARTICULO EN ESPECIFICO. \n" ; 
		cout << "3. REGISTRAR NUEVOS ARTICULOS DE COMPUTO. \n" ;
		cout << "4. MODIFICAR ARTICULOS DE COMPUTO. \n" ;
		cout << "5. ELIMINAR ARTICULOS DE COMPUTO. \n" ;
		cout << "6. Atras. \n" ;
		cout << "7. Salir. \n\n" ; 
		
		this->Opcion = common::ValidarEntero("Elija una opcion \n") ;
		
		switch(this->Opcion) {
			case 1 : { // Ver articulos registrados
				system("cls") ;
				
				if (UsoDelLaboratorio->VerificarArticulosCompu() == false) {
					UsoDelLaboratorio->getComputo() ;
				
					system("pause") ; 
					
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
					 
				}
				break;
			}
			
			case 2 : { // Ver articulo en especifico
				system("cls") ; 
				
				if (UsoDelLaboratorio->VerificarArticulosCompu() == false) {
					cout << "\nIngrese el articulo que desea ver su informacion \n\n" ;
					cin  >> this->Opcion ;
					UsoDelLaboratorio->AccederAComputo(this->Opcion) ;
					
					system("pause") ;
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
				}  
				
				break;
			}
				
			case 3 : { // Registrar Articulos
				system("cls") ;
				
				Cantidad = common::ValidarEntero("\nCuantos articulos desea requistar ? \n") ;
					
				bool Estado = UsoDelLaboratorio->AgregarAlVectorComputo(Cantidad) ;
				system("pause") ; 
				
				if (Estado == false) {
					*Salir = true ;
					MenuParaArticulosDeComputo() ;
				}
				break;
			}
				
			case 4 : { // Modificar Articulos
				system("cls") ;
				
				if (UsoDelLaboratorio->VerificarArticulosCompu() == false){
					UsoDelLaboratorio->ModificarDatosDelVectorComputo() ; 
					system("pause") ;
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
				}
				break;
			} 
				
			case 5 : { // Eliminar Articulos 
				system("cls") ;
				
				if (UsoDelLaboratorio->VerificarArticulosCompu() == false){
					UsoDelLaboratorio->EliminarDatosDelVectorComputo() ;
					system("pause") ;
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
				}
				break;
			}
			
			case 6 : { // Atras
				*Salir = true ; 
				break;
			}
				
			case 7 : { // Salir
				cout << "\nESPERAMOS SU REGRESO, ADIOS... \n\n" ;
				system("pause") ;
				exit(1) ;
				break;
			}
				
			default : { // Opcion Incorrecta
				cout << "\nOPCION INCORRECTA \n" ;
				cout << "INTENTE DE NUEVO \n" ;
				system("pause") ;
				break;
			}
		}
	}while(!*Salir) ;
	
	
}



/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::MenuParaPersonalAdmi(int Posicion) {
	bool* Salir = new bool (false) ;
	
	
	do {
		system("cls") ;
		
		cout << "\n\tFUNCIONES DISPONIBLES. \n\n" ;
		cout << "1. VER MI INFORMACION DISPONIBLE. \n" ; 
		cout << "2. ELIMINAR OTRO PERSONAL ADMINISTRATIVO. \n" ; 
		cout << "3. FUNCIONES: PARA INFORMACION DEL LABORATORIO. \n" ;
		cout << "4. FUNCIONES: PARA Estudiantes DEL LABORATORIO. \n" ;
		cout << "5. FUNCIONES: PARA Profesores DEL LABORATORIO. \n" ;
		cout << "6. FUNCIONES: PARA ARTICULOS DE COMPUTO DEL LABORATORIO. \n" ;
		cout << "7. FUNCIONES: PARA ARTICULOS DE MUEBLE DEL LABORATORIO. \n" ;
		cout << "8. FUNCIONES: PARA ARTICULOS DE PRESTAMO DEL LABORATORIO. \n" ;
		cout << "9. IR A MENU PRINCIPAL. \n" ;
		cout << "10. Salir. \n\n" ;
		
		this->Opcion = common::ValidarEntero("Elija una opcion\n") ;
		
		switch (this->Opcion) {
			case 1 : { // Ver mi informacion
				
				UsoDelLaboratorio->AccederPersonalAdmi(Posicion) ;
				system("pause") ;
				
				break;
			}
			
			case 2 : { // Eliminar otro personal adiminstrativo
				
				UsoDelLaboratorio->EliminarDatosDelVectorAdmi() ;
				system("pause") ; 
				break;
			}
			
			case 3 : { // Funciones para informaciones
				cout << "\nEn Cualquier momento sera dirigido \n" ;
				system("pause") ;
				
				if (UsoDelLaboratorio->VerificarVectorInformaciones() == false) {
					MenuInformacionLaboratorio() ;
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
					MenuInformacionLaboratorio() ;
				}
				break;
			}
			
			case 4 : { // Menu exclusivo de estudiantes
				cout << "\nEn Cualquier momento sera dirigido \n\n" ;
				system("pause") ;
				
				if (UsoDelLaboratorio->VerificarVectorEstudiantes() == false) {
					MenuExclusivoEstudiante() ;
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					cout << "\nPor favor registre Al menos un estudiante \n\n" ;
					system("pause") ;
					system("cls") ;
					
					cout << "\nPor favor registre algun estudiante \n\n" ;				
					this->Opcion = common::ValidarEntero("\n\nCuantos Estudiantes desea registrar? \n") ;
					
					bool Estado = UsoDelLaboratorio->AgregarAlVectorEstudiantes(this->Opcion) ;
					
					if (Estado == false) {
						system("pause") ;
						*Salir = true ;
						MenuParaPersonalAdmi(Posicion) ;
					}
				}
				break;
			}
			
			case 5 : { //Menu para funciones exclusivas de profesor desde administrador				
				cout << "\nEn Cualquier momento sera dirigido \n\n" ;
				system("pause") ;
				
				if (UsoDelLaboratorio->VerificarVectorProfesores() == false) {
					MenuExclusivoProfe();
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					cout << "\nPor favor registre Al menos un Profesor \n\n" ;
					system("pause") ;
					system("cls") ;
					
					cout << "\nPor favor registre algun profesor \n\n" ;				
					this->Opcion = common::ValidarEntero("\n\nCuantos Profesores desea registrar? \n") ;
					bool Estado = UsoDelLaboratorio->AgregarAlVectorProfesores(this->Opcion) ;
					
					if (Estado == false) {
						*Salir = true ;
						MenuParaPersonalAdmi(Posicion) ;
					}
				}
				break;
			}
			
			case 6 : { // Funciones para articulos de computo
				cout << "\nEn Cualquier momento sera dirigido \n\n" ;
				system("pause") ;
				
				if (UsoDelLaboratorio->VerificarArticulosCompu() == false) {
					MenuParaArticulosDeComputo() ;
					
				}else {
					system("cls") ;
					cout << "\nNo existen datos de registro \n\n" ;
					cout << "\nPor favor registre articulos de computo \n\n" ;
					system("pause") ;
					system("cls") ;
					
					if (UsoDelLaboratorio->VerificarVectorProfesores() == false) {				
						this->Opcion = common::ValidarEntero("\n\nCuantos articulos desea registrar? \n") ;
						
						bool Estado = UsoDelLaboratorio->AgregarAlVectorComputo(this->Opcion) ;
						if(Estado == false) {
							*Salir = true ;
							MenuParaPersonalAdmi(Posicion) ;
						}
						
					}else {
						cout << "\nPor favor registre al menos un profesor para poder proceder al registro de articulos \n\n" ;				
						this->Opcion = common::ValidarEntero("Cuantos Profesores desea registrar? \n") ;
						bool Estado = UsoDelLaboratorio->AgregarAlVectorProfesores(this->Opcion) ;
						
						if (Estado == false) {
							*Salir = true ;
							MenuParaPersonalAdmi(Posicion) ;
						}
					}					
				}
				
				break;
			}
			
			case 7 : { // Funciones para articulos de Mueble
				cout << "\nEn Cualquier momento sera dirigido \n\n" ;
				system("pause") ;
				
				if (UsoDelLaboratorio->VerificarArticulosMueble() == false) {
					MenuParaArticulosDeMueble() ; 
				}else {
					system("cls") ;
					cout << "\nNo existen datos de registro \n" ;
					cout << "Registre articulos de muebles \n\n" ;
					system("pause") ;
					system("cls") ;
					
					if (UsoDelLaboratorio->VerificarVectorProfesores() == false) {				
						this->Opcion = common::ValidarEntero("\n\nCuantos articulos desea registrar? \n") ;
						
						bool Estado = UsoDelLaboratorio->AgregarAlVectorMueble(this->Opcion) ;
						
						if (Estado == false) {
							*Salir = true ;
							MenuParaPersonalAdmi(Posicion) ;
						}
					}else {
						cout << "\nPor favor registre al menos un profesor para poder proceder al registro de articulos \n\n" ;				
						this->Opcion = common::ValidarEntero("Cuantos Profesores desea registrar? \n") ;
						bool Estado = UsoDelLaboratorio->AgregarAlVectorProfesores(this->Opcion) ;
						
						if (Estado == false) {
							*Salir = true ;
							MenuParaPersonalAdmi(Posicion) ;
						}
					}
				}
				break;
			}
			
			case 8 : { // Funciones para articulos de Prestamo
				cout << "\nEn Cualquier momento sera dirigido \n\n" ;
				system("pause") ;
				
				if (UsoDelLaboratorio->VerificarArticulosPrestamo() == false) {
					MenuParaArticulosDePrestamo() ;
				}else {
					system("cls") ;
					cout << "\nNo existen datos de registro \n" ;
					cout << "Registre articulos de prestamo \n\n" ;
					system("pause") ;
					system("cls") ;
					
					if (UsoDelLaboratorio->VerificarVectorProfesores() == false) {				
						this->Opcion = common::ValidarEntero("\n\nCuantos articulos desea registrar? \n") ;
						
						bool Estado = UsoDelLaboratorio->AgregarAlVectorPrestamo(this->Opcion) ;
						
						if (Estado == false) {
							MenuParaPersonalAdmi(Posicion) ;
						}
					}else {
						cout << "\nPor favor registre al menos un profesor para poder proceder al registro de articulos \n\n" ;				
						this->Opcion = common::ValidarEntero("Cuantos Profesores desea registrar? \n") ;
						bool Estado = UsoDelLaboratorio->AgregarAlVectorProfesores(this->Opcion) ;
						
						if (Estado == false ){
							*Salir = true ;
							MenuParaPersonalAdmi(Posicion) ;
						}
					}
				}
				break;
			}
			
			case 9 : { // Atras
				MenuIngreso() ;
				*Salir = true ;
				break;
			}
			
			case 10 : { // Salir 
				cout << "\nESPERAMOS SU REGRESO, ADIOS... \n\n" ;
				system("pause") ;
				exit(1) ;
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nOPCION INCORRECTA \n" ;
				cout << "INTENTE DE NUEVO \n" ;
				system("pause") ;
				break;
			}
		} 	
	}while(!*Salir) ;
}


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


void Menu::MenuInformacionLaboratorio() {
	bool* Salir = new bool (false) ;
	int Cantidad ;
	
	do {
		system("cls") ;
		
		cout << "\n\tFUNCIONES DISPONIBLES.  \n\n" ;
		cout << "1. VER INFORMACION PRINCIPAL EL LABORATORIO. \n" ;
		cout << "2. AGREGAR INFORMACION AL LABORATORIO. \n" ;
		cout << "3. MODIFICAR INFORMACION AL LABORATORIO. \n" ;
		cout << "4. ELIMNAR DATOS AGREGADOS AL LABORATORIO. \n" ;
		cout << "5. Atras. \n" ;
		
		this->Opcion = common::ValidarEntero("Elija una opcion\n") ;
		
		switch (this->Opcion) {
			case 1 : { // Ver toda la informacion del Laboratorio disponible
				UsoDelLaboratorio->getInformaciones() ;
				cout << "\n" ; 
				system("pause") ;
				break;
			}
			
			case 2 : { // Agregar informacion al Laboratorio
				system("cls") ;
				cout << "Ingrese la cantidad de datos que desea agregar \n" ;
				Cantidad = common::ValidarEntero("Digete la cantidad de informacion que desea registrar \n") ;
				
				UsoDelLaboratorio->AgregarAlVectorInformaciones(Cantidad) ; 
				system("pause") ; 
				break;
			}
			
			case 3 : { // Modificar datos del Laboratorio
				system("cls") ;
				
				cout << "\nEs hora modificar !!! \n" ;
				system("pause") ;
				UsoDelLaboratorio->ModificarDatosDelVectorInformaciones() ;
				break;
			}
			
			case 4 : { // Eliminar datos del Laboratorio Exclusivo para personal Adiministrativo
				system("cls") ;
				
				cout << "\nA continuacion podras eliminar informacion del Laboratorio \n" ;
				cout << "Solo podras eliminar informacion agregada \n\n" ;
				system("pause") ;
				UsoDelLaboratorio->EliminarDatosDelVectorInformaciones() ;
								
				break;
			}
			
			case 5 : { // Atras 
				*Salir = true ; 
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nOPCION INCORRECTA \n" ;
				cout << "INTENTE DE NUEVO \n" ;
				system("pause") ;
				system("cls") ;
				break;
			}
		}
	}while(!*Salir) ;
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::MenuConsultas() {
	bool* Salir = new bool (false) ;
	
	do {
		system("cls") ;
		
		cout << "\n\tFUNCIONES DISPONIBLES PARA CONSULTAS. \n\n" ;
		cout << "1. CONSULTAR ARTICULOS ASIGNADOS A UN PROFESOR. \n" ;
		cout << "2. CONSULTAR ASIGNACION DE ARTICULO. \n" ;
		cout << "3. CONSULTAR HISTORIAL DE PRESTAMO DE UN ARTICULO. \n" ;
		cout << "4. CONSULTAR HISTORIAL DE PRESTAMO DE UN ESTUDIANTE. \n" ;
		cout << "5. CONSULTAR MULTA Y ESTADO DE PRESTAMO DE UN ESTUDIANTE. \n" ;
		cout << "6. CONSULTAR PRESTAMOS REALIZADOS EN FECHAS DETERMINADAS. \n" ;
		cout << "7. CONSULTAR VALOR, DEPRECIACION Y ESTADO DE UN ARTICULO. \n" ; 
		cout << "8. CONSULTAR LOS ARTICULOS ACTIVOS E INACTIVOS. \n" ;
		cout << "9. ELIMINAR HISTORIAL COMPLETO DEL LABORATORIO \n" ; 
		cout << "10. REGLAS DEL LABORATORIO \n" ; 
		cout << "11. Atras. \n" ;
		cout << "12. Salir \n\n" ;
		
		this->Opcion = common::ValidarEntero("Elija una opcion\n") ;
		
		switch(this->Opcion) {
			case 1 : { // Consultar Articulos de profesor
				UsoDelLaboratorio->ConsultaProfeArticulos() ;
				system("pause") ; 
				break;
			}
			
			case 2 : { // Consultar asignacion del articulo
				UsoDelLaboratorio->ConsultaAsignacionArt() ; 
				system("pause") ; 
				break;
			}
			
			case 3 : { // Consultar Historial de articulo Prestamo
				system("cls") ;
				UsoDelLaboratorio->MostrarHistorialArticulo() ; 
				system("pause") ; 
				break;
			}
			
			case 4 : { // Consultar Historial de prestamo estudiante
				UsoDelLaboratorio->MostrarHistorialEstudiante() ;
				system("pause") ; 
				break;
			}
			
			case 5 : { // Multa y Estado de estudiante
				UsoDelLaboratorio->ConsultaMultaYEstado() ;
				system("pause") ; 
				break;
			}
			
			case 6 : { // Consultar Prestamos en fechas
				UsoDelLaboratorio->MostrarHistorialConFechas() ;
				system("pause") ;
				break;
			}
			
			case 7 : { // Valor, Despreciacion Y estado de articulo
				UsoDelLaboratorio->ConsultaVDEArticulo() ;
				system("pause") ;
				break;
			}
			
			case 8 : { // Estados de activos o inactivos
				UsoDelLaboratorio->ConsultaActiInac() ;
				system("pause") ; 
				break;
			}
			
			case 9 : { // Eliminar Historial 
				UsoDelLaboratorio->EliminarHistorial() ;
				system("pause") ;
				break;
			}
			
			case 10 : { // Reglas
				UsoDelLaboratorio->Reglas() ;
				system("pause") ; 
				break; 
			}
			
			case 11 : { // Atras
				*Salir = true ; 
				break;
			}
			
			case 12 : { // Salir
				cout << "\nESPERAMOS SU REGRESO, ADIOS... \n\n" ;
				system("pause") ;
				exit(1) ;
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nOPCION INCORRECTA \n" ;
				cout << "INTENTE DE NUEVO \n" ;
				system("pause") ;
				system("cls") ;
				break;
			}
			
		}
	}while(!*Salir) ;
}


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

// DESTRUCTOR
Menu::~Menu() {
}
