//
// Created by molina on 13/10/2026.
//

#ifndef PRACTICA1_CONTROLPARQUES_H
#define PRACTICA1_CONTROLPARQUES_H
#include "Parque.h"
#include "Especie.h"
#include "ListaDEnlazada.h"

class ControlParques {
private:
    VDinamico<Especie> varieties;
    ListaDEnlazada<Parque> parks;
public:
    ControlParques(const std::string &nombreFicheroEspecies, const std::string &nomFicheroParques);
    ControlParques(const ControlParques &original);
    ~ControlParques();
    void asignarEspecieParque(Especie *esp, Parque *parq);
    int contarEspecieParque(const std::string &nomComun);
    VDinamico<Especie*>listadoEspeciesSubNbre(const std::string &nombre);
    Parque *buscarParque(const std::string &nombreParque);
    void eliminaEspecieNombreComun(const std::string &nombreEspecieComun);
    void eliminaParque(const std::string &nombreParque);
    void enlazarLasEspeciesEnParques();

};

#endif //PRACTICA1_CONTROLPARQUES_H