#include <iostream>
#include<stdio.h>
#include <cstdlib>
#include <windows.h>
#include<mmsystem.h>
#include "menu.h"
#include <time.h>
#include <conio.h>


using namespace std;
#define ARRIBA    72
#define IZQUIERDA 75
#define DERECHA   77
#define ABAJO     80
#define ESC		  27

/*
void gotoxy(int x, int y)// fincion que posiciona el cursor en la consola
{
	HANDLE hCon;
	COORD dwPos;

	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}
*/

void pintarMarcoGrande()
{
	//lineas horizontales
	for (int i = 2; i < 118; i++)
	{
		gotoxy(i, 1);
		printf("%c", 205);
	}

	for (int i = 2; i < 118; i++)
	{
		gotoxy(i, 30);
		printf("%c", 205);
	}
	//lineas verticales
	for (int j = 2; j <= 30; j++)
	{
		gotoxy(1, j);
		printf("%c", 186);
	}
	for (int j = 1; j <= 30; j++)
	{
		gotoxy(118, j);
		printf("%c", 186);
	}

	//Esquinas superiores
	gotoxy(1, 1);
	printf("%c", 201);

	gotoxy(118, 1);
	printf("%c", 187);

	//esquinas inferiores
	gotoxy(1, 30);
	printf("%c", 200);

	gotoxy(118, 30);
	printf("%c", 188);

}
void pintarMarcoChico()
{
	//lineas horizontales
	for (int i = 3; i < 116; i++)
	{
		gotoxy(i, 3);
		printf("%c", 205);
	}

	for (int i = 3; i < 116; i++)
	{
		gotoxy(i, 28);
		printf("%c", 205);
	}
	//lineas verticales
	for (int j = 3; j <= 28; j++)
	{
		gotoxy(3, j);
		printf("%c", 186);
	}
	for (int j = 3; j <= 28; j++)
	{
		gotoxy(116, j);
		printf("%c", 186);
	}

	//Esquinas superiores
	gotoxy(3, 3);
	printf("%c", 201);

	gotoxy(116, 3);
	printf("%c", 187);

	//esquinas inferiores
	gotoxy(3, 28);
	printf("%c", 200);

	gotoxy(116, 28);
	printf("%c", 188);


}

void opcion1();
void opcion2();
void opcion3();
void opcionb1();
void opcionb2();

class Rectangulo
{

    private:
    int largo, ancho;

    public: //metodos
    Rectangulo(int,int);//Constructor de la clase
    //metodos:
    //void perimetro();
    //void area();
};



int main(){

    //PlaySound(TEXT("max.wav"),NULL,SND_SYNC);
    int op;
//    Rectangulo base(12,12);

    do{

        system("cls");
        pintarMarcoGrande();
        pintarMarcoChico();
        op = menu(50, 10, "ADIVINO TU NUMERO", "PIENSA UN NUMERO ENTRE EN 1-10", "PIENSA UN NUMERO ENTRE EL 1-100", "EXIT");

        switch(op){

            case 1:
                opcion1();
            break;

            case 2:
                opcion2();
            break;

            case 3:
                opcion3();
            break;
            case 4:
                exit(0);
            break;

        }

    }while(true);

    return 0;
}

void opcion1(){exit(0);}

/*
void opcion2(){
    int op;
    int i;
    int n=5;

    system("cls");

    cout<< "\t\t\t\t\t PIENSA EN UN NUMERO DEL 1 AL 10 " << endl;

    for (i=0; i<=n ;)
    {
    i++;
    cout<<i<<"..........."<<endl;

    }
    cout<<"Lo tienes,......... ---------> EMPEZEMOS";

    op = menu(20, 10, "Opcion B1", "Opcion B2", "Regresar", "Salir");

    switch(op){
        case 1:
            opcionb1();
        break;

        case 2:
            opcionb2();
        break;

        case 4:
            exit(0);
        break;
    }

}
*/

void opcion2()
{
    int op;
    system("cls");





     int resp = 0;
    int num = 0;
    int control = 0;
    char juego;

    do
    {
        srand(time(NULL));
        num=1 + rand() % ((10+1)-1);
        do
        {
            printf("==ADIVINA UN NUMERO ENTRE EL 1 Y EL 100\n");
            printf("==Sabes cual es?\n");
            printf("==Ingrese su respuesta : %d\n",num);
            scanf("%d", &resp);

            if (resp==num)
            {
                system("cls");
                printf("\n Excellente adivinaste el numero\n");
                system("pause");
            }
            else if(resp<num)
            {
                system("cls");
                printf("\nEl numero es mayor que el que intentaste\n");
            }
            else if(resp>num)
            {
                system("cls");
                printf("\nEl numero es menor que el que intentaste\n");
            }
        }while(resp!=num);

        printf("Quieres jugar denuevo (s=si, n=no)");
        scanf("%s",&juego);

        if (juego=='s')
        {
            control=0;
            system("cls");//limpiar pantalla
        }
        else
        {
            control =1;
        }

    }while (control==0);
//    return 0;

   system("cls");
    cout<< endl << endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t TEN EN MENTE TU NUMERO Y ESTE DEBE ENCONTRARSE ENTRE : 1-10"<<endl;
    op= menu(20,20,"love","ly");



    switch(op)
    {
    case 1:
        opcionb1();
        break;
    case 2:
        opcionb2();
        break;
    }
}

void opcion3(){
    system("cls");
    cout << endl << endl <<endl<<endl<<endl<<endl<<endl<< "\t\t\t\t\t\t TEN EN MENTE TU NUMERO Y ESTE DEBE ENCONTRARSE ENTRE : 1-100" << endl << endl;
    system("pause");
}

void opcionb1(){
    system("cls");
    cout << endl << endl << "Estas en la opcion B1" << endl << endl;
    system("pause");
}

void opcionb2(){
    system("cls");
    cout << endl << endl << "Estas en la opcion B2" << endl << endl;
    system("pause");
}


