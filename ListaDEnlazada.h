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
            nodo=nodo->siguiente;
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
    void insertaInicio(const T&objeto);
    void insertaFin(const T&objeto);
    void inserta(Iterador &i, const T&dato);
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
ListaDEnlazada<T> &ListaDEnlazada<T> :: operator=(const ListaDEnlazada<T> &origen) {
    while (cabecera!=nullptr) {
        borraInicio();
    }
   Nodo *p;
    cabecera=nullptr;
    cola=nullptr;
    p=origen.cabecera;
    tamañoListaD=0;
    while (p!=nullptr) {
        insertaFin(p->dato);
        p=p->siguiente;

    }
    return *this;
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
template<class T>
ListaDEnlazada<T>::Iterador:: iterador() {

}
template<class T>
void ListaDEnlazada<T>::insertaInicio(const T&objeto) {
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
void ListaDEnlazada<T>::insertaFin(const T&objeto) {
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

template<class T>
void ListaDEnlazada<T>::inserta(Iterador &i, const T&dato) {
if (i.fin()) {
    throw std::invalid_argument("ListaDEnlazada<T>::inserta:Iterador incorrecto");
}
    if (i.nodo==cabecera) {
        insertaInicio(dato);
    }else {
        Nodo* nuevo;
        nuevo=new Nodo(dato,i.nodo->anterior,i.nodo);
        i.nodo->anterior->siguiente=nuevo;
        i.nodo->anterior=nuevo;
        tamañoListaD++;

    }

}
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
template <class T>
void ListaDEnlazada<T>::borraFinal() {
    if (cola==nullptr) {
        throw std::invalid_argument("ListaDEnlazada<T>::borraFinal: La lista esta vacia ");
    }
    tamañoListaD--;
    Nodo *ultimo;
    ultimo=cola->anterior;
    delete cola;
    cola=ultimo;
    if (cola!=nullptr) {
        cola->siguiente=nullptr;
    }else {
        cabecera=nullptr;
    }

}
template<class T>
void ListaDEnlazada<T>::borra(Iterador &i) {
if (i.nodo==nullptr) {
    throw std::invalid_argument("ListaDEnlazada<T>::borra:iterador nulo");
}
    if (cabecera==nullptr || cola==nullptr) {
        throw std::invalid_argument("ListaDEnlazada<T>::borra:La lista esta vacia");
    }
    if (cabecera==cola) { //es decir solo hay un elemento
        cabecera=nullptr;
        cola=nullptr; //las dos a nullptr porq se va a qedar la lista vacia
        tamañoListaD--;
        delete i.nodo;
        i.nodo=nullptr;
    }else { //segundo caso, que el que se quiera borrar sea el que apunte la cabecera
        if (i.nodo==cabecera) {
            borraInicio();
        }else {
            if (i.nodo==cola) {
                borraFinal(); //tercer caso que el que se quiera borrar sea el ultimo de la lista
            }else {
                i.nodo->anterior->siguiente=i.nodo->siguiente;
                i.nodo->siguiente->anterior=i.nodo->anterior;
                tamañoListaD--;
                delete i.nodo;
                i.nodo=nullptr; //preguntar al profesor si habria que apuntar a null despues del delete
            }
        }
    }
}
template<class T>
unsigned long int ListaDEnlazada<T>::getTamanio() {
    return tamañoListaD;
}
#endif //PRACTICA1_LISTADENLAZADA_H

