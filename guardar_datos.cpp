// Archivo para guardar datos

#include<iostream>
#include<fstream>
#include<cstring>

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

int main(){
    int x = 0;

    cout << "Cuantas personas desea registrar?" << endl;
    cin >> x;

    fstream FILE("./archivo.bin",ios::out| ios::binary);

    for (int i = 1; i <= x; ++i) {
        People persona;
        persona.id = i;

        cout << "Persona numero " << i << endl;

        cout << "Ingrese el nombre: " << endl;
        cin >> persona.nombre;

        cout << "Ingrese la cedula: " << endl;
        cin >> persona.cedula;

        cout << "Ingrese la edad: " << endl;
        cin >> persona.edad;

        cout << "Ingrese el peso (kg): " << endl;
        cin >> persona.peso;

        cout << "Ingrese el altura (cm): " << endl;
        cin >> persona.altura;

        cout << "Ingrese el genero (M/F): " << endl;
        cin >> persona.genero;

        FILE.write(reinterpret_cast<char *>(&persona), sizeof(People));
    }

    FILE.close();

    return 0;
}
