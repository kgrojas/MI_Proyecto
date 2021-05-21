#define VUELTA (20)
int main() {
    int entrenamiento [VUELTAS+1]= {0};
    int vueltaACargar =  1;
    int tiempoDeVuelta = 0;

    system("cls");

    while ( vueltaACargar != 0 ) {
        leer(" Ingrese la vuelta a cargar (solo se aceptan valores del 1 al 20) \n Ingre 0 para SALIR: ", vueltaACargar);

        tiempoDeVuelta= cargarDatos(vueltaACargar,tiempoDeVuelta);

        entrenamiento [vueltaACargar] = tiempoDeVuelta;

        if (vueltaACargar != 0)
        {
            /* code */
        } else
        {
            system("cls");

            for (int i = 1; i <= VUELTAS; i++)
            {
                if (entrenamiento[i] != 0) {
                   cout <<"Vuelta "<<i<< " : " << entrenamiento[i] << endl;
                }
            }
        }
    }
    system ("pause"); 
    return 0;
}