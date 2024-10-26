#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
    int number;
    struct List *next;
} Node, *Link;

// 创建一个新节点
Node *createNode(int number)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->number = number;
    newNode->next = NULL;
    return newNode;
}

// 插入节点到指定位置
void insertNode(Link head, int number, int position)
{
    Node *newNode = createNode(number);
    Node *current = head;
    Node *prev = NULL;
    int currentPosition = 1;

    // 找到插入位置的前一个节点
    while (current != NULL && currentPosition < position)
    {
        prev = current;
        current = current->next;
        currentPosition++;
    }

    // 如果prev为NULL，说明链表为空或要在头部插入
    if (prev == NULL)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        // 否则在prev和current之间插入新节点
        newNode->next = current;
        prev->next = newNode;
    }
}

// 打印链表
void printList(Link head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->number);
        current = current->next;
    }
    printf("NULL\n");
}

// 主函数
int main()
{
    // 创建一个简单的链表：1 -> 2 -> 3 -> NULL
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    int number, position;

    // 获取用户输入的新节点值和插入位置
    printf("请输入新节点的值：");
    scanf("%d", &number);
    printf("请输入插入位置（从1开始计数）：");
    scanf("%d", &position);

    // 插入新节点
    insertNode(head, number, position);

    // 打印修改后的链表
    printList(head);

    // 注意：在实际应用中，应释放链表占用的内存

    return 0;
}