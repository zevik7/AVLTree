#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
class Node
{
    private:

    public:
        //Thuoc tinh co ban
        int value;
        int height;
        Node *left, *right;
        //Phuong thuc khoi tao
        Node();

        //Thuoc tinh cho giao dien
        sf::CircleShape circle;
        sf::VertexArray linestrip;
        sf::Text text;
        sf::Font font;
};