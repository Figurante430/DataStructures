#include <string>
using namespace std;
#ifndef CLIONPROJECTS_COORDENATES_H
#define CLIONPROJECTS_COORDENATES_H

struct Coordinate{
    string longitudSTR;
    string latitudSTR;
    double longitudDEC;
    double latitudDEC;
};
string toString(Coordinate c);
#endif //CLIONPROJECTS_COORDENATES_H
