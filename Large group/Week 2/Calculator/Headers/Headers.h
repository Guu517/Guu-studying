#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ����ת�����ʽ 
typedef struct node
{
    char val;//������ 
    struct node* next;
}pnode;

typedef struct seqstack
{
    int size;//��¼ջ�Ĵ�С
    pnode* top;//ָ��ջ��
}phead;

// ���ڼ�����ʽ 
typedef struct node1//����������ջ
{
    int val;//����
    struct node1* next;
}pnode1;

typedef struct seqstack1
{
    int size;//��¼ջ�Ĵ�С
    pnode1* top;//ָ��ջ��
}phead1;
