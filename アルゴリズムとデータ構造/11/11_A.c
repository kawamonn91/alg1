#include<stdio.h>
#include<stdlib.h>

// 隣接行列を初期化する関数
void initialize_adj(int n, int **adj) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;  // 全ての要素を0に初期化
        }
    }
}

// 隣接リストを作成する関数
void make_adj_list(int n, int **adj_list) {
    for (int i = 0; i < n; i++) {
        int u, k;
        scanf("%d %d", &u, &k);  // 頂点uとその出次数kを読み取る
        adj_list[u - 1][0] = k;  // 出次数を隣接リストの最初の要素に格納
        for (int j = 1; j <= k; j++) {
            scanf("%d", &adj_list[u - 1][j]);  // 隣接する頂点を読み取る
        }
    }
}

// 隣接リストから隣接行列を作成する関数
void make_adj_matrices(int n, int **adj_list, int **adj_matrices) {
    for (int i = 0; i < n; i++) {
        int k = adj_list[i][0];  // 出次数を取得
        for (int j = 1; j <= k; j++) {
            int v = adj_list[i][j];  // 隣接する頂点を取得
            adj_matrices[i][v - 1] = 1;  // 隣接行列に1を設定
        }
    }
}

// 隣接行列を出力する関数
void print_list(int n, int **list) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", list[i][j]);  // 各要素を出力
            if (j != n - 1) {
                printf(" ");  // 要素の間に空白を入れる
            }
        }
        printf("\n");  // 行の終わりで改行
    }
}

int main() {
    int n;
    scanf("%d", &n);  // 頂点数を読み取る

    int **adj_list;
    // n個の配列の作成
    adj_list = (int **)malloc(n * sizeof(int *));
    // n*n行列の作成
    for (int i = 0; i < n; i++) {
        adj_list[i] = (int *)malloc((n + 1) * sizeof(int));  // 出次数を格納するためにn+1のサイズを確保
    }

    // 行列の初期化
    initialize_adj(n, adj_list);

    // 隣接リストの作成
    make_adj_list(n, adj_list);

    int **adj_matrices;
    adj_matrices = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adj_matrices[i] = (int *)malloc(n * sizeof(int));
    }

    // 行列の初期化
    initialize_adj(n, adj_matrices);
    
    // 隣接行列の作成
    make_adj_matrices(n, adj_list, adj_matrices);

    // 隣接行列の出力
    print_list(n, adj_matrices);

    // メモリ解放
    for (int i = 0; i < n; i++) {
        free(adj_list[i]);
        free(adj_matrices[i]);
    }
    free(adj_list);
    free(adj_matrices);

    return 0;
}