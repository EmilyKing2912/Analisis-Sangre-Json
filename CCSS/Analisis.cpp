#include "Analisis.h"
//Universidad Nacional 
	//Proyecto desarollado por:
	//Emily King Bustamante
	//Junio 2021.


 Analisis* Analisis::instance = nullptr;

 Analisis* Analisis::getInstance() {
	if (!instance)
		instance = new Analisis();
	return instance;
}

Analisis::~Analisis() {
	delete enfermedades;
	delete pacientes;
}
Analisis::Analisis() {
	CrearListas* list = new CrearListas();
	enfermedades = list->crearListaEnfermedades();
	pacientes = list->crearListaPacientes();
	delete list;
}

void Analisis::setPacientes(lista<Paciente>* ptr) {
	pacientes = ptr;
}

void Analisis::setEnfermerdades(lista<Enfermedad>* ptr) {
	enfermedades = ptr;
}

int Analisis::contarRepeticionBase(string adn,string base) { 
	int apariciones = 0;
	string substr = "";
	for (size_t i = 0; i <= (adn.size() - base.size()); i++)
	{
		if (adn.substr(i, base.size()) == base)
		{
			apariciones++;
		}
	}
	return apariciones;

}

bool Analisis::BuscarEnfermedad(string adn, string enfermedad) {
	return (adn.find(enfermedad) < adn.size());
}
string Analisis::anadirDatosSTring(string enfermedad1, string enfermedad2) {
	stringstream s;
	s << enfermedad1 <<","<< enfermedad2;
	return s.str();
}
string Analisis::convertirString(string adn,string base) {
	stringstream s;
	float porcentaje1 = porcentaje(adn, base);
	s << base << "-%" <<porcentaje1;
	return s.str();
}
float Analisis::porcentaje(string adn, string base) {
	float longitud = adn.length();
	int cantidad = contarRepeticionBase(adn, base);
	float porcen = (cantidad*100 )/longitud;
	return porcen;
}
lista<PacienteUCI>* Analisis::analisis1(){
lista<PacienteUCI>* datos = new lista<PacienteUCI>;
 iterador<Enfermedad> i = enfermedades->obtenerIterador();
 iterador<Paciente> j = pacientes->obtenerIterador();
 Paciente* paci= nullptr;
 Enfermedad* enfer = nullptr;
 while (j.masElementos())
 {
	 paci = j.proximoElemento();
	 string enfermedadesLista = "";
	 int contador = 0;
	 i = enfermedades->obtenerIterador();
	 string nombre = paci->getNombre();
	 string id = paci->getID();
	 string adn = paci->getADN();
	 while (i.masElementos()) {
		 enfer = i.proximoElemento();
		 string enfermedad = enfer->getSecuencia();
		 if (BuscarEnfermedad(adn, enfermedad) == true){
			 string enfermedadesPA = enfer->getNombre();
			 enfermedadesLista = anadirDatosSTring(enfermedadesPA,enfermedadesLista);
				 contador++;
				 
		 }
	  }
	 PacienteUCI* pacienteUCI = new PacienteUCI(nombre, id, enfermedadesLista,contador);
	 datos->agregarFinal(pacienteUCI);
 }
 return datos;
}

string Analisis::analisis2(){
	iterador<Paciente> i = pacientes->obtenerIterador();
	Paciente* paci = nullptr;
	stringstream s;
	while (i.masElementos())
	{
		paci = i.proximoElemento();
		string adn = paci->getADN();
		string porcentaje1 = convertirString(adn, "G");
		string porcentaje2 = convertirString(adn, "A");
		string porcentaje3 = convertirString(adn, "T");
		string porcentaje4 = convertirString(adn, "C");
		string nombre = paci->getNombre();
		string id = paci->getID();
		string basesNitrogenadas = anadirDatosSTring(nombre,id);
		nombre = anadirDatosSTring(basesNitrogenadas, porcentaje1);
		basesNitrogenadas= anadirDatosSTring(nombre,porcentaje2);
		nombre=anadirDatosSTring(basesNitrogenadas, porcentaje3);
		basesNitrogenadas=anadirDatosSTring(nombre, porcentaje4);
		s << basesNitrogenadas << endl;
	}
	return s.str();
}
lista<PacienteUCI>* Analisis::analisis3(){
	lista<PacienteUCI>* datos = analisis1();
	lista<PacienteUCI>* datos2 = new lista<PacienteUCI>;
	iterador<PacienteUCI> i = datos->obtenerIterador();
	PacienteUCI* pauci = nullptr;
	while (i.masElementos()) {
		pauci = i.proximoElemento();
		if (pauci->getCantidadEnfermedades() >= 2) {
			string nombre = pauci->getNombre();
			string id = pauci->getID();
			int cantidad = pauci->getCantidadEnfermedades();
			string enfermedades = pauci->getEnfermedades();
			string probabilidad = pauci->getProbabilidadUCI();
			PacienteUCI* pacienteUCI = new PacienteUCI(nombre, id,cantidad,enfermedades,probabilidad);
			if (pauci->getCantidadEnfermedades()>2) {
				datos2->agregar(pacienteUCI);
			}
			else
				datos2->agregarFinal(pacienteUCI);
		}
	}
	return datos2;
}

string Analisis::mostrarAnalisis1() {
	lista<PacienteUCI>* an1 = analisis1();
	iterador<PacienteUCI> i = an1->obtenerIterador();
	stringstream s;
	while (i.masElementos()) {
		s << i.proximoElemento()->toStringAnalisis1() << endl;
	}
		return s.str();
}


	string Analisis::mostrarAnalisisCVS() {
		stringstream s;
		for (int i = 8; i > 0; i--) {
			s<<orden(i);
		}
		return s.str();
	}
	string Analisis::orden(int cantidad) {
		lista<PacienteUCI>* an3 = analisis3();
		iterador<PacienteUCI> j = an3->obtenerIterador();
		stringstream s;
		PacienteUCI* pac = nullptr;
		while (j.masElementos()) {
			pac = j.proximoElemento();
			if (pac->getCantidadEnfermedades() == cantidad) {
				s << pac->toStringCvsFormat() << endl;
			}
		}
		return s.str();
	}
	string Analisis::orden2(int cantidad) {
		lista<PacienteUCI>* an3 = analisis3();
		iterador<PacienteUCI> j = an3->obtenerIterador();
		stringstream s;
		PacienteUCI* pac = nullptr;
		while (j.masElementos()) {
			pac = j.proximoElemento();
			if (pac->getCantidadEnfermedades() == cantidad) {
				s << pac->toStringAnalisi3() << endl;
			}
		}
		return s.str();
	}
	string Analisis::mostrarAnalisis3() {
		stringstream s;
		for (int i = 8; i > 0; i--) {
			s << orden2(i);
		}
		return s.str();
	}
		


