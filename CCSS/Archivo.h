#pragma once
#include <string>
#include <fstream>
#ifndef Archivo_H
#define Archivo_H
//Universidad Nacional 
	//Proyecto desarollado por:
	//Emily King Bustamante
	//Junio 2021.

class Archivo {

public:

	Archivo();

	void escribir(std::string archivo, std::string texto);

	std::string leer(std::string archivo);
};
#endif /*Archivo */

