#include<stdio.h>
#include<stdlib.h>

#define MAX 101

// タイムスタンプを保持する構造体
typedef struct 
{
    int start; // 探索開始時間
    int end;   // 探索終了時間
} Timestamp;

// 深さ優先探索(Deep First Search)
void dfs(int G[MAX][MAX], int *visited, Timestamp *timestamps, int *time, int v, int n)
{
    visited[v] = 1; // 頂点vを訪問済みにする
    (*time)++; // 時間を進める
    timestamps[v].start = *time; // 探索開始時間を記録

    // 隣接する頂点を探索
    for(int u = 1; u <= n; u++)
    {
        if(G[v][u] == 1 && visited[u] == 0)
        {
            dfs(G, visited, timestamps, time, u, n); // 再帰的に探索
        }
    }

    (*time)++; // 時間を進める
    timestamps[v].end = *time; // 探索終了時間を記録
}

// 深さ優先探索を開始する関数
void depth_first_search(int G[MAX][MAX], int n)
{
    int visited[MAX] = {0}; // 訪問済みかどうかを記録する配列
    Timestamp timestamps[MAX]; // 各頂点のタイムスタンプを記録する配列
    int time = 0; // 時間を初期化

    // 全ての頂点について深さ優先探索を行う
    for(int v = 1; v <= n; v++)
    {
        if(visited[v] == 0)
        {
            dfs(G, visited, timestamps, &time, v, n); // 未訪問の頂点から探索開始
        }
    }

    // 結果を出力
    for(int v = 1; v <= n; v++)
    {
        printf("%d %d %d\n", v, timestamps[v].start, timestamps[v].end);
    }
}

int main()
{
    int n; // 頂点の数
    int G[MAX][MAX] = {0}; // 隣接行列を初期化

    // 頂点数を入力
    scanf("%d", &n);

    // グラフの隣接行列を入力
    for(int i = 0; i < n; i++)
    {
        int u, k;
        scanf("%d %d", &u, &k); // 頂点uとその隣接頂点の数kを入力
        for(int j = 0; j < k; j++)
        {
            int v;
            scanf("%d", &v); // 隣接頂点vを入力
            G[u][v] = 1; // 隣接行列にエッジを追加
        }
    }

    // 深さ優先探索を実行
    depth_first_search(G, n);

    return 0;
}