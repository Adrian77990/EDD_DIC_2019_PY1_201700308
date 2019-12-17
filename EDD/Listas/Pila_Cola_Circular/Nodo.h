//
// Created by aybso on 15/12/2019.
//

#ifndef MUSIC___NODO_H
#define MUSIC___NODO_H

#include <iostream>
#include <string>

using namespace std;


class NodoL{

public:
    string artista, cancion, album, mes, anio;
    NodoL* siguiente, *anterior;

    NodoL(string artista, string cancion, string album, string mes, string anio){
        this->artista = artista;
        this->cancion = cancion;
        this->album = album;
        this->mes = mes;
        this->anio = anio;
        siguiente = anterior = NULL;
    }

};


#endif //MUSIC___NODO_H
