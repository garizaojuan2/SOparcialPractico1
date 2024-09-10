#include "mlfq.h"
using namespace std;

MLFQ::MLFQ(){}

void MLFQ::agregarCola(Cola& cola){
    colas.push_back(cola);
}

void MLFQ::agregarProcesosCola(int tiempoActual, vector<Proceso> &procesos){
    int i = 0;
    vector<int> borrar;
    while(i < procesos.size()){
        if(procesos[i].getTiempoLlegada() == tiempoActual){
            procesos[i].setColaAso(0);
            colas[0].agregarProceso(procesos[i]);
        }
        i++;
    }
}

bool MLFQ::comprobarEmpty(vector<Proceso> &procesos){
    bool ans = true;
    if(procesos.size() == 0) {
        int i = 0;
        vector<Proceso> tmp;
        while(i < colas.size() && !ans){
            tmp = colas[i].getProcesos();
            if(tmp.size() > 0) {
                ans = true;
            }
            i++;
        }
    } 
    else {
        ans = false;
    }
    return ans;
}

int MLFQ::RR(int itCola, vector<Proceso> &procesos, int tiempoActual){
    int i = 0, ans = tiempoActual;
    bool flag = true;
    while(i < procesos.size() && flag) {
        if(procesos[i].getQuantumTotal() < colas[itCola].getQuantum()){
            ans += 1;
            colas[itCola].ejecutar(ans);
            colas[itCola].eliminarProcesos();
            flag = false;
        } 
        else if(i + 1 == procesos.size() && procesos[i].getQuantumTotal() == colas[itCola].getQuantum()){
            colas[itCola].ejecutar(ans);
            flag = false;
        }
        i++;
    }
    return ans;
}

int MLFQ::FCFS(int itCola, vector<Proceso> &procesos, int tiempoActual){
    int ans;
    if(procesos.size() > 0){
        ans = tiempoActual + 1;
        colas[itCola].ejecutar(tiempoActual);
        colas[itCola].eliminarProcesos();
    }
    return ans;
}
void MLFQ::penalizar(){
    for(int i = 0; i < colas.size() - 1; i++){
        vector<Proceso> tmp = colas[i].getProcesos();
        for(int j = 0; j < tmp.size(); j++){
            if(tmp[j].isPenalizado()){
                tmp[j].despenalizar();
                colas[i + 1].agregarProceso(tmp[j]);
            }
        }
    }
}
void MLFQ::ejecutarTodas(vector<Proceso> &procesos, int tiempoTotal){
    int tiempoActual = 0;
    bool flag1 = true;
    while(tiempoActual < tiempoTotal){
        bool flag2 = true;
        int i = 0;
        this->agregarProcesosCola(tiempoActual, procesos);
        vector<Proceso> tmp;
        this->penalizar();
        while(i < colas.size() && flag2){
            tmp = colas[i].getProcesos();

            if(tmp.size() > 0){
                if(colas[i].getString() == "rr"){
                    tiempoActual = this->RR(i, tmp, tiempoActual);
                    cout << "1. el tiempoActual es " << tiempoActual;
                    flag2 = false;
                } 
                else{
                    tiempoActual = this->FCFS(i, tmp, tiempoActual);
                    cout << "2. el tiempoActual es " << tiempoActual;
                    flag2 = false;
                }
            }
            i++;
        }
    }
}
