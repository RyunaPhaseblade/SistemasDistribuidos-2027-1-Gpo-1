#include "comun.h"
#include <pthread.h>

#define N 4

typedef struct { int inicio, fin; } Rango;

void *trabajar(void *arg) {
    Rango *r = arg;
    for (int i = r->inicio; i < r->fin; i++)
        fila(i);
    return NULL;
}

int main(void) {
    pthread_t hilos[N];
    Rango rangos[N];
    preparar();
    double inicio = ahora();
    for (int r = 0; r < REP; r++) {
        // Cada hilo recibe un bloque de filas
        for (int k = 0; k < N; k++) {
            rangos[k].inicio = 1 + k * (H - 2) / N;
            rangos[k].fin = 1 + (k + 1) * (H - 2) / N;
            pthread_create(&hilos[k], NULL, trabajar, &rangos[k]);
        }
        for (int k = 0; k < N; k++)
            pthread_join(hilos[k], NULL);
    }
    terminar(ahora() - inicio);
    return 0;
}
