//
// Created by molina on 19/09/2026.
//

#ifndef PRACTICA1_ESPECIE_H
#define PRACTICA1_ESPECIE_H
#include <string>
#include <stdexcept>

enum TiposPlanta {
    ARBUSTO, CONIFERA, PALMACEA, HERB_PERENNES, FRONDOSA, TAPIZANTE_TREPADORA,
    CACTACEA_SUCULENTA, SUBTROPICAL_TROPICAL, HERB_ANUAL, HERB_ANUALES, NO
};

inline std::string tipoPlantaToString(TiposPlanta tipo) {
    switch (tipo) {
        case ARBUSTO:               return "ARBUSTO";
        case CONIFERA:              return "CONIFERA";
        case PALMACEA:              return "PALMACEA";
        case HERB_PERENNES:         return "HERB_PERENNES";
        case FRONDOSA:              return "FRONDOSA";
        case TAPIZANTE_TREPADORA:   return "TAPIZANTE_TREPADORA";
        case CACTACEA_SUCULENTA:    return "CACTACEA_SUCULENTA";
        case SUBTROPICAL_TROPICAL:  return "SUBTROPICAL_TROPICAL";
        case HERB_ANUAL:            return "HERB_ANUAL";
        case HERB_ANUALES:          return "HERB_ANUALES";
        case NO:                    return "";
        default:
            throw std::runtime_error("Tipo de planta desconocido");
    }
}

inline TiposPlanta stringToTipoPlanta(const std::string& str) {
    if (str == "ARBUSTO") return ARBUSTO;
    else if (str == "CONIFERA") return CONIFERA;
    else if (str == "PALMACEA") return PALMACEA;
    else if (str == "HERB_PERENNES") return HERB_PERENNES;
    else if (str == "FRONDOSA") return FRONDOSA;
    else if (str == "TAPIZANTE_TREPADORA") return TAPIZANTE_TREPADORA;
    else if (str == "CACTACEA_SUCULENTA") return CACTACEA_SUCULENTA;
    else if (str == "SUBTROPICAL_TROPICAL") return SUBTROPICAL_TROPICAL;
    else if (str == "HERB_ANUAL") return HERB_ANUAL;
    else if (str == "HERB_ANUALES") return HERB_ANUALES;
    else if (str == "" || str == "NO") return NO;

    throw std::runtime_error("Tipo de planta desconocido: " + str);
}


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