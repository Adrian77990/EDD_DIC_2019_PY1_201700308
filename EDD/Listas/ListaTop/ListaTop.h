//
// Created by aybso on 16/12/2019.
//

#ifndef MUSIC___LISTATOP_H
#define MUSIC___LISTATOP_H

#include <iostream>
#include <string>
#include "NodoTop.h"

using namespace std;


class ListaTop{

public:
    NodoTop* cabeza, *cola;
    int size;

    ListaTop(){
        size = 0;
        cabeza = cola = NULL;
    }

    void agregar(double valoracion, string data){
        if(cabeza == NULL){
            cabeza = cola = new NodoTop(valoracion, data);
        }else{
            NodoTop* nuevo = new NodoTop(valoracion, data);
            if(valoracion <= cabeza->valoracion){
                nuevo->siguiente = cabeza;
                cabeza->anterior = nuevo;
                cabeza = nuevo;
            }else if(valoracion >= cola->valoracion){
                cola->siguiente = nuevo;
                nuevo->anterior = cola;
                cola = nuevo;
            }else{
                NodoTop* aux = cabeza->siguiente;
                NodoTop* ant = cabeza;
                while(aux != NULL){
                    if(valoracion <= aux->valoracion){
                        ant->siguiente = nuevo;
                        nuevo->anterior = ant;
                        nuevo->siguiente = aux;
                        aux->anterior = nuevo;
                        break;
                    }
                    ant = aux;
                    aux = aux->siguiente;
                }
            }
        }
    }

    void imprimir(){
        if(cabeza != NULL){
            NodoTop* aux = cabeza;
            while(aux != NULL){
                cout << aux->valoracion << " --- " << aux->dato << endl;
                aux = aux->siguiente;
            }
        }
    }

    void graficar(string descripcion){
        ofstream archivo;
        archivo.open("listaTopAlbumes.txt",ios::out);

        archivo << "digraph G{" << endl;
        archivo << "   rankdir = LR;" << endl;
        archivo << "   node[shape=record];" << endl;
        archivo << "   graph[ranksep = \"1\"];" << endl <<endl;

        NodoTop* aux = cola;
        int cont = 1;
        int cont5 = 0;
        while(aux != NULL){
            if(cont5 < 5){
                archivo << "   nodo_" << cont << "[label=\""<< aux->dato <<" \\n "<< aux->valoracion  << "\"];" << endl;

                if(aux->anterior != NULL && cont5 + 1 < 5){
                    archivo << "   nodo_" << cont << "->nodo_" << cont + 1 << endl;
                }
            }

            cont5++;
            cont++;
            aux = aux->anterior;
        }

        archivo << "   labelloc=\"t\";" << endl;
        archivo << "   label = \" Lista de Top 5 - "<< descripcion << "\";" << endl;
        archivo << "}" << endl;
        archivo.close();

        system("dot -Tpng listaTopAlbumes.txt -o listaTopAlbumes.png");
        system("listaTopAlbumes.png");
    }

};

#endif //MUSIC___LISTATOP_H
