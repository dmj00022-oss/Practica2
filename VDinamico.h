//
// Created by molina on 21/09/2026.
//

#ifndef PRACTICA1_VDINAMICO_H
#define PRACTICA1_VDINAMICO_H
#include <stdexcept>
#include "cmath"
#include <algorithm>
#include <climits>

template<class T>
class VDinamico {
private:
    unsigned long int tamañoFisico, tamañoLogico;
    T *vec;

    void cogerMemoria();

    void liberarMemoria();

    void tamanioBase(unsigned long int &tamañ);

    //aqui lo pasamos por referencia para cuando entre un numero, salga su potencia de 2 igual o mayor que el
public:
    VDinamico();

    VDinamico(unsigned long int tamañoLogic, T &dato);

    VDinamico(const VDinamico<T> &orig);

    VDinamico(const VDinamico<T> &origen, unsigned long int posicionInicial, unsigned long int numElementos);

    ~VDinamico();

    VDinamico<T> &operator=(const VDinamico<T> &origen);

    void insertar(const T &dato, unsigned long int posicion = UINT_MAX);

    T &operator[](unsigned long int pos);

    // se pone el & para poder escribir despues sobre el, si no lo tuviera solo podriamos leerlo, etnoces por ejemplo un Dato a= vec[3] , no nos dejaria hacer despues un a=100; ya que solo seria de lectura y no lectura y escritura
    T borrar(unsigned long int posicion = UINT_MAX);

    unsigned long int tamañoLogic();

    void ordenar();

    int busquedaDicotomica(const T &dato);
};


/**
 * @brief Segun el tamaño recibido calcula la potencia de 2 inmediatamente superior al numero dado o deja el mismo tamaño
 * @param tamanio, tamaño que recibe el metodo y aumenta si no es potencia de 2
 */
template<typename T>
void VDinamico<T>::tamanioBase(unsigned long int &tamanio) {
    if (tamanio == 0) {
        tamanio = 1;
        return;
    }

    if (tamanio == 1)
        return;

    bool potenciaDe2 = true;
    bool uno = false;
    unsigned long int aux = tamanio;
    for (unsigned long int i = 0; i < tamanio && potenciaDe2 && !uno; i++) {
        if (aux % 2 == 0) {
            aux = aux / 2;

            if (aux % 2 != 0) {
                if (aux == 1) {
                    uno = true;
                } else
                    potenciaDe2 = false;
            }
        } else
            potenciaDe2 = false;
    }

    if (!potenciaDe2) {
        unsigned long int tamaCorrecto = 1;
        for (unsigned long int i = 0; !potenciaDe2; i++) {
            tamaCorrecto = tamaCorrecto * 2;
            if (tamanio < tamaCorrecto)
                potenciaDe2 = true;
        }
        tamanio = tamaCorrecto;
    }
}


/**
 * @brief coge memoria cuando el vector dinamico se encuentra lleno, si hay 8 posiciones guarda hasta 16
 * @pre el tamaño logico y el fisico tienen que ser iguales
 */
template<class T>
void VDinamico<T>::cogerMemoria() {
    T *vAux;
    vAux = new T[tamañoFisico = tamañoFisico * 2];
    for (unsigned long int i = 0; i < tamañoLogico; i++) {
        vAux[i] = vec[i];
    }
    delete[] vec;
    vec = vAux;
}


/**
 * @brief reduce el tamaño fisico a la mitad
 * @pre el tamaño logico debe caber en el tamaño fisico reducido
 */
template<class T>
void VDinamico<T>::liberarMemoria() {
    T *aux;
    aux = new T[tamañoFisico = tamañoFisico / 2];
    for (unsigned long int i = 0; i < tamañoLogico; i++) {
        aux[i] = vec[i];
    }
    delete[] vec;
    vec = aux;
}


/**
 * @brief Crea un vector sin elementos y deja el tamaño fisico a 1 y el logico a 0
 */
template<class T>
VDinamico<T>::VDinamico() : tamañoFisico(1), tamañoLogico(0) {
    vec = new T[tamañoFisico];
}


/**
 * @brief rellena un vector con el mismo dato
 * @tparam T tipo de dato que almacena el vector
 * @param tamaño tamaño logico del vector
 * @param dato dato con el que rellenamos el vector
 */
template<class T>
VDinamico<T>::VDinamico(unsigned long int tamaño, T &dato) : tamañoLogico(tamaño) {
    tamanioBase(tamaño);
    vec = new T[tamañoFisico = tamaño];
    for (unsigned long int i = 0; i < tamañoLogico; i++) {
        vec[i] = dato;
    }
}


/**
 * @brief copia los datos de otro VDinamico
 * @param orig vector que es copiado
 */
template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &orig) : tamañoFisico(orig.tamañoFisico), tamañoLogico(orig.tamañoLogico) {
    vec = new T[tamañoFisico = orig.tamañoFisico];
    for (int i = 0; i < orig.tamañoLogico; i++) {
        vec[i] = orig.vec[i];
    }
}


/**
 * @brief copia una parte de otro VDinamico
 * @param origen vector que es copiado
 * @param posicionInicial  posicion desde la que se empieza a copiar el vector
 * @param numElementos numero de elementos que se van a copiar
 * @pre posInicial + numElementos no pueden superar el tamaño logico del vector dado
 * @throw std::out_of_range si el rango dado se sale del vector
 */
template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &origen, unsigned long int posicionInicial, unsigned long int numElementos) {
    if (numElementos + posicionInicial > origen.tamañoLogico || posicionInicial >= origen.tamañoLogico) {
        throw std::out_of_range(
            "VDinamico<T>::VDinamico: Has introducido un numero de elementos para copiar incorrecto");
    }
    unsigned long int tamañoo = numElementos;
    tamanioBase(tamañoo);
    tamañoLogico = numElementos;
    vec = new T[tamañoFisico = tamañoo];
    for (unsigned long int i = 0; i < tamañoLogico; i++) {
        // asi porque en vec[0] se le asignara el origen.vec[0+posicionInicial] que sera el primer dato que queremos copiar, asin sucesivamente
        vec[i] = origen.vec[i + posicionInicial];
    }
}


/**
 * @brief asigna los datos de una objeto a otro
 * @param origen vector copiado
 * @return referencia al objeto
 */
template<class T>
VDinamico<T> &VDinamico<T>::operator=(const VDinamico<T> &origen) {
    if (this != &origen) {
        delete[] vec;
        tamañoLogico = origen.tamañoLogico;
        vec = new T[tamañoFisico = origen.tamañoFisico];
        for (unsigned int i = 0; i < tamañoLogico; i++) {
            vec[i] = origen.vec[i];
        }
    }
    return *this;
}


/**
 * @brief permite acceso por posicion a cada elemento del vector
 * @param pos posicion del dato
 * @return referencia al dato de tipo T en la posicion dada
 * @throw std::out_of_range si pos es mayor o igual al tamaño lógico
 */
template<class T>
T &VDinamico<T>::operator[](unsigned long int posicionDelVector) {
    if (posicionDelVector >= tamañoLogico) {
        throw std::out_of_range("VDinamico<T>::operator[]:La posicion que has introducido es incorreta");
    }
    return vec[posicionDelVector];
}


/**
 * @brief inserta un dato en la posicion dada del vector
 * @tparam T tipo de dato que almacena el vector
 * @param dato dato de tipo T que se desea insertar
 * @param posicion posicion en la que se encuentra el dato
 */
template<class T>
void VDinamico<T>::insertar(const T &nuevoDato, unsigned long int posicion) {
    bool alFinal = (posicion == UINT_MAX);

    if (!alFinal && posicion > tamañoLogico) {
        throw std::out_of_range("VDinamico<T>::insertar: La posicion es incorrecta");
    }

    if (alFinal) {
        posicion = tamañoLogico;   // se traduce a "insertar justo después del último"
    }

    if (tamañoLogico == tamañoFisico) {
        cogerMemoria();
    }

    // Desplaza hacia la derecha todo lo que haya desde 'posicion' en adelante.
    // Si posicion == tamañoLogico (insertar al final), el bucle no llega a ejecutarse.
    for (unsigned long int i = tamañoLogico; i > posicion; i--) {
        vec[i] = vec[i - 1];
    }

    vec[posicion] = nuevoDato;
    tamañoLogico++;
}


/**
 * @brief Elimina un dato del vector y lo devuelve
 * @param posicion Posición a borrar. Si no se indica (UINT_MAX) se borra el último dato
 * @pre El vector no puede estar vacío
 * @return Copia del dato de tipo T que se ha borrado
 * @throw std::length_error Si el vector está vacío
 * @throw std::out_of_range Si posicion es mayor o igual que el tamaño lógico
 */
template<typename T>
T VDinamico<T>::borrar(unsigned long int posicion) {
    if (tamañoLogico == 0)
        throw std::length_error("[VDinamico<T>::borrar]:Error, el tamaño logico del vector es cero.");

    T aux;
    if (posicion == UINT_MAX) {
        aux = vec[tamañoLogico - 1];
        tamañoLogico--;
    } else {
        if (posicion >= tamañoLogico)
            throw std::out_of_range("[VDinamico<T>::borrar]:Error,La posicion erronea.");

        aux = vec[posicion];
        for (unsigned long int i = posicion; i < tamañoLogico - 1; i++) {
            vec[i] = vec[i + 1];
        }
        tamañoLogico--;
    }
    if (tamañoLogico * 3 < tamañoFisico)
        liberarMemoria();
    return aux;
}


/**
 * @brief Ordena el vector de menor a mayor
 * @pre La clase T debe tener implementado operator<
 */
template<class T>
void VDinamico<T>::ordenar() {
    std::sort(vec, vec + tamañoLogico);
}


/**
 * @brief libera la memoria que reserva el vector
 */
template<class T>
VDinamico<T>::~VDinamico() {
    if (vec)
        delete[] vec;
}


/**
 * @brief devuelve el tamaño logico del vector
 * @return numero de datos del vector
 */
template<class T>
unsigned long int VDinamico<T>::tamañoLogic() {
    return tamañoLogico; //
}


/**
 *@brief:Busca la posicion de un dato en un vector ordenado
 *@tparam T T tipo de dato que almacena el vector
 *@pre:El vector debe estar ordenado
 *@return:Devuelve la posicion donde se ha encontrado el dato, si no se encuentra devuelve -1
 */
template<typename T>
int VDinamico<T>::busquedaDicotomica(const T &dato) {
    int superior = tamañoLogico - 1;
    int inferior = 0;
    int posicion;
    for (unsigned long int i = 0; superior >= inferior; i++) {
        posicion = (inferior + superior) / 2;
        if (vec[posicion] == dato)
            return posicion;
        else {
            if (vec[posicion] < dato)
                inferior = posicion + 1;
            else
                superior = posicion - 1;
        }
    }
    return -1;
}


#endif //PRACTICA1_VDINAMICO_H
