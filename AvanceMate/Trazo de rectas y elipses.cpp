#include <iostream>
#include <math.h>
#include <locale.h>
using namespace std;

void Trazo_Rectas();
void Trazo_Elipses();

int main() {
	setlocale(LC_ALL, "spanish");
	Trazo_Rectas();
	Trazo_Elipses();
}

void Trazo_Rectas() {
	system("CLS");
	float pk, x_punto1, y_punto1, x_punto2, y_punto2, dx, dy, repeticiones;

	cout << endl << "Ingrese la x del primer punto: ";
	cin >> x_punto1;
	cout << "Ingrese la y del primer punto: ";
	cin >> y_punto1;

	cout << endl << "Ingrese la x del segundo punto: ";
	cin >> x_punto2;
	cout << "Ingrese la y del segundo punto: ";
	cin >> y_punto2;
	cout << endl;

	system("PAUSE");
	system("CLS");
	
	dx = x_punto2 - x_punto1;
	dy = y_punto2 - y_punto1;
	repeticiones = dx - 1;
	pk = 2 * dy - dx;

	cout << "Los puntos que conforman la recta son: " << endl << endl << "(" << x_punto1 << "," << y_punto1 << "), ";

	for(repeticiones; repeticiones > 0; repeticiones = repeticiones - 1){
		if (pk < 0) {
			pk = pk + 2 * dy;
			x_punto1 = x_punto1 + 1;
		}
		else {
			pk = pk + 2 * dy - 2 * dx;
			x_punto1 = x_punto1 + 1;
			y_punto1 = y_punto1 + 1;
		}
		cout << "(" << x_punto1 << "," << y_punto1 << "), ";
	}
	cout << "(" << x_punto2 << "," << y_punto2 << ")" << endl << endl;
	system("PAUSE");
}
void Trazo_Elipses() {
	system("CLS");
	float rx_elipse, ry_elipse, p1k, columna1_2ryx, columna2_2rxy, x_punto, y_punto, x_centro, y_centro;

	cout << endl << "Ingrese la x del centro del elipse: ";
	cin >> x_centro;
	cout << "Ingrese la y del centro del elipse: ";
	cin >> y_centro;

	cout << endl << "Ingrese cuánto mide el radio x de la elipse: ";
	cin >> rx_elipse;
	cout << "Ingrese cuánto mide el radio y de la elipse: ";
	cin >> ry_elipse;
	cout << endl;

	system("PAUSE");
	system("CLS");	

	p1k = pow(ry_elipse, 2) - pow(rx_elipse, 2) * (ry_elipse)+(1 / 4) * pow(rx_elipse, 2);
	x_punto = 0;
	y_punto = ry_elipse;
	columna1_2ryx = 2 * pow(ry_elipse, 2) * x_punto;
	columna2_2rxy = 2 * pow(rx_elipse, 2) * y_punto;

	cout << "Los puntos que conforman un cuadrante de la elipse son: " << endl << endl << "(" << x_punto + x_centro << "," << y_punto + y_centro << "), ";

	while (columna2_2rxy > columna1_2ryx) {
		if (p1k < 0) {
			p1k = p1k + (2 * pow(ry_elipse, 2) * x_punto + 2 * pow(ry_elipse, 2)) + pow(ry_elipse, 2);		
		}
		else {
			p1k = p1k + (2 * pow(ry_elipse, 2) * x_punto + 2 * pow(ry_elipse, 2)) - (2 * pow(rx_elipse, 2) * y_punto - 2 * pow(rx_elipse, 2)) + pow(ry_elipse, 2);
			y_punto = y_punto - 1;
		}
		x_punto = x_punto + 1;
		columna1_2ryx = 2 * pow(ry_elipse, 2) * x_punto;
		columna2_2rxy = 2 * pow(rx_elipse, 2) * y_punto;		
		cout << "(" << x_punto + x_centro << "," << y_punto + y_centro << "), ";
	}
	p1k = pow(ry_elipse, 2) * pow(x_punto + 1 / 2, 2) + pow(rx_elipse, 2) * pow(y_punto - 1, 2) - pow(rx_elipse, 2) * pow(ry_elipse, 2);

	while (y_punto != 0) {
		if (p1k < 0) {
			p1k = p1k + (2 * pow(ry_elipse, 2) * x_punto + 2 * pow(ry_elipse, 2)) - (2 * (rx_elipse, 2) * y_punto - 2 * pow(rx_elipse, 2)) + pow(rx_elipse, 2);
			x_punto = x_punto + 1;
		}
		else {
			p1k = p1k - (2 * pow(rx_elipse, 2) * y_punto - 2 * pow(rx_elipse, 2)) + pow(rx_elipse, 2);
		}
		y_punto = y_punto - 1;
		cout << "(" << x_punto + x_centro << "," << y_punto + y_centro << "), ";
	}
	cout << endl << endl;
	system("PAUSE");
}
