//
// Created by aybso on 15/12/2019.
//

#include <fstream>
#include "ABB.h"

ABB::ABB() {
    this->raiz = NULL;
}

NodoBinario* ABB::agregar(NodoBinario *nodo, NodoBinario *data) {
    if (nodo == NULL){
        size++;
        return data;
    }

    if(data->nombre.compare(nodo->nombre) < 0){
        nodo->izquierda = agregar(nodo->izquierda, data);
    }else if(data->nombre.compare(nodo->nombre) > 0){
        nodo->derecha = agregar(nodo->derecha, data);
    }else{
        cout << endl << "No se puede agregar " << data->nombre << " porque ya existe" << endl << endl;
    }

    return nodo;

}

void ABB::imprimirEnOrden(NodoBinario *nodo) {
    if(nodo != NULL){
        imprimirEnOrden(nodo->izquierda);
        cout << nodo->nombre << endl;
        cout << "------------------------"<<endl;
        nodo->playlist->imprimir();
        imprimirEnOrden(nodo->derecha);
        cout << endl << endl;
    }
}

void ABB::imprimirPreOrden(NodoBinario *nodo) {
    if(nodo != NULL){
        cout << nodo->nombre << endl;
        nodo->playlist->imprimir();
        imprimirPreOrden(nodo->izquierda);
        imprimirPreOrden(nodo->derecha);
        cout << endl << endl;
    }
}

void ABB::imprimirPostOrden(NodoBinario *nodo) {
    if(nodo != NULL){
        imprimirPostOrden(nodo->izquierda);
        imprimirPostOrden(nodo->derecha);
        cout << nodo->nombre << endl;
        nodo->playlist->imprimir();
        cout << endl << endl;
    }
}

void ABB::agregar(string nombre, Lista* lista) {
    raiz = agregar(raiz, new NodoBinario(nombre, lista));

}

void ABB::imprimirEnOrden() {
    imprimirEnOrden(raiz);
}

void ABB::imprimirPreOrden() {
    imprimirPreOrden(raiz);
}

void ABB::imprimirPostOrden() {
    imprimirPostOrden(raiz);
}

void ABB::graficar(NodoBinario* nodo, string& s) {

    if(nodo != NULL){
        string nombre = nodo->nombre;
        replaceChars(nombre, " ", "_");

        s += "    nodo_" + nombre + "[label=\"<i>|" + nombre + "|<d>\"];\n";
        if(nodo->izquierda != NULL){
            s += "    nodo_" + nodo->nombre + ":i->" + "nodo_" + nodo->izquierda->nombre + ";\n";
        }

        if(nodo->derecha != NULL){
            s += "    nodo_" + nodo->nombre + ":d->" + "nodo_" + nodo->derecha->nombre + ";\n";
        }

        graficar(nodo->izquierda, s);
        graficar(nodo->derecha, s);
    }

}

void ABB::replaceChars(string& modifyMe,const string& findMe, const string& newChars){
    size_t i = modifyMe.find(findMe, 0);
    if(i != string::npos)
        modifyMe.replace(i, findMe.size(), newChars);
}

void ABB::graficar() {
    ofstream archivo;
    archivo.open("abb.txt",ios::out);

    string s = "digraph G{ \n";
    s+= "    rankdir = TB; \n";
    s+= "    node[shape=record]; \n";
    s+= "    graph[ranksep=\"1\"]; \n";
    graficar(raiz, s);
    s+= "} \n";

    archivo << s << endl;
    archivo.close();
    system("dot -Tpng abb.txt -o abb.png");
    system("abb.png");
}

