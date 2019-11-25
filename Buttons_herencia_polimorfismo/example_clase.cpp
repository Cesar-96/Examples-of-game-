// example_clase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*


#include <iostream>

using namespace std;

class Point
{
private:
	int x, y;
public:
	Point();
	void pedirPrimerPunto(int, int);
	void obtenerRecta(Point,Point);
};



Point::Point()
	:x(0), y(0) {}



void Point::pedirPrimerPunto(int _x, int _y)
{
	x = _x;
	y = _y;
	cout << "(" << x << "," << y<<")";
}

class Recta: public Point
{
private:
	Point inicio, finall;
public:
	void obtenerRecta(Point _inicio, Point finall);
};

void Point::obtenerRecta(Point _inicio, Point _finall)
{
	inicio = _inicio;
	finall = _finall;
}


int main()
{
	Point p;
	p.pedirPrimerPunto(8, 15);
	return 0;
}


class Rectangulo
{
protected:
	string color;
	int base;
	int altura;
};


*/


#include<iostream>
using namespace std;



class Rectangulo
{
protected:
	int base;
	int altura;
public:
	//Rectangulo();
	//Rectangulo(int base_, int altura_);
	//{
	//	base = base_;
	//	altura = altura_;
	//}
	int obtenerBase(int _base) { 
		base = _base;
		return base; }
	int obtenerAltura(int _altura) { 
		altura = _altura;
		return altura; }
	int obtenerArea() {
		int area;
		area = base * altura;
		return area;
		}
	virtual string test() 
		{
		return "este es un rectangulo";
		}
	
};

class Button : public Rectangulo
{
private:
	string color;
public:
	
	string getColor(string color_)
	{
		color = color_;
		return color;
	}
	string test() {
		return "este es un boton";
	}
};

class StartButton : public Rectangulo
{
private:
	string color;
public:
	string getColor(string color_)
	{
		color = color_;
		return color;
	}
	string test()
	{
		return "este es el boton de start";
	}
};

class QuitButton : public Rectangulo
{
private:


};


int main() 
{
	Rectangulo r1;
	Rectangulo* pt = &r1;

	Button b2;
	Button* pt1 = &b2;

	pt = &b2;
	
	cout << pt->test() << endl;


	
	cout << r1.obtenerBase(5) << endl;
	cout << r1.obtenerAltura(10)<<endl;
	cout << r1.obtenerArea()<<endl;
	cout << r1.test()<<endl;
	Button b1;
	cout << b1.obtenerBase(10)<<endl;
	cout << b1.test();
}

/*
class Button : public Rectangulo
{

public:

};

*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
