#include <iostream>
#include "dataType.h"

 main() {
    // Creazione di una tupla
    Tuple<int, float, char> t(10, 3.14f, 'd');

    // Accesso agli elementi
    std::cout << "Elemento 0: " << t.get(0) << std::endl; // Stampa 10
    // std::cout << "Elemento 1: " << t.get(1) << std::endl; // Stampa 3.14
    // std::cout << "Elemento 2: " << t.get(2) << std::endl; // Stampa 'd'


    return 0;
}
