#include "round_robin.h"
using namespace std;
RoundRobin::RoundRobin(int quantum) : quantum(quantum){}

void RoundRobin::ejecutar(vector<Proceso>& procesos, int tiempoActual){
    int i = 0;
    bool flag = true;
    while(i < procesos.size() && flag){
        if(procesos[i].getTiempoLlegada() <= tiempoActual){
            int id1 = procesos[i].getId();
            procesos[i].actualizar(tiempoActual);
            int j = 0;
            procesos[i].setQuantumTotal();
            int k = procesos[i].getQuantumTotal();
            int id2 = -1;
            while(flag && j < procesos.size()){
                if(procesos[j].getTiempoLlegada() <= tiempoActual){
                    id2 = procesos[j].getId();
                }
                if(id1 == id2 && k < quantum){
                    j = 0;
                    k++;
                    procesos[j].setQuantumTotal();
                    procesos[j].actualizar(tiempoActual);
                }
                else{
                    flag = false;
                }              
                j++;
            }
        }
        i++;
    }

}

bool RoundRobin::detectarPenalizacion(const Proceso& proceso){
    return proceso.getTiempoRestante() > quantum;
}
