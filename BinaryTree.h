/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryTree.h
 * Author: jhdra
 *
 * Created on 20 de Setembro de 2018, 16:48
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree {
public:
    BinaryTree();
    BinaryTree(char root_v);
    virtual ~BinaryTree();
    BinNode_t* dfs(char value, BinNode_t* arvore);//busca em profundidade
    BinNode_t* bfs(char value);//busca em largura
    void print_descendents(BinNode_t *father);//imprime o filho do nó
    BinNode_t* print_father(char son, BinNode_t *node);//imprime o pai do nó
    void print_uncles(BinNode_t *me);//imprime os tios do nó
    void print_brothers(char value, BinNode_t *nodo);//imprime o pai do nó
    void print_ancestors(char value);//imprime os ancestrais do nó
    bool add_node(char father, char son_left, char son_right);//
    BinNode_t* get_root();
private:
    typedef struct bt{
        char value;
        struct bt *left, *right;
    }BinNode_t;
    BinNode_t *root;
    BinNode_t* createNode();
    int cont_nodes = 0;
};

#endif /* BINARYTREE_H */

