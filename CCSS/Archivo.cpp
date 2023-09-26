#include "Archivo.h"
//Universidad Nacional 
	//Proyecto desarollado por:
	//Emily King Bustamante
	//Junio 2021.

Archivo::Archivo() {}
void Archivo::escribir(std::string nombreArchivo, std::string texto) {
	std::ofstream fs(nombreArchivo+".cvs", std::ios::app);
	fs << "" + texto;
	fs.close();
}
std::string Archivo::leer(std::string nombreArchivo) {
	std::ifstream fe;
	std::string textoLeido = " ", linea = " ";
	fe.open(nombreArchivo+".cvs", std::ios::out);
	if (fe.is_open()) {
		while (!fe.eof()) {
			getline(fe, linea);
			textoLeido += linea;
		}
		fe.close();
	}
	else {
		textoLeido = "Error en la lectura del archivo";
	}
	return textoLeido;
}
