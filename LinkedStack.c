#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Linknode, *Linklist;
// 初始化
Linklist initStack() // 注意传进来的是什么
{
    Linknode *s = (Linknode *)malloc(sizeof(Linknode));
    s->next = NULL;
    return s; // 这里是*s还是s?
}
// 判断是否为空（条件是：s->next==NULL）
int ifEmpty(Linknode *s)
{
    if (s->next == NULL)
        return 1;
    else
        return 0;
}
// 进栈
void Push(Linknode *s, int e)
{
    Linknode *p;
    p = (Linknode *)malloc(sizeof(Linknode));
    p->data = e;
    p->next = s->next;
    s->next = p;
}
// 出栈

int Pop(Linknode *s) // 注意这里返回的是int
{
    Linknode *p = s->next; // 初始化p的位置
    // 先判断是否为空
    if (s->next == NULL)
        return -1;
    // 关键

    // 这样写是错的：p->next = s->next;
    int e = p->data;
    // 删除操作
    s->next = p->next;
    free(p);
    return e;
}

int main()
{
    int a[4] = {1, 2, 3, 4};
    Linknode *s = initStack();
    if (s == NULL)
    {
        printf("内存分配失败\n");
        return 1; // 如果内存分配失败，返回错误码
    }
    int i;
    for (i = 0; i < 4; i++)
    {
        Push(s, a[i]);
    }
    int n, m;
    printf("请输入你要的操作：1. 进栈 2. 出栈 3.结束\n");
    scanf("%d", &n); // 将第一次读操作编号移到循环外
    while (n != 3)
    {
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
            printf("无效的操作，请重新输入：\n");
            break;
        }
        printf("请输入你要的操作：1. 进栈 2. 出栈 3.结束\n");
        scanf("%d", &n); // 在循环的末尾读取下一次操作编号
    }

    return 0;
}