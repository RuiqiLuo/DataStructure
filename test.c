#include <stdio.h>
#include <stdlib.h>
#define Max 100
typedef struct node
{
    int data[Max];
    struct node *next;
} Linknode, *Linklist;

// 初始化
Linknode *initStack() // 注意这里不需要传参数
{
    Linknode *s = (Linknode *)malloc(sizeof(Linknode));
    s->next = NULL;
    return s;
}

// 判断是否为空（条件是：s->next==NULL）
int ifEmpty(Linknode *s)
{
    return s->next == NULL;
}

// 进栈
void Push(Linknode *s, int e)
{
    Linknode *p = (Linknode *)malloc(sizeof(Linknode));
    p->next = s->next; // 将新节点的next指向当前的next
    s->next = p;       // 将栈顶指向新节点
    p->data[0] = e;    // 存储数据
}

// 出栈
int Pop(Linknode *s) // 注意这里返回的是int
{
    Linknode *p;
    // 先判断是否为空
    if (ifEmpty(s))
        return -1;     // 栈空时返回-1或其他错误码
    p = s->next;       // 先指向要删除的节点
    s->next = p->next; // 将栈顶指向下一个节点
    int e = p->data[0];
    free(p); // 释放节点
    return e;
}

int main()
{
    int a[4] = {1, 2, 3, 4};
    Linknode *s = initStack();
    int i;
    for (i = 0; i < 4; i++)
    {
        Push(s, a[i]);
    }
    printf("请输入你要的操作：1. 进栈 2. 出栈\n");
    int n, m;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("请输入你要插入的数字：");
        scanf("%d", &m);
        Push(s, m);
        break;
    case 2:
        m = Pop(s);
        if (m != -1)
        {
            printf("出栈的数字是：%d\n", m);
        }
        else
        {
            printf("栈空，无法出栈\n");
        }
        break;
    default:
        printf("无效的操作\n");
        break;
    }
    return 0;
}