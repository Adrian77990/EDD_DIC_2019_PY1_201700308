//
// Created by aybso on 15/12/2019.
//

#ifndef MUSIC___LISTAPALABRAS_H
#define MUSIC___LISTAPALABRAS_H

#include <iostream>
#include <string>
#include "NodoPalabras.h"

class ListaPalabras{

public:
    NodoPalabras *cabeza;
    NodoPalabras *cola;
    int size;

    ListaPalabras(){
        cabeza = cola = NULL;
        size = 0;
    }

    void agregar(string palabra){
        if(cabeza == NULL){
            cabeza = cola = new NodoPalabras(palabra);
            size++;
        }else{
            if(!existePalabra(palabra)) {
                NodoPalabras *nodo = new NodoPalabras(palabra);
                cola->siguiente = nodo;
                cola = nodo;
                size++;
            }
        }
    }

    string getPalabra(int index){
        if(size >= 0){
            int aux = 0;
            NodoPalabras* nodoaux = cabeza;

            while(nodoaux != NULL){
                if(aux == index){
                    return nodoaux->palabra;
                }
                aux++;
                nodoaux = nodoaux->siguiente;
            }
        }
        return " ";
    }

    bool existePalabra(string palabra){
        if(cabeza != NULL){
            NodoPalabras *aux = cabeza;
            while(aux != NULL){
                if(aux->palabra == palabra){
                    return true;
                }
                aux = aux->siguiente;
            }
        }
        return false;
    }

    void imprimir(){
        NodoPalabras *aux = cabeza;
        while(aux != NULL){
            cout << "[ " << aux->palabra << "] ------> ";
            aux = aux->siguiente;
        }
        cout << endl << endl;
    }



};


#endif //MUSIC___LISTAPALABRAS_H
