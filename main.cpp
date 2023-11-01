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
void imprimir_articulo (articulo art);
void imprimir_pila (Pila<articulo> a);
int main(int argc, char **argv) {
    clock_t begin;
    cout << "Comenzando a medir Tiempo\n" << endl;
    begin = clock();
    string filename;
    filename= argv[1];
    string linea;
    Pila<articulo > pila;
    int num_depositos =0;
    fstream archivo;
    archivo.open("./" + filename);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        throw 400; // Salir del programa con código de error
    }
    getline(archivo, linea,',');
    getline(archivo, linea,',');
    getline(archivo, linea,',');
    string deposito;

    while (getline(archivo, deposito, ',')) {
        cout << "Depósito: " << deposito << endl; // Imprimir cada depósito

        if (deposito == "\n") {
            break; // Si encuentra un salto de línea, terminar el bucle
        }
        num_depositos++;
    }
    cout<< "num: "<< num_depositos;

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
        }else if (::strcmp(argv[2], "-min_stock" )==0){
            string grupo_anterior;
            while (getline(archivo,linea)){
                articulo a;

                int n = stoi(argv[3]);
                getline(archivo,a.grupo, ',' );
                if (!a.grupo.empty()){
                    grupo_anterior = a.grupo;
                }else{
                    a.grupo = grupo_anterior;
                }
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
                cout << "Listado de artículos con cantidad <= " << n<< " de stock: " << endl;
            }

        }else if (::strcmp(argv[2], "-min_stock_dep" )==0){
            //linea de codigo para este argumento
        }else if (::strcmp(argv[2], "-stock" )==0){
            //linea de codigo para este argumento
        }else if (::strcmp(argv[2], "-stock_dep" )==0){
            //linea de codigo para este argumento
        }else if (::strcmp(argv[2], "-max_stock" )==0){
            //linea de codigo para este argumento
        }else {
            cout <<" No ingresó un parámetro correcto"<<endl;
        }
    clock_t end = clock();

    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;

    cout << "Tiempo transcurrido: " << elapsed_secs << "\n" << std::endl;

    return 0;
}
void imprimir_articulo (articulo art){
    int i = 1;
    cout<< "\nGrupo: "<<art.grupo<<endl;
    cout << "Codigo de barras: "<< art.cod_barras<<endl;
    cout<< "Nombre del articulo: "<< art.nom_articulo<<endl;
    while (!art.depositos.esVacia()){
        cout<<"Deposito nro "<<i<< ": "<<art.depositos.desencolar();
        i++;
    }
}
void imprimir_pila (Pila<articulo> a){
    articulo art;
    while (!a.esVacia()){
        art= a.pop();
        imprimir_articulo(art);
    }
}
