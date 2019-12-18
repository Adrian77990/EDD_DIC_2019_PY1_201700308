//
// Created by aybso on 15/12/2019.
//

#ifndef MUSIC___ABB_H
#define MUSIC___ABB_H


#include "NodoBinario.h"
#include "../Listas/Pila_Cola_Circular/Lista.h"
#include <iostream>

using namespace std;

class ABB {
public:
    NodoBinario* raiz;
    int size;

    ABB();

    void agregar(string nombre, Lista* lista);
    void imprimirEnOrden();
    void imprimirPreOrden();
    void imprimirPostOrden();

    void graficar();
    void menuPlaylist();
    void reproducirMusica(int index);




private:
    NodoBinario* agregar(NodoBinario* nodo, NodoBinario* data);
    void imprimirEnOrden(NodoBinario* nodo);
    void imprimirPreOrden(NodoBinario* nodo);
    void imprimirPostOrden(NodoBinario* nodo);
    void graficar(NodoBinario* nodo, string& s);
    void replaceChars(string& modifyMe,const string& findMe, const string& newChars);
    void menuEnOrden(NodoBinario* nodo, int& i);
    void reproducirMusica(NodoBinario* nodo, int& i, int index);

};



#endif //MUSIC___ABB_H
