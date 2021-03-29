using namespace std;
#include </usr/include/gtk-3.0/gtk/gtk.h>
#include <string.h>
#include </usr/include/gtk-3.0/gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <list>
#include "creadorProcesos.cpp"
#include <sstream>
#include "rama.cpp"

class Sentencia{
    private:
    string identificador;
    int numeroRamas;
    int numeroHojas;
    void SentenciaSimple(string ident);
    void SentenciaCompuesta(string ident , int ramas, int hojas);

    public:

    Sentencia(string ident);
    Sentencia(string ident, int ramas, int hojas);
    
};

Sentencia:: Sentencia(string ident){
    identificador = ident;
    SentenciaSimple(ident);
}

Sentencia:: Sentencia(string ident, int rama, int hoja){
    identificador = ident;
    this->numeroRamas = rama;
    this->numeroHojas  = hoja;
    SentenciaCompuesta(ident, rama, hoja);
}

void Sentencia:: SentenciaSimple(string identifi){
    CreadorArbol arbol(12);
    arbol.crearTronco(identifi);
}

void Sentencia:: SentenciaCompuesta(string ident, int rama, int hoja){
    
}

