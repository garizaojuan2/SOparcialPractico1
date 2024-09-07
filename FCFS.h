#ifndef FCFS_H
#define FCFS_H

#include "politica_planificacion.h"

class FCFS : public PoliticaPlanificacion{
public:
    FCFS();
    void ejecutar(std::vector<Proceso>& procesos, int tiempoActual) override;
    bool detectarPenalizacion(const Proceso& proceso) override;
};

#endif
