#include <iostream>
#include "AVLTree.cpp"
using namespace std;
int main() {
	AVLTree tree;
	for (int i = 1; i <= 9; i++) {
		tree.insert(i);
	}
	tree.delNode(5);
	tree.NLR();
	cout << endl;
	tree.LNR();
	cout << endl;
	tree.LRN();
	cout << endl;
	cout << tree.getHeight();
	return 0;
}