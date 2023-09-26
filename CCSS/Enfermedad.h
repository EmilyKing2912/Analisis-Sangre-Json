#pragma once
#include<iostream>
#include<sstream>
#ifndef Enfermedad_H
#define Enfermedad_H
using namespace std;
//Universidad Nacional 
	//Proyecto desarollado por:
	//Emily King Bustamante
	//Junio 2021.
class Enfermedad
{
private:
	string nombre;
	string secuencia;
public:
	~Enfermedad();
	Enfermedad(string pNombre = "", string pSecuencia = "");
	void setNombre(string pNombre);
	void setSecuencia(string pSecuencia);
	string getNombre();
	string getSecuencia();
	string toString();
};
#endif /* Enfermedad_H */


