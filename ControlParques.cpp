//
// Created by molina on 13/10/2026.
//

#include "LectorCSV.h"

#include "ControlParques.h"

void ControlParques::enlazarLasEspeciesEnParques() {
    for (unsigned long int i = 0; i < varieties.tamañoLogic(); i++) {
        TiposPlanta tipoDePlanta = varieties[i].getTipoPlanta();
        if (tipoDePlanta == ARBUSTO || tipoDePlanta == CONIFERA || tipoDePlanta == PALMACEA ||
            tipoDePlanta == HERB_PERENNES || tipoDePlanta == FRONDOSA) {
            ListaDEnlazada<Parque>::Iterador itera = parks.iterador();
            while (!itera.fin()) {
                if (itera.dato().getCodigoParque() % 2 == 0) {
                    asignarEspecieParque(&varieties[i], &itera.dato());
                }
                itera.siguiente();
            }
        } else {
            if (tipoDePlanta == CACTACEA_SUCULENTA || tipoDePlanta == TAPIZANTE_TREPADORA || tipoDePlanta == HERB_ANUAL
                ||tipoDePlanta == HERB_ANUALES || tipoDePlanta == SUBTROPICAL_TROPICAL) {
                ListaDEnlazada<Parque>::Iterador itera = parks.iterador();
                while (!itera.fin()) {
                    if (itera.dato().getCodigoParque() % 2 != 0) {
                        asignarEspecieParque(&varieties[i], &itera.dato());
                    }
                    itera.siguiente();
                }
            }
        }
    }
}

ControlParques::ControlParques(const std::string &nombreFicheroEspecies,
                               const std::string &nomFicheroParques) : varieties(), parks() {
    LectorCSV carga;

    if (!carga.cargar(varieties, nombreFicheroEspecies)) {
        throw std::runtime_error("[ControlParques::ControlParques]:Error al cargar fichero de especies.");
    }

    varieties.ordenar();

    if (!carga.cargarParques(parks, nomFicheroParques))
        throw std::runtime_error("[ControlParques::ControlParques]:Error al cargar fichero de parques.");

    enlazarLasEspeciesEnParques();
}

ControlParques::ControlParques(const ControlParques &original) : varieties(original.varieties), parks(original.parks) {
}

ControlParques::~ControlParques() {
}

void ControlParques::asignarEspecieParque(Especie *PuntEsp, Parque *PuntParq) {
    if (PuntEsp == nullptr) {
        throw std::invalid_argument("ControlParques::asignarEspecieParque:Especie no existe");
    }
    if (PuntParq == nullptr) {
        throw std::invalid_argument("ControlParques::asignarEspecieParque:El parque no existe");
    }
    PuntParq->insertaEspecie(PuntEsp);
}

int ControlParques::contarEspecieParque(const std::string &nombreComun) {
    if (nombreComun == "") {
        throw std::invalid_argument("ControlParques::contarEspecieParque:La cadena esta vacia");
    }
    int contador = 0;
    ListaDEnlazada<Parque>::Iterador it = parks.iterador(); //para empezar en la cabecera de la funcion
    while (!it.fin()) {
        if (it.dato().existeNombreComun(nombreComun)) {
            contador++;
            it.siguiente(); //para pasar al siguiente nodo y realizar lo mismo
        }
    }
    return contador;
}

VDinamico<Especie *> ControlParques::listadoEspeciesSubNbre(const std::string &nombre) {
    VDinamico<Especie *> listado;
    for (int i = 0; i < varieties.tamañoLogic(); i++) {
        if (varieties[i].getNombreCientifico().find(nombre) != -1) {
            //¿find?
            listado.insertar(&varieties[i]);
        }
    }
    return listado;
}

Parque *ControlParques::buscarParque(const std::string &nombreParque) {
    ListaDEnlazada<Parque>::Iterador it = parks.iterador();
    while (!it.fin()) {
        //mientras sea distinto de nullptr
        if (it.dato().getNombreParque() == nombreParque) {
            return &it.dato();
        } else {
            it.siguiente();
        }
    }
    return nullptr;
}

void ControlParques::eliminaEspecieNombreComun(const std::string &nombreEspecieComun) {
    if (nombreEspecieComun == "")
        throw std::invalid_argument("[ControlParques::eliminaEspecieNombreComun]:nombre vacio.");

    ListaDEnlazada<Parque>::Iterador iterador = parks.iterador();
    //he tenido que hacer el constructor por defecto de iterador para esto

    for (int i = 0; i < varieties.tamañoLogic(); i++) {
        if (varieties[i].getNombreComun() == nombreEspecieComun)
            varieties.borrar(i);
    }

    while (!iterador.fin()) {
        iterador.dato().borraEspecie(nombreEspecieComun);
        iterador.siguiente();
    }
}

void ControlParques::eliminaParque(const std::string &nombreParque) {
    if (nombreParque == "") {
        throw std::invalid_argument("ControlParques::eliminaParque:El nombre del parque esta vacio ");
    }
    ListaDEnlazada<Parque>::Iterador iterador = parks.iterador();
    while (!iterador.fin()) {
        if (nombreParque == iterador.dato().getNombreParque()) {
            parks.borra(iterador);
        }
        iterador.siguiente();
    }
}
