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

    double Xo;
    cout << "Ingrese el valor de Xo para evaluar el polinomio: ";
    cin >> Xo;

    // Evaluar el polinomio
    double resultado = evaluarPolinomio(Xo, m, exponentes, coeficientes);

    cout << "El resultado de evaluar el polinomio para Xo = " << Xo << " es: " << resultado << endl;

    return 0;
}