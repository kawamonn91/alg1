#include<stdio.h>

int main()
{
    int n;
    // 配列の要素数を読み取る
    scanf("%d", &n);
    int str[n];
    // 配列に要素を格納
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &str[i]);
    }

    int min, min_index, count = 0, escape;
    // 選択ソートを用いて配列をソート
    for(int i = 0; i < n; i++)
    {
        min = str[i];
        min_index = i;
        for(int j = i; j < n; j++)
        {
            // 最小値を探す
            if(str[j] < min)
            {
                min_index = j;
                min = str[j];
            }
        }
        // 最小値と現在の要素を交換
        if(min_index != i)
        {
            escape = str[i];
            str[i] = min;
            str[min_index] = escape;
            count++; // 交換回数をカウント
        }
    }

    // ソートされた配列を出力
    for(int i = 0; i < n; i++)
    {
        printf("%d", str[i]);
        if(i != n - 1) printf(" "); // 要素の間に空白を入れる
    }
    printf("\n");
    printf("%d\n", count); // 交換回数を出力
    return 0;
}