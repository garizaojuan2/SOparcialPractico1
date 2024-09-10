#include "fcfs.h"
using namespace std;
FCFS::FCFS(){};
void FCFS::ejecutar(vector<Proceso>& procesos, int tiempoActual){    
    procesos[0].setTiempoRestante(procesos[0].getTiempoRestante() - 1);
    cout << "Se esta ejecutando el proceso #" << procesos[0].getId() << endl;
    procesos[0].actualizar(tiempoActual);
}
bool FCFS::detectarPenalizacion(const Proceso& proceso){
    return false; 
}
