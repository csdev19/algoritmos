#include<iostream>
using namespace std;

void ingresarNotas (int);
void validaroUniversal();
int *notas;


int main() {
	int maximo;
	cout << "ingrese el numero de notas (maximo 40)";
	cin >> maximo;
	ingresarNotas(maximo);
	validaroUniversal();

	return 0;
}


void ingresarNotas(int maximo) {
	cout<<"ingrese calificaciones del alumno:"<<endl;
	notas = new int[maximo];
	for(int i=0;i<maximo;i++){
		cout<<"ingrese la calificaciones numero "<<i+1<<"  del alumno : ";
		cin>>nota[i];
	}
}

void validadorUniversal() {
	float medida = sizeof(notas)/sizeof(*nota)
	int numZero = 0, numDos = 0, numAprob = 0, numDesaprob = 0;
	for (int i=0; i < medida; i++){
		if (notas[i] == 0) {
			numZero++;
		}

		if (notas[i] == 2) {
			numDos++;
		}

		if (notas[i] >= 13) {
			numAprob++;
		} else {
			numDesaprob++;
		}
	}
	cout << "El numero de Zeroses:" << numZero << endl;
	cout << "El numero de Dos es:" << numDos << endl;
	cout << "El numero de Aprobadoses:" << numAprob << endl;
	cout << "El numero de Desaprobados es:" << numDesaprob << endl;
}
