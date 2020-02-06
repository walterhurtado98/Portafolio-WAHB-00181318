#include <iostream>
using namespace std;

void llenarArreglo(int *puntero, int longi, int cont);
void mostrarArreglo(int *puntero, int longi);

int main(void){
	
	int opcion=0;
	int lon=0, buscado=0;
	
	cout<<"Ingrese la cantidad de valores a guardar en el arreglo: ";
	cin>>lon;
	
	int A[lon];
	llenarArreglo(A, lon-1, 1);
	cout<<endl;
	
	cout<<"Monstrando arreglo."<<endl;
	mostrarArreglo(A, lon-1);
	
	return 0;
}

void llenarArreglo(int *puntero, int longi, int cont){
	if(longi>=0){
		cout<<"Ingrese el valor de la posicion "<<cont<<": ";
		cin>> *puntero;
		llenarArreglo(puntero+1, longi-1, cont+1);
	}
}
void mostrarArreglo(int *puntero, int longi){
	if(longi>=0){
		cout<< *puntero;
		mostrarArreglo(puntero+1, longi-1);
	}
}

