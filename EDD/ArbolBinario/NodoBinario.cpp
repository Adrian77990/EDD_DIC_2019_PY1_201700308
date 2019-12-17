//
// Created by aybso on 15/12/2019.
//

#include "NodoBinario.h"

NodoBinario::NodoBinario(string nombre, Lista* playlist) {
    this->nombre = nombre;
    this->playlist = playlist;
    izquierda = derecha = NULL;
}