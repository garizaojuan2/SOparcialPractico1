#include <iostream>
#include <vector>
#include "proceso.h"
#include "cola.h"
#include "mlfq.h"
#include "round_robin2.h"
#include "fcfs.h"

using namespace std;

// Función para leer los datos de un proceso desde la consola
Proceso leerDatosProceso(int id) {
    int tiempoLlegada, tiempoRafaga;
    cout << "Ingrese el tiempo de llegada del proceso: ";
    cin >> tiempoLlegada;
    cout << "Ingrese el tiempo de rafaga (burst time) del proceso: ";
    cin >> tiempoRafaga;
    Proceso proceso(id, tiempoLlegada, tiempoRafaga, -1); // Prioridad eliminada, se establece como 0
    return proceso;
}

int main() {
    int tiempoActual = 0;

    // Instancias de MLFQ y políticas de planificación
    MLFQ mlfq1; // Instancia de MLFQ
    RoundRobin2 rr1(3);  // Round Robin con quantum de 3
    RoundRobin2 rr2(2);  // Round Robin con quantum de 2
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
        tmp.push_back(nuevoProceso);
    }
    
    // Agregar las colas al sistema MLFQ
    mlfq1.agregarCola(cola1);
    mlfq1.agregarCola(cola2);    
    mlfq1.agregarCola(cola3);

    // Ejecutar todos los procesos
    mlfq1.ejecutarTodas(tmp, tiempoTotal);

    return 0;
}
