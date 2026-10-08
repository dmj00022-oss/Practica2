//
// Created by molina on 02/10/2026.
//

#ifndef PRACTICA1_LISTADENLAZADA_H
#define PRACTICA1_LISTADENLAZADA_H
#include <stdexcept>
template<class T>
class ListaDEnlazada {
private :
    class Nodo {
public:
    T dato;
    Nodo *anterior,*siguiente;
    Nodo(T &aDato, Nodo *aAnterior, Nodo *aSiguiente): dato(aDato),anterior(aAnterior),siguiente(aSiguiente) {}
    ~Nodo(){}
};

    Nodo *cabecera,*cola;
    unsigned long int tamañoListaD;
public:
    class Iterador {
    public:
        Nodo *nodo;
        Iterador(Nodo *aNodo):nodo(aNodo){}
        bool fin() {
            return nodo==nullptr;
        }
        void anterior() {
            nodo=nodo->anterior;
        }
        void siguiente() {
            nodo=nodo->siguiente();
        }
        T &dato() {
            return nodo->dato;
        }
        ~Iterador(){}
    };
    ListaDEnlazada<T>();
    ListaDEnlazada<T>(const ListaDEnlazada<T> &origen);
    ListaDEnlazada<T> &operator=(const ListaEnlazada<T> &origen);
    T& inicio();
    T& fin();
    ListaDEnlazada<T>::Iterador iterador();
    void insertaInicio(T&objeto);
    void insertaFin(T&objeto);
    void inserta(Iterador &i, T&dato);
    void borraInicio();
    void borraFinal();
    void borra(Iterador &i);
    unsigned long int getTamanio();

};
template<class T>
ListaDEnlazada<T>::ListaDEnlazada():
cabecera(nullptr),cola(nullptr),tamañoListaD(0)
{}
template<class T>
ListaDEnlazada<T>::ListaDEnlazada(const ListaDEnlazada<T> &origen):
tamañoListaD(0) {
    Nodo *p;
    cabecera=nullptr;
    cola=nullptr;
    p=origen.cabecera;
    while (p!=nullptr) {
        insertaFin(p->dato);
        p=p->siguiente;


    }
}
template<class T>
ListaDEnlazada<T> &ListaDEnlazada<T> :: operator=(const ListaEnlazada<T> &origen) {
    Nodo *p;
    p=cabecera;
    while (p!=nullptr) {

    }
}
template<class T>
T& ListaDEnlazada<T>::inicio() {
    if (!cabecera) {
        throw std::invalid_argument("ListaEnlazada<T>::inicio:No hay valor inicial");
    }
    return cabecera->dato;
}
template<class T>
T& ListaDEnlazada<T>::fin() {
    if (!cola) {
        throw std::invalid_argument("ListaEnlazada<T>::fin:No hay valor final");
    }
    return cola->dato;
}
ListaDEnlazada<T>::Iterador iterador();
template<class T>
void ListaDEnlazada<T>::insertaInicio(T&objeto) {
    Nodo *nuevoInicio;
    nuevoInicio=new Nodo(objeto,nullptr,cabecera);
    tamañoListaD++;
    if (cabecera!=nullptr) {
        cabecera->anterior=nuevoInicio;
    }
    if (cola==nullptr) {
        cola=nuevoInicio;
    }
    cabecera=nuevoInicio;
}
template<class T>
void ListaDEnlazada<T>::insertaFin(T&objeto) {
    Nodo *nuevoDato;
    nuevoDato=new Nodo(objeto,cola,nullptr);
    tamañoListaD++;

    if (cabecera==nullptr) {
        cabecera=nuevoDato;
    }
    if (cola!=nullptr) {
        cola->siguiente=nuevoDato;
    }
    cola=nuevoDato;
}
void inserta(Iterador &i, T&dato);
template <class T>

void ListaDEnlazada<T>::borraInicio() {
    if (!cabecera) {
        throw std::invalid_argument("ListaDEnlazada<T>::borraInicio():No se puede borrar un elemento de una lista vacia");
    }
    Nodo *borrar;
    borrar=cabecera;
    cabecera=cabecera->siguiente;
    delete borrar;
    if (cabecera!=nullptr) {
        cabecera->anterior=nullptr;
    }else  {
        cola=nullptr;
    }
}
void borraFinal();
void borra(Iterador &i);
template<class T>
unsigned long int ListaDEnlazada<T>::getTamanio() {
    return tamañoListaD;
}
#endif //PRACTICA1_LISTADENLAZADA_H

