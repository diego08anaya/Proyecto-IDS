#include <iostream>
#include <string>
using namespace std;

const int NUM_ALUMNOS = 20; // Número máximo de alumnos

// Estructura para almacenar los datos personales de los alumnos
struct Alumno {

};

// Estructura para almacenar los nombres de las materias
struct Materias {
    string nombreMaterias[8];
};

// Función para mostrar el menú
void mostrarMenu() {
    cout << "\n--- Men\xA3 Principal ---" << endl;
    cout << "1. Dar de alta un alumno (incluyendo calificaciones)" << endl;
    cout << "2. Consultar alumno por nombre" << endl;
    cout << "3. Eliminar un alumno" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opci\xA2n: ";
}

// Función para dar de alta a un alumno 
void altaAlumno(Alumno alumnos[], int &numAlumnos, Materias &materias) {

}

// Función para consultar los datos de un alumno
void consultarAlumno(Alumno alumnos[], int numAlumnos, Materias &materias) {

}

// Función para eliminar un alumno
void eliminarAlumno(Alumno alumnos[], int &numAlumnos) {

}

int main() {
    Alumno alumnos[NUM_ALUMNOS]; // Array de 20 alumnos
    Materias materias;

    // Captura de los nombres de las materias al inicio
    cout << "Ingrese los nombres de las 8 materias:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << "Materia " << i + 1 << ": ";
        getline(cin, materias.nombreMaterias[i]);
    }

    int numAlumnos = 0; // Contador de alumnos registrados
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(); // Limpiar el salto de línea después de seleccionar una opción

        switch (opcion) {
            case 1:
                altaAlumno(alumnos, numAlumnos, materias);
                break;
            case 2:
                consultarAlumno(alumnos, numAlumnos, materias);
                break;
            case 3:
                eliminarAlumno(alumnos, numAlumnos);
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opci\xA2n no v\xA0lida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}
