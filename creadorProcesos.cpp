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

static list<int> arboles;


int crearTronco(char *argv[])
{
    int pid;
    int status=0;
    char *path = "./tronco";
	pid = fork();

	if ( pid == 0 ) {
        strcpy(argv[0], "tronco");
		printf( "hijo Creado  del padre %d\n", (int)getpid() );
        if (execvp(path, argv) < 0) {
            cout<<"error al ejecutar programa del hijo";
            exit(1);
        };
	} else {
        arboles.push_back(pid);
        printf("Mi PID es el %d y he creado un proceso hijo cuyo pid es %d\n", getppid(),pid);
        wait(&status);
        printf("\n El proceso hijo finalizo con el estado %d\n\n",status);
	}
	return 0;
}

