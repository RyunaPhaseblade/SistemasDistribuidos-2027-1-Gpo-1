#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define W 2000
#define H 2000
#define REP 50

unsigned char *imagen, *resultado;

double ahora(void) {
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec + t.tv_nsec / 1e9;
}

void preparar(void) {
    imagen = malloc(W * H);
    resultado = calloc(W * H, 1);
    srand(1);
    for (int k = 0; k < W * H; k++) {
        imagen[k] = rand() % 256;
    }
}

// Desenfoca la fila i: promedio de los 9 vecinos
void fila(int i) {
    for (int j = 1; j < W - 1; j++) {
        int suma = 0;
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                suma += imagen[(i + di) * W + j + dj];
            }
        }
        resultado[i * W + j] = suma / 9;
    }
}

void terminar(double segundos) {
    long suma = 0;
    for (int k = 0; k < W * H; k++) {
        suma += resultado[k];
    }
    printf("Tiempo por filtro: %f s\n", segundos / REP);
    printf("Suma de pixeles: %ld\n", suma);
    free(imagen);
    free(resultado);
}
