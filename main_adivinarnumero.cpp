#include<stdio.h>
#include<windows.h>
#include<time.h>

using namespace std;

int main()
{
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

    return 0;
}
