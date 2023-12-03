#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

using namespace cv;
using namespace std;
using namespace std::chrono;

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " <ImagenEntrada> <ImagenSalida>" << endl;
        return -1;
    }

    Mat imagen = imread(argv[1], IMREAD_COLOR);
    if (imagen.empty()) {
        cout << "No se pudo abrir o encontrar la imagen" << endl;
        return -1;
    }

    Mat imagenGris(imagen.rows, imagen.cols, CV_8UC1);

    // Iniciar el temporizador
    auto start = high_resolution_clock::now();

    // Procesamiento de la imagen
    #pragma omp parallel for collapse(2)
    for (int y = 0; y < imagen.rows; y++) {
        for (int x = 0; x < imagen.cols; x++) {
            Vec3b pixel = imagen.at<Vec3b>(y, x);
            uchar gris = static_cast<uchar>(0.21 * pixel[2] + 0.72 * pixel[1] + 0.07 * pixel[0]);
            imagenGris.at<uchar>(y, x) = gris;
        }
    }

    // Detener el temporizador
    auto stop = high_resolution_clock::now();

    // Calcular la duración
    auto duration = duration_cast<microseconds>(stop - start);

    // Guarda la imagen resultante
    if (!imwrite(argv[2], imagenGris)) {
        cout << "Error al guardar la imagen" << endl;
        return -1;
    }

    // Mostrar el tiempo de ejecución
    cout << "Tiempo de ejecución: " << duration.count() / 1000.0 << " milisegundos" << endl;

    return 0;
}
