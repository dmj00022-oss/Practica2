//
// Created by molina on 02/10/2026.
//

#ifndef PRACTICA1_PARQUE_H
#define PRACTICA1_PARQUE_H
#include  "Especie.h"
#include <stdexcept>
#include "VDinamico.h"

class Parque {

private:
    int codigoParque;
    std::string nombreDelParque;

    VDinamico<Especie*> especies;

public:
    Parque();

    Parque(int codigo, const std::string &nombreParque);

    Parque(const Parque &orig);

    ~Parque();

    void insertaEspecie(Especie *esp);

    bool existeNombreComun(const std::string &nombreComun);

    bool existeNombreCientifico(const std::string &nombreCientifico);

    int getCodigoParque() const;
    void setCodigoParque(int codigo_parque);

    std::string getNombreParque() const;
    void setNombreParque(const std::string &nombre_del_parque);

    void borraEspecie(const std::string &nombre_comun);  //Parejas , pone david q este hay q hacerlo al estar en parejas pero no se donde sale exactamente eso en el pdf
};


#endif //PRACTICA1_PARQUE_H
