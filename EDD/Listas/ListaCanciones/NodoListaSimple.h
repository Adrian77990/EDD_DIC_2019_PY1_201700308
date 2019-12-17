//
// Created by aybso on 15/12/2019.
//

#ifndef MUSIC___NODOLISTASIMPLE_H
#define MUSIC___NODOLISTASIMPLE_H

#include <iostream>
#include <string>

using namespace std;

class NodoListaSimple {
public:
    string artista;
    string nombre;
    string archivo;
    string rating;
    NodoListaSimple* siguiente;

    NodoListaSimple(string nombre, string archivo, string rating){
        this->nombre = nombre;
        this->archivo = archivo;
        this->rating = rating;
        siguiente = NULL;
    }

    NodoListaSimple(string artista, string nombre, string archivo, string rating){
        this->artista = artista;
        this->nombre = nombre;
        this->archivo = archivo;
        this->rating = rating;
        siguiente = NULL;
    }
};


#endif //MUSIC___NODOLISTASIMPLE_H
