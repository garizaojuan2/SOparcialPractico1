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
    void ejecutarTodas(int tiempoActual);
    std::vector<Proceso> obtenerEstadoActual();
};

#endif
