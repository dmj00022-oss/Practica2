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
        std::string nombre = "";

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
        //Prueba 1
        VDinamico<Especie> especie;

        LectorCSV a;

        //Prueba 2
        std::cout << "Lectura del fichero " << std::endl;
        if (!a.cargar(especie, "../arbolado-especies.csv")) {
            std::cout << "No se ha podido extraer el fichero ";
            return 1;
        }

        std::cout << "El numero de especies totales leidas son" << especie.tamañoLogic() << std::endl;

        std::cout << std::endl;

        std::cout << "Los identificadores de los primeros 50 elementos del vector son: " << std::endl;

        for (int i = 0; i < 50; i++) {
            std::cout << i << " : " << especie[i].getCodigoEspecie() << std::endl;
        }

        std::cout << std::endl;

        //prueba 3
        std::cout << "El vector dinamico de especies ordenado es: " << std::endl;
        especie.ordenar();

        for (int i = 0; i < 50; i++) {
            std::cout << i << " : " << especie[i].getCodigoEspecie() << " / "
                    << especie[i].getNombreComun() << " / "
                    << especie[i].getNombreCientifico() << " / "
                    << especie[i].getTipoPlanta() << std::endl;
        }

        //prueba 4
        std::string codigos[] = {"CTA", "DMD", "HCN", "NDOF", "JAX"};


        std::cout << std::endl;
        std::cout << "La buesqueda de los codigos son: " << std::endl;


        for (int i = 0; i < 5; i++) {
            Especie buscar;
            buscar.setCodigoEspecie(codigos[i]);
            int pos = 0;
            pos = especie.busquedaDicotomica(buscar);
            if (pos == -1) {
                std::cout << "El codigo " << codigos[i] << "no se encuentra en el vector " << std::endl;
            } else {
                std::cout << "La posicion de " << codigos[i] << " es :" << pos << std::endl;
            }
        }

        //prueba 5
        VDinamico<Especie *> especies;
        especies = getEspNComun(especie);

         std::cout<<"Vector de especies que tienen nombre comun: ";
        for (int i=0;i<especies.tamañoLogic();i++) { //Ponemos hasta tamañoLogic por si no hay suficientes elementos
          std::cout<<especies[i]->getNombreComun()<<" / "
        <<especies[i]->getCodigoEspecie()<<std::endl;
        }

        std::cout << "El tamanio de dicho vector es: " << especies.tamañoLogic() << std::endl;

        //prueba 6 metodo burbuja
        VDinamico<Especie> burbuj;
        a.cargar(burbuj, "../arbolado-especies.csv");
        //tengo en cuenta que se pueden cargar archivos ya que lo he hecho antes
        for (int i = 0; i < burbuj.tamañoLogic() - 1; i++) {
            for (int j = 0; j < burbuj.tamañoLogic() - i - 1; j++) {
                if (burbuj[j].getCodigoEspecie() < burbuj[j + 1].getCodigoEspecie()) {
                    Especie aux;
                    aux = burbuj[j];
                    burbuj[j] = burbuj[j + 1];
                    burbuj[j + 1] = aux;
                }
            }
        }

        std::cout << "Los 50 mayores elementos son: " << std::endl;
        std::cout << std::endl;

        for (int i = 0; i < 50; i++) {
            std::cout << i << " : " << burbuj[i].getCodigoEspecie() << " / "
                    << burbuj[i].getNombreComun() << " / "
                    << burbuj[i].getNombreCientifico() << " / "
                    << burbuj[i].getTipoPlanta() << std::endl;
        }

        //prueba 7
        VDinamico<Especie *> prueba7 = buscaPalabra(especie, "Jasminum");
        std::cout << "El numero de Jasminun es: " << prueba7.tamañoLogic() << std::endl;
    } catch (const std::out_of_range &fallo) {
        std::cerr << fallo.what() << std::endl;
    } catch (const std::exception &fallo) {
        std::cerr << fallo.what() << std::endl;
    }

    return 0;
}