/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fila.cpp
 * Author: jeronimo
 * 
 * Created on 2 de Outubro de 2018, 10:41
 */

#include "Fila.h"
#include "Lista.h"

Fila::Fila() {
    fila = Lista();
}

Fila::~Fila() {
    fila.~Lista();
}

void Fila::add(char value) {
    fila.add_back(value);
}

void Fila::see() {
    fila.front();
}

void Fila::pop() {
    fila.pop_front();
}

