#include<stdio.h>
#include<stdlib.h>

// ノード構造体の定義
struct node {
    struct node *right;  // 右の子ノード
    struct node *left;   // 左の子ノード
    struct node *parent; // 親ノード
    int key;             // ノードのキー
};

typedef struct node * Node;

#define NIL NULL  // ノードが存在しないことを示す定数

Node root;  // ツリーの根ノード

// 部分木の中で最も小さいキーを持つノードを探す関数
Node treeMinimum(Node x) {
    while (x->left != NIL) {
        x = x->left;
    }
    return x;
}

// 最も大きいキーを持つノードを探す関数
Node treeMaximum(Node x) {
    while (x->right != NIL) {
        x = x->right;
    }
    return x;
}

// 与えられたキーkを持つノードを探す関数
Node treeSearch(Node u, int k) {
    if (u == NIL || k == u->key) return u;
    if (k < u->key) return treeSearch(u->left, k);  // kが小さい場合は左の子ノードを探索
    else return treeSearch(u->right, k);  // kが大きい場合は右の子ノードを探索
}

// 後継ノードを探す関数
Node treeSuccessor(Node x) {
    if (x->right != NIL) return treeMinimum(x->right);  // 右部分木の最小ノード
    Node y = x->parent;
    while (y != NIL && x == y->right) {  // 親ノードを辿っていく
        x = y;
        y = y->parent;
    }
    return y;
}

// 指定されたノードzを削除する関数
void treeDelate(Node z) {
    Node y;  // 削除されるノード
    Node x;  // 削除されるノードの子ノード
    if (z->left == NIL || z->right == NIL) y = z;  // zが子ノードを持たない場合
    else y = treeSuccessor(z);  // zの後継ノード
    if (y->left != NIL) x = y->left;  // yが左の子を持つ場合
    else x = y->right;  // 持たない場合
    if (x != NIL) x->parent = y->parent;  // xが存在する場合、yの親ノードをxの親ノードに設定
    if (y->parent == NIL) root = x;  // yが根ノードの場合、xを根ノードに設定
    else if (y == y->parent->left) y->parent->left = x;  // yが左の子だった場合
    else y->parent->right = x;  // yが右の子だった場合
    if (y != z) z->key = y->key;  // yとzが異なる場合、yのキーをzにコピー
    free(y);  // yのメモリを解放
}

// キーkを持つノードを挿入する関数
void insert(int k) {
    Node y = NIL;
    Node x = root;
    Node z;

    z = malloc(sizeof(struct node));  // 新しいノードのメモリを確保
    z->key = k;
    z->left = NIL;
    z->right = NIL;

    while (x != NIL) {
        y = x;
        if (z->key < x->key) x = x->left;
        else x = x->right;
    }

    z->parent = y;
    if (y == NIL) root = z;  // ツリーが空の場合、新しいノードを根ノードに設定
    else if (z->key < y->key) y->left = z;
    else y->right = z;
}

// 中間順巡回し、ノードのキーを出力する関数
void inorder(Node u, int *first) {
    if (u != NIL) {
        inorder(u->left, first);
        if (*first) {
            printf(" %d", u->key);
            *first = 0;
        } else {
            printf(" %d", u->key);
        }
        inorder(u->right, first);
    }
}

// 先行順巡回し、ノードのキーを出力する関数
void preorder(Node u, int *first) {
    if (u != NIL) {
        if (*first) {
            printf(" %d", u->key);
            *first = 0;
        } else {
            printf(" %d", u->key);
        }
        preorder(u->left, first);
        preorder(u->right, first);
    }
}

int main() {
    int n, i, x;
    char com[20];
    scanf("%d", &n);  // コマンドの数を入力

    for (int i = 0; i < n; i++) {
        scanf("%s", com);  // コマンドを入力
        if (com[0] == 'f') {
            scanf("%d", &x);
            Node t = treeSearch(root, x);  // キーxを持つノードを検索
            if (t != NIL) printf("yes\n");
            else printf("no\n");
        } else if (com[0] == 'i') {
            scanf("%d", &x);
            insert(x);  // キーxを持つノードを挿入
        } else if (com[0] == 'p') {
            int first = 1;
            inorder(root, &first);  // 中間順巡回でキーを出力
            printf("\n");
            first = 1;
            preorder(root, &first);  // 先行順巡回でキーを出力
            printf("\n");
        } else if (com[0] == 'd') {
            scanf("%d", &x);
            treeDelate(treeSearch(root, x));  // キーxを持つノードを削除
        } else {
            printf("It is not correct code\n");
        }
    }

    return 0;
}