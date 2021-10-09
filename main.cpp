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
#include "list.h"

using namespace std;

int main(){
    //Para usar archivos .txt
    ifstream inputFile;
	ofstream outputFile;

    //Vector que almacena los alumnos
	vector<Alumno> v;

    string nombre, apellido;
    int matricula, saldo;

    //Abrir el archivo
    inputFile.open("alumnos.txt");
	
    if (inputFile.is_open()) {
	    cout << '\n' << "Mostrando registro de alumnos pre ordenamiento..." << '\n' << endl;
        while (inputFile>>matricula>>nombre>>apellido>>saldo){
            //Mostrar la información del archivo desordenada
            cout<< matricula << " " << nombre << " " << apellido << " " << saldo << endl;
            
            //Almacenar la información en el vector
            Alumno alumno(matricula, nombre, apellido, saldo);
            v.push_back(alumno);
		}
        
        //Cerrar el archivo
        inputFile.close();

        //Ordenar y mostrar
        cout << '\n' << "Ordenando registro de alumnos..." << endl;
        bubbleSort(v);
        
        cout << '\n' << "Mostrando el registro de alumnos ordenado..." << '\n' << endl;
        for(int i = 0; i < v.size(); i++){
            v[i].mostrarInfo();
        }

        //Almacenar ordenados en un archivo .txt
        outputFile.open("alumnosSort.txt");
        
        if (outputFile.is_open()) {
            for (int i = 0; i < v.size(); i++) {
                outputFile << v[i].getMatricula() << " " << v[i].getNombre() << " " << v[i].getApellido() << " " << v[i].getSaldo() << endl;
            }
        }

        outputFile.close();

        //Búsqueda binaria de alumno por matrícula
        int mat, pos;
        cout << "\n" << "Busqueda Binaria de alumno por matricula" << endl;
        cout << "Ingresa la matricula que deseas buscar: ";
        cin >> mat;

        pos = binarySearch(v, mat);

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

    List<Alumno> lista;

    //Abrir el archivo
    cout << "\n" << "Leyendo archivo alumnosSort.txt y guardando matriculas en una lista ligada..." << endl;
    inputFile.open("alumnosSort.txt");
	
    if (inputFile.is_open()) {
        while (inputFile>>matricula>>nombre>>apellido>>saldo){
            //Almacenar la información en el vector
            Alumno alumno(matricula, nombre, apellido, saldo);
            lista.insertion(alumno);
		}
        
        //Cerrar el archivo
        inputFile.close();
        
        //Mostramos la lista
        cout << "\n" << "Lista ligada simple creada..." << "\n" << endl;
        cout << lista.toString() <<endl;

        //Almacenar ordenados en un archivo .txt
        cout << '\n' << "Almacenando el registro de matriculas..." << "\n" << endl;
        outputFile.open("alumnosList.txt");
        
        if (outputFile.is_open()) {
            outputFile << "Lista con matriculas de estudiantes" << endl;
            outputFile << lista.toString() <<endl;
        }

        outputFile.close();
        
        cout << "Almacenamiento exitoso." << "\n" << endl;
	}

    else{
        cout<<"Error al abrir archivo"<<endl;
        return 0;
    }

    return 0;
}