#include<stdio.h>

// 最大公約数を計算する関数のプロトタイプ宣言
long long int gcd(long long int x, long long int y);

int main()
{
    long long int x, y, result;
    // 2つの整数を入力
    scanf("%lld %lld", &x, &y);
    // 最大公約数を計算
    result = gcd(x, y);
    // 結果を出力
    printf("%lld\n", result);
    return 0;
}

// ユークリッドの互除法を用いて最大公約数を計算する関数
long long int gcd(long long int x, long long int y)
{
    // yが0になるまでループ
    while(y != 0)
    {
        long long int temp = y; // yの値を一時的に保存
        y = x % y; // xをyで割った余りをyに代入
        x = temp; // 一時的に保存したyの値をxに代入
    }
    // xが最大公約数
    return x;
}