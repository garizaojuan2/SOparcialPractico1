#include "round_robin2.h"
using namespace std;
RoundRobin2::RoundRobin2(int quantum) : quantum(quantum){}

void RoundRobin2::ejecutar(vector<Proceso>& procesos, int tiempoActual){
    int i = 0;
    bool flag = true;
    while(i < procesos.size() && flag){
        if(procesos[i].getTiempoLlegada() <= tiempoActual && procesos[i].getQuantumTotal() < quantum){
            procesos[i].setTiempoRestante(procesos[i].getTiempoRestante() - 1);
            cout << "Se esta ejecutando el proceso #" << procesos[i].getId() << endl;
            procesos[i].actualizar(tiempoActual);
            procesos[i].setQuantumTotal(procesos[i].getQuantumTotal() + 1);
            flag = false;
        }
        
        i++;
    }
}

bool RoundRobin2::detectarPenalizacion(const Proceso& proceso){
    return proceso.getTiempoRestante() > quantum;
}