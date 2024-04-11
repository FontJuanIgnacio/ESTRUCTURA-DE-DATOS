#include <iostream>
#include <vector>

using namespace std;

// Estructura para representar una posición en la matriz
struct Posicion {
    int fila;
    int columna;
};

// Función para encontrar el punto de silla en la matriz M
Posicion encontrarPuntoDeSilla(const vector<vector<int>>& M) {
    int filas = M.size();
    int columnas = M[0].size();

    // Encontrar máximo de cada fila
    vector<int> maximos_filas;
    for (int i = 0; i < filas; ++i) {
        int maximo_fila = M[i][0];
        for (int j = 1; j < columnas; ++j) {
            if (M[i][j] > maximo_fila) {
                maximo_fila = M[i][j];
            }
        }
        maximos_filas.push_back(maximo_fila);
    }

    // Encontrar mínimo de cada columna
    vector<int> minimos_columnas;
    for (int j = 0; j < columnas; ++j) {
        int minimo_columna = M[0][j];
        for (int i = 1; i < filas; ++i) {
            if (M[i][j] < minimo_columna) {
                minimo_columna = M[i][j];
            }
        }
        minimos_columnas.push_back(minimo_columna);
    }

    // Verificar si hay algún punto de silla
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (M[i][j] == maximos_filas[i] && M[i][j] == minimos_columnas[j]) {
                // Se ha encontrado un punto de silla
                return {i, j};
            }
        }
    }

    // Si no se encontró ningún punto de silla, devolver {-1, -1}
    return {-1, -1};
}

int main() {
    // Definir la matriz M
    vector<vector<int>> M = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Encontrar el punto de silla en la matriz M
    Posicion punto_de_silla = encontrarPuntoDeSilla(M);

    // Imprimir el resultado
    if (punto_de_silla.fila != -1 && punto_de_silla.columna != -1) {
        cout << "El punto de silla se encuentra en la fila " << punto_de_silla.fila << " y columna " << punto_de_silla.columna << endl;
    } else {
        cout << "No se encontró ningún punto de silla en la matriz." << endl;
    }

    return 0;
}