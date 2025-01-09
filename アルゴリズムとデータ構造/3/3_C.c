#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ノードの定義
typedef struct Node
{
    int key;
    struct Node* prev;
    struct Node* next;
} Node;

// リストの定義
typedef struct DoublyLinkedList
{
    Node* head;
    Node* tail;
} DoublyLinkedList;

// ノードの作成
Node *createNode(int key)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->key=key;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

// リストの初期化
DoublyLinkedList* createDoublyLinkedList()
{
    DoublyLinkedList* dll=(DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    dll->head=NULL;
    dll->tail=NULL;
    return dll;
}

// 要素の挿入
void insert(DoublyLinkedList* dll,int key)
{
    Node* newNode=createNode(key);
    if(dll->head==NULL)
    {
        dll->head=dll->tail=newNode;
    }
    else
    {
        newNode->next=dll->head;
        dll->head->prev=newNode;
        dll->head=newNode;
    }
}

// 要素の削除
void delete(DoublyLinkedList* dll,int key)
{
    Node* current=dll->head;
    while(current!=NULL)
    {
        if(current->key==key)
        {
            if(current->prev) current->prev->next=current->next;
            if(current->next) current->next->prev=current->prev;
            if(current==dll->head) dll->head=current->next;
            if(current==dll->tail) dll->tail=current->prev;
            free(current);
            break;
        }
        current=current->next;
    }
}

// 先頭の消去
void deleteFirst(DoublyLinkedList* dll)
{
    if(dll->tail)
    {
        Node* temp=dll->head;
        if(dll->head==dll->tail) dll->head=dll->tail=NULL;
        else
        {
            dll->head=dll->head->next;
            dll->head->prev=NULL;
        }
        free(temp);
    }
}

// 末尾の消去
void deleteLast(DoublyLinkedList* dll)
{
    if(dll->tail)
    {
        Node* temp=dll->tail;
        if(dll->head==dll->tail) dll->head=dll->tail=NULL;
        else
        {
            dll->tail=dll->tail->prev;
            dll->tail->next=NULL;
        }
        free(temp);
    }
}

// リストの出力
void printList(DoublyLinkedList* dll)
{
    Node* current=dll->head;
    while(current!=NULL)
    {
        printf("%d",current->key);
        current=current->next;
        if(current!=NULL) printf(" ");
    }
    printf("\n");
}

int main()
{
    int n,num;
    char order[20];
    DoublyLinkedList* dll=createDoublyLinkedList();

    // 操作の数を入力
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        // 操作を入力
        scanf("%s",order);
        if(strcmp(order,"insert")==0)
        {
            scanf("%d",&num);
            insert(dll,num);
        }
        if(strcmp(order,"delete")==0)
        {
            scanf("%d",&num);
            delete(dll,num);
        }
        if(strcmp(order,"deleteFirst")==0)
        {
            deleteFirst(dll);
        }
        if(strcmp(order,"deleteLast")==0)
        {
            deleteLast(dll);
        }
    }
    // リストを出力
    printList(dll);
    return 0;
}