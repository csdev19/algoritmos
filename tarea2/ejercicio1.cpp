#include<iostream>
using namespace std;

void ingresarNotas();
void eliminarMenor();
void promedio();
int *nota;

int main(){

	
	ingresarNotas();
	eliminarMenor();
	promedio();
	delete[] nota;
	return 0;
}
void ingresarNotas(){
	cout<<" calificaciones del alumno"<<endl<<endl;
	nota = new int[6];
	for(int i=0;i<6;i++){
		cout<<"ingrese la calificaciones numero "<<i+1<<"  del alumno : ";
		cin>>nota[i];
	}
}

void eliminarMenor(){
	int save=0 , menor=999 ;
	for(int i=0; i<6;i++){
		if( menor > nota[i] ){
			menor = nota[i];
      		save = i;
		}
  }
  nota[save] = 0;
  cout << "la menor nota es: "<< menor;
}

void promedio() {
  float promedio=0, total=0;
  for (int i=0; i < 6; i++) {
    promedio += nota[i];
  }
  total = promedio / 5.0;
  cout << "y el promedio es: "<< total;
}