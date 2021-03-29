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
#include "tronco.cpp"

class CreadorArbol{
    public:
    static list<Tronco> arboles;
    CreadorArbol(int a);
    void crearTronco(string identificador);
    void destruirTronco(int tronco);
    int buscarIdProcesoIndice();
};

CreadorArbol:: CreadorArbol(int a){

}

void CreadorArbol::crearTronco(string identificador)
{
    int pid;
    int status=0;
    char *path = "./tronco";

	pid = fork();

	if ( pid == 0 ) {
		printf( "hijo Creado  del padre %d\n", (int)getpid() );
        Tronco nuevo(0,getpid(), identificador);
        arboles.push_back(nuevo);
        nuevo.pintarTronco();
	} else {
        printf("Mi PID es el %d y he creado un proceso hijo cuyo pid es %d\n", getppid(),pid);
        wait(&status);
	}
    
}
/*
int  CreadorArbol:: buscarIdProcesoIndice(Arbol arbol){
    
    auto Iterator = arboles.begin();
    int i=0;
    do
    {
        auto salta = std::next(Iterator, i); 
    } while (TRUE);
    
}
*/

