#include <ctime>
#include <iostream>
#include "cstring"
#include "fstream"
#include "sstream"
#include "HashMap/HashMap.h"

using namespace std;

struct articulo {
    string grupo;
    string cod_barras;
    string nom_articulo;
    string depositos [5];
};
unsigned int Hash_fun(std::string clave) {
    unsigned int hash = 0;

    for (char c : clave) {
        hash += static_cast<unsigned int>(c);
    }
    // Multiplicar por un número primo grande para distribuir más
    return hash * 2654435761;
}

int main(int argc, char **argv) {
    clock_t begin;
    cout << "Comenzando a medir Tiempo\n" << endl;
    begin = clock();
    string filename;
    filename= argv[1];
    string linea;
    fstream archivo;
    archivo.open("./" + filename);
    getline(archivo, linea);

        string opcion;
        if (::strcmp(argv[2], "-total_art_dif" )==0){
            while (getline(archivo,linea)){
                articulo a;
                getline(archivo,a.grupo, ',' );
                getline(archivo,a.cod_barras, ',' );
                getline(archivo,a.nom_articulo, ',' );
                getline(archivo,a.depositos[0], ',' );
                getline(archivo,a.depositos[1], ',' );
                getline(archivo,a.depositos[2], ',' );
                getline(archivo,a.depositos[3], ',' );
                getline(archivo,a.depositos[4], ',' );
                //guardar en pila
            }
            //linea de codigo para este argumento
        }else if (::strcmp(argv[2], "-total_art" )==0){
            //linea de codigo para este argumento
        }else if (::strcmp(argv[2], "-min_stock" )==0){
            //linea de codigo para este argumento
        }else if (::strcmp(argv[2], "-min_stock_dep" )==0){
            //linea de codigo para este argumento
        }else if (::strcmp(argv[2], "-stock" )==0){
            //linea de codigo para este argumento
        }else if (::strcmp(argv[2], "-stock_dep" )==0){
            //linea de codigo para este argumento
        }else if (::strcmp(argv[2], "-max_stock" )==0){
            //linea de codigo para este argumento
        }
    clock_t end = clock();

    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;

    cout << "Tiempo transcurrido: " << elapsed_secs << "\n" << std::endl;

    return 0;
}
