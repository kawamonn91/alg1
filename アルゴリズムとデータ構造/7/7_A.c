#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100000  // 最大ノード数の定義

// ノードを表す構造体
typedef struct Node {
    int id;                 // ノードのID
    int parent;             // 親ノードのID
    int depth;              // ノードの深さ
    int *children;          // 子ノードの配列
    int children_count;     // 子ノードの数
    char type[15];          // ノードの種類 (root, internal node, leaf)
} Node;

Node *nodes[MAX_NODES];  // ノードの配列

// 再帰的に深さと種類を設定する関数
void set_depths_and_types(int id, int depth) {
    nodes[id]->depth = depth;  // ノードの深さを設定
    if (nodes[id]->parent == -1) {
        strcpy(nodes[id]->type, "root");  // 親がいない場合は根ノード
    } else if (nodes[id]->children_count == 0) {
        strcpy(nodes[id]->type, "leaf");  // 子がいない場合は葉ノード
    } else {
        strcpy(nodes[id]->type, "internal node");  // それ以外は内部ノード
    }
    // 子ノードについても再帰的に深さと種類を設定
    for (int i = 0; i < nodes[id]->children_count; i++) {
        set_depths_and_types(nodes[id]->children[i], depth + 1);
    }
}

int main() {
    int n;  // ノード数
    scanf("%d", &n);  // ノード数を入力

    // 全ノードの初期化
    for (int i = 0; i < n; i++) {
        nodes[i] = (Node *)malloc(sizeof(Node));  // ノードのメモリ確保
        nodes[i]->id = i;  // ノードのIDを設定
        nodes[i]->parent = -1;  // 初期状態では親を持たない
        nodes[i]->depth = -1;  // 初期状態では深さを未設定
        nodes[i]->children = NULL;  // 子ノードの配列を初期化
        nodes[i]->children_count = 0;  // 子ノードの数を初期化
    }

    // ノード情報の読み取り
    for (int i = 0; i < n; i++) {
        int id, k;
        scanf("%d %d", &id, &k);  // ノードIDと子ノードの数を入力
        nodes[id]->children = (int *)malloc(k * sizeof(int));  // 子ノードのメモリ確保
        for (int j = 0; j < k; j++) {
            int child;
            scanf("%d", &child);  // 子ノードのIDを入力
            nodes[id]->children[nodes[id]->children_count++] = child;  // 子ノードを追加
            nodes[child]->parent = id;  // 子ノードの親を設定
        }
    }

    // 根ノードを見つけて深さと種類を設定
    for (int i = 0; i < n; i++) {
        if (nodes[i]->parent == -1) {  // 親がいないノードを根ノードとする
            set_depths_and_types(i, 0);  // 根ノードの深さは0
            break;
        }
    }

    // ノード情報を出力
    for (int i = 0; i < n; i++) {
        printf("node %d: parent = %d, depth = %d, %s, [", nodes[i]->id, nodes[i]->parent, nodes[i]->depth, nodes[i]->type);
        for (int j = 0; j < nodes[i]->children_count; j++) {
            printf("%d", nodes[i]->children[j]);
            if (j < nodes[i]->children_count - 1) printf(", ");
        }
        printf("]\n");
    }

    // メモリ解放
    for (int i = 0; i < n; i++) {
        free(nodes[i]->children);  // 子ノード配列のメモリ解放
        free(nodes[i]);  // ノードのメモリ解放
    }

    return 0;
}
