#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Persona {
    string apellido;
    string nombre;
    double sueldo_o_promedio;
};

void aplicarAumento(vector<Persona>& personas) {
    for (auto& persona : personas) {
        // Aumentar el sueldo solo si la persona es tanto empleado como estudiante
        if (persona.sueldo_o_promedio > 7) {
            // Aumento de sueldo que se debe realizar al Estudiante-Empleado de un 10%
            persona.sueldo_o_promedio *= 1.1;
        }
    }
}

int main() {
    // Matriz de Empleados
    vector<Persona> empleados = {{"Mendoza", "Rodrigo", 5000},
                                 {"Font", "Juan Ignacio", 6000},
                                 {"Font", "Geronimo", 7000}};
    
    // Matriz de Estudiantes
    vector<Persona> alumnos = {{"Bueso", "Facundo", 6.5},
                                {"Font", "Juan Ignacio", 7.5},
                                {"Font", "Geronimo", 8.0}};

    // Encontrar estudiantes que también son empleados
    vector<Persona> estudiantes_empleados;
    for (const auto& estudiante : alumnos) {
        for (const auto& empleado : empleados) {
            if (estudiante.nombre == empleado.nombre && estudiante.apellido == empleado.apellido) {
                estudiantes_empleados.push_back(estudiante);
                break;
            }
        }
    }

    // Aplicar aumento solo a las personas que son tanto estudiantes como empleados
    aplicarAumento(estudiantes_empleados);

    // Mostrar los sueldos incrementados por pantalla
    cout << "Sueldos incrementados:" << endl;
    for (const auto& persona : estudiantes_empleados) {
        cout << "Apellido: " << persona.apellido << ", Nombre: " << persona.nombre;
        cout << ", Sueldo incrementado: " << persona.sueldo_o_promedio << endl;
    }

    return 0;
}