#include <opencv2/opencv.hpp>
#include <iostream>
#include <thread>
#include <vector>

using namespace cv;
using namespace std;

// Función para convertir a escala de grises una sección de la imagen de manera paralela
void convertirAGrisParalelo(const Mat& imagenColor, Mat& imagenGris, int inicioY, int finY) {
    for (int y = inicioY; y < finY; y++) {
        for (int x = 0; x < imagenColor.cols; x++) {
            Vec3b pixel = imagenColor.at<Vec3b>(y, x);
            uchar gris = static_cast<uchar>(0.21 * pixel[2] + 0.72 * pixel[1] + 0.07 * pixel[0]);
            imagenGris.at<uchar>(y, x) = gris;
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 4) {
        cout << "Uso: " << argv[0] << " <ImagenEntrada> <ImagenSalida> <NumHilos>" << endl;
        return -1;
    }

    Mat imagen = imread(argv[1], IMREAD_COLOR);
    if (imagen.empty()) {
        cout << "No se pudo abrir o encontrar la imagen" << endl;
        return -1;
    }

    int numHilos = stoi(argv[3]);
    vector<thread> hilos;
    Mat imagenGris(imagen.rows, imagen.cols, CV_8UC1);

    int paso = imagen.rows / numHilos;
    // Crea un hilo por cada sección de la imagen
    for (int i = 0; i < numHilos; ++i) {
        hilos.emplace_back(convertirAGrisParalelo, cref(imagen), ref(imagenGris), i * paso, (i + 1) * paso);
    }

    // Espera a que todos los hilos terminen
    for (auto& hilo : hilos) {
        hilo.join();
    }

    // Guarda la imagen resultante
    if (!imwrite(argv[2], imagenGris)) {
        cout << "Error al guardar la imagen" << endl;
        return -1;
    }

    return 0;
}
