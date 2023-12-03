#include <opencv2/opencv.hpp>
#include <iostream>

// Espacios de nombres para facilitar la escritura del código
using namespace cv;
using namespace std;

// Función para convertir una imagen a color a escala de grises
void convertirAGris(const Mat& imagenColor, Mat& imagenGris) {
    // Recorre cada píxel de la imagen
    for (int y = 0; y < imagenColor.rows; y++) {
        for (int x = 0; x < imagenColor.cols; x++) {
            Vec3b pixel = imagenColor.at<Vec3b>(y, x); // Obtiene el píxel (BGR)
            // Aplica la fórmula de luminosidad para convertir a gris
            uchar gris = static_cast<uchar>(0.21 * pixel[2] + 0.72 * pixel[1] + 0.07 * pixel[0]);
            imagenGris.at<uchar>(y, x) = gris; // Asigna el valor gris al nuevo píxel
        }
    }
}

int main(int argc, char** argv) {
    // Verifica que se pasen los argumentos correctos
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " <ImagenEntrada> <ImagenSalida>" << endl;
        return -1;
    }

    // Carga la imagen de entrada
    Mat imagen = imread(argv[1], IMREAD_COLOR);
    if (imagen.empty()) {
        cout << "No se pudo abrir o encontrar la imagen" << endl;
        return -1;
    }

    // Crea una imagen en blanco del mismo tamaño para la salida en escala de grises
    Mat imagenGris(imagen.rows, imagen.cols, CV_8UC1);

    // Convierte la imagen a escala de grises
    convertirAGris(imagen, imagenGris);

    // Guarda la imagen resultante
    if (!imwrite(argv[2], imagenGris)) {
        cout << "Error al guardar la imagen" << endl;
        return -1;
    }

    return 0;
}

