#include "Coordinate.hpp"
#include <iostream>
#include "Label.hpp"
string toString(Label l) {
    return "\nLa Id de la Etiqueta es: "+ l.id_pkt+".\n Las Coordenadas son: "+ toString(l.coordinate)+".\n"+ "El DNI del cliente es: " + l.id_cliente +".\n";
}
