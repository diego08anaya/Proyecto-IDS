#include <iostream>
#include <string>
using namespace std;

const int NUM_ALUMNOS = 20; // Número máximo de alumnos

// Estructura para almacenar los datos personales de los alumnos
struct Alumno {
    string nombre;
    string matricula;
    float calificaciones[8];
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
    if (numAlumnos >= NUM_ALUMNOS) {
        cout << "No se pueden registrar más alumnos." << endl;
        return;
    }

    Alumno nuevoAlumno;
    cout << "Ingrese el nombre del alumno: ";
    getline(cin, nuevoAlumno.nombre);
    cout << "Ingrese la matrícula del alumno: ";
    getline(cin, nuevoAlumno.matricula);

    cout << "Ingrese las calificaciones para las materias:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << materias.nombreMaterias[i] << ": ";
        cin >> nuevoAlumno.calificaciones[i];
    }
    cin.ignore(); // Limpiar el buffer de entrada

    alumnos[numAlumnos] = nuevoAlumno;
    numAlumnos++;

    cout << "Alumno registrado con éxito." << endl;
}

// Función para consultar los datos de un alumno
void consultarAlumno(Alumno alumnos[], int numAlumnos, Materias &materias) {
    if (numAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }

    string nombreBusqueda;
    cout << "Ingrese el nombre del alumno a consultar: ";
    getline(cin, nombreBusqueda);

    for (int i = 0; i < numAlumnos; i++) {
        if (alumnos[i].nombre == nombreBusqueda) {
            cout << "\nNombre: " << alumnos[i].nombre << endl;
            cout << "Matrícula: " << alumnos[i].matricula << endl;
            cout << "Calificaciones:" << endl;
            for (int j = 0; j < 8; j++) {
                cout << materias.nombreMaterias[j] << ": " << alumnos[i].calificaciones[j] << endl;
            }
            return;
        }
    }

    cout << "Alumno no encontrado." << endl;
}

// Función para eliminar un alumno (opcional, aún no implementada)
void eliminarAlumno(Alumno alumnos[], int &numAlumnos) {
    // Aquí podrías implementar la lógica para eliminar un alumno en el futuro.
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
