#include <iostream>
#include <algorithm>
#include "Node.cpp"
using namespace std;
class AVLTree {
private:
	Node* root;
public:
	AVLTree(){
		root = NULL;
	}
	// Phuong thuc lay chieu cao not hoac cay
	int getHeight(Node* a) {
		if (a == NULL) return -1;
		return a->height;
	}
	int getHeight() {
		return root->height;
	}
	// Tinh lai chieu cao cua mot not
	int calHeight(Node* a) {
		return max(getHeight(a->left), getHeight(a->right)) + 1;
	}
	// Tinh he so can bang tai mot not
	int calBalance(Node* a) {
		if (a == NULL) return 0;
		// Neu 2 node con la null thi height la -1 (-1-1=-2) co the gay sai nen phai tang 1 don vi
		return (getHeight(a->left) + 1) - (getHeight(a->right) + 1);
	}
	int calBalance() {
		if (root == NULL) return 0;
		return (getHeight(root->left) + 1) - (getHeight(root->right) + 1);
	}
	// Tim mot not co gia tri x trong root
	Node* search(Node* searchingNode, int x) {
		if (root == NULL) return 0;
		if (root->value == x) return root;
		if (x < root->value) 
			return search(root->left, x);
		if (x > root->value) 
			return search(root->right, x);
	}
	Node* search(int x) {
		return search(root, x);
	}
	void rightRotate(Node* &a) { //Xoay phai  tai a khi lech trai
		if (a == NULL) return;
		if (a->left == NULL) return;
		Node* leftRoot = a->left; // Bien tam luu Node can doi voi root
		a->left = leftRoot->right; // Con trai cua root se thanh con phai cua Node can doi
		leftRoot->right = a; //Root se thanh con phai->cua con trai Root
		//Cap nhat lai chieu cao
		a->height = calHeight(a);
		leftRoot->height = calHeight(leftRoot);
		//Cap nhat lai leftRoot, vi ban chat to tien cua root van tro den root
		a = leftRoot;
	}
	void leftRotate(Node* &a) { //Xoay trai khi lech phai
		if (a == NULL) return;
		if (a->right == NULL) return;
		Node* rightRoot = a->right; // Bien tam luu Node can doi voi root
		a->right = rightRoot->left; // Con phai cua root se thanh con trai cua Node can doi
		rightRoot->left = a; //Root se thanh con trai cua con trai Root
		//Cap nhat lai chieu cao
		a->height = calHeight(a);
		rightRoot->height = calHeight(rightRoot);
		//Cap nhat lai rightRoot, vi ban chat to tien cua root van tro den root
		a = rightRoot;
	}
	// Can bang tai not a
	void balanceNode(Node* &a) {
		int balanceValue = calBalance(a);
		if (balanceValue > 1)
		{
			if (calBalance(a->left) < 0)
				leftRotate(a->left); //Lech trai trai ,xoay trai truoc khi xoay phai
			rightRotate(a);
		}
		if (balanceValue < -1)
		{
			if (calBalance(a->right) > 0)
				rightRotate(a->right);
			leftRotate(a);
		}
	}
	void insert(Node* &insertNode, int x) {
		if (insertNode == NULL) {
			insertNode = new Node(x);
			return;
		}
		if (insertNode->value == x) return;
		//So sanh x va gia tri node hien tai
		if (x < insertNode->value)
			insert(insertNode->left, x);
		else
			insert(insertNode->right, x);
		//Tinh lai chieu cao cua node hien tai sao khi chen
		insertNode->height = calHeight(insertNode);
		//Can bang lai node sao khi chen
		balanceNode(insertNode);
	}
	void insert(int x) {
		insert(root, x);
	}
	void replacementNode(Node* &root,Node* &rightChild) {
		if (rightChild->left != NULL)
		{
			replacementNode(root, rightChild->left);// tim ra node trai nhat
		}
		else {
			root->value = rightChild->value;
			root = rightChild;
			//Con trai nhat chi co con phai nen thay the no bang con phai
			rightChild = rightChild->right;
		}
	}
	void delNode(Node* &a, int x) {
		if (a == NULL) return;
		if (a->value > x) delNode(a->left, x); //logn
		else if (a->value < x) delNode(a->right, x);
		else {
			//Da tim duoc node can xoa
			Node* deleteNode = a;
			// TH1 : Nut co 1 con
			if (a->left == NULL) {
				a = a->right;
			}
			else if (a->right == NULL) {
				a = a->left;
			}
			// TH2: Nut co 2 con
			else {
				replacementNode(deleteNode, a->right);//logn
			}
			delete deleteNode;
		}
		balanceNode(a);
	}
	void delNode(int x) {
		delNode(root, x);
	}

	void NLR(Node* root)
	{
		if (root != NULL)
		{
			cout << root->value << "	";
			NLR(root->left);
			NLR(root->right);
		}
	}
	void LNR(Node* root)
	{
		if (root != NULL)
		{
			LNR(root->left);
			cout << root->value << "	";
			LNR(root->right);
		}
	}
	void LRN(Node* root)
	{
		if (root != NULL)
		{
			LNR(root->left);
			LNR(root->right);
			cout << root->value << "	";
		}
	}
	void NLR() { 
		NLR(root);
	}
	void LNR() {
		LNR(root);
	}
	void LRN() {
		LRN(root);
	}
};