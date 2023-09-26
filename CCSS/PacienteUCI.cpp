#include "PacienteUCI.h"
PacienteUCI::~PacienteUCI() {}
PacienteUCI::PacienteUCI(string pNombre, string pId, string pEnfermedades, int pCantidadEnfermedades) {
	nombre = pNombre;
	id = pId;
	enfermedades = pEnfermedades;
	cantidadEnfermedades = pCantidadEnfermedades;
}

PacienteUCI::PacienteUCI(string pNombre, string pId, int pCantidadEnfermedades, string pEnfermedades, string pProbabilidadesUCI) {
	nombre = pNombre;
	id = pId;
	enfermedades = pEnfermedades;
	cantidadEnfermedades = pCantidadEnfermedades;
	probabilidadUCI = pProbabilidadesUCI;
}
string PacienteUCI::toStringAnalisis1() {
	stringstream s;
	s << "Nombre: " << nombre << endl;
	s << "ID: " << id<< endl;
	s << "El paciente tiene susceptibilidad a: " << enfermedades << endl;
	return s.str();
}
string PacienteUCI::getNombre()const {
	return nombre;
}

string PacienteUCI::getID()const {
	return id;
}
string PacienteUCI::getEnfermedades() const {
	return enfermedades;
}
int PacienteUCI::getCantidadEnfermedades()const {
	return cantidadEnfermedades;
}
string PacienteUCI::toStringAnalisi3() const {
	stringstream s;
	s << "Cantidad Enfermedades: " << cantidadEnfermedades << endl;
	s << "Nombre: " << nombre << endl;
	s << "ID: " << id << endl;
	s << "El paciente tiene susceptibilidad a: " << enfermedades << endl;
	s << probabilidadUCI << "." << endl;
	return s.str();
}
string PacienteUCI::toStringCvsFormat() const {
	stringstream s;
	s << cantidadEnfermedades<<";"<<nombre << ";" << id << ";" << enfermedades << ";"<<probabilidadUCI << "." << endl;
	return s.str();
}
string PacienteUCI::getProbabilidadUCI()const {
	stringstream s;
	if (cantidadEnfermedades == 2) {
		s << "El paciente tiene un 40% de probabilidad de necesitar una  UCI";
	}else
		if (cantidadEnfermedades > 2) {
			s << "El paciente tiene un 70% de probabilidad de necesitar una  UCI";
		}
	return s.str();
}