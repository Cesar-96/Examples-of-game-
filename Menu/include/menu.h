#include <iostream>
#include <conio.h>
#include <windows.h>  // Libreria para que sirva la funcion gotoxy();
#include<mmsystem.h>

using namespace std;

void gotoxy(int x,int y){  // Funcion para mover el cursor
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}

void ocultaCursor(bool boleano){
    CONSOLE_CURSOR_INFO cci = {100, boleano}; // El segundo miembro de la estructura indica si se muestra el cursor o no.

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

int menu(int x, int y, string a, string b, string c, string d, string e){
    int cant, tempy;  // Vareable donde se almacenara el valor inicial de y
    char tecla;  // Aqui se almacenara las flechas o el enter
    bool aux = true;  // Para que se ejecute el ciclo

    ocultaCursor(false);
    cant = 5;

    if(x < 0)  // Por si dan una cordenada no valida
        x = 0;

    if(y < 0)  // Por si dan una cordenada no valida
        y = 0;

    tempy = y;

    cant -= 1;  // Para que se pueda dar la aritmetica y comienze desde 0

    gotoxy(x, y);
    cout << char(196) << char(196) << ">";  // Imprime la flecha en la cordenada que se le dio
    gotoxy(x + 5, y);  // Todo lo de aqui abajo es para imprimir las opciones del menu
    cout << "   " << a;
    gotoxy(x, y + 1);
    cout << "     " << b;
    gotoxy(x, y + 2);
    cout << "     " << c;
    gotoxy(x, y + 3);
    cout << "     " << d;
    gotoxy(x, y + 4);
    cout << "     " << e;

    do{
        tecla = getch();  // Obtener la tecla que se presiono

        if(tecla == -32){  // Si da -32 significa que ha apretado una tecla de direccion
            gotoxy(x, y);  // Se borra la flecha
            cout << "   ";
            tecla = getch();  // Se queda en el buffer otro numero que indica que tecla de direccion se presiono

            if(tecla == 72){ //Arriba

                if(y == tempy){  // Si la flecha llega a la primera opcion se baja a la ultima obcion
                    y = cant + tempy;
                }
                else{
                    y--;  // Se le disminuye una unidad a y para que suba la flecha
                }

            }
            else if(tecla == 80){ // Abajo

                if(y == cant + tempy){  // Si la flecha llega a la ultima opcion se sube a la primera obcion
                    y = tempy;
                }
                else{
                    y++;  // Se le aumenta una unidad a y para que baje la flecha
                }

            }
            gotoxy(x, y);  // Se posiciona en el lugar correcto dependiendo de que tecla apreto
            cout << char(196) << char(196) << ">";  // Se imprime la flecha en el lugar correcto

            switch (y - tempy + 1){  // Para que este dentro de las opciones 1, 2, 3......10
                case 1:
                    gotoxy(x + 5, tempy);  // Se imprime la opcion 1 con 8 espacios (5 del 1er argumento y 3 en el cout)
                    cout << "   " << a;
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";  // Los ultimos espacios son para que se borren las opciones anteriormente tabuladoas
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                break;

                case 2:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x + 5, tempy + 1);
                    cout << "   " << b;
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                break;

                case 3:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x + 5, tempy + 2);
                    cout << "   " << c;
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                break;

                case 4:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x + 5, tempy + 3);
                    cout << "   " << d;
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                break;

                case 5:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x + 5, tempy + 4);
                    cout << "   " << e;
                break;
            }

        }
        else if(tecla == 13){  // Para ver si se presiono enter
            aux = false;
        }
    }while(aux);

    ocultaCursor(true);

    return y - tempy + 1;  // Retorna el valor de la opcion seleccionada
}

int menu(int x, int y, string a, string b, string c, string d){
    int cant, tempy;  // Vareable donde se almacenara el valor inicial de y
    char tecla;  // Aqui se almacenara las flechas o el enter
    bool aux = true;  // Para que se ejecute el ciclo

    ocultaCursor(false);
    cant = 4;  /*Poner cantidad de opciones*/

    if(x < 0)  // Por si dan una cordenada no valida
        x = 0;

    if(y < 0)  // Por si dan una cordenada no valida
        y = 0;

    tempy = y;

    cant -= 1;  // Para que se pueda dar la aritmetica y comienze desde 0

    gotoxy(x, y);
    cout << char(196) << char(196) << ">";  // Imprime la flecha en la cordenada que se le dio
    gotoxy(x + 5, y);  // Todo lo de aqui abajo es para imprimir las opciones del menu
    cout << "   " << a;
    gotoxy(x, y + 1);
    cout << "     " << b;
    gotoxy(x, y + 2);
    cout << "     " << c;
    gotoxy(x, y + 3);
    cout << "     " << d;

    do{
        tecla = getch();  // Obtener la tecla que se presiono

        if(tecla == -32){  // Si da -32 significa que ha apretado una tecla de direccion
            gotoxy(x, y);  // Se borra la flecha
            cout << "   ";
            tecla = getch();  // Se queda en el buffer otro numero que indica que tecla de direccion se presiono

            if(tecla == 72){ //Arriba

                if(y == tempy){  // Si la flecha llega a la primera opcion se baja a la ultima obcion
                    y = cant + tempy;
                }
                else{
                    y--;  // Se le disminuye una unidad a y para que suba la flecha
                }

            }
            else if(tecla == 80){ // Abajo

                if(y == cant + tempy){  // Si la flecha llega a la ultima opcion se sube a la primera obcion
                    y = tempy;
                }
                else{
                    y++;  // Se le aumenta una unidad a y para que baje la flecha
                }

            }
            gotoxy(x, y);  // Se posiciona en el lugar correcto dependiendo de que tecla apreto
            cout << char(196) << char(196) << ">";  // Se imprime la flecha en el lugar correcto

            switch (y - tempy + 1){  // Para que este dentro de las opciones 1, 2, 3......10
                case 1:
                    gotoxy(x + 5, tempy);  // Se imprime la opcion 1 con 8 espacios (5 del 1er argumento y 3 en el cout)
                    cout << "   " << a;
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";  // Los ultimos espacios son para que se borren las opciones anteriormente tabuladoas
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                break;

                case 2:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x + 5, tempy + 1);
                    cout << "   " << b;
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                break;

                case 3:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x + 5, tempy + 2);
                    cout << "   " << c;
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                break;

                case 4:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x + 5, tempy + 3);
                    cout << "   " << d;
                break;
            }

        }
        else if(tecla == 13){  // Para ver si se presiono enter
            aux = false;
        }
    }while(aux);

    ocultaCursor(true);

    return y - tempy + 1;  // Retorna el valor de la opcion seleccionada
}

int menu(int x, int y, string a, string b, string c){
    int cant, tempy;  // Vareable donde se almacenara el valor inicial de y
    char tecla;  // Aqui se almacenara las flechas o el enter
    bool aux = true;  // Para que se ejecute el ciclo

    ocultaCursor(false);
    cant = 3;  /*Poner cantidad de opciones*/

    if(x < 0)  // Por si dan una cordenada no valida
        x = 0;

    if(y < 0)  // Por si dan una cordenada no valida
        y = 0;

    tempy = y;

    cant -= 1;  // Para que se pueda dar la aritmetica y comienze desde 0

    gotoxy(x, y);
    cout << char(196) << char(196) << ">";  // Imprime la flecha en la cordenada que se le dio
    gotoxy(x + 5, y);  // Todo lo de aqui abajo es para imprimir las opciones del menu
    cout << "   " << a;
    gotoxy(x, y + 1);
    cout << "     " << b;
    gotoxy(x, y + 2);
    cout << "     " << c;

    do{
        tecla = getch();  // Obtener la tecla que se presiono

        if(tecla == -32){  // Si da -32 significa que ha apretado una tecla de direccion
            gotoxy(x, y);  // Se borra la flecha
            cout << "   ";
            tecla = getch();  // Se queda en el buffer otro numero que indica que tecla de direccion se presiono

            if(tecla == 72){ //Arriba

                if(y == tempy){  // Si la flecha llega a la primera opcion se baja a la ultima obcion
                    y = cant + tempy;
                }
                else{
                    y--;  // Se le disminuye una unidad a y para que suba la flecha
                }

            }
            else if(tecla == 80){ // Abajo

                if(y == cant + tempy){  // Si la flecha llega a la ultima opcion se sube a la primera obcion
                    y = tempy;
                }
                else{
                    y++;  // Se le aumenta una unidad a y para que baje la flecha
                }

            }
            gotoxy(x, y);  // Se posiciona en el lugar correcto dependiendo de que tecla apreto
            cout << char(196) << char(196) << ">";  // Se imprime la flecha en el lugar correcto

            switch (y - tempy + 1){  // Para que este dentro de las opciones 1, 2, 3......10
                case 1:
                    gotoxy(x + 5, tempy);  // Se imprime la opcion 1 con 8 espacios (5 del 1er argumento y 3 en el cout)
                    cout << "   " << a;
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";  // Los ultimos espacios son para que se borren las opciones anteriormente tabuladoas
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                break;

                case 2:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x + 5, tempy + 1);
                    cout << "   " << b;
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                break;

                case 3:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x + 5, tempy + 2);
                    cout << "   " << c;
                break;
            }
        }
        else if(tecla == 13){  // Para ver si se presiono enter
            aux = false;
        }
    }while(aux);

    ocultaCursor(true);

    return y - tempy + 1;  // Retorna el valor de la opcion seleccionada
}

int menu(int x, int y, string a, string b){
    int cant, tempy;  // Vareable donde se almacenara el valor inicial de y
    char tecla;  // Aqui se almacenara las flechas o el enter
    bool aux = true;  // Para que se ejecute el ciclo

    ocultaCursor(false);
    cant = 2;  /*Poner cantidad de opciones*/

    if(x < 0)  // Por si dan una cordenada no valida
        x = 0;

    if(y < 0)  // Por si dan una cordenada no valida
        y = 0;

    tempy = y;

    cant -= 1;  // Para que se pueda dar la aritmetica y comienze desde 0

    gotoxy(x, y);
    cout << char(196) << char(196) << ">";  // Imprime la flecha en la cordenada que se le dio
    gotoxy(x + 5, y);  // Todo lo de aqui abajo es para imprimir las opciones del menu
    cout << "   " << a;
    gotoxy(x, y + 1);
    cout << "     " << b;

    do{
        tecla = getch();  // Obtener la tecla que se presiono

        if(tecla == -32){  // Si da -32 significa que ha apretado una tecla de direccion
            gotoxy(x, y);  // Se borra la flecha
            cout << "   ";
            tecla = getch();  // Se queda en el buffer otro numero que indica que tecla de direccion se presiono

            if(tecla == 72){ //Arriba

                if(y == tempy){  // Si la flecha llega a la primera opcion se baja a la ultima obcion
                    y = cant + tempy;
                }
                else{
                    y--;  // Se le disminuye una unidad a y para que suba la flecha
                }

            }
            else if(tecla == 80){ // Abajo

                if(y == cant + tempy){  // Si la flecha llega a la ultima opcion se sube a la primera obcion
                    y = tempy;
                }
                else{
                    y++;  // Se le aumenta una unidad a y para que baje la flecha
                }

            }
            gotoxy(x, y);  // Se posiciona en el lugar correcto dependiendo de que tecla apreto
            cout << char(196) << char(196) << ">";  // Se imprime la flecha en el lugar correcto

            switch (y - tempy + 1){  // Para que este dentro de las opciones 1, 2, 3......10
                case 1:
                    gotoxy(x + 5, tempy);  // Se imprime la opcion 1 con 8 espacios (5 del 1er argumento y 3 en el cout)
                    cout << "   " << a;
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";  // Los ultimos espacios son para que se borren las opciones anteriormente tabuladoas
                break;

                case 2:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x + 5, tempy + 1);
                    cout << "   " << b;
                break;
            }
        }
        else if(tecla == 13){  // Para ver si se presiono enter
            aux = false;
        }
    }while(aux);

    ocultaCursor(true);

    return y - tempy + 1;  // Retorna el valor de la opcion seleccionada
}

int menu(int x, int y, string a, string b, string c, string d, string e, string f){
    int cant, tempy;  // Vareable donde se almacenara el valor inicial de y
    char tecla;  // Aqui se almacenara las flechas o el enter
    bool aux = true;  // Para que se ejecute el ciclo

    ocultaCursor(false);
    cant = 6;  /*Poner cantidad de opciones*/

    if(x < 0)  // Por si dan una cordenada no valida
        x = 0;

    if(y < 0)  // Por si dan una cordenada no valida
        y = 0;

    tempy = y;

    cant -= 1;  // Para que se pueda dar la aritmetica y comienze desde 0

    gotoxy(x, y);
    cout << char(196) << char(196) << ">";  // Imprime la flecha en la cordenada que se le dio
    gotoxy(x + 5, y);  // Todo lo de aqui abajo es para imprimir las opciones del menu
    cout << "   " << a;
    gotoxy(x, y + 1);
    cout << "     " << b;
    gotoxy(x, y + 2);
    cout << "     " << c;
    gotoxy(x, y + 3);
    cout << "     " << d;
    gotoxy(x, y + 4);
    cout << "     " << e;
    gotoxy(x, y + 5);
    cout << "     " << f;

    do{
        tecla = getch();  // Obtener la tecla que se presiono

        if(tecla == -32){  // Si da -32 significa que ha apretado una tecla de direccion
            gotoxy(x, y);  // Se borra la flecha
            cout << "   ";
            tecla = getch();  // Se queda en el buffer otro numero que indica que tecla de direccion se presiono

            if(tecla == 72){ //Arriba

                if(y == tempy){  // Si la flecha llega a la primera opcion se baja a la ultima obcion
                    y = cant + tempy;
                }
                else{
                    y--;  // Se le disminuye una unidad a y para que suba la flecha
                }

            }
            else if(tecla == 80){ // Abajo

                if(y == cant + tempy){  // Si la flecha llega a la ultima opcion se sube a la primera obcion
                    y = tempy;
                }
                else{
                    y++;  // Se le aumenta una unidad a y para que baje la flecha
                }

            }
            gotoxy(x, y);  // Se posiciona en el lugar correcto dependiendo de que tecla apreto
            cout << char(196) << char(196) << ">";  // Se imprime la flecha en el lugar correcto

            switch (y - tempy + 1){  // Para que este dentro de las opciones 1, 2, 3......10
                case 1:
                    gotoxy(x + 5, tempy);  // Se imprime la opcion 1 con 8 espacios (5 del 1er argumento y 3 en el cout)
                    cout << "   " << a;
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";  // Los ultimos espacios son para que se borren las opciones anteriormente tabuladoas
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                break;

                case 2:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x + 5, tempy + 1);
                    cout << "   " << b;
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                break;

                case 3:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x + 5, tempy + 2);
                    cout << "   " << c;
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                break;

                case 4:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x + 5, tempy + 3);
                    cout << "   " << d;
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                break;

                case 5:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x + 5, tempy + 4);
                    cout << "   " << e;
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                break;

                case 6:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x + 5, tempy + 5);
                    cout << "   " << f;
                break;
            }

        }
        else if(tecla == 13){  // Para ver si se presiono enter
            aux = false;
        }
    }while(aux);

    ocultaCursor(true);

    return y - tempy + 1;  // Retorna el valor de la opcion seleccionada
}

int menu(int x, int y, string a, string b, string c, string d, string e, string f, string g){
    int cant, tempy;  // Vareable donde se almacenara el valor inicial de y
    char tecla;  // Aqui se almacenara las flechas o el enter
    bool aux = true;  // Para que se ejecute el ciclo

    ocultaCursor(false);
    cant = 7;  /*Poner cantidad de opciones*/

    if(x < 0)  // Por si dan una cordenada no valida
        x = 0;

    if(y < 0)  // Por si dan una cordenada no valida
        y = 0;

    tempy = y;

    cant -= 1;  // Para que se pueda dar la aritmetica y comienze desde 0

    gotoxy(x, y);
    cout << char(196) << char(196) << ">";  // Imprime la flecha en la cordenada que se le dio
    gotoxy(x + 5, y);  // Todo lo de aqui abajo es para imprimir las opciones del menu
    cout << "   " << a;
    gotoxy(x, y + 1);
    cout << "     " << b;
    gotoxy(x, y + 2);
    cout << "     " << c;
    gotoxy(x, y + 3);
    cout << "     " << d;
    gotoxy(x, y + 4);
    cout << "     " << e;
    gotoxy(x, y + 5);
    cout << "     " << f;
    gotoxy(x, y + 6);
    cout << "     " << g;

    do{
        tecla = getch();  // Obtener la tecla que se presiono

        if(tecla == -32){  // Si da -32 significa que ha apretado una tecla de direccion
            gotoxy(x, y);  // Se borra la flecha
            cout << "   ";
            tecla = getch();  // Se queda en el buffer otro numero que indica que tecla de direccion se presiono

            if(tecla == 72){ //Arriba

                if(y == tempy){  // Si la flecha llega a la primera opcion se baja a la ultima obcion
                    y = cant + tempy;
                }
                else{
                    y--;  // Se le disminuye una unidad a y para que suba la flecha
                }

            }
            else if(tecla == 80){ // Abajo

                if(y == cant + tempy){  // Si la flecha llega a la ultima opcion se sube a la primera obcion
                    y = tempy;
                }
                else{
                    y++;  // Se le aumenta una unidad a y para que baje la flecha
                }

            }
            gotoxy(x, y);  // Se posiciona en el lugar correcto dependiendo de que tecla apreto
            cout << char(196) << char(196) << ">";  // Se imprime la flecha en el lugar correcto

            switch (y - tempy + 1){  // Para que este dentro de las opciones 1, 2, 3......10
                case 1:
                    gotoxy(x + 5, tempy);  // Se imprime la opcion 1 con 8 espacios (5 del 1er argumento y 3 en el cout)
                    cout << "   " << a;
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";  // Los ultimos espacios son para que se borren las opciones anteriormente tabuladoas
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                break;

                case 2:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x + 5, tempy + 1);
                    cout << "   " << b;
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                break;

                case 3:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x + 5, tempy + 2);
                    cout << "   " << c;
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                break;

                case 4:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x + 5, tempy + 3);
                    cout << "   " << d;
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                break;

                case 5:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x + 5, tempy + 4);
                    cout << "   " << e;
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                break;

                case 6:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x + 5, tempy + 5);
                    cout << "   " << f;
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                break;

                case 7:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x + 5, tempy + 6);
                    cout << "   " << g;
                break;
            }

        }
        else if(tecla == 13){  // Para ver si se presiono enter
            aux = false;
        }
    }while(aux);

    ocultaCursor(true);

    return y - tempy + 1;  // Retorna el valor de la opcion seleccionada
}

int menu(int x, int y, string a, string b, string c, string d, string e, string f, string g, string h){
    int cant, tempy;  // Vareable donde se almacenara el valor inicial de y
    char tecla;  // Aqui se almacenara las flechas o el enter
    bool aux = true;  // Para que se ejecute el ciclo

    ocultaCursor(false);
    cant = 8;  /*Poner cantidad de opciones*/

    if(x < 0)  // Por si dan una cordenada no valida
        x = 0;

    if(y < 0)  // Por si dan una cordenada no valida
        y = 0;

    tempy = y;

    cant -= 1;  // Para que se pueda dar la aritmetica y comienze desde 0

    gotoxy(x, y);
    cout << char(196) << char(196) << ">";  // Imprime la flecha en la cordenada que se le dio
    gotoxy(x + 5, y);  // Todo lo de aqui abajo es para imprimir las opciones del menu
    cout << "   " << a;
    gotoxy(x, y + 1);
    cout << "     " << b;
    gotoxy(x, y + 2);
    cout << "     " << c;
    gotoxy(x, y + 3);
    cout << "     " << d;
    gotoxy(x, y + 4);
    cout << "     " << e;
    gotoxy(x, y + 5);
    cout << "     " << f;
    gotoxy(x, y + 6);
    cout << "     " << g;
    gotoxy(x, y + 7);
    cout << "     " << h;

    do{
        tecla = getch();  // Obtener la tecla que se presiono

        if(tecla == -32){  // Si da -32 significa que ha apretado una tecla de direccion
            gotoxy(x, y);  // Se borra la flecha
            cout << "   ";
            tecla = getch();  // Se queda en el buffer otro numero que indica que tecla de direccion se presiono

            if(tecla == 72){ //Arriba

                if(y == tempy){  // Si la flecha llega a la primera opcion se baja a la ultima obcion
                    y = cant + tempy;
                }
                else{
                    y--;  // Se le disminuye una unidad a y para que suba la flecha
                }

            }
            else if(tecla == 80){ // Abajo

                if(y == cant + tempy){  // Si la flecha llega a la ultima opcion se sube a la primera obcion
                    y = tempy;
                }
                else{
                    y++;  // Se le aumenta una unidad a y para que baje la flecha
                }

            }
            gotoxy(x, y);  // Se posiciona en el lugar correcto dependiendo de que tecla apreto
            cout << char(196) << char(196) << ">";  // Se imprime la flecha en el lugar correcto

            switch (y - tempy + 1){  // Para que este dentro de las opciones 1, 2, 3......10
                case 1:
                    gotoxy(x + 5, tempy);  // Se imprime la opcion 1 con 8 espacios (5 del 1er argumento y 3 en el cout)
                    cout << "   " << a;
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";  // Los ultimos espacios son para que se borren las opciones anteriormente tabuladoas
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                break;

                case 2:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x + 5, tempy + 1);
                    cout << "   " << b;
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                break;

                case 3:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x + 5, tempy + 2);
                    cout << "   " << c;
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                break;

                case 4:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x + 5, tempy + 3);
                    cout << "   " << d;
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                break;

                case 5:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x + 5, tempy + 4);
                    cout << "   " << e;
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                break;

                case 6:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x + 5, tempy + 5);
                    cout << "   " << f;
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                break;

                case 7:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x + 5, tempy + 6);
                    cout << "   " << g;
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                break;

                case 8:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x + 5, tempy + 7);
                    cout << "   " << h;
                break;
            }

        }
        else if(tecla == 13){  // Para ver si se presiono enter
            aux = false;
        }
    }while(aux);

    ocultaCursor(true);

    return y - tempy + 1;  // Retorna el valor de la opcion seleccionada
}

int menu(int x, int y, string a, string b, string c, string d, string e, string f, string g, string h, string i){
    int cant, tempy;  // Vareable donde se almacenara el valor inicial de y
    char tecla;  // Aqui se almacenara las flechas o el enter
    bool aux = true;  // Para que se ejecute el ciclo

    ocultaCursor(false);
    cant = 9;  /*Poner cantidad de opciones*/

    if(x < 0)  // Por si dan una cordenada no valida
        x = 0;

    if(y < 0)  // Por si dan una cordenada no valida
        y = 0;

    tempy = y;

    cant -= 1;  // Para que se pueda dar la aritmetica y comienze desde 0

    gotoxy(x, y);
    cout << char(196) << char(196) << ">";  // Imprime la flecha en la cordenada que se le dio
    gotoxy(x + 5, y);  // Todo lo de aqui abajo es para imprimir las opciones del menu
    cout << "   " << a;
    gotoxy(x, y + 1);
    cout << "     " << b;
    gotoxy(x, y + 2);
    cout << "     " << c;
    gotoxy(x, y + 3);
    cout << "     " << d;
    gotoxy(x, y + 4);
    cout << "     " << e;
    gotoxy(x, y + 5);
    cout << "     " << f;
    gotoxy(x, y + 6);
    cout << "     " << g;
    gotoxy(x, y + 7);
    cout << "     " << h;
    gotoxy(x, y + 8);
    cout << "     " << i;

    do{
        tecla = getch();  // Obtener la tecla que se presiono

        if(tecla == -32){  // Si da -32 significa que ha apretado una tecla de direccion
            gotoxy(x, y);  // Se borra la flecha
            cout << "   ";
            tecla = getch();  // Se queda en el buffer otro numero que indica que tecla de direccion se presiono

            if(tecla == 72){ //Arriba

                if(y == tempy){  // Si la flecha llega a la primera opcion se baja a la ultima obcion
                    y = cant + tempy;
                }
                else{
                    y--;  // Se le disminuye una unidad a y para que suba la flecha
                }

            }
            else if(tecla == 80){ // Abajo

                if(y == cant + tempy){  // Si la flecha llega a la ultima opcion se sube a la primera obcion
                    y = tempy;
                }
                else{
                    y++;  // Se le aumenta una unidad a y para que baje la flecha
                }

            }
            gotoxy(x, y);  // Se posiciona en el lugar correcto dependiendo de que tecla apreto
            cout << char(196) << char(196) << ">";  // Se imprime la flecha en el lugar correcto

            switch (y - tempy + 1){  // Para que este dentro de las opciones 1, 2, 3......10
                case 1:
                    gotoxy(x + 5, tempy);  // Se imprime la opcion 1 con 8 espacios (5 del 1er argumento y 3 en el cout)
                    cout << "   " << a;
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";  // Los ultimos espacios son para que se borren las opciones anteriormente tabuladoas
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                    gotoxy(x, tempy + 8);
                    cout << "     " << i << "   ";

                break;

                case 2:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x + 5, tempy + 1);
                    cout << "   " << b;
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                    gotoxy(x, tempy + 8);
                    cout << "     " << i << "   ";
                break;

                case 3:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x + 5, tempy + 2);
                    cout << "   " << c;
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                    gotoxy(x, tempy + 8);
                    cout << "     " << i << "   ";
                break;

                case 4:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x + 5, tempy + 3);
                    cout << "   " << d;
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                    gotoxy(x, tempy + 8);
                    cout << "     " << i << "   ";
                break;

                case 5:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x + 5, tempy + 4);
                    cout << "   " << e;
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                    gotoxy(x, tempy + 8);
                    cout << "     " << i << "   ";
                break;

                case 6:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x + 5, tempy + 5);
                    cout << "   " << f;
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                    gotoxy(x, tempy + 8);
                    cout << "     " << i << "   ";
                break;

                case 7:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x + 5, tempy + 6);
                    cout << "   " << g;
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                    gotoxy(x, tempy + 8);
                    cout << "     " << i << "   ";
                break;

                case 8:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x + 5, tempy + 7);
                    cout << "   " << h;
                    gotoxy(x, tempy + 8);
                    cout << "     " << i << "   ";
                break;

                case 9:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                    gotoxy(x + 5, tempy + 8);
                    cout << "   " << i;
                break;
            }

        }
        else if(tecla == 13){  // Para ver si se presiono enter
            aux = false;
        }
    }while(aux);

    ocultaCursor(true);

    return y - tempy + 1;  // Retorna el valor de la opcion seleccionada
}

int menu(int x, int y, string a, string b, string c, string d, string e, string f, string g, string h, string i, string j){
    int cant, tempy;  // Vareable donde se almacenara el valor inicial de y
    char tecla;  // Aqui se almacenara las flechas o el enter
    bool aux = true;  // Para que se ejecute el ciclo

    ocultaCursor(false);
    cant = 10;  /*Poner cantidad de opciones*/

    if(x < 0)  // Por si dan una cordenada no valida
        x = 0;

    if(y < 0)  // Por si dan una cordenada no valida
        y = 0;

    tempy = y;

    cant -= 1;  // Para que se pueda dar la aritmetica y comienze desde 0

    gotoxy(x, y);
    cout << char(196) << char(196) << ">";  // Imprime la flecha en la cordenada que se le dio
    gotoxy(x + 5, y);  // Todo lo de aqui abajo es para imprimir las opciones del menu
    cout << "   " << a;
    gotoxy(x, y + 1);
    cout << "     " << b;
    gotoxy(x, y + 2);
    cout << "     " << c;
    gotoxy(x, y + 3);
    cout << "     " << d;
    gotoxy(x, y + 4);
    cout << "     " << e;
    gotoxy(x, y + 5);
    cout << "     " << f;
    gotoxy(x, y + 6);
    cout << "     " << g;
    gotoxy(x, y + 7);
    cout << "     " << h;
    gotoxy(x, y + 8);
    cout << "     " << i;
    gotoxy(x, y + 9);
    cout << "     " << j;

    do{
        tecla = getch();  // Obtener la tecla que se presiono

        if(tecla == -32){  // Si da -32 significa que ha apretado una tecla de direccion
            gotoxy(x, y);  // Se borra la flecha
            cout << "   ";
            tecla = getch();  // Se queda en el buffer otro numero que indica que tecla de direccion se presiono

            if(tecla == 72){ //Arriba

                if(y == tempy){  // Si la flecha llega a la primera opcion se baja a la ultima obcion
                    y = cant + tempy;
                }
                else{
                    y--;  // Se le disminuye una unidad a y para que suba la flecha
                }

            }
            else if(tecla == 80){ // Abajo

                if(y == cant + tempy){  // Si la flecha llega a la ultima opcion se sube a la primera obcion
                    y = tempy;
                }
                else{
                    y++;  // Se le aumenta una unidad a y para que baje la flecha
                }

            }
            gotoxy(x, y);  // Se posiciona en el lugar correcto dependiendo de que tecla apreto
            cout << char(196) << char(196) << ">";  // Se imprime la flecha en el lugar correcto

            switch (y - tempy + 1){  // Para que este dentro de las opciones 1, 2, 3......10
                case 1:
                    gotoxy(x + 5, tempy);  // Se imprime la opcion 1 con 8 espacios (5 del 1er argumento y 3 en el cout)
                    cout << "   " << a;
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";  // Los ultimos espacios son para que se borren las opciones anteriormente tabuladoas
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                    gotoxy(x, tempy + 8);
                    cout << "     " << i << "   ";
                    gotoxy(x, tempy + 9);
                    cout << "     " << j << "   ";
                break;

                case 2:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x + 5, tempy + 1);
                    cout << "   " << b;
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                    gotoxy(x, tempy + 8);
                    cout << "     " << i << "   ";
                    gotoxy(x, tempy + 9);
                    cout << "     " << j << "   ";
                break;

                case 3:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x + 5, tempy + 2);
                    cout << "   " << c;
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                    gotoxy(x, tempy + 8);
                    cout << "     " << i << "   ";
                    gotoxy(x, tempy + 9);
                    cout << "     " << j << "   ";
                break;

                case 4:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x + 5, tempy + 3);
                    cout << "   " << d;
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                    gotoxy(x, tempy + 8);
                    cout << "     " << i << "   ";
                    gotoxy(x, tempy + 9);
                    cout << "     " << j << "   ";
                break;

                case 5:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x + 5, tempy + 4);
                    cout << "   " << e;
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                    gotoxy(x, tempy + 8);
                    cout << "     " << i << "   ";
                    gotoxy(x, tempy + 9);
                    cout << "     " << j << "   ";
                break;

                case 6:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x + 5, tempy + 5);
                    cout << "   " << f;
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                    gotoxy(x, tempy + 8);
                    cout << "     " << i << "   ";
                    gotoxy(x, tempy + 9);
                    cout << "     " << j << "   ";
                break;

                case 7:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x + 5, tempy + 6);
                    cout << "   " << g;
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                    gotoxy(x, tempy + 8);
                    cout << "     " << i << "   ";
                    gotoxy(x, tempy + 9);
                    cout << "     " << j << "   ";
                break;

                case 8:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x + 5, tempy + 7);
                    cout << "   " << h;
                    gotoxy(x, tempy + 8);
                    cout << "     " << i << "   ";
                    gotoxy(x, tempy + 9);
                    cout << "     " << j << "   ";
                break;

                case 9:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                    gotoxy(x + 5, tempy + 8);
                    cout << "   " << i;
                    gotoxy(x, tempy + 9);
                    cout << "     " << j << "   ";
                break;

                case 10:
                    gotoxy(x, tempy);
                    cout << "     " << a << "   ";
                    gotoxy(x, tempy + 1);
                    cout << "     " << b << "   ";
                    gotoxy(x, tempy + 2);
                    cout << "     " << c << "   ";
                    gotoxy(x, tempy + 3);
                    cout << "     " << d << "   ";
                    gotoxy(x, tempy + 4);
                    cout << "     " << e << "   ";
                    gotoxy(x, tempy + 5);
                    cout << "     " << f << "   ";
                    gotoxy(x, tempy + 6);
                    cout << "     " << g << "   ";
                    gotoxy(x, tempy + 7);
                    cout << "     " << h << "   ";
                    gotoxy(x, tempy + 8);
                    cout << "     " << i << "   ";
                    gotoxy(x + 5, tempy + 9);
                    cout << "   " << j;
                break;
            }

        }
        else if(tecla == 13){  // Para ver si se presiono enter
            aux = false;
        }
    }while(aux);

    ocultaCursor(true);

    return y - tempy + 1;  // Retorna el valor de la opcion seleccionada
}






