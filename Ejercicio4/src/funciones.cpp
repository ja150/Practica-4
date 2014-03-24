#include "funciones.h"
#include <iostream>

using namespace std;

//Función que introduce datos a nuestra lista enlazada. 
//Recibe un numero. Si el numero es mayor o igual a 0, crea una lista, le asigna al campo número el valor del número y colocamos a next un 0, ya que sera nuestro último valor ahora mismo y le indico que la variable end apunte a donde está apuntando p.Si el número anteriormente introducido es mayor o igual a 0, puedo volver a introducir números mientras sean mayor o iguales a 0, creo otra lista y vuelvo a asignarle los datos.

lista *mete_datos(){
	lista *p, *end, *aux;
	double numero;
	cout << "Introduce número (negativo para salir): " << endl;          
	cin >> numero;
	if(numero >= 0){                                                      
		p = new lista;		                                            
		p->numero = numero;
		p->next = 0;
		end = p;
		while(numero >= 0){                                              
			cout << "Introduce número (negativo para salir): " << endl; 
			cin >> numero;		
			if(numero >= 0){					
				end->next = new lista;
				end = end->next;
				end->numero = numero;
				end->next = 0;
			}
		}
	}
	return p;
}

//Función que muestra los datos que tenemos en nuestra lista
//Coloco aux al principio y repito hasta que aux no apunte a nada, muestro el número e incremento aux.

void muestra_datos(lista *p){
	lista *aux;
	aux = p;                 								    
	cout << endl;
	while(aux != 0){
		cout << aux->numero << endl;
		aux = aux->next;	
	}
}

//Función que retorna cuantas celdas enlazadas hay
//Coloco aux al principio y repito hasta que aux no apunte a nada, aumento el contador y apunto con aux a la siguiente lista.

int numero_celdas(lista *p){
	lista *aux;
	int contador = 0;
	aux = p;                                                             
	while(aux != 0){
		contador++;
		aux = aux->next;
	}
	return contador;
}

//Función que retorna la media de los numeros almacenados
//Recojo cuantas celdas hay, coloco aux al principio y repito hasta que aux no apunte a nada, sumo los números que tengo en la lista y apunto con aux a la siguiente lista y devuelvo el total de números entre las celdas.

double medial(lista *p){
	lista *aux;
	int celdas = numero_celdas(p);
	double sumatoria = 0;                                                 
	aux = p;                                                             
	while(aux != 0){
		sumatoria = aux->numero + sumatoria;
		aux = aux->next;
	}	
	return (sumatoria/celdas);
}

//Función que retorna la varianza
//Apunto con aux a la primera posicion, recorro las listas que tengo, resto al numero que tengo la media y lo elevo al cuadrado y sumo los valores que tenia almacenados en sumatoria, aumento aux y retorno la variable sumatoria/celdas.

double var(lista *p){
	lista *aux;
	double celdas = numero_celdas(p);
	double media = medial(p);
	double sumatoria = 0, total = 0;	
	aux = p;                                                             
	while(aux != 0){										    
		sumatoria = (aux->numero - media) * (aux->numero - media) + sumatoria;
		aux = aux->next;
	}
	total = (1/celdas * sumatoria);
	return total;
	
}

//Función que devuelve true si la lista está ordenada o false si no lo está
//Apunto con end al principio de la lista y con aux a la siguiente lista, repito hasta que aux llegue al final. Si la posición segunda es menor que la posición primera devuelvo false ya que la lista no está ordenada, en caso de que no sea así por ahora, avanzo aux y end. Devuelvo true si no encontró desordenada la lista.

bool ordenada(lista *p){
	lista *end, *aux;
	aux = p;
	end = p;
	aux = aux->next;	                                                  
	while(aux != 0){                                                      
		if(aux->numero < end->numero){                                  
			return false;			
		}else{
			aux = aux->next;
			end = end->next;			
		}			
	}
	return true;	                                                      
}

//Función que comprueba si la lista esta ordenada

void comprueba_ordenada(lista *p){
	if(ordenada(p) == true){
		cout << "La lista está ordenada" << endl;
	}else{
		cout << "La lista no está ordenada" << endl;
	}
}

//Funcion que ordena por el método de selección la lista
//Inicializo end al principio de la lista y aux lo adelanto a la siguiente. Repito el bucle tantas veces como celdas tenga. Repito otro bucle hasta que aux no apunte a nada. Si la posición avanzada es menor que la primera posición, pongo comprueba a verdadero, guardo el valor menor en una variable (numaux) y apunto con otro puntero donde esta ese valor y vuelvo a avanzar aux y hago otro bucle por si hubiera otro valor menor al valor guardado en numaux. Vuelvo a repetir el bucle hasta que llegue al final, compruebo si hay uno menor y en caso de que no avanzo hasta el final. Compruebo si hubo un valor menor, en caso de que sea true guardo el valor de la primera posicion donde encontré el valor mínimo, guardo en la primera posicion el valor mínimo y pongo comprueba a false. Avanzo a ambos.

void ordena_seleccion(lista *p){
	lista *aux, *end, *pnumaux;
	int celdas = numero_celdas(p);	
	int i;
	double numaux = 0;
	bool comprueba = false;	
	end = p;                                                              
	aux = p;
	aux = aux->next;
	for(i=1; i<celdas; i++){	                                   
		while(aux != 0){                                            
			if(aux->numero <= end->numero){                     
				comprueba = true;                          
				numaux = aux->numero;                               
				pnumaux = aux;
				aux = aux->next;
				while(aux != 0){
					if(aux->numero <= numaux){
						numaux = aux->numero;
						pnumaux = aux;	
						aux = aux->next;				
					}else{
						aux = aux->next;
					}
				}					
			}else{
				aux = aux->next;		
			}
		}
		if(comprueba == true){                                     
			pnumaux->numero = end->numero;                    
			end->numero = numaux;
			comprueba = false;
		}	
		end = end->next;                                                 
		aux = end;
		aux = aux->next;			
	}
}
