//
// Created by aybso on 15/12/2019.
//

#ifndef MUSIC___ABB_H
#define MUSIC___ABB_H


#include "NodoBinario.h"
#include <iostream>

using namespace std;

class ABB {
public:
    NodoBinario* raiz;

    ABB();

    void agregar(string nombre);
    void imprimirEnOrden();
    void imprimirPreOrden();
    void imprimirPostOrden();



private:
    NodoBinario* agregar(NodoBinario* nodo, NodoBinario* data);
    void imprimirEnOrden(NodoBinario* nodo);
    void imprimirPreOrden(NodoBinario* nodo);
    void imprimirPostOrden(NodoBinario* nodo);
};



#endif //MUSIC___ABB_H
