#include <iostream>
using namespace std;

void llenarArreglo(int *puntero, int longi, int cont);
void mostrarArreglo(int *puntero, int longi);
int elementoBuscado(int *p, int longi, int busq, int conta);

int main(void){
	
	int opcion=0;
	int lon=0, buscado=0;
	
	cout<<"Ingrese la cantidad de valores a guardar en el arreglo: ";
	cin>>lon;
	cout << endl;
	
	int A[lon];
	llenarArreglo(A, lon-1, 1);
	cout<<endl;
	
	cout<<"\nMonstrando arreglo."<<endl;
	mostrarArreglo(A, lon-1);
	cout<<endl;
	
	cout<<"\nIngrese el numero a buscar: ";
	cin>>buscado;
	if(elementoBuscado(A, lon-1, buscado, 0)>1){
		cout<<"\nEl elemento "<<buscado<< " se repite: "<<elementoBuscado(A, lon-1, buscado, 0)<< " veces.";
	}else{
		cout<<"\nEl elemento "<<buscado<< " se repite: "<<elementoBuscado(A, lon-1, buscado, 0)<< " veces.";	
	}
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

int elementoBuscado(int *p, int longi, int busq, int conta){
	if (longi<0){
	    return conta;
}
	else{
		if(*(p+longi)==busq){
			conta+=1;
		}
		elementoBuscado(p, longi-1, busq, conta);
	}
	
}

