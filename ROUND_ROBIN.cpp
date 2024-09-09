#include "round_robin.h"
using namespace std;
RoundRobin::RoundRobin(int quantum) : quantum(quantum){}

void RoundRobin::ejecutar(vector<Proceso>& procesos, int tiempoActual){
    int i = 0;
    bool flag = true;
    while(i < procesos.size() && flag){
        if(procesos[i].getTiempoLlegada() <= tiempoActual && procesos[i].getQuantumTotal() < quantum){
            procesos[i].setTiempoRestante(procesos[i].getTiempoRestante() - 1);
            procesos[i].actualizar(tiempoActual);
            procesos[i].setQuantumTotal(procesos[i].getQuantumTotal() + 1);
            flag = false;
        }
        else if(i + 1 == procesos.size() && flag){
            for(int j = 0; j < procesos.size(); j++)
                procesos[i].setQuantumTotal(0);
        }
        i++;
    }

}
bool RoundRobin::detectarPenalizacion(const Proceso& proceso){
    return proceso.getTiempoRestante() > quantum;
}
