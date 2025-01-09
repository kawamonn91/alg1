#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// スタックからポップする関数
void pop(int q1[],int q2[],int count1[],int count2[])
{
    q2[count2[0]]=q1[count1[0]];
    count2[0]++;
    count1[0]++;
}

// 計算を行う関数
void calculate(int q1[],int q2[],int count1[],int count2[])
{
    if(count1[0]>=2)
    {
        // 加算
        if(q1[count1[0]]=='+')
        {
            q2[count2[0]-2]=q2[count2[0]-2]+q2[count2[0]-1];
        }
        // 減算
        else if(q1[count1[0]]=='-')
        {
            q2[count2[0]-2]=q2[count2[0]-2]-q2[count2[0]-1];
        }
        // 乗算
        else if(q1[count1[0]]=='*')
        {
            q2[count2[0]-2]=q2[count2[0]-2]*q2[count2[0]-1];
        }
    }
    count1[0]++; 
    count2[0]--;
}

int main()
{
    char que_c[2048];
    int q1[2048]; // 最初の配列
    int q2[2048]; // スタックする配列
    int count1[1]={0}; // q1の読み取る場所
    int count2[1]={0}; // スタックの一番上の部分
    int count=0;

    // 数字と演算子の読み込み
    fgets(que_c, sizeof(que_c),stdin);
    char *c=strtok(que_c," \n");

    int i=0;
    while(c!=NULL)
    {
        if(isdigit(c[0]))
        {
            q1[i]=atoi(c); // 数字を整数に変換
        }
        else
        {
            q1[i]=c[0]; // 演算子をそのまま格納
        }
        i++;
        c=strtok(NULL," \n");
    }

    count=i-1;
    while(1)
    {
        if(count1[0]>count) break;

        // 演算子の場合
        if((q1[count1[0]] == '+' || q1[count1[0]] == '-' || q1[count1[0]] == '*'))
        {
            calculate(q1,q2,count1,count2);
        }
        // 数字の場合
        else
        {
            pop(q1,q2,count1,count2);
        }
    }

    // 結果を出力
    printf("%d\n",q2[0]);
    return 0;
}