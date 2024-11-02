#include <stdio.h>
#include <stdlib.h>
// 数据节点
typedef struct q
{
    int data;
    struct q *next;
} DataNode, *Linknode;

// 链队节点
typedef struct
{
    DataNode *front;
    DataNode *rear;
} LinkQ;
// 初始化队列
LinkQ *initQue()
{
    LinkQ *q;
    q = (LinkQ *)malloc(sizeof(LinkQ));
    q->front = q->rear = NULL;
    return q;
}
// 进队(会出现两种情况)
void enQ(LinkQ *q, int e)
{
    DataNode *p;
    p = (DataNode *)malloc(sizeof(DataNode));
    p->data = e;
    p->next = NULL;
    // 判断链队是否是空
    if (q->rear == NULL) // 这里很关键，链队为空，新节点是队首又是队尾
        q->rear = q->front = p;
    // 关键
    else
    {
        q->rear->next = p; // 为什么q->rear会有->next
        q->rear = p;
    }
}
// 出队
// 三种情况（1.原队列为空，2.原队列只有一个节点,3.其他）
int deQ(LinkQ *q)
{
    DataNode *t;
    if (q->rear == NULL)
        return 0;
    // t指向第一个数据节点
    t = q->front;
    if (q->front == q->rear) // 队列就一个节点
        q->front = q->rear = NULL;
    else
        // 重点（q->front前移）
        q->front = q->front->next;
    int m = t->data;
    free(t);
    return m;
}
int main()
{
    int a[4] = {1, 2, 3, 4};
    LinkQ *q = initQue();
    int i;
    for (i = 0; i < 4; i++)
    {
        enQ(q, a[i]);
    }
    if (q == NULL)
    {
        printf("队列初始化失败\n");
        return 1;
    }
    int choice, num;
    while (1)
    {
        printf("输入功能选择：1.进队 2.出队 3.退出程序\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("请输入要进队的数据：");
            scanf("%d", &num);
            enQ(q, num);
            printf("数据 %d 已进队\n", num);
            break;
        case 2:
            num = deQ(q);
            printf("出队的数据是：%d\n", num);

            break;
        case 3:
            printf("退出程序\n");
            // 释放队列内存
            while (q->front != NULL)
            {
                deQ(q);
            }
            free(q);
            return 0;
        default:
            printf("无效的输入，请重新选择\n");
            break;
        }
    }
    return 0;
}