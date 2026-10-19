# Guía de Instalación de MPI (Message Passing Interface)

Esta guía detalla los pasos para instalar MPI en sistemas operativos Linux (distribuciones basadas en Debian/Ubuntu) y Windows.

## Instalación en Linux (Ubuntu / Debian)

La forma más común y estable de utilizar MPI en entornos Linux es a través de la implementación **OpenMPI**.

1. **Actualizar los repositorios**
   Abre tu terminal y sincroniza la lista de paquetes disponibles.
   ```bash
   sudo apt update```

2. **Instalar OpenMPI**
   Instala los binarios de ejecución y las librerías de desarrollo (necesarias para compilar tu código fuente en C/C++).
   ```bash
   sudo apt install openmpi-bin libopenmpi-dev```

3. **Verificar la instalación**
   Comprueba que el compilador y el entorno de ejecución están listos en tu sistema.
   ```bash
   mpicc --version
   mpiexec --version```

> Deberías ver en la terminal la versión exacta de OpenMPI instalada sin mensajes de error.

## Instalación en Windows

1. **Descargar los instaladores de Microsoft**

    Dirígete a la página de descargas de Microsoft MPI o a su repositorio en GitHub. Debes descargar dos archivos de la última versión:

    `msmpisetup.exe` (El entorno de ejecución).
    `msmpisdk.msi` (El SDK, indispensable para compilar tus programas).

2. **Ejecutar la instalación**
    Ejecuta e instala primero msmpisetup.exe siguiendo las instrucciones del asistente. Una vez finalizado, ejecuta e instala msmpisdk.msi.

3. **Verificar las variables de entorno**
    Los instaladores deben configurar tu sistema automáticamente. Abre el "Símbolo del sistema" (cmd) o PowerShell y verifica las rutas:

    ```DOS
    set MSMPI```

4. **Comprobar el ejecutor**
    En la misma consola, comprueba que el sistema reconoce el comando de MPI:

    ```DOS
    mpiexec -help```

> Se desplegará la lista de parámetros y opciones de uso del comandoo mpiexec.