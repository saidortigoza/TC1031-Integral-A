//
// alumno.h
//
// Created on: 19/09/2021
// Author: Said Ortigoza
//
// Description: Clase para almacenar los atributos de cada alumno
//

#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
using namespace std;

class Alumno {
    private:
        string nombre, apellido;
        int matricula, saldo, costoCredito = 10000;

    public:
        Alumno(int m, string n, string a, int s){
            matricula = m;
            nombre = n;
            apellido = a;
            saldo = s;
        }
    
    void mostrarInfo();

    int getMatricula();
    string getNombre();
    string getApellido();
    int getSaldo();
};

void Alumno::mostrarInfo(){
    cout << matricula << " " << nombre << " " << apellido << " " << saldo << endl;
}

int Alumno::getMatricula(){
    return matricula;
}

string Alumno::getNombre(){
    return nombre;
}

string Alumno::getApellido(){
    return apellido;
}

int Alumno::getSaldo(){
    retun saldo;
}

#endif