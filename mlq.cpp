#include "mlq.h"
using namespace std;
MLQ::MLQ(){}

void MLQ::agregarCola(Cola& cola){
    colas.push_back(cola);
}
void MLQ::agregarProcesosCola(int tiempoActual, vector<Proceso> &procesos){
    bool flag2 = true;
    int i = 0;
    while(flag2 && i < procesos.size()){
        if(procesos[i].getTiempoLlegada() == tiempoActual){
            if(procesos[i].getPrioridad() >= 3){
                colas[0].agregarProceso(procesos[i]);
                cout << "Proceso " << procesos[i].getId() << " en el tiempo " << tiempoActual << endl;
                procesos.erase(procesos.begin() + i);
            }
            else if(procesos[i].getPrioridad() == 2){
                colas[1].agregarProceso(procesos[i]);
                cout << "Proceso " << procesos[i].getId() << " en el tiempo " << tiempoActual << endl;
                procesos.erase(procesos.begin() + i);
            }
            else{
                colas[2].agregarProceso(procesos[i]);
                cout << "Proceso " << procesos[i].getId() << " en el tiempo " << tiempoActual << endl;
                procesos.erase(procesos.begin() + i);
            }
        }
        i++;
    }
}
bool MLQ::comprobarEmpty(vector<Proceso> &procesos){
    bool ans = true;
    if(procesos.size() == 0){
        int i = 0;
        vector<Proceso> tmp;
        while(i < colas.size() && !ans){
            tmp = colas[i].getProcesos();
            if(tmp.size() > 0){
                ans = true ;
            }
            i++;
        }
    }
    else
        ans = false;
}

int MLQ::RR(int itCola, vector<Proceso> &procesos, int tiempoActual){
    int i = 0, ans = tiempoActual;
    bool flag = true;
    while(i < procesos.size() && flag){
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

int MLQ::FCFS(int itCola, vector<Proceso> &procesos, int tiempoActual){
    int ans;
    if(procesos.size() > 0){
        ans = tiempoActual + 1;
        colas[itCola].ejecutar(tiempoActual);
        colas[itCola].eliminarProcesos();
    }
    return ans;
}
void MLQ::ejecutarTodas(vector<Proceso> &procesos, int tiempoTotal){
    int tiempoActual = 0;
    bool flag1 = true;
    while(tiempoActual <= tiempoTotal){
        bool flag2 = true;
        int i = 0;
        sort(procesos.begin(),procesos.end());
        this->agregarProcesosCola(tiempoActual, procesos);
        flag1 = this->comprobarEmpty(procesos);        
        vector<Proceso> tmp;
        while(i < colas.size() && flag2){
            tmp = colas[i].getProcesos();
            if(tmp.size() > 0){
                if(colas[i].getString() == "rr"){
                    tiempoActual = this->RR(i, tmp, tiempoActual);
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