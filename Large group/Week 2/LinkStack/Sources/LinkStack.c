#include"..\Headers\Headers.h"

// 初始化栈 
Status initLStack(LinkStack *s){
	s->top = NULL;
	s->count = 0; // 实时记录元素个数 
	return SUCCESS;
}

// 判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	return s->top == NULL ? SUCCESS : ERROR;
}

// 得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	if(isEmptyLStack(s) == SUCCESS){
		return ERROR; // 判断是否为空 
	}
	*e = s->top->data;
	return SUCCESS;
}

// 清空栈
Status clearLStack(LinkStack *s){
	if(s == NULL) return ERROR;
	LinkStackPtr p,q;
	p = s->top;
	while(p) { // 遍历链栈
		q = p;
		p = p->next; 
		free(q); // 释放空间 
	}
	initLStack(s);
}

// 销毁栈
Status destroyLStack(LinkStack *s){
	clearLStack(s); // 清空后释放 
	free(s);
    return SUCCESS;
}

// 检测栈长度
Status LStackLength(LinkStack *s,int *length){
	if(isEmptyLStack(s) == SUCCESS){
		printf("\n这里比我的钱包还空~\n");
		system("pause");
		return SUCCESS; 
	} // 判断是否为空 
	*length = s->count;
	printf("\n该栈的长度为: %d\n", *length);
    system("pause");
	return SUCCESS;
}

// 入栈
Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr newNode = (LinkStack*)malloc(sizeof(StackNode)); 
	if(!newNode) {
		return ERROR;
	} // 判断内存分配成功不 
	newNode->data = data;
	newNode->next = s->top;
	s->top = newNode; // 更新顶针 
	s->count++; // 更新count
	return SUCCESS; 
}

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	if(isEmptyLStack(s) == SUCCESS){
		return ERROR;
	}
	LinkStackPtr temp = s->top;
	*data = temp->data;
	s->top = s->top->next; // 更新顶针 
	free(temp);
	s->count--; // 更新count
	return SUCCESS; 
}

//打印栈
Status print(LinkStack* s) {
	LinkStackPtr p = s->top;
	printf("\nLinkStack:");
	while(p){
		printf("\n\t\t%d\n",p->data);
		p = p->next;
	} 
	return SUCCESS;
}

//打印菜单
void Userwelcome(){
	system("cls");
	printf("*********************************************\n");
	printf("**    欢迎进入517-QG之旅-WeekTwo-链栈站    **\n");
	printf("**-----------------------------------------**\n");
	printf("**     1--入栈             2--出栈         **\n");
	printf("**     3--获取栈顶元素     4--判断空栈     **\n");
	printf("**     5--测量栈长度       6--清空栈       **\n");
	printf("**     7--销毁栈           8--打印栈       **\n");
	printf("**                0--退出程序              **\n"); 
	printf("*********************************************\n");
	printf("\n请输入所需操作相应数字：(若输入多数字仅取第一个数字)");
} 

int main(){
	LinkStack stack;
    ElemType data;
    char choice;
    Status status;
    int length;

    initLStack(&stack); // 初始化栈 

	system("mode can cols=116 lines=35");//设置窗口大小 
	system("color f0");//设置颜色 
    while(1){
        Userwelcome();//进入用户页面 
		fflush(stdin);//不读取换行符 
		choice = getchar();//用户选择 
        while(getchar()!='\n');//丢弃getchar后所有字符
        system("cls"); // 清屏 
        
        switch (choice){
        	case '1':
            	printf("请输入所要入栈的整数: (非整数取整数部分)");
            	scanf("%d", &data);
            	status = pushLStack(&stack, data);
            	if (status == SUCCESS){
               		printf("\n入栈成功啦！\n");
            	}
            	else{
                printf("\n入栈失败了呜呜呜\n");
            	}
            	system("pause");
            	break;
        	case '2':
            	status = popLStack(&stack, &data);
            	if (status == SUCCESS){
                	printf("\n出栈成功啦！出栈元素为: %d\n", data);
            	}
            	else{
                printf("\n出栈失败！这里比我的钱包还空~\n");
            	}
            	system("pause");
            	break;
        	case '3':
            	status = getTopLStack(&stack, &data);
            	if (status == SUCCESS){
                	printf("\n栈顶元素为: %d\n", data);
            	}
            	else{
                	printf("\n找不到栈顶！这里比我脸还干净~\n");
            	}
            	system("pause");
            	break;
        	case '4':
            	if (isEmptyLStack(&stack) == SUCCESS){
                	printf("\n这里比我的钱包还空~\n");
            	}
            	else{
                	printf("\n不是空的:)\n");
            	}
            	system("pause");
            	break;
        	case '5':
            	LStackLength(&stack, &length);
            	break;
        	case '6':
            	clearLStack(&stack);
            	printf("\n清空成功~\n");
            	system("pause");
            	break;
        	case '7':
            	destroyLStack(&stack);
            	printf("\n销毁成功~\n");
            	system("pause");
            	break;
        	case '8':
            	status = print(&stack);
            	system("pause");
            	break;
        	case '0':exit(0);
        	default:{
				printf("\n没有这个选项~\n");
            	system("pause");
			}
		}
    } 
    return 0;
} 
