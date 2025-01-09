#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// 関数プロトタイプ宣言
void insertionsort(int[],int,int);
void shellsort(int[],int);

// グローバル変数
int cnt=0;

int main()
{
    int n;
    // 配列のサイズを入力
    scanf("%d",&n);
    // 動的メモリ割り当て
    int *A=(int*)malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
    {
        // 配列の要素を入力
        scanf("%d",&A[i]);
    }

    // シェルソートを実行
    shellsort(A,n);

    // 交換回数を出力
    printf("%d\n",cnt);

    // ソート後の配列を出力
    for(int i=0;i<n;i++)
    {
        printf("%d\n",A[i]);
    }

    // 動的メモリの解放
    free(A);
    return 0;
}

// 挿入ソート関数
void insertionsort(int A[],int n,int g)
{
    int v,j;
    for(int i=g;i<n;i++)
    {
        v=A[i];
        j=i-g;
        // 要素を適切な位置に挿入
        while(j>=0&&A[j]>v)
        {
            A[j+g]=A[j];
            j=j-g;
            cnt++; // 交換回数をカウント
        }
        A[j+g]=v;
    }
}

// シェルソート関数
void shellsort(int A[],int n)
{
    cnt=0;
    int m=0;
    int G[100];

    // 間隔の生成
    for(int i=1;i<=n;i=3*i+1)
    {
        G[m]=i;
        m++;
    }
    // 間隔の数を出力
    printf("%d\n",m);
    for(int i=m-1;i>=0;i--)
    {
        printf("%d",G[i]);
        if(i>0) printf(" ");
    }
    printf("\n");

    // 各間隔で挿入ソートを実行
    for(int i=m-1;i>=0;i--)
    {
        insertionsort(A,n,G[i]);
    }
}