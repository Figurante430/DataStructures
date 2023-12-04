
#include <iostream>
#include <cmath>
#include <ctime>
#include <time.h>
#include "auxLib.hpp"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>

using namespace std;

//Metodos para generar coordenadas
double generarLongitud(void) {
    random_device rd;
    mt19937 gen(rd());

    double min = -5.83;
    double max = -5.48;

    std::uniform_real_distribution<double> dist(min, max);
    double longitud = dist(gen);
    return longitud;
}

double generarLatitud(void) {
	
	std::random_device rd;
    std::mt19937 gen(rd());

    double min = 40.85;
    double max = 41.07;

    std::uniform_real_distribution<double> dist(min, max);
    double latitud = dist(gen);
    return latitud;
}

string decimalToDMS(double decimal) {

    int degrees = static_cast<int>(decimal);  //cojo la parte entera del numero decimal que seran los grados

    double remaining = std::fabs(decimal - degrees) * 60.0; //resto la parte entera de los grados a decimal, se multiplica por 60 y almaceno su parte entera en minutes
    int minutes = static_cast<int>(remaining);
    degrees = abs(degrees);
    double secondsdec = (remaining - minutes) * 60.0; //calculo los segundos restando el decimal con los minutos a los minutos y multiplicando por 60

    int seconds = static_cast<int>(secondsdec);

    string c = to_string(degrees) + " "+ to_string(minutes) + " " + to_string(seconds);

    return c;
}

//-----------------------------------------------------------------------

//Metodos auxiliares para generar Etiqueta:

char generaLetraRand(){

    return ('A' + rand() % 26);   
}

int generaIntRand(){
	
	return (rand() % 10);
}

char norteSur(double latitud){
	if (latitud >= 40.962527) {
        return 'N';
    }
	else {
        return 'S';
    }
}

char esteOeste(double longitud){
	if (longitud < -5.660391) {
        return 'O';
    }
	else {
        return 'E';
    }
}

string fechaSys(){
    string mes, dia,anno;
    time_t now = time(NULL);
    tm *timeinfo = localtime(&now);
    string fecha;
    anno = to_string(timeinfo->tm_year+1900);
    if ((int)timeinfo->tm_mon + 1 < 10) {
        mes = "0" + to_string(timeinfo->tm_mon + 1);
    }
    else{
        mes = to_string(timeinfo->tm_mon + 1);
    }
    if((int)timeinfo->tm_mday < 10) {
        dia = "0" + to_string(timeinfo->tm_mday);
    }
    else {
        dia = to_string(timeinfo->tm_mday);
    }
    fecha = dia + mes + anno;
    return fecha;
}
//-------------------------------------------------------------------------------------------


//Modulos para generar etiqueta:
string generarid_pkt(Coordinate c) {
    //srand(time(NULL));
	string cad = "";
    for (int i=0;i<3;i++){
        cad+= to_string(generaIntRand());
    }
    cad+=generaLetraRand();
    cad+=fechaSys();
    cad+= norteSur(c.latitudDEC);
    cad+= esteOeste(c.longitudDEC);
    return cad;
}

Coordinate generarCoordenadas(){
	Coordinate c;
	
	c.latitudDEC = generarLatitud();
	c.longitudDEC = generarLongitud();
	c.latitudSTR = decimalToDMS(c.latitudDEC);
	c.longitudSTR = decimalToDMS(c.longitudDEC);
	
	return c;
}

string DNIrandom(){
    //srand(time(NULL));
    string c;
    for (int i=0;i<8;i++){
        c += to_string(generaIntRand());
    }
    c += generaLetraRand();
    return c;
}







