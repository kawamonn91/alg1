#include<stdio.h>
#include<stdlib.h>

#define NTL 2000000001  // 与えられる要素の最大値が2000000000のため、それよりも1大きい数に設定
#define index_max 1000002  // ノードの最大個数の定義

// ノード構造体の定義
typedef struct node {
    int index;       // ノードのインデックス
    int id;          // ノードのID
    int key;         // ノードのキー
    int parent_key;  // 親ノードのキー
    int left_key;    // 左の子ノードのキー
    int right_key;   // 右の子ノードのキー
} node;

node tree[index_max];  // ノードの配列

// ノードの初期化
void initializetree() {
    for (int i = 0; i < index_max; i++) {
        tree[i].index = i + 1;
        tree[i].id = NTL;
        tree[i].key = NTL;
        tree[i].parent_key = NTL;
        tree[i].left_key = NTL;
        tree[i].right_key = NTL;
    }
}

// ノードへのキーの格納
void get_key(int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &tree[i].key);
    }
}

// 親のキーを探す
void get_parent_key(int n) {
    for (int i = 0; i < n; i++) {
        if (tree[i].index > 1) {
            // 親のインデックスを求める
            int parent_index = tree[i].index / 2;
            // 親のインデックスから親のキーを求める
            if (parent_index >= 1) tree[i].parent_key = tree[parent_index - 1].key;
        }
    }
}

// 左の子のキーを探す
void get_left_key(int n) {
    for (int i = 0; i < n; i++) {
        int index = tree[i].index * 2;  // 左の子ノードのインデックス
        if (tree[index - 1].key != NTL) tree[i].left_key = tree[index - 1].key;
    }
}

// 右の子のキーを探す
void get_right_key(int n) {
    for (int i = 0; i < n; i++) {
        int index = tree[i].index * 2 + 1;  // 右の子ノードのインデックス
        if (tree[index - 1].key != NTL) tree[i].right_key = tree[index - 1].key;
    }
}

// 最大ヒープを維持するための関数
void maxHeapify(int i, int n) {
    int l = 2 * i;  // 左の子ノードのインデックス
    int r = 2 * i + 1;  // 右の子ノードのインデックス
    int largest;
    if (l <= n && tree[l - 1].key > tree[i - 1].key) largest = l;
    else largest = i;
    if (r <= n && tree[r - 1].key > tree[largest - 1].key) largest = r;
    if (largest != i) {
        int tmp = tree[i - 1].key;
        tree[i - 1].key = tree[largest - 1].key;
        tree[largest - 1].key = tmp;
        maxHeapify(largest, n);
    }
}

// 最大ヒープを構築するための関数
void buildMaxHeap(int n) {
    for (int i = n / 2; i >= 1; i--) {
        maxHeapify(i, n);
    }
}

int main() {
    int n;
    scanf("%d", &n);  // ノード数を入力
    initializetree();  // ツリーの初期化
    get_key(n);  // ノードのキーを入力
    get_parent_key(n);  // 親のキーを設定
    get_left_key(n);  // 左の子のキーを設定
    get_right_key(n);  // 右の子のキーを設定
    buildMaxHeap(n);  // 最大ヒープを構築
    for (int i = 0; i < n; i++) {
        printf(" %d", tree[i].key);  // ヒープのキーを出力
    }

    printf("\n");
    return 0;
}