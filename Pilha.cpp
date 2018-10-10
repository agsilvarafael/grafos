/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pilha.cpp
 * Author: jeronimo
 * 
 * Created on 2 de Outubro de 2018, 10:41
 */

#include "Pilha.h"

Pilha::Pilha() {
    pilha = Lista();
}

Pilha::~Pilha() {
    pilha.~Lista();
}

void Pilha::add(char value) {
    pilha.add_front(value);
}

void Pilha::see() {
    return pilha.front();
}

void Pilha::pop() {
    pilha.pop_front();
}


