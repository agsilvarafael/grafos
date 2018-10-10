/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pilha.h
 * Author: jeronimo
 *
 * Created on 2 de Outubro de 2018, 10:41
 */

#ifndef PILHA_H
#define PILHA_H

#include "Lista.h"


class Pilha {
public:
    Pilha();
    void add(char value);
    char see();
    void pop();
    virtual ~Pilha();
private:
    Lista pilha;
};

#endif /* PILHA_H */

