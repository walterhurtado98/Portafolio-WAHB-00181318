#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct caja{
    string color;
    string material;
    string tipo;
};
typedef struct caja Caja;

int main(){
  
    stack<Caja> pilaDeCajas;
    
   
    bool continuar = true;
    do{
        char opcion = 's';
        cout << "\nCantidad de cajas actual: " << pilaDeCajas.size();
        cout << "\nDesea apilar otra caja? (s/n): ";
        cin >> opcion; cin.ignore();
        
        if(opcion == 's'){
            Caja unaCaja;
            cout << "Color: ";   getline(cin, unaCaja.color);
            cout << "Material: ";   getline(cin, unaCaja.material);
            cout << "Tipo: ";       getline(cin, unaCaja.tipo);
            pilaDeCajas.push(unaCaja); 
        }
        else if(opcion == 'n')
            continuar = false;
        else
            cout << "Opcion no valida!" << endl;
    }while(continuar);
    
   
    cout << "\nDesapilando cajas..." << endl;
    while(!pilaDeCajas.empty()){
        
        Caja cajaDeArriba = pilaDeCajas.top();
        cout << "Plato [" << cajaDeArriba.color;
        cout << ", " << cajaDeArriba.material;
        cout << ", " << cajaDeArriba.tipo << "]\n";
        
        pilaDeCajas.pop();
    }
    cout << "Pila de cajas vacia." << endl;

    return 0;
}

