//
// Created by molina on 19/09/2026.
//

#ifndef PRACTICA1_ESPECIE_H
#define PRACTICA1_ESPECIE_H
#include <string>

class Especie {
private:
    std::string codigoEspecie;
    std::string nombreComun;
    std::string nombreCientifico;
    std::string tipoPlanta;

public:
    Especie();
    Especie(const std::string &codE,const  std::string &nComun, const std::string &nCientifico, const std::string &tipo);
    Especie(const Especie &orig);
    ~Especie();

    std::string getCodigoEspecie() const;
    void setCodigoEspecie(const std::string &codigo_especie);

    std::string getNombreComun() const;
    void setNombreComun(const std::string &nombre_comun);

    std::string getNombreCientifico() const;
    void setNombreCientifico(const std::string &nombre_cientifico);

    std::string getTipoPlanta() const;
    void setTipoPlanta(const std::string &tipo_planta);

    Especie& operator=(const Especie &original);
    bool operator<(const Especie &especie) const;
    bool operator==(const Especie &especie) const;

};





#endif //PRACTICA1_ESPECIE_H