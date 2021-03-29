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
#include "rama.cpp"

class Tronco{
    public:
        int pid;
        int numeroRamas;
        string identificador;
        static list<Rama> ramas;
        int numeroRamas;
        string getIdentificador();
        void crearRamas(int numRamas);
        void destriuirRamas(int numero);
        void dividirRamas(int numRamas);
        void pintarTronco();
        Tronco(int ramas, int pid, string id);
};

string Tronco:: getIdentificador() { 
     return this->identificador; 
}


void Tronco:: crearRamas(int numRamas){
    for (size_t i = 0; i < numRamas; i++)
    {
        dividirRamas(numRamas);
    }
    
}

void Tronco:: destriuirRamas(int numero){
    int resta = numeroRamas-numero;
    if(resta>=0){
        for (size_t i = 0; i < resta; i++)
        {
            /* code */
        }
        numeroRamas = resta;
    }
}

void Tronco:: dividirRamas(int numRamas){
    int fork1 = fork();
    switch (fork1)
    {
    case 0:
        /* hijo ramas*/
        
        break;
    case -1:
        /* error */

        break;
    default:
        //padre tronco

        break;
    }
}

void Tronco:: pintarTronco(){
    //pintar Gris y Negro
    int i = 0;
    while (true)
    {
        //cambiar color verde Cafe
        if(i==0){
            //verde
            i=2;
            cout<<"Verde";
        }else{
            //cafe
            i=0;
            cout<<"Cafe";
        }
    }
}

Tronco::Tronco(int numRamas, int pidD, string id){
    pid= pidD;
    numRamas=numeroRamas;
    id= identificador;
}











/*
int main(int argc, char *argv[])
{
    if(argc==2){
        if(isNumber( argv[1])){
            int numRama = (int) argv[1];
            for (size_t i = 0; i < numRama; i++)
            {
                crearTronco();
            }  
        } 
    }
}

void crearTronco(){
    int pid;
    int status=0;
    char *path = "./rama";
	pid = fork();

	if ( pid == 0 ) {
        char **argv;
        strcpy(argv[0], "rama");
		printf( "hijo Creado  del padre %d\n", (int)getpid() );
        if (execvp(path, argv) < 0) {
            cout<<"error al ejecutar programa del hijo";
            exit(1);
        };
	} else {
        ramas.push_back(pid);
        printf("Mi PID es el %d y he creado una rama cuyo pid es %d\n", getppid(),pid);

        wait(&status);
        printf("\n El proceso rama finalizo con el estado %d\n\n",status);
	}
}

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}*/