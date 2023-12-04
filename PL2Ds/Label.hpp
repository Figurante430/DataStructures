#include <iostream>
#include "Coordinate.hpp"
using namespace std;
#ifndef PL1DS_LABEL_HPP
#define PL1DS_LABEL_HPP
struct Label{
    string id_cliente;
    Coordinate coordinate;
    string id_pkt;
};
string toString (Label l);
#endif //PL1DS_LABEL_HPP
