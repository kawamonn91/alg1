#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// 定数の定義
#define MAX 1000
#define INF 2001

// 最小キー値を持つ頂点を見つける関数
int minKey(int key[], bool mstSet[], int n) 
{
    int min = INF, min_index;
    for (int v = 0; v < n; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

// プリムのアルゴリズムを使用して最小全域木を計算する関数
int primMST(int graph[MAX][MAX], int n) 
{
    int parent[MAX]; // 最小全域木を構成するための配列
    int key[MAX]; // 各頂点のキー値
    bool mstSet[MAX]; // 頂点が最小全域木に含まれているかどうかを示す配列

    // 初期化
    for (int i = 0; i < n; i++)
        key[i] = INF, mstSet[i] = false;
    key[0] = 0; // 最初の頂点を含める
    parent[0] = -1; // 最初の頂点はルートなので親はなし

    // 最小全域木を構築
    for (int count = 0; count < n - 1; count++) 
    {
        int u = minKey(key, mstSet, n); // 最小キー値を持つ頂点を選択
        mstSet[u] = true; // 選択した頂点を最小全域木に含める

        // 選択した頂点に隣接する頂点のキー値を更新
        for (int v = 0; v < n; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // 最小全域木の辺の重みの総和を計算
    int sum = 0;
    for (int i = 1; i < n; i++)
        sum += graph[i][parent[i]];
    return sum;
}

int main() 
{
    int n;
    scanf("%d", &n); // 頂点数を入力
    int graph[MAX][MAX];
    // 隣接行列を入力
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1)
                graph[i][j] = INF; // 辺がない場合はINFに設定
        }
    // 最小全域木の辺の重みの総和を出力
    printf("%d\n", primMST(graph, n));
    return 0;
}
