#include<iostream>
using namespace std;

void pedirDatos();
void mostrarMatriz(int **, int**, int, int);
void mostrarSumaMatriz(int **, int , int);
void sumarMatrices(int **, int **, int **);

int **punteroMatrizA, **punteroMatrizB, **punteroMatrizC, nFilas, nCol;

int main(){
	
	pedirDatos();
	
	for(int i=0; i<nFilas; i++){
		delete[] punteroMatrizA[i];
	}
	
	delete[] punteroMatrizA;
	
	for(int k=0; k<nFilas; k++){
		delete[] punteroMatrizB[k];
	}
	
	delete[] punteroMatrizB;
	
	return 0;
}

void pedirDatos(){
	
	cout << "Digite el numero de filas: ";
	cin >> nFilas;
	cout << "Digite el numero de columnas: ";
	cin >> nCol;
	
	if(nFilas == nCol){
    punteroMatrizA = new int*[nFilas];
	for(int i=0; i<nFilas; i++){
		punteroMatrizA[i] = new int[nCol];
	}
	
	cout << "\nDigitando los elementos de la matriz A: " << endl;
	for(int i=0; i<nFilas; i++){
		for(int j=0; j<nCol; j++){
			cout << "Digite un numero[" << i << "][" << j << "]: ";
			cin >> *(*(punteroMatrizA+i)+j);
		}
	}
	

	cout << "\nDigite el numero de filas: ";
	cin >> nFilas;
	cout << "Digite el numero de columnas: ";
	cin >> nCol;
	
	if(nFilas == nCol){	
	punteroMatrizB = new int*[nFilas];
	for(int k=0; k<nFilas; k++){
		punteroMatrizB[k] = new int[nCol];
	}
	
	cout << "\nDigitando los elementos de la matriz B: " << endl;
	for(int k=0; k<nFilas; k++){
		for(int l=0; l<nCol; l++){
			cout << "Digite un numero[" << k << "][" << l << "]: ";
			cin >> *(*(punteroMatrizB+k)+l);
		}
    }
    
    punteroMatrizC = new int*[nFilas];
	for(int k=0; k<nFilas; k++){
		punteroMatrizC[k] = new int[nCol];
	}
    
	 mostrarMatriz(punteroMatrizA, punteroMatrizB, nFilas, nCol);
  }else{
  	cout << "\nERROR SOLO SE PUEDEN SUMAR MATRICES CUADRADAS!";
  }
   }else{
  	cout << "\nERROR SOLO SE PUEDEN SUMAR MATRICES CUADRADAS!";
    }
    
    sumarMatrices(punteroMatrizA, punteroMatrizB , punteroMatrizC);
    mostrarSumaMatriz(punteroMatrizC, nFilas, nCol);
    
 }


void mostrarMatriz(int **punteroMatrizA, int **punteroMatrizB, int nFilas, int nCol){
	cout << "\n\nImprimiendo la matriz A:\n";
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout << *(*(punteroMatrizA+i)+j) << " ";
		}
		cout << "\n";
	}
	
    cout << "\n\nImprimiendo la matriz B:\n";
	for(int k=0;k<nFilas;k++){
		for(int l=0;l<nCol;l++){
			cout << *(*(punteroMatrizB+k)+l) << " ";
		}
		cout << "\n";
	}
}

void sumarMatrices(int **punteroMatrizA, int **punteroMatrizB , int **punteroMatrizC){
	for(int m=0;m<nFilas;m++){
		for(int n=0;n<nCol;n++){
			*(*(punteroMatrizC+m)+n)=*(*(punteroMatrizA+m)+n)+*(*(punteroMatrizB+m)+n);
		}
	}
}

void mostrarSumaMatriz(int **punteroMatrizC, int nFilas, int nCol){
	cout << "\n\nImprimiendo la matriz resultante:\n";
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout << (*(*(punteroMatrizC+i)+j))<< " ";
		}
		cout << "\n";
	}
}
