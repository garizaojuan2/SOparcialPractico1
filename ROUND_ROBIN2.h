#ifndef ROUND_ROBIN2_H
#define ROUND_ROBIN2_H

#include "politica_planificacion.h"
using namespace std;

class RoundRobin2 : public PoliticaPlanificacion{
private:
    int quantum;

public:
    RoundRobin2(int quantum);
    void ejecutar(vector<Proceso>& procesos, int tiempoActual) override;
    bool detectarPenalizacion(const Proceso& proceso) override;
};

#endif