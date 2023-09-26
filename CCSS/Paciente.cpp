#include "Paciente.h"
//Universidad Nacional 
	//Proyecto desarollado por:
	//Emily King Bustamante
	//Junio 2021.

Paciente::Paciente(string pNombre, string pId, string pADN) {
	nombre = pNombre;
	id = pId;
	adn = pADN;
}

Paciente::~Paciente() {
}

void Paciente::setNombre(string pNombre){
	nombre = pNombre;
}

void Paciente::setID(string pId){
	id = pId;
}

void Paciente::setADN(string pADN){
	adn = pADN;
}

string Paciente::getNombre()const{
	return nombre;
}

string Paciente::getID()const{
	return id;
}

string Paciente::getADN()const{
	return adn;
}

string Paciente::ToString()const {
	stringstream ss;

	ss << "Nombre: " << getNombre() << endl;
	ss << "ID: " << getID() << endl;
	ss << "Secuencia de ADN: " << getADN() << endl;

	return ss.str();
}
