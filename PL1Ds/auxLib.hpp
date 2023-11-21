#ifndef auxLib_hpp
#define auxLib_hpp
#include "Coordinate.hpp"



using namespace std;

const int N1= 1000;
const int N2= 73;

//Metodos para generar coordenadas:
double generarLatitud(void);
double generarLongitud(void);
string decimalToDMS(double decimal);


//Metodos auxiliares para generar etiqueta:
char generaLetraRand();
int generaIntRand();
char norteSur(double latitud);
char esteOeste(double longitud);
string fechaSys();

//Modulos para generar etiqueta completa:
string generarid_pkt(Coordinate c);
Coordinate generarCoordenadas();
string DNIrandom();

#endif