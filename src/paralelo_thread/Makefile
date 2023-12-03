 # Definir el compilador
CC=g++

# Opciones de compilación, incluyendo banderas para OpenCV y para el soporte de hilos
CFLAGS=-std=c++11 -pthread `pkg-config --cflags --libs opencv4`

# Ruta al directorio de binarios
BINDIR=../../bin

# Nombre del ejecutable
EXECUTABLE=$(BINDIR)/lumus_parallel_thread

# Regla principal
all: $(EXECUTABLE)

# Regla para compilar el ejecutable
$(EXECUTABLE): lumus_parallel_thread.cpp
	$(CC) $(CFLAGS) lumus_parallel_thread.cpp -o $(EXECUTABLE)

# Regla para limpiar los archivos compilados
clean:
	rm -f $(EXECUTABLE)
