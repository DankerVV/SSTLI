//  main.cpp
//  Programa-STLI
//  Created by Carlos Salcido on 27/10/22.
#include<stdlib.h>
#include<time.h>
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

void hola();
void lectura();
void escribir();
void mostrar_todo();
void mostrar_lineas();
void first_read();
void arreglar_contloc();
void buscar_etiquetas();
void mostrar_etiquetas();
void second_read();

int main(){
    lectura();
    first_read();
    buscar_etiquetas();
    mostrar_etiquetas();
    second_read();
    escribir();
    return 0;
}
