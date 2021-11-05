//
//  File: casosPrueba.h
//  Date: 31/10/2021
//  Author: Said Ortigoza
//  Description: Implementación de las funciones de los casos de prueba
//
//  Copyrigth (c) 2021 by Tecnologico de Monterrey.
//  All Rights Reserved. May be reproduced for any non-commercial
//  purpose
//

#ifndef CASOSPRUEBA_H_
#define CASOSPRUEBA_H_

#include "alumno.h"
#include "sorts.h"
#include "heap.h"

using namespace std;

//Corre los casos de prueba de busqueda binaria
template <class T>
void casosBusqBinaria(vector<T> &v) {
    int pos;
    
    cout << "\n" << "Prueba 1 de busqueda binaria: input 1707430" << endl;
    pos = binarySearch(v, 1707430);
    cout << "Resultado de la busqueda: " << "\n" << endl;
    if (pos >= 0) {
        v[pos].mostrarInfo();
    } else {
        cout << "Alumno no encontrado en la base de datos." << endl;
    }

    cout << "\n" << "Prueba 2 de busqueda binaria: input 827472" << endl;
    pos = binarySearch(v, 827472);
    cout << "Resultado de la busqueda: " << "\n" << endl;
    if (pos >= 0) {
        v[pos].mostrarInfo();
    } else {
        cout << "Alumno no encontrado en la base de datos." << endl;
    }

    cout<< "\n" << "Prueba 3 de busqueda binaria: input 1403495" << endl;
    pos = binarySearch(v, 1378643);
    cout << "Resultado de la busqueda: " << "\n" << endl;
    if (pos >= 0) {
        v[pos].mostrarInfo();
    } else {
        cout << "Alumno no encontrado en la base de datos." << endl;
    }
}

template <class T>
void pruebaBusqArbol(Heap<T> &arbol, int mat) {
  if(arbol.busqSecuencial(mat)){
      cout << "Matricula encontrada." << endl;
  }
  else{
    cout << "Matricula no encontrada." << endl;
  }
}

template <class T>
void casosBusqArbol(Heap<T> &arbol) {
  cout << "\n" << "Prueba 1 de busqueda en Arbol Heap: input 1403495 == True" << endl;
  pruebaBusqArbol(arbol, 1403495);

  cout << "\n" << "Prueba 2 de busqueda en Arbol Heap: input 140444 == False" << endl;
  pruebaBusqArbol(arbol, 140444);

  cout << "\n" << "Prueba 3 de busqueda en Arbol Heap: input 1706352 = True" << endl;
  pruebaBusqArbol(arbol, 1706352);
}


#endif