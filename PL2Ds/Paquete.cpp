#include "Paquete.hpp"
#include "auxLib.hpp"



Paquete::Paquete(){
	l = generarLabel();
	state = states[0];
}

Paquete::Paquete(string DNI){
    l = generarLabelDNI(DNI);
    state =states[0];
}

Paquete::~Paquete(){
}

Label Paquete::generarLabel() {
    Label e;
    e.coordinate = generarCoordenadas();
    e.id_pkt = generarid_pkt(e.coordinate);
    e.id_cliente = DNIrandom();
    return e;
}

Label Paquete::generarLabelDNI(string DNI) {
    Label e;
    e.coordinate = generarCoordenadas();
    e.id_pkt = generarid_pkt(e.coordinate);
    e.id_cliente = DNI;
    return e;
}
string Paquete::getState(){
	return state;
}

Label Paquete::getLabel(){
	return l;
}

void Paquete::setState(int i) {
    state=states[i];
}

string Paquete::toString() {
    return  "El estado del paquete es: " + getState() + ".\n" + "La etiqueta del paquete es: " + ::toString(getLabel()) + "\n";
}
