#include "comun.h"

int main(void) {
    preparar();
    double inicio = ahora();
    for (int r = 0; r < REP; r++)
        for (int i = 1; i < H - 1; i++)
            fila(i);
    terminar(ahora() - inicio);
    return 0;
}
