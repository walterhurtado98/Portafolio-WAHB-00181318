#include<iostream>
using namespace std;

int main(){
	int numeros[] = {1,3,4,5,17,18,31,33};
	int inf,sup,mitad,dato =0,i;
	char band='F';
	
     cout << "Ingrese el numero a buscar: ";
     cin >> dato;
	

	inf=0;
	sup=8;
	i=0;
	while((inf<=sup)&&(i<8)){
		mitad = (inf+sup)/2;
		if(numeros[mitad] == dato){
			band='V';
			break;
		}
		if(numeros[mitad]>dato){
			sup = mitad;
			mitad = (inf+sup)/2;
		}
		if(numeros[mitad]<dato){
			inf = mitad;
			mitad = (inf+sup)/2;
		}
		i++;
	}
	
	if(band == 'V'){
		cout<<"El numero se encontro en la posicion: "<<mitad<<endl;
	}
	else{
		cout<<"El numero NO se encontro";
	}
	
	return 0;
}
