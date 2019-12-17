//
// Created by aybso on 15/12/2019.
//

#ifndef MUSIC___NODOPALABRAS_H
#define MUSIC___NODOPALABRAS_H

#include <iostream>
#include <string>

using namespace std;

class NodoPalabras{

public:
    string palabra;
    NodoPalabras* siguiente;

    NodoPalabras(string palabra){
        this->palabra = palabra;
        siguiente = NULL;
    }
};

#endif //MUSIC___NODOPALABRAS_H
