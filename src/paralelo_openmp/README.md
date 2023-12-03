# Versión Paralela con OpenMP - Procesamiento de Imágenes

## Descripción

Este programa convierte imágenes a color en imágenes en escala de grises utilizando paralelismo con OpenMP.

## Compilación y Ejecución

Para compilar el programa, ejecuta el comando `make` en este directorio:

```bash
make
```

Esto generará un ejecutable llamado `lumus_parallel_openmp` en el directorio `bin/` del proyecto.

Para ejecutar el programa, utiliza el siguiente comando desde el directorio raíz del proyecto:

```bash
../../bin/lumus_parallel_openmp ../../img/<ImagenEntrada> ../../img/<ImagenSalida>
```

Reemplaza `<ImagenEntrada>` con el nombre del archivo de imagen a color y `<ImagenSalida>` con el nombre del archivo donde se guardará la imagen en escala de grises.

## Ejemplo

Desde el directorio raíz del proyecto:

```bash
../../bin/lumus_parallel_openmp ../../img/1.jpg ../../img/imagen_gris.jpg
```
