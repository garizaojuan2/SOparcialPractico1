#include "round_robin.h"
using namespace std;
RoundRobin::RoundRobin(int quantum) : quantum(quantum){}

void RoundRobin::ejecutar(vector<Proceso>& procesos, int tiempoActual){
    int i = 0;
    bool flag = true;
    while(i < procesos.size() && flag){
        //cout << "Tiempo llegada del proceso #" << procesos[i].getId() << " es " << procesos[i].getTiempoLlegada() << endl;
        //cout << "El tiempoActual es " << tiempoActual << endl;
        //cout << "Quantum del proceso #" << procesos[i].getId() << " es " << procesos[i].getQuantumTotal() << endl;
        if(procesos[i].getTiempoLlegada() <= tiempoActual && procesos[i].getQuantumTotal() < quantum){
            procesos[i].setTiempoRestante(procesos[i].getTiempoRestante() - 1);
            procesos[i].actualizar(tiempoActual);
            procesos[i].setQuantumTotal(procesos[i].getQuantumTotal() + 1);
            cout << "Se ejecuta el proceso #" << procesos[i].getId() << endl << "El quantum es " << procesos[i].getQuantumTotal() << endl;
            flag = false;
        }
        else if(i + 1 == procesos.size() && flag){
            for(int j = 0; j < procesos.size(); j++)
                procesos[j].setQuantumTotal(0);
        }
        i++;
    }

}
bool RoundRobin::detectarPenalizacion(const Proceso& proceso){
    return proceso.getTiempoRestante() > quantum;
}
