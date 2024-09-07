#include "proceso.h"

Proceso::Proceso(int id, int tiempoLlegada, int tiempoRafaga, int prioridad)
    : id(id), tiempoLlegada(tiempoLlegada), tiempoRafaga(tiempoRafaga),
      prioridad(prioridad), tiempoRestante(tiempoRafaga), penalizado(false) {}

// Getters
int Proceso::getId() const { return id; }
int Proceso::getTiempoLlegada() const {return tiempoLlegada;}
int Proceso::getTiempoRafaga() const {return tiempoRafaga;}
int Proceso::getPrioridad() const {return prioridad;}
int Proceso::getTiempoRestante() const {return tiempoRestante;}
int Proceso::getQuantumTotal() const {return quantumTotal;}
bool Proceso::isPenalizado() const {return penalizado;}
void Proceso::setTiempoRestante(int tiempoRestante) {this->tiempoRestante = tiempoRestante;}
void Proceso::setQuantumTotal(){quantumTotal++;}
void Proceso::penalizar() {penalizado = true;}
void Proceso::actualizar(int tiempoActual) {
    if (tiempoRestante > 0) {
        tiempoRestante--;
        tiempoActual++;
        if (tiempoRestante == 0) {
            tiempoFin = tiempoActual;
            cout << "Waiting time proceso" << id << " = "  << tiempoFin - tiempoRafaga - tiempoLlegada;
            cout << "TAT proceso" << id << " = "  << tiempoFin - tiempoLlegada;
        }
    }
}
bool Proceso::operator<(const Proceso& otro) const {
    // El proceso con mayor prioridad (valor más alto) se considera menor para que vaya primero
    return this->prioridad > otro.prioridad;
}