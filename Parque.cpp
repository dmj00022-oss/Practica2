//
// Created by molina on 02/10/2026.
//

#include "Parque.h"
Parque::Parque():codigoParque(0),nombreDelParque(" ") {  //si tenemos q hacer lo q hace david de poner tmb el vector, en el defecto como lo ponemos?

}

Parque::Parque(int codigo, const std::string &nombreParque):codigoParque(codigo),nombreDelParque(nombreParque){
}

Parque::Parque(const Parque &orig):codigoParque(orig.codigoParque),nombreDelParque(orig.nombreDelParque),especies(orig.especies) {

}

Parque::~Parque() {

}

void Parque::insertaEspecie(Especie *esp) {
    if (esp==nullptr) {
        throw std::invalid_argument("Parque::insertaEspecie: La especie no existe");
    }
    especies.insertar(esp);
}

bool Parque::existeNombreComun(const std::string &nombreComun) {
    if (nombreComun=="") {
        throw std::invalid_argument("Parque::existeNombreComun:El nombre pasado esta vacio");
    }
    for (int i=0;i<especies.tamañoLogic();i++) {
        if (especies[i]->getNombreComun()==nombreComun) {
            return true;
        }
    }
    return false;
}

bool Parque::existeNombreCientifico(const std::string &nombreCientifico) {
    if (nombreCientifico=="") {
        throw std::invalid_argument("Parque::existeNombreCientifico:El nombre pasado esta vacio");
    }
    for (int i=0;i<especies.tamañoLogic();i++) {
        if (nombreCientifico==especies[i]->getNombreCientifico()) {
            return true;
        }
    }
    return false;
}

int Parque::getCodigoParque() const {
    return codigoParque;
}

void Parque::setCodigoParque(int codigo_parque) {
    codigoParque = codigo_parque;
}

std::string Parque::getNombreParque() const {
    return nombreDelParque;
}

void Parque::setNombreParque(const std::string &nombre_del_parque) {
    nombreDelParque = nombre_del_parque;
}


void Parque::borraEspecie(const std::string &nombre_comun) {
    for (int i=0;i<especies.tamañoLogic();i++) {
        if (especies[i]->getNombreComun()==nombre_comun) {
            especies.borrar(i);
            i--;
        }
    }
}