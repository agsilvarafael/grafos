/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.h
 * Author: jeronimo
 *
 * Created on 2 de Outubro de 2018, 11:07
 */

#ifndef LISTA_H
#define LISTA_H

class Lista {
public:
    int contador;
    Lista();
    void add_front(char value);
    void add_back(char value);
    void pop_front();
    void pop_back();
    char front();
    char back();
    void print_list();
    virtual ~Lista();
private:
    typedef struct l{
        char value;
        struct l *previous, *next;
    }List_t;
    List_t* create_element(char value);
    List_t* head;
};

#endif /* LISTA_H */

