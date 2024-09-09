#ifndef MLQ_H
#define MLQ_H

#include <vector>
#include "cola.h"
using namespace std;
class MLQ{
protected:
    vector<Cola> colas;

public:
    MLQ();
    void agregarCola(Cola& cola);
    void ejecutarTodas(vector<Proceso> &procesos, int tiempoTotal);
    void agregarProcesosCola(int tiempoActual, vector<Proceso> &procesos);
    bool comprobarEmpty(vector<Proceso> &procesos);
    int RR(int itCola, vector<Proceso> &procesos, int tiempoActual);
    int FCFS(int itCola, vector<Proceso> &procesos, int tiempoActual);
};

#endif
