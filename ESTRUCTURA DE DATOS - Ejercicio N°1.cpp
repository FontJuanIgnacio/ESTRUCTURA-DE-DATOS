#include<iostream>

using namespace std;

int main()
{
    //declaración de variables
    string x;
    string L[5]={"2","5","7","9","10"}; // arreglo 
    bool encontrado = false; // Bandera para indicar si se encontró el elemento
    
    cout << "Ingrese el elemento a buscar: ";
    cin >> x;
    
    for(int i = 0; i < 5; i++) {
        if(L[i] == x) {
            L[i] = "*"; //auto conversión equivalente código ASCII
            encontrado = true; // Marcar que se ha encontrado el elemento
        }
    }
    
    if(!encontrado) {
        cout << "El elemento " << x << " no se encuentra en la lista." << endl;
    }
    else {
        for(int i = 0; i < 5; i++) {
            cout << L[i] << " - ";
        }
    }
    
    return 0;
}
