#include "funciones.cpp"
#include <iostream>

using namespace std;

int main(){
	lista *p;
	p = mete_datos();

	ordena_seleccion(p);
	
	muestra_datos(p);
}
