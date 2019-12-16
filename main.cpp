#include <iostream>
#include <string>
//LIBRERIA PARA EL MANEJO DEL ARCHIVO JSON
#include "json.hpp"

//IMPORTACIÓN DE CLASES DE LAS PROPIAS ESTRUCTURAS
#include "EDD/ListaDoble.h"
#include "EDD/CuboOrtogonal.h"
#include "EDD/ArbolBinario/ABB.h"

//DECLARACIÓN DE METODOS
void Menu();
void Reportes();
void Reproduccion();
void Biblioteca();
void PlayLista();
void CargarLibreria();
void CargarPlaylist();

//USINGS
using namespace std;
using json = nlohmann::json;

//----------------------------------------------MAIN----------------------------------------------
int main() {


    return 0;
}
//------------------------------------------------------------------------------------------------


//IMPLEMENTACIÓN DE METODOS DECLARADOS
void Menu(){
    int eleccionM = 0;

    do{
        cout<<"	1 Carga de library json"<<endl;
        cout<<"	2 Carga de playlist json"<<endl;
        cout<<"	3 Reportes"<<endl;
        cout<<"	4 Reproduccion musica"<<endl;
        cout<<"	5 Salir o una letra"<<endl;
        cout << "Ingresa una opcion: ";

        cin >> eleccionM;

        cout << "" <<  endl << endl;
        if(eleccionM == 1){
            cout<<"Carga de library json"<<endl;
            //json_ex();
            CargarLibreria();
        }else if(eleccionM == 2){
            cout<<"Carga de playlist json"<<endl;
            //json_play();
            CargarPlaylist();
        }else if(eleccionM == 3){
            cout<<"Reportes"<<endl;
            Reportes();
        }else if(eleccionM == 4){
            cout<<"Reproduccion de musica"<<endl;
            Reproduccion();
        }else if(eleccionM == 5){
            cout<<"Saliste"<<endl;
            break;
        }else{
            eleccionM = 0;
        }
    }while(eleccionM != 0);
}