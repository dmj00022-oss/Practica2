//
// Created by molina on 02/10/2026.
//

#ifndef PRACTICA1_PARQUE_H
#define PRACTICA1_PARQUE_H
#include  "Especie.h"
#include <stdexcept>
#include "VDinamico.h"

class Parque {
public:

private:
    int codigoParque;
    std::string nombreDelParque;
    VDinamico<Especie> especies;
    int tamEspecies;

public:
    Parque();

    Parque(int codigo, const std::string &nombreParque);

    Parque(const Parque &orig);

    ~Parque();

    void insertaEspecie(Especie esp);

    bool existeNombreComun(const std::string &nombreComun);

    bool existeNombreCientifico(const std::string &nombreCientifico);
};


#endif //PRACTICA1_PARQUE_H
