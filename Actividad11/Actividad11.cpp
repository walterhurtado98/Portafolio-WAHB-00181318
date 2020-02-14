#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Articulo{
    string nombre;
    int peso;
    float precio;
    bool perecedero;
};
vector<Articulo> bodega;

bool compNombre(Articulo a, Articulo b){
    return a.nombre < b.nombre;
}
bool compPeso(Articulo a, Articulo b){
    return a.peso < b.peso;
}
bool compPrecio(Articulo a, Articulo b){
    return a.precio < b.precio;
}

void agregar(), buscar(), eliminar(), mostrar(), ordenar(), perecedero(), peso(), precio();

int main(){
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Agregar articulos a la bodega.\n";
        cout << "2) Buscar articulos.\n";
        cout << "3) Eliminar articulos.\n";
        cout << "4) Mostrar todo lo que contenga la bodega.\n";
        cout << "5) Mostrar todo lo que contenga la bodega y sea perecedero.\n";
        cout << "6) Mostrar todo lo que contenga la bodega y pese mas de 300 gramos.\n";
        cout << "7) Mostrar todo lo que contenga la bodega y tenga un precio mayor de $50.\n";
        cout << "8) Ordenar.\n";
        cout << "9) Salir.\n";
        cout << "Opcion: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: agregar(); break;
            case 2: buscar(); break;
            case 3: eliminar(); break;
            case 4: mostrar(); break;
            case 5: perecedero(); break;
            case 6: peso(); break;
            case 7: precio(); break;
            case 8: ordenar(); break;
            case 9: continuar = false; break;
            default: cout << "Opcion no valida.\n"; break;
        }
    }while(continuar);

    return 0;
}

void agregar(){
    Articulo unArticulo;
    int perecedero=0;
    cout << "Nombre: "; getline(cin, unArticulo.nombre);
    cout << "Peso: "; cin >> unArticulo.peso; cin.ignore();
    cout << "Precio: "; cin >> unArticulo.precio; cin.ignore();
    preguntar:
    cout << "Es un articulo perecedero? (1-SI || 0-NO): "; cin >> perecedero;
    if(perecedero < 0 || perecedero > 1){
    	cout<<"Opcion incorrecta, ingrese nuevamente!"<<endl;
    	goto preguntar;
	}else{
		if(perecedero == 1){
			unArticulo.perecedero = true;
		}else{
			unArticulo.perecedero = false;
		}
	}
    bodega.insert(bodega.end(), unArticulo);
    cout << "Articulo ingresado exitosamente!\n";
}
void buscar(){
    string unNombre;
    cout << "Nombre del articulo que buscar: ";
    getline(cin, unNombre);
    
    bool encontrado = false;
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].nombre == unNombre){
            encontrado = true;
            break;
        }
    }
    
    if(encontrado)
        cout << "Articulo si se encuentra en la bodega.\n";
    else
        cout << "Articulo no se encuentra en la bodega.\n";
}
void eliminar(){
    string unNombre;
    cout << "Nombre del articulo que buscar: ";
    getline(cin, unNombre);
    
    for(vector<Articulo>::iterator iter = bodega.begin(); iter != bodega.end(); ++iter){
        if(iter->nombre == unNombre){
            iter = bodega.erase(iter);
            cout << "Articulo eliminado exitosamente.\n";
            break;
        }
    }
}

void precio(){
	cout<<endl;
	int contador=0;
	int tam=bodega.size();
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].precio > 50){
        	cout <<"-"<< bodega[i].nombre << " pesa " << bodega[i].peso;
        	cout << " gramos y vale $" << bodega[i].precio << "\n";
        	cout<<"Y posee la caracteristica ";
        	if(bodega[i].perecedero == true){
        		cout<<"de ser perecedero"<<endl;
			}else{
				cout<<"de no ser perecedero"<<endl;
			}
		}else{
			contador++;
		}
    }
    if(contador==tam){
    	cout<<"Actualmente no hay ningun articulo en bodega que tenga un precio mayor de $50"<<endl;
		}
}

void peso(){
	cout<<endl;
	int contador=0;
	int tam=bodega.size();
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].peso > 300){
        	cout <<"-"<<bodega[i].nombre << " pesa " << bodega[i].peso;
        	cout << " gramos y vale $" << bodega[i].precio << "\n";
        	cout<<" Y posee la caracteristica ";
        	if(bodega[i].perecedero == true){
        		cout<<"de ser perecedero"<<endl;
			}else{
				cout<<"de no ser perecedero"<<endl;
			}
		}else{
			contador++;
		}
    }
    if(contador==tam){
    	cout<<"Actualmente no hay ningun articulo en bodega que pese mas de 300 gramos"<<endl;
	}
}

void perecedero(){
	cout<<endl;
	int contador=0;
	int tam=bodega.size();
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].perecedero == true){
        	cout <<"-"<<bodega[i].nombre << " pesa " << bodega[i].peso;
        	cout << " gramos y vale $" << bodega[i].precio << "\n";	
		}else{
			contador++;
		}
    }
    if(contador==tam){
    	cout<<" Actualmente no hay ningun articulo en bodega que sea perecedero"<<endl;
	}
}

void mostrar(){
	cout<<endl;
    for (int i = 0; i < bodega.size(); i++) {
        cout <<"-"<<bodega[i].nombre << " pesa " << bodega[i].peso;
        cout << "  gramos y vale $" << bodega[i].precio << "\n";
        cout<<"Y posee la caracteristica ";
        if(bodega[i].perecedero == true){
        	cout<<"de ser perecedero"<<endl;
		}else{
			cout<<"de no ser perecedero"<<endl;
		}
    }
}
void ordenar(){
    int opcion = 0;
    cout << "Criterio de ordenamiento:\n";
    cout << "1) Alfabetico\n";
    cout << "2) Peso\n3)Precio\n";
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    
    if(opcion == 1)
        sort(bodega.begin(), bodega.end(), compNombre);
    else if(opcion == 2)
        sort(bodega.begin(), bodega.end(), compPeso);
    else if(opcion == 3)
        sort(bodega.begin(), bodega.end(), compPrecio);
        
    cout << "Bodega ordenada exitosamente\n";
}

