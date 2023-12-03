# Proyecto de Procesamiento de Imágenes

## Descripción

Este proyecto implementa un programa para convertir imágenes a color en imágenes en escala de grises. Se proporcionan tres versiones del programa: una versión secuencial, una versión paralela utilizando `std::thread` y una versión paralela utilizando OpenMP.

## Estructura del Proyecto

```
proyecto-imagenes/
│
├── src/
│   ├── secuencial/
│   │   ├── lumus.cpp
│   │   ├── Makefile
│   │   └── README.md
│   │
│   ├── paralelo_thread/
│   │   ├── lumus_parallel_thread.cpp
│   │   ├── Makefile
│   │   └── README.md
│   │
│   └── paralelo_openmp/
│       ├── lumus_parallel_openmp.cpp
│       ├── Makefile
│       └── README.md
│
├── bin/      [Archivos binarios compilados]
├── img/      [Imágenes de prueba]
├── Makefile
└── README.md
```

## Requisitos

- C++11 o superior
- OpenCV
- GNU Make (opcional para compilación)

## Instalación de OpenCV

Para instalar OpenCV en tu sistema, sigue estos pasos:

### Linux (Ubuntu/Debian)

1. Actualiza los paquetes de tu sistema:
   ```bash
   sudo apt-get update
   sudo apt-get upgrade
   ```
2. Instala las dependencias necesarias:
   ```bash
   sudo apt-get install build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
   ```
3. Instala OpenCV:
   ```bash
   sudo apt-get install libopencv-dev
   ```

Para otras distribuciones o sistemas operativos, visita [Instalación de OpenCV](https://opencv.org/releases/).

## Compilación

Para compilar los programas, utiliza el `Makefile` proporcionado en el directorio raíz:

```bash
make
```

Esto generará ejecutables en el directorio `bin/`.

### Limpieza

Para eliminar los archivos binarios compilados, ejecuta:

```bash
make clean
```

## Uso

Para ejecutar las diferentes versiones del programa, utiliza los siguientes comandos:

### Versión Secuencial

Para obtener más información, consulta el [README.md](src/secuencial/README.md) en `src/secuencial/`.

```bash
./bin/lumus ruta/a/imagen_entrada.jpg ruta/a/imagen_salida.jpg
```

EJ:

```
./bin/lumus img/1.jpg img/salida_1.jpg
```

### Versión Paralela con `std::thread`

Para obtener más información, consulta el [README.md](src/paralelo_thread/README.md) en `src/paralelo_thread/`.

```bash
./bin/lumus_parallel_thread ruta/a/imagen_entrada.jpg ruta/a/imagen_salida.jpg num_hilos
```

EJ:

```
./bin/lumus_parallel_thread img/1.jpg img/salida_parallel_1.jpg 4
```

### Versión Paralela con OpenMP

Para obtener más información, consulta el [README.md](src/paralelo_openmp/README.md) en `src/paralelo_openmp/`.

```bash
./bin/lumus_parallel_openmp ruta/a/imagen_entrada.jpg ruta/a/imagen_salida.jpg
```

EJ:

```
./bin/lumus_parallel_openmp img/1.jpg img/salida_openmp_1.jpg
```

## Licencia

GNU 3.0

## Autores

- Juan Pablo Rosas M.
- Diego Gutierrez M.
