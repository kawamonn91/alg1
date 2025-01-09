#include<stdio.h>
#include<stdlib.h>

#define mux_n 44  // フィボナッチ数列の最大インデックス

// フィボナッチ数列を計算する関数
int fib(int n) {
    static int memo[mux_n + 1] = {0};  // メモ化用の配列を追加
    if (n == 0 || n == 1) return 1;  // ベースケース: fib(0) と fib(1) は 1
    if (memo[n] != 0) return memo[n];  // 既に計算済みの場合はそれを返す
    memo[n] = fib(n - 1) + fib(n - 2);  // 計算結果をメモ化
    return memo[n];
}

int main() {
    int n;
    scanf("%d", &n);  // フィボナッチ数列のインデックスを入力
    printf("%d\n", fib(n));  // フィボナッチ数列の値を出力
    return 0;
}