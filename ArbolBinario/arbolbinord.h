#ifndef ARBOLBINORD_H     
#define ARBOLBINORD_H 
#include "estructura.h"
#include "cola.h"
#include <stack>

class arbolbinord {nodo *raiz;
  	cola *listInorden, *listPreorden,*listPosorden;
	public: 	arbolbinord(){raiz=NULL;
		listInorden=new cola;
		listPreorden= new cola; 
		listPosorden= new cola;} 
		void insertar(int dato);
		nodo *buscarpadre(int dato, nodo *p);
		void eliminar(int dato);
		nodo * buscar_nodo (int dato, nodo **padre);
		void inorden(nodo *inicio);
		void  preorden(nodo *inicio);
		void posorden(nodo *inicio);
};


void arbolbinord::insertar(int i){
	nodo *nuevo, *padre;
	padre = raiz;
    nuevo= new nodo;
    nuevo->clave=i;
    nuevo->izq= NULL;
    nuevo->der=NULL;
    if (raiz==NULL)
         {raiz=nuevo;}
	bool aux =true;
	
	while(aux){
			
	if(nuevo->clave > padre->clave && aux == true){
		if(padre->der=NULL){
			padre->der= nuevo;
			aux = false;
		}else{
			padre = padre->der;
		}
	}
	
	if(nuevo->clave < padre->clave && aux == true){
		if(padre->izq=NULL){
			padre->izq= nuevo;
			aux = false;
		}else{
			padre = padre->izq;
		}
	}
	}	

}
	
void arbolbinord::preorden(nodo* inicio) { 
    if (inicio == NULL) 
       return; 
  
    stack<nodo *> nodoPila; 
    nodoPila.push(inicio);
	cout<< nodoPila.top();
  

    while (nodoPila.empty() == false) //Si el nodo está vacío
    { 

        nodo *aux = nodoPila.top(); //Apunta al tope de la pila
        printf ("%d ", aux->clave); 
        nodoPila.pop(); //Saca el nodo de la pila
  

        if (aux->der) 
            nodoPila.push(aux->der); 
        if (aux->izq) 
            nodoPila.push(aux->izq); 
    } 
} 
	
void arbolbinord::inorden(nodo *inicio) { 
    stack<nodo *> s; 
    nodo *actual = inicio; 
  
    while (actual != NULL || s.empty() == false) { 

        while (actual !=  NULL) { 
            s.push(actual); 
            actual = actual->izq; 
        } 
        actual = s.top(); 
        s.pop(); 
        cout << actual->clave << " "; 
        actual = actual->der; 
  
    }
}
	


#endif
