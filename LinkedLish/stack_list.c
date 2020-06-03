#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define OK  1
#define ERROR 0

typedef int Status;
typedef int SElemType;  //SElemType 的类型根据实际情况决定，这里暂设为int
//疑问，top，top1，top2 这些栈顶在哪里赋初始值？？
typedef struct 
{
    SElemType data[MAXSIZE];
    int top;    //用于栈顶指针
}SqStack;

/*两个共享空间结构*/
typedef struct 
{
    SElemType data[MAXSIZE];
    int top1;   //栈1栈顶指针
    int top2;   //栈2栈顶指针
}SqDoubleStack;

/*插入元素e为新的栈顶元素*/
Status Push(SqStack *S, SElemType e)
{
    if(S->top == MAXSIZE -1)
    {
        return ERROR;
    }
    S->top++;   //栈顶指针增加1
    S->data[S->top]=e;      //将新插入元素赋值给栈顶空间
    return OK;
} 
/*若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR*/
Status Pop(SqStack *S, SElemType *e)
{
    if(S->top == -1)
    {
        return ERROR;
    }
    *e = S->data[S->top];   //将要删除的栈顶元素赋值给e
    S->top--;       //栈顶指针减1
    return OK;
}

/*插入元素e为新的栈顶元素*/
Status PushDouble(SqDoubleStack *S, SElemType e, int stackNumber)
{
    if(S->top1+1 == S->top2)    //栈已满，不能在push新元素了
    {
        return ERROR;
    }
    if(stackNumber == 1)    //栈1有元素进栈
    {
        S->data[++S->top1] = e; //若栈1则先top+1后给数组元素赋值
    }
    else if(stackNumber == 2)   //栈2有元素进栈
    {
        S->data[--S->top2] = e; //若栈2则先top2-1后给数组元素赋值
    }
    return OK;
}