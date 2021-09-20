//
// File: main.cpp
// Date: 19/09/2021
// Author: Said Ortigoza
// Description: Este archivo contiene el programa main
//              del proyecto
//
// Copyright (c) 2021 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//

#include <fstream>
#include "alumno.h"
#include "sorts.h"

using namespace std;

int main(){
    //Para usar archivos .txt
    ifstream inputFile;
	ofstream outputFile;

    //Vector que almacena los alumnos
	vector<Alumno> v;

    string nombre, apellido;
    int matricula, dinero;

    //Abrir el archivo
    inputFile.open("alumnos.txt");
	
    if (inputFile.is_open()) {
	    while (inputFile>>matricula>>nombre>>apellido>>saldo){
            //Mostrar la información del archivo desordenada
            cout << '\n' << "Mostrando registro de alumnos pre ordenamiento..." << endl;
            cout<< matricula << " " << nombre << " " << apellido << " " << " " << endl;
            
            //Almacenar la información en el vector
            Alumno alumno(matricula, nombre, apellido, saldo);
            v.push_back(alumno);
		}
        
        //Cerrar el archivo
        inputFile.close();

        //Ordenar y mostrar
        cout << '\n' << "Ordenando registro de alumnos..." << endl;
        ordenaBurbuja(v);
        
        cout << '\n' << "Mostrando el registro de alumnos ordenado..." << endl;
        for(int i = 0; i < v.size(); i++){
            v[i].mostrar();
        }

        //Almacenar ordenados en un archivo .txt
        cout << '\n' << "Almacenando el registro de alumnos ordenado..." << endl;
        outputFile.open("alumnosSort.txt");
        
        if (outputFile.is_open()) {
            for (int i = 0; i < v.size(); i++) {
                outputFile << v[i].getMatricula() << " " << v[i].getNombre() << " " << v[i].getApellido() << " " << v[i].getSaldo() << endl;
            }
        }

        outputFile.close();
        
        cout << "Almacenamiento exitoso." << endl;

        //Búsqueda de alumno por matrícula
        int mat, pos;
        cout << "\n" << "Ingresa la matrícula que deseas buscar" << endl;
        cin >> mat;

        pos = busqBinaria(v, mat);

        //Mostramos resultado de la busqueda
        cout << "\n" << "Resultado de la busqueda: " << endl;
        
        if (pos >= 0) {
            v[pos].mostrarInfo();
        } else {
            cout << "\n" << "Alumno no encontrado en la base de datos." << endl;
        }
	}

    else{
        cout<<"Error al abrir archivo"<<endl;
        return 0;
    }

    return 0;
}