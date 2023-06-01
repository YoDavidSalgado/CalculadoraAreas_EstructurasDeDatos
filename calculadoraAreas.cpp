#include <iostream>
#include <string>
#include <locale>
#include <cmath>
#include <windows.h>
#define color SetConsoleTextAttribute

using namespace std;
	
class vectores {
	
private:
	int i, j, k, cantidad, cantidadVertices, calcular;
	float radio[10], areaCirculos[10];
	float ladoUno[10], ladoDos[10], areaCuadrados[10];
	float largo[10], ancho[10], areaRectangulos[10]; 
	float base[10], altura[10], areaTriangulos[10];
	float coordenadaX[10], coordenadaY[10], areaPoligono=0;
	
public:	
	void cantidadAreas ();
	void cargarRadios ();
	void operacionRadios ();
	void mostrarRadios ();
	void cargarLados ();
	void operacionLados ();
	void mostrarCuadrados ();
	void cargarLadosRectangulo ();
	void operacionLadosRectangulo ();
	void mostrarRectangulos ();
	void cargarLadosTriangulo ();
	void operacionLadosTriangulo ();
	void mostrarTriangulos ();
	void cargarCantidadVertices ();
	void cargarLadosPoligono ();
};	

void vectores :: cantidadAreas () {
	cout << endl << "\tCuantas areas deseas calcular: ";
	cin >> cantidad;
	cout << endl; 
}

void vectores :: cargarRadios () {
	for (i=0; i<cantidad; i++) {
		cout << "\tIngresa el radio del circulo #" << i+1 << " : ";
		cin >> radio[i];
	}
	cout << endl;
}	

void vectores :: operacionRadios () {
	for (int i=0; i<cantidad; i++){
		areaCirculos[i] = 3.141592 * (radio[i] * radio[i]);	
	}
}

void vectores :: mostrarRadios () {
	for (int i=0; i<cantidad; i++){
		cout << "\tEl area del circulo #" << i+1 << " es: "<< areaCirculos[i] << endl;
	}
	cout << endl;	
}

void vectores :: cargarLados () {
	for (i=0; i<cantidad; i++) {
		cout << "\tIngresa el primer lado del cuadrado #" << i+1 << " : ";
		cin >> ladoUno[i];
		cout << "\tIngresa el segundo lado del cuadrado #" << i+1 << " : ";
		cin >> ladoDos[i];
		cout << endl;
	}
}	

void vectores :: operacionLados () {
	for (int i=0; i<cantidad; i++){
		areaCuadrados[i] = ladoUno[i] * ladoDos[i];	
	}
}

void vectores :: mostrarCuadrados () {
	for (int i=0; i<cantidad; i++){
		cout << "\tEl area del cuadrado #" << i+1 << " es: "<< areaCuadrados[i] << endl;
	}
	cout << endl;	
}

void vectores :: cargarLadosRectangulo () {
	for (i=0; i<cantidad; i++) {
		cout << "\tIngresa el largo del rectangulo #" << i+1 << " : ";
		cin >> largo[i];
		cout << "\tIngresa el ancho del rectangulo #" << i+1 << " : ";
		cin >> ancho[i];
		cout << endl;
	}
}	

void vectores :: operacionLadosRectangulo () {
	for (int i=0; i<cantidad; i++){
		areaRectangulos[i] = largo[i] * ancho[i];	
	}
}

void vectores :: mostrarRectangulos () {
	for (int i=0; i<cantidad; i++){
		cout << "\tEl area del rectangulo #" << i+1 << " es: "<< areaRectangulos[i] << endl;
	}
	cout << endl;	
}

void vectores :: cargarLadosTriangulo () {
	for (i=0; i<cantidad; i++) {
		cout << "\tIngresa la base del triangulo #" << i+1 << " : ";
		cin >> base[i];
		cout << "\tIngresa la altura del triangulo #" << i+1 << " : ";
		cin >> altura[i];
		cout << endl;
	}
}	

void vectores :: operacionLadosTriangulo () {
	for (int i=0; i<cantidad; i++){
		areaTriangulos[i] = (base[i] * altura[i])/2;	
	}
}

void vectores :: mostrarTriangulos () {
	for (int i=0; i<cantidad; i++){
		cout << "\tEl area del triangulo #" << i+1 << " es: "<< areaTriangulos[i] << endl;
	}
	cout << endl;	
}

void vectores :: cargarLadosPoligono () {
	for (k=0; k<cantidad; k++) {
        cout << "\tPolígono irregular #" << k+1 << endl << endl;
        cout << "\tIngresa el número de vértices mayor a 3 ya que se calcula por triangulos: ";
        cin >> cantidadVertices;
        cout << endl;
        
        if (cantidadVertices<100 && cantidadVertices>2){
	        cout << "\tRecuerda ingresar los vértices en el orden en que aparecen en el polígono!" << endl;
	        cout << "\t(sentido horario o antihorario)" << endl << endl;
	        
	        for (i=0; i<cantidadVertices; i++) {
	            cout << "\tVértice " << i+1 << endl;
	            cout << "\tIngresa la coordenada x: ";
	            cin >> coordenadaX[i];
	            cout << "\tIngresa la coordenada y: ";
	            cin >> coordenadaY[i];
	            cout << endl;
	        }
	        
	        for (i=0; i<cantidadVertices; i++) {
	            calcular = (i + 1) % cantidadVertices;
	            areaPoligono += coordenadaX[i] * coordenadaY[calcular] - coordenadaX[calcular] * coordenadaY[i];
	        }
	        
	        areaPoligono = abs(areaPoligono / 2.0);
	        
	        cout << "\tEl area del poligono #" << k+1 << " es: " << areaPoligono << endl << endl;
    	} else {
    		cout << "\tLa cantidad de vertíces no se puede calcular ya que es la suma de triangulos y necesita minimo 3 vertíces!";
    		cout << endl << endl;
		}
    }
}

int main (int argc, char*argv[]) {
	
	setlocale(LC_ALL,"");
	system ("color 0");
	system ("title Calculadora, Figuras geometricas");
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	
	int opcion;
	vectores m;
	
	color(hConsole, 2);
	cout << endl << "\tBienvenido a calcular Areas de Figuras Geométricas!" << endl << endl;
	
	do {
		color(hConsole, 15);
		cout << "\t-----------------------------------------------" << endl;	
		cout << "\t|  Con que opcion desea proceder:             |" << endl;
		cout << "\t|                                             |" << endl;	
		cout << "\t|  1. Calcular area de circulos.              |" << endl;
		cout << "\t|  2. Calcular area de cuadrados.             |" << endl;
		cout << "\t|  3. Calcular area de rectángulos.           |"<< endl;
		cout << "\t|  4. Calcular area de triangulos.            |" << endl;
		cout << "\t|  5. Calcular area de polígonos irregulares. |" << endl;
		cout << "\t|  0. Salir.                                  |" << endl;
		cout << "\t-----------------------------------------------" << endl;
			
		cout << endl;
		cin >> opcion;
		cout << endl;
		system ("cls");
			
		if (opcion>=0 && opcion<6){
				
			switch (opcion){
				
			case 1:
				
				color(hConsole, 2);
				m.cantidadAreas();
				color(hConsole, 15);
				m.cargarRadios ();
				m.operacionRadios ();
				color(hConsole, 2);
				m.mostrarRadios ();
				
			break;
			
			case 2:
				
				color(hConsole, 2);
				m.cantidadAreas();
				color(hConsole, 15);
				m.cargarLados();
				m.operacionLados();
				color(hConsole, 2);
				m.mostrarCuadrados();
				
			break;
			
			case 3:
				
				color(hConsole, 2);
				m.cantidadAreas();
				color(hConsole, 15);
				m.cargarLadosRectangulo();
				m.operacionLadosRectangulo();
				color(hConsole, 2);
				m.mostrarRectangulos();
				
			break;
			
			case 4:
				
				color(hConsole, 2);
				m.cantidadAreas();
				color(hConsole, 15);
				m.cargarLadosTriangulo();
				m.operacionLadosTriangulo();
				color(hConsole, 2);
				m.mostrarTriangulos();
				
			break;
			
			case 5:
				
				color(hConsole, 2);
				m.cantidadAreas();
				color(hConsole, 15);
				m.cargarLadosPoligono();
				
			break;	
				}
		} else {
			color(hConsole, 4);
			cout << endl << "\tLa opción no esta dentro del menu." << endl << endl;
		}
	} while (opcion != 0);
	
	color(hConsole, 2);
	cout << endl << "\t\tVuelve pronto!" << endl;
	color(hConsole, 15);
	
	return 0;
}