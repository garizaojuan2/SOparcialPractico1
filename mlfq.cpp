#include "mlfq.h"
using namespace std;

MLFQ::MLFQ() {}

void MLFQ::agregarCola(Cola& cola) {
    colas.push_back(cola);
}

void MLFQ::agregarProcesosCola(int tiempoActual, vector<Proceso> &procesos) {
    int i = 0;
    cout << "se entro a agregarProcesosCola en el tiempo " << tiempoActual << endl;
    vector<int> borrar;
    while(i < procesos.size()) {
        if(procesos[i].getTiempoLlegada() == tiempoActual) {
            if(procesos[i].getPrioridad() == -1) {
                colas[0].agregarProceso(procesos[i]);
                borrar.push_back(i);
            } else if(procesos[i].getPrioridad() == -2) {
                colas[1].agregarProceso(procesos[i]);
                borrar.push_back(i);
            } else {
                colas[2].agregarProceso(procesos[i]);
                borrar.push_back(i);
            }
        }
        i++;
    }
    for(int j = 0; j < borrar.size(); j++)
        procesos.erase(procesos.begin() + j);
}

bool MLFQ::comprobarEmpty(vector<Proceso> &procesos) {
    bool ans = true;
    if(procesos.size() == 0) {
        int i = 0;
        vector<Proceso> tmp;
        while(i < colas.size() && !ans) {
            tmp = colas[i].getProcesos();
            if(tmp.size() > 0) {
                ans = true;
            }
            i++;
        }
    } else {
        ans = false;
    }
    return ans;
}

int MLFQ::RR(int itCola, vector<Proceso> &procesos, int tiempoActual) {
    int i = 0, ans = tiempoActual;
    bool flag = true;
    vector<Proceso> tmp;
    while(i < procesos.size() && flag){
        if(procesos[i].getQuantumTotal() < colas[itCola].getQuantum()) {
            ans += 1;
            colas[itCola].ejecutar(ans);
            colas[itCola].eliminarProcesos();
            flag = false;
        } 
        else if(procesos[i].getQuantumTotal() == colas[itCola].getQuantum()){
                procesos[i].subPrioridad();
                procesos[i].setQuantumTotal(0);
                colas[itCola + 1].agregarProceso(procesos[i]);
                colas[itCola].penalizar();
        }
        i++;            
    }
        
    return ans;
}

int MLFQ::FCFS(int itCola, vector<Proceso> &procesos, int tiempoActual) {
    int ans;
    if(procesos.size() > 0) {
        ans = tiempoActual + 1;
        colas[itCola].ejecutar(tiempoActual);
        colas[itCola].eliminarProcesos();
    }
    return ans;
}

void MLFQ::ejecutarTodas(vector<Proceso> &procesos, int tiempoTotal) {
    int tiempoActual = 0;
    bool flag1 = true;
    int fcfsCont = 0;
    while(tiempoActual <= tiempoTotal) {
        bool flag2 = true;
        int i = 0;

        this->agregarProcesosCola(tiempoActual, procesos);
        flag1 = this->comprobarEmpty(procesos);
        vector<Proceso> tmp;
        while(i < colas.size() && flag2){
            tmp = colas[i].getProcesos();
            if(tmp.size() > 0) {
                if(colas[i].getString() == "rr"){
                    tiempoActual = this->RR(i, tmp, tiempoActual);
                    flag2 = false;
                } 
                else if(fcfsCont == 0){
                    fcfsCont += 1;
                    tiempoActual += 1;
                    tiempoActual = this->FCFS(i, tmp, tiempoActual);
                    flag2 = false;
                }
                else{
                    tiempoActual = this->FCFS(i, tmp, tiempoActual);
                    flag2 = false;
                }
            }
            i++;
        }
    }
}
