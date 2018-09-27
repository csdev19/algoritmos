#include<iostream>
using namespace std;

void ingresarNotas(int); 
void promedioNotas();
void moda();
void maxMin();
int *notas;

int main () {
	int maximo;
	cout << "ingrese el numero de notas (maximo 40)";
	cin >> maximo;
	ingresarNotas(maximo);
	promedioNotas();
	moda();
	maxMin();
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

void promedioNotas() {
	float medida = sizeof(notas)/sizeof(*nota);
	float sumatoria=0, promedio=0;
	for (int i=0; i < medida; i++) {
		sumatoria += notas[i]
	}
	promedio = sumatoria/ medida;
	cout << "el promedio es: "<< promedio<<endl;
}

void moda () {
	float medida = sizeof(notas)/sizeof(*nota);
	int copiaNotas[medida][2] = {0};
	int mayor[2]= {0,0};
	for (int i=0; i < medida; i++) {
		copiaNotas[i][0] = notas[i];																																													
	}

	for (int i=0; i < medida; i++) {
		for (int u=0; u< medida; u++) {
			if (notas[i] == copiaNotas[u][0]) {
				copiaNotas[u][1]++;
			}
		}
	}

	for (int i =0 ; i < medida; i++) {
		if (mayor[1] < copiaNotas[u][1]) {
			mayor[0] = copiaNotas[u][0];
			mayor[1] = copiaNotas[u][1];
		}
	}

	cout << "la moda es: " << mayor[0] << endl;
}

void maxMin() {
	int maximo=-999, minimo=999;
	float medida = sizeof(notas)/sizeof(*nota);
	for (int i=0; i < medida; i++) {
		if (maximo < notas[i]) {
			maximo = notas[i];
		}
		if (minimo > notas[i]) {
			minimo = notas[i];
		}
	}
	cout << "el valor maximo es: " << maximo<< endl;
	cout << "el valor minimo es: " << minimo<< endl;
}