#pragma once
#include "PacienteUCI.h"
#include "Lista.h"
#include "Enfermedad.h"
#include "Paciente.h"
#include "CrearListas.h"
//Universidad Nacional 
	//Proyecto desarollado por:
	//Emily King Bustamante
	//Junio 2021.

class Analisis
{ //en esta clase se emplea el singleton para restringir la creacion de otros objetos tipo analisis
	//porque no es necesario crear otros objetos tipo analisis.
private:
	lista<Paciente>* pacientes;
	lista<Enfermedad>* enfermedades;
	static Analisis* instance;
	
public:
	static Analisis* getInstance();
	~Analisis();
	Analisis();
	void setPacientes(lista<Paciente>* ptr);
	void setEnfermerdades(lista<Enfermedad>* ptr);
	string anadirDatosSTring(string enfermedad1, string enfermedad2); //concatena datos string
	bool BuscarEnfermedad(string adn, string enfermedad);
	int contarRepeticionBase(string adn,string base);
	float porcentaje(string adn, string base);
	string convertirString(string adn, string base);
	lista<PacienteUCI>* analisis1();
	string analisis2(); 
	string orden(int cantidad);
	string orden2(int cantidad);
	lista<PacienteUCI>* analisis3();
	string mostrarAnalisis1();
	string mostrarAnalisis3();
	string mostrarAnalisisCVS();
};

