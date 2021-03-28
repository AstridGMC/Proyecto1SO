#include"hoja.cpp"

using namespace std;
#include </usr/include/gtk-3.0/gtk/gtk.h>
#include <string.h>
#include </usr/include/gtk-3.0/gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <list>
#include <regex>
#include <sstream>
#include <sys/wait.h>

class Rama{
    int pid;
    int pidPadre;
    list<Hoja> hojas;
    int numHojas;
    Rama(int numeroHojas);
    void crearHojas(int num);
    void destruirHojas(int num);
    void dividirHojas(int num);
    void imprimirRama();
};

Rama:: Rama (int numeroHojas){
    numHojas = numeroHojas;
}

void Rama:: crearHojas(int num){
    for (size_t i = 0; i < num; i++)
    {
        /* code */
    }
    
}
void Rama:: destruirHojas(int num){
    int resta = numHojas-num;
    if(resta>=0){
        for (size_t i = 0; i < resta; i++)
        {
            /* code */
        }
        numHojas = resta;
    }
    
}

void Rama:: dividirHojas(int numero){
    int fork1 = fork();
    switch (fork1)
    {
    case 0:
        /* hijo */

        break;
    case -1:
        /* error */

        break;
    default:
        //padre

        break;
    }
}

void Rama:: imprimirRama(){ 
    int i = 0;
    while (true)
    {
        //cambiar color verde Cafe
        if(i==0){
            //verde
            i=2;

        }else{
            //cafe
            i=0;

        }
    }
}