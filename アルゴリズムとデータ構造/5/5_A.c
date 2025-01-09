#include<stdio.h>
#include<stdlib.h>

// 挿入ソートを行う関数
void insertionSort(int *A,int n)
{
    for(int i=1;i<n;i++)
    {
        int v=A[i];
        int j=i-1;
        while(j>=0&&A[j]>v)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
    }
}

// 全てのインデックスの組み合わせを生成し部分和を計算する関数
void calculate_all_combinations(int* judge,int* A, int* indices, int n, int k, int start, int currLen, int* used) {
    if (currLen == k) {
        // 部分和を計算
        int sum = 0;
        for (int i = 0; i < k; ++i) 
        {
            sum += A[indices[i]];
        }
        judge[sum]=1;
        return;
    }

    if (start == n) return ;

    for (int i = start; i < n; ++i) {
        if (!used[i]) 
        {
            indices[currLen] = i;
            used[i] = 1;
            calculate_all_combinations(judge,A, indices, n, k, i + 1, currLen + 1, used);
            used[i] = 0;
        }
    }
}
    
int main()
{
    int n,*A,q,*m;
    scanf("%d",&n);
    //printf("n=%d\n",n);

    A=(int *)malloc(n *sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    // 数列をソート
    insertionSort(A,n);

    scanf("%d",&q);

    m=(int *)malloc(q *sizeof(int));
    for(int i=0;i<q;i++)
    {
        scanf("%d",&m[i]);
    }

    int judge[2001];
    judge[0]=1;
    for(int i=1;i<2001;i++)
    {
        judge[i]=0;
    }

    // 全ての部分和を計算
    for(int i=1;i<=n;++i)
    {
        int indices[i];
        int used[n];
        for(int j=0;j<n;++j) used[j]=0;
        calculate_all_combinations(judge,A, indices, n, i, 0, 0, used);
    }

    // 結果を出力
    for(int i=0;i<q;i++)
    {
        if(judge[m[i]]==1) printf("yes\n");
        else printf("no\n");
    }

    free(A);
    free(m);
    return 0;
}