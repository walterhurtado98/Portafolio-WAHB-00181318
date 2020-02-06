#include <iostream>
using namespace std;

int functi(int n){
	if(n==0)
	  return(0);
	  return(n + functi(n-1));
}
int main(void){
	int numero;
	malo:
	cout<<"Ingrese el limite superior de la sumatoria (mayor que cero): ";
	cin>>numero;
	if(numero<=0){
		goto malo;
	}
	cout<<"\nLa suma es: "<< functi(numero);
	return 0;
}
