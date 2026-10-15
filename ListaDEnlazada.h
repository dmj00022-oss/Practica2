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
        Nodo *anterior, *siguiente;

        /**
             * @brief crea un nodo con el dato y los enlaces dados
             * @param aDato dato que guarda el nodo
             * @param aAnterior nodo anterior
             * @param aSiguiente nodo siguiente
             */
        Nodo(const T &aDato, Nodo *aAnterior, Nodo *aSiguiente) : dato(aDato), anterior(aAnterior),
                                                                  siguiente(aSiguiente) {
        }

        /**
             * @brief Destructor del nodo
             */
        ~Nodo() {
        }
    };

    Nodo *cabecera, *cola;
    unsigned long int tamanioDeLaListaDoblementeEnlazada;

public:
    class Iterador {
    public:
        Nodo *nodo;

        /**
         * @brief crea un iterador sin inicializar
         */
        Iterador() = default;

        /**
         * @brief crea un iterador que apunta al nodo dado
         * @param aNodo nodo al que apunta el iterador
         */
        Iterador(Nodo *aNodo) : nodo(aNodo) {
        }

        /**
         * @brief indica si el iterador se ha salido de la lista
         * @return true si no apunta a ningun nodo, false si apunta a alguno
         */
        bool fin() {
            if (nodo == nullptr) {
                return true;
            } else {
                return false;
            }
        }

        /**
        * @brief mueve el iterador al nodo anterior
        * @pre el iterador debe apuntar a un nodo valido
        */
        void anterior() {
            nodo = nodo->anterior;
        }

        /**
        * @brief mueve el iterador al nodo siguiente
        * @pre el iterador debe apuntar a un nodo valido
        */
        void siguiente() {
            nodo = nodo->siguiente;
        }

        /**
        * @brief permite acceder al dato del nodo al que apunta el iterador
        * @pre el iterador debe apuntar a un nodo valido
        * @return referencia al dato del nodo
        */
        T &dato() {
            return nodo->dato;
        }

        /**
         * @brief Destructor del iterador
         */
        ~Iterador() {
        }
    };

    ListaDEnlazada<T>();

    ListaDEnlazada<T>(const ListaDEnlazada<T> &origen);

    ListaDEnlazada<T> &operator=(const ListaDEnlazada<T> &origen);

    ~ListaDEnlazada<T>();

    T &inicio();

    T &fin();

    Iterador iterador() const;

    void insertaInicio(const T &objeto);

    void insertaFin(const T &objeto);

    void inserta(Iterador &i, const T &dato);

    void borraInicio();

    void borraFinal();

    void borra(Iterador &i);

    unsigned long int getTamanio();

    ListaDEnlazada<T> concatena(const ListaDEnlazada<T> &nuevaLista);

    ListaDEnlazada<T> operator+(const ListaDEnlazada<T> &nuevaLista);
};

/**
 * @brief crea una lista vacia, con cabecera y cola a nullptr y tamaño 0
 */
template<class T>
ListaDEnlazada<T>::ListaDEnlazada() : cabecera(nullptr), cola(nullptr), tamanioDeLaListaDoblementeEnlazada(0) {
}


/**
 * @brief copia los datos de otra lista, manteniendo el orden
 * @param origen lista que es copiada
 */
template<class T>
ListaDEnlazada<T>::ListaDEnlazada(const ListaDEnlazada<T> &origen) : tamanioDeLaListaDoblementeEnlazada(0) {
    Nodo *NodoOriginal;
    cola = nullptr;
    cabecera = nullptr;
    NodoOriginal = origen.cabecera;
    while (NodoOriginal != nullptr) {
        insertaFin(NodoOriginal->dato);
        NodoOriginal = NodoOriginal->siguiente;
    }
}


/**
 * @brief asigna los datos de una lista a otra, vaciando antes la lista actual
 * @param origen lista copiada
 * @return referencia al objeto
 */
template<class T>
ListaDEnlazada<T> &ListaDEnlazada<T>::operator=(const ListaDEnlazada<T> &origen) {
    while (cola != nullptr) {
        borraFinal();
    }
    Nodo *NodoOriginal;
    cabecera = nullptr;
    cola = nullptr;
    NodoOriginal = origen.cabecera;
    tamanioDeLaListaDoblementeEnlazada = 0;
    while (NodoOriginal != nullptr) {
        insertaFin(NodoOriginal->dato);
        NodoOriginal = NodoOriginal->siguiente;
    }

    return *this;
}


/**
 * @brief libera la memoria de todos los nodos de la lista
 */
template<typename T>
ListaDEnlazada<T>::~ListaDEnlazada() {
    while (cabecera != nullptr) {
        borraInicio();
    } // al salir de aqui cabecera apunta al siguiente del ultimo , por tanto a null

    tamanioDeLaListaDoblementeEnlazada = 0;
}


/**
 * @brief permite acceder al primer dato de la lista
 * @return referencia al dato situado al inicio
 * @throw std::invalid_argument si la lista esta vacia
 */
template<class T>
T &ListaDEnlazada<T>::inicio() {
    if (!cabecera) {
        throw std::invalid_argument("ListaEnlazada<T>::inicio:No hay valor inicial");
    }
    return cabecera->dato;
}


/**
 * @brief permite acceder al ultimo dato de la lista
 * @return referencia al dato situado al final
 * @throw std::invalid_argument si la lista esta vacia
 */
template<class T>
T &ListaDEnlazada<T>::fin() {
    if (!cola) {
        throw std::invalid_argument("ListaEnlazada<T>::fin:No hay valor final");
    }
    return cola->dato;
}


/**
 * @brief obtiene un iterador para recorrer la lista
 * @return iterador apuntando al primer nodo
 */
template<class T>
typename ListaDEnlazada<T>::Iterador ListaDEnlazada<T>::iterador() const {
    //typename ListaDEnlazada<T>::Iterador   // "esto es un tipo"
    return Iterador(cabecera);
}


/**
 * @brief inserta un dato al inicio de la lista
 * @tparam T dato que se desea insertar
 */
template<class T>
void ListaDEnlazada<T>::insertaInicio(const T &objeto) {
    Nodo *nuevoInicio;
    nuevoInicio = new Nodo(objeto, nullptr, cabecera);
    tamanioDeLaListaDoblementeEnlazada++;

    if (cola == nullptr) {
        cola = nuevoInicio;
    }

    if (cabecera != nullptr) {
        cabecera->anterior = nuevoInicio;
    }

    cabecera = nuevoInicio;
}


/**
 * @brief inserta un dato al final de la lista
 * @tparam T dato que se desea insertar
 */
template<class T>
void ListaDEnlazada<T>::insertaFin(const T &objeto) {
    Nodo *nuevoDato;
    nuevoDato = new Nodo(objeto, cola, nullptr);
    tamanioDeLaListaDoblementeEnlazada++;

    if (cabecera == nullptr) {
        cabecera = nuevoDato;
    }
    if (cola != nullptr) {
        cola->siguiente = nuevoDato;
    }
    cola = nuevoDato;
}


/**
 * @brief inserta un dato en la posicion anterior a la que apunta el iterador
 * @param i iterador que apunta al nodo delante del cual se inserta
 * @tparam T dato que se desea insertar
 * @throw std::invalid_argument si el iterador no apunta a ningun nodo
 */
template<class T>
void ListaDEnlazada<T>::inserta(Iterador &i, const T &dato) {
    if (i.fin()) {
        throw std::invalid_argument("ListaDEnlazada<T>::inserta:Iterador incorrecto");
    }
    if (i.nodo == cabecera) {
        insertaInicio(dato);
    } else {
        Nodo *nuevo;
        nuevo = new Nodo(dato, i.nodo->anterior, i.nodo);
        i.nodo->anterior->siguiente = nuevo;
        i.nodo->anterior = nuevo;
        tamanioDeLaListaDoblementeEnlazada++;
    }
}


/**
 * @brief elimina el primer dato de la lista
 * @pre la lista no puede estar vacia
 * @throw std::invalid_argument si la lista esta vacia
 */
template<class T>

void ListaDEnlazada<T>::borraInicio() {
    if (!cabecera) {
        throw std::invalid_argument(
            "ListaDEnlazada<T>::borraInicio():No se puede borrar un elemento de una lista vacia");
    }
    Nodo *borrar;
    borrar = cabecera;
    cabecera = cabecera->siguiente;
    delete borrar;
    if (cabecera != nullptr) {
        cabecera->anterior = nullptr;
    } else {
        cola = nullptr;
    }
    tamanioDeLaListaDoblementeEnlazada--;
}


/**
 * @brief elimina el ultimo dato de la lista
 * @pre la lista no puede estar vacia
 * @throw std::invalid_argument si la lista esta vacia
 */
template<class T>
void ListaDEnlazada<T>::borraFinal() {
    if (cola == nullptr) {
        throw std::invalid_argument("ListaDEnlazada<T>::borraFinal: La lista esta vacia ");
    }
    tamanioDeLaListaDoblementeEnlazada--;
    Nodo *ultimo;
    ultimo = cola->anterior;
    delete cola;
    cola = ultimo;
    if (cola != nullptr) {
        cola->siguiente = nullptr;
    } else {
        cabecera = nullptr;
    }
}


/**
 * @brief elimina el dato al que apunta el iterador
 * @param i iterador que apunta al nodo que se borra
 * @throw std::invalid_argument si el iterador no apunta a ningun nodo o la lista esta vacia
 */
template<class T>
void ListaDEnlazada<T>::borra(Iterador &i) {
    if (i.nodo == nullptr) {
        throw std::invalid_argument("[ListaDEnlazada<T>::borra]:El iterador no apunta a ningun nodo");
    }
    if (cabecera == nullptr || cola == nullptr) {
        throw std::invalid_argument("[ListaDEnlazada<T>::borra]:La lista no tiene nodos");
    }

    if (cola == cabecera) {
        //es decir solo hay un elemento
        cabecera = nullptr;
        cola = nullptr; //las dos a nullptr porq se va a qedar la lista vacia
        tamanioDeLaListaDoblementeEnlazada = 0;
        delete i.nodo;
    } else {
        //segundo caso que el que se quiera borrar sea el ultimo de la lista
        if (i.nodo == cola) {
            borraFinal();
        } else {
            if (i.nodo == cabecera) {
                //tercer caso, que el que se quiera borrar sea el que apunte la cabecera
                borraInicio();
            } else {
                i.nodo->anterior->siguiente = i.nodo->siguiente;
                i.nodo->siguiente->anterior = i.nodo->anterior;
                tamanioDeLaListaDoblementeEnlazada--;
                delete i.nodo;
            }
        }
    }
}


/**
 * @brief devuelve el numero de elementos de la lista
 * @return tamaño de la lista
 */
template<class T>
unsigned long int ListaDEnlazada<T>::getTamanio() {
    return tamanioDeLaListaDoblementeEnlazada;
}


/**
 * @brief crea una nueva lista con los datos de la lista actual seguidos de los de otra lista
 * @param nuevaLista lista cuyos datos se añaden al final
 * @return nueva lista concatenada, las dos originales no se modifican
 */
template<typename T>
ListaDEnlazada<T> ListaDEnlazada<T>::concatena(const ListaDEnlazada<T> &nuevaLista) {
    ListaDEnlazada<T> listaFinal(*this); //hacemos una copia de this sin tocar el original

    Iterador iterador = nuevaLista.iterador();

    while (!iterador.fin()) {
        listaFinal.insertaFin(iterador.dato());
        iterador.siguiente();
    }
    return listaFinal;
}


/**
 * @brief sobrecarga del operador + para concatenar listas
 * @param nuevaLista lista cuyos datos se añaden al final
 * @return nueva lista concatenada, igual que concatena()
 */
template<typename T>
ListaDEnlazada<T> ListaDEnlazada<T>::operator+(const ListaDEnlazada<T> &nuevaLista) {
    return this->concatena(nuevaLista);
}

#endif //PRACTICA1_LISTADENLAZADA_H
