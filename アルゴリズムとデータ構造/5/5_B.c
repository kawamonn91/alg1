#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// グローバル変数
int count=0;

// マージ関数
void merge(int *A,int left,int mid,int right)
{
    int n1=mid-left;
    int n2=right-mid;

    int *L,*R;
    L=(int *)malloc((n1+1) *sizeof(int));
    R=(int *)malloc((n2+1) *sizeof(int));

    // 左半分と右半分をそれぞれの配列にコピー
    for(int i=0;i<n1;i++)
    {
        L[i]=A[left+i];
    }
    for(int i=0;i<n2;i++)
    {
        R[i]=A[mid+i];
    }

    L[n1]=INT_MAX; // 番兵
    R[n2]=INT_MAX; // 番兵

    int i=0;
    int j=0;

    // マージ処理
    for(int k=left;k<right;k++)
    {
        count++;
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }

    free(L);
    free(R);
}

// マージソート関数
void mergeSort(int *A,int left,int right)
{
    if(left+1<right)
    {
        int mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}

int main()
{
    int n,mid,*S;
    scanf("%d",&n);
    S=(int *)malloc(n *sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&S[i]);
    }
    mergeSort(S,0,n);

    // ソート結果を出力
    for(int i=0;i<n;i++)
    {
        printf("%d",S[i]);
        if(i!=n-1) printf(" ");
    }
    printf("\n");
    // 交換回数を出力
    printf("%d\n",count);
    free(S);

    return 0;
}