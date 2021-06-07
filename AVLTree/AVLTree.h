#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
class AVLTree
{
private:
    Node* root;
public:
    //Phuong thuc khoi tao
    AVLTree();
    ~AVLTree();
    //Thao tac voi node goc
    Node* getroot();
    void setroot(Node*);
    //Tinh chieu cao va he so can bang
    int calHeight(Node*); 
    int calBalance(Node*); 

    //Tim kiem
    Node* search(int, Node*);
    //Can bang nut
    Node* balanceNode(Node*);

    Node* rightRotation(Node*);
    Node* leftRightRotation(Node*);

    Node* rightLeftRotation(Node*);
    Node* leftRotation(Node*);

    Node* insert(Node*, int);
    Node* delNode(int key, Node*);

    Node* rightMostChild(Node*);
    Node* leftMostChild(Node*);
    
    //Cac phuong thuc de hien thi
    void draw(Node*, sf::RenderWindow&);
    void setCordinate(Node*, int);
    void setbackcolor(Node*, bool&);
    void setspcolor(Node*, bool&, sf::Clock&);
    void resetColor(Node*);
};