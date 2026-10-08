//
// Created by molina on 02/10/2026.
//

#include "Parque.h"
Parque::Parque():codigoParque(0),nombreDelParque(""),tamEspecies(0) {

}
Parque::Parque(int codigo, const std::string &nombreParque):
codigoParque(codigo),nombreDelParque(nombreParque),tamEspecies(0) {
}
Parque::Parque(const Parque &orig):
codigoParque(orig.codigoParque),nombreDelParque(orig.nombreDelParque),tamEspecies(orig.tamEspecies) {

}
Parque::~Parque() {

}
void Parque::insertaEspecie(Especie esp) {
    especies.insertar(esp);
}
bool Parque::existeNombreComun(const std::string &nombreComun) {
    if (nombreComun=="") {
        throw std::invalid_argument("Parque::existeNombreComun:El nombre pasado esta vacio");
    }
    for (int i=0;i<tamEspecies;i++) {
        if (especies[i].getNombreComun()==nombreComun) {
            return true;
        }
    }
    return false;
}
bool Parque::existeNombreCientifico(const std::string &nombreCientifico) {
    if (nombreCientifico=="") {
        throw std::invalid_argument("Parque::existeNombreCientifico:El nombre pasado esta vacio");
    }
    for (int i=0;i<tamEspecies;i++) {
        if (nombreCientifico==especies[i].getNombreCientifico()) {
            return true;
        }
    }
    return false;
}
