#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

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

    // Utiliza OpenMP para paralelizar el bucle de conversión a escala de grises
    #pragma omp parallel for collapse(2)
    for (int y = 0; y < imagen.rows; y++) {
        for (int x = 0; x < imagen.cols; x++) {
            Vec3b pixel = imagen.at<Vec3b>(y, x);
            uchar gris = static_cast<uchar>(0.21 * pixel[2] + 0.72 * pixel[1] + 0.07 * pixel[0]);
            imagenGris.at<uchar>(y, x) = gris;
        }
    }

    // Guarda la imagen resultante
    if (!imwrite(argv[2], imagenGris)) {
        cout << "Error al guardar la imagen" << endl;
        return -1;
    }

    return 0;
}
