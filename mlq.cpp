#include "mlq.h"
using namespace std;
MLQ::MLQ(){}

void MLQ::agregarCola(Cola& cola){
    colas.push_back(cola);
}

void MLQ::ejecutarTodas(int tiempoActual){
    int j = 0;
    bool flag1 = true;
    while(flag1 && j < 3){
        vector<Proceso> procesos = colas[j].getProcesos();
        int i = 0;
        bool flag2 = true;
        while(i < procesos.size() && flag2){
            if(procesos[i].getTiempoLlegada() <= tiempoActual)
        }
    }
}

vector<Proceso> MLQ::obtenerEstadoActual(){
    vector<Proceso> estado;
    for (Cola& cola : colas){
        auto& procesos = cola.getProcesos();
        estado.insert(estado.end(), procesos.begin(), procesos.end());
    }
    return estado;
}
