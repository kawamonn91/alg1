#include<stdio.h>
#include<stdlib.h>

// カウントソートを行う関数
void countingsort(int n,int *A,int *C)
{
    // カウント配列を初期化
    for(int i=0;i<10001;i++)
    {
        C[i]=0;
    }

    // 各要素の出現回数をカウント
    for(int i=0;i<n;i++)
    {
        C[A[i]]++;
    }

    // 累積和を計算
    int sum=0;
    for(int i=0;i<10001;i++)
    {
        sum=sum+C[i];
        C[i]=sum;
    }

    int *B;
    B=(int *)malloc((n+1) *sizeof(int));

    // ソートされた配列を作成
    for(int i=n-1;i>=0;i--)
    {
        B[C[A[i]]-1]=A[i];
        C[A[i]]--;
    }

    // 元の配列にソート結果をコピー
    for(int i=0;i<n;i++)
    {
        A[i]=B[i];
    }
    free(B);
}

int main()
{
    int *A,C[10001],n;

    // 配列のサイズを入力
    scanf("%d",&n);
    A=(int *)malloc(n *sizeof(int));

    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    // カウントソートを実行
    countingsort(n,A,C);

    // ソート結果を出力
    for(int i=0;i<n;i++)
    {
        printf("%d",A[i]);
        if(i<n-1) printf(" ");
    }
    printf("\n");
    free(A);
    return 0;
}