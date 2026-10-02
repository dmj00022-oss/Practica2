//
// Created by molina on 19/09/2026.
//

#include "Especie.h"

Especie::Especie():codigoEspecie(""),nombreComun(""),nombreCientifico(""),tipoPlanta("") {

}

Especie::Especie(const std::string &codE,const std::string &nComun,const std::string &nCientifico,
    const std::string &tipo):codigoEspecie(codE),nombreComun(nComun),nombreCientifico(nCientifico),
    tipoPlanta(tipo) {

}

Especie::Especie(const Especie &orig):codigoEspecie(orig.codigoEspecie),nombreComun(orig.nombreComun),
    nombreCientifico(orig.nombreCientifico),tipoPlanta(orig.tipoPlanta) {

}

Especie::~Especie() {

}

std::string Especie::getCodigoEspecie() const {
    return codigoEspecie;
}

void Especie:: setCodigoEspecie(const std::string &codigo_especie) {
    this->codigoEspecie = codigo_especie;
}

std::string Especie::getNombreComun() const {
    return nombreComun;
}

void Especie::setNombreComun(const std::string &nombre_comun) {
    this->nombreComun = nombre_comun;
}

std::string Especie::getNombreCientifico() const{
    return nombreCientifico;
}

void Especie::setNombreCientifico(const std::string &nombre_cientifico) {
    this->nombreCientifico = nombre_cientifico;
}

std::string Especie::getTipoPlanta() const {
    return tipoPlanta;
}

void Especie::setTipoPlanta(const std::string &tipo_planta) {
    this->tipoPlanta = tipo_planta;
}

Especie& Especie::operator=(const Especie &original) {
    if (this!=&original) {
        codigoEspecie=original.codigoEspecie;
        nombreComun=original.nombreComun;
        nombreCientifico=original.nombreCientifico;
        tipoPlanta=original.tipoPlanta;
    }
    return *this;
}

bool Especie::operator<(const Especie &especie) const {
    return (this->getCodigoEspecie()<especie.getCodigoEspecie());
}

bool Especie::operator==(const Especie &especie) const {
    return (this->getCodigoEspecie() == especie.getCodigoEspecie()
          );
}