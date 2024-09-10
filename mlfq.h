#ifndef MLFQ_H
#define MLFQ_H

#include <vector>
#include "cola.h"
using namespace std;
class MLFQ{
protected:
    vector<Cola> colas;

public:
    MLFQ();
    void agregarCola(Cola& cola);
    void ejecutarTodas(vector<Proceso> &procesos, int tiempoTotal);
    void agregarProcesosCola(int tiempoActual, vector<Proceso> &procesos);
    bool comprobarEmpty(vector<Proceso> &procesos);
    int RR(int itCola, vector<Proceso> &procesos, int tiempoActual);
    int FCFS(int itCola, vector<Proceso> &procesos, int tiempoActual);
};

#endif