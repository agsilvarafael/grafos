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
#include <stddef.h>
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
        if(aux->left != NULL){
            fila.push_front(aux->left);
        }
        if(aux->right != NULL){
            fila.push_front(aux->right);
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

void BinaryTree::print_father(char value) {
    if(root == NULL)
        return ;
    if(root->value == value)
        cout << value << " nao possui pai" << endl;
    //fila do BFS
    list<BinNode_t*> fila;
    BinNode_t *aux;
    //Marca a raiz como visitada
    fila.push_front(root);
    while(!fila.empty()){
        aux = fila.front();
        fila.pop_front();
        if(aux->right != NULL){
            if(aux->right->value == value){
                break;
            }
            fila.push_front(aux->right);
        }
        if(aux->left != NULL){
            if(aux->left->value == value){
                break;
            }
            fila.push_front(aux->left);
        }
    }
    if(fila.empty())
        cout << value << " nao pertence a arvore" << endl;
    else
        cout << "PAI: O pai de " << value << " eh "<< aux->value << endl;
}

void BinaryTree::print_brothers(char value) {
    if(root == NULL)
        return ;
    //fila do BFS
    list<BinNode_t*> fila;
    BinNode_t *aux;
    //Marca a raiz como visitada
    fila.push_front(root);
    cout << "IRMAO: ";
    while(!fila.empty()){
        aux = fila.front();
        fila.pop_front();
        if(aux->right != NULL){
            if(aux->right->value == value){
                break;
            }
            fila.push_front(aux->right);
        }
        if(aux->left != NULL){
            if(aux->left->value == value){
                break;
            }
            fila.push_front(aux->left);
        }
    }
    if(aux->left != NULL && aux->left->value == value && aux->right != NULL){
        cout << "O irmao de " << value << " eh " << aux->right->value << endl;
    }
    else if(aux->right != NULL && aux->right->value == value && aux->left != NULL){
        cout << "O irmao de " << value << " eh " << aux->left->value << endl;
    }
    else{
        cout << value << " nao possui irmao" << endl;
    }
}

void BinaryTree::print_ancestors(char value) {
    cout << "ANTECEDENTES(" << value << "):";
    if(root == NULL)
        return ;
    if(root->value == value)
        cout << ' ' << value << " nao possui antecedentes" << endl;
    //fila do BFS
    list<BinNode_t*> fila, f2;
    BinNode_t *aux;
    //Marca a raiz como visitada
    fila.push_front(root);
    while(!fila.empty()){
        aux = fila.front();
        fila.pop_front();
        f2.push_front(aux);
        if(aux->right != NULL){
            if(aux->right->value == value){
                aux = aux->right;
                break;
            }
            fila.push_front(aux->right);
        }
        if(aux->left != NULL){
            if(aux->left->value == value){
                aux = aux->left;
                break;
            }
            fila.push_front(aux->left);
        }
    }
    while(!f2.empty()){
        if( (f2.front()->left != NULL && f2.front()->left == aux) ||
            (f2.front()->right != NULL && f2.front()->right == aux)
        ){
            cout << ' ' << f2.front()->value;
            aux = f2.front();
        }
        f2.pop_front();
    }
    cout << endl;
}


void BinaryTree::print_descendents(char value){
    if(root == NULL)
        cout << "Árvore invélida" << endl;
    //Controle de impressão
    bool print = false;
    //fila do BFS
    list<BinNode_t*> fila;
    BinNode_t *aux;
    //Marca a raiz como visitada
    fila.push_back(root);
    cout << "Descendentes: ";
    while(!fila.empty()){
        aux = fila.front();
        fila.pop_front();
        if(print){
            cout << aux->value << " ";
        }
        else if(aux->value == value){
            print = true;
        }
        if(aux->left != NULL){
            fila.push_back(aux->left);
        }
        if(aux->right != NULL){
            fila.push_back(aux->right);
        }
    }
    cout << endl;
}

void BinaryTree::print_uncles(char value) {
    cout << "TIO: ";
    if(root == NULL)
        return ;
    if(root->value == value)
        cout << value << " nao possui antecedentes" << endl;
    //fila do BFS
    list<BinNode_t*> fila;
    BinNode_t *aux;
    //Marca a raiz como visitada
    fila.push_front(root);
    while(!fila.empty()){
        aux = fila.front();
        if(aux->value == value)
            break;
        if(aux->right != NULL){
            if(aux->right->value == value){
                break;
            }
            fila.push_front(aux->right);
        }
        if(aux->left != NULL){
            if(aux->left->value == value){
                break;
            }
            fila.push_front(aux->left);
        }
    }
    if(fila.empty()){
        cout << value << " nao pertence a arvore" << endl;
    }else{
        while(!fila.empty()){
            if(fila.front()->left != NULL && fila.front()->left == aux){
                cout << "O tio de " << value << " eh "<<
                    fila.front()->right->value << endl;
                return;
            }
            if(fila.front()->right != NULL && fila.front()->right == aux){
                cout << "O tio de " << value << " eh "<<
                    fila.front()->right->value << endl;
                return;
            }
            fila.pop_front();
        }
        cout << value << " nao possui tio " << endl;
    }
}

BinaryTree::~BinaryTree() {
    //TODO destruir árvore
}
