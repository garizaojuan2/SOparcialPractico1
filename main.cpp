#include <iostream>
#include <vector>
#include "proceso.h"
#include "cola.h"
#include "mlq.h"
#include "round_robin.h"
#include "fcfs.h"

using namespace std;

// Función para leer los datos de un proceso desde la consola
Proceso leerDatosProceso() {
    int id, tiempoLlegada, tiempoRafaga, prioridad;
    cout << "Ingrese el ID del proceso (ID): ";
    cin >> id;
    cout << "Ingrese el tiempo de llegada del proceso: ";
    cin >> tiempoLlegada;
    cout << "Ingrese el tiempo de ráfaga (burst time) del proceso: ";
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
    Cola cola1(&rr1);   // Cola con política Round Robin (quantum 3)
    Cola cola2(&rr2);   // Cola con política Round Robin (quantum 2)
    Cola cola3(&fcfs1); // Cola con política FCFS

    // Leer procesos desde la entrada del usuario
    cout << "Cuantos procesos deseas ingresar?: ";
    int cantidadProcesos;
    cin >> cantidadProcesos;

    for (int i = 0; i < cantidadProcesos; i++) {
        cout << "Ingrese los datos del proceso " << (i + 1) << ":" << endl;
        Proceso nuevoProceso = leerDatosProceso();

        // Distribuir los procesos entre las colas
        if ((i + 1) % 3 == 0)  // Condición corregida
            cola1.agregarProceso(nuevoProceso);
        else if ((i + 1) % 3 == 1)
            cola2.agregarProceso(nuevoProceso);
        else
            cola3.agregarProceso(nuevoProceso);
    }

    // Agregar colas a MLQ
    mlq1.agregarCola(cola1);
    mlq1.agregarCola(cola2);
    mlq1.agregarCola(cola3);

    // Aquí puedes ejecutar las colas o avanzar el tiempo
    cout << "Simulacion completa." << endl;

    return 0;
}
