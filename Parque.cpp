//
// Created by molina on 02/10/2026.
//

#include "Parque.h"
Parque::Parque():codigoParque(0),nombreDelParque(""),tamEspecies(0) {
    for (int i=0;i<TAMMAX;i++) {
        especies[i]=nullptr;
    }
}
Parque::Parque(int codigo, const std::string &nombreParque):
codigoParque(codigo),nombreDelParque(nombreParque),tamEspecies(0) {

    for (int i=0;i<TAMMAX;i++) {
        especies[i]=nullptr;
    }
}
Parque::Parque(const Parque &orig):
codigoParque(orig.codigoParque),nombreDelParque(orig.nombreDelParque),tamEspecies(orig.tamEspecies) {
    for (int i=0;i<orig.tamEspecies;i++) {
        especies[i]=orig.especies[i];
    }
}
Parque::~Parque() {
    for (int i=0;i<tamEspecies;i++) {
        especies[i]=nullptr;
    }
}
void Parque::insertaEspecie(Especie esp) {
    if (tamEspecies==TAMMAX) {
        throw std::length_error("Parque::InsertaEspecie::No caben mas especies en el parque");
    }
    especies[tamEspecies]=&esp;
    tamEspecies++;
}
bool Parque::existeNombreComun(const std::string &nombreComun) {
    if (nombreComun=="") {
        throw std::invalid_argument("Parque::existeNombreComun:El nombre pasado esta vacio");
    }
    bool existe=false;
    for (int i=0;i<tamEspecies;i++) {
        if (nombreComun==especies[i]->getNombreComun()) {
            return true;
        }
    }
    return existe;
}
bool Parque::existeNombreCientifico(const std::string &nombreCientifico) {
    if (nombreCientifico=="") {
        throw std::invalid_argument("Parque::existeNombreCientifico:El nombre pasado esta vacio");
    }
    bool existe=false;
    for (int i=0;i<tamEspecies;i++) {
        if (nombreCientifico==especies[i]->getNombreCientifico()) {
            return true;
        }
    }
    return existe;
}
