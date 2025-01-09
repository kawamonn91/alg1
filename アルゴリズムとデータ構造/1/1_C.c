#include<stdio.h>
#include<math.h>

// 素数判定を行う関数のプロトタイプ宣言
int prime(long long int x);

int main()
{
    int count = 0, n;
    long long int x;
    // 入力された数の個数を読み取る
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        // 各数を読み取る
        scanf("%lld", &x);
        // 素数であればカウントを増やす
        if(prime(x) == 1) count++;
    }
    // 素数の個数を出力
    printf("%d\n", count);
    return 0;
}

// 素数判定を行う関数
int prime(long long int x)
{
    if(x <= 1) return 0; // 1以下の数は素数ではない
    if(x == 2) return 1; // 2は素数
    if(x % 2 == 0) return 0; // 偶数は素数ではない

    // 3からxの平方根までの奇数で割り切れるかをチェック
    for(long long int i = 3; i <= sqrt(x); i += 2)
    {
        if(x % i == 0) return 0; // 割り切れる場合は素数ではない
    }
    return 1; // 割り切れない場合は素数
}