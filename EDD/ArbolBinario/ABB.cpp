//
// Created by aybso on 15/12/2019.
//

#include "ABB.h"

ABB::ABB() {
    this->raiz = NULL;
}

NodoBinario* ABB::agregar(NodoBinario *nodo, NodoBinario *data) {
    if (nodo == NULL){
        return data;
    }

    if(data->nombre.compare(nodo->nombre) < 0){
        nodo->izquierda = agregar(nodo->izquierda, data);
    }else if(data->nombre.compare(nodo->nombre) > 0){
        nodo->derecha = agregar(nodo->derecha, data);
    }else{
        cout << endl << "No se puede agregar " << data->nombre << " porque ya existe" << endl << endl;
    }

    return nodo;

}

void ABB::imprimirEnOrden(NodoBinario *nodo) {
    if(nodo != NULL){
        imprimirEnOrden(nodo->izquierda);
        cout << nodo->nombre << endl;
        imprimirEnOrden(nodo->derecha);
    }
}

void ABB::imprimirPreOrden(NodoBinario *nodo) {
    if(nodo != NULL){
        cout << nodo->nombre << endl;
        imprimirPreOrden(nodo->izquierda);
        imprimirPreOrden(nodo->derecha);
    }
}

void ABB::imprimirPostOrden(NodoBinario *nodo) {
    if(nodo != NULL){
        imprimirPostOrden(nodo->izquierda);
        imprimirPostOrden(nodo->derecha);
        cout << nodo->nombre << endl;
    }
}

void ABB::agregar(string nombre) {
    raiz = agregar(raiz, new NodoBinario(nombre));
}

void ABB::imprimirEnOrden() {
    imprimirEnOrden(raiz);
}

void ABB::imprimirPreOrden() {
    imprimirPreOrden(raiz);
}

void ABB::imprimirPostOrden() {
    imprimirPostOrden(raiz);
}
