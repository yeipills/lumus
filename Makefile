# Definir el compilador
CC=g++

# Opciones de compilación
CFLAGS=-std=c++11

# Opciones de vinculación para OpenCV
OPENCV_LIBS=`pkg-config --cflags --libs opencv4`

# Directorio de los archivos fuente
SRCDIR=src

# Subdirectorios para las versiones secuencial, con thread y con OpenMP
DIR_SECUENCIAL=$(SRCDIR)/secuencial
DIR_THREAD=$(SRCDIR)/paralelo_thread
DIR_OPENMP=$(SRCDIR)/paralelo_openmp

# Directorio de destino para los binarios
BINDIR=bin

# Nombres de los archivos fuente
SRC_SECUENCIAL=$(DIR_SECUENCIAL)/lumus.cpp
SRC_THREAD=$(DIR_THREAD)/lumus_parallel_thread.cpp
SRC_OPENMP=$(DIR_OPENMP)/lumus_parallel_openmp.cpp

# Nombres de los ejecutables
EXE_SECUENCIAL=$(BINDIR)/lumus
EXE_THREAD=$(BINDIR)/lumus_parallel_thread
EXE_OPENMP=$(BINDIR)/lumus_parallel_openmp

all: $(EXE_SECUENCIAL) $(EXE_THREAD) $(EXE_OPENMP)

$(EXE_SECUENCIAL): $(SRC_SECUENCIAL)
	$(CC) $(CFLAGS) $^ -o $@ $(OPENCV_LIBS)

$(EXE_THREAD): $(SRC_THREAD)
	$(CC) $(CFLAGS) $^ -pthread -o $@ $(OPENCV_LIBS)

$(EXE_OPENMP): $(SRC_OPENMP)
	$(CC) $(CFLAGS) $^ -fopenmp -o $@ $(OPENCV_LIBS)

clean:
	find $(BINDIR) -type f ! -name '.gitkeep' -delete

