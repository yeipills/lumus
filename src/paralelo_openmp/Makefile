# Definir el compilador
CC=g++

# Opciones de compilación, excluyendo las banderas de OpenCV
CFLAGS=-std=c++11 -fopenmp

# Opciones de vinculación para OpenCV
OPENCV_LIBS=`pkg-config --cflags --libs opencv4`

# Ruta al directorio de binarios
BINDIR=../../bin

# Nombre del ejecutable
EXECUTABLE=$(BINDIR)/lumus_parallel_openmp

# Regla principal
all: $(EXECUTABLE)

# Regla para compilar el ejecutable
$(EXECUTABLE): lumus_parallel_openmp.cpp
	$(CC) $(CFLAGS) lumus_parallel_openmp.cpp -o $(EXECUTABLE) $(OPENCV_LIBS)

# Regla para limpiar los archivos compilados
clean:
	rm -f $(EXECUTABLE)
