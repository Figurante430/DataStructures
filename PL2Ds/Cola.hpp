#ifndef PL1DS_PCS_H
#define PL1DS_PCS_H
#include <iostream>
#include "Paquete.hpp"
//#include "auxLib.hpp"
using namespace std;
struct node {
    Paquete p;
    struct node *next;
};

typedef struct node *pointer;

class Cola {
private:
    int numele;
    pointer rear, front;
public:
    Cola();
    void makenull(void);
    Paquete rfront (void);
    void enqueue (Paquete p);
    Paquete dequeue (void);
    int getNumEle();
    void showCola();
    bool empty (void);
    string returnState(string id_pkt);
    string toString();
};

#endif //PL1DS_PCS_H
