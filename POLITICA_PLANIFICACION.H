#ifndef POLITICA_PLANIFICACION_H
#define POLITICA_PLANIFICACION_H

#include <vector>
#include "proceso.h"

using namespace std;

class PoliticaPlanificacion{
public:
    virtual void ejecutar(vector<Proceso>& procesos, int tiempoActual) = 0;
    virtual bool detectarPenalizacion(const Proceso& proceso) = 0;
};

#endif
