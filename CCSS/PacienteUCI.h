#pragma once
#include<iostream>
#include<sstream>
using namespace std;
//Universidad Nacional 
	//Proyecto desarollado por:
	//Emily King Bustamante
	//Junio 2021.
//se realiza una sobrecarga de constructores
class PacienteUCI{
private:
	string nombre;
	string id;
	string enfermedades;
	int cantidadEnfermedades;
	string probabilidadUCI;
public:
	~PacienteUCI();
	PacienteUCI(string pNombre = "", string pId = "", string pEnfermedades = "", int pCantidadEnfermedades = 0);
	PacienteUCI(string pNombre = "", string pId = "", int pCantidadEnfermedades = 0, string pEnfermedades = "", string pProbabilidadesUCI = "");
	string toStringAnalisis1();
	int getCantidadEnfermedades()const;
	string getNombre()const;
	string getID()const;
	string getEnfermedades()const;
	string getProbabilidadUCI()const;
	string toStringCvsFormat()const;
	string toStringAnalisi3()const;

};

