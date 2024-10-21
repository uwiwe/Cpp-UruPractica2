// Archivo para leer datos

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct People {
    int id;
    char nombre[50];
    int cedula;
    int edad;
    float peso;
    float altura;
    char genero;
};

int main() {
    People persona;
    int idx;

    cout << "Ingrese el id de la persona que desea buscar: ";
    cin >> idx;

    fstream FILE("./archivo.bin", ios::in | ios::binary);
    if (!FILE) {
        cout << "Error al abrir el archivo" << endl;
        return 0;
    }

    FILE.seekg((idx - 1) * sizeof(People), ios::beg);
    FILE.read(reinterpret_cast<char*>(&persona), sizeof(People));
    
    if (persona.id == idx) {
        cout << "id: " << persona.id << endl;
        cout << "Nombre: " << persona.nombre << endl;
        cout << "Cedula: " << persona.cedula << endl;
        cout << "Edad: " << persona.edad << endl;
        cout << "Peso: " << persona.peso << " kg" << endl;
        cout << "Altura: " << persona.altura << " cm" << endl;
        cout << "Genero: " << persona.genero << endl;
    } else {
        cout << "No se encontro una persona con el id ingresado." << endl;
    }

    FILE.close();
    return 0;
}
