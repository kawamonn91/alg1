#include<stdio.h>
#include<stdlib.h>

#define max_node 25  // 最大ノード数の定義
#define ntl -1  // ノードが存在しないことを示す定数

// ノード構造体の定義
typedef struct node {
    int parent;  // 親ノードのID
    int left;    // 左の子ノードのID
    int right;   // 右の子ノードのID
    int depth;   // ノードの深さ
    int height;  // ノードの高さ
} node;

node tree[max_node];  // ノードの配列

// ツリーを初期化する関数
void initializetree() {
    for (int i = 0; i < max_node; i++) {
        tree[i].parent = ntl;
        tree[i].left = ntl;
        tree[i].right = ntl;
        tree[i].depth = 0;
        tree[i].height = 0;
    }
}

// ノードの型を文字列で取得
const char* gettype(int id) {
    if (tree[id].parent == ntl) return "root";  // 親がいない場合は根ノード
    if (tree[id].left == ntl && tree[id].right == ntl) return "leaf";  // 子がいない場合は葉ノード
    return "internal node";  // それ以外は内部ノード
}

// ノードの深さを計算する関数
void calculatedepth(int id, int d) {
    if (id == ntl) return;  // ノードが存在しない場合は終了
    tree[id].depth = d;  // ノードの深さを設定
    calculatedepth(tree[id].left, d + 1);  // 左の子ノードの深さを計算
    calculatedepth(tree[id].right, d + 1);  // 右の子ノードの深さを計算
}

// ノードの高さを計算する関数
int calculateheight(int id) {
    if (id == ntl) return -1;  // ノードが存在しない場合は-1を返す
    int h1 = calculateheight(tree[id].left) + 1;  // 左の子ノードの高さを計算
    int h2 = calculateheight(tree[id].right) + 1;  // 右の子ノードの高さを計算
    return tree[id].height = (h1 > h2) ? h1 : h2;  // 高い方の高さを設定
}

// 子の数を取得する関数
int getdegree(int id) {
    int deg = 0;
    if (tree[id].left != ntl) deg++;  // 左の子ノードが存在する場合はカウント
    if (tree[id].right != ntl) deg++;  // 右の子ノードが存在する場合はカウント
    return deg;
}

// 兄弟の番号を取得する関数
int getsibling(int id) {
    if (tree[id].parent == ntl) return ntl;  // 親がいない場合は兄弟もいない
    int parent = tree[id].parent;
    if (tree[parent].left != id && tree[parent].left != ntl) return tree[parent].left;  // 左の兄弟を返す
    if (tree[parent].right != id && tree[parent].right != ntl) return tree[parent].right;  // 右の兄弟を返す
    return ntl;  // 兄弟がいない場合は-1を返す
}

int main() {
    int n, id, l, r, root = 0;

    // 初期化
    initializetree();

    // 入力
    scanf("%d", &n);  // ノード数を入力
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &id, &l, &r);  // ノードIDと左・右の子ノードIDを入力
        tree[id].left = l;
        tree[id].right = r;
        if (l != ntl) tree[l].parent = id;  // 左の子ノードの親を設定
        if (r != ntl) tree[r].parent = id;  // 右の子ノードの親を設定
    }

    // ルートを特定
    for (int i = 0; i < n; i++) {
        if (tree[i].parent == ntl) {
            root = i;  // 親がいないノードを根ノードとする
            break;
        }
    }

    calculatedepth(root, 0);  // 根ノードの深さを計算
    calculateheight(root);  // 根ノードの高さを計算

    // 出力
    for (int i = 0; i < n; i++) {
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",
               i, tree[i].parent, getsibling(i), getdegree(i), tree[i].depth, tree[i].height, gettype(i));
    }

    return 0;
}