//
// Created by aybso on 15/12/2019.
//

#ifndef MUSIC___NODOBINARIO_H
#define MUSIC___NODOBINARIO_H


#include <iostream>
#include <string>
#include "../Listas/Pila_Cola_Circular/Lista.h"

using namespace std;

class NodoBinario {

public:
    string nombre;
    Lista * playlist;
    NodoBinario* izquierda, *derecha;

    NodoBinario(string nombre, Lista* playlist);

};

#endif //MUSIC___NODOBINARIO_H
