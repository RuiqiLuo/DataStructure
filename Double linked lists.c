#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *prior;
    struct DNode *next;
} DLinkNode, *DLinkList;

// 头插法创建双链表
DLinkList CreatListF(int a[], int n)
{
    DLinkNode *s;
    DLinkList L = (DLinkNode *)malloc(sizeof(DLinkNode));
    L->prior = L->next = NULL;
    for (int i = 0; i < n; i++)
    {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = a[i];
        s->next = L->next;
        s->prior = L;
        if (L->next != NULL)
        {
            L->next->prior = s;
        }
        L->next = s;
    }
    return L;
}

// 尾插法创建双链表
DLinkList CreatListR(int a[], int n)
{
    DLinkNode *r, *s;
    DLinkList L = (DLinkNode *)malloc(sizeof(DLinkNode));
    L->data = 0;
    L->next = L->prior = NULL;
    r = L;
    for (int i = 0; i < n; i++)
    {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = a[i];
        s->next = NULL;
        s->prior = r;
        r->next = s;
        r = s;
    }
    return L;
}

// 打印双链表
void PrintList(DLinkList L)
{
    DLinkNode *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 主函数
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    DLinkList L;

    // 选择头插法创建双链表
    L = CreatListF(a, n);
    printf("Double Linked List (Head Insertion): ");
    PrintList(L);

    // 释放头插法创建的双链表内存
    DLinkNode *p, *q;
    while (L != NULL)
    {
        p = L->next;
        free(L);
        L = p;
    }

    // 选择尾插法创建双链表
    L = CreatListR(a, n);
    printf("Double Linked List (Tail Insertion): ");
    PrintList(L);

    // 释放尾插法创建的双链表内存
    while (L != NULL)
    {
        p = L->next;
        free(L);
        L = p;
    }

    return 0;
}