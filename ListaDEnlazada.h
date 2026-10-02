//
// Created by molina on 02/10/2026.
//

#ifndef PRACTICA1_LISTADENLAZADA_H
#define PRACTICA1_LISTADENLAZADA_H
template<class T>
class ListaDEnlazada {
private :
    ListaDEnlazada *cabecera;
    ListaDEnlazada* cola;
public:
    ListaDEnlazada<T>();
    ListaDEnlazada<T>(const ListaEnlazada<T> &origen);
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
#endif //PRACTICA1_LISTADENLAZADA_H