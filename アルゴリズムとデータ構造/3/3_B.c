#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// キューを回転させる関数（整数用）
void rota_time(int *que, int count) {
    int temp = que[0];
    memmove(que, que + 1, (count - 1) * sizeof(int));
    que[count - 1] = temp;
}

// キューを回転させる関数（文字列用）
void rota_name(char **name,int count)
{
    char *temp=name[0];
    memmove(name,name+1,(count-1) * sizeof(char *));
    name[count-1]=temp;
}

int main()
{
    int n,q,current_time=0;
    int *que;
    char **name;

    // プロセス数とクオンタムを入力
    scanf("%d %d",&n,&q);

    // 動的メモリ割り当て
    que=(int *)malloc((n) * sizeof(int)); // 整数型の配列の宣言
    name=(char **)malloc(n * sizeof(char *));

    // 各配列にメモリを確保
    for(int i=0;i<n;i++)
    {
        name[i]=(char *)malloc(11 * sizeof(char));
        if(name[i]==NULL)
        {
            printf("Memory allocation failed\n");
        }
    }

    if(que==NULL||name==NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // 配列にプロセス名と実行時間を格納
    for(int i=0;i<n;i++)
    {
        scanf("%s %d",name[i],&que[i]);
    }

    int count=n;

    // ラウンドロビンスケジューリングの実行
    while(n!=0)
    {
        int flag=0;
        int exec_time=(que[0]<q) ? que[0]:q;
        que[0]=que[0]-exec_time; // クオンタム分マイナス
        current_time=current_time+exec_time;

        if(que[0]==0)
        {
             flag=1; // 処理終了のフラグ
             printf("%s %d\n",name[0],current_time);
        }

        // 先頭のキューを最後尾に持っていく
        rota_time(que,n);
        rota_name(name,n);

        if(flag==1) // 処理終了の場合ローテーションの外に行くようにnの値を調整 
        {
            n=n-1;
        }
    }

    // メモリ開放
    for(int i=0;i<count;i++)
    {
        free(name[i]);
    }
    free(name);
    free(que);

    return 0;
}