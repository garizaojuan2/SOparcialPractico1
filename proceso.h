#ifndef PROCESO_H
#define PROCESO_H

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
    bool isPenalizado() const;
    void setTiempoRestante(int tiempoRestante);
    void setQuantumTotal();
    void penalizar();
    void actualizar(int tiempoActual);
    bool operator<(const Proceso& otro) const;
};

#endif
