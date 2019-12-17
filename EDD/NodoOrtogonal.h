//
// Created by aybso on 15/12/2019.
//

#ifndef MUSIC___NODOORTOGONAL_H
#define MUSIC___NODOORTOGONAL_H

using namespace std;
#include <string>
#include "Listas/ListaCanciones/ListaSimple.h"

class Nodo{
public:
    Nodo *siguientex;
    Nodo *siguientey;
    Nodo *siguientez;
    Nodo *atrasx;
    Nodo *atrasy;
    Nodo *atrasz;

    string nombre;
    int mes;
    int ano;
    ListaSimple *canciones;

    Nodo(string nombre,int mes,int ano, ListaSimple* canciones){
        this->nombre = nombre;
        this->mes = mes;
        this->ano=ano;
        this->canciones = canciones;
        siguientex =siguientey=siguientez=atrasx=atrasy=atrasz = NULL;
    }
};

#endif //MUSIC___NODOORTOGONAL_H
