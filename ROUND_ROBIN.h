#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include "politica_planificacion.h"
using namespace std;

class RoundRobin : public PoliticaPlanificacion{
private:
    int quantum;

public:
    RoundRobin(int quantum);
    void ejecutar(vector<Proceso>& procesos, int tiempoActual) override;
    bool detectarPenalizacion(const Proceso& proceso) override;
};

#endif
