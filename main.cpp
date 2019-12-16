#include <iostream>
#include <string>
//LIBRERIA PARA EL MANEJO DEL ARCHIVO JSON
#include "json.hpp"

//IMPORTACIÓN DE CLASES DE LAS PROPIAS ESTRUCTURAS
#include "EDD/ListaDoble.h"
#include "EDD/CuboOrtogonal.h"
#include "EDD/ArbolBinario/ABB.h"

//DECLARACIÓN DE METODOS
string convertir_lower(string data);
void Menu();
void Reportes();
void Reproduccion();
void Biblioteca();
void PlayLista();
void CargarLibreria();
void CargarPlaylist();

//ESTRUCTURAS PARA MANEJAR LA INFORMACIÓN
ListaDoble *listaArtistas = new ListaDoble();

//USINGS
using namespace std;
using json = nlohmann::json;


//----------------------------------------------MAIN----------------------------------------------
int main() {

    Menu();

    return 0;
}
//------------------------------------------------------------------------------------------------


//IMPLEMENTACIÓN DE METODOS DECLARADOS
string convertir_lower(string data){
    int lower(int c);
    for_each(data.begin(), data.end(), [](char & c){
        c = ::tolower(c);
    });
    return data;
}

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

void Reportes(){
    int eleccionR = 0;

    do{
        cout<<"	1 Artist Report"<<endl;
        cout<<"	2 Discography Report"<<endl;
        cout<<"	3 Album Report"<<endl;
        cout<<"	4 Playlist Report"<<endl;
        cout<<"	5 Top 5 Albums by artist report"<<endl;
        cout<<"	6 Top 5 artist "<<endl;
        cout<<"	7 Regresar al menu principal"<<endl;
        cout << "Ingresa una opcion: ";

        cin >> eleccionR;

        cout << "" <<  endl << endl;
        if(eleccionR == 1){
            cout<<"Artist Report"<<endl;
        }else if(eleccionR == 2){
            cout<<"Discography Report"<<endl;
        }else if(eleccionR == 3){
            cout<<"Album Report"<<endl;
        }else if(eleccionR == 4) {
            cout << "Playlist Report" << endl;
        }else if(eleccionR == 5){
            cout<<"Top 5 Albums by artist report"<<endl;
        }else if(eleccionR == 6){
            cout<<"Top 5 artists"<<endl;
        }else if(eleccionR == 7){
            cout<<"Regresas a menu"<<endl;
            // Menu();
            break;
        }else{
            eleccionR = 0;
        }
    }while(eleccionR != 0);
}

void Reproduccion(){
    int eleccionREP = 0;

    do{
        cout<<"	1 Biblioteca"<<endl;
        cout<<"	2 Playlist"<<endl;
        cout<<"	3 Regresar al menu principal"<<endl;
        cout << "Ingresa una opcion: ";

        cin >> eleccionREP;

        cout << "" <<  endl << endl;
        if(eleccionREP == 1){
            cout<<"Biblioteca"<<endl;
            Biblioteca();
        }else if(eleccionREP == 2){
            cout<<"Playlist"<<endl;
            PlayLista();
        }else if(eleccionREP == 3){
            cout<<"Regresar al menu principal"<<endl;
            // Menu();
            break;
        }else{
            eleccionREP = 0;
        }
    }while(eleccionREP != 0);
}

void Biblioteca(){
    int eleccionB = 0;

    do{
        cout<<"	1 By artist"<<endl;
        cout<<"	2 By songs"<<endl;
        cout<<"	3 Regresar al menu principal"<<endl;
        cout << "Ingresa una opcion: ";

        cin >> eleccionB;

        cout << "" <<  endl << endl;
        if(eleccionB == 1){
            cout<<"By artist"<<endl;
        }else if(eleccionB == 2){
            cout<<"By songs"<<endl;
        }else if(eleccionB == 3){
            cout<<"Regresar al menu principal"<<endl;
            Menu();
            break;
        }else{
            eleccionB = 0;
        }
    }while(eleccionB != 0);
}

void PlayLista(){
    int eleccionPL = 0;

    do{
        cout<<"	1 Stack Pila"<<endl;
        cout<<"	2 Queue Cola"<<endl;
        cout<<"	3 Shuffle Lista doblemente enlazada"<<endl;
        cout<<"	4 Circular Lista doblemente enlazada circular"<<endl;
        cout<<"	5 Regresar al menu principal"<<endl;
        cout << "Ingresa una opcion: ";

        cin >> eleccionPL;

        cout << "" <<  endl << endl;
        if(eleccionPL == 1){
            cout<<"Stack"<<endl;
        }else if(eleccionPL == 2){
            cout<<"Queue"<<endl;
        }else if(eleccionPL == 3){
            cout<<"Shuffle"<<endl;
        }else if(eleccionPL == 4){
            cout<<"Circular"<<endl;
        }else if(eleccionPL == 5){
            cout<<"Regresar al menu principal"<<endl;
            Menu();
            break;
        }else{
            eleccionPL = 0;
        }
    }while(eleccionPL != 0);
}

void CargarPlaylist(){

}

bool validarArtista(json artista){
    if(!artista.is_null() && !artista["Name"].is_null() && !artista["Albums"].is_null()){
        return true;
    }
    return false;
}

bool validarAlbum(json album){
    if(!album["Name"].is_null() && !album["Month"].is_null() && !album["Year"].is_null() && !album["Songs"].is_null()){
        return true;
    }
    return false;
}

void agregarAlbums(string album, string mes, string anio, Cuboortogonal* cuboAlbums){
    if(mes == "enero"){
        cuboAlbums->agregarcubo(album, cuboAlbums->enero, atoi(anio.c_str()) );
    }

    if(mes == "febrero"){
        cuboAlbums->agregarcubo(album, cuboAlbums->febrero, atoi(anio.c_str()) );
    }

    if(mes == "marzo"){
        cuboAlbums->agregarcubo(album, cuboAlbums->marzo, atoi(anio.c_str()) );
    }

    if(mes == "abril"){
        cuboAlbums->agregarcubo(album, cuboAlbums->abril, atoi(anio.c_str()) );
    }

    if(mes == "mayo"){
        cuboAlbums->agregarcubo(album, cuboAlbums->mayo, atoi(anio.c_str()) );
    }

    if(mes == "junio"){
        cuboAlbums->agregarcubo(album, cuboAlbums->junio, atoi(anio.c_str()) );
    }

    if(mes == "julio"){
        cuboAlbums->agregarcubo(album, cuboAlbums->julio, atoi(anio.c_str()) );
    }

    if(mes == "agosto"){
        cuboAlbums->agregarcubo(album, cuboAlbums->agosto, atoi(anio.c_str()) );
    }

    if(mes == "septiembre"){
        cuboAlbums->agregarcubo(album, cuboAlbums->septiembre, atoi(anio.c_str()) );
    }

    if(mes == "octubre"){
        cuboAlbums->agregarcubo(album, cuboAlbums->octubre, atoi(anio.c_str()) );
    }

    if(mes == "noviembre"){
        cuboAlbums->agregarcubo(album, cuboAlbums->noviembre, atoi(anio.c_str()) );
    }

    if(mes == "diciembre"){
        cuboAlbums->agregarcubo(album, cuboAlbums->diciembre, atoi(anio.c_str()) );
    }
}

void CargarLibreria(){
    string filename = "";

    cout << "Nombre de la libreria: ";
    cin >> filename;

    cout << "Cargando archivo " << filename << endl << endl;
    ifstream reader(filename);

    if (reader.fail()){
        cout << "El archivo no existe, verifique que la ruta y el archivo exista." << endl << endl;
    }else{
        cout << "Cargando " << filename << endl << endl;

        json libreria;
        reader >> libreria;
        libreria = libreria["Library"];

        for(int i = 0; i < libreria.size(); i++){
            json artista = libreria[i]["Artist"];

            if(validarArtista(artista)){
                string nombreArtista = artista["Name"];
                json albumsArtista = artista["Albums"];
                Cuboortogonal *cuboAlbums = new Cuboortogonal();

                for(int j = 0; j < albumsArtista.size(); j++){
                    json album = albumsArtista[j];

                    if(validarAlbum(album)){
                        string nombreAlbum = album["Name"];
                        string mesAlbum = convertir_lower(album["Month"]);
                        string anioAlbum = album["Year"];
                        json cancionesAlbum = album["Songs"];

                        agregarAlbums(nombreAlbum, mesAlbum, anioAlbum, cuboAlbums);

                    }
                }
                listaArtistas->replaceChars(nombreArtista, "\"", "");
                listaArtistas->insertarartista(nombreArtista, cuboAlbums);
            }
        }
        listaArtistas->imprimiralbums();
    }
    reader.close();
}





