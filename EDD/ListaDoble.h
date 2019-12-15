//
// Created by aybso on 15/12/2019.
//

#ifndef MUSIC___LISTADOBLE_H
#define MUSIC___LISTADOBLE_H

#include <iostream>
#include <fstream>
#include "Cuboortogonal.h"
#include <string>
class ListaDoble {
    class Nodo {
    public:
        Nodo *siguiente;
        Nodo *anterior;
        string valor;
        Cuboortogonal *cubo;


        Nodo(string valor,Cuboortogonal *cubo){
            siguiente = NULL;
            anterior = NULL;
            this->cubo = cubo;
            this->valor = valor;
        }


    };
public:
    Nodo *cabeza = NULL;
    Nodo *cola = NULL;

    int tamano = 0;

    void insertar_inicio(string valor, Cuboortogonal *cubo)
    {
        Nodo *nodo = new Nodo(valor,cubo);
        if(tamano == 0){
            cabeza = cola = nodo;
            tamano++;
        }else{
            cabeza->anterior = nodo;
            nodo->siguiente = cabeza;
            cabeza = nodo;
            tamano++;
        }
    }
    void insertar_final(string valor, Cuboortogonal *cubo)
    {
        Nodo *nodo = new Nodo(valor,cubo);
        if(tamano == 0){
            cabeza = cola = nodo;
            tamano++;
        }else{
            cola->siguiente = nodo;
            nodo->anterior = cola;
            cola = nodo;
            tamano++;
        }
    }

    void replaceChars(string& modifyMe,const string& findMe, const string& newChars){
        size_t i = modifyMe.find(findMe, 0);
        if(i != string::npos)
            modifyMe.replace(i, findMe.size(), newChars);
    }

    void grafoy()
    {
        ofstream archivo;
        archivo.open("grafo.txt",ios::out);

        archivo<<"digraph fila{"<<endl;
        archivo<<"	"<<endl;

        archivo<<"	node[shape=record];"<<endl;
        archivo<<"	graph[ranksep=\"2\"];"<<endl;


        Nodo *temp = this->cabeza;
        int contador =0;
        while(temp!=0){
            archivo<<"nodo_"<<contador<<"[label= \"  " << temp->valor << + " \" ];\n";
            if(temp->siguiente != NULL && contador<tamano-1){
                archivo<<"nodo_"<<contador<<"->"<<"nodo_"<<contador+1<<";\n";
                archivo<<"nodo_"<<contador+1<<"->"<<"nodo_"<<contador<<";\n";
            }
            temp = temp->siguiente;
            contador++;
        }

        archivo<<endl;
        archivo<<endl;
        archivo<<"}"<<endl;
        archivo.close();

        system("dot -Tpng grafo.txt -o grafo.png");
    }

    void insertarordenado(string valor,Cuboortogonal *cubo){
        Nodo *nodo = new Nodo(valor,cubo);
        if(tamano ==0)
        {
            insertar_inicio(valor, cubo);
        }else{
            if(nodo->valor.compare(cabeza->valor)<0){
                // cout << nodo->valor << "es menor que " << cabeza->valor << endl;
                insertar_inicio(valor, cubo);
            }
            else if (nodo->valor.compare(cola->valor)>0){
                // cout << nodo->valor << "es menor que " << cabeza->valor << endl;
                insertar_final(valor,cubo);
            }
            else{
                Nodo *aux = cabeza;
                while(aux!=NULL){
                    if(nodo->valor.compare(aux->valor)<0){
                        //cout << nodo->valor << "es menor que " << aux->valor << " //////" << endl;
                        tamano++;
                        break;
                    }
                    aux = aux->siguiente;
                }
                nodo->siguiente = aux;
                nodo->anterior = aux->anterior;
                aux->anterior->siguiente = nodo;
                aux->anterior = nodo;

            }
        }
    }

    void insertarartista(string valor, Cuboortogonal *cubo){
        insertarordenado(valor, cubo);
    }

    void imprimiralbums()
    {
        Nodo *temp = cabeza;
        while(temp!=0){
            cout<<temp->valor<<endl;
            temp->cubo->imprimirporfilas();
            cout<<endl<<endl<<endl;
            //cout<<temp->valor<< endl;
            temp = temp->siguiente;
        }
    }


    void imprimir()
    {
        Nodo *temp = cabeza;
        while(temp!=0){
            cout<<temp->valor<< endl;
            temp = temp->siguiente;
        }
    }
};


#endif //MUSIC___LISTADOBLE_H
