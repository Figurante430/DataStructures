#ifndef CLIONPROJECTS_TRUCK_H
#define CLIONPROJECTS_TRUCK_H
#include <iostream>
//#include "Paquete.hpp"
#include "Cola.hpp"
//#include "auxLib.hpp"
using namespace std;

const int N3 = 24;
const string statePila[3] = {"At HUB Zone", "In distribution", "Free"};

class Pila{
	private:
	    Paquete paquetes[N3];
	    int top;
        int ID;
	    string state;
	public:

        Pila();
        Pila(int& i);
	    void makenull();
	    bool empty();
	    void push (Paquete pl);
	    Paquete pop();
	    Paquete rtop();
        string getState();
        void setState(string estado);
        int getTop();
        int getID();
        string returnState(string id_pkt);
        bool full();
        void cambiar_estado_paquetes (int i);
        void entregar_paquetes(Cola &zona_entrega);
        void show_Camion ();
        string to_stringPila ();
	    ~Pila();
};

#endif //CLIONPROJECTS_TRUCK_H
