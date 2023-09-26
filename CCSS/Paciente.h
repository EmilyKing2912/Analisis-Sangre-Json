#pragma once
#include<iostream>
#include<sstream>
#ifndef Paciente_H
#define Paciente_H
using namespace std;
//Universidad Nacional 
	//Proyecto desarollado por:
	//Emily King Bustamante
	//Junio 2021.

class Paciente
{
private:
	string nombre;
	string id;
	string adn;

public:

	Paciente(string pNombre= " ", string pId= " ", string pADN= " ");
	~Paciente();
	void setNombre(string pNombre);
	void setID(string pId);
	void setADN(string pADN);

	string getNombre()const;
	string getID()const;
	string getADN()const;

	string ToString()const;

};
#endif /* Paciente_H */