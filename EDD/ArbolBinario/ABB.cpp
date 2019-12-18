//
// Created by aybso on 15/12/2019.
//

#include <fstream>
#include "ABB.h"

ABB::ABB() {
    this->raiz = NULL;
    size = 0;
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

void ABB::menuEnOrden(NodoBinario *nodo, int& i) {
    if(nodo != NULL){
        menuEnOrden(nodo->izquierda, i );
        i = i + 1;
        cout << "   " << i << ". " << nodo->nombre << " [" <<nodo->playlist->tipoEstructura << "]" << endl;
        i = i + 1;
        menuEnOrden(nodo->derecha, i);
    }else{
        i = i - 1;
    }
}

void ABB::menuPlaylist(){
    if(raiz != NULL){
        int i = 1;
        cout << "----------------------------------------------" << endl;
        menuEnOrden(raiz, i);
        cout << "   " << i + 1 << ". Salir" << endl;
        cout << "   Ingrese una opcion: ";
    }else{
        cout << endl << endl << "No hay ninguna playlist registrada" << endl << endl;
    }
}

void ABB::reproducirMusica(NodoBinario *nodo, int& i, int index) {
    if(nodo != NULL){
        reproducirMusica(nodo->izquierda, i, index);
        i = i + 1;

        if(i == index){
            cout << endl << " *******  REPRODUCIENDO LA PLAYLIST " << nodo->nombre << "  ******* " <<  endl;
            if(nodo->playlist->tipoEstructura == "stack"){
                nodo->playlist->reproducirPopDequeue(nodo->nombre,"orange","stack");
            }

            if(nodo->playlist->tipoEstructura == "queue"){
                nodo->playlist->reproducirPopDequeue(nodo->nombre,"yellow","queue");
            }
        }

        i = i + 1;
        reproducirMusica(nodo->derecha, i, index);
    }else{
        i = i - 1;
    }
}

void ABB::reproducirMusica(int index) {
    int i = 1;
    reproducirMusica(raiz, i, index );
}


