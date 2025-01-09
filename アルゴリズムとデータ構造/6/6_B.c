#include<stdio.h>
#include<stdlib.h>

// パーティション関数
int partition(int *A,int p,int q,int r)
{
    int x=A[r];
    int escape; // 基準の値をxに代入
    // A[q]がxよりも小さい場合、A[p]とA[q]を入れ替える
    if(x>=A[q])
    {
        escape=A[p];
        A[p]=A[q];
        A[q]=escape;
        p++;
    }
    return p;
}

int main()
{
    int *A,p=0,q=0,r,n,x;
    // 配列のサイズを入力
    scanf("%d",&n);
    A=(int *)malloc(n *sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    
    r=n-1;
    x=A[n-1]; // 基準値を格納
    while(q!=n)
    {
        p=partition(A,p,q,r);
        q++;
    }

    // 最も後ろにある、基準値と同じ数字の位置を記録する
    int i_max;
    for(int i=0;i<n;i++)
    {
        if(A[i]==x) i_max=i;
    }
    // 結果を出力
    for(int i=0;i<n;i++)
    {
        if(i==i_max) printf("[%d]",A[i]);
        else printf("%d",A[i]);
        if(i<n-1) printf(" ");
    }
    printf("\n");

    free(A);
    return 0;
}