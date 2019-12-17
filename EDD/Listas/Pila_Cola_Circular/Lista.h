//
// Created by aybso on 15/12/2019.
//

#ifndef MUSIC___LISTA_H
#define MUSIC___LISTA_H

#include <iostream>
#include <string>
#include "Nodo.h"

using namespace std;

class Lista {

public:
    NodoL* cabeza, *cola;
    bool stack, queue, circular, shuffle;
    int tipo = 1;
    int size;

    Lista(string estructura){
        cabeza = cola = NULL;
        stack = queue = circular = false;

        if(estructura == "stack"){
            stack = true;
        }

        if(estructura == "queue"){
            queue = true;
        }

        if(estructura == "shuffle"){
            shuffle = true;
        }

        if(estructura == "circular"){
            circular = true;
        }

        size = 0;
    }

    void agregar(string artista, string cancion, string album, string mes, string anio){
        if(stack){
            agregarPila(artista, cancion, album, mes, anio);
        }

        if(queue){
            agregarCola(artista, cancion, album, mes, anio);
        }

        if(shuffle){
            agregarShuffle(artista, cancion, album, mes, anio);
        }
    }

    void imprimir(){
        if(cabeza != NULL){
            int cont = 0;
            NodoL* aux = cabeza;
            while(cont < size){
                cout << "ALBUM -> " << aux->album << " ------- CANCION ->  " << aux->cancion << " -------- ARTISTA -> " << aux->artista << endl;
                cont++;
                aux = aux->siguiente;
            }
        }
    }

private:

    void agregarPila(string artista, string cancion, string album, string mes, string anio){
        if(cabeza == NULL){
            cabeza = cola =  new NodoL(artista, cancion, album, mes, anio);
            size++;
        }else{
            NodoL* nuevo = new NodoL(artista, cancion, album, mes, anio);
            nuevo->siguiente = cabeza;
            cabeza = nuevo;
            size++;
        }
    }

    void agregarCola(string artista, string cancion, string album, string mes, string anio){
        if(cabeza == NULL){
            cabeza = cola =  new NodoL(artista, cancion, album, mes, anio);
            size++;
        }else{
            NodoL* nuevo = new NodoL(artista, cancion, album, mes, anio);
            cola->siguiente = nuevo;
            cola = nuevo;
            size++;
        }
    }

    void agregarShuffle(string artista, string cancion, string album, string mes, string anio){
        if(cabeza == NULL){
            cabeza = cola =  new NodoL(artista, cancion, album, mes, anio);
            size++;
        }else{
            NodoL* nuevo = new NodoL(artista, cancion, album, mes, anio);

            if(tipo == 1){
                cola->siguiente = nuevo;
                nuevo->anterior = cola;
                cola = nuevo;
                tipo = 2;
                size++;
            }else{
                nuevo->siguiente = cabeza;
                cabeza->anterior = nuevo;
                cabeza = nuevo;
                tipo = 1;
                size++;
            }

        }
    }

    void agregarCircular(string artista, string cancion, string album, string mes, string anio){
        if(cabeza == NULL){
            cabeza = cola =  new NodoL(artista, cancion, album, mes, anio);
            size++;
        }else{
            NodoL* nuevo = new NodoL(artista, cancion, album, mes, anio);
            cola->siguiente = nuevo;
            nuevo->anterior = cola;
            cola = nuevo;
            cola->siguiente = cabeza;
            cabeza->anterior = cola;
            size++;
        }
    }



};


#endif //MUSIC___LISTA_H
