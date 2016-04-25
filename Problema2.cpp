// Problema2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//Funciones
int promptMenu();
void leerArchivo();
void anadirEmpleado();

//Variables y objetos
ofstream outfile;
ifstream infile;
string titulo, line;
int menu, choice, seleccion;
string nombre;
double hrs, pagoHora, totalBruto, totalNeto, horasExtra;
const double DESC_SS = .765, DESC_SM = .1112, SEG_CHOF = .05, SEG_INC = .0765, PREST_COOP = 75;

//Funccion Principal
int _tmain(int argc, _TCHAR* argv[])
{
	menu = promptMenu();
	while (menu != 3)
	{
		switch (seleccion)
		{
		case 1:
			anadirEmpleado();
			break;
		case 2:
			leerArchivo();
			break;
		}
		system("cls");
		menu = promptMenu();
	}
	return 0;
}
int promptMenu() {
	cout << "Menu:" << endl
		<< "1.Anadir Empleado" << endl
		<< "2.Generar Informe" << endl
		<< "3.Salir" << endl
		<< "Seleccion: ";
	cin >> seleccion;
	return seleccion;
}
void leerArchivo() {
	system("cls");
	infile.open("nomina.txt");
	if (infile.is_open())
	{
		cout << "Informe:" << endl << endl;
		while (getline(infile, line))
		{
			cout << line << '\n';
		}
		infile.close();
		system("pause");
	}
	else cout << "No se pudo abrir el archivo";
}
void anadirEmpleado() {
	system("cls");
	outfile.open("nomina.txt", ios::app);
	if (outfile.is_open())
	{
		choice = 0;
		while (choice != 2)
		{
			cout << "Entre nombre: ";
			cin >> nombre;
			outfile << "Nombre Empleado: " << nombre << endl;
			cout << "Entre horas trabajadas: ";
			cin >> hrs;
			outfile << "Horas trabajadas: " << hrs << endl;
			cout << "Entrar pago por hora: ";
			cin >> pagoHora;
			outfile << "Pago por hora: $" << pagoHora << endl;
			totalBruto = hrs * pagoHora;
			if (hrs > 40)
			{
				horasExtra = ((hrs - 40) * pagoHora) * 2;
				totalBruto = (hrs * pagoHora) + horasExtra;
			}
			double totalDesc = DESC_SS + DESC_SM + SEG_CHOF + SEG_INC + PREST_COOP;
			totalNeto = totalBruto - totalDesc;
			outfile << "Nomina:"
				<< "\nTotal Bruto: $" << totalBruto
				<< "\nHoras Extra: " << horasExtra
				<< "\nTotal Descuentos: $" << totalDesc
				<< "\nTotal Neto: $" << totalNeto << endl << endl;
			cout << "Desea anadir otro? (1.Yes| 2.No): ";
			cin >> choice;
		}
		outfile.close();
		system("cls");
	}
}

