//
// Created by aybso on 15/12/2019.
//

#ifndef MUSIC___LISTADOBLE_H
#define MUSIC___LISTADOBLE_H

#include <iostream>
#include <fstream>
#include "Cuboortogonal.h"
#include <string>
#include "Listas/ListaTop/ListaTop.h"

class ListaDoble {
public:
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
        archivo.open("listaArtistas.txt",ios::out);

        archivo<<"digraph fila{"<<endl;
        archivo<<"	rankdir = LR;"<<endl;

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

        system("dot -Tpng listaArtistas.txt -o listaArtistas.png");
        system("listaArtistas.png");
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
                        nodo->siguiente = aux;
                        nodo->anterior = aux->anterior;
                        aux->anterior->siguiente = nodo;
                        aux->anterior = nodo;
                        tamano++;
                        break;
                    }
                    aux = aux->siguiente;
                }
            }
        }
    }

    void insertarartista(string valor, Cuboortogonal *cubo){
        if(!existeArtista(valor)) {
            insertarordenado(valor, cubo);
        }
    }

    bool existeArtista(string valor){
        if(cabeza != NULL){
            Nodo *aux = cabeza;
            while(aux != NULL){
                if(aux->valor == valor){
                    return true;
                }
                aux = aux->siguiente;
            }
        }
        return false;
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

    void graficarDiscografia(string artista){
        if(cabeza != NULL){
               Nodo * aux = cabeza;
               while(aux != NULL){
                   if(aux->valor.compare(artista) == 0){
                       aux->cubo->graficar();
                       break;
                   }
                   aux = aux->siguiente;
               }
        }else{
            cout << endl << "El artista no existe" << endl << endl;
        }
    }

    void graficarCanciones(string artista, string album, int anio, int mes){
        if(cabeza != NULL){
            Nodo * aux = cabeza;
            while(aux != NULL){
                if(aux->valor.compare(artista) == 0){
                    cout << "----->" << artista << " voy a graficar " << endl;
                    aux->cubo->graficarCanciones(artista, album, mes, anio);
                    break;
                }
                aux = aux->siguiente;
            }
        }else{
            cout << endl << "El artista no existe" << endl << endl;
        }
    }

    void graficarTopAlbumes(string artista){
        if(cabeza != NULL){
            Nodo * aux = cabeza;
            while(aux != NULL){
                if(aux->valor.compare(artista) == 0){
                    aux->cubo->graficarTopAlbumes(artista);
                    break;
                }
                aux = aux->siguiente;
            }
            if(aux == NULL){
                cout << endl << "El artista no existe" << endl << endl;
            }
        }else{
            cout << endl << "El artista no existe" << endl << endl;
        }
    }

    void graficarTopArtistas(){
        if(cabeza != NULL){
            Nodo * aux = cabeza;
            ListaTop* ltop = new ListaTop();

            while(aux != NULL){
                ltop->agregar(aux->cubo->valoracion, aux->valor);
                aux = aux->siguiente;
            }

            ltop->graficar("Artistas");
        }else{
            cout << endl << "El artista no existe" << endl << endl;
        }
    }

    void menuArtistas(){
        int opc = 1;
        if(cabeza != NULL){
            Nodo* aux = cabeza;
            cout << "----------------------------------------------" << endl;
            while(aux != NULL){
                cout << "   " << opc << ". " << aux->valor << endl;
                opc++;
                aux = aux->siguiente;
            }
            cout << "   Ingrese una opcion: " ;
        }
    }

    Nodo* getArtista(int index){
        int i = 1;
        if(cabeza != NULL ){
            Nodo* aux = cabeza;
            while(aux != NULL){
                if(index == i){
                    return aux;
                }
                i++;
                aux = aux->siguiente;
            }
        }
        return NULL;
    }

};


#endif //MUSIC___LISTADOBLE_H
