//#include<stdio.h>
//#include<malloc.h>
//#include<conio.h>
//typedef struct node
//{
//    int data;
//    int height;
//    node* left;
//    node* right;
//};
//typedef node* tree_avl;
//
////function
//void init(tree_avl& root);    //ham khoi tao cay
//int max(int a, int b);
//int height(tree_avl root);    // tinh chieu cao cua root
//node* getnode(int x);    // tao node
//void right_rotate(tree_avl& root);    //quay phai
//void left_rotate(tree_avl& root);    // quay trai
//int getbalance(tree_avl root);
//void insert_node(tree_avl& root, int x);    // ham tren node
//void create_tree_avl(tree_avl& root, int n);    // ham tao cay avl
//void del_node(tree_avl& root, int x);    // ham xoa node
//int search(tree_avl root, int x);    //ham tim kiem
//void NLR(tree_avl root);
//void LNR(tree_avl root);
//void LRN(tree_avl root);
//void menu();
//int main()
//{
//    menu();
//    return 0;
//}
//void init(tree_avl& root)
//{
//    root = NULL;
//}
//node* getnode(int x)
//{
//    node* p;
//    p = (node*)malloc(sizeof(node));
//    if (p != NULL)
//    {
//        p->data = x;
//        p->height = 1;// chieu cao node la
//        p->left = p->right = NULL;
//        return p;
//    }
//    return NULL;
//}
//int max(int a, int b)
//{
//    return a > b ? a : b;
//}
//int height(tree_avl root)
//{
//    if (root != NULL)
//        return root->height;
//    return 0;
//}
//void NLR(tree_avl root)
//{
//    if (root != NULL)
//    {
//        printf("%d\t", root->data);
//        NLR(root->left);
//        NLR(root->right);
//    }
//}
//void LNR(tree_avl root)
//{
//    if (root != NULL)
//    {
//        LNR(root->left);
//        printf("%d\t", root->data);
//        LNR(root->right);
//    }
//}
//void LRN(tree_avl root)
//{
//    if (root != NULL)
//    {
//        LNR(root->left);
//        LNR(root->right);
//        printf("%d\t", root->data);
//    }
//}
//void right_rotate(tree_avl& root)
//{
//    node* p;
//    p = root->left;
//
//    root->left = p->right;
//    p->right = root;
//    //cap nhat chieu cao
//    root->height = max(height(root->left), height(root->right)) + 1;
//    p->height = max(height(p->left), height(p->right)) + 1;
//    root = p;
//}
//void left_rotate(tree_avl& root)
//{
//    node* p;
//    p = root->right;
//    root->right = p->left;
//    p->left = root;
//    root->height = max(height(root->left), height(root->right)) + 1;
//    p->height = max(height(p->left), height(p->right)) + 1;
//    root = p;
//}
//int getbalance(tree_avl root)
//{
//    if (root != NULL)
//        return height(root->left) - height(root->right);
//    return 0;
//}
//void insert_node(tree_avl& root, int x)
//{
//    int bal;
//    if (root == NULL)
//    {
//        root = getnode(x);
//        //    return root;
//    }
//    else
//    {
//        //neu x nam ben trai 
//        if (x < root->data)
//            insert_node(root->left, x);
//
//        //neu x nam ben phai
//        else
//            insert_node(root->right, x);
//
//        //tinh chieu cao cua root
//        root->height = max(height(root->left), height(root->right)) + 1;
//
//        bal = getbalance(root);
//        // kiem tra can bang cua root
//
//        //neu lech trai trai
//        if (bal > 1 && x < root->left->data)
//            right_rotate(root);
//
//        //neu lech phai phai
//        else if (bal<-1 && x > root->right->data)
//            left_rotate(root);
//
//        //neu lech trai phai
//        else if (bal > 1 && x > root->left->data)
//        {
//            left_rotate(root->left);
//            right_rotate(root);
//        }
//
//        //neu lech phai trai    
//        else if (bal < -1 && x < root->right->data)
//        {
//            right_rotate(root->right);
//            left_rotate(root);
//        }
//    }
//}
//void create_tree_avl(tree_avl& root, int n)
//{
//    int i;
//    int x;
//    for (i = 0; i < n; i++)
//    {
//        printf("Nhap phan tu: ");
//        scanf("%d", &x);
//        insert_node(root, x);
//    }
//
//}
//void del_node(tree_avl& root, int x)
//{
//    node* p1, * p2=NULL, * p3=NULL, * p4=NULL;
//    int bal;
//    //step 1
//    //xoa nut
//    if (root != NULL)
//    {
//        p1 = root;
//        if (root->data == x) // neu la node goc
//        {
//            p2 = p1->left;
//            if (p2->right == NULL) // neu la nut trai lon nhat
//            {
//                root->data = p2->data;
//                p2->right = root->right;
//                //cap nhat lai chieu cao
//                p2->height = max(height(p2->left), height(p2->right)) + 1;
//                free(p1);
//                root = p2;
//
//                //return 1;
//            }
//            else
//            {
//                while (p2->right != NULL) // tim den nut trai lon nhat
//                {
//                    p3 = p2; //p2 la nut cha p2;
//                    p2 = p2->right; //p2 la nut trai lon nhat
//                }
//                root->data = p2->data;
//                p3->right = NULL;
//                p2->left = root->left;
//                p2->right = root->right;
//                //cap nhat lai chieu cao
//                p2->height = max(height(p2->left), height(p2->right)) + 1;
//                free(p1);
//                root = p2;
//                //    return 1;
//            }
//            // quay root
//
//            bal = getbalance(root);
//            //lech trai trai
//            if (bal > 1 && getbalance(root->left) >= 0)
//                right_rotate(root);
//
//            // lech trai phai
//            if (bal > 1 && getbalance(root->left) < 0)
//            {
//                left_rotate(root->left);
//                right_rotate(root);
//            }
//            // lech phai phai
//            if (bal < -1 && getbalance(root->right) <= 0)
//                left_rotate(root);
//            if (bal < 1 && getbalance(root->right)>0)
//            {
//                right_rotate(root->right);
//                left_rotate(root);
//            }
//
//        }
//        else
//        {
//            while (p1 != NULL)
//            {
//                if (p1->data == x)
//                    break;
//                p2 = p1; // p2 la nut truoc p1
//                if (p1->data > x)
//                    p1 = p1->left;
//                else
//                    p1 = p1->right;
//            }
//            if (p1 == NULL)
//            {
//                printf("%d khong co trong cay \n", x);
//                return;
//            }
//            if (p1->left == NULL && p1->right == NULL)
//            {
//                if (x < p2->data)
//                    p2->left = NULL;
//                else
//                    p2->right = NULL;
//                p2->height = max(height(p2->left), height(p2->right)) + 1;
//                free(p1);
//                //    return 1;
//            }
//            if (p1->left != NULL && p1->right == NULL)
//            {
//                if (x < p2->data)
//                    p2->left = p1->left;
//                else
//                    p2->right = p1->left;
//                // cap nhat chieu cao p2
//                p2->height = max(height(p2->left), height(p2->right)) + 1;
//                free(p1);
//                //    return 1;
//            }
//            if (p1->right != NULL && p1->left == NULL)
//            {
//                if (x < p2->data)
//                    p2->left = p1->right;
//                else
//                    p2->right = p1->right;
//                p2->height = max(height(p2->left), height(p2->right)) + 1;
//                free(p1);
//                //    return 1;
//            }
//
//            //quay p2
//            bal = getbalance(p2);
//            //lech trai trai
//            if (bal > 1 && getbalance(p2->left) >= 0)
//                right_rotate(p2);
//
//            // lech trai phai
//            if (bal > 1 && getbalance(p2->left) < 0)
//            {
//                left_rotate(p2->left);
//                right_rotate(p2);
//            }
//            // lech phai phai
//            if (bal < -1 && getbalance(p2->right) <= 0)
//                left_rotate(p2);
//            if (bal < 1 && getbalance(p2->right)>0)
//            {
//                right_rotate(p2->right);
//                left_rotate(p2);
//            }
//
//            // truong hop co 2 con
//            if (p1->left != NULL && p1->right != NULL)
//            {
//                if (x < p2->data)
//                {
//                    p3 = p1->left;
//                    if (p3->right == NULL) // la nut trai lon nhat
//                    {
//                        p1->data = p3->data;
//                        p2->left = p3;
//                        p3->right = p1->right;
//                        // cap nhat chieu cao p3
//                        p3->height = max(height(p3->left), height(p3->right)) + 1;
//                        free(p1);
//                        //        return 1;
//                    }
//                    else
//                    {
//                        while (p3->right != NULL)
//                        {
//                            p4 = p3;
//                            p3 = p3->right;
//                        }
//                        p1->data = p3->data;
//                        p4->right = NULL;
//                        p2->left = p3;
//                        p3->left = p1->left;
//                        p3->right = p1->right;
//                        p3->height = max(height(p3->left), height(p3->right)) + 1;
//                        free(p1);
//                        //        return 1;
//
//                    }
//                }
//                else
//                {
//                    p3 = p1->left;
//                    if (p3->right == NULL)
//                    {
//                        p1->data = p3->data;
//                        p2->right = p3;
//                        p3->right = p1->right;
//                        // cap nhat chieu cao p3
//                        p3->height = max(height(p3->left), height(p3->right)) + 1;
//                        free(p1);
//                        //    return 1;
//                    }
//                    else
//                    {
//                        while (p3->right != NULL)
//                        {
//                            p4 = p3;
//                            p3 = p3->right;
//                        }
//                        p1->data = p3->data;
//                        p4->right = NULL;
//                        p2->right = p3;
//                        p3->left = p1->left;
//                        p3->right = p1->right;
//                        // cap nhat chieu cao
//                        p3->height = max(height(p3->left), height(p3->right)) + 1;
//                        free(p1);
//                        //    return 1;
//                    }
//                }
//                //quay p3
//                bal = getbalance(p3);
//                //lech trai trai
//                if (bal > 1 && getbalance(p3->left) >= 0)
//                    right_rotate(p3);
//
//                // lech trai phai
//                if (bal > 1 && getbalance(p3->left) < 0)
//                {
//                    left_rotate(p3->left);
//                    right_rotate(p3);
//                }
//                // lech phai phai
//                if (bal < -1 && getbalance(p3->right) <= 0)
//                    left_rotate(p3);
//                if (bal < 1 && getbalance(p3->right)>0)
//                {
//                    right_rotate(p3->right);
//                    left_rotate(p3);
//                }
//            }
//        }
//
//    }
//    else
//        return;
//
//}
//int search(tree_avl root, int x)
//{
//    node* p;
//    p = root;
//    if (p != NULL)
//    {
//        while (p != NULL)
//        {
//            if (x < p->data)
//                p = p->left;
//            else if (x > p->data)
//                p = p->right;
//            else
//                return 1;
//        }
//    }
//    return 0;
//}
//void menu()
//{
//
//    int k;
//    tree_avl root= NULL;
//    int n, i, x;
//tt:
//    printf("---------------MENU---------------\n");
//    printf("1. Tao cay avl\n");
//    printf("2. Tim kiem\n");
//    printf("3. Chen\n");
//    printf("4. Xoa\n");
//    printf("5. Duyet NLR\n");
//    printf("6. Duyet LNR\n");
//    printf("7. Duyet LRN\n");
//    printf("8. Thoat\n");
//    printf("\n");
//    printf("Moi ban chon: ");
//    scanf("%d", &k);
//    switch (k)
//    {
//    case 1:
//        init(root);
//        printf("Nhap so phan tu n = ");
//        scanf("%d", &n);
//        create_tree_avl(root, n);
//        _getch();
//        goto tt;
//    case 2:
//        printf("Nhap so can tim x= ");
//        scanf("%d", &x);
//        if (search(root, x))
//            printf("%d co trong cay\n", x);
//        else
//            printf("%d khong co trong cay\n", x);
//        _getch();
//        goto tt;
//    case 3:
//        printf("Nhap so can chen x= ");
//        scanf("%d", &x);
//        insert_node(root, x);
//        printf("Ban da chen thanh cong!\n");
//        _getch();
//        goto tt;
//    case 4:
//        printf("Nhap so can xoa x= ");
//        scanf("%d", &x);
//        del_node(root, x);
//        printf("Ban da xoa thanh cong\n");
//        _getch();
//        goto tt;
//    case 5:
//        printf("Duyet theo NLR\n");
//        NLR(root);
//        _getch();
//        goto tt;
//    case 6:
//        printf("Duyet theo LNR\n");
//        LNR(root);
//        _getch();
//        goto tt;
//    case 7:
//        printf("Duyet theo LRN\n");
//        LRN(root);
//        _getch();
//        goto tt;
//    case 8:
//        break;
//    default:
//        printf("Ban chon ngu vl. Chon lai\n");
//        _getch();
//        goto tt;
//    }
//}