/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mapa.h
 * Author: jeronimo
 *
 * Created on 2 de Outubro de 2018, 10:48
 */

#ifndef MAPA_H
#define MAPA_H

#include "Lista.h"


class Mapa {
public:
    Mapa();
    Lista get_by_key(char value);
    Lista get_keys();
    virtual ~Mapa();
private:
    typedef struct m{
        char value;
        Lista adjacents;
        struct m* next;
    }mapa;
    Lista keys;
};

#endif /* MAPA_H */

