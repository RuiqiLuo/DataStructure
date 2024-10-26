#include <stdio.h>
#include <stdlib.h>
// 常见错误：CreateListF 和 CreateListR 函数中，传递了 LinkNode *L 作为参数，但在函数内部又重新分配了内存给 L。这可能导致原始的 L 指针失去对分配的内存的引用

typedef struct LNode
{
    int data;
    struct LNode *next;
} LinkNode, *LinkList;

// 创建单链表 - 头插法
LinkList CreateListF(int a[], int n)
{
    LinkNode *s, *L;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    for (int i = 0; i < n; i++)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
    return L;
}

// 在链表的第n个位置添加元素
int AddNode(LinkNode *L, int n, int data)
{
    int i = 0;
    LinkNode *p = L;
    while (i < n - 1 && p != NULL)
    {
        p = p->next;
        i++;
    }
    if (p == NULL)
        return 0; // 未找到第n个位置
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = data;
    s->next = p->next;
    p->next = s;
    return 1;
}

// 删除链表的第i个元素
int ListDelete(LinkNode *L, int i)
{
    int j = 0;
    LinkNode *p = L, *q;
    while (j < i - 1 && p != NULL)
    {
        p = p->next;
        j++;
    }
    if (p == NULL || p->next == NULL)
        return 0; // 未找到第i个元素或第i个元素不存在
    q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

// 查找节点
LinkNode *FindNode(LinkNode *L, int data)
{
    LinkNode *p = L->next;
    while (p != NULL)
    {
        if (p->data == data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// 打印链表
void PrintList(LinkNode *L)
{
    LinkNode *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    LinkNode *list = CreateListF(a, n);

    printf("Head Insertion List: ");
    PrintList(list);

    // 在第2个位置添加元素
    if (AddNode(list, 2, 10))
    {
        printf("After Adding Node 10 at position 2: ");
        PrintList(list);
    }
    else
    {
        printf("Failed to add node.\n");
    }

    // 删除第3个元素
    if (ListDelete(list, 3))
    {
        printf("After Deleting Node at position 3: ");
        PrintList(list);
    }
    else
    {
        printf("Failed to delete node.\n");
    }

    // 查找元素4
    LinkNode *node = FindNode(list, 4);
    if (node != NULL)
    {
        printf("Node 4 found with value %d\n", node->data);
    }
    else
    {
        printf("Node 4 not found.\n");
    }

    // 释放链表内存
    LinkNode *p, *q;
    p = list;
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }

    return 0;
}