//
// Created by aybso on 15/12/2019.
//

#ifndef MUSIC___LISTASIMPLE_H
#define MUSIC___LISTASIMPLE_H

#include <iostream>
#include <string>
#include "NodoListaSimple.h"

using namespace std;

class ListaSimple {
public:
    NodoListaSimple *cabeza;
    NodoListaSimple *cola;
    double valoracion;
    int size;

    ListaSimple(){
        cabeza = cola = NULL;
        size = 0;
        valoracion = 0;
    }

    void agregar(string nombre, string archivo, string rating){
            if(cabeza == NULL){
                cabeza = cola = new NodoListaSimple(nombre, archivo, rating);
                size++;
            }else{
                if(!existeCancion(nombre)) {
                    NodoListaSimple *nodo = new NodoListaSimple(nombre, archivo, rating);
                    cola->siguiente = nodo;
                    cola = nodo;
                    size++;
                }
            }
            valoracion = calcular_valoracion();
    }

    void agregar(string artista, string nombre, string archivo, string rating){
        if(cabeza == NULL){
            cabeza = cola = new NodoListaSimple(artista, nombre, archivo, rating);
            size++;
        }else{
            NodoListaSimple *nodo = new NodoListaSimple(artista, nombre, archivo, rating);
            if(nodo->nombre.compare(cabeza->nombre) <= 0){
                nodo->siguiente = cabeza;
                cabeza = nodo;
                size++;
            }else if(nodo->nombre.compare(cola->nombre) >= 0){
                cola->siguiente = nodo;
                cola = nodo;
                size++;
            }else{
                NodoListaSimple* aux = cabeza->siguiente;
                NodoListaSimple* ant = cabeza;
                while(aux != NULL){
                    if(nodo->nombre.compare(aux->nombre) <= 0){
                        ant->siguiente = nodo;
                        nodo->siguiente = aux;
                        size++;
                        break;
                    }
                    ant = aux;
                    aux = aux->siguiente;
                }
            }

        }
        valoracion = calcular_valoracion();
    }

    bool existeCancion(string nombre){
        if(cabeza != NULL){
            NodoListaSimple *aux = cabeza;
            while(aux != NULL){
                if(aux->nombre == nombre){
                    return true;
                }
                aux = aux->siguiente;
            }
        }
        return false;
    }

    void imprimir(){
        NodoListaSimple *aux = cabeza;
        while(aux != NULL){
            cout << "[ " << aux->nombre << " --- " << aux->rating << "] ------> ";
            aux = aux->siguiente;
        }
        cout << endl << endl;
    }

    void graficar(string artista){
        ofstream archivo;
        archivo.open("listaCanciones.txt",ios::out);

        archivo << "digraph G{" << endl;
        archivo << "   rankdir = LR;" << endl;
        archivo << "   node[shape=record];" << endl;
        archivo << "   graph[ranksep = \"1\"];" << endl <<endl;

        NodoListaSimple* aux = cabeza;
        int cont = 1;
        while(aux != NULL){
            archivo << "   nodo_" << cont << "[label=\""<< aux->nombre <<"\"];" << endl;

            if(aux->siguiente != NULL){
                archivo << "   nodo_" << cont << "->nodo_" << cont + 1 << endl;
            }

            cont++;
            aux = aux->siguiente;
        }

        archivo << "   labelloc=\"t\";" << endl;
        archivo << "   label = \" Lista de Canciones "<< artista << "\";" << endl;
        archivo << "}" << endl;
        archivo.close();

        system("dot -Tpng listaCanciones.txt -o listaCanciones.png");
        system("listaCanciones.png");
    }

    double calcular_valoracion(){
        if(size > 0){
            double suma = 0;
            NodoListaSimple *aux = cabeza;
            while(aux != NULL){
                suma += atoi(aux->rating.c_str());
                aux = aux->siguiente;
            }

            double res = suma / size;
            return res;
        }
        return 0;
    }

    void menuCanciones(){
        NodoListaSimple *aux = cabeza;
        int index = 1;
        cout << "----------------------------------------------" << endl;

        while(aux != NULL){
            cout << "   " << index << ". " << aux->nombre << endl;
            index++;
            aux = aux->siguiente;
        }

        cout << "   Ingrese una opcion: " ;
    }

    void menuTodasCanciones(){
        NodoListaSimple *aux = cabeza;
        int index = 1;
        cout << "----------------------------------------------" << endl;

        while(aux != NULL){
            cout << "   " << index << ". " << aux->nombre << " --- " << aux->artista << endl;
            index++;
            aux = aux->siguiente;
        }

        cout << "   Ingrese una opcion: " ;
    }

    NodoListaSimple* getCancion(int indice){
        NodoListaSimple *aux = cabeza;
        int index = 1;

        while(aux != NULL){
            if(index == indice){
                return aux;
            }
            index++;
            aux = aux->siguiente;
        }

        return NULL;
    }

    void reproducirCancion(int indice){
        ofstream archivo;
        archivo.open("reproducirCancion.txt",ios::out);

        archivo << "digraph G{" << endl;
        archivo << "   rankdir = LR;" << endl;
        archivo << "   node[shape=record];" << endl;
        archivo << "   graph[ranksep = \"1\"];" << endl <<endl;

        NodoListaSimple *aux = cabeza;
        int index = 1;

        while(aux != NULL){
            if(index == indice){
                archivo << "    nodo[label=\" [REPRODUCIENDO] "<< aux->archivo << " \\n[CANCION] "<< aux->nombre <<"\\n[RATING] "<< aux->rating <<" \"];"<< endl;
                cout << endl;
                cout << "[REPRODUCIENDO] " << aux->archivo <<endl;
                cout << "   [--->NOMBRE] " << aux->nombre << endl;
                cout << "   [--->RATING] " << aux->rating << endl << endl << endl;
            }
            index++;
            aux = aux->siguiente;
        }

        archivo << "}" << endl;
        archivo.close();
        system("neato -Tpng reproducirCancion.txt -o reproducirCancion.png");
        system("reproducirCancion.png");
        system("pause");
    }
};


#endif //MUSIC___LISTASIMPLE_H
