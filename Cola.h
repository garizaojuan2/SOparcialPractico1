#ifndef COLA_H
#define COLA_H

#include <vector>
#include "proceso.h"
#include "politica_planificacion.h"

using namespace std;
class Cola{
private:
    vector<Proceso> procesos;
    PoliticaPlanificacion* politica;

public:
    Cola(PoliticaPlanificacion* politica);

    void agregarProceso(const Proceso& proceso);
    void ejecutar(int tiempoActual);
    vector<Proceso>& getProcesos();
};

#endif
