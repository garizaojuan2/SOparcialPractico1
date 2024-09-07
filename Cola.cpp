#include "cola.h"
using namespace std;
Cola::Cola(PoliticaPlanificacion* politica) : politica(politica){};

void Cola::agregarProceso(const Proceso& proceso){
    procesos.push_back(proceso);
}

void Cola::ejecutar(int tiempoActual){
    int i = 0;
    bool flag = true;
    politica->ejecutar(procesos, tiempoActual);
}

vector<Proceso>& Cola::getProcesos(){
    return procesos;
}
