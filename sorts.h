//
// File: sorts.h
// Date: 19/09/2021
// Author: Said Ortigoza
// Description: Este archivo contiene las funciones
//              de los algoritmos de búsqueda y ordenamiento
//
// Copyright (c) 2021 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//

#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include "alumno.h"

template <class T>
void swap(vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
vector<T> bubbleSort(vector<T> &v) {
	for (int i = v.size() - 1 ; i >= 0 ; i--) {
		for (int j = 0 ; j < i ; j++) {
			if (v[j].getMatricula() > v[j + 1].getMatricula()) {
				swap(v, j, j + 1);
			}
		}
	}
    return v;
}

template<class T>
int bs_aux(vector<T> v, int low, int high, int n) {
    if (low < high) {
        int mid = (high + low) / 2;
        if (n == v[mid].getMatricula()) {
            return mid;
        } else if (n < v[mid].getMatricula()) {
            return bs_aux(v, low, mid - 1, n);
        } else if (n > v[mid].getMatricula()) {
            return bs_aux(v, mid + 1, high, n);
        }
    }
    return -1;
}

template<class T>
int binarySearch(const vector<T> &v, int n) {
    vector<T> vec(v);
    return bs_aux(vec, 0, vec.size() - 1, n);
}

#endif