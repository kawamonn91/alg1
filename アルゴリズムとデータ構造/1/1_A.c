#include<stdio.h>

void insertionSort(int A[], int N);

int main()
{
    int N;
    scanf("%d",&N);
    int A[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }

    for(int i=0;i<N;i++)
    {
        printf("%d",A[i]);
        if(i<N-1) printf(" ");
    }

    printf("\n");
    insertionSort(A,N);
    
    return 0;
}

void insertionSort(int A[],int N)
{
    for(int i=1;i<N;i++)
    {
        int v=A[i];
        int j=i-1;
        while(j>=0&&A[j]>v)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        for(int k=0;k<N;k++)
        {
            printf("%d",A[k]);
            if(k<N-1) printf(" ");
        }
        printf("\n");
    }
}

