#include<iostream>
using namespace std;

struct pais{
	string nombre, capital;
	int habitantes;
};
typedef struct pais paises;

struct continente{
	string nombreContinente;
	
	int poblacion = 0;
	
	paises paisxCon[5];
};


typedef struct continente continentes;

int main(){
	string mayorCapital;
	string nombreContinentePoblacion;
	bool encontreContinente = false;
	continentes continente[5];
	
	cout << "Ingrese los datos: " << endl << endl;
	
	for(int i = 0; i < 4; i++){
		cout << "Ingrese el nombre del continente " << i + 1 << ": " << endl;
		cin >> continente[i].nombreContinente;
		cout << endl;
		
		cout << "Introduzca la informacion de los paises para este continente: " << endl;
		
		for(int j = 0; j <= 4; j++){
			cout << "Nombre del pais " << j +1 << ": " << endl;
			cin >> continente[i].paisxCon[j].nombre;
			cout << "Nombre de la Capital: " << endl;
			cin >> continente[i].paisxCon[j].capital;
			cout << "Cantidad de habitantes: " << endl;
			cin >> continente[i].paisxCon[j].habitantes;
			continente[i].poblacion = continente[i].poblacion + continente[i].paisxCon[j].habitantes;
		}
	}
	
	cout << "Los datos ingresados son: "<< endl << endl;
	
	for(int i = 0; i <= 4; i++){
		int numMayor = 0;
		cout << "Continente " << i + 1 << ": " << continente[i].nombreContinente << endl;
		
		for(int j = 0; j <= 4; j++){
			cout << "Pais: " << j + 1<< ": " << continente[i].paisxCon[j].nombre << endl;
			cout << "Capital: " << continente[i].paisxCon[j].capital << endl;
			cout << "Habitantes: " << continente[i].paisxCon[j].habitantes << endl;
			if(continente[i].paisxCon[j].habitantes > numMayor){
				numMayor = continente[i].paisxCon[j].habitantes;
				mayorCapital = continente[i].paisxCon[j].capital;
			}
		}
		cout << "La capital con mayor poblacion es: " << mayorCapital << endl;	
	}
		cout << endl << endl << endl;
	
	
	cout << "Ingrese el nombre del contiente del que desea saber su poblacion total: ";
	cin >> nombreContinentePoblacion;
	
	for(int i = 0; i <=4; i++){
		if(continente[i].nombreContinente == nombreContinentePoblacion){
			cout << "La poblacion total de este continente es: " << continente[i].poblacion;
			encontreContinente = true;
		}
	}
	
	if(encontreContinente == false){
		cout << "El continente ingresado no existe";
	}
	
return 0;
}
