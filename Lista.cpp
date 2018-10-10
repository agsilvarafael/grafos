/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: jeronimo
 * 
 * Created on 2 de Outubro de 2018, 11:07
 */

#include <cstdlib>

#include "Lista.h"

Lista::Lista() {
    head = NULL;
}

Lista::~Lista() {
    List_t* aux = head->previous;
    head->previous = NULL;
    while (aux != NULL) {
        aux = aux->previous;
        free(aux->next);
        aux->next = NULL;
    }
}

Lista::List_t* Lista::create_element(char value, List_t* previous, List_t* next) {
    List_t* l = (List_t*)malloc(sizeof(List_t));
    l->value = value;
    l->previous = previous;
    if(previous != NULL)
        previous->next = l;
    l->next = next;
    if(next != NULL)
        next->previous = l;
    return l;
}

void Lista::add_front(char value) {
    if(head == NULL){
        head = create_element(value, NULL, NULL);
        head->previous = head;
        head->next = head;
    }
    else{
        head = create_element(value, head->previous, head);
    }
}

void Lista::add_front(char value) {
    if(head == NULL){
        head = create_element(value, NULL, NULL);
        head->previous = head;
        head->next = head;
    }
    else{
        create_element(value, head, head->previous, );
    }
}

void Lista::pop_front() {
    List_t* aux = head;
    head = aux->next;
    head->previous = aux->previous;
    aux->previous->next = head;
    free(aux);
}

void Lista::pop_back() {
    List_t* aux = head->previous;
    head->previous = aux->previous;
    aux->previous->previous = head;
    free(aux);
}

char Lista::front() {
    return head->value;
}

char Lista::back() {
    return head->previous;
}


