#include <ctime>
#include <iostream>
#include "cstring"
#include "fstream"
#include "sstream"
#include "Pila/Pila.h"
#include "Cola/Cola.h"


using namespace std;

struct articulo {
    string grupo;
    string cod_barras;
    string nom_articulo;
    Cola<int> depositos;
};
void imprimir_articulos (Pila<articulo> a, int num);
int main(int argc, char **argv) {
    clock_t begin;
    cout << "Comenzando a medir Tiempo\n" << endl;
    begin = clock();
    string filename;
    filename= argv[1];
    string linea;
    Pila<articulo > pila;
    int num_depositos;
    fstream archivo;
    archivo.open("./" + filename);
    getline(archivo, linea,',');
    getline(archivo, linea,',');
    getline(archivo, linea,',');
    string deposito;

    while (getline(archivo, deposito, ',')) {
        if (deposito == "\n") {
            break; // Si encuentra un salto de línea, terminar el bucle
        }
        num_depositos++;
    }

        if (::strcmp(argv[2], "-total_art_dif" )==0){
            //linea de codigo para este argumento
        }else if (::strcmp(argv[2], "-total_art" )==0){
            articulo a;
            int cant_total_art = 0;
            getline(archivo,a.grupo, ',' );
            getline(archivo,a.cod_barras, ',' );
            getline(archivo,a.nom_articulo, ',' );
            for (int i = 0; i < num_depositos; ++i) {
                getline(archivo,deposito, ',' );
                while (!a.depositos.esVacia()){
                    cant_total_art += a.depositos.desencolar();
                }
            }
            cout << "La cantidad total de articulos es: " << cant_total_art << " articulos." << endl;
            //linea de codigo para este argumento
        }else if (::strcmp(argv[2], "-min_stock" )==0){
            while (getline(archivo,linea)){
                articulo a;
                int n = stoi(argv[3]);
                getline(archivo,a.grupo, ',' );
                getline(archivo,a.cod_barras, ',' );
                getline(archivo,a.nom_articulo, ',' );
                int cant_stock=0;
                for (int i = 0; i < num_depositos; ++i) {
                    getline(archivo,deposito, ',' );
                    if (deposito.empty()){
                        a.depositos.encolar(0);

                    }else {
                        a.depositos.encolar(stoi(deposito));
                        cant_stock += stoi(deposito);
                    }
                }
                if (cant_stock <= n){
                    pila.push(a);
                }
                imprimir_articulos(pila, n);
            }
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
//funcion para imprimir art, usada en argumento -min_stock
void imprimir_articulos (Pila<articulo> a, int num){
    cout << "Listado de artículos con cantidad <= " << num << " de stock: " << endl;
    while (!a.esVacia()){
        cout << a.pop().nom_articulo << endl;
    }
}
