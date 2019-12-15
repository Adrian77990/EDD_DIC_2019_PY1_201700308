//
// Created by aybso on 15/12/2019.
//

#ifndef MUSIC___CUBOORTOGONAL_H
#define MUSIC___CUBOORTOGONAL_H

using namespace std;
#include <string>
#include <iostream>
#include "NodoOrtogonal.h"

class Cuboortogonal{
public:
    Nodo *cabecerax;
    Nodo *colax;
    int tamanox;

    Nodo *cabeceray;
    Nodo *colay;
    int tamanoy;

    Cuboortogonal() {
        cabecerax = NULL;
        colax = NULL;
        tamanox = 0;
        cabeceray = NULL;
        colay = NULL;
        tamanoy = 0;
    }

//--------------------------------------------------
    Nodo *obtenermesano(int mes,int ano)
    {
        Nodo *auxy = cabeceray;
        while(auxy!=NULL){
            if(auxy->mes == mes){
                Nodo *tempx = auxy->siguientex;
                while(tempx!=NULL){
                    if(tempx->ano == ano){return tempx;}
                    // cout<<"no "<<tempx->nombre<<"me "<<tempx->mes<<"ano "<<tempx->ano<<endl;
                    tempx = tempx->siguientex;
                }
                return NULL;
            }
            auxy = auxy->siguientey;
        }
        return NULL;
    }

//--------------------------------------------
    void imprimirporfilas()
    {
        Nodo *auxy = cabeceray;
        while(auxy!=NULL){
            Nodo *tempx = auxy->siguientex;
            while(tempx!=NULL){
                cout<<"no "<<tempx->nombre<<"me "<<tempx->mes<<"ano "<<tempx->ano<<endl;
                Nodo *tempz = tempx->siguientez;
                while(tempz!=NULL){
                    cout<<"  no "<<tempz->nombre<<"me "<<tempz->mes<<"ano "<<tempz->ano<<endl;
                    tempz = tempz->siguientez;
                }
                tempx = tempx->siguientex;
            }
            auxy = auxy->siguientey;
        }
    }

    bool existealbum(string nombre, int mes, int ano)
    {
        Nodo *auxy = cabeceray;
        while(auxy!=NULL){
            Nodo *tempx = auxy->siguientex;
            while(tempx!=NULL){
                //cout<<"no "<<tempx->nombre<<"me "<<tempx->mes<<"ano "<<tempx->ano<<endl;
                Nodo *tempz = tempx->siguientez;
                while(tempz!=NULL){
                    //      cout<<"  no "<<tempz->nombre<<"me "<<tempz->mes<<"ano "<<tempz->ano<<endl;
                    if(tempz->nombre == nombre){return true;}
                    tempz = tempz->siguientez;
                }
                tempx = tempx->siguientex;
            }
            auxy = auxy->siguientey;
        }
        return false;
    }

    void imprimirporcolumnas()
    {
        Nodo *auxx = cabecerax;
        while(auxx!=NULL){
            Nodo *tempy = auxx->siguientey;
            while(tempy!=NULL){
                cout<<"no "<<tempy->nombre<<"me "<<tempy->mes<<"ano "<<tempy->ano<<endl;
                tempy = tempy->siguientey;
            }
            auxx = auxx->siguientex;
        }
    }


    //----------------------------------------------------------------------------
    void agregaralbumenx(Nodo *mesy,Nodo *nuevo)
    {
        if(mesy->siguientex==NULL){
            mesy->siguientex = nuevo;
            nuevo->atrasx = mesy;
        }else{
            Nodo *anterior = mesy;
            Nodo *actual = mesy->siguientex;

            while(actual!=NULL){
                if(nuevo->ano < actual->ano){
//                    Nodo *aux = mesy->siguientex;
                    nuevo->siguientex = actual;
                    actual->atrasx = nuevo;
                    nuevo->atrasx = anterior;
                    anterior->siguientex = nuevo;
                    break;
                }
                anterior = actual;
                actual = actual->siguientex;
            }
            if(actual==NULL){
                nuevo->atrasx = anterior;
                anterior->siguientex = nuevo;
            }
        };
    }

    enum meses{
        enero = 1,
        febrero = 2,
        marzo = 3,
        abril = 4,
        mayo = 5,
        junio = 6,
        julio = 7,
        agosto = 8,
        septiembre = 9,
        octubre=10,
        noviembre = 11,
        diciembre =12
    };


    void agregaralbumeny(Nodo *anox,Nodo *nuevo)
    {
        if(anox->siguientey==NULL){
            anox->siguientey = nuevo;
            nuevo->atrasy = anox;
        }else{
            Nodo *anterior = anox;
            Nodo *actual = anox->siguientey;

            while(actual!=NULL){
                if(nuevo->mes < actual->mes){
//                    Nodo *aux = mesy->siguientex;
                    nuevo->siguientey = actual;
                    actual->atrasy = nuevo;
                    nuevo->atrasy = anterior;
                    anterior->siguientey = nuevo;
                    break;
                }
                anterior = actual;
                actual = actual->siguientey;
            }
            if(actual==NULL){
                nuevo->atrasy = anterior;
                anterior->siguientey = nuevo;
            }
        };
    }


    void agregaralbumenz(Nodo *z,Nodo *nuevo)
    {
        if(z->siguientez==NULL){
            z->siguientez = nuevo;
            nuevo->atrasz = z;
        }
//        cout<<z->siguientez->nombre;
        else{
            Nodo *auxiliar = z->siguientez;
            while(auxiliar->siguientez!=NULL){
                auxiliar = auxiliar->siguientez;
            }
            auxiliar->siguientez = nuevo;
            nuevo->atrasz = auxiliar;
        };
    }


    //------------------------------------------------------------------------
    void agregarcubo(string nombre, int mes, int ano)
    {
        insertarenx(ano);
        insertareny(mes);
        Nodo *nuevo = new Nodo(nombre,mes,ano);
        Nodo *x = obtenerx(ano);
        Nodo *y = obtenery(mes);

        Nodo *z = obtenermesano(mes, ano);

        if(z == NULL) {
            //cout << "ano " << x->ano << "mes" << y->mes << endl;
            agregaralbumenx(y, nuevo);
            agregaralbumeny(x, nuevo);
        }else{
            //cout<<z->nombre<<"  "<<z->mes<<"  "<<z->ano;
            if(existealbum(nombre,mes,ano) == false) {
                agregaralbumenz(z, nuevo);
            }
        }
    }

    //---------------------cabecera en y--------------------------------------------------------------
    bool existey(int mes)
    {
        if(cabeceray !=NULL){
            Nodo *temp = cabeceray;
            while(temp!=0){
                if(mes == temp->mes){ return true;}
                temp = temp->siguientey;
            }
        }
        return false;
    }

    Nodo *obtenery(int mes)
    {
        Nodo *temp = cabeceray;
        while(temp!=0){
            if(mes == temp->mes){ return temp;}
            temp = temp->siguientey;
        }
        return NULL;
    }

    void agregarenfrentey(int mes){
        Nodo *nodo = new Nodo("cabecera y",mes,0);
        if(cabeceray == NULL){
            cabeceray = colay = nodo;
            tamanoy++;
        }else{
            cabeceray->atrasy = nodo;
            nodo->siguientey = cabeceray;
            cabeceray = nodo;
            tamanoy++;
        }
    }

    void agregaralfinaly(int mes){
        Nodo *nodo = new Nodo("cabecera y",mes,0);
        if(cabeceray == NULL){
            cabeceray = colay = nodo;
            tamanoy++;
        }else{
            colay->siguientey = nodo;
            nodo->atrasy = colay;
            colay = nodo;
            tamanoy++;
        }
    }
    void insertareny(int mes){
        if(0 < mes && mes <= 12 && existey(mes)==false) {
            agregarenmedioy(mes);
        }
    }

    void imprimiry(){
        Nodo *temp = cabeceray;
        while(temp!=0){
            cout<<temp->mes<< endl;
            temp = temp->siguientey;
        }
    }

    void agregarenmedioy(int mes){
        Nodo *nodo = new Nodo("cabecera y",mes,0);
        if(cabeceray ==0)
        {
            agregarenfrentey(mes);
        }else{
            if(nodo->mes < cabeceray->mes){
                //   cout << nodo->mes << "es menor que " << cabeceray->mes << endl;
                agregarenfrentey(mes);
            }
            else if (nodo->mes > colay->mes){
                //   cout << nodo->mes << "es menor que " << cabeceray->mes << endl;
                agregaralfinaly(mes);
            }
            else{
                Nodo *aux = cabeceray;
                while(aux!=NULL){
                    if(nodo->mes < aux->mes){
                        // cout << nodo->mes << "es menor que " << aux->mes << " //////" << endl;
                        tamanoy++;
                        break;
                    }
                    aux = aux->siguientey;
                }
                nodo->siguientey = aux;
                nodo->atrasy = aux->atrasy;
                aux->atrasy->siguientey = nodo;
                aux->atrasy = nodo;

            }
        }
    }


    //---------------------------------cabecera en x-------------------------------------------
    bool existex(int ano)
    {
        if(cabecerax !=NULL){
            Nodo *temp = cabecerax;
            while(temp!=0){
                if(ano == temp->ano){ return true;}
                temp = temp->siguientex;
            }
        }
        return false;
    }

    Nodo *obtenerx(int ano)
    {
        Nodo *temp = cabecerax;
        while(temp!=0){
            if(ano == temp->ano){ return temp;}
            temp = temp->siguientex;
        }
        return NULL;
    }

    void agregarenfrentex(int ano){
        Nodo *nodo = new Nodo("cabecera x",0,ano);
        if(cabecerax == NULL){
            cabecerax = colax = nodo;
            tamanox++;
        }else{
            cabecerax->atrasx = nodo;
            nodo->siguientex = cabecerax;
            cabecerax = nodo;
            tamanox++;
        }
    }

    void agregaralfinalx(int ano){
        Nodo *nodo = new Nodo("cabecera x",0,ano);
        if(cabecerax == NULL){
            cabecerax = colax = nodo;
            tamanox++;
        }else{
            colax->siguientex = nodo;
            nodo->atrasx = colax;
            colax = nodo;
            tamanox++;
        }
    }
    void insertarenx(int ano){
        if(existex(ano)==false){agregarenmediox(ano);}
    }

    void imprimirx(){
        Nodo *temp = cabecerax;
        while(temp!=0){
            cout<<temp->ano<< endl;
            temp = temp->siguientex;
        }
    }

    void agregarenmediox(int ano){
        Nodo *nodo = new Nodo("cabecera x",0,ano);
        if(cabecerax ==0)
        {
            agregarenfrentex(ano);
        }else{
            if(nodo->ano < cabecerax->ano){
                //  cout << nodo->ano << "es menor que " << cabecerax->ano << endl;
                agregarenfrentex(ano);
            }
            else if (nodo->ano > colax->ano){
                //   cout << nodo->ano << "es menor que " << cabecerax->ano << endl;
                agregaralfinalx(ano);
            }
            else{
                Nodo *aux = cabecerax;
                while(aux!=NULL){
                    if(nodo->ano < aux->ano){
                        //   cout << nodo->ano << "es menor que " << aux->ano << " //////" << endl;
                        tamanox++;
                        break;
                    }
                    aux = aux->siguientex;
                }
                nodo->siguientex = aux;
                nodo->atrasx = aux->atrasx;
                aux->atrasx->siguientex = nodo;
                aux->atrasx = nodo;

            }
        }
    }
};


#endif //MUSIC___CUBOORTOGONAL_H
