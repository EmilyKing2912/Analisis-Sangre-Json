#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <sstream>
using namespace std;

//Universidad Nacional 
    //Proyecto desarollado por:
    //Emily King Bustamante
    //Junio 2021.

template <class T> class lista;
template <class T> class nodo;
template <class T> class iterador;

/*En esta clase se implementa el patron de diseño iterador 
para acceder de manera secuencial a cada uno de los elementos de la lista
Debido a que necesitabamos una forma de recorrer nuestra lista y me parecio
que este metodo es el mas indicado debido a la facilidad de uso.
*/
//En esta clase se implementa la programacion generica, se creo una lista generica o template
//porque se deben manejar listas que contienen diferentes clases  para realizar los analisis correspondientes.

template <class T>
class lista {
public:
    lista();
    virtual ~lista();

    virtual bool vacia();
    virtual void agregar(T*);
    virtual void agregarFinal(T*);

    virtual iterador<T> obtenerIterador() const;

private:
    nodo<T>* _primero;
    nodo<T>* _ultimo;
};

template <class T>
class nodo {
public:
    nodo(T*, nodo<T>* = NULL);
    virtual ~nodo();

    virtual T* obtenerInfo() const;
    virtual nodo<T>* obtenerSiguiente() const;
    virtual void establecerSiguiente(nodo<T>*);

private:
    T* _info;
    nodo<T>* _siguiente;
};

template <class T>
class iterador {
public:
    iterador(nodo<T>*);

    virtual bool masElementos() const;
    virtual T* proximoElemento();

private:
    nodo<T>* _actual;
};

template <class T>
lista<T>::lista() : _primero(NULL), _ultimo(NULL) {
}

template <class T>
lista<T>::~lista() {
    delete _primero;
}

template <class T>
bool lista<T>::vacia() {
    return (_primero == NULL);
}

template <class T>
void lista<T>::agregar(T* x) {
    nodo<T>* tmp = new nodo<T>(x, _primero);
    if (vacia()) {
        _ultimo = tmp;
    }
    _primero = tmp;
}

template <class T>
void lista<T>::agregarFinal(T* x) {
    if (vacia()) {
        agregar(x);
    }
    else {
        _ultimo->establecerSiguiente(new nodo<T>(x));
        _ultimo = _ultimo->obtenerSiguiente();
    }
}

template <class T>
iterador<T> lista<T>::obtenerIterador() const {
    return iterador<T>(_primero);
}


template <class T>
nodo<T>::nodo(T* info, nodo<T>* siguiente) : _info(info), _siguiente(siguiente) {
}

template <class T>
nodo<T>::~nodo() {
    if (_siguiente != NULL) {
        delete _info;
        delete _siguiente;
    }
}

template <class T>
T* nodo<T>::obtenerInfo() const {
    return _info;
}

template <class T>
nodo<T>* nodo<T>::obtenerSiguiente() const {
    return _siguiente;
}

template <class T>
void nodo<T>::establecerSiguiente(nodo<T>* siguiente) {
    _siguiente = siguiente;
}

template <class T>
iterador<T>::iterador(nodo<T>* primero) : _actual(primero) {
}

template <class T>
bool iterador<T>::masElementos() const {
    return _actual != NULL;
}

template <class T>
T* iterador<T>::proximoElemento() {
    if (masElementos()) {
        T* r = _actual->obtenerInfo();
        _actual = _actual->obtenerSiguiente();
        return r;
    }
    else {
        throw - 1;
    }
}

#endif /* LISTA_H */
