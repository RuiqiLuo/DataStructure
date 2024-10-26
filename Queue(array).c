#include <stdio.h>

#define size 3
int arr[size];
int front = 0;
int rear = 0;

void Queue_en(int val)
{
    // 检查队列是否已满
    if (rear == size)
    {
        printf("队列满\n");
    }
    else
    {
        arr[rear] = val;
        rear++;
    }
}

void Queue_de()
{
    // 检查队列是否为空
    if (front == rear)
    {
        printf("队列空\n");
    }
    else
    {
        printf("出队的元素：%d\n", arr[front]);
        front++; // 先进先出
    }
}

// 打印队列内容的函数
void printQueue()
{
    if (front == rear)
    {
        printf("队列为空\n");
        return;
    }
    printf("队列内容从front到rear：");
    for (int i = front; i < rear; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // 演示入队操作
    Queue_en(1); // 将元素1加入队列
    Queue_en(2); // 将元素2加入队列
    Queue_en(3); // 将元素3加入队列

    // 打印队列内容
    printQueue();

    // 演示出队操作
    Queue_de(); // 出队一个元素
    Queue_de(); // 出队一个元素

    // 打印队列内容
    printQueue();

    // 尝试再次入队，此时队列已满
    Queue_en(4); // 尝试加入元素4，应该提示队列满

    // 打印队列内容
    printQueue();

    // 清空队列
    while (front != rear)
    {
        Queue_de();
    }

    // 打印队列内容，此时队列应该为空
    printQueue();

    return 0;
}