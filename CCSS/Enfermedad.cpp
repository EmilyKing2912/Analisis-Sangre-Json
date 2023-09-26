#include "Enfermedad.h"
//Universidad Nacional 
	//Proyecto desarollado por:
	//Emily King Bustamante
	//Junio 2021.

Enfermedad::~Enfermedad() {}
Enfermedad::Enfermedad(string pNombre, string pSecuencia) {
	nombre = pNombre;
	secuencia = pSecuencia;
}
void Enfermedad::setNombre(string pNombre) {
	nombre = pNombre;
}
void Enfermedad::setSecuencia(string pSecuencia) {
	secuencia = pSecuencia;
}
string Enfermedad::getNombre() {
	return nombre;
}
string Enfermedad::getSecuencia(){
	return secuencia;
}
string Enfermedad::toString() {
	stringstream s;
	s << "El nombre de la enfermedad es: " << getNombre() << endl;
	s << "La secuencia de la enfermedad es: " << getSecuencia() << endl;
	return s.str();
}