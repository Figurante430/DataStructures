#include <iostream>
using namespace std;
#include "Pila.hpp"


Pila::Pila(int& i) {
    i+=1; //i es el numero de furgonetas, sirve para identificar furgos.
    this->ID=i;
    this->state=state[0];
    this->top=N3-1;
}
Pila::Pila() {
    this->state=state[0];
    this->top=N3-1;
}
bool Pila::empty() {
    return top==N3-1;
}

void Pila::makenull() {
    this->top=N3-1;
    state = statePila[2];
}

bool Pila::full(){
    return this->top==0;
}

Paquete Pila::rtop() {
    if (empty()){
        cout<<"Error, the truck is empty"<<endl;}
    else {
        return paquetes[top];
    }
}

Paquete Pila::pop() {
    if (empty()){
        cout<<"Error, the truck is empty"<<endl;
    }
    else{
        top+=1;
        return paquetes[top-1];
    }
}

void Pila::push(Paquete p) {
    if (top==0){
        cout<<"Error, the truck is full"<<endl;
    }
    else {
        top -= 1;
        paquetes[top]=p;
        p.setState(1);
    }
}

string Pila::getState(){
    return this->state;
}

int Pila::getID() {
    return ID;
}
void Pila::setState(string estado){
    this->state = estado;
}

void Pila::cambiar_estado_paquetes(int i) {
    if (!empty()){
        int pos=N3-1;
        while(pos!=top){
            paquetes[pos].setState(i);
            pos-=1;
        }
        paquetes[top].setState(i);
    }
}
void Pila::entregar_paquetes(Cola &zona_entrega) {
    Pila auxp;

    while (!this->empty()){
        auxp.push(pop());
    }
    this->makenull();
    while (!auxp.empty()){
        Paquete p= auxp.pop();
        p.setState(3); //Cambio estado de pkts
        zona_entrega.enqueue(p);
    }
    setState(statePila[2]);
}

int Pila::getTop() {
    return top;
}

string Pila::returnState(string id_pkt) {
    if (!empty()) {
        int auxp;
        auxp = N3 - 1;
        while (auxp != top) {
            if (paquetes[auxp].getLabel().id_pkt == id_pkt) {
                return paquetes[auxp].getState();
            } else {
                auxp -= 1;
            }
        }
        return "No encontrado";
    } else {
        return "No encontrado";
    }
}
void Pila::show_Camion() {
    if (empty()){
        cout << "Camión vacio" << endl;
    }
    else {
        cout << "-------Camion " << ID << " -------" << endl;
        int auxp = N3 - 1;
        int i=1;
        while (auxp != top) {
            cout<< "-------Paquete " << i << " -------"<< endl;
            cout << paquetes[auxp].toString() << endl;
            cout <<"------------------------"<<endl;
            auxp-=1;
            i+=1;
        }
    }
}

string Pila::to_stringPila() {
    if (empty()){
        return "Pila Vacia\n";
    }
    else {
        string c ="";
        c+="Camion"+ to_string(ID)+"\n";
        int auxp = N3-1;
        while (auxp!= top) {
            c+= paquetes[auxp].toString();
            auxp-=1;
        }
        c+= paquetes[auxp].toString();
        c+="----------------------------\n";
        return c;
    }
}
Pila::~Pila() {}

//Deconstructor