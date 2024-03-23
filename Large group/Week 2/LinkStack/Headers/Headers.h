#include<stdio.h>
#include<stdlib.h>

// ��������ö�ٳ�����ʾ����״̬�ķ���ֵ0/1 ��ǿʦ����˵�ġ���׳�ԡ� 
typedef enum Status {
    ERROR = 0, 
	SUCCESS = 1
}Status;

// ջԪ�ص��������� 
typedef int ElemType;

// ջ�ڵ�ṹ�� 
typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;
 
typedef struct LinkStack {
    LinkStackPtr top; // ջ��ָ�� 
    int count; // ��¼Ԫ�ظ��� 
}LinkStack;

// �������� 
Status initLStack(LinkStack *s);//��ʼ��ջ
Status isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack *s,int *e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack *s);//���ջ
Status destroyLStack(LinkStack *s);//����ջ
Status LStackLength(LinkStack *s,int *length);//���ջ����
Status pushLStack(LinkStack *s,int data);//��ջ
Status popLStack(LinkStack *s,int *data);//��ջ
Status print(LinkStack* s);// ��ӡջ
void Userwelcome();//��ӡ�˵� 
