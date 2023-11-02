#include <iostream>
#include <ctime>
#include<sstream>
#include <fstream>
#include <vector>
#include <cstring>
#include "./Lista/Lista.h"

using namespace std;

vector<vector<string>> leerArchivo(string fileName){
    fstream fin;
    fin.open("./"+fileName, ios::in);
    vector<string>row; // lista para que cada fila sea una lista
    string line, palabra;
    vector<vector<string>> data;
    while(getline(fin,line)){
        row.clear();
        stringstream s(line);
        while(getline(s,palabra,';')){
            if(palabra.size()<1)
                palabra = "0";
            row.push_back(palabra);
        }
        data.push_back(row);
    }
    return data;
}
int encontrarPosArticulo(string nombreArticulo, string fileName) // función que devuelve la posición del articulo
{
    fstream fin;
    fin.open("./" + fileName, ios::in);
    vector<string> row;
    vector<vector<string>> data;
    string line, palabra;
    int total=-1;
    while (getline(fin, line))
    {
        total++;
        row.clear();
        stringstream s(line);
        while (getline(s, palabra, ';'))
        {
            if (palabra.size() < 1)
                palabra = "NA";
            row.push_back(palabra);
        }
        data.push_back(row);
    }

    for (int i = 0; i <= total; i++)
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            if (data[i][j] == nombreArticulo)
            {
                return i;
            }

        }
    }
    return 0;
}

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
        while(getline(s,palabra,';')){
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
void minStockDep(string nombreArticulo, string nDep, string fileName){

}

void stock(string nombreArticulo, string fileName)
{
    vector<vector<string>> data;
    data = leerArchivo(fileName);
    int n; // variable para encontrar la posición
    int n2=0;
    n = encontrarPosArticulo(nombreArticulo,fileName); // posición
    Lista<int> depositos;
    for (int j = 3; j < data[n].size(); j++)
    {
        n2 = atoi(data[n][j].c_str()); // convierte la variable a int

        depositos.insertarUltimo(n2);
    }
    int suma=0;
    for (int j = 0; j<depositos.getTamanio(); j++)
    {
        suma+=depositos.getDato(j);
    }
    cout<<"El stock de " << nombreArticulo<< " es: "<< suma<<endl;
}
void stockDep(string nombreArticulo, string nDep, string fileName){
    vector<vector<string>> data;
    Lista<string> stock;
    data = leerArchivo(fileName);
    int n, n2 = 0, nDep2=0;
    nDep2 = atoi(nDep.c_str()); // casting de string a int
    n = encontrarPosArticulo(nombreArticulo, fileName);
    Lista<int> depositos;
    for (int j = 3; j <=data[n].size(); j++)
    {
        n2 = atoi(data[n][j].c_str()); // convierte la variable a int

        depositos.insertarUltimo(n2);
    }

    cout<<"El numero de stock de "<< nombreArticulo<<" del deposito "<< nDep << " es  de "<<depositos.getDato(nDep2-1)<<" articulos"<<endl;


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
        while(getline(s,palabra,';')){
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

    for(int i =0;i<argc;i++){
        if (strcmp(argv[i+1], "total_art_dif") == 0)
        {
            totalArticulosDiferentes(argv[i+2]);
            break;
        }
        else if(strcmp(argv[i+1], "total_art") == 0)
        {
            totalArticulos(argv[i+2]);
            break;
        }
        else if(strcmp(argv[i+1], "min_stock") == 0 && argc == 5){
            minStockDep(argv[i+2],argv[i+3],argv[i+4]);
            break;
        }
        else if(strcmp(argv[i+1], "stock") == 0 && argc == 4)
        {
            stock(argv[i+2],argv[i+3]);
            break;
        }
        else if(strcmp(argv[i+1], "stock")== 0 && argc == 5)
        {
            stockDep(argv[i+2],argv[i+3],argv[i+4]);
            break;

        }
        else if(strcmp(argv[i+1], "max_stock") == 0){
            maxStock(argv[i+2],argv[i+3]);
            break;
        }
        else if(strcmp(argv[i+1], "min_stock") == 0){
            minStock(argv[i+2],argv[i+3]);
            break;
        }

    }
    clock_t end = clock();
    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Tiempo transcurrido: " << elapsed_secs << "\n" << std::endl;
    return 0;
}
