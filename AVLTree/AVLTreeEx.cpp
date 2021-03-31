//#include <iostream>
//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//struct node {
//    int value, height;
//    node* ll, * rr, * pp;
//    node (int x = 0) {
//        ll = rr = pp = 0;
//        value = x;
//        height = 0;
//    }
//};
//node* root = 0;
////Tri tuyet doi hay so tru nhau
//int abs(int a, int b) {
//    return a > b ? a - b : b - a;
//}
//
////Đệ quy lấy chiều cao
//int height(node* a, bool force = false) {
//    if (a == 0) return 0;
//    if (!force) //Lay height trực tiếp từ 1 nút 
//        if (a->height != 0) return a->height;
//    return a->height = max(
//        height(a->ll) + 1,
//        height(a->rr) + 1
//    );
//}
////Hàm này tính hệ số cân bằng tại 1 nút
//int absdelta(node* a) {
//    if (a == 0) return 0;
//    return abs(height(a->ll), height(a->rr));
//}
////Dat lai height cua cac tien boi cua a, neu khong dat lai thi mot hoi tinh sai height
//void requireHeightToRoot(node* a) {
//    for (;;) {
//        if (a == 0) return;
//        if (a->height == 0) return;
//        a->height = 0;
//        a = a->pp;
//    }
//}
//#define rhtr requireHeightToRoot
//
//void lljoin(node* a, node* b) {
//    if (a) a->pp = b;
//    if (b) 
//        b->ll = a;
//    else root = a; //neu n khong ton thi a thanh rooot luon
//    rhtr(a);
//    rhtr(b);
//}
//
//void rrjoin(node* a, node* b) {
//    if (a) a->pp = b;
//    if (b)
//        b->rr = a;
//    else root = a;
//    rhtr(a);
//    rhtr(b);
//}
//
////Xoay phai
//void llrotate(node* a, node* b) {//Xoay b thành con phải cuả a
//    if (b == 0) {
//        rrjoin(a, b);
//        return;
//    }
//    node* c = b->pp;
//    lljoin(a->rr, b);// gan tat ca con phai cua a vào bên trái của b
//    rrjoin(b, a);// b trở thành con trái của a
//    if (c == 0) { //nếu c là nút rỗng, tức là b là nút gốc
//        rrjoin(a, c);//a thành nút gốc
//    }
//    else {
//        if (c->ll == b) //nếu b chưa là nút gốc
//            lljoin(a, c); //nối a vào bên trái c
//        else
//            rrjoin(a, c);// nếu b nằm bên phải :)))
//    }
//}
//
////Xoay trai
//void rrrotate(node* a, node* b) {
//    if (b == 0) {
//        rrjoin(a, b);
//        return;
//    }
//    node* c = b->pp;
//    rrjoin(a->ll, b);
//    lljoin(b, a);
//    if (c == 0) {
//        rrjoin(a, c);
//    }
//    else {
//        if (c->rr == b)
//            rrjoin(a, c);
//        else
//            lljoin(a, c);
//    }
//}
//
//void balance(node* a) { //root
//    //Cố tìm node có mức cân bằng cao nhất mà tại đó bị phá vỡ
//    if (a == 0) return;
//    if (absdelta(a) <= 1) return;//Nếu hệ số cân bằng <=1 thì không cần can băng nữa
//    balance(a->ll); // Hoi thua, cai nay chi xai khi balance khong thong qua insert
//    balance(a->rr); 
//
//    if (height(a->ll) > height(a->rr)) {
//        if (a->ll == 0) {
//            puts("Fatal");
//            return;
//        }
//        if (height(a->ll->ll) < height(a->ll->rr)) //
//            rrrotate(a->ll->rr, a->ll);
//        llrotate(a->ll, a);
//    }
//    else if (height(a->rr) > height(a->ll)) {
//        if (a->rr == 0) {
//            puts("Fatal\n");
//            return;
//        }
//        if (height(a->rr->rr) < height(a->rr->ll))
//            llrotate(a->rr->ll, a->rr);
//        rrrotate(a->rr, a);
//    }
//}
//
//void show(node* a) {
//    if (a == 0) return;
//    printf("(");
//    show(a->ll);
//    printf(" %d ", a->value);
//    show(a->rr);
//    printf(")");
//}
//
//void doInsert(node* a, node* b) { // a thêm vào b
//    if (b == 0) { //b==root
//        rrjoin(a, b);
//        return;
//    }
//    if (a == 0) { //a không thể là ô rỗng
//        puts("Fatal\n");
//        return;
//    }
//    if (a->value == b->value){ // bằng giá k thể chung giá trị
//        return;
//    }
//    if (a->value < b->value)
//        if (b->ll)
//            doInsert(a, b->ll);
//        else
//            lljoin(a, b);
//    if (a->value > b->value)
//        if (b->rr)
//            doInsert(a, b->rr);
//        else
//            rrjoin(a, b);
//    balance(b);
//}
//
//node* rightMost(node* a) {
//    if (a == 0) return 0;
//    if (a->rr == 0)
//        return a;
//    else
//        return rightMost(a->rr);
//}
//
//node* leftMost(node* a) {
//    if (a == 0) return 0;
//    if (a->ll == 0)
//        return a;
//    else
//        return leftMost(a->ll);
//}
//
//void doDelete(node* a) {
//    if (a == 0) return; //Neu khong ton tai thi khong xoa
//    if (a->ll == 0) { // Neu khong co con trai
//        if (a->pp == 0 || a->pp->ll == a) //Neu no la node goc hoac la con trai cua 1 node khac
//            lljoin(a->rr, a->pp);
//        else
//            rrjoin(a->rr, a->pp);
//        delete a;
//    }
//    else if (a->rr == 0) {
//        if (a->pp == 0 || a->pp->ll == a)
//            lljoin(a->ll, a->pp);
//        else
//            rrjoin(a->ll, a->pp);
//        delete a;
//    }
//    else {
//        node* b = rightMost(a->ll);
//        if (b == 0) {
//            printf("Fatal\n");
//            return;
//        }
//        swap(b->value, a->value);
//        doDelete(b);
//    }
//}
//
//node* doSearch(int x, node* a) {
//    if (a == 0) return 0;
//    if (x == a->value) return a;
//    if (x < a->value) return doSearch(x, a->ll);
//    if (x > a->value) return doSearch(x, a->rr);
//}
//
//node* doLowerBound(int x, node* a) {
//    if (a == 0) return 0;
//    if (a->value >= x) {
//        node* b = doLowerBound(x, a->ll);
//        if (b != 0)
//            return b;
//        else
//            return a;
//    }
//    else
//        return doLowerBound(x, a->rr);
//}
//
//node* doUpperBound(int x, node* a) {
//    if (a == 0) return 0;
//    if (a->value > x) {
//        node* b = doUpperBound(x, a->ll);
//        if (b != 0)
//            return b;
//        else
//            return a;
//    }
//    else
//        return doUpperBound(x, a->rr);
//}
//
//node* doSucc(node* a) {
//    if (a == 0) return 0;
//    if (a->rr) return leftMost(a->rr);
//    for (;;) {
//        if (a->pp == 0)
//            return 0;
//        else if (a->pp->ll == a)
//            return a->pp;
//        else
//            a = a->pp;
//    }
//}
//
//node* doPrev(node* a) {
//    if (a == 0) return rightMost(root);
//    if (a->ll) return rightMost(a->ll);
//    for (;;) {
//        if (a->pp == 0)
//            return 0;
//        else if (a->pp->rr == a)
//            return a->pp;
//        else
//            a = a->pp;
//    }
//}
//
//int get() {
//    int r;
//    scanf_s("%d", &r);
//    return r;
//}
//
//void display(node* a) {
//    if (a == 0)
//        printf("no\n");
//    else
//        printf("%d\n", a->value);
//}
//void NLR(node* root)
//{
//    if (root != NULL)
//    {
//        printf("%d\t", root->value);
//        NLR(root->ll);
//        NLR(root->rr);
//    }
//}
//void LNR(node* root)
//{
//    if (root != NULL)
//    {
//        LNR(root->ll);
//        printf("%d\t", root->value);
//        LNR(root->rr);
//    }
//}
//void LRN(node* root)
//{
//    if (root != NULL)
//    {
//        LNR(root->ll);
//        LNR(root->rr);
//        printf("%d\t", root->value);
//    }
//}
//
//int main() {
//    //root = 0;
//    /*
//    int p;
//    for (;;) {
//        scanf_s("%d", &p);
//        if (p == 0)
//            return 0;
//        else if (p == 1)
//            doInsert(new node(get()), root);
//        else if (p == 2)
//            doDelete(doSearch(get(), root));
//        else if (root == 0)
//            printf("empty\n");
//        else {
//            if (p == 3)
//                printf("%d\n", leftMost(root)->value);
//            else if (p == 4)
//                printf("%d\n", rightMost(root)->value);
//            else if (p == 5)
//                display(doUpperBound(get(), root));
//            else if (p == 6)
//                display(doLowerBound(get(), root));
//            else if (p == 7)
//                display(doPrev(doLowerBound(get(), root)));
//            else if (p == 8)
//                display(doPrev(doUpperBound(get(), root)));
//        }
//    }
//    */
//    for (int i = 1; i <= 8; i++) {
//        doInsert(new node(i), root);
//    }
//    doDelete(doSearch(4, root));
//    doDelete(doSearch(1, root));
//    NLR(root);
//    cout << endl;
//    LNR(root);
//    //Ket luan: Khong can bang sau khi xoa :))
//}
