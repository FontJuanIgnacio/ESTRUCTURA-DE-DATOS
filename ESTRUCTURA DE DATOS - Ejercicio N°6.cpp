#include <iostream>
#include <vector>

using namespace std;

// Estructura para representar un elemento no cero de la matriz sparse
struct ElementoSparse {
    int fila;
    int columna;
    int valor;
};

// Función para generar la matriz sparse M a partir de la matriz dada A
vector<ElementoSparse> generarMatrizSparse(const vector<vector<int>>& A) {
    vector<ElementoSparse> M;
    int filas = A.size();
    int columnas = A[0].size();

    // Recorremos la matriz A para encontrar los elementos distintos de cero
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (A[i][j] != 0) {
                ElementoSparse elemento;
                elemento.fila = i;
                elemento.columna = j;
                elemento.valor = A[i][j];
                M.push_back(elemento);
            }
        }
    }

    return M;
}

// Función para imprimir la matriz sparse M
void imprimirMatrizSparse(const vector<ElementoSparse>& M) {
    for (const auto& elemento : M) {
        cout << "Fila: " << elemento.fila << ", Columna: " << elemento.columna << ", Valor: " << elemento.valor << endl;
    }
}

int main() {
    // Definir la matriz A
    vector<vector<int>> A = {
        {0, 0, 0, 0, 0},
        {5, 8, 0, 0, 0},
        {0, 0, 0, 3, 0},
        {0, 6, 0, 0, 0}
    };

    // Generar la matriz sparse M a partir de A
    vector<ElementoSparse> M = generarMatrizSparse(A);

    // Imprimir la matriz sparse M
    cout << "Matriz sparse M:" << endl;
    imprimirMatrizSparse(M);

    return 0;
}