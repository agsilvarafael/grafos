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

//#include <string>

class BinaryTree {
private:
    typedef struct bt{
        char value;
        struct bt *left, *right;
    } BinNode_t;
public:
    BinaryTree();
    virtual ~BinaryTree();
    BinNode_t* dfs(char value);//busca em profundidade
    BinNode_t* bfs(char value);//busca em largura
    void print_descendents(char father);//imprime os descendentes do nó
    void print_father(char son);//imprime o pai do nó
    void print_uncles(char value);//imprime os tios do nó
    void print_brothers(char value);//imprime o pai do nó
    void print_ancestors(char value);//imprime os ancestrais do nó
    bool add_node(std::string input);//
    BinNode_t* get_root();
private:
    BinNode_t* root;
    BinNode_t* createNode(char value);
};

#endif /* BINARYTREE_H */

