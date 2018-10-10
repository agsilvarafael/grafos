/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fila.h
 * Author: jeronimo
 *
 * Created on 2 de Outubro de 2018, 10:41
 */

#ifndef FILA_H
#define FILA_H

#include "Lista.h"


class Fila {
public:
    Fila();
    void add(char value);
    char see();
    void pop();
    virtual ~Fila();
private:
    Lista fila;
};

#endif /* FILA_H */

