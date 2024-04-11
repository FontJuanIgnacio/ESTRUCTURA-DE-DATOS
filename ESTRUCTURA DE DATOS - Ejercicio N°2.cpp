
// Online C Compiler - Build, Compile and Run your C programs online in your favorite browser

#include <iostream>

int main() {
    int A, B;
    
    // Solicitar al usuario que ingrese los valores de A y B
    std::cout << "Ingrese el valor de A: ";
    std::cin >> A;
    
    std::cout << "Ingrese el valor de B: ";
    std::cin >> B;
    
    // Comparar los valores de A y B y emitir el resultado correspondiente
    if (A < B) {
        std::cout << "-1" << std::endl;
    } else if (A > B) {
        std::cout << "1" << std::endl;
    } else {
        std::cout << "0" << std::endl;
    }
    
    return 0;
}


