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
#include "casosPrueba.h"
#include "sorts.h"
#include "list.h"
#include "heap.h"

using namespace std;

int main(){
    //Para usar archivos .txt
    ifstream inputFile;
	ofstream outputFile;

    //Vector que almacena los alumnos
	vector<Alumno> v;

    string nombre, apellido, respuesta, line;
    int matricula, saldo, ansMatricula;

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
        cout << "\n" << "Busqueda binaria de alumno por matricula" << endl;
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

    //Lista que almacena las matriculas
    List<Alumno> lista;

    //Abrir el archivo
    cout << "\n" << "Leyendo archivo alumnosSort.txt y guardando matriculas en una lista ligada..." << endl;
    inputFile.open("alumnosSort.txt");
	
    if (inputFile.is_open()) {
        while (inputFile>>matricula>>nombre>>apellido>>saldo){
            //Almacenar la información en la lista ligada
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
            outputFile << lista.toString() <<endl;
        }

        //Cerrar el archivo
        outputFile.close();
        
        cout << "Almacenamiento exitoso." << endl;
	}

    else{
        cout<<"Error al abrir archivo"<<endl;
        return 0;
    }

    //Arbol Heap
    Heap<int> arbol(25);

    cout << "\n" << "Leyendo archivo alumnosSort.txt y guardando matriculas de estudiantes en un Arbol Heap..." << endl;
    inputFile.open("alumnosSort.txt");
	if (inputFile.is_open()) {
        while (inputFile>>matricula>>nombre>>apellido>>saldo){
            //Almacenar las matriculas en un arbol Heap
            arbol.push(matricula);
		}

        cout << "\n" << "Archivo leido exitosamente." << endl;
        inputFile.close();
        
        //Mostrar el contenido del arbol
        cout << "\n" << "Arbol Heap creado: " << endl;
        cout << arbol.toString() <<endl;

        //Almacenar en archivo txt
        cout << '\n' << "Almacenando Arbol Heap con numeros de cuenta..." << endl;
        outputFile.open("alumnosHeap.txt");
        if (outputFile.is_open()) {
            outputFile << arbol.toString() <<endl;
        }
        
        //Cerrar el archivo
        outputFile.close();
        cout << "\n" << "Almacenamiento exitoso." << endl;

        //Busqueda secuencial de matricula
        cout << "\n" << "Busqueda de alumno dentro del Arbol Heap" << endl;
        cout << "Ingresa la matricula que deseas buscar: ";
        cin >> ansMatricula;
        
        //Se realiza la busqueda
        if(arbol.busqSecuencial(ansMatricula)) {
        cout << "\n" << "La matricula ingresada se encuentra dentro del registro." << endl;
        } else {
        cout << "\n" << "La matricula ingresada no existe dentro del registro." << endl;
        }
	}

    else {
        cout<<"Fallo al abrir archivo."<<endl;
        return 0;
    }

    cout << "\n" << "Correr casos de prueba? (si/no)" << endl;
    cin >> respuesta;
    if (respuesta == "si") {
      casosBusqBinaria(v);
      casosBusqArbol(arbol);
    } else {
      cout<<"Ok sera para la proxima"<<endl;
    }

    return 0;
}