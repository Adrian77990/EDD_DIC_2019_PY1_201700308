//
// Created by aybso on 15/12/2019.
//

#ifndef MUSIC___NODOORTOGONAL_H
#define MUSIC___NODOORTOGONAL_H

using namespace std;
#include <string>

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

    Nodo(string nombre,int mes,int ano){
        this->nombre = nombre;
        this->mes = mes;
        this->ano=ano;
        siguientex =siguientey=siguientez=atrasx=atrasy=atrasz = NULL;
    }
};

#endif //MUSIC___NODOORTOGONAL_H
