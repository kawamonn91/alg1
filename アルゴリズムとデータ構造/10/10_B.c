#include<stdio.h>
#include<stdlib.h>

// 行列の連鎖積の最小計算コストを求める関数
int matrix_chain_order(int p[], int n) {
    int m[n][n];  // コストを保存するための2次元配列
    int i, j, k, l, q;
    
    // 単一行列のコストは0
    for (i = 1; i < n; i++) m[i][i] = 0;
    
    // lはチェーンの長さ
    for (l = 2; l < n; l++) {
        for (i = 1; i < n - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = 1000000000;  // 初期化
            for (k = i; k < j; k++) {
                // コスト計算
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) m[i][j] = q;  // 最小コストを保存
            }
        }
    }
    return m[1][n - 1];  // 最小コストを返す
}

int main() {
    int n;
    scanf("%d", &n);  // 行列の個数を入力
    int p[n + 1];  // 行列のサイズを保存する配列
    
    // 行列のサイズを入力
    for (int i = 0; i < n; i++) {
        int rows, cols;
        scanf("%d %d", &rows, &cols);
        p[i] = rows;  // 行数を保存
        if (i == n - 1) {
            p[i + 1] = cols;  // 最後の列数を保存
        }
    }
    
    // 最小計算コストを出力
    printf("%d\n", matrix_chain_order(p, n + 1));
    return 0;
}