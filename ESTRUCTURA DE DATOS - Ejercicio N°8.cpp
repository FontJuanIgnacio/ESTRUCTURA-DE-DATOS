#include <iostream>
#include <vector>

using namespace std;

// Estructura para representar un elemento no cero de la matriz sparse
struct ElementoSparse {
    int fila;
    int columna;
    int valor;
};

// Función para sumar dos matrices sparse A y B y almacenar el resultado en C
vector<ElementoSparse> sumarMatricesSparse(const vector<ElementoSparse>& A, const vector<ElementoSparse>& B, int n) {
    vector<ElementoSparse> C;
    vector<vector<int>> valoresC(n, vector<int>(n, 0)); // Matriz temporal para almacenar los valores de C
    
    // Sumar los elementos de A y B
    for (const auto& elemento : A) {
        valoresC[elemento.fila][elemento.columna] += elemento.valor;
    }
    for (const auto& elemento : B) {
        valoresC[elemento.fila][elemento.columna] += elemento.valor;
    }

    // Construir la matriz sparse C a partir de los valores no cero de la matriz temporal
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (valoresC[i][j] != 0) {
                ElementoSparse elemento;
                elemento.fila = i;
                elemento.columna = j;
                elemento.valor = valoresC[i][j];
                C.push_back(elemento);
            }
        }
    }

    return C;
}

// Función para imprimir una matriz sparse
void imprimirMatrizSparse(const vector<ElementoSparse>& matrizSparse, int n) {
    vector<vector<int>> matrizCompleta(n, vector<int>(n, 0));
    
    // Construir la matriz completa a partir de la matriz sparse
    for (const auto& elemento : matrizSparse) {
        matrizCompleta[elemento.fila][elemento.columna] = elemento.valor;
    }

    // Imprimir la matriz completa
    cout << "Matriz sparse:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrizCompleta[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Definir matrices sparse A y B
    vector<ElementoSparse> A = {
        {0, 1, 3},
        {1, 0, 2},
        {2, 2, 4}
    };
    vector<ElementoSparse> B = {
        {0, 1, 1},
        {1, 0, 2},
        {2, 2, 5}
    };
    int n = 3; // Tamaño de las matrices originales (n x n)

    // Sumar las matrices sparse A y B
    vector<ElementoSparse> C = sumarMatricesSparse(A, B, n);

    // Imprimir la matriz sparse resultante C
    imprimirMatrizSparse(C, n);

    return 0;
}