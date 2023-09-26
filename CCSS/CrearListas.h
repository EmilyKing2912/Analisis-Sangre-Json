#pragma once
#include "json/json.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Paciente.h"
#include "Enfermedad.h"
#include "Archivo.h"
#include "Lista.h"
//Universidad Nacional 
	//Proyecto desarollado por:
	//Emily King Bustamante
	//Junio 2021.
//clase para respetar el principio de responsabilidad unica cuya unica funcion es meter el archivo json y el cvs a una lista.
class CrearListas
{
public:
	CrearListas();
	~CrearListas();
	 lista<Enfermedad>* crearListaEnfermedades();
	 lista<Paciente>* crearListaPacientes();
};

