/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryTree.cpp
 * Author: jhdra
 * 
 * Created on 20 de Setembro de 2018, 16:48
 */

#include <stdlib.h>
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include "BinaryTree.h"

using namespace BinaryTree;

BinaryTree::BinaryTree() {
    root = NULL;
    cont_nodes = 0;
}

BinaryTree::BinaryTree(char root_v) {
    root = createNode();
    root->value = root_v;
    cont_nodes = 1;
}

BinaryTree::BinNode_t* BinaryTree::dfs(char value, BinNode_t* arvore) {
    if(arvore == NULL)
        return NULL;
    puts(arvore->value);
    if(arvore->value == value)
        return arvore;
    BinNode_t *l = bfs(value, arvore->left);
    if(l != NULL)
        return l;
    BinNode_t *r = bfs(value, arvore->right);
    if(r != NULL)
        return *r;
    return NULL;
}

BinaryTree::BinNode_t* BinaryTree::bfs(char value) {
//    list<char> fila;
//    vector<char, bool> visitados[cont_nodos];
//    int cont_v = 0;
//    visitados[tree->value] = true;
//    while(!fila.empty()){
//    }
}

BinaryTree::BinNode_t* BinaryTree::print_father(char son, BinNode_t *nodo) {
    if(nodo == NULL)
        return NULL;
    if(nodo->left != NULL && nodo->left-> == son){
        printf("%c\n", nodo->value);
        return nodo;
    }
    else if(nodo->right != NULL && nodo->right == son){
        printf("%c\n", nodo->value);
        return nodo;
    }else{
        BinNode_t* aux1 = print_father(son, nodo->left);
        BinNode_t* aux2 = print_father(son, nodo->right);
        if(aux1 != NULL)
            return aux1;
        if(aux2 == NULL)
            return aux2;
        return NULL;
    }
}

void BinaryTree::print_brothers(char value, BinNode_t *nodo) {
    if(nodo == NULL)
        return;
    if(nodo->left != NULL && nodo->left-> == value){
        if(nodo->right != NULL)
            printf("%c\n", nodo->value);
        else
            puts("Não possui irmão");
    }
    else if(nodo->right != NULL && nodo->right == value){
        printf("%c\n", nodo->value);
        if(nodo->left != NULL)
            printf("%c\n", nodo->value);
        else
            puts("Não possui irmão");
    }else{
        print_father(value, nodo->left);
        print_father(value, nodo->right);
    }
}

void BinaryTree::print_ancestors(char value) {
    BinNode_t *aux;
    while(aux != root){
        BinNode_t* p = print_father(value, root);
        value = p->value;
    }
}

void BinaryTree::print_descendents(BinNode_t *father) {
    if(father->left != NULL){
        printf("%c ", father->left->value);
        print_descendents(father->left);
    }
    if(father->right != NULL){
        printf("%c ", father->right->value);
        print_descendents(father->right);
    }
}

void BinaryTree::print_uncles(BinNode_t *me) {
    char v_father = print_father(me->value, root)->value;
    print_brothers(v_father, root);
}

BinaryTree::BinNode_t* BinaryTree::createNode() {
    BinNode_t *temp = malloc(sizeof(BinNode_t));
    temp->value = '\0';
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

BinaryTree::BinNode_t* BinaryTree::get_root() {
    return root;
}

bool BinaryTree::add_node(char father, char son_left, char son_right) {
    BinNode_t *aux = dfs(father, root);
    if(son_left != NULL || son_left != '\0'){
        aux->left = createNode();
        aux->left->value = son_left;
    }
    if(son_right != NULL || son_right != '\0'){
        aux->right = createNode();
        aux->right->value = son_left;
    }
}


BinaryTree::~BinaryTree() {
}
