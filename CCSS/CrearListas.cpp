#include "CrearListas.h"
//Universidad Nacional 
    //Proyecto desarollado por:
    //Emily King Bustamante
    //Junio 2021.

CrearListas::CrearListas() {}
CrearListas::~CrearListas() {}

 lista<Enfermedad>* CrearListas::crearListaEnfermedades() {
    std::ifstream entrada("ListaSecuenciaEnfermedad.JSON");
    Json::Value objeto;
    Json::Reader reader;
    reader.parse(entrada, objeto);
    lista<Enfermedad>* enfermedades = new lista<Enfermedad>();
    for (int i = 0; i<(objeto.size()); i++)
    {
        string nombre = (objeto[i]["nombre"].asString());
        string secuencia = (objeto[i]["secuencia"].asString());
        Enfermedad* enfermedad = new Enfermedad(nombre, secuencia);
        enfermedades->agregarFinal(enfermedad);

    }
    return enfermedades;
}

 lista<Paciente>* CrearListas::crearListaPacientes() {
    lista<Paciente>* pacientes = new lista<Paciente>();
    ifstream archivo("CadenaADN-Pacientes.csv");
    string linea;
    char delimitador = ';';
    //Leemos todas las líneas
    while (getline(archivo, linea))
    {
        stringstream stream(linea); 
        string nombre, id, adn;
        getline(stream, nombre, delimitador);
        getline(stream, id, delimitador);
        getline(stream, adn, delimitador);
        Paciente* pac = new Paciente(nombre, id, adn);
        pacientes->agregarFinal(pac);
    }
    archivo.close();
    return pacientes;
}