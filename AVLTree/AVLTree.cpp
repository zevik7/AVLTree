#include <iostream>
#include "AVLTree.h"
using namespace std;

//Ham khoi tao
AVLTree::AVLTree()
{
    root = NULL;
}
//Ham huy
AVLTree::~AVLTree()
{

}
int AVLTree::calHeight(Node* q)
{
    if (q == NULL) return 0;
    int heightLeftChild = q->left ? q->left->height : 0;
    int heightRightChild = q->right ? q->right->height : 0;

    return (heightRightChild > heightLeftChild ? heightRightChild: heightLeftChild) + 1;
}

int AVLTree::calBalance(Node* q)
{
    if (q == NULL) return 0;
    int heightLeftChild = q->left ? q->left->height : 0;
    int heightRightChild = q->right ? q->right->height : 0;

    return (heightLeftChild - heightRightChild);
}

void AVLTree::resetColor(Node* a) {
    if (a != NULL)
    {
        a->circle.setFillColor(sf::Color::Green);
        resetColor(a->left);
        resetColor(a->right);
    }
}
Node* AVLTree::search(int key, Node* q)
{
    if (q == NULL) NULL;
    else if (q->value == key) return q;
    else if (key < q->value)
    {
        q->circle.setFillColor(sf::Color::Yellow);
        return search(key, q->left);
    }
    else if (key > q->value)
    {
        q->circle.setFillColor(sf::Color::Yellow);
        return search(key, q->right);
    }
}
Node* AVLTree::balanceNode(Node* a) {
    int balanceValue = calBalance(a);
    if (balanceValue > 1)
    {
        if (calBalance(a->left) < 0)
            return leftRightRotation(a); //Lech trai phai, xoay trai phai
        return rightRotation(a);// Lech trai phai, chi can xoay phai
    }
    if (balanceValue < -1)
    {
        if (calBalance(a->right) > 0)
            return rightLeftRotation(a);
        return leftRotation(a);
    }
    return a;
}
Node* AVLTree::insert(Node* a, int key)
{
    Node* addNode = NULL;
    if (a == NULL)
    {
        addNode = new Node();
        addNode->value = key;
        return addNode;
    }
    if (a->value < key)
    {
        a->right = insert(a->right, key);
    }
    else if (a->value > key)
    {
        a->left = insert(a->left, key);
    }
    a->height = calHeight(a);
    balanceNode(a);
}
Node* AVLTree::delNode(int x, Node* a) {
    Node* p;
    if (a == NULL) return NULL;
    if (!a->left && !a->right && a->value == x) //Neu tim thay
    {
        if (a == root)
            root = NULL;
        delete a;
        return NULL;
    }
    if (x < a->value)
        a->left = delNode(x, a->left);
    else if (x > a->value)
        a->right = delNode(x, a->right);
    else
    {
        //doi cho voi con trai nhat hoac phai nhat de xoa
        if (calHeight(a->left) > calHeight(a->right))
        {
            p = rightMostChild(a->left);
            a->value = p->value;
            a->left = delNode(p->value, a->left);
        }
        else
        {
            p = leftMostChild(a->right);
            a->value = p->value;
            a->right = delNode(p->value, a->right);
        }
    }
    if (!a) return a;
    a->height = calHeight(a);
    balanceNode(a);
}
Node* AVLTree::rightRotation(Node* a) // Xoay phai khi lech trai trai
{
    //Luu con trai cua a
    Node* al = a->left;
    //Luu con phai cua con trai (Neu co)
    Node* alr = al->right;
    //Con trai cua a se luu con phai cua con trai (Neu co)
    a->left = alr;
    al->right = a;

    //Tinh lai chieu cao
    a->height = calHeight(a);
    al->height = calHeight(al);
    //Neu a la root thi phai gan lai root
    if (a == root) root = al;
    return al;
}

Node* AVLTree::leftRightRotation(Node* a)
{
    //Con trai
    Node* al = a->left;
    //Con phai cua con trai
    Node* alr = al->right;

    //Con phai al tro den con trai alr
    al->right = alr->left;
    a->left = alr->right;

    //Xong xoay 
    alr->left = al;
    alr->right = a;

    //Cap nhat chieu cao
    a->height = calHeight(a);
    al->height = calHeight(al);
    alr->height = calHeight(alr);
    if (a == root) root = alr;
    return alr;
}

Node* AVLTree::rightLeftRotation(Node* a)
{
    Node* ar = a->right;
    Node* arl = ar->left;
    ar->left = arl->right;
    a->right = arl->left;
    arl->right = ar;
    arl->left = a;
    a->height = calHeight(a);
    ar->height = calHeight(ar);
    arl->height = calHeight(arl);
    if (a == root) root = arl;
    return arl;
}

Node* AVLTree::leftRotation(Node* a) //Xoay trai khi lech phai
{
    //Luu con phai
    Node* ar = a->right; 
    //Luu con trai cua con phai (Neu co)
    Node* arl = ar->left; 
    //Con trai cua a se luu con phai cua con trai (Neu co)
    a->right = arl;
    ar->left = a;
    //Tinh lai chieu cao
    a->height = calHeight(a);
    ar->height = calHeight(ar);
    //Neu la root thi phai cap nhat lai
    if (a == root) root = ar;
    return ar;
}

Node* AVLTree::getroot()
{
    return root;
}

void AVLTree::setroot(Node* q)
{
    root = q;
}
Node* AVLTree::rightMostChild(Node* p)
{
    while (p && p->right)
        p = p->right;
    return p;
}
Node* AVLTree::leftMostChild(Node* p)
{
    while (p && p->left)
        p = p->left;
    return p;
}

void AVLTree::draw(Node* q, sf::RenderWindow& window)
{
    if (q)
    {
        window.draw(q->linestrip);
        window.draw(q->circle);
        window.draw(q->text);

        draw(q->left, window);

        draw(q->right, window);

    }
}
//Toa do
void AVLTree::setCordinate(Node* q, int dist)
{
    if (q)
    {
        if (q == root)
        {
            q->circle.setPosition(400, 140);
            q->text.setPosition(400 + 18, 140 + 20);
            q->text.setString(to_string(q->value));
        }

        for (int j = 0; j < 3; j++)
        {
            q->linestrip[j].position = (sf::Vector2f(q->circle.getPosition().x + q->circle.getRadius(), q->circle.getPosition().y + q->circle.getRadius()));
            q->linestrip[j].color = sf::Color::Black;
        }

        if (q->left)
        {
            (q->left)->circle.setPosition(sf::Vector2f(q->circle.getPosition().x - dist, q->circle.getPosition().y + 100));
            (q->left)->text.setPosition(sf::Vector2f(q->circle.getPosition().x - dist + 18, q->circle.getPosition().y + 100 + 20));
            q->left->text.setString(to_string(q->left->value));

            q->linestrip[0].position = (sf::Vector2f(q->left->circle.getPosition().x + q->left->circle.getRadius(), q->left->circle.getPosition().y + q->left->circle.getRadius()));
            q->linestrip[0].color = sf::Color::Black;
            setCordinate(q->left, dist / 2);
        }


        if (q->right)
        {
            (q->right)->circle.setPosition(sf::Vector2f(q->circle.getPosition().x + dist, q->circle.getPosition().y + 100));
            (q->right)->text.setPosition(sf::Vector2f(q->circle.getPosition().x + dist + 18, q->circle.getPosition().y + 100 + 20));
            q->right->text.setString(to_string(q->right->value));

            q->linestrip[2].position = (sf::Vector2f(q->right->circle.getPosition().x + q->right->circle.getRadius(), q->right->circle.getPosition().y + q->right->circle.getRadius()));
            q->linestrip[2].color = sf::Color::Black;
            setCordinate(q->right, dist / 2);
        }
    }
}
//Mau vang sau khi tim kiem
void AVLTree::setspcolor(Node* t, bool& value, sf::Clock& clock)
{
    if (t && value == false)
    {
        t->circle.setFillColor(sf::Color::Yellow);
        value = true;
        clock.restart();
    }
}
//Thiet lap lai mau sau khi da tim kiem
void AVLTree::setbackcolor(Node* t, bool& value)
{
    t->circle.setFillColor(sf::Color::Green);
    value = false;
}