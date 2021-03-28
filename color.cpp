#include "colorModificador.cpp" // namespace Color
#include <iostream>
#include <string>

/*
         foreground background
black        30         40
red          31         41
green        32         42
yellow       33         43
blue         34         44
magenta      35         45
cyan         36         46
white        37         47
gris       1;30         
fondo serían los mismos sumando 10 (fondo verde: 42, fondo marrón: 43 ...).
*/

using namespace std;
int redond(int num);
int color = 30;
string gris = "\033[1;30;1m";
string gris = "\033[1;30;1m";
int main() {
    //letra;consola
    cout << gris<<"bold red text\033[0m\n";
}

string rama = "=====================";
string tronco="|||||";
string hoja = "()";
int hojas =9;
int ramas = 5;

void EscribirRamas(){

    for (size_t i = 0; i < (redond(ramas)*2); i++)
    {
        for (size_t i = 0; i < (redond(hojas)*2); i++)
        {
            /* code */
        }
        
    }
    
}


int redond(int num){
    if(num%2==0){
        return num/2;
    }else{
        return num/2 +1;
    }
}
