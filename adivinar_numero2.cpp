#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<string>
/**variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;**/ /*Función genérica para que te saque numeros aleatorios dentro de un rango*/
using namespace std;
int main(){
    cout<<"piensa un numero entre el 1 y el 100"<<endl;
    int num;
    int fallos=0;
    string respuesta="no";
    srand(time(NULL)); /*esto es como avisar al ordenador de que vas a utilizar la funcion de números aleatorios*/
    do{
    num=1+rand()%(101-1); /*funcion para que te saque numeros entre 1 y 100*/
    cout<<"El numero que has pensado es este?-->"<<num<<endl;
    cin>>respuesta;
    fallos++;
    }while(respuesta=="no");
    if (respuesta=="si"){
    cout<<"Gane!"<<endl;
    cout<<"He fallado "<<fallos-1<<" veces."<<endl;
    }
    return 0;
}
