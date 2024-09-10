#include "proceso.h"
using namespace std;


Proceso::Proceso(int id, int tiempoLlegada, int tiempoRafaga, int prioridad)
    : id(id), tiempoLlegada(tiempoLlegada), tiempoRafaga(tiempoRafaga),
      prioridad(prioridad), tiempoRestante(tiempoRafaga), penalizado(false), colaAso(-1){}

// Getters
int Proceso::getId() const { return id; }
int Proceso::getTiempoLlegada() const {return tiempoLlegada;}
int Proceso::getTiempoRafaga() const {return tiempoRafaga;}
int Proceso::getPrioridad() const {return prioridad;}
int Proceso::getTiempoRestante() const {return tiempoRestante;}
int Proceso::getQuantumTotal() const {return quantumTotal;}
int Proceso::getColaAso() const{return colaAso;}
bool Proceso::isPenalizado() const {return penalizado;}
void Proceso::setTiempoRestante(int tiempoRestante) {this->tiempoRestante = tiempoRestante;}
void Proceso::setQuantumTotal(int quantum){quantumTotal = quantum;}
void Proceso::setColaAso(int colaAso){this->colaAso = colaAso;}
void Proceso::penalizar() {penalizado = true;}
void Proceso::despenalizar(){penalizado = false;}
void Proceso::actualizar(int tiempoActual){
    if (tiempoRestante == 0){
        tiempoFin = tiempoActual;
        cout << "Waiting time proceso " << id  << " = " << tiempoFin << " - "<< tiempoRafaga << " - "<< tiempoLlegada << " = "<< tiempoFin - tiempoRafaga - tiempoLlegada<< endl;
        cout << "TAT proceso " << id << " = "  << tiempoFin - tiempoLlegada << endl;;
    }
}

bool Proceso::operator<(const Proceso& otro) const {
    // El proceso con mayor prioridad (valor más alto) se considera menor para que vaya primero
    return this->tiempoLlegada < otro.tiempoLlegada;
}