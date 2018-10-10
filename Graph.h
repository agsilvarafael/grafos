/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.h
 * Author: jeronimo
 *
 * Created on 2 de Outubro de 2018, 09:39
 */

#ifndef GRAPH_H
#define GRAPH_H

using namespace std;

class Graph {
public:
    Graph(char s);
    virtual ~Graph();
    void read(string dir_file);
    void relax();
    void bfs(char value);
    void dfs(char value);
    void bellman_ford();
    void dijkstra();
    void floyd_warshall();
private:
    typedef struct{
        char value;
        Lista adjacents();
    }Node_t;
    char start;
    Node_t *nodes[];
    int cont_nodes;
};

#endif /* GRAPH_H */

