#include<iostream>
using namespace std;
class Node {
public:
	int value;
	int height;
	Node* left;
	Node * right;
	Node(int valueInit = 0){
		left = right = NULL;
		value = valueInit;
		height = 0;
	}
};