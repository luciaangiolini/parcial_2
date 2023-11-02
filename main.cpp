#include <iostream>
#include <ctime>
#include<sstream>
#include <fstream>
#include <vector>
#include <cstring>
#include "./Lista/Lista.h"

using namespace std;

void totalArticulosDiferentes(string fileName){
    fstream fin;
    fin.open("./"+fileName, ios::in);
    string line, palabra;
    int total = -1;
    while(getline(fin,line)){
        total++;
        stringstream s(line);
        getline(s,palabra,';');
        while(getline(s,palabra, ';')){
            if(palabra.find("ERROR")!=std::string::npos )
                total--;
        }
    }
    cout<< "El total de articulos es " << total<< endl;
}
void totalArticulos(string fileName){
    fstream fin;
    fin.open("./"+fileName, ios::in);
    string line, palabra;
    int total=0;
    getline(fin, line);
    while(getline(fin,line)){
        stringstream s(line);
        getline(s,palabra,',');
        getline(s,palabra,',');
        getline(s,palabra,',');
        if(palabra.find("ERROR")!=std::string::npos ){
            while(getline(s,palabra,',')){
                if(palabra.size()<1)
                {
                    palabra="0";
                }
                total -= atoi(palabra.c_str());
            }
        }else{
            while(getline(s,palabra,',')){
                if(palabra.size()<1)
                {
                    palabra="0";
                }
                total += atoi(palabra.c_str());
            }
        }
    }
    cout<< "El total de articulos es " << total << endl;
}
void minStock(string n, string fileName){
    fstream fin;
    fin.open("./"+fileName, ios::in);
    Lista<string> articulos; // lista para que cada fila sea una lista
    string line, palabra, nombreArticulo;
    Lista<int> depositos;
    int i;
    int suma;
    int n2=atoi(n.c_str());
    getline(fin, line);
    while(getline(fin,line)){
        i=0;
        suma=0;
        depositos.vaciar();
        stringstream s(line);
        while(getline(s,palabra,',')){
            i++;
            if(i==3)
                nombreArticulo = palabra;
            if(i>3){
                if (palabra.size()<1)
                    palabra="0";
                depositos.insertarUltimo(atoi(palabra.c_str()));
            }
        }
        for (int j=0; j<depositos.getTamanio(); j++){
            suma+=depositos.getDato(j);
        }
        if(suma<=n2)
            articulos.insertarUltimo(nombreArticulo);
    }
    for (i=0; i<articulos.getTamanio(); i++){
        cout<< articulos.getDato(i)<< endl;
    }
}
void minStockDep(string nDep,string ncant, string fileName){
    fstream fin;
    fin.open("./"+fileName, ios::in);
    Lista<string> articulos;
    string line, palabra, nombre_articulo;
    Lista<int> depositos;
    int n2=atoi(nDep.c_str()), i, n_min=atoi(ncant.c_str());
    getline(fin, line);
    while(getline(fin,line)){
        stringstream s(line);
        getline(s,palabra,',');
        getline(s,palabra,',');
        getline(s,palabra,',');
        nombre_articulo= palabra;
        i=0;
            while(getline(s,palabra,',')){
                i++;
                if (i == n2){
                    if (::atoi(palabra.c_str())<= n_min){
                        articulos.insertarUltimo(nombre_articulo);
                    }
                }

            }
    }
    fin.close();

    cout<<"El listado de articulos con stock menor o igual a " <<ncant << " en el deposito "<< n2<< " es: "<<endl;
    for (int j = 0; j < articulos.getTamanio(); ++j) {
        cout <<"-"<< articulos.getDato(j)<<endl;
    }

}

void stock(string nombreArticulo, string fileName)
{
    fstream fin;
    fin.open("./"+fileName, ios::in);
    Lista<string> articulos; // lista para que cada fila sea una lista
    string line, palabra;
    Lista<int> depositos;
    int suma=0;
    getline(fin, line);
    while(getline(fin,line)){
        stringstream s(line);
        getline(s,palabra,',');
        getline(s,palabra,',');
        getline(s,palabra,',');
        if(palabra==nombreArticulo){
            while(getline(s,palabra,',')){
                 depositos.insertarUltimo(atoi(palabra.c_str()));
            }
            break;
        }
    }
    for (int j=0; j<depositos.getTamanio(); j++){
            suma+=depositos.getDato(j);
        }
    cout<<"El stock de " << nombreArticulo<< " es: "<< suma<<endl;
}
void stockDep(string nombreArticulo, string nDep, string fileName){
    fstream fin;
    fin.open("./"+fileName, ios::in);
    Lista<string> articulos; // lista para que cada fila sea una lista
    string line, palabra;
    Lista<int> depositos;
    int stock, n2=atoi(nDep.c_str()), i=0;
    getline(fin, line);
    while(getline(fin,line)){
        stringstream s(line);
        getline(s,palabra,',');
        getline(s,palabra,',');
        getline(s,palabra,',');
        if(palabra==nombreArticulo){
            while(getline(s,palabra,',')){
                if(palabra.size()<1)
                {
                    palabra="0";
                }
                depositos.insertarUltimo(atoi(palabra.c_str()));
            }
            break;
        }
    }
    fin.close();
    fin.clear();
    fin.open("./"+fileName, ios::in);
    getline(fin,line);
    stringstream s(line);
    getline(s,palabra,',');
    getline(s,palabra,',');
    getline(s,palabra,',');
    while(getline(s,palabra, ','))
        i++;
    if(n2==i && depositos.getTamanio()<i){
        stock=0;
    }
    else
        stock=depositos.getDato(n2-1);
    cout<<"El stock de " << nombreArticulo<< " en el deposito "<< n2<< " es: "<< stock<<endl;
}
void maxStock(string n, string fileName){
    fstream fin;
    fin.open("./"+fileName, ios::in);
    Lista<string> articulos; // lista para que cada fila sea una lista
    string line, palabra, nombreArticulo;
    Lista<int> depositos;
    int i;
    int suma;
    int n2=atoi(n.c_str());
    getline(fin, line);
    while(getline(fin,line)){
        i=0;
        suma=0;
        depositos.vaciar();
        stringstream s(line);
        while(getline(s,palabra,',')){
            i++;
            if(i==3)
                nombreArticulo = palabra;
            if(i>3){
                if (palabra.size()<1)
                    palabra="0";
                depositos.insertarUltimo(atoi(palabra.c_str()));
            }
        }
        for (int j=0; j<depositos.getTamanio(); j++){
            suma+=depositos.getDato(j);
        }
        if(suma>=n2)
            articulos.insertarUltimo(nombreArticulo);
    }
    for (i=0; i<articulos.getTamanio(); i++){
        cout<< articulos.getDato(i)<< endl;
    }

}



int main(int argc, char** argv)
{
    clock_t begin;
    std::cout << "Comenzando a medir Tiempo\n" << endl;
    begin = clock();


        if (strcmp(argv[1], "total_art_dif") == 0)
        {
            totalArticulosDiferentes(argv[2]);
        }
        else if(strcmp(argv[1], "total_art") == 0)
        {
            totalArticulos(argv[2]);
        }
        else if(strcmp(argv[1], "min_stock") == 0 && argc == 5){
            minStockDep(argv[2],argv[3],argv[4]);
        }
        else if(strcmp(argv[1], "stock") == 0 && argc == 4)
        {
            stock(argv[2],argv[3]);
        }
        else if(strcmp(argv[1], "stock")== 0 && argc == 5)
        {
            stockDep(argv[2],argv[3],argv[4]);

        }
        else if(strcmp(argv[1], "max_stock") == 0){
            maxStock(argv[2],argv[3]);
        }
        else if(strcmp(argv[1], "min_stock") == 0){
            minStock(argv[2],argv[3]);
        }

    clock_t end = clock();
    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Tiempo transcurrido: " << elapsed_secs << "\n" << std::endl;
    return 0;
}
