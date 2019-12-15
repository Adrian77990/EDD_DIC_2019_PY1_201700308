//
// Created by aybso on 15/12/2019.
//

#ifndef MUSIC___NODOBINARIO_H
#define MUSIC___NODOBINARIO_H


#include <iostream>
#include <string>

using namespace std;

class NodoBinario {

public:
    string nombre;
    NodoBinario* izquierda, *derecha;

    NodoBinario(string nombre);

};

#endif //MUSIC___NODOBINARIO_H
