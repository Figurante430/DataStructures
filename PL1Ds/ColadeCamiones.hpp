
#ifndef PL1DS_COLADEPILAS_HPP
#define PL1DS_COLADEPILAS_HPP
#include "auxLib.hpp"
#include "Pila.hpp"
#include "Cola.hpp"

struct nodePilas {
    Pila p;
    nodePilas *next;
};

typedef struct nodePilas *pointerPilas;

class ColaCamiones {
private:
    int numele;
    pointerPilas rear, front;
public:
    ColaCamiones();
    void makenull(void);
    Pila rfront (void);
    void enqueue (Pila p);
    Pila dequeue (void);
    bool empty (void);
    Pila extract_truck (int identificador);
    string returnState(string id_pkt);
    void showCamiones();
    void mostrarContentCamiones();
    string toString ();
};
#endif //PL1DS_COLADEPILAS_HPP
