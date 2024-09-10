#ifndef PROCESO_H
#define PROCESO_H
#include <iostream>

using namespace std;

class Proceso{
private:
    int id;              
    int tiempoLlegada;    
    int tiempoRafaga;     
    int prioridad;         
    int tiempoRestante;    
    int tiempoInicio;      
    int tiempoFin;
    int quantumTotal;
    int colaAso;         
    bool penalizado;       

public:
    // Constructor
    Proceso(int id, int tiempoLlegada, int tiempoRafaga, int prioridad);

    // Getters y Setters
    int getId() const;
    int getTiempoLlegada() const;
    int getTiempoRafaga() const;
    int getPrioridad() const;
    int getTiempoRestante() const;
    int getQuantumTotal() const;
    int getColaAso() const; 
    bool isPenalizado() const;
    void setTiempoRestante(int tiempoRestante);
    void setQuantumTotal(int quantum);
    void setColaAso(int colaAso);
    void penalizar();
    void despenalizar();
    void actualizar(int tiempoActual);
    bool operator<(const Proceso& otro) const;
};

#endif
