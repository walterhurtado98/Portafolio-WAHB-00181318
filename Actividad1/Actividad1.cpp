#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;

void desplegar(int elementos, int numeros[]){
	cout<< "\nLos numeros dentro de la lista son:\n";
	   for(int i=0; i<elementos; i++){
	   	    cout<<" "<<numeros[i];
	   }
	cout<<endl;
}

    float mediana(int elementos, int numeros[]){
    	 int pos=elementos/2;
    	 float medi=0.0;
    	     if(elementos%2==0){
    	     	   medi= (float)(numeros[pos-1]+numeros[pos])/2.0;
			 }
			 else{
			 	medi=numeros[pos];
			 }
			 return medi;
    	}
    	
    	int main(){
    		
    		//int elementos=8;
    		int elementos, total=0;
    		int numeros[elementos];
    		cout<<"Ingrese la cantidad de elementos: "; cin>> elementos;
    		
    		cout<<"Ingrese los numeros de manera ascendente\n\n";
    		for(int i=0; i<elementos; i++){
    			cout<<i+1<<") Digite un numero: ";cin>>numeros[i];
    			total+=numeros[i];
			}
    		  desplegar(elementos,numeros);
    		  cout<< "\nEl valor de la mediana es: "<<mediana(elementos,numeros)<<endl;
    		  
    		  system("pause");
    		  return 0;
    		}
