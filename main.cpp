/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: jhdra
 *
 * Created on 20 de Setembro de 2018, 16:47
 */

#include <iostream>
#include <fstream>
#include "BinaryTree.h"

using namespace std;

/*
 *
 */
int main() {
    BinaryTree bt;
    string line;
    ifstream myfile ("entrada.txt"); // ifstream = padrão ios:in
    if (myfile.is_open())
    {
        while (! myfile.eof() ) //enquanto end of file for false continua
        {
            // como foi aberto em modo texto(padrão) e não binário(ios::bin) pega cada linha
            getline (myfile,line);
            cout << line << endl;
            bt.add_node(line);
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    bt.print_father('F', bt.get_root());
    bt.print_brothers('F', bt.get_root());
    bt.print_brothers('I', bt.get_root());
    //bt.print_descendents('A');
    bt.dfs('G');
    bt.bfs('G');
    return 0;
}

