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
#include <string>
#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree() {
    root = NULL;
}

BinaryTree::BinNode_t* BinaryTree::createNode(char value) {
    BinNode_t *temp = (BinNode_t*)malloc(sizeof(BinNode_t));
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

bool BinaryTree::add_node(std::string input){
    BinNode_t* node;
    int len = input.size();
    if(len == 1)
        return false;
    if(root != NULL){
        list<BinNode_t*> fila;
        BinNode_t *aux;
        //Marca a raiz como visitada
        fila.push_back(root);
        while(!fila.empty()){
            aux = fila.front();
            fila.pop_front();
            if(aux->value == input[0]){
                node = aux;
                break;
            }
            if(aux->left != NULL){
                fila.push_back(aux->left);
            }
            if(aux->right != NULL){
                fila.push_back(aux->right);
            }
        }
    }
    else{
        root = createNode(input[0]);
        node = root;
    }
    if(len >= 3)
        node->left = createNode(input[2]);
    if(len == 5)
        node->right = createNode(input[4]);
    return true;
}

BinaryTree::BinNode_t* BinaryTree::get_root(){
    return root;
}

BinaryTree::BinNode_t* BinaryTree::dfs(char value) {
    /*//implementa��o recursiva
    if(arvore == NULL)
        return NULL;
    cout << arvore->value << ' ';
    if(arvore->value == value)
        return arvore;
    BinaryTree::BinNode_t *l = BinaryTree::dfs(value, arvore->left);
    if(l != NULL)
        return l;
    BinNode_t *r = dfs(value, arvore->right);
    if(r != NULL)
        return r;
    return NULL;
    /*/
    if(root == NULL)
        return NULL;
    //fila do BFS
    list<BinNode_t*> fila;
    BinNode_t *aux;
    //Marca a raiz como visitada
    fila.push_front(root);
    cout << "DFS: ";
    while(!fila.empty()){
        aux = fila.front();
        cout << aux->value << " ";
        fila.pop_front();
        if(aux->value == value){
            cout << endl;
            return aux;
        }
        if(aux->right != NULL){
            fila.push_front(aux->right);
        }
        if(aux->left != NULL){
            fila.push_front(aux->left);
        }
    }
    cout << endl;
    return NULL;
}

BinaryTree::BinNode_t* BinaryTree::bfs(char value) {
    if(root == NULL)
        return NULL;
    //fila do BFS
    list<BinNode_t*> fila;
    BinNode_t *aux;
    //Marca a raiz como visitada
    fila.push_back(root);
    cout << "BFS: ";
    while(!fila.empty()){
        aux = fila.front();
        cout << aux->value << " ";
        fila.pop_front();
        if(aux->value == value){
            cout << endl;
            return aux;
        }
        if(aux->left != NULL){
            fila.push_back(aux->left);
        }
        if(aux->right != NULL){
            fila.push_back(aux->right);
        }
    }
    cout << endl;
    return NULL;
}

BinaryTree::BinNode_t* BinaryTree::print_father(char son, BinNode_t *node) {
    if(node == NULL)
        return NULL;
    if(node->left != NULL && node->left->value == son){
        cout << "O pai de " << son << " eh " << node->value << endl;
        return node;
    }
    else if(node->right != NULL && node->right->value == son){
        cout << "O pai de " << son << " eh "<< node->value << endl;
        return node;
    }else{
        BinNode_t* aux1 = print_father(son, node->left);
        BinNode_t* aux2 = print_father(son, node->right);
        if(aux1 != NULL)
            return aux1;
        if(aux2 == NULL)
            return aux2;
        return NULL;
    }
}

void BinaryTree::print_brothers(char value, BinNode_t *node) {
    if(node == NULL)
        return;
    if(node->left != NULL && node->left->value == value){
        if(node->right != NULL)
            cout << "O irmao de " << value << " eh " << node->right->value << endl;
        else
            cout << value << " nao possui irmao" << endl;
    }
    else if(node->right != NULL && node->right->value == value){
        cout << node->value << endl;
        if(node->left != NULL)
            cout << "O irmao de " << value << " eh " << node->left->value << endl;
        else
            cout << value << " nao possui irmao" << endl;
    }else{
        print_brothers(value, node->left);
        print_brothers(value, node->right);
    }
}

void BinaryTree::print_ancestors(char value) {
    //BinNode_t *aux;
    while(value != root->value){
        BinNode_t* p = print_father(value, root);
        value = p->value;
    }
}

void BinaryTree::print_descendents_n(BinNode_t *father) {
    if(father == NULL)
        cout << "Fim descendentes!" << endl;
    if(father->left != NULL){
        cout << father->left->value << " ";
        print_descendents_n(father->left);
    }
    if(father->right != NULL){
        cout << father->right->value << " ";
        print_descendents_n(father->right);
    }
}

void BinaryTree::print_descendents(char father){
    print_descendents_n(bfs(father));
}

void BinaryTree::print_uncles(BinNode_t *me) {
    char v_father = print_father(me->value, root)->value;
    print_brothers(v_father, root);
}

BinaryTree::~BinaryTree() {
}
