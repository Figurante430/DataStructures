#include "ColadeCamiones.hpp"
#include "Pila.hpp"
#include "auxLib.hpp"
#include <iostream>
void menu(void);
void menuZona();
void direccion_HUB(Cola &Central, Cola &zona_NE, Cola &zona_NO, Cola &zona_SE, Cola &zona_SO);
void saber_direccion (Cola &Central, Cola &zona_NE, Cola &zona_NO, Cola &zona_SE, Cola &zona_SO);
Pila cargarCamion(Cola &zona, Pila Camion, ColaCamiones &CamionesEnReparto, ColaCamiones &CamionesLibres, int &contador_camiones);
void realizar_entrega_uno (ColaCamiones &colaCamiones, Cola &zona_entrega, int IDcamion, ColaCamiones &CamionesLibres);
Pila cargarRestantes(Cola &zona, Pila Camion, ColaCamiones &CamionesEnReparto, ColaCamiones &CamionesLibres, int &contador_camiones);


int main() {
    int contador_camiones = 0; //sirve para identificar furgos
    srand(time(NULL));

    //Creamos una cola con la copia de todos los paquetes
    Cola copia;
    //Colas de cada una de los hubs y la central
    Cola Central;
    Cola zona_NE;
    Cola zona_NO;
    Cola zona_SE;
    Cola zona_SO;
    //Furgos en proceso de carga, en cada hub
    Pila furgo_NE(contador_camiones);
    furgo_NE.makenull();
    Pila furgo_NO(contador_camiones);
    furgo_NO.makenull();
    Pila furgo_SE(contador_camiones);
    furgo_SE.makenull();
    Pila furgo_SO(contador_camiones);
    furgo_SO.makenull();

    //Colas de paquetes entregados a cada hub
    Cola entregados_NE;
    Cola entregados_NO;
    Cola entregados_SE;
    Cola entregados_SO;

    //Colas de los camiones que están reparto en cada zona.
    ColaCamiones enReparto_NE;
    ColaCamiones enReparto_NO;
    ColaCamiones enReparto_SE;
    ColaCamiones enReparto_SO;

    //Cola de camiones libres, disponibles para cargar.
    ColaCamiones CamionesLibres;

    //Creamos 3500 pkts y los metemos a la central. Los 2 primeros con nuestros DNI´s.
    Paquete Gonzalo("09099729D");
    Central.enqueue(Gonzalo);
    copia.enqueue(Gonzalo);
    Paquete Enrique("03212238N");
    Central.enqueue(Enrique);
    copia.enqueue(Enrique);

    for (int i = 0; i <N1-2; i++){
        Paquete p;
        Central.enqueue(p);
        copia.enqueue(p);
    }

    int opcion;
    string id_paquete;

    do
    {
        menu();  cin>> opcion;

        switch(opcion)
        {
            case 1:
                if (Central.empty() && zona_NE.empty() && zona_SO.empty() && zona_SE.empty() && zona_NO.empty()){
                    cout << "No hay paquetes que distribuir"<<endl;
                }
                else {
                    if (!Central.empty()) {
                        direccion_HUB(Central, zona_NE, zona_NO, zona_SE,
                                      zona_SO); //Direccionamos los 73 paquetes entre los hubs
                    }
                    //Cargamos los paquetes en sus furgonetas y mandamos las llenas.
                    while (!zona_NE.empty()) {
                        furgo_NE = cargarCamion(zona_NE, furgo_NE, enReparto_NE, CamionesLibres, contador_camiones);
                    }

                    while (!zona_NO.empty()) {
                        furgo_NO = cargarCamion(zona_NO, furgo_NO, enReparto_NO, CamionesLibres, contador_camiones);
                    }

                    while (!zona_SE.empty()) {
                        furgo_SE = cargarCamion(zona_SE, furgo_SE, enReparto_SE, CamionesLibres, contador_camiones);
                    }

                    while (!zona_SO.empty()) {
                        furgo_SO = cargarCamion(zona_SO, furgo_SO, enReparto_SO, CamionesLibres, contador_camiones);
                    }
                    if (Central.empty() && zona_NE.empty() && zona_SO.empty() && zona_SE.empty() && zona_NO.empty()) {
                        furgo_NE = cargarRestantes(zona_NE, furgo_NE, enReparto_NE, CamionesLibres, contador_camiones);
                        furgo_NO = cargarRestantes(zona_NO, furgo_NO, enReparto_NO, CamionesLibres, contador_camiones);
                        furgo_SE = cargarRestantes(zona_SE, furgo_SE, enReparto_SE, CamionesLibres, contador_camiones);
                        furgo_SO = cargarRestantes(zona_SO, furgo_SO, enReparto_SO, CamionesLibres, contador_camiones);
                    }
                }
                break;

            case 2:
                int op;
                int ID;
                menuZona(); cin>>op;
                switch(op) {
                    case 1:
                        if (!enReparto_NE.empty()) {
                            enReparto_NE.showCamiones();
                            cin >> ID;
                            realizar_entrega_uno(enReparto_NE, entregados_NE, ID, CamionesLibres);
                        } else {
                            cout << "No hay camiones en reparto en la zona NE" << endl;
                        }
                        break;
                    case 2:
                        if (!enReparto_NE.empty()) {
                            enReparto_NO.showCamiones();
                            cin >> ID;
                            realizar_entrega_uno(enReparto_NO, entregados_NO, ID, CamionesLibres);
                        }
                        else {
                            cout<<"No hay camiones en reparto en la zona NO"<< endl;
                        }
                        break;
                    case 3:
                        if (!enReparto_NE.empty()) {
                            enReparto_SE.showCamiones();
                            cin >> ID;
                            realizar_entrega_uno(enReparto_SE, entregados_SE, ID, CamionesLibres);
                        }
                        else {
                            cout<<"No hay camiones en reparto en la zona SE"<< endl;
                        }
                        break;
                    case 4:
                        if (!enReparto_NE.empty()) {
                            enReparto_SO.showCamiones();
                            cin >> ID;
                            realizar_entrega_uno(enReparto_SO, entregados_SO, ID, CamionesLibres);
                        }
                        else {
                            cout<<"No hay camiones en reparto en la zona SO1" << endl;
                        }
                        break;
                    case 5:
                        break;
                }
                break;
            case 3:
                cout<< "Ingrese la ID del paquete que quiere buscar:"; cin >> id_paquete;
                cout<< "Resultado de la busqueda en la central:" << Central.returnState(id_paquete)<<endl;
                cout<< "Resultado de la busqueda en el hub NE:" << zona_NE.returnState(id_paquete)<<endl;
                cout<< "Resultado de la busqueda en el hub NO:" << zona_NO.returnState(id_paquete)<<endl;
                cout<< "Resultado de la busqueda en el hub SE:" << zona_SE.returnState(id_paquete)<<endl;
                cout<< "Resultado de la busqueda en el hub SO:" << zona_SO.returnState(id_paquete)<<endl;
                cout<< "Resultado de la busqueda en la furgo del hub NE:" << furgo_NE.returnState(id_paquete)<<endl;
                cout<< "Resultado de la busqueda en la furgo del hub NO:" << furgo_NO.returnState(id_paquete)<<endl;
                cout<< "Resultado de la busqueda en la furgo del hub SE:" << furgo_SE.returnState(id_paquete)<<endl;
                cout<< "Resultado de la busqueda en la furgo del hub SO:" << furgo_SO.returnState(id_paquete)<<endl;
                cout<< "Resultado de la busqueda en las furgos en reparto en la zona NE" << enReparto_NE.returnState(id_paquete)<<endl;
                cout<< "Resultado de la busqueda en las furgos en reparto en la zona NO" << enReparto_NO.returnState(id_paquete)<<endl;
                cout<< "Resultado de la busqueda en las furgos en reparto en la zona SE" << enReparto_SE.returnState(id_paquete)<<endl;
                cout<< "Resultado de la busqueda en las furgos en reparto en la zona SO" << enReparto_SO.returnState(id_paquete)<<endl;
                cout<< "Resultado de la busqueda en los paquetes entregados en la zona NE" << entregados_NE.returnState(id_paquete)<<endl;
                cout<< "Resultado de la busqueda en los paquetes entregados en la zona NO" << entregados_NO.returnState(id_paquete)<<endl;
                cout<< "Resultado de la busqueda en los paquetes entregados en la zona SE" << entregados_SE.returnState(id_paquete)<<endl;
                cout<< "Resultado de la busqueda en los paquetes entregados en la zona SO" << entregados_SO.returnState(id_paquete)<<endl;
                break;
            case 4:
                copia.showCola();
                break;
            case 5:
                Central.showCola();
                break;
            case 6:
                CamionesLibres.mostrarContentCamiones();
                furgo_NE.show_Camion();
                furgo_NO.show_Camion();
                furgo_SE.show_Camion();
                furgo_SO.show_Camion();
                enReparto_NE.mostrarContentCamiones();
                enReparto_NO.mostrarContentCamiones();
                enReparto_SE.mostrarContentCamiones();
                enReparto_SO.mostrarContentCamiones();
                break;
            case 7:
                furgo_NE.show_Camion();
                furgo_NO.show_Camion();
                furgo_SE.show_Camion();
                furgo_SO.show_Camion();
                break;
            case 8:
                entregados_NE.showCola();
                entregados_NO.showCola();
                entregados_SE.showCola();
                entregados_SO.showCola();
                break;
        }
    }while(opcion!=9);

    return 0;
}

void menu(void){
    cout<<"\t -------------------------------------------\n";
    cout<<"\t|        IMPLEMENTACION DE UNA PILA         |\n";
    cout<<"\t|-------------------------------------------|\n";
    cout<<" \t|                                           |"<<endl;
    cout<<" \t|  1. DIRECCIONAR Y CARGAR 73 PKTS          |"<<endl;
    cout<<" \t|  2. REALIZAR ENTREGA                      |"<<endl;
    cout<<" \t|  3. MOSTRAR ESTADO PAQUETE                |"<<endl;
    cout<<" \t|  4. MOSTRAR LABELS                        |"<<endl;
    cout<<" \t|  5. MOSTRAR PCS                           |"<<endl;
    cout<<" \t|  6. MOSTRAR CAMIONES                      |"<<endl;
    cout<<" \t|  7. MOSTRAR CAMIONES EN HUBS              |"<<endl;
    cout<<" \t|  8. MOSTRAR PAQUETES ENVIADOS A ZONA      |"<<endl;
    cout<<" \t|  9. SALIR                                 |"<<endl;
    cout<<" \t|                                           |"<<endl;
    cout<<"\t -------------------------------------------\n";
    cout<<"\t Ingrese opcion: ";
}

void direccion_HUB (Cola &Central, Cola &zona_NE, Cola &zona_NO, Cola &zona_SE, Cola &zona_SO) {
    int numEle=Central.getNumEle();
    if (Central.getNumEle() < 73) {
        for (int i = 0; i < numEle; i++) {
            saber_direccion(Central, zona_NE, zona_NO, zona_SE, zona_SO);
        }
    } else {
        for (int i = 0; i < N2; i++) {
            saber_direccion(Central, zona_NE, zona_NO, zona_SE, zona_SO);
        }
    }
}

void saber_direccion(Cola &Central, Cola &zona_NE, Cola &zona_NO, Cola &zona_SE, Cola &zona_SO){
    if (!Central.empty()) {
        Paquete p = Central.dequeue(); //Sacamos pkt de Central
        if ((p.getLabel().id_pkt[12] == 78) && (p.getLabel().id_pkt[13] == 69)){
            zona_NE.enqueue(p); //Paquete a Zona NE
            //cout << "Paquete al NE"<< endl;
        } else if ((p.getLabel().id_pkt[12] == 78) && (p.getLabel().id_pkt[13] == 79)) {
            zona_NO.enqueue(p);
            //cout << "Paquete al NO" << endl;
        } else if ((p.getLabel().id_pkt[12] == 83) && (p.getLabel().id_pkt[13] == 69)) {
            zona_SE.enqueue(p);
            //cout << "Paquete al SE" << endl;
        } else if ((p.getLabel().id_pkt[12] == 83) && (p.getLabel().id_pkt[13] == 79) ){
            zona_SO.enqueue(p);
            //cout << "Paquete al SO" << endl;
        }
        p.setState(2); //Cambiamos estado del pkt
    }
}

Pila cargarCamion(Cola &zona, Pila Camion, ColaCamiones &CamionesEnReparto, ColaCamiones &CamionesLibres, int &contador_camiones){
    Paquete p = zona.dequeue();
    if (Camion.full()){
        CamionesEnReparto.enqueue(Camion);

        Camion.setState(statePila[1]); //Cambiamos estado de camion
        if (CamionesLibres.empty()){
            p.setState(1);
            Pila c(contador_camiones);
            c.push(p);
            return c;
        }
        else{
            Pila c = CamionesLibres.dequeue();
            c.setState(statePila[0]);
            p.setState(1);
            c.push(p);
            return c;
        }
    }
    else{
        p.setState(2);
        Camion.push(p);
        return Camion;
    }
}

Pila cargarRestantes(Cola &zona, Pila Camion, ColaCamiones &CamionesEnReparto, ColaCamiones &CamionesLibres, int &contador_camiones){
    if (!Camion.empty()){
        CamionesEnReparto.enqueue(Camion);
        Camion.setState(statePila[1]); //Cambio estado del camion
        if (CamionesLibres.empty()){
            Pila c(contador_camiones);
            return c;
        }
        else{
            Pila c = CamionesLibres.dequeue();
            return c;
        }
    }
}

void menuZona(void){
    cout<<" \t ------------------------------------------\n";
    cout<<" \t|              SELECCIONE ZONA             |\n";
    cout<<" \t|------------------------------------------|\n";
    cout<<" \t|                                          |"<<endl;
    cout<<" \t|  1. NE                                   |"<<endl;
    cout<<" \t|  2. NO                                   |"<<endl;
    cout<<" \t|  3. SE                                   |"<<endl;
    cout<<" \t|  4. SO                                   |"<<endl;
    cout<<" \t|  5. SALIR                                |"<<endl;
    cout<<" \t|                                          |"<<endl;
    cout<<"\t -------------------------------------------\n";
    cout<<"\t Ingrese opcion: ";
}

void realizar_entrega_uno (ColaCamiones &colaCamiones, Cola &zona_entrega, int IDcamion, ColaCamiones &CamionesLibres){
        if (!colaCamiones.empty()){
            Pila c = colaCamiones.extract_truck(IDcamion); //se busca el camion con la ID entre los camiones que estan en reparto
            c.entregar_paquetes(zona_entrega); //se llevan los paquetes a la zona de entrega (se termina la entrega)
            CamionesLibres.enqueue(c); //Se lleva la furgoneta al almacen de furgos libres
        }
}

