#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 用于转换表达式 
typedef struct node
{
    char val;//数据域 
    struct node* next;
}pnode;

typedef struct seqstack
{
    int size;//记录栈的大小
    pnode* top;//指向栈顶
}phead;

// 用于计算表达式 
typedef struct node1//这里是整型栈
{
    int val;//数据
    struct node1* next;
}pnode1;

typedef struct seqstack1
{
    int size;//记录栈的大小
    pnode1* top;//指向栈顶
}phead1;
