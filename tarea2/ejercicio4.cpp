#include<iostream>
#include<string>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<locale.h>
using namespace std;

int codigo[100];
int cantidad[100];
float prcUnitario[100];
bool esNumero(string);
bool esFlotante(string);
bool comprobacion(int ,string);
void ingresandoVenta();
void calculador();
int maximo=-1;
int main(){
	setlocale(LC_ALL,"");
	
	string opci;
	do{
		
		maximo++;
		cout<<"\nVenta numero "<<(maximo+1)<<endl;
		if(maximo==100){
			break;
		}else{
			ingresandoVenta();
		}
		cout<<"\nDesea continuar ";
		cout<<"\n1.Si \n2.No";
		
		cout<<"\nOpción : ";
		cin>>opci;
		if(opci[0]=='N' || opci[0]=='n' || opci[0]=='2'){
			break;
		}
		system("cls");
	}while(true);
	system("cls");
	calculador();
//	cout<<prcUnitario[0]<<" "<<cantidad[0]<<" "<<codigo[0];
}

bool esNumero(string cadena){
	int size=cadena.size();
	
		if(size==0){
			cout<<"\nIncorrecto ";
			return false;
		}else if(size==1 && !isdigit(cadena[0])){
			cout<<"\nIncorrecto ";
			return false;
		}else{
			for(int i=0;i<size;i++){
				if(!isdigit(cadena[i])){
					cout<<"\nIncorrecto ";
					return false;
				}
			}
		}
		return true;
}

bool esFlotante(string cadena){
	int size=cadena.size();
	int puntos=0;
	int postPunto=0;
	if(size==0){
		cout<<"\nIncorrecto";
		return false;
	}else{
		for(int i=0;i<size;i++){
			if(cadena[i]=='.'){
				postPunto=i;
				puntos++;
			}
			if(puntos>1){
				cout<<"\nIncorrecto ";
				return false;
			}
		}
		
		for(int i=0;i<size;i++){
			if(i==postPunto && i!=0){
				i++;
			}
			if(!isdigit(cadena[i])){
				cout<<"\nIncorrecto";
				return false;
			}
		}
		return true;
	}
}

bool comprobacion(int id,string cadena){
	int size=cadena.size();
	switch(id){
		case 1 : 
			
			if(size!=4){
				cout<<"\nIncorrecto";
				return false;
			}
			break;
		case 2:
			if(atoi(cadena.c_str())<=0){
				cout<<"\nIncorrecto";
				return false;
			}
			break;
		case 3:
			if(atof(cadena.c_str())<=0){
				cout<<"\nIncorrecto";
				return false;
			}
	}
	return true;
}
void ingresandoVenta(){
	string codigoCadena;
	string cantidades;
	string precio;
	do{
		cout<<"\nIngrese el código del producto  : ";
		cin>>codigoCadena;
		if(comprobacion(1,codigoCadena) && esNumero(codigoCadena)){
			codigo[maximo]=atoi(codigoCadena.c_str());
			break;
		}
	}while(true);
	do{
		cout<<"\nIngrese la cantidad  : ";
		cin>>cantidades;
		if(comprobacion(2,cantidades) && esNumero(cantidades)){
			cantidad[maximo]=atoi(cantidades.c_str());
			break;
		}
	}while(true);
	do{
		cout<<"\nIngrese el Precio Unitario : ";
		cin>>precio;
		if(comprobacion(3,precio) && esFlotante(precio)){
			prcUnitario[maximo]=atof(precio.c_str());
			break;
		}
	}while(true);
}
void calculador(){
	double suma=0;
	double ingreso=0;
	double mayor=prcUnitario[0]*cantidad[0];
	int codigoMayor=codigo[0];
	double caro=prcUnitario[0];
	int codigoCaro=codigo[0];
	for(int i=0;i<=maximo;i++){
		ingreso=prcUnitario[i]*cantidad[i];
		suma+=(ingreso);
		if(mayor<ingreso){
			mayor=ingreso;
			codigoMayor=codigo[i];
		}
		if(caro<prcUnitario[i]){
			caro=prcUnitario[i];
			codigoCaro=codigo[i];
		}
	}
	
	cout<<"\nTotal de soles vendidos : "<<suma;
	cout<<"\nProducto que produjo myor ingreso : "<<codigoMayor;
	cout<<"\nEL producto mas caro : "<<codigoCaro;
}

