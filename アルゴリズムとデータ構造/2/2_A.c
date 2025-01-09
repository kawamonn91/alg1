#include<stdio.h>

int main()
{
    int n, escape, count = 0;
    // 配列の要素数を読み取る
    scanf("%d", &n);
    int str[n];
    // 配列に要素を格納
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &str[i]);
    }

    // バブルソートを用いて配列をソート
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            // 隣接する要素を比較して交換
            if(str[j] > str[j + 1])
            {
                escape = str[j];
                str[j] = str[j + 1];
                str[j + 1] = escape;
                count++; // 交換回数をカウント
            }
        }
    }

    // ソートされた配列を出力
    for(int i = 0; i < n; i++)
    {
        printf("%d", str[i]);
        if(i != n - 1) printf(" "); // 要素の間に空白を入れる
    }
    printf("\n%d\n", count); // 交換回数を出力
    return 0;
}