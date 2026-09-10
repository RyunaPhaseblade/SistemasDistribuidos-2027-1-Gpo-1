#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

void get_walltime(double *wcTime) {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    *wcTime = (tp.tv_sec + tp.tv_usec / 1000000.0);
}

int main(int argc, char* argv[]) {
    int i, j, k, n=3,modo;
    int **matrizA, **matrizB, **matrizC;
    double S1, E1;

    printf("Tamaño de matriz: ");
    scanf("%d",&n);
    printf("Modos de acceso: \n1 ijk\t4 jki\n2 ikj\t5 kij\n3 jik\t6 kji\n> ");
    scanf("%d",&modo);

    matrizA = (int **)malloc(n * sizeof(int *));
    matrizB = (int **)malloc(n * sizeof(int *));
    matrizC = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++) {
        matrizA[i] = (int *)malloc(n * sizeof(int));
        matrizB[i] = (int *)malloc(n * sizeof(int));
        matrizC[i] = (int *)malloc(n * sizeof(int));
    }

    // Llenar valores de matrices
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            matrizA[i][j] = rand() % 6;
            matrizB[i][j] = rand() % 6;
            matrizC[i][j] = 0;
        }
    }

    get_walltime(&S1);

    switch(modo){
    case 1:
	printf("\nMétodo ijk con matrices de tamaño %d\n",n);
	for (i = 0; i < n; ++i) {
       	    for (j = 0; j < n; ++j) {
               for (k = 0; k < n; ++k) {
                  matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
       	       }
       	    }
        }
    break;
    case 2:
	printf("\nMétodo ikj con matrices de tamaño %d\n",n);
	for (i = 0; i < n; ++i) {
       	    for (k = 0; k < n; ++k) {
               for (j = 0; j < n; ++j) {
                  matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
       	       }
       	    }
        }
    break;
    case 3:
	printf("\nMétodo jik con matrices de tamaño %d\n",n);
	for (j = 0; j < n; ++j) {
       	    for (i = 0; i < n; ++i) {
               for (k = 0; k < n; ++k) {
                  matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
       	       }
       	    }
        }
    break;
    case 4:
	printf("\nMétodo jki con matrices de tamaño %d\n",n);
	for (j = 0; j < n; ++j) {
       	    for (k = 0; k < n; ++k) {
               for (i = 0; i < n; ++i) {
                  matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
       	       }
       	    }
        }
    break;
    case 5:
	printf("\nMétodo kij con matrices de tamaño %d\n",n);
	for (k = 0; k < n; ++k) {
       	    for (i = 0; i < n; ++i) {
               for (j = 0; j < n; ++j) {
                  matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
       	       }
       	    }
        }
    break;
    case 6:
	printf("\nMétodo kji con matrices de tamaño %d\n",n);
	for (k = 0; k < n; ++k) {
       	    for (j = 0; j < n; ++j) {
               for (i = 0; i < n; ++i) {
                  matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
       	       }
       	    }
        }
    break;
    default:
	for (i = 0; i < n; ++i) {
       	    for (j = 0; j < n; ++j) {
               for (k = 0; k < n; ++k) {
                  matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
       	       }
       	    }
        }
    }


    // Multiplicación de matrices (Método ijk)

    // Finaliza toma de tiempo
    get_walltime(&E1);

    printf("Tiempo método %f s\n", (E1 - S1));

	/*Usadas para verificar el proceso
	printf("Matriz A\n");
    for(i=0; i<n; i++){
	for(j=0; j<n; j++){
		printf("%d\t",matrizA[i][j]);
	}
	printf("\n");
    }
    printf("Matriz B\n");
    for(i=0; i<n; i++){
	for(j=0; j<n; j++){
		printf("%d\t",matrizB[i][j]);
	}
	printf("\n");
    }
    printf("Matriz C\n");
    for(i=0; i<n; i++){
	for(j=0; j<n; j++){
		printf("%d\t",matrizC[i][j]);
	}
	printf("\n");
    }*/

    // Liberar memoria
    for (i = 0; i < n; i++) {
        free(matrizA[i]);
        free(matrizB[i]);
        free(matrizC[i]);
    }
    free(matrizA);
    free(matrizB);
    free(matrizC);

    return 0;
}
