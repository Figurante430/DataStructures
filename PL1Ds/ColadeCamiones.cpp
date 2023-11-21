#include "ColadeCamiones.hpp"
ColaCamiones::ColaCamiones() {
    rear= nullptr; front = nullptr;
    numele=0;
}

void ColaCamiones::makenull() {
    while (front != nullptr) {
        pointerPilas aux =front;
        front = front->next;
        delete(aux);
    }
    cout << "La cola de camiones ha sido vaciada\n";
}

Pila ColaCamiones::rfront() {
    if (empty()) {
        cout << "La cola de camiones está vacía\n";
    }
    else{
        return front->p;
    }
}

void ColaCamiones::enqueue(Pila p) {
    p.cambiar_estado_paquetes(1);
    if (empty()) {
        pointerPilas ele = new struct nodePilas();
        front= ele;
        front->p=p;
        rear=front;
        front->next= nullptr;
        numele+=1;
    }
    else{
        pointerPilas ele =new struct nodePilas();
        rear->next= ele;
        rear= rear->next;
        rear->p=p;
        rear->next = nullptr;
        numele+=1;
    }
}

Pila ColaCamiones::dequeue() {
    if (empty()){
        cout<<"Nothing tu dequeue";
    }
    else if (front == rear) {
        Pila auxe;
        auxe = front->p;
        delete (front);
        front= nullptr, rear = nullptr;
        numele-=1;
        return auxe;
    }
    else {
        pointerPilas auxc;
        Pila auxe;
        auxc = front;
        auxe = front->p;
        front = front->next;
        delete (auxc);
        numele-=1;
        return auxe;
    }
}

bool ColaCamiones::empty() {
    return front== nullptr;
}

Pila ColaCamiones::extract_truck(int identificador) {
    if (front == rear) {
        pointerPilas auxe=front;
        if (auxe->p.getID()==identificador) {
            return dequeue();
        }
    }
    else if  (front->p.getID()==identificador){
        pointerPilas auxp=front;
        Pila temp;
        front = front->next;
        temp=auxp->p;
        delete (auxp);
        return temp;
    }
    else if (!empty()){
        pointerPilas auxe=front;
        pointerPilas temp;
        Pila auxp;
        while ((auxe->next->p.getID()!= identificador) && (auxe->next !=nullptr)) {
            auxe=auxe->next;
        }
        if (auxe->next->next == nullptr){
            temp=auxe->next;
            auxe->next = nullptr;
            auxp=temp->p;
            delete(temp);
            return auxp;
        }
        else {
            temp = auxe->next;
            auxe->next = auxe->next->next;
            auxp = temp->p;
            delete (temp);
            return auxp;
        }
    }
}



string ColaCamiones::returnState(string id_pkt){
    if (!empty()) {
        pointerPilas auxp;
        Pila p;
        auxp = front;
        while (auxp->next != nullptr) {
            p = auxp->p;
            string state = p.returnState(id_pkt);
            if (state != "No encontrado") {
                return state;
            }
            auxp = auxp->next;
        }
        p = auxp->p;
        string state = p.returnState(id_pkt);
        if (state != "No encontrado") {
            return state;
        } else {
            return "No encontrado";
        }
    }
    else{
        return "No encontrado";
    }
}

void ColaCamiones::showCamiones(){
    if (empty()){
        cout << "No hay camiones" << endl;
    }
    else {
        pointerPilas auxp;
        auxp=front;
        while (auxp->next != nullptr){
            cout << "-------Camión " << auxp->p.getID() << " -------" << endl;
            auxp=auxp->next;
        }
        cout << "-------Camión " << auxp->p.getID() << " -------" << endl;
    }
}
void ColaCamiones::mostrarContentCamiones(){
    if (empty()){
        cout << "------- " << "Camión vacío" << " -------" << endl;
    }
    else{
        pointerPilas auxp = front;
        while (auxp->next!= nullptr){
            auxp->p.show_Camion();
            auxp=auxp->next;
        }
        auxp->p.show_Camion();
    }
}

