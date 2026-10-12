#include "comun.h"
#include <omp.h>

int main(void) {
    preparar();
    printf("Hilos: %d\n", omp_get_max_threads());
    double inicio = ahora();
    for (int r = 0; r < REP; r++) {
        #pragma omp parallel for
        for (int i = 1; i < H - 1; i++)
            fila(i);
    }
    terminar(ahora() - inicio);
    return 0;
}
