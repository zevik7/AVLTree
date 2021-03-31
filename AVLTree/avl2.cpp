//#include <iostream>
//#include <algorithm>
//#include <math.h>
//using namespace std;
//typedef struct node
//{
//	int value;
//	int height;
//	node* left;
//	node* right;
//	node (int x = 0)
//	{
//		left = right = NULL;
//		value = x;
//		height = 1;
//	}
//};
//typedef node *tree;	/*Typedef khong tao ra vung nho moi, no chi refer den kieu du lieu do node = node*
//					Thuc ra la de cho de nhin chu K co cai db con tro tham chieu gi ca  -_-*/
//
//// Cac ham tinh toan can thiet
//int max(int a, int b); // Tra ve so lon nhat trong 2 so
//int height(tree a);	// Tinh chieu cao mot cay
//int cal_balance(tree a); // Tinh he so can bang 
//tree search(tree a, int x); // Ham tim kiem
//
//// Khai bao cac ham can thiet
//void init_tree(tree& tree);	// Khoi tao cay
//void right_rotate(tree& a);	// Quay phai
//void left_rotate(tree& a);	// Quay trai
//void insert_node(tree& a, int x);// Them node co value x vao cay
//void del_node(tree& root, int x); // Ham xoa node
//
//// Cac ham duyet cay
//void NLR(tree root);
//void LNR(tree root);
//void LRN(tree root);
//
//// Xay dung cac ham	
//int max(int a, int b) {
//	return a > b ? a : b;
//}
//
//int height(tree a) {
//	if (a == NULL) return 0;
//	return a->height;
//}
//
//int cal_balance(tree a) {
//	if (a == NULL) return 0;
//	return height(a->left) - height(a->right);
//}
//
//tree search(tree a, int x) {
//	if (a == NULL) return 0;
//	if (x == a->value) return a;
//	if (x < a->value) return search(a->left, x);
//	if (x > a->value) return search(a->right, x);
//}
//
//void init_tree(tree& root) {
//	root = NULL;
//}
//
//void right_rotate(tree& a) {//Quay phai tai a
//	if (a == NULL) return;
//	if (a->left == NULL) return;
//	tree leftChild = a->left; // Tao mot tham chieu leftChild
//	a->left = leftChild->right;
//	leftChild->right = a;
//	//Cap nhat lai chieu cao
//	a->height = max(height(a->left), height(a->right)) + 1;
//	leftChild->height = max(height(leftChild->left), height(leftChild->right)) + 1;
//	//Cap nhat leftChild, vi ban chat cha cua a van tro den a nen chi co the cap nhat lai a hoac dia chi cua a;
//	a = leftChild;
//}
//
//void left_rotate(tree& a) {//Quay trai tai a
//	if (a == NULL) return;
//	if (a->right == NULL) return;
//	tree rightChild = a->right; // Tao mot tham chieu rightChild
//	a->right = rightChild->left;
//	rightChild->left = a;
//	//Cap nhat lai chieu cao
//	a->height = max(height(a->left), height(a->right)) + 1;
//	rightChild->height = max(height(rightChild->left), height(rightChild->right)) + 1;
//	//Cap nhat rightChild, vi ban chat tien boi cua a van tro den a nen chi co the cap nhat lai a hoac dia chi cua a;
//	a = rightChild;
//}
//
//void insert_node(tree& a, int x) {
//	if (a == NULL) {
//		a = new node(x);
//		return;
//	}
//	if (a->value == x) return;
//	//So sanh x va gia tri node hien tai
//	if (x < a->value) insert_node(a->left, x);
//	else insert_node(a->right, x);
//	//Tinh lai chieu cao cua node hien tai sao khi chen
//	a->height = max(height(a->left), height(a->right)) + 1;
//	//Can bang node hien tai dang chen
//	int balanceValue = cal_balance(a);
//
//	if (balanceValue > 1 and x < a->left->value)
//	{
//		//Lech trai trai
//		right_rotate(a);
//	}
//	else if (balanceValue > 1 && x > a->left->value)
//	{
//		//Lech trai phai
//		left_rotate(a->left);
//		right_rotate(a);
//	}
//	if (balanceValue < -1 && x > a->right->value) 
//	{
//		//Lech phai phai
//		left_rotate(a);
//	}
//	else if (balanceValue < -1 && x < a->right->value)
//	{
//		//Lech phai trai   
//		right_rotate(a->right);
//		left_rotate(a);
//	}
//	
//}
//void replacement_node(tree& root, tree& rightChild) {
//	if (rightChild->left != NULL)
//	{
//		replacement_node(root, rightChild->left);// tìm ra node trái nhất ?
//	}
//	else 
//	{
//		root->value = rightChild->value; // cập nhật cái data của node cần xóa chính là data của node thế mạng
//		root = rightChild; // cho node X(là node mà chúng ta sẽ đi xóa sau này) trỏ đến node thế mạng ==> ra khỏi hàm thì ta sẽ xóa node X
//		rightChild = rightChild->right; // bản chất chỗ này chính là cập nhật lại mối liên kết cho node cha của node thế mạng(mà chúng ta sẽ xóa) với node con của node thế mạng  
//	}
//}
//void del_node(tree& root, int x) {
//	if (root == NULL) return;
//	if (root->value > x) del_node(root->left, x); //logn
//	else if (root->value < x) del_node(root->right, x);
//	else {
//		//Da tim duoc node can xoa
//		node *deleteNode = root;
//		if (root->left == NULL){
//			root = root->right;
//		}
//		else if (root->right == NULL){
//			root = root->left;
//		}
//		else {
//			replacement_node(deleteNode, root->right);//logn
//		}
//		delete deleteNode;
//	}
//	int balanceValue = cal_balance(root);
//	if (balanceValue > 1 && cal_balance(root->left) >= 0)
//	{
//		//Lech trai trai
//		right_rotate(root);
//	}
//	else if (balanceValue > 1 && cal_balance(root->left) < 0)
//	{
//		//Lech trai phai
//		left_rotate(root->left);
//		right_rotate(root);
//	}
//	if (balanceValue < -1 && cal_balance(root->right) <=0)
//	{
//		//Lech phai phai
//		left_rotate(root);
//	}
//	else if (balanceValue < -1 && cal_balance(root->right) > 0)
//	{
//		//Lech phai trai   
//		right_rotate(root->right);
//		left_rotate(root);
//	}
//}
//
//void NLR(tree root)
//{
//	if (root != NULL)
//	{
//		printf("%d\t", root->value);
//		NLR(root->left);
//		NLR(root->right);
//	}
//}
//void LNR(tree root)
//{
//	if (root != NULL)
//	{
//		LNR(root->left);
//		printf("%d\t", root->value);
//		LNR(root->right);
//	}
//}
//void LRN(tree root)
//{
//	if (root != NULL)
//	{
//		LNR(root->left);
//		LNR(root->right);
//		printf("%d\t", root->value);
//	}
//}
//int main() {
//	tree root = NULL;
//	for (int i = 1; i <= 9; i++) {
//		insert_node(root, i);
//	}
//	NLR(root);
//	del_node(root, 5);
//	del_node(root, 2);
//	cout << endl;
//	NLR(root);
//}