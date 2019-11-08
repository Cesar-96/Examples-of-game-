#include <iostream>

using namespace std;


/*
class Persona
{
private:
    string nombre;
    int edad;
public:
    Persona(string,int);//Constructor
    void correr();
    void hablar();
};

//Constructor e inizializa los atributos
Persona::Persona(string _nombre, int _edad)
{
    nombre = _nombre;
    edad = _edad;
}

void Persona::correr()
{
    cout<<"Soy"<<nombre<<" y estoy leyendo y saludandote"<< endl ;
}
void Persona::hablar()
{
cout << "Soy "<<nombre <<" y te dire mi edad " << edad;
}

int main()
{
    Persona p1 = Persona("Pablo",23);
    p1.correr();
    p1.hablar();
    cout << endl;

    Persona p2 ("Angela",20);
    p2.hablar();

    return 0;
}

*/

/*
class Pared
{
private:
    float largo, ancho;//Atributos
public: //metodos
    Pared(float,float);//Constructor de la clase
    //metodos:
    void perimetro();
    void area();
};

Pared::Pared(float _largo, float _ancho)
{
    largo=_largo;
    ancho=_ancho;
}

void Pared::perimetro()
{
    float _perimetro;
    _perimetro = (2*largo)+(2*ancho);

    cout <<"el perimetro es : "<<_perimetro <<endl;
}
void Pared::area()
{
    float _area;
    _area=largo*ancho;

    cout <<"el area es : "<<_area<<endl;
}
//Instanciar es lo mismo que inicializar o crear
int main()
{
    Pared Suelo(11,7);
    Suelo.area();
}

*/


/*
//Sobracarga de Contructores

class Fecha
{
private:
    int dia,mes,anio;
public:
    Fecha(int,int,int);//Constructor1
    Fecha(long);//Constructor2
    void mostrarFecha();
};

//7/11/2019 --------- 201901107

Fecha::Fecha(int _dia, int _mes, int _anio)
{
    anio = _anio;
    mes = _mes;
    dia = _dia;
}

Fecha::Fecha(long fecha)
{
    anio= int(fecha/10000);//Extraer año
    mes=int((fecha-anio*10000)/100);
    dia=int(fecha-anio*10000-mes*100);
}

void Fecha::mostrarFecha()
{
    cout<<"La fecha es : "<<dia << "/"<<mes<<"/"<<anio<<endl;
}
int main()
{
    Fecha hoy(7,11,2019);
    Fecha ayer (6,11,2019);

    hoy.mostrarFecha();
    ayer.mostrarFecha();

    return 0;
}

*/

class Tiempo
{
private:
    int horas ,minutos,segundos;
public:
    Tiempo(int,int,int);//Constructor
    void mostrarTiempo();
};

Tiempo::Tiempo(int _horas, int _minutos, int _segundos)
{
    horas = _horas;
    minutos = _minutos;
    segundos = _segundos;
}

void Tiempo::mostrarTiempo()
{
    cout <<"El tiempo es : " << horas << " horas, con " << minutos << " minutos y "<<segundos <<" segundos "<<endl;
}

int main(){
    Tiempo nueva(15,20,30);
    nueva.mostrarTiempo();
    return 0;}


