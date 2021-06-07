#include<iostream>
#include "Node.h"
using namespace std;
Node::Node()
{
	//Gia tri khoi tao thuoc tinh
	height = 1;
	left = NULL;
	right = NULL;

	//Gia tri mac dinh cho giao dien
	circle.setFillColor(sf::Color::Green);
	circle.setRadius(32.0f);
	circle.setPosition(sf::Vector2f(200.0f, 200.0f));

	font.loadFromFile("Assets/unispace.ttf");

	text.setFont(font);
	text.setFillColor(sf::Color::Blue);
	text.setCharacterSize(18);

	linestrip.setPrimitiveType(sf::LinesStrip);
	linestrip.resize(3);
	linestrip;
}