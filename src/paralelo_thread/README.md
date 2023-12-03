# Versión Paralela con `std::thread` - Procesamiento de Imágenes

## Descripción

Este programa convierte imágenes a color en imágenes en escala de grises utilizando paralelismo con `std::thread`.

## Compilación y Ejecución

Para compilar el programa, ejecuta el comando `make` en este directorio:

```bash
make
```

Esto generará un ejecutable llamado `lumus_parallel_thread` en el directorio `bin/` del proyecto.

Para ejecutar el programa, utiliza el siguiente comando desde el directorio raíz del proyecto:

```bash
../../bin/lumus_parallel_thread ../../img/<ImagenEntrada> ../../img/<ImagenSalida> <NumHilos>
```

Reemplaza `<ImagenEntrada>` con el nombre del archivo de imagen a color, `<ImagenSalida>` con el nombre del archivo donde se guardará la imagen en escala de grises, y `<NumHilos>` con el número de hilos que deseas utilizar.

## Ejemplo

Desde el directorio raíz del proyecto:

```bash
../../bin/lumus_parallel_thread ../../img/1.jpg ../../img/salida_parallel_1.jpg 4
```
