/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   trabalho1.cpp
 * Author: jeronimo
 *
 * Created on 2 de Outubro de 2018, 10:33
 */

#include <cstdlib>

#include "Lista.h"

using namespace std;

struct structLista{
        struct structVertice* v;
        int peso;
        struct structLista * proximo;
    };
typedef struct structLista ListaAdjacentes;

struct structVertice{
    char* nome;
    ListaAdjacentes* listaAdjacentes;
};
typedef struct structVertice Vertice;

/*
 * 
 */
int main(int argc, char** argv) {
    //http://linguagemc.com.br/argumentos-em-linha-de-comando/
    
    return 0;
}
