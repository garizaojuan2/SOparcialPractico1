#ifndef COLA_H
#define COLA_H

#include <vector>
#include <algorithm>
#include <string>
#include "proceso.h"
#include "politica_planificacion.h"

using namespace std;
class Cola{
private:
    vector<Proceso> procesos;
    PoliticaPlanificacion* politica;
    int quantum;
    string policy;

public:
    Cola(PoliticaPlanificacion* politica, int quantum, string policy);
    void agregarProceso(const Proceso& proceso);
    void ejecutar(int tiempoActual);
    void eliminarProcesos();
    void borrarProceso(int it);
    int getQuantum();
    void penalizar();
    string getString();
    vector<Proceso>& getProcesos();
};

#endif
