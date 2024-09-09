#include <iostream>
#include <vector>
#include "proceso.h"
#include "cola.h"
#include "mlq.h"
#include "round_robin.h"
#include "fcfs.h"

using namespace std;

// Función para leer los datos de un proceso desde la consola
Proceso leerDatosProceso(int id) {
    int tiempoLlegada, tiempoRafaga, prioridad;
    cout << "Ingrese el tiempo de llegada del proceso: ";
    cin >> tiempoLlegada;
    cout << "Ingrese el tiempo de rafaga (burst time) del proceso: ";
    cin >> tiempoRafaga;
    cout << "Ingrese la prioridad del proceso (mayor numero = mayor prioridad): ";
    cin >> prioridad;
    Proceso proceso(id, tiempoLlegada, tiempoRafaga, prioridad);
    return proceso;
}

int main() {
    int tiempoActual = 0;

    // Instancias de MLQ y políticas de planificación
    MLQ mlq1; // Instancia correcta de MLQ
    RoundRobin rr1(3);  // Round Robin con quantum de 3
    RoundRobin rr2(2);  // Round Robin con quantum de 2
    FCFS fcfs1;         // FCFS

    // Colas asociadas con las diferentes políticas
    Cola cola1(&rr1, 3, "rr");   // Cola con política Round Robin (quantum 3)
    Cola cola2(&rr2, 2, "rr");   // Cola con política Round Robin (quantum 2)
    Cola cola3(&fcfs1, -1, "fcfs"); // Cola con política FCFS

    cout << "Cuantos procesos deseas ingresar?: ";
    int cantidadProcesos;
    cin >> cantidadProcesos;
    vector<Proceso> tmp;
    int tiempoTotal = 0;
    for (int i = 0; i < cantidadProcesos; i++) {
        cout << "Ingrese los datos del proceso " << (i + 1) << ":" << endl;
        Proceso nuevoProceso = leerDatosProceso(i + 1);
        tiempoTotal += nuevoProceso.getTiempoRafaga();


        if (nuevoProceso.getPrioridad() >= 3){
        	nuevoProceso.setQuantumTotal(3);
        }
        else if (nuevoProceso.getPrioridad() == 2){
        	nuevoProceso.setQuantumTotal(2);
        }
        tmp.push_back(nuevoProceso);
    }
    mlq1.agregarCola(cola1);
    mlq1.agregarCola(cola2);    
    mlq1.agregarCola(cola3);
    mlq1.ejecutarTodas(tmp, tiempoTotal);


    return 0;
}
