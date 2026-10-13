//
// Created by molina on 13/10/2026.
//

#include "ControlParques.h"
ControlParques(const std::string &nomFichEspecies, const std::string nomFichParques);
ControlParques(const ControlParques &original);
~ControlParques();
void ControlParques::asignarEspecieParque(Especie *esp, Parque *parq) {
if (esp==nullptr) {
    throw std::invalid_argument("ControlParques::asignarEspecieParque:Especie no existe");
}
    if (parq==nullptr) {
        throw std::invalid_argument("ControlParques::asignarEspecieParque:El parque no existe");
    }
    parq->insertaEspecie(esp);
}
int ControlParques::contarEspecieParque(const std::string &nomComun) {
    if (nomComun==" ") {
        throw std::invalid_argument("ControlParques::contarEspecieParque:La cadena esta vacia");
    }
   int cont=0;
    ListaDEnlazada<Parque>::Iterador it=parks.iterador(); //para empezar en la cabecera de la funcion
    while (!it.fin()) {

    }
}
VDinamico<Especie*>listadoEspeciesSubNbre(const std::string &nombre);
Parque *buscarParque(const std::string nombreParque);
void eliminaEspecieNombreComun(const std::string &nombreEspecieComun);
