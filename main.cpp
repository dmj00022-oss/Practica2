//Nombre:Luis Romero Sánchez. Correo:lrs00052@red.ujaen.es
//Nombre:David Molina Jiménez. Correo:dmj00022@red.ujaen.es

#include <iostream>
#include <iostream>
#include<sstream>
#include<string>
#include "VDinamico.h"
#include "Especie.h"
#include "LectorCSV.h"
#include "ControlParques.h"

//prueba 5
VDinamico<Especie *> getEspNComun(VDinamico<Especie> &vEspecie) {
    VDinamico<Especie *> auxiliar;
    for (int i = 0; i < vEspecie.tamanioLogic(); i++) {
        if (vEspecie[i].getNombreComun() != "")
            auxiliar.insertar(&vEspecie[i]);
    }
    return auxiliar;
}

//prueba 7
VDinamico<Especie *> buscaPalabra(VDinamico<Especie> &orden, const std::string &cad) {
    VDinamico<Especie *> sol;
    for (int i = 0; i < orden.tamanioLogic(); i++) {
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

//creamos este metodo para no tener que repetir codigo al imprimir el primer metodo
void mostrarPrueba1(const ListaDEnlazada<int> listaEnteros) {
    ListaDEnlazada<int>::Iterador it = listaEnteros.iterador();
    while (!it.fin()) {
        std::cout << it.dato() << " ";
        it.siguiente();
    }
}

int main() {
    try {
        //Programa 1

        std::cout<<"Programa de prueba I: probar la lista doblemente enlazada con enteros: "<<std::endl;
        //a)
        ListaDEnlazada<int> prog1;
        ListaDEnlazada<int>::Iterador it1;
        //b)
        for (int i = 101; i <= 200; i++) {
            prog1.insertaFin(i);
        }
        mostrarPrueba1(prog1);
        //c)
        std::cout << std::endl;
        std::cout << "SEGUNDA PRUEBA: " << std::endl;
        for (int i = 98; i >= 1; i--) {
            prog1.insertaInicio(i);
        }
        mostrarPrueba1(prog1);

        //d)
        std::cout << std::endl;
        std::cout << "TERCERA PRUEBA: " << std::endl;
        it1 = prog1.iterador();

        while (it1.dato() != 101) {
            it1.siguiente();
        }
        prog1.inserta(it1, 100);
        mostrarPrueba1(prog1);

        //e)
        std::cout << std::endl;
        std::cout << "CUARTA PRUEBA: " << std::endl;
        it1 = prog1.iterador();
        bool asignado = false;
        while (!it1.fin() && !asignado) {
            if (it1.dato() == 98) {
                it1.siguiente();
                prog1.inserta(it1, 99);
                asignado = true;
            } else {
                it1.siguiente();
            }
        }
        mostrarPrueba1(prog1);
        //f)
        std::cout << std::endl;
        std::cout << "QUINTA PRUEBA: " << std::endl;
        it1 = prog1.iterador();
        for (int i = 0; i < 10; i++) {
            prog1.borraInicio();
            it1.siguiente();
        }
        it1 = prog1.iterador();

        for (int i = 0; i < 10; i++) {
            prog1.borraFinal();
            it1.siguiente();
        }
        mostrarPrueba1(prog1);
        //g)
        std::cout << std::endl;
        std::cout << "SEXTA PRUEBA: " << std::endl;
        it1 = prog1.iterador();

        while (!it1.fin()) {
            if (it1.dato() % 10 == 0) {
                prog1.borra(it1);
            }
            it1.siguiente();
        }
        mostrarPrueba1(prog1);

        std::cout << std::endl;
        std::cout << std::endl;


        //Programa 2
        //prueba 1
        std::cout << "Programa 2:Funcionalidad de ControlParques: " << std::endl;
        ControlParques controlDelParque("../arbolado-especies.csv", "../parques.csv");
        //el constructor de ControlParques llama a ordenar de vDinamico de Especies
        std::cout << "El vector ordenado es :" << std::endl;


        Parque *p = controlDelParque.buscarParque("PARQUE PRINCESA LEONOR");
        std::cout << std::endl;
        if (p) {
            if (p->existeNombreComun("Eucalipto rojo"))
                std::cout <<"En el PARQUE PRINCESA LEONOR se encuentra la especie cuyo nombre común es eucalipto rojo. " <<std::endl;
            else
                std::cout <<"En el PARQUE PRINCESA LEONOR no se encuentra la especie cuyo nombre común es eucalipto rojo. "<< std::endl;
        }

        if (p) {
            if (p->existeNombreComun("Arce de sierra"))
                std::cout <<"En el PARQUE PRINCESA LEONOR se encuentra la especie cuyo nombre común es Arce de sierra. " <<std::endl;
            else
                std::cout <<"En el PARQUE PRINCESA LEONOR no se encuentra la especie cuyo nombre común es Arce de sierra. "<< std::endl;
        }

        //prueba 2
        p = controlDelParque.buscarParque("PARQUE MADRID RIO");
        if (p) {
            if (p->existeNombreCientifico("Hebe floribunda"))
                std::cout <<"En el PARQUE MADRID RIO se encuentra la especie cuyo nombre cientifico es Hebe floribunda." <<std::endl;
            else
                std::cout <<"En el PARQUE MADRID RIO no se encuentra la especie cuyo nombre cientifico es Hebe floribunda."<< std::endl;
        }

        if (p) {
            if (p->existeNombreCientifico("Ananas comosa"))
                std::cout << "En el PARQUE MADRID RIO se encuentra la especie cuyo nombre cientifico es Ananas comosa."<< std::endl;
            else
                std::cout <<"En el PARQUE MADRID RIO no se encuentra la especie cuyo nombre cientifico es Ananas comosa." <<std::endl;
        }

        //prueba 3
        Parque *pa3 = controlDelParque.buscarParque("PARQUE JUAN CARLOS III");
        if (pa3) {
            std::cout << "El codigo del parque PARQUE JUAN CARLOS III es: " << pa3->getCodigoParque();
        } else {
            std::cout << "No se ha encontrado el PARQUE JUAN CARLOS III " << std::endl;
        }
        Parque *pa4 = controlDelParque.buscarParque("VIVERO DE MIGAS CALIENTES");
        if (pa4) {
            std::cout << "El codigo del parque VIVERO DE MIGAS CALIENTES es: " << pa4->getCodigoParque();
        } else {
            std::cout << "No se ha encontrado el VIVERO DE MIGAS CALIENTES" << std::endl;
        }


        //prueba 4
        VDinamico<Especie *> espe = controlDelParque.listadoEspeciesSubNbre("rosa");
        std::cout << "Especies con subnombre [rosa]: " << std::endl;
        for (int i = 0; i < espe.tamanioLogic(); i++) {
            std::cout << "Posicion: " << i << std::endl;
            std::cout << " Codigo= " << espe[i]->getCodigoEspecie() << std::endl;
            std::cout << " NombreCient.=" << espe[i]->getNombreCientifico() << std::endl;
            std::cout << " NombreComun=" << espe[i]->getNombreComun() << std::endl;
            std::cout << " TipoPlanta=" << pasarDePlantaAString(espe[i]->getTipoPlanta()) << std::endl;

            std::cout << std::endl;
        }
        //prueba 5
        std::cout << std::endl;
        int numAbetos = controlDelParque.contarEspecieParque("Abeto");
        std::cout << "El numero de especies con nombre comun abeto es: " << numAbetos << std::endl;

        //prueba 6
        controlDelParque.eliminaParque("VIVERO DE MIGAS CALIENTES");
        Parque *pa6 = controlDelParque.buscarParque("VIVERO DE MIGAS CALIENTES");
        if (pa6) {
            std::cout << "VIVERO DE MIGAS CALIENTES no esta eliminado ";
        } else {
            std::cout << "VIVERO DE MIGAS CALIENTES  esta eliminado ";
        }

    } catch (const std::out_of_range &fallo) {
        std::cerr << fallo.what() << std::endl;
    } catch (const std::invalid_argument &fallo) {
        std::cerr << fallo.what() << std::endl;
    } catch (const std::exception &fallo) {
        std::cerr << fallo.what() << std::endl;
    }

    return 0;
}
