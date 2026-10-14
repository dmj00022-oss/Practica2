//Nombre:Luis Romero Sánchez. Correo:lrs00052@red.ujaen.es
//Nombre:David Molina Jiménez. Correo:dmj00022@red.ujaen.es

#include <iostream>
#include <iostream>
#include<sstream>
#include<string>
#include "VDinamico.h"
#include "Especie.h"
#include "LectorCSV.h"

//prueba 5
VDinamico<Especie *> getEspNComun(VDinamico<Especie> &vEspecie) {
    VDinamico<Especie *> auxiliar;
    for (int i = 0; i < vEspecie.tamañoLogic(); i++) {
        if (vEspecie[i].getNombreComun() != "")
            auxiliar.insertar(&vEspecie[i]);
    }
    return auxiliar;
}

//prueba 7
VDinamico<Especie *> buscaPalabra(VDinamico<Especie> &orden, const std::string &cad) {
    VDinamico<Especie *> sol;
    for (int i = 0; i < orden.tamañoLogic(); i++) {
        int j = 0;
        std::string cadenaEntera = orden[i].getNombreCientifico();
        std::string nombre = " ";

        while (j < cadenaEntera.length() && cadenaEntera[j] != ' ') {
            nombre += cadenaEntera[j];
            j++;
        }
        if (nombre == cad) {
            sol.insertar(&orden[i]);
        }
    }
    return sol;
}

int main() {
    try {
//Programa 1

        //Programa 2



    } catch (const std::out_of_range &fallo) {
        std::cerr << fallo.what() << std::endl;
    } catch (const std::invalid_argument &fallo) {
       std::cerr<<fallo.what()<<std::endl;
    }catch (const std::exception &fallo) {
        std::cerr << fallo.what() << std::endl;
    }

    return 0;
}