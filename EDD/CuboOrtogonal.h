//
// Created by aybso on 15/12/2019.
//

#ifndef MUSIC___CUBOORTOGONAL_H
#define MUSIC___CUBOORTOGONAL_H

using namespace std;
#include <string>
#include <iostream>
#include "NodoOrtogonal.h"
#include "Listas/ListaTop/ListaTop.h"

class Cuboortogonal{
public:
    Nodo *cabecerax;
    Nodo *colax;
    int tamanox;
    double valoracion;

    Nodo *cabeceray;
    Nodo *colay;
    int tamanoy;

    int size;

    Cuboortogonal() {
        cabecerax = NULL;
        colax = NULL;
        tamanox = 0;
        cabeceray = NULL;
        colay = NULL;
        tamanoy = 0;
        valoracion = 0;
        size = 0;
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

    void graficarCanciones(string nombreArtista, string nombreAlbum, int mes,int ano)
    {
        Nodo *auxy = cabeceray;
        while(auxy!=NULL){
            if(auxy->mes == mes){
                Nodo *tempx = auxy->siguientex;
                while(tempx!=NULL){
                    if(tempx->ano == ano){
                        while(tempx != NULL){
                            if(tempx->nombre.compare(nombreAlbum) == 0){
                                tempx->canciones->graficar(nombreArtista); //GRAFICAR
                                break;
                            }
                            tempx = tempx->siguientez;
                        }
                        if(tempx == NULL){
                            cout << "El album no se encontro" << endl;
                        }
                        break;
                    }
                    tempx = tempx->siguientex;
                }
                if(tempx == NULL){
                    cout << "El anio no se encontro" << endl;
                }
                break;
            }
            auxy = auxy->siguientey;
        }
        if(auxy == NULL){
            cout << "El mes no se encontro" << endl;
        }
    }

    void graficarTopAlbumes(string nombreArtista) // ---------------------------------------------REPORTE TOP 5 ALBUMES DE UN ARTISTA
    {
        ListaTop* ltop = new ListaTop();

        Nodo* y = cabeceray;

        while(y != NULL){
            Nodo* x = y->siguientex;
            while(x != NULL){

                Nodo* z = x;

                while(z != NULL){
                    ltop->agregar(z->canciones->valoracion, z->nombre);
                    z = z->siguientez;
                }
                x = x->siguientex;
            }
            y = y->siguientey;
        }

        ltop->graficar("Albumes de " + nombreArtista);
    }

    double calcularValoracion() // ---------------------------------------------CALCULAR VALORACIÓN DEL CUBO DE LOS ALBUMES
    {
        Nodo* y = cabeceray;
        double sumaValoraciones = 0;
        int contadorAlbumes = 0;
        double res = 0;

        while(y != NULL){
            Nodo* x = y->siguientex;
            while(x != NULL){
                Nodo* z = x;
                while(z != NULL){
                    sumaValoraciones += z->canciones->valoracion;
                    contadorAlbumes++;
                    z = z->siguientez;
                }
                x = x->siguientex;
            }
            y = y->siguientey;
        }

        res = sumaValoraciones / contadorAlbumes;
        return res;

    }

//--------------------------------------------
    void imprimirporcolumnas()
    {
        Nodo *auxx = cabecerax;
        while(auxx!=NULL){
            Nodo *tempy = auxx->siguientey;
            while(tempy!=NULL){
                cout<<"[NOMBRE] "<<tempy->nombre<<" [MES] "<<tempy->mes<<" [ANIO] "<<tempy->ano<<endl;
                tempy->canciones->imprimir();
                Nodo *tempz = tempy->siguientez;

                while(tempz!=NULL){
                    cout<<"[NOMBRE] "<<tempz->nombre<<" [MES] "<<tempz->mes<<" [ANIO] "<<tempz->ano<<endl;
                    tempz->canciones->imprimir();
                    tempz = tempz->siguientez;
                }

                tempy = tempy->siguientey;
            }
            auxx = auxx->siguientex;
        }
    }

    void menuAlbumes()
    {
        Nodo *auxx = cabecerax;
        int index = 1;
        cout << "----------------------------------------------" << endl;

        while(auxx!=NULL){
            Nodo *tempy = auxx->siguientey;
            while(tempy!=NULL){
                Nodo *tempz = tempy;
                while(tempz!=NULL){
                    cout << "   " << index << ". " << tempz->nombre << endl;
                    index++;
                    tempz = tempz->siguientez;
                }

                tempy = tempy->siguientey;
            }
            auxx = auxx->siguientex;
        }
        cout << "   Ingrese una opcion: ";
    }

    Nodo* getAlbum(int indice)
    {
        Nodo *auxx = cabecerax;
        int index = 1;

        while(auxx!=NULL){
            Nodo *tempy = auxx->siguientey;
            while(tempy!=NULL){
                Nodo *tempz = tempy;
                while(tempz!=NULL){
                    if(index == indice){
                        return tempz;
                    }
                    index++;
                    tempz = tempz->siguientez;
                }

                tempy = tempy->siguientey;
            }
            auxx = auxx->siguientex;
        }

        return  NULL;
    }


    void imprimirporfilas()
    {
        Nodo *auxy = cabeceray;
        while(auxy!=NULL){
            Nodo *tempx = auxy->siguientex;
            while(tempx!=NULL){
                cout<<"[NOMBRE] "<<tempx->nombre<<" [MES] "<<tempx->mes<<" [ANIO] "<<tempx->ano<<endl;
                tempx->canciones->imprimir();
                Nodo *tempz = tempx->siguientez;
                while(tempz!=NULL){
                    cout<<"[NOMBRE] "<<tempz->nombre<<" [MES] "<<tempz->mes<<" [ANIO] "<<tempz->ano<<endl;
                    tempz->canciones->imprimir();
                    tempz = tempz->siguientez;
                }
                tempx = tempx->siguientex;
            }
            auxy = auxy->siguientey;
        }
    }

    string mes_string(int mes){
        if(mes == 1){
            return "Enero";
        }

        if(mes == 2){
            return "Febrero";
        }

        if(mes == 3){
            return "Marzo";
        }

        if(mes == 4){
            return "Abril";
        }

        if(mes == 5){
            return "Mayo";
        }

        if(mes == 6){
            return "Junio";
        }

        if(mes == 7){
            return "Julio";
        }

        if(mes == 8){
            return "Agosto";
        }

        if(mes == 9){
            return "Septiembre";
        }

        if(mes == 10){
            return "Octubre";
        }

        if(mes == 11){
            return "Noviembre";
        }

        if(mes == 12){
            return "Diciembre";
        }

        return " ";
    }

    int index_year (int year){
        if(cabecerax != NULL){
            Nodo* x = cabecerax;
            int contx = 1;
            while (x != NULL){
                if(year == x->ano){
                    return contx;
                }
                contx++;
                x= x->siguientex;
            }
        }

        return 0;
    }

    void graficar()
    {
        ofstream archivo;
        archivo.open("matrix.txt",ios::out);

       archivo << "digraph G{ \n";
       archivo << "    rankdir = TB; \n";
       archivo << "    node[shape=record]; \n";
       archivo << "    graph[ranksep=\"1\"]; \n";


        if(cabecerax != NULL && cabeceray != NULL){
            archivo << "raiz[label=\"matrix\", pos=\"0,0!\"];"<<endl;
            archivo << "raiz->nodo_0_" << cabeceray->mes << ";"<<endl;
            archivo << "nodo_0_" << cabeceray->mes << "->raiz;"<<endl;

            archivo << "raiz->nodo_" << cabecerax->ano << "_0;"<< endl;
            archivo << "nodo_" << cabecerax->ano << "_0->raiz;"<< endl;
        }

        //---------------------------Y---------------------
        Nodo *y = cabeceray;

        while(y!=NULL){
            archivo << "nodo_0_" << to_string(y->mes) << "[label=\" "<< mes_string(y->mes) << "\"  pos=\"0,-" << y->mes << "!\"];\n";

            if(y->siguientey != NULL){
                archivo << "nodo_0_" << y->mes << "-> nodo_0_" << y->siguientey->mes << "\n";
                archivo << "nodo_0_" << y->siguientey->mes << "-> nodo_0_" << y->mes << "\n";
            }

            if(y->siguientex != NULL){
                archivo << "nodo_0_" << y->mes << "-> nodo_"<< y->siguientex->ano <<"_" << y->siguientex->mes << ";\n";
                archivo << "nodo_"<< y->siguientex->ano <<"_" << y->siguientex->mes << "->" << "nodo_0_" << y->mes << ";\n";
            }

            Nodo *y_x = y->siguientex;

            while(y_x != NULL){
                archivo << "nodo_"<< y_x->ano << "_" << y_x->mes << "[label=\" "<< y_x->nombre << "\"  pos=\" "<< index_year(y_x->ano) * 4 <<",-" << y_x->mes << "!\"];\n";

                if(y_x->siguientex != NULL){
                    archivo << "nodo_"<< y_x->ano << "_" << y_x->mes << "->" << "nodo_"<< y_x->siguientex->ano << "_" << y_x->siguientex->mes << ";\n";
                    archivo << "nodo_"<< y_x->siguientex->ano << "_" << y_x->siguientex->mes << "->" << "nodo_"<< y_x->ano << "_" << y_x->mes << ";\n";
                }

                Nodo *z = y_x->siguientez;
                int contz = 1;
                while(z != NULL){
                    archivo << "nodo_"<< y_x->ano << "_" << y_x->mes << "_"<< contz << "[label=\" "<< z->nombre <<" \"  pos=\" "<< (index_year(y_x->ano) * 4 + (0.3 * contz)) <<",-" << (y_x->mes + (0.12 * contz)) << "!\"];\n";
                    contz++;
                    z = z->siguientez;
                }

                y_x = y_x->siguientex;
            }

            y = y->siguientey;
        }

        //---------------------------X---------------------
        Nodo *x = cabecerax;

        while(x!=NULL){
            archivo << "nodo_" << to_string(x->ano) << "_0[label=\" "<< x->ano << "\"  pos=\"" << (index_year(x->ano) * 4) << ", 0!\"];\n";
            if(x->siguientex != NULL){
                archivo << "nodo_" << x->ano << "_0 -> nodo_" << x->siguientex->ano << "_0;\n";
                archivo << "nodo_" << x->siguientex->ano << "_0 -> nodo_" << x->ano << "_0;\n";
            }

            if(x->siguientey != NULL){
                archivo << "nodo_" << x->ano << "_0 -> nodo_" << x->siguientey->ano << "_"<< x->siguientey->mes<<";\n";
                archivo << "nodo_" << x->siguientey->ano << "_"<< x->siguientey->mes <<" -> nodo_" << x->ano << "_0" <<";\n";
            }

            Nodo *x_y = x->siguientey;

            while(x_y != NULL){
                if(x_y->siguientey != NULL){
                    archivo << "nodo_"<< x_y->ano << "_" << x_y->mes << "->" << "nodo_"<< x_y->siguientey->ano << "_" << x_y->siguientey->mes << ";\n";
                    archivo << "nodo_"<< x_y->siguientey->ano << "_" << x_y->siguientey->mes << "->" << "nodo_"<< x_y->ano << "_" << x_y->mes << ";\n";
                }

                x_y = x_y->siguientey;
            }

            x = x->siguientex;
        }

        archivo << "}" << endl;
        archivo.close();
        system("neato -Tpng matrix.txt -o matrix.png");
        system("matrix.png");
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
    void agregarcubo(string nombre, int mes, int ano, ListaSimple* canciones)
    {
        insertarenx(ano);
        insertareny(mes);
        Nodo *nuevo = new Nodo(nombre,mes,ano, canciones);
        Nodo *x = obtenerx(ano);
        Nodo *y = obtenery(mes);

        Nodo *z = obtenermesano(mes, ano);

        if(z == NULL) {
            //cout << "ano " << x->ano << "mes" << y->mes << endl;
            agregaralbumenx(y, nuevo);
            agregaralbumeny(x, nuevo);
            size++;
        }else{
            //cout<<z->nombre<<"  "<<z->mes<<"  "<<z->ano;
            if(existealbum(nombre,mes,ano) == false) {
                agregaralbumenz(z, nuevo);
                size++;
            }
        }

        valoracion = calcularValoracion();
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
        Nodo *nodo = new Nodo("cabecera y",mes,0, new ListaSimple());
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
        Nodo *nodo = new Nodo("cabecera y",mes,0, new ListaSimple());
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
        Nodo *nodo = new Nodo("cabecera y",mes,0, new ListaSimple());
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
                        nodo->siguientey = aux;
                        nodo->atrasy = aux->atrasy;
                        aux->atrasy->siguientey = nodo;
                        aux->atrasy = nodo;
                        tamanoy++;
                        break;
                    }
                    aux = aux->siguientey;
                }


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
        Nodo *nodo = new Nodo("cabecera x",0,ano, new ListaSimple());
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
        Nodo *nodo = new Nodo("cabecera x",0,ano, new ListaSimple());
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
        Nodo *nodo = new Nodo("cabecera x",0,ano, new ListaSimple());
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
