#include <iostream>
#include <cmath>

using namespace std;

// Función para evaluar el polinomio
double evaluarPolinomio(double Xo, int m, int exponentes[], double coeficientes[]) {
    double resultado = 0;
    for (int i = 0; i < m; ++i) {
        resultado += coeficientes[i] * pow(Xo, exponentes[i]);
    }
    return resultado;
}

// Función para calcular la primera derivada del polinomio
void primeraDerivada(int m, int exponentes[], double coeficientes[]) {
    cout << "La primera derivada del polinomio es: ";
    for (int i = 0; i < m; ++i) {
        if (exponentes[i] != 0) {
            cout << coeficientes[i] * exponentes[i] << "x^" << exponentes[i] - 1;
            if (i < m - 1) {
                cout << " + ";
            }
        }
    }
    cout << endl;
}

int main() {
    int m;
    cout << "Ingrese la cantidad de términos del polinomio: ";
    cin >> m;

    int exponentes[m];
    double coeficientes[m];

    // Ingresar los exponentes y coeficientes
    for (int i = 0; i < m; ++i) {
        cout << "Ingrese el exponente para el término " << i + 1 << ": ";
        cin >> exponentes[i];
        cout << "Ingrese el coeficiente para el término " << i + 1 << ": ";
        cin >> coeficientes[i];
    }

    // Calcular y mostrar la primera derivada del polinomio
    primeraDerivada(m, exponentes, coeficientes);

    return 0;
}