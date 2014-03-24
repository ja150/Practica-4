#ifndef FUNCIONES
#define FUNCIONES

struct lista{
	double numero;
	lista *next;
};

lista *mete_datos();
void muestra_datos(lista *p);
int numero_celdas(lista *p);
double medial(lista *p);
double var(lista *p);
bool ordenada(lista *p);
void comprueba_ordenada(lista *p);
void ordena_seleccion(lista *p);
void inserta_dato(lista *p);
lista *borrar_dato(lista *p);

#endif
