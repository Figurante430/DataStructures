
#include <iostream>
#include "Label.hpp"
//#include "auxLib.hpp"
using namespace std;
const string states[4] = {"At Central Station", "In distribution", "At Starting HUB", "Delivered"};
class Paquete {
	private:	
		Label l;
		string state;
	public: 
		Paquete();
        Paquete(string DNI);
		~Paquete();
		Label getLabel();
		string getState();
        void setState(int i);
        Label generarLabel();
        Label generarLabelDNI(string DNI);
        string toString();
};