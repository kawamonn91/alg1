#include<stdio.h>
#include<stdlib.h>

// 配列Sと配列Tの共通要素を検索し、countにその数を格納する関数
void search(int *S,int n,int q,int *T,int *count)
{
    int *str,k=0;
    str=(int *)malloc((n>q?n:q) * sizeof(int));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<q;j++)
        {
            if(S[i]==T[j])
            {
                str[k++]=S[i];
                (*count)++;
                break;
            }
        }
    }

    // 重複を排除してユニークな要素の数を数える
    int unique_count=0;
    for(int i=0;i<k;i++)
    {
        int found=0;
        for(int j=0;j<unique_count;j++)
        {
            if(str[i]==str[j])
            {
                found=1;
                break;
            }
        }
        if(!found)
        {
            str[unique_count++]=str[i]; // str[unique_count]=str[i]; unique_count++; と同義
        }
    }

    *count=unique_count;
    free(str);
}

int main()
{
    int n,q,*S,*T;

    // 配列Sのサイズを入力
    scanf("%d",&n);
    S=(int *)malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&S[i]);
    }

    // 配列Tのサイズを入力
    scanf("%d",&q);
    T=(int *)malloc(q * sizeof(int));
    for(int i=0;i<q;i++)
    {
        scanf("%d",&T[i]);
    }

    int count=0;
    // 共通要素の検索
    search(S,n,q,T,&count);

    // 結果を出力
    printf("%d\n",count);
    free(T);
    free(S);
    return 0;
}