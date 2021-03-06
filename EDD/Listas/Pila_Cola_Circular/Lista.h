//
// Created by aybso on 15/12/2019.
//

#ifndef MUSIC___LISTA_H
#define MUSIC___LISTA_H

#include <iostream>
#include <string>
#include "Nodo.h"
#include <fstream>
#include <unistd.h>

using namespace std;

class Lista {

public:
    NodoL* cabeza, *cola;
    bool stack, queue, circular, shuffle;
    int tipo = 1;
    int size;
    string tipoEstructura;

    Lista(string estructura){
        cabeza = cola = NULL;
        stack = queue = circular = shuffle = false;

        if(estructura == "stack"){
            stack = true;
        }

        if(estructura == "queue"){
            queue = true;
        }

        if(estructura == "shuffle"){
            shuffle = true;
        }

        if(estructura == "circular"){
            circular = true;
        }


        tipoEstructura = estructura;
        size = 0;
    }

    void agregar(string artista, string cancion, string album, string mes, string anio){
        if(stack){
            agregarPila(artista, cancion, album, mes, anio);
        }

        if(queue){
            agregarCola(artista, cancion, album, mes, anio);
        }

        if(shuffle){
            agregarShuffle(artista, cancion, album, mes, anio);
        }

        if(circular){
            agregarCircular(artista, cancion, album, mes, anio);
        }
    }

    void imprimir(){
        if(cabeza != NULL){
            int cont = 0;
            NodoL* aux = cabeza;
            while(cont < size){
                cout << "ALBUM -> " << aux->album << " ------- CANCION ->  " << aux->cancion << " -------- ARTISTA -> " << aux->artista << endl;
                cont++;
                aux = aux->siguiente;
            }

            if(shuffle){
                cout << "-- DE REGRESO <--" << endl;
                int contr = 0;
                NodoL* aux = cola;
                while(contr < size){
                    cout << "ALBUM -> " << aux->album << " ------- CANCION ->  " << aux->cancion << " -------- ARTISTA -> " << aux->artista << endl;
                    contr++;
                    aux = aux->anterior;
                }
            }

            if(circular){
                cout << "ALBUM -> " << aux->album << " ------- CANCION ->  " << aux->cancion << " -------- ARTISTA -> " << aux->artista << endl;

                cout << "-- DE REGRESO <--" << endl;
                int contr = 0;
                NodoL* aux = cola;
                while(contr < size){
                    cout << "ALBUM -> " << aux->album << " ------- CANCION ->  " << aux->cancion << " -------- ARTISTA -> " << aux->artista << endl;
                    contr++;
                    aux = aux->anterior;
                }

                cout << "ALBUM -> " << aux->album << " ------- CANCION ->  " << aux->cancion << " -------- ARTISTA -> " << aux->artista << endl;

            }

        }
    }

    NodoL* sacar(){
        if(cabeza != NULL && (stack || queue)){
            NodoL* aux = cabeza;
            cabeza = cabeza->siguiente;
            size--;
            return aux;
        }
        cout << "No se puede sacar porque no es ni pila, ni cola" << endl;
        return NULL;
    }

    void reproducirStackQueue(string nombrePlaylist, string color, string es){

        if(cabeza != NULL){

            NodoL* cancion = cabeza;
            int contCanciones = 1;

            while(contCanciones <= size){
                NodoL* auxCancion = cancion;
                int auxContCanciones = 1;

                ofstream archivo;
                archivo.open("reproducirStack.txt",ios::out);
                archivo << "digraph G{" << endl;

                if(stack){
                    archivo << "   rankdir = TB;" << endl;
                }

                if(queue){
                    archivo << "   rankdir = LR;" << endl;
                }

                archivo << "   node[shape=record];" << endl;
                archivo << "   graph[ranksep = \"1\"];" << endl <<endl;

                while(auxContCanciones <= ((size + 1) - contCanciones)){
                    if(auxContCanciones == 1){
                        archivo << "    nodo_"<< auxContCanciones <<"[style=filled, fillcolor="<<color<<", label=\" [CANCION] "<< auxCancion->cancion  <<" \"];"<< endl;
                    }else{
                        archivo << "    nodo_"<< auxContCanciones <<"[label=\" [CANCION] "<< auxCancion->cancion  <<" \"];"<< endl;
                    }

                    if(auxCancion->siguiente != NULL){
                        archivo << "    nodo_" << auxContCanciones << "->nodo_" << auxContCanciones + 1 << ";" << endl;
                    }

                    auxContCanciones++;
                    auxCancion = auxCancion->siguiente;
                }

                archivo << "    labelloc=\"t\"" << endl;
                archivo << "    label = \"Reproduciendo Playlist " << nombrePlaylist << " Tipo "<< es <<" \" " << endl;
                archivo << "}" << endl;
                archivo.close();
                system("dot -Tpng reproducirStack.txt -o reproducirStack.png");
                system("reproducirStack.png");

                usleep(3000000);
                cout << endl << endl << endl;
                contCanciones++;
                cancion = cancion->siguiente;
            }

            ofstream archivo;
            archivo.open("reproducirStack.txt",ios::out);
            archivo << "digraph G{" << endl;
            archivo << "   rankdir = LR;" << endl;
            archivo << "   node[shape=record];" << endl;
            archivo << "   graph[ranksep = \"1\"];" << endl <<endl;
            archivo << "    nodo[label=\" FIN DE LA PLAYLIST \"];"<< endl;
            archivo << "}" << endl;
            archivo.close();
            system("dot -Tpng reproducirStack.txt -o reproducirStack.png");
            system("reproducirStack.png");
        }else{
            ofstream archivo;
            archivo.open("reproducirStack.txt",ios::out);
            archivo << "digraph G{" << endl;
            archivo << "   rankdir = LR;" << endl;
            archivo << "   node[shape=record];" << endl;
            archivo << "   graph[ranksep = \"1\"];" << endl <<endl;
            archivo << "    nodo[label=\" LA PLAYLIST "<< nombrePlaylist <<" ESTA VACIA \"];"<< endl;
            archivo << "}" << endl;
            archivo.close();
            system("dot -Tpng reproducirStack.txt -o reproducirStack.png");
            system("reproducirStack.png");
        }
    }

    void reproducirPopDequeue(string nombrePlaylist, string color, string es){

        if(cabeza != NULL){

            while(size > 0){
                ofstream archivo;
                archivo.open("reproducirStack.txt",ios::out);
                archivo << "digraph G{" << endl;

                if(stack){
                    archivo << "   rankdir = TB;" << endl;
                }

                if(queue){
                    archivo << "   rankdir = LR;" << endl;
                }

                archivo << "   node[shape=record];" << endl;
                archivo << "   graph[ranksep = \"1\"];" << endl <<endl;

                NodoL* aux = cabeza;
                int cont = 1;

                while(cont <= size){
                    if(cont == 1){
                        archivo << "    nodo_"<< cont <<"[style=filled, fillcolor="<<color<<", label=\" [CANCION] "<< aux->cancion  <<" \"];"<< endl;
                    }else{
                        archivo << "    nodo_"<< cont <<"[label=\" [CANCION] "<< aux->cancion  <<" \"];"<< endl;
                    }

                    if(aux->siguiente != NULL){
                        archivo << "    nodo_" << cont << "->nodo_" << cont + 1 << ";" << endl;
                    }
                    cont++;
                    aux = aux->siguiente;
                }

                sacar(); //SACAR == METODO POP == METODO DEQUEUE


                archivo << "    labelloc=\"t\"" << endl;
                archivo << "    label = \"Reproduciendo Playlist " << nombrePlaylist << " Tipo "<< es <<" \" " << endl;
                archivo << "}" << endl;
                archivo.close();
                system("dot -Tpng reproducirStack.txt -o reproducirStack.png");
                system("reproducirStack.png");

                usleep(3000000);
            }

            ofstream archivo;
            archivo.open("reproducirStack.txt",ios::out);
            archivo << "digraph G{" << endl;
            archivo << "   rankdir = LR;" << endl;
            archivo << "   node[shape=record];" << endl;
            archivo << "   graph[ranksep = \"1\"];" << endl <<endl;
            archivo << "    nodo[label=\" FIN DE LA PLAYLIST \"];"<< endl;
            archivo << "}" << endl;
            archivo.close();
            system("dot -Tpng reproducirStack.txt -o reproducirStack.png");
            system("reproducirStack.png");

        }else{
            ofstream archivo;
            archivo.open("reproducirStack.txt",ios::out);
            archivo << "digraph G{" << endl;
            archivo << "   rankdir = LR;" << endl;
            archivo << "   node[shape=record];" << endl;
            archivo << "   graph[ranksep = \"1\"];" << endl <<endl;
            archivo << "    nodo[label=\" LA PLAYLIST "<< nombrePlaylist <<" ESTA VACIA \"];"<< endl;
            archivo << "}" << endl;
            archivo.close();
            system("dot -Tpng reproducirStack.txt -o reproducirStack.png");
            system("reproducirStack.png");
        }
    }

    void reproducirShuffle(string nombrePlaylist){
        seleccionarShuffle(cabeza, 1, nombrePlaylist);
    }

    void reproducirCircular(string nombrePlaylist){
        seleccionarCircular(cabeza, 1, nombrePlaylist);
    }

private:

    void seleccionarShuffle(NodoL* nodo, int index, string nombrePlaylist){
        if(cabeza != NULL){

            int opc = 0;
            do{
                cout << endl << endl;
                cout << "   -------------- SELECCIONAR CANCION --------------" << endl;
                cout << "   [CANCION] : " << nodo->cancion << endl;
                cout << "   [ALBUM] : " << nodo->album << endl;
                cout << "   [ARTISTA] : " << nodo->artista << endl << endl;
                cout << "   1. REPRODUCIR CANCION" << endl;
                cout << "   2. CANCION ANTERIOR" << endl;
                cout << "   3. CANCION SIGUIENTE" << endl;
                cout << "   4. REGRESAR AL MENU" << endl;
                cout << "   -------------------------------------------------" << endl;
                cout << "   SELECCIONA UNA OPCION: ";
                cin >> opc;

                if(opc == 1){
                    cout << endl << "[REPRODUCIENDO] " << nodo->cancion << " [ARTISTA] " << nodo->artista << endl << endl;
                    graficarShuffle(index,nombrePlaylist);
                    opc = 5;
                    system("pause");
                }else if(opc == 2){
                    if(nodo->anterior != NULL){
                        seleccionarShuffle(nodo->anterior, index - 1, nombrePlaylist);
                        break;
                    }
                    opc = 5;
                }else if(opc == 3){
                    if(nodo->siguiente != NULL){
                        seleccionarShuffle(nodo->siguiente, index + 1, nombrePlaylist);
                        break;
                    }
                    opc = 5;
                }else if(opc == 4){
                    break;
                }else{
                    seleccionarShuffle(nodo, index, nombrePlaylist);
                    break;
                }
            }while(opc < 0 || opc > 4);

        }
    }

    void graficarShuffle(int index, string nombrePlaylist){
        if(cabeza != NULL){
            NodoL* aux = cabeza;
            int cont = 1;

            ofstream archivo;
            archivo.open("reproducirShuffle.txt",ios::out);
            archivo << "digraph G{" << endl;
            archivo << "   rankdir = LR;" << endl;
            archivo << "   node[shape=record];" << endl;
            archivo << "   graph[ranksep = \"1\"];" << endl <<endl;

            while(cont <= size){
                archivo << "    nodo_"<< cont <<"[label=\" [CANCION] "<< aux->cancion  <<" \"];"<< endl;
                if(cont == index){
                    archivo << "    nodo_"<< cont <<"[style=filled, fillcolor=pink, label=\" [CANCION] "<< aux->cancion  <<" \"];"<< endl;
                }else{
                    archivo << "    nodo_"<< cont <<"[label=\" [CANCION] "<< aux->cancion  <<" \"];"<< endl;
                }

                if(aux->siguiente != NULL){
                    archivo << "    nodo_" << cont << "->nodo_" << cont + 1 << ";" << endl;
                    archivo << "    nodo_" << cont + 1 << "->nodo_" << cont << ";" << endl;
                }
                cont++;
                aux = aux->siguiente;
            }

            archivo << "    labelloc=\"t\"" << endl;
            archivo << "    label = \"Reproduciendo Playlist " << nombrePlaylist << " Tipo Shuffle \"; " << endl;
            archivo << "}" << endl;
            archivo.close();
            system("dot -Tpng reproducirShuffle.txt -o reproducirShuffle.png");
            system("reproducirShuffle.png");
        }
    }

    void seleccionarCircular(NodoL* nodo, int index, string nombrePlaylist){
        if(cabeza != NULL){

            if(index > size){
                index = index - size;
            }

            if(index <= 0){
                index = size + index;
            }

            int opc = 0;
            do{
                cout << endl << endl;
                cout << "   -------------- SELECCIONAR CANCION --------------" << endl;
                cout << "   [CANCION] : " << nodo->cancion << endl;
                cout << "   [ALBUM] : " << nodo->album << endl;
                cout << "   [ARTISTA] : " << nodo->artista << endl << endl;
                cout << "   1. REPRODUCIR CANCION" << endl;
                cout << "   2. CANCION ANTERIOR" << endl;
                cout << "   3. CANCION SIGUIENTE" << endl;
                cout << "   4. REGRESAR AL MENU" << endl;
                cout << "   -------------------------------------------------" << endl;
                cout << "   SELECCIONA UNA OPCION: ";
                cin >> opc;

                if(opc == 1){
                    cout << endl << "[REPRODUCIENDO] " << nodo->cancion << " [ARTISTA] " << nodo->artista << endl << endl;
                    graficarCircular(index,nombrePlaylist);
                    opc = 5;
                    system("pause");
                }else if(opc == 2){
                    if(nodo->anterior != NULL){
                        seleccionarCircular(nodo->anterior, index - 1, nombrePlaylist);
                        break;
                    }
                    opc = 5;
                }else if(opc == 3){
                    if(nodo->siguiente != NULL){
                        seleccionarCircular(nodo->siguiente, index + 1, nombrePlaylist);
                        break;
                    }
                    opc = 5;
                }else if(opc == 4){
                    break;
                }else{
                    seleccionarCircular(nodo, index, nombrePlaylist);
                    break;
                }
            }while(opc < 0 || opc > 4);

        }
    }

    void graficarCircular(int index, string nombrePlaylist){
        if(cabeza != NULL){
            NodoL* aux = cabeza;
            int cont = 1;

            ofstream archivo;
            archivo.open("reproducirCircular.txt",ios::out);
            archivo << "digraph G{" << endl;
            archivo << "   rankdir = LR;" << endl;
            archivo << "   node[shape=record];" << endl;
            archivo << "   graph[ranksep = \"1\"];" << endl <<endl;



            while(cont <= size){
                archivo << "    nodo_"<< cont <<"[label=\" [CANCION] "<< aux->cancion  <<" \"];"<< endl;
                if(cont == index){
                    archivo << "    nodo_"<< cont <<"[style=filled, fillcolor=pink, label=\" [CANCION] "<< aux->cancion  <<" \"];"<< endl;
                }else{
                    archivo << "    nodo_"<< cont <<"[label=\" [CANCION] "<< aux->cancion  <<" \"];"<< endl;
                }

                if(aux->siguiente != NULL && cont < size){
                    archivo << "    nodo_" << cont << "->nodo_" << cont + 1 << ";" << endl;
                    archivo << "    nodo_" << cont + 1 << "->nodo_" << cont << ";" << endl;
                }
                cont++;
                aux = aux->siguiente;
            }

            archivo << "nodo_1->nodo_" << size << ";" << endl;
            archivo << "nodo_"<< size <<"->nodo_1" << ";" << endl;

            archivo << "    labelloc=\"t\"" << endl;
            archivo << "    label = \"Reproduciendo Playlist " << nombrePlaylist << " Tipo Circular \"; " << endl;
            archivo << "}" << endl;
            archivo.close();
            system("dot -Tpng reproducirCircular.txt -o reproducirCircular.png");
            system("reproducirCircular.png");
        }
    }


    void agregarPila(string artista, string cancion, string album, string mes, string anio){
        if(cabeza == NULL){
            cabeza = cola =  new NodoL(artista, cancion, album, mes, anio);
            size++;
        }else{
            NodoL* nuevo = new NodoL(artista, cancion, album, mes, anio);
            nuevo->siguiente = cabeza;
            cabeza = nuevo;
            size++;
        }
    }

    void agregarCola(string artista, string cancion, string album, string mes, string anio){
        if(cabeza == NULL){
            cabeza = cola =  new NodoL(artista, cancion, album, mes, anio);
            size++;
        }else{
            NodoL* nuevo = new NodoL(artista, cancion, album, mes, anio);
            cola->siguiente = nuevo;
            cola = nuevo;
            size++;
        }
    }

    void agregarShuffle(string artista, string cancion, string album, string mes, string anio){
        if(cabeza == NULL){
            cabeza = cola =  new NodoL(artista, cancion, album, mes, anio);
            size++;
        }else{
            NodoL* nuevo = new NodoL(artista, cancion, album, mes, anio);

            if(tipo == 1){
                cola->siguiente = nuevo;
                nuevo->anterior = cola;
                cola = nuevo;
                tipo = 2;
                size++;
            }else{
                nuevo->siguiente = cabeza;
                cabeza->anterior = nuevo;
                cabeza = nuevo;
                tipo = 1;
                size++;
            }

        }
    }

    void agregarCircular(string artista, string cancion, string album, string mes, string anio){
        if(cabeza == NULL){
            cabeza = cola =  new NodoL(artista, cancion, album, mes, anio);
            size++;
        }else{
            NodoL* nuevo = new NodoL(artista, cancion, album, mes, anio);
            cola->siguiente = nuevo;
            nuevo->anterior = cola;
            cola = nuevo;
            cola->siguiente = cabeza;
            cabeza->anterior = cola;
            size++;
        }
    }



};


#endif //MUSIC___LISTA_H
