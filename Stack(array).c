#include <stdio.h>

#define size 3
int stack[size];
int top = -1;

void push(int e)
{
    // 入栈时先检查是否已满
    if (top == size - 1)
    {
        printf("栈已满\n");
        return;
    }
    top += 1;
    stack[top] = e; // 应该将传入的值e压入栈顶
}

void pop()
{
    // 出栈时先检查是否为空
    if (top == -1)
    {
        printf("栈为空\n");
        return;
    }
    top -= 1;
}

// 打印栈内容的函数
void printStack()
{
    if (top == -1)
    {
        printf("栈为空\n");
        return;
    }
    printf("栈内容从栈顶到栈底：");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    // 演示入栈操作
    push(1); // 将元素1压入栈
    push(2); // 将元素2压入栈
    push(3); // 将元素3压入栈

    // 打印栈内容
    printStack();

    // 演示出栈操作
    pop(); // 弹出栈顶元素
    pop(); // 弹出栈顶元素

    // 打印栈内容
    printStack();

    // 尝试再次入栈，此时栈已满
    push(4); // 尝试将元素4压入栈，应该提示栈已满

    // 打印栈内容
    printStack();

    // 清空栈
    while (top != -1)
    {
        pop();
    }

    // 打印栈内容，此时栈应该为空
    printStack();

    return 0;
}