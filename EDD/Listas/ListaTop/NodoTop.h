//
// Created by aybso on 16/12/2019.
//

#ifndef MUSIC___NODOTOP_H
#define MUSIC___NODOTOP_H

#include <iostream>
#include <string>

using namespace std;

class NodoTop{

public:
    double valoracion;
    string dato;
    NodoTop* siguiente, *anterior;

    NodoTop(double valoracion, string dato){
        this->valoracion = valoracion;
        this->dato = dato;
        siguiente = anterior = NULL;
    }



};

#endif //MUSIC___NODOTOP_H
