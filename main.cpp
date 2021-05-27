/* Un ciclista desea obtener una aplicacion que le permita obtener datos estadísticos sobre sus*/
// entrenamientos con el fin de mejorar en su actividad.
// El ciclista nos cuenta que registra una cantidad aleatoria de vueltas, que elige también de forma
// aleatoria, de las 20 vueltas que realiza en cada entrenamiento.
// De cada vuelta siempre se conoce:
// ● Su posición (primera vuelta, segunda vuelta, etc)
// ● Su duración, expresada como un número entero en el formato MMSS
// (minutos,segundos)
// También se conoce la extensión de la vuelta expresada en Km, para todas las vueltas es la
// misma ya que el ciclista realiza los entrenamientos en un circuito cerrado.
#include<stdio.h>
#include<iostream>
using namespace std;

#define VUELTAS (20)
#define KMdeVUELTA (5)//Kilometros

void leer(string mensaje, int &valor) {
    cout << mensaje;
    cin >> valor;
    return;
}
void leer(string mensaje, float &valor) {
    cout << mensaje;
    cin >> valor;
    return;
}
void entradaErronea (int &entradasErroneas){
    system("cls");
    cout <<endl<< "INGRESE UN VALOR CORRECTO!!: \n" << "Entradas erroneas: " << ++entradasErroneas <<endl<<endl;
}
void calcularTiempo (int &valor1, char &mitadSuperior, char &mitadInferior, int divisor,int vueltaACargar)
{
    int dividendo=1;
    for (int i = 0; i < divisor; i++) {
        dividendo *= 10;
    }
    cout << "ingrese el tiempo de vuelta "<< vueltaACargar << " en MMSS: ";
    cin >> valor1;
    mitadSuperior=valor1/dividendo;
    mitadInferior=valor1%dividendo;
}

int calcTiempoReduc(int tMax, int tMin){
    int minTMax, segTMax, minTMin, segTMin, segTMaxTotal, segTMinTotal;
    float tiempoReduc;

    minTMax = tMax / 100;
    segTMax = tMax % 100;
    minTMin = tMin / 100;
    segTMin = tMin % 100;

    segTMaxTotal = (minTMax * 60) + segTMax;
    segTMinTotal = (minTMin * 60) + segTMin;
    tiempoReduc = segTMaxTotal - segTMinTotal;

    return (tiempoReduc / segTMaxTotal) * 100;
}


int cargarDatos (int &vueltaACargar,int tiempoDeVuelta) 
{   
    int entradasErroneas = 0; 
    char minutos  = 0;
    char segundos = 0;
    int divisor = 2;
    while (vueltaACargar < 0 || vueltaACargar > VUELTAS) {
        entradaErronea(entradasErroneas);
        leer(" Ingrese la vuelta a cargar (solo se aceptan valores del 1 al 20) \n Ingre 0 para SALIR: ",
         vueltaACargar);
    }
    if (vueltaACargar == 0) {
        return 1;
    }
    calcularTiempo (tiempoDeVuelta,minutos,segundos,divisor,vueltaACargar);
    while (minutos > 59 || segundos > 59 || tiempoDeVuelta <= 0) {
        entradaErronea(entradasErroneas);
        calcularTiempo (tiempoDeVuelta,minutos,segundos,divisor,vueltaACargar);
    }

    return tiempoDeVuelta;  
}
int vueltaRapida(int entrenamiento[],int vueltas){
 int rapida = 6060;
    
    for (int i = 1; i < vueltas; i++)
    {
        if(entrenamiento[i]!=0 && entrenamiento[i] < rapida) {
            rapida = entrenamiento[i];
        }
    }
    return rapida;  
}
int vueltaLenta(int entrenamiento[],int vueltas){
    int lenta = 0;    
    for (int i = 1; i < vueltas; i++){
        if(entrenamiento[i] > lenta) {
          lenta = entrenamiento[i];
        }
    }
    return lenta;
}
void imprimirValores(float porcentaje, int rapida, int lenta, int entrenamiento[],int vueltas ){
    cout << "Vuelta mas rapida: " << endl;

    for (int i = 0; i < vueltas; i++){
        if(entrenamiento[i] == rapida){
            cout <<"Vuelta: "<< i<<"  "<< entrenamiento[i]<<" MMSS"<< endl;
        }
    }
    cout << "Vuelta mas lenta: " << endl;    
    for (int i = 0; i < vueltas; i++){
        if(entrenamiento[i] == lenta){
            cout <<"Vuelta: "<< i<<"  "<< entrenamiento[i]<<" MMSS"<< endl;
        }
    }
    cout << "El porcentaje de reduccion de tiempo es : " << porcentaje << endl;
}

int main() {
    int entrenamiento [VUELTAS+1]= {0};
    int vueltaACargar =  1;
    int tiempoDeVuelta = 0;
    int largoVuelta = 0;
    leer("Ingrese la distancia de la Vuelta Completa: ",largoVuelta);
    system("cls");
    while ( vueltaACargar != 0 ) {
        leer(" Ingrese la vuelta a cargar (solo se aceptan valores del 1 al 20) \n Ingrese 0 para SALIR: ", vueltaACargar);
        tiempoDeVuelta= cargarDatos(vueltaACargar, tiempoDeVuelta);
        entrenamiento [vueltaACargar] = tiempoDeVuelta;
        if (vueltaACargar != 0){
            
        } else{
            system("cls");
            for (int i = 1; i <= VUELTAS; i++)
            {
                if (entrenamiento[i] != 0) {
                   cout <<"Vuelta "<<i<< " : " << entrenamiento[i] << endl;
                }
            }
        }
    }
    int rapida = vueltaRapida(entrenamiento,VUELTAS);
    int lenta = vueltaLenta(entrenamiento, VUELTAS);
    float porcentajeReduc = calcTiempoReduc(lenta, rapida);

    imprimirValores(porcentajeReduc,rapida, lenta, entrenamiento,VUELTAS);

    system ("pause"); 
    return 0;
}