#include "cola.h"
using namespace std;
Cola::Cola(PoliticaPlanificacion* politica, int quantum, string policy) : politica(politica), quantum(quantum), policy(policy){};

void Cola::agregarProceso(const Proceso& proceso){
    procesos.push_back(proceso);
}

void Cola::ejecutar(int tiempoActual){
    int i = 0;
    politica->ejecutar(procesos, tiempoActual);
}

void Cola::eliminarProcesos(){
    for(int i = 0; i < procesos.size(); i++){
        if(procesos[i].getTiempoRestante() == 0)
            procesos.erase(procesos.begin() + i);
    }
}
int Cola::getQuantum(){return quantum;}

string Cola::getString(){return policy;}


vector<Proceso>& Cola::getProcesos(){
    return procesos;
}
