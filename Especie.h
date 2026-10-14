//
// Created by molina on 19/09/2026.
//

#ifndef PRACTICA1_ESPECIE_H
#define PRACTICA1_ESPECIE_H
#include <string>
#include <stdexcept>

enum TiposPlanta {
    ARBUSTO, CONIFERA, FRONDOSA, SUBTROPICAL_TROPICAL, CACTACEA_SUCULENTA,
    TAPIZANTE_TREPADORA, HERB_PERENNES, PALMACEA, HERB_ANUAL, HERB_ANUALES, OTRO // cambio el no por OTRO
};

inline std::string pasarDePlantaAString(const TiposPlanta &tipo) {
    switch (tipo) {
        case ARBUSTO: return "ARBUSTO";
        case CONIFERA: return "CONIFERA";
        case FRONDOSA: return "FRONDOSA";
        case SUBTROPICAL_TROPICAL: return "SUBTROPICAL_TROPICAL";
        case CACTACEA_SUCULENTA: return "CACTACEA_SUCULENTA";
        case TAPIZANTE_TREPADORA: return "TAPIZANTE_TREPADORA";
        case HERB_PERENNES: return "HERB_PERENNES";
        case PALMACEA: return "PALMACEA";
        case HERB_ANUAL: return "HERB_ANUAL";
        case HERB_ANUALES: return "HERB_ANUALES";
        case OTRO: return "";
        default:
            throw std::runtime_error("Tipo de planta desconocido");
    }
}

inline TiposPlanta pasarDeStringAPlanta(const std::string &str) {
    if (str == "ARBUSTO") return ARBUSTO;
    else if (str == "CONIFERA") return CONIFERA;
    else if (str == "FRONDOSA") return FRONDOSA;
    else if (str == "SUBTROPICAL/TROPICAL") return SUBTROPICAL_TROPICAL;
    else if (str == "CACTACEA/SUCULENTA") return CACTACEA_SUCULENTA;
    else if (str == "TAPIZANTE/TREPADORA") return TAPIZANTE_TREPADORA;
    else if (str == "HERB_PERENNES") return HERB_PERENNES;
    else if (str == "PALMACEA") return PALMACEA;
    else if (str == "HERB_ANUAL") return HERB_ANUAL;
    else if (str == "HERB_ANUALES") return HERB_ANUALES;
    else if (str == "" || str == "OTRO") return OTRO;

    throw std::runtime_error("Tipo de planta desconocido: " + str);
}


class Especie {
private:
    std::string codigoEspecie;
    std::string nombreComun;
    std::string nombreCientifico;
    TiposPlanta tipoPlanta;

public:
    Especie();

    Especie(const std::string &codE, const std::string &nComun, const std::string &nCientifico,
            TiposPlanta tipo);

    Especie(const Especie &orig);

    ~Especie();

    std::string getCodigoEspecie() const;

    void setCodigoEspecie(const std::string &codigo_especie);

    std::string getNombreComun() const;

    void setNombreComun(const std::string &nombre_comun);

    std::string getNombreCientifico() const;

    void setNombreCientifico(const std::string &nombre_cientifico);

    TiposPlanta getTipoPlanta() const;

    void setTipoPlanta(TiposPlanta tipo_planta);

    Especie &operator=(const Especie &original);

    bool operator<(const Especie &especie) const;

    bool operator==(const Especie &especie) const;

};


#endif //PRACTICA1_ESPECIE_H
