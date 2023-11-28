#include <iostream>
using namespace std;
#include "Cola.hpp"


Cola::Cola() {
    rear= nullptr; front = nullptr;
    numele=0;
}

void Cola::makenull() {
    numele= 0;
    while (front != nullptr) {
        pointer aux =front;
        front = front->next;
        delete(aux);
    }
    cout << "La cola ha sido vaciada\n";
}

Paquete Cola::rfront() {
    if (empty()) {
        cout << "La cola está vacía\n";
    }
    else{
        return front->p;
    }
}

void Cola::enqueue(Paquete p) {
    if (empty()) {
        pointer ele = new struct node();
        front= ele;
        front->p=p;
        rear=front;
        front->next= nullptr;
        numele+=1;
    }
    else{
        pointer ele =new struct node();
        rear->next= ele;
        rear= rear->next;
        rear->p=p;
        rear->next = nullptr;
        numele+=1;
    }
}

Paquete Cola::dequeue() {
    if (empty()){
        cout<<"Nothing tu dequeue";
    }
    else if (front == rear) {
        Paquete auxe;
        auxe =front->p;
        delete (front);
        front= nullptr, rear = nullptr;
        numele-=1;
        return auxe;
    }
    else {
        pointer auxc;
        Paquete auxe;
        auxc = front;
        auxe = front->p;
        front = front->next;
        delete (auxc);
        numele-=1;
        return auxe;
    }
}

int Cola::getNumEle(){
    return this->numele;
}

bool Cola::empty() {
    return front== nullptr;
}

void Cola::showCola() {
    if (empty()){
        cout<< "La cola esta vacía"<<endl;
    }
    else{
        cout << "The number of packets in the queue is:"<< numele << endl;
        pointer auxc;
        auxc = front;
        int i=1;
        while(auxc->next != nullptr){
            cout << "------- " << "Paquete " << i << " -------" <<endl;
            cout << "La ID del paquete es: " <<auxc->p.getLabel().id_pkt << endl;
            cout << "El DNI del cliente es: " << auxc->p.getLabel().id_cliente << endl;
            cout << "------------------------------" << endl;
            auxc = auxc->next;
            i+=1;
        }
        cout << "------- " << "Paquete " << i << " -------" <<endl;
        cout << "La ID del paquete es: " <<auxc->p.getLabel().id_pkt << endl;
        cout << "El DNI del cliente es: " << auxc->p.getLabel().id_cliente << endl;
        cout << "------------------------------" << endl;
    }
}
string Cola::returnState(string id_pkt){
    if (!empty()){
        pointer auxc;
        Paquete auxe;
        auxc=front;
        while (auxc->next!=nullptr){
            auxe=auxc->p;
            if (auxe.getLabel().id_pkt == id_pkt){
                return auxe.getState();
            }
            else {
                auxc= auxc->next;
            }
        }
        auxe=auxc->p;
        if (auxe.getLabel().id_pkt == id_pkt){
            return auxe.getState();
        }
        return "No encontrado";
    }
    else{
        return "No encontrado";
    }
}
string Cola::toString() {
    if (empty()){
       return "Cola Vacía\n";
    }
    else if (front==rear){
        return front->p.toString();
    }
    else {
        pointer auxp = front;
        string c="";
        while (auxp->next!= nullptr){
            c+=auxp->p.toString();
            auxp=auxp->next;
        }
        c+=auxp->p.toString();
        return c;
    }
}

