#include<stdio.h>

int main()
{
    int n, profit_max;
    // 個数の読み取り
    scanf("%d", &n);
    int R[n];
    // 配列に格納
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &R[i]);
    }
    // profit_maxの初期値を設定
    profit_max = R[1] - R[0];
    int min = R[0];
    // profit_maxの計算
    for(int i = 1; i < n; i++)
    {
        // 現在の利益が最大利益を上回る場合、最大利益を更新
        if(profit_max < R[i] - min) profit_max = R[i] - min;
        // 現在の値が最小値を下回る場合、最小値を更新
        if(min > R[i]) min = R[i];
    }

    // 最大利益を出力
    printf("%d\n", profit_max);
    return 0;
}