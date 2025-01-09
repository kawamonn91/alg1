#include<stdio.h>
#include<stdlib.h>

// 二分探索を行う関数
void binary_search(int n,int x,int *S,int *count)
{
    int left=0,right=n-1;
    while(left<=right)
    {
        int current=(left+right)/2;
        if(S[current]==x)
        {
            (*count)++;
            break;
        }
        else if(S[current]<x)
        {
            left=current+1;
        }
        else
        {
            right=current-1;
        }
    }
}

int main()
{
    int n,*S,q,*T,count=0;

    // 配列Sのサイズを入力
    scanf("%d",&n);
    S=(int *)malloc(n * sizeof (int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&S[i]);
    }

    // 配列Tのサイズを入力
    scanf("%d",&q);
    T=(int *)malloc(q *sizeof (int));
    for(int i=0;i<q;i++)
    {
        scanf("%d",&T[i]);
    }

    // 配列Tの各要素に対して二分探索を実行
    for(int i=0;i<q;i++)
    {
        binary_search(n,T[i],S,&count);
    }

    // 結果を出力
    printf("%d\n",count);
    return 0;
}