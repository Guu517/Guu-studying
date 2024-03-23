#include<stdio.h>
#include<stdlib.h>

// 定义两个枚举常量表示操作状态的返回值0/1 增强师兄们说的“健壮性” 
typedef enum Status {
    ERROR = 0, 
	SUCCESS = 1
}Status;

// 栈元素的数据类型 
typedef int ElemType;

// 栈节点结构体 
typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;
 
typedef struct LinkStack {
    LinkStackPtr top; // 栈顶指针 
    int count; // 记录元素个数 
}LinkStack;

// 函数声明 
Status initLStack(LinkStack *s);//初始化栈
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
Status getTopLStack(LinkStack *s,int *e);//得到栈顶元素
Status clearLStack(LinkStack *s);//清空栈
Status destroyLStack(LinkStack *s);//销毁栈
Status LStackLength(LinkStack *s,int *length);//检测栈长度
Status pushLStack(LinkStack *s,int data);//入栈
Status popLStack(LinkStack *s,int *data);//出栈
Status print(LinkStack* s);// 打印栈
void Userwelcome();//打印菜单 
