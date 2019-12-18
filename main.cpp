#include <iostream>
#include <string>
//LIBRERIA PARA EL MANEJO DEL ARCHIVO JSON
#include "json.hpp"

//IMPORTACIÓN DE CLASES DE LAS PROPIAS ESTRUCTURAS
#include "EDD/ListaDoble.h"
#include "EDD/CuboOrtogonal.h"
#include "EDD/ArbolBinario/ABB.h"
#include "EDD/Listas/ListaCanciones/ListaSimple.h"
#include "EDD/Listas/ListaPalabras/ListaPalabras.h"
#include "EDD/Listas/Pila_Cola_Circular/Lista.h"
#include "EDD/Listas/ListaTop/ListaTop.h"
#include "EDD/NodoOrtogonal.h"
#include <unistd.h>

//DECLARACIÓN DE METODOS
string convertir_lower(string data);
ListaPalabras* split(string palabra, string del);
void Menu();
void Reportes();
void Reproduccion();
void Biblioteca();
void PlayLista();
void CargarLibreria();
void CargarPlaylist();

//ESTRUCTURAS PARA MANEJAR LA INFORMACIÓN
ListaDoble *listaArtistas = new ListaDoble();
ListaSimple* allSongsList = new ListaSimple();
ABB *arbolPlaylist = new ABB();

//USINGS
using namespace std;
using json = nlohmann::json;


//----------------------------------------------MAIN----------------------------------------------
int main() {

    //pila->reproducirStackQueue("Rock","orange", "Stack");

    //cola->reproducirStackQueue("Electronica","yellow","Queue");
    //cola->reproducirPopDequeue("Electronica","yellow","Queue");
    //cola->reproducirPopDequeue("Electronica","yellow","Queue");

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

void replaceChars(string& modifyMe,const string& findMe, const string& newChars){
    size_t i = modifyMe.find(findMe, 0);
    if(i != string::npos)
        modifyMe.replace(i, findMe.size(), newChars);
}

ListaPalabras* split(string palabra, string del){
    size_t pos = 0;
    string tkn;
    ListaPalabras* l = new ListaPalabras();

    while((pos = palabra.find(del)) != string::npos ){
        tkn = palabra.substr(0, pos);
        l->agregar(tkn);
        palabra.erase(0, pos + del.length());
    }

    l->agregar(palabra);

    return l;
}

void limpiarBuffer(){
    while ((getchar()) != '\n');
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
            CargarLibreria();
        }else if(eleccionM == 2){
            cout<<"Carga de playlist json"<<endl;
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

int mes_int (string mes){

    if(mes == "enero"){
        return 1;
    }
    if(mes == "febrero"){
        return 2;
    }
    if(mes == "marzo"){
        return 3;
    }
    if(mes == "abril"){
        return 4;
    }
    if(mes == "mayo"){
        return 5;
    }
    if(mes == "junio"){
        return 6;
    }
    if(mes == "julio"){
        return 7;
    }
    if(mes == "agosto"){
        return 8;
    }
    if(mes == "septiembre"){
        return 9;
    }
    if(mes == "octubre"){
        return 10;
    }
    if(mes == "noviembre"){
        return 11;
    }
    if(mes == "diciembre"){
        return 12;
    }
    return 0;

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


        if(eleccionR == 1){
            cout<<"Artist Report"<<endl;
            listaArtistas->grafoy();
        }else if(eleccionR == 2){
            limpiarBuffer();
            char nombreArtista[100];
            cout<<endl << "Discography Report"<<endl;
            cout << "Nombre del artista: " ;
            cin.getline(nombreArtista, sizeof(nombreArtista));
            listaArtistas->graficarDiscografia(nombreArtista);
        }else if(eleccionR == 3){
            char nombreArtista[150];
            char nombreAlbum[150];
            string mes_s = "";
            int anio;
            int mes;

            cout << endl << "Album Report"<<endl;
            cout << "Nombre del artista: ";
            limpiarBuffer();
            cin.getline(nombreArtista, sizeof(nombreArtista));

            cout << "Nombre del Album: ";
            cin.getline(nombreAlbum, sizeof(nombreAlbum));

            cout << "Anio del Album: ";
            cin >> anio;

            cout << "Mes del Album: ";
            cin >> mes_s;

            mes = mes_int(mes_s);

            listaArtistas->graficarCanciones(nombreArtista, nombreAlbum, anio, mes);

        }else if(eleccionR == 4) {
            cout << "Playlist Report" << endl;
            arbolPlaylist->graficar();
        }else if(eleccionR == 5){

            limpiarBuffer();
            char nombreArtista[100];
            cout<<"Top 5 Albums by artist report"<<endl;
            cout << "Nombre del artista: " ;
            cin.getline(nombreArtista, sizeof(nombreArtista));

            listaArtistas->graficarTopAlbumes(nombreArtista);

        }else if(eleccionR == 6){

            limpiarBuffer();
            char nombreArtista[100];
            cout<<"Top 5 artists"<<endl;
            listaArtistas->graficarTopArtistas();

        }else if(eleccionR == 7){
            cout<<"Regresas a menu"<<endl;
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

            int opc;
            listaArtistas->menuArtistas();
            cin >> opc;
            cout << endl << endl;

            if(opc >= 1 && opc <= listaArtistas->tamano){
                ListaDoble::Nodo *artista = listaArtistas->getArtista(opc);
                cout << "Discografia de  " << artista->valor << endl;
                Cuboortogonal* cubo = artista->cubo;
                cout << "Tiene " << cubo->size << " Albumes " << endl;
                cubo->menuAlbumes();
                limpiarBuffer();
                int opc2;
                cin >> opc2;

                if(opc2 >= 1 && opc2 <= cubo->size){
                    Nodo * album = cubo->getAlbum(opc2);
                    cout << "Canciones del album  " << album->nombre << endl;
                    album->canciones->menuCanciones();
                    int opc3;
                    cin >> opc3;

                    if(opc3 >= 1 && opc3 <= album->canciones->size){
                        album->canciones->reproducirCancion(opc3);
                    }else{
                        cout << endl << endl;
                        limpiarBuffer();
                        break;
                    }
                }else{
                    cout << endl << endl;
                    limpiarBuffer();
                    break;
                }

            }else{
                cout << endl << endl;
                limpiarBuffer();
                break;
            }

        }else if(eleccionB == 2){
            cout<<"By songs"<<endl;
            allSongsList->menuTodasCanciones();
            int opc;
            cin >> opc;

            if(opc >= 1 && opc <= allSongsList->size){
                allSongsList->reproducirCancion(opc);
            }else{
                cout << endl << endl;
                limpiarBuffer();
                break;
            }

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

bool validarCancion(json cancion){
    if(!cancion["Name"].is_null() && !cancion["File"].is_null() && !cancion["Rating"].is_null() ){
        return true;
    }
    return false;
}

void agregarAlbums(string album, string mes, string anio, Cuboortogonal* cuboAlbums, ListaSimple* canciones){
    if(mes == "enero"){
        cuboAlbums->agregarcubo(album, cuboAlbums->enero, atoi(anio.c_str()), canciones );
    }

    if(mes == "febrero"){
        cuboAlbums->agregarcubo(album, cuboAlbums->febrero, atoi(anio.c_str()) , canciones );
    }

    if(mes == "marzo"){
        cuboAlbums->agregarcubo(album, cuboAlbums->marzo, atoi(anio.c_str()) , canciones );
    }

    if(mes == "abril"){
        cuboAlbums->agregarcubo(album, cuboAlbums->abril, atoi(anio.c_str()) , canciones );
    }

    if(mes == "mayo"){
        cuboAlbums->agregarcubo(album, cuboAlbums->mayo, atoi(anio.c_str()) , canciones );
    }

    if(mes == "junio"){
        cuboAlbums->agregarcubo(album, cuboAlbums->junio, atoi(anio.c_str()) , canciones );
    }

    if(mes == "julio"){
        cuboAlbums->agregarcubo(album, cuboAlbums->julio, atoi(anio.c_str()) , canciones );
    }

    if(mes == "agosto"){
        cuboAlbums->agregarcubo(album, cuboAlbums->agosto, atoi(anio.c_str()) , canciones );
    }

    if(mes == "septiembre"){
        cuboAlbums->agregarcubo(album, cuboAlbums->septiembre, atoi(anio.c_str()) , canciones );
    }

    if(mes == "octubre"){
        cuboAlbums->agregarcubo(album, cuboAlbums->octubre, atoi(anio.c_str()) , canciones );
    }

    if(mes == "noviembre"){
        cuboAlbums->agregarcubo(album, cuboAlbums->noviembre, atoi(anio.c_str()) , canciones );
    }

    if(mes == "diciembre"){
        cuboAlbums->agregarcubo(album, cuboAlbums->diciembre, atoi(anio.c_str()) , canciones );
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
                        ListaSimple *listaCanciones = new ListaSimple();


                        for(int k = 0; k < cancionesAlbum.size(); k++){
                            json cancion = cancionesAlbum[k];

                            if(validarCancion(cancion)){
                                string nombreCancion = cancion["Name"];
                                string archivoCancion = cancion["File"];
                                string ratingCancion = cancion["Rating"];


                                allSongsList->agregar(nombreArtista, nombreCancion, archivoCancion, ratingCancion);
                                listaCanciones->agregar(nombreCancion, archivoCancion, ratingCancion);
                            }
                        }

                        agregarAlbums(nombreAlbum, mesAlbum, anioAlbum, cuboAlbums, listaCanciones);
                    }
                }
                listaArtistas->replaceChars(nombreArtista, "\"", "");
                listaArtistas->insertarartista(nombreArtista, cuboAlbums);
            }
        }
    }
    reader.close();
}


void CargarPlaylist(){
    string filename = "";

    cout << "Nombre de la playlist: ";
    cin >> filename;

    cout << "Cargando archivo " << filename << endl << endl;
    ifstream reader(filename);

    if (reader.fail()){
        cout << "El archivo no existe, verifique que la ruta y el archivo exista." << endl << endl;
    }else{
        filename = convertir_lower(filename);
        ListaPalabras* splitFilename = split(filename, "playlist_");
        string aux = splitFilename->getPalabra(1);
        ListaPalabras* splitname = split(aux, ".");
        string nombrePlaylist = splitname->getPalabra(0);


        json playlist;
        reader >> playlist;

        string tipo = convertir_lower(playlist["Type"]);
        json canciones = playlist["Songs"];
        Lista *l = new Lista(tipo);

        for(int i = 0; i < canciones.size(); i++){
            json cancion = canciones[i];
            l->agregar(cancion["Artist"], cancion["Song"], cancion["Album"], cancion["Month"], cancion["Year"]);
        }

        arbolPlaylist->agregar(nombrePlaylist, l);

    }
}



